/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_ALL */
#define PWM_ALL_INST                                                       TIMA0
#define PWM_ALL_INST_IRQHandler                                 TIMA0_IRQHandler
#define PWM_ALL_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define PWM_ALL_INST_CLK_FREQ                                           80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_ALL_C0_PORT                                               GPIOA
#define GPIO_PWM_ALL_C0_PIN                                        DL_GPIO_PIN_0
#define GPIO_PWM_ALL_C0_IOMUX                                     (IOMUX_PINCM1)
#define GPIO_PWM_ALL_C0_IOMUX_FUNC                    IOMUX_PINCM1_PF_TIMA0_CCP0
#define GPIO_PWM_ALL_C0_IDX                                  DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_ALL_C1_PORT                                               GPIOA
#define GPIO_PWM_ALL_C1_PIN                                        DL_GPIO_PIN_1
#define GPIO_PWM_ALL_C1_IOMUX                                     (IOMUX_PINCM2)
#define GPIO_PWM_ALL_C1_IOMUX_FUNC                    IOMUX_PINCM2_PF_TIMA0_CCP1
#define GPIO_PWM_ALL_C1_IDX                                  DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_PWM_ALL_C2_PORT                                               GPIOA
#define GPIO_PWM_ALL_C2_PIN                                        DL_GPIO_PIN_7
#define GPIO_PWM_ALL_C2_IOMUX                                    (IOMUX_PINCM14)
#define GPIO_PWM_ALL_C2_IOMUX_FUNC                   IOMUX_PINCM14_PF_TIMA0_CCP2
#define GPIO_PWM_ALL_C2_IDX                                  DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_ALL_C3_PORT                                               GPIOA
#define GPIO_PWM_ALL_C3_PIN                                       DL_GPIO_PIN_23
#define GPIO_PWM_ALL_C3_IOMUX                                    (IOMUX_PINCM53)
#define GPIO_PWM_ALL_C3_IOMUX_FUNC                   IOMUX_PINCM53_PF_TIMA0_CCP3
#define GPIO_PWM_ALL_C3_IDX                                  DL_TIMER_CC_3_INDEX

/* Defines for PWM_SERVO */
#define PWM_SERVO_INST                                                     TIMG7
#define PWM_SERVO_INST_IRQHandler                               TIMG7_IRQHandler
#define PWM_SERVO_INST_INT_IRQN                                 (TIMG7_INT_IRQn)
#define PWM_SERVO_INST_CLK_FREQ                                          2000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_SERVO_C0_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C0_PIN                                     DL_GPIO_PIN_26
#define GPIO_PWM_SERVO_C0_IOMUX                                  (IOMUX_PINCM59)
#define GPIO_PWM_SERVO_C0_IOMUX_FUNC                 IOMUX_PINCM59_PF_TIMG7_CCP0
#define GPIO_PWM_SERVO_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_SERVO_C1_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C1_PIN                                     DL_GPIO_PIN_24
#define GPIO_PWM_SERVO_C1_IOMUX                                  (IOMUX_PINCM54)
#define GPIO_PWM_SERVO_C1_IOMUX_FUNC                 IOMUX_PINCM54_PF_TIMG7_CCP1
#define GPIO_PWM_SERVO_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (155U)




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C0
#define I2C_OLED_INST_IRQHandler                                 I2C0_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C0_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             400000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOA
#define GPIO_I2C_OLED_SDA_PIN                                     DL_GPIO_PIN_28
#define GPIO_I2C_OLED_IOMUX_SDA                                   (IOMUX_PINCM3)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                    IOMUX_PINCM3_PF_I2C0_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOA
#define GPIO_I2C_OLED_SCL_PIN                                     DL_GPIO_PIN_31
#define GPIO_I2C_OLED_IOMUX_SCL                                   (IOMUX_PINCM6)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                    IOMUX_PINCM6_PF_I2C0_SCL

/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_3
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM16)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_2
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM15)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM15_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           40000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_FREQUENCY                                           40000000
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOB
#define GPIO_UART_1_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_6
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM40)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM23)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM40_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM23_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_1_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Defines for ADC12_CCD */
#define ADC12_CCD_INST                                                      ADC0
#define ADC12_CCD_INST_IRQHandler                                ADC0_IRQHandler
#define ADC12_CCD_INST_INT_IRQN                                  (ADC0_INT_IRQn)
#define ADC12_CCD_ADCMEM_0                                    DL_ADC12_MEM_IDX_0
#define ADC12_CCD_ADCMEM_0_REF                   DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_CCD_ADCMEM_0_REF_VOLTAGE_V                                     3.3
#define GPIO_ADC12_CCD_C0_PORT                                             GPIOA
#define GPIO_ADC12_CCD_C0_PIN                                     DL_GPIO_PIN_27

