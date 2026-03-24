#pragma once

#include <RadioLib.h>

inline bool sx126xIsReceivingOrRecover(SX126x& radio) {
  uint16_t irq = radio.getIrqFlags();
  uint16_t errorIrqs = RADIOLIB_SX126X_IRQ_CRC_ERR | RADIOLIB_SX126X_IRQ_HEADER_ERR;
  if ((irq & errorIrqs) != 0) {
    radio.clearIrqStatus(errorIrqs | RADIOLIB_SX126X_IRQ_HEADER_VALID | RADIOLIB_SX126X_IRQ_PREAMBLE_DETECTED);
    return false;
  }

  return (irq & (RADIOLIB_SX126X_IRQ_HEADER_VALID | RADIOLIB_SX126X_IRQ_PREAMBLE_DETECTED)) != 0;
}
