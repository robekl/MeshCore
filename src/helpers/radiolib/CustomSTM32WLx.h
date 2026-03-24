#pragma once

#include <RadioLib.h>
#include "SX126xReceiveState.h"

class CustomSTM32WLx : public STM32WLx {
  public:
    CustomSTM32WLx(STM32WLx_Module *mod) : STM32WLx(mod) { }

    bool isReceiving() { return sx126xIsReceivingOrRecover(*this); }
};
