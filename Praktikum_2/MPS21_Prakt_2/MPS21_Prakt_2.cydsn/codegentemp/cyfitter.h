/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Rx_1__0__MASK 0x01u
#define Rx_1__0__PC CYREG_PRT2_PC0
#define Rx_1__0__PORT 2u
#define Rx_1__0__SHIFT 0u
#define Rx_1__AG CYREG_PRT2_AG
#define Rx_1__AMUX CYREG_PRT2_AMUX
#define Rx_1__BIE CYREG_PRT2_BIE
#define Rx_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Rx_1__BYP CYREG_PRT2_BYP
#define Rx_1__CTL CYREG_PRT2_CTL
#define Rx_1__DM0 CYREG_PRT2_DM0
#define Rx_1__DM1 CYREG_PRT2_DM1
#define Rx_1__DM2 CYREG_PRT2_DM2
#define Rx_1__DR CYREG_PRT2_DR
#define Rx_1__INP_DIS CYREG_PRT2_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Rx_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Rx_1__LCD_EN CYREG_PRT2_LCD_EN
#define Rx_1__MASK 0x01u
#define Rx_1__PORT 2u
#define Rx_1__PRT CYREG_PRT2_PRT
#define Rx_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Rx_1__PS CYREG_PRT2_PS
#define Rx_1__SHIFT 0u
#define Rx_1__SLW CYREG_PRT2_SLW

/* Tx_1 */
#define Tx_1__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Tx_1__0__MASK 0x02u
#define Tx_1__0__PC CYREG_PRT2_PC1
#define Tx_1__0__PORT 2u
#define Tx_1__0__SHIFT 1u
#define Tx_1__AG CYREG_PRT2_AG
#define Tx_1__AMUX CYREG_PRT2_AMUX
#define Tx_1__BIE CYREG_PRT2_BIE
#define Tx_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Tx_1__BYP CYREG_PRT2_BYP
#define Tx_1__CTL CYREG_PRT2_CTL
#define Tx_1__DM0 CYREG_PRT2_DM0
#define Tx_1__DM1 CYREG_PRT2_DM1
#define Tx_1__DM2 CYREG_PRT2_DM2
#define Tx_1__DR CYREG_PRT2_DR
#define Tx_1__INP_DIS CYREG_PRT2_INP_DIS
#define Tx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Tx_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Tx_1__LCD_EN CYREG_PRT2_LCD_EN
#define Tx_1__MASK 0x02u
#define Tx_1__PORT 2u
#define Tx_1__PRT CYREG_PRT2_PRT
#define Tx_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Tx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Tx_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Tx_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Tx_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Tx_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Tx_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Tx_1__PS CYREG_PRT2_PS
#define Tx_1__SHIFT 1u
#define Tx_1__SLW CYREG_PRT2_SLW

/* UART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB13_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB13_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB13_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB13_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB13_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB13_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB13_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB14_15_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB14_15_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB14_15_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB14_15_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB14_15_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB14_15_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB14_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB14_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB14_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB14_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB14_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB14_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB14_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB14_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB14_F1
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB12_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB12_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB12_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB12_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB12_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB12_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB12_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB12_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB15_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB15_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB15_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB15_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB15_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB15_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB15_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB15_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB15_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB15_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB15_ST
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u

/* Pin_N_G */
#define Pin_N_G__0__INTTYPE CYREG_PICU6_INTTYPE3
#define Pin_N_G__0__MASK 0x08u
#define Pin_N_G__0__PC CYREG_PRT6_PC3
#define Pin_N_G__0__PORT 6u
#define Pin_N_G__0__SHIFT 3u
#define Pin_N_G__AG CYREG_PRT6_AG
#define Pin_N_G__AMUX CYREG_PRT6_AMUX
#define Pin_N_G__BIE CYREG_PRT6_BIE
#define Pin_N_G__BIT_MASK CYREG_PRT6_BIT_MASK
#define Pin_N_G__BYP CYREG_PRT6_BYP
#define Pin_N_G__CTL CYREG_PRT6_CTL
#define Pin_N_G__DM0 CYREG_PRT6_DM0
#define Pin_N_G__DM1 CYREG_PRT6_DM1
#define Pin_N_G__DM2 CYREG_PRT6_DM2
#define Pin_N_G__DR CYREG_PRT6_DR
#define Pin_N_G__INP_DIS CYREG_PRT6_INP_DIS
#define Pin_N_G__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define Pin_N_G__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define Pin_N_G__LCD_EN CYREG_PRT6_LCD_EN
#define Pin_N_G__MASK 0x08u
#define Pin_N_G__PORT 6u
#define Pin_N_G__PRT CYREG_PRT6_PRT
#define Pin_N_G__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define Pin_N_G__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define Pin_N_G__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define Pin_N_G__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define Pin_N_G__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define Pin_N_G__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define Pin_N_G__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define Pin_N_G__PS CYREG_PRT6_PS
#define Pin_N_G__SHIFT 3u
#define Pin_N_G__SLW CYREG_PRT6_SLW

