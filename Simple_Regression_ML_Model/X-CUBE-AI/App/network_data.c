/**
******************************************************************************
* @file    network_data.c
* @author  AST Embedded Analytics Research Platform
* @date    Thu May 20 14:20:17 2021
* @brief   AI Tool Automatic Code Generator for Embedded NN computing
******************************************************************************
* @attention
*
* Copyright (c) 2021 STMicroelectronics.
* All rights reserved.
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
*                             www.st.com/SLA0044
*
******************************************************************************
*/

#include "network_data.h"

ai_handle ai_network_data_weights_get(void)
{
  AI_ALIGNED(32)
  static const ai_u8 s_network_weights[16] = {
    0x4f, 0xdc, 0x38, 0x41, 0xc9, 0x1f, 0xe8, 0x41,
    0x9f, 0x16, 0x2d, 0xc3, 0x46, 0x47, 0x12, 0x41  };
  return AI_HANDLE_PTR(s_network_weights);
}
