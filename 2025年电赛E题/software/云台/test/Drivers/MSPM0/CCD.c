#include "CCD.h"
#include "adc.h"
#include  "Delay.h"
uint8_t CCD_Zhongzhi;
uint16_t ADV[128]={0};
unsigned int adc_value = 0;
unsigned int voltage_value = 0;
volatile bool gCheckADC;        //ADC采集成功标志位
float CCD_KP=16,CCD_KI=7;
float CCD_Vel=350;

void CCD_Mode(void)
{
    // Move_X=CCD_Vel/1000.0f;
    // static float Bias,Last_Bias;
    // Bias=64-CCD_Zhongzhi;   //提取偏差
    // Move_Z=Bias*CCD_KP/1000.0f+(Bias-Last_Bias)*CCD_KI/1000.0f; //PD控制
    // Last_Bias=Bias;   //保存上一次的偏差
    // Get_Target_Encoder(Move_X,Move_Z);
}
//读取ADC的数据
int adc_getValue(void)
{
        unsigned int gAdcResult = 0;

        //软件触发ADC开始转换
        DL_ADC12_startConversion(ADC12_CCD_INST);
        //如果当前状态为正在转换中则等待转换结束
        //获取数据
        gAdcResult = DL_ADC12_getMemResult(ADC12_CCD_INST, ADC12_CCD_ADCMEM_0);

        //清除标志位
        gCheckADC = false;

        return gAdcResult;
}

//CCD_ADC中断服务函数
void ADC12_CCD_INST_IRQHandler(void)
{
        //查询并清除ADC中断
        switch (DL_ADC12_getPendingInterrupt(ADC12_CCD_INST))
        {
                  //检查是否完成数据采集
                  case DL_ADC12_IIDX_MEM0_RESULT_LOADED:
                       gCheckADC = true;//将标志位置1
                       break;
                  default:
                       break;
        }
}
/**************************************************************************
函数功能：CCD数据采集
入口参数：无
返回  值：无
**************************************************************************/
void RD_TSL(void) 
{
   TSL_CLK(1); 
	Delay_us(5);
	TSL_SI(0);  
	Delay_us(10);
	TSL_CLK(0); 
	Delay_us(5);
	TSL_SI(1);
	Delay_us(30);
	TSL_CLK(1);
	Delay_us(5);
	TSL_SI(1);
	Delay_us(10);
	TSL_CLK(1);
	Delay_us(5);
	TSL_SI(0); 
	Delay_us(10); 		
	TSL_CLK(0);  
	Delay_us(100);
	for(int i=0;i<128;i++)    //读取128个像素点电压值
	{ 
		TSL_CLK(0);
		Delay_us(100);  //调节曝光时间
	
		ADV[i]=(adc_getValue())>>4;//右移4位是/4操作，将数据范围从0-4096压缩到0-256方便数据处理
	
		TSL_CLK(1);
		Delay_us(20);
	}
}

/**************************************************************************
函数功能：线性CCD取中值
入口参数：无
返回  值：无
**************************************************************************/
void Find_CCD_Median(void)
{ 
    static uint16_t i,j,Left,Right,Last_CCD_Median;
    static uint16_t value1_max,value1_min;
    static uint16_t CCD_Threshold;
    //阈值说明：CCD采集回来的128个数据，每个数据单独与阈值进行比较，比阈值大为白色，比阈值小为黑色
    //动态阈值算法，读取每次采集数据的最大和最小值的平均数作为阈值 
    value1_max=ADV[0];  
    for(i=5;i<123;i++)   //两边各去掉5个点
    {
        if(value1_max<=ADV[i])
        value1_max=ADV[i];
    }
    value1_min=ADV[0];  //最小值
    for(i=5;i<123;i++) 
    {
        if(value1_min>=ADV[i])
        value1_min=ADV[i];
    }
    CCD_Threshold =(value1_max+value1_min)/2;    //计算出本次中线提取的阈值
     
    for(i = 5;i<118; i++)   //寻找左边跳变沿，连续三个白像素后连续三个黑像素判断左边跳变沿
    {
        if(ADV[i]>CCD_Threshold &&ADV[i+1]>CCD_Threshold &&ADV[i+2]>CCD_Threshold &&ADV[i+3]<CCD_Threshold &&ADV[i+4]<CCD_Threshold &&ADV[i+5]<CCD_Threshold )
        {    
            Left=i+2;
            break;    
        }
    }
    for(j = 118;j>5; j--)//寻找右边跳变沿，连续三个黑像素后连续三个白像素判断右边跳变沿
    {
        if(ADV[j]<CCD_Threshold &&ADV[j+1]<CCD_Threshold &&ADV[j+2]<CCD_Threshold &&ADV[j+3]>CCD_Threshold &&ADV[j+4]>CCD_Threshold &&ADV[j+5]>CCD_Threshold )
        {    
            Right=j+2;
            break;    
        }
    }
    CCD_Zhongzhi =(uint8_t)(Right+Left)/2;//计算中线位置
}


void TSL_CLK(int state)
{
    if (state) {
        DL_GPIO_setPins(GPIO_CLK_PORT, GPIO_CLK_PIN_9_PIN);
    } else {
        DL_GPIO_clearPins(GPIO_CLK_PORT, GPIO_CLK_PIN_9_PIN);
    }
}

void TSL_SI(int state)
{
    if (state) {
        DL_GPIO_setPins(GPIO_SI_PORT, GPIO_SI_PIN_22_PIN);
    } else {
        DL_GPIO_clearPins(GPIO_SI_PORT, GPIO_SI_PIN_22_PIN);
    }
}