#include "adc.h"
//读取ADC的数据
float Get_battery_volt(void)
{
        float gAdcResult = 0;
        //软件触发ADC开始转换
        DL_ADC12_startConversion(ADC12_VOLTAGE_INST);
        //如果当前状态为正在转换中则等待转换结束
        //获取数据
        gAdcResult = DL_ADC12_getMemResult(ADC12_VOLTAGE_INST, ADC12_VOLTAGE_ADCMEM_0)*3.3*11.0/4096;
        //清除标志位
        gCheckADC = false;

        return gAdcResult;
}

//ADC中断服务函数
void ADC12_VOLTAGE_INST_IRQHandler(void)
{
        //查询并清除ADC中断
        switch (DL_ADC12_getPendingInterrupt(ADC12_VOLTAGE_INST))
        {
                  //检查是否完成数据采集
                  case DL_ADC12_IIDX_MEM0_RESULT_LOADED:
                       gCheckADC = true;//将标志位置1
                       break;
                  default:
                       break;
        }
}

