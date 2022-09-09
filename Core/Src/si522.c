#include "si522.h"

inline uint8_t si522_read(si522_handle_t *handler, uint8_t reg) {
  uint8_t value;
  reg = (reg & 0x3f) << 1 | 0x80;
  handler->nss(1);
  handler->tx(&reg, 1);
  handler->rx(&value, 1);
  handler->nss(0);
  return value;
}

inline void si522_write(si522_handle_t *handler, uint8_t reg, uint8_t value) {
  reg = (reg & 0x3f) << 1;
  handler->nss(1);
  handler->tx(&reg, 1);
  handler->tx(&value, 1);
  handler->nss(0);
}

inline void si522_clearbit(si522_handle_t *handler, uint8_t reg, uint8_t mask) {
  uint8_t val = si522_read(handler, reg);
  si522_write(handler, reg, val & ~mask);
}

inline void si522_setbit(si522_handle_t *handler, uint8_t reg, uint8_t mask) {
  uint8_t val = si522_read(handler, reg);
  si522_write(handler, reg, val | mask);
}

void si522_init(si522_handle_t *handler) {
  si522_reset(handler);
}

void si522_reset(si522_handle_t *handler) {
  si522_clearbit(handler, Status2Reg, 0x08);
  // Reset baud rates
  si522_write(handler, TxModeReg, 0x00);
  si522_write(handler, RxModeReg, 0x00);
  // Reset ModWidthReg
  si522_write(handler, ModWidthReg, 0x26);
}
