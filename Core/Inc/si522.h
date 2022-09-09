#ifndef SI522_SI522_H
#define SI522_SI522_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define RFCfgReg_Val 0x48
#define DivIEnReg_Val 0xC0
#define ComIEnReg_Val 0x80
#define IRQMODE 0x01
#define EXTI_Trigger_Mode 0x0C
#define ACDConfigRegA_Val 0x02
#define ACDConfigRegB_Val 0xA8
#define ACDConfigRegD_Val 0x04
#define ACDConfigRegH_Val 0x26
#define ACDConfigRegI_Val 0x00
#define ACDConfigRegJ_Val 0x55
#define ACDConfigRegM_Val 0x01
#define ACDConfigRegO_Val 0x00

// Page 0: Command and status
#define RFU00 0x00
#define CommandReg 0x01
#define ComIEnReg 0x02
#define DivIEnReg 0x03
#define ComIrqReg 0x04
#define DivIrqReg 0x05
#define ErrorReg 0x06
#define Status1Reg 0x07
#define Status2Reg 0x08
#define FIFODataReg 0x09
#define FIFOLevelReg 0x0A
#define WaterLevelReg 0x0B
#define ControlReg 0x0C
#define BitFramingReg 0x0D
#define CollReg 0x0E
#define ACDConfigReg 0x0F

// Page 1: Command
#define RFU10 0x10
#define ModeReg 0x11
#define TxModeReg 0x12
#define RxModeReg 0x13
#define TxControlReg 0x14
#define TxASKReg 0x15
#define TxSelReg 0x16
#define RxSelReg 0x17
#define RxThresholdReg 0x18
#define DemodReg 0x19
#define RFU1A 0x1A
#define RFU1B 0x1B
#define MfTxReg 0x1C
#define MfRxReg 0x1D
#define TypeBReg 0x1E
#define SerialSpeedReg 0x1F

// Page 2: Configuration
#define ACDConfigSelReg 0x20
#define CRCResultRegH 0x21
#define CRCResultRegL 0x22
#define RFU23 0x23
#define ModWidthReg 0x24
#define RFU25 0x25
#define RFCfgReg 0x26
#define GsNReg 0x27
#define CWGsPReg 0x28
#define ModGsPReg 0x29
#define TModeReg 0x2A
#define TPrescalerReg 0x2B
#define TReloadRegH 0x2C
#define TReloadRegL 0x2D
#define TCounterValueRegH 0x2E
#define TCounterValueRegL 0x2F

// Page 3: Test Register
#define RFU30 0x30
#define TestSel1Reg 0x31
#define TestSel2Reg 0x32
#define TestPinEnReg 0x33
#define TestPinValueReg 0x34
#define TestBusReg 0x35
#define AutoTestReg 0x36
#define VersionReg 0x37
#define AnalogTestReg 0x38
#define TestDAC1Reg 0x39
#define TestDAC2Reg 0x3A
#define TestADCReg 0x3B
#define RFU3C 0x3C
#define RFU3D 0x3D
#define RFU3E 0x3E
#define RFU3F 0x3F

#define PCD_IDLE 0x00
#define PCD_AUTHENT 0x0E
#define PCD_RECEIVE 0x08
#define PCD_TRANSMIT 0x04
#define PCD_TRANSCEIVE 0x0C
#define PCD_RESETPHASE 0x0F
#define PCD_CALCCRC 0x03

#define MI_OK 0
#define MI_NOTAGERR 1
#define MI_ERR 2

#define DEF_FIFO_LENGTH 64  // FIFO size=64byte
#define MAXRLEN 18

#define PICC_REQIDL 0x26
#define PICC_REQALL 0x52
#define PICC_ANTICOLL1 0x93
#define PICC_ANTICOLL2 0x95
#define PICC_ANTICOLL3 0x97

#define PICC_AUTHENT1A 0x60
#define PICC_AUTHENT1B 0x61
#define PICC_READ 0x30
#define PICC_WRITE 0xA0
#define PICC_DECREMENT 0xC0
#define PICC_INCREMENT 0xC1
#define PICC_RESTORE 0xC2
#define PICC_TRANSFER 0xB0
#define PICC_HALT 0x50

typedef void (*si522_nss)(uint8_t);

typedef void (*si522_tx)(uint8_t *, size_t);

typedef void (*si522_rx)(uint8_t *, size_t);

typedef struct {
  volatile uint8_t irq_flag;
  /* BSP Functions */
  si522_nss nss;
  si522_tx tx;
  si522_rx rx;
} si522_handle_t;

void si522_init(si522_handle_t *);
void si522_reset(si522_handle_t *);

#endif  // SI522_SI522_H