/* Defines for ADC12_VOLTAGE */
#define ADC12_VOLTAGE_INST                                                  ADC1
#define ADC12_VOLTAGE_INST_IRQHandler                            ADC1_IRQHandler
#define ADC12_VOLTAGE_INST_INT_IRQN                              (ADC1_INT_IRQn)
#define ADC12_VOLTAGE_ADCMEM_0                                DL_ADC12_MEM_IDX_0
#define ADC12_VOLTAGE_ADCMEM_0_REF               DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_VOLTAGE_ADCMEM_0_REF_VOLTAGE_V                                     3.3
#define GPIO_ADC12_VOLTAGE_C0_PORT                                         GPIOA
#define GPIO_ADC12_VOLTAGE_C0_PIN                                 DL_GPIO_PIN_15



/* Port definition for Pin Group KEY1 */
#define KEY1_PORT                                                        (GPIOB)

/* Defines for KEY_1: GPIOB.0 with pinCMx 12 on package pin 47 */
#define KEY1_KEY_1_PIN                                           (DL_GPIO_PIN_0)
#define KEY1_KEY_1_IOMUX                                         (IOMUX_PINCM12)
/* Port definition for Pin Group KEY2 */
#define KEY2_PORT                                                        (GPIOA)

/* Defines for KEY_2: GPIOA.2 with pinCMx 7 on package pin 42 */
#define KEY2_KEY_2_PIN                                           (DL_GPIO_PIN_2)
#define KEY2_KEY_2_IOMUX                                          (IOMUX_PINCM7)
/* Port definition for Pin Group KEY3 */
#define KEY3_PORT                                                        (GPIOA)

/* Defines for KEY_3: GPIOA.8 with pinCMx 19 on package pin 54 */
#define KEY3_KEY_3_PIN                                           (DL_GPIO_PIN_8)
#define KEY3_KEY_3_IOMUX                                         (IOMUX_PINCM19)
/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOB)

/* Defines for LED1PIN: GPIOB.25 with pinCMx 56 on package pin 27 */
#define LED1_LED1PIN_PIN                                        (DL_GPIO_PIN_25)
#define LED1_LED1PIN_IOMUX                                       (IOMUX_PINCM56)
/* Port definition for Pin Group LED2 */
#define LED2_PORT                                                        (GPIOB)

/* Defines for LED2PIN: GPIOB.26 with pinCMx 57 on package pin 28 */
#define LED2_LED2PIN_PIN                                        (DL_GPIO_PIN_26)
#define LED2_LED2PIN_IOMUX                                       (IOMUX_PINCM57)
/* Port definition for Pin Group BUZZER */
#define BUZZER_PORT                                                      (GPIOB)

/* Defines for BUZZERPIN: GPIOB.13 with pinCMx 30 on package pin 1 */
#define BUZZER_BUZZERPIN_PIN                                    (DL_GPIO_PIN_13)
#define BUZZER_BUZZERPIN_IOMUX                                   (IOMUX_PINCM30)
/* Port definition for Pin Group GPIO_MPU6050 */
#define GPIO_MPU6050_PORT                                                (GPIOA)

/* Defines for PIN_INT: GPIOA.25 with pinCMx 55 on package pin 26 */
// groups represented: ["GPIO_Encoder","GPIO_MPU6050"]
// pins affected: ["PIN_Front_Left_A","PIN_INT"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_MPU6050_PIN_INT_IIDX                           (DL_GPIO_IIDX_DIO25)
#define GPIO_MPU6050_PIN_INT_PIN                                (DL_GPIO_PIN_25)
#define GPIO_MPU6050_PIN_INT_IOMUX                               (IOMUX_PINCM55)
/* Port definition for Pin Group GPIO_SI */
#define GPIO_SI_PORT                                                     (GPIOA)

/* Defines for PIN_22: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_SI_PIN_22_PIN                                      (DL_GPIO_PIN_22)
#define GPIO_SI_PIN_22_IOMUX                                     (IOMUX_PINCM47)
/* Port definition for Pin Group GPIO_CLK */
#define GPIO_CLK_PORT                                                    (GPIOA)

/* Defines for PIN_9: GPIOA.9 with pinCMx 20 on package pin 55 */
#define GPIO_CLK_PIN_9_PIN                                       (DL_GPIO_PIN_9)
#define GPIO_CLK_PIN_9_IOMUX                                     (IOMUX_PINCM20)
/* Port definition for Pin Group KEY4 */
#define KEY4_PORT                                                        (GPIOA)