/* Pin_N_R */
#define Pin_N_R__0__INTTYPE CYREG_PICU2_INTTYPE7
#define Pin_N_R__0__MASK 0x80u
#define Pin_N_R__0__PC CYREG_PRT2_PC7
#define Pin_N_R__0__PORT 2u
#define Pin_N_R__0__SHIFT 7u
#define Pin_N_R__AG CYREG_PRT2_AG
#define Pin_N_R__AMUX CYREG_PRT2_AMUX
#define Pin_N_R__BIE CYREG_PRT2_BIE
#define Pin_N_R__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_N_R__BYP CYREG_PRT2_BYP
#define Pin_N_R__CTL CYREG_PRT2_CTL
#define Pin_N_R__DM0 CYREG_PRT2_DM0
#define Pin_N_R__DM1 CYREG_PRT2_DM1
#define Pin_N_R__DM2 CYREG_PRT2_DM2
#define Pin_N_R__DR CYREG_PRT2_DR
#define Pin_N_R__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_N_R__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_N_R__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_N_R__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_N_R__MASK 0x80u
#define Pin_N_R__PORT 2u
#define Pin_N_R__PRT CYREG_PRT2_PRT
#define Pin_N_R__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_N_R__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_N_R__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_N_R__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_N_R__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_N_R__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_N_R__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_N_R__PS CYREG_PRT2_PS
#define Pin_N_R__SHIFT 7u
#define Pin_N_R__SLW CYREG_PRT2_SLW

/* Pin_N_Y */
#define Pin_N_Y__0__INTTYPE CYREG_PICU6_INTTYPE2
#define Pin_N_Y__0__MASK 0x04u
#define Pin_N_Y__0__PC CYREG_PRT6_PC2
#define Pin_N_Y__0__PORT 6u
#define Pin_N_Y__0__SHIFT 2u
#define Pin_N_Y__AG CYREG_PRT6_AG
#define Pin_N_Y__AMUX CYREG_PRT6_AMUX
#define Pin_N_Y__BIE CYREG_PRT6_BIE
#define Pin_N_Y__BIT_MASK CYREG_PRT6_BIT_MASK
#define Pin_N_Y__BYP CYREG_PRT6_BYP
#define Pin_N_Y__CTL CYREG_PRT6_CTL
#define Pin_N_Y__DM0 CYREG_PRT6_DM0
#define Pin_N_Y__DM1 CYREG_PRT6_DM1
#define Pin_N_Y__DM2 CYREG_PRT6_DM2
#define Pin_N_Y__DR CYREG_PRT6_DR
#define Pin_N_Y__INP_DIS CYREG_PRT6_INP_DIS
#define Pin_N_Y__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define Pin_N_Y__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define Pin_N_Y__LCD_EN CYREG_PRT6_LCD_EN
#define Pin_N_Y__MASK 0x04u
#define Pin_N_Y__PORT 6u
#define Pin_N_Y__PRT CYREG_PRT6_PRT
#define Pin_N_Y__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define Pin_N_Y__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define Pin_N_Y__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define Pin_N_Y__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define Pin_N_Y__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define Pin_N_Y__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define Pin_N_Y__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define Pin_N_Y__PS CYREG_PRT6_PS
#define Pin_N_Y__SHIFT 2u
#define Pin_N_Y__SLW CYREG_PRT6_SLW