/* Defines for KEY_4: GPIOA.30 with pinCMx 5 on package pin 37 */
#define KEY4_KEY_4_PIN                                          (DL_GPIO_PIN_30)
#define KEY4_KEY_4_IOMUX                                          (IOMUX_PINCM5)
/* Defines for AIN1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define MOTOR_AIN1_PORT                                                  (GPIOA)
#define MOTOR_AIN1_PIN                                          (DL_GPIO_PIN_17)
#define MOTOR_AIN1_IOMUX                                         (IOMUX_PINCM39)
/* Defines for AIN2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define MOTOR_AIN2_PORT                                                  (GPIOA)
#define MOTOR_AIN2_PIN                                          (DL_GPIO_PIN_16)
#define MOTOR_AIN2_IOMUX                                         (IOMUX_PINCM38)
/* Defines for BIN1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define MOTOR_BIN1_PORT                                                  (GPIOB)
#define MOTOR_BIN1_PIN                                           (DL_GPIO_PIN_4)
#define MOTOR_BIN1_IOMUX                                         (IOMUX_PINCM17)
/* Defines for BIN2: GPIOB.1 with pinCMx 13 on package pin 48 */
#define MOTOR_BIN2_PORT                                                  (GPIOB)
#define MOTOR_BIN2_PIN                                           (DL_GPIO_PIN_1)
#define MOTOR_BIN2_IOMUX                                         (IOMUX_PINCM13)
/* Defines for PIN_Front_Left_A: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_Encoder_PIN_Front_Left_A_PORT                               (GPIOA)
#define GPIO_Encoder_PIN_Front_Left_A_IIDX                  (DL_GPIO_IIDX_DIO12)
#define GPIO_Encoder_PIN_Front_Left_A_PIN                       (DL_GPIO_PIN_12)
#define GPIO_Encoder_PIN_Front_Left_A_IOMUX                      (IOMUX_PINCM34)
/* Defines for PIN_Front_Left_B: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_Encoder_PIN_Front_Left_B_PORT                               (GPIOA)
#define GPIO_Encoder_PIN_Front_Left_B_PIN                       (DL_GPIO_PIN_13)
#define GPIO_Encoder_PIN_Front_Left_B_IOMUX                      (IOMUX_PINCM35)
/* Defines for PIN_Front_Right_A: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_Encoder_PIN_Front_Right_A_PORT                              (GPIOB)
// pins affected by this interrupt request:["PIN_Front_Right_A"]
#define GPIO_Encoder_GPIOB_INT_IRQN                             (GPIOB_INT_IRQn)
#define GPIO_Encoder_GPIOB_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_PIN_Front_Right_A_IIDX                 (DL_GPIO_IIDX_DIO22)
#define GPIO_Encoder_PIN_Front_Right_A_PIN                      (DL_GPIO_PIN_22)
#define GPIO_Encoder_PIN_Front_Right_A_IOMUX                     (IOMUX_PINCM50)
/* Defines for PIN_Front_Right_B: GPIOB.23 with pinCMx 51 on package pin 22 */
#define GPIO_Encoder_PIN_Front_Right_B_PORT                              (GPIOB)
#define GPIO_Encoder_PIN_Front_Right_B_PIN                      (DL_GPIO_PIN_23)
#define GPIO_Encoder_PIN_Front_Right_B_IOMUX                     (IOMUX_PINCM51)
/* Defines for L2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define Track_L2_PORT                                                    (GPIOB)
#define Track_L2_PIN                                            (DL_GPIO_PIN_15)
#define Track_L2_IOMUX                                           (IOMUX_PINCM32)
/* Defines for M0: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Track_M0_PORT                                                    (GPIOA)
#define Track_M0_PIN                                            (DL_GPIO_PIN_14)
#define Track_M0_IOMUX                                           (IOMUX_PINCM36)
/* Defines for R1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define Track_R1_PORT                                                    (GPIOB)
#define Track_R1_PIN                                            (DL_GPIO_PIN_19)
#define Track_R1_IOMUX                                           (IOMUX_PINCM45)
/* Defines for R2: GPIOA.21 with pinCMx 46 on package pin 17 */
#define Track_R2_PORT                                                    (GPIOA)
#define Track_R2_PIN                                            (DL_GPIO_PIN_21)
#define Track_R2_IOMUX                                           (IOMUX_PINCM46)
/* Defines for L1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define Track_L1_PORT                                                    (GPIOB)
#define Track_L1_PIN                                            (DL_GPIO_PIN_16)
#define Track_L1_IOMUX                                           (IOMUX_PINCM33)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_ALL_init(void);
void SYSCFG_DL_PWM_SERVO_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_ADC12_CCD_init(void);
void SYSCFG_DL_ADC12_VOLTAGE_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