/* Pin_CWEW */
#define Pin_CWEW__0__INTTYPE CYREG_PICU6_INTTYPE5
#define Pin_CWEW__0__MASK 0x20u
#define Pin_CWEW__0__PC CYREG_PRT6_PC5
#define Pin_CWEW__0__PORT 6u
#define Pin_CWEW__0__SHIFT 5u
#define Pin_CWEW__AG CYREG_PRT6_AG
#define Pin_CWEW__AMUX CYREG_PRT6_AMUX
#define Pin_CWEW__BIE CYREG_PRT6_BIE
#define Pin_CWEW__BIT_MASK CYREG_PRT6_BIT_MASK
#define Pin_CWEW__BYP CYREG_PRT6_BYP
#define Pin_CWEW__CTL CYREG_PRT6_CTL
#define Pin_CWEW__DM0 CYREG_PRT6_DM0
#define Pin_CWEW__DM1 CYREG_PRT6_DM1
#define Pin_CWEW__DM2 CYREG_PRT6_DM2
#define Pin_CWEW__DR CYREG_PRT6_DR
#define Pin_CWEW__INP_DIS CYREG_PRT6_INP_DIS
#define Pin_CWEW__INTSTAT CYREG_PICU6_INTSTAT
#define Pin_CWEW__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define Pin_CWEW__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define Pin_CWEW__LCD_EN CYREG_PRT6_LCD_EN
#define Pin_CWEW__MASK 0x20u
#define Pin_CWEW__PORT 6u
#define Pin_CWEW__PRT CYREG_PRT6_PRT
#define Pin_CWEW__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define Pin_CWEW__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define Pin_CWEW__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define Pin_CWEW__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define Pin_CWEW__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define Pin_CWEW__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define Pin_CWEW__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define Pin_CWEW__PS CYREG_PRT6_PS
#define Pin_CWEW__SHIFT 5u
#define Pin_CWEW__SLW CYREG_PRT6_SLW
#define Pin_CWEW__SNAP CYREG_PICU6_SNAP

/* Pin_E_CW */
#define Pin_E_CW__0__INTTYPE CYREG_PICU15_INTTYPE5
#define Pin_E_CW__0__MASK 0x20u
#define Pin_E_CW__0__PC CYREG_IO_PC_PRT15_PC5
#define Pin_E_CW__0__PORT 15u
#define Pin_E_CW__0__SHIFT 5u
#define Pin_E_CW__AG CYREG_PRT15_AG
#define Pin_E_CW__AMUX CYREG_PRT15_AMUX
#define Pin_E_CW__BIE CYREG_PRT15_BIE
#define Pin_E_CW__BIT_MASK CYREG_PRT15_BIT_MASK
#define Pin_E_CW__BYP CYREG_PRT15_BYP
#define Pin_E_CW__CTL CYREG_PRT15_CTL
#define Pin_E_CW__DM0 CYREG_PRT15_DM0
#define Pin_E_CW__DM1 CYREG_PRT15_DM1
#define Pin_E_CW__DM2 CYREG_PRT15_DM2
#define Pin_E_CW__DR CYREG_PRT15_DR
#define Pin_E_CW__INP_DIS CYREG_PRT15_INP_DIS
#define Pin_E_CW__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define Pin_E_CW__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define Pin_E_CW__LCD_EN CYREG_PRT15_LCD_EN
#define Pin_E_CW__MASK 0x20u
#define Pin_E_CW__PORT 15u
#define Pin_E_CW__PRT CYREG_PRT15_PRT
#define Pin_E_CW__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define Pin_E_CW__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define Pin_E_CW__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define Pin_E_CW__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define Pin_E_CW__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define Pin_E_CW__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define Pin_E_CW__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define Pin_E_CW__PS CYREG_PRT15_PS
#define Pin_E_CW__SHIFT 5u
#define Pin_E_CW__SLW CYREG_PRT15_SLW

/* isr_CWEW */
#define isr_CWEW__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_CWEW__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_CWEW__INTC_MASK 0x400u
#define isr_CWEW__INTC_NUMBER 10u
#define isr_CWEW__INTC_PRIOR_NUM 7u
#define isr_CWEW__INTC_PRIOR_REG CYREG_NVIC_PRI_10
#define isr_CWEW__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_CWEW__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_UART_RX */
#define isr_UART_RX__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_UART_RX__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_UART_RX__INTC_MASK 0x01u
#define isr_UART_RX__INTC_NUMBER 0u
#define isr_UART_RX__INTC_PRIOR_NUM 7u
#define isr_UART_RX__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define isr_UART_RX__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_UART_RX__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "MPS21_Prakt_2"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E160069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
