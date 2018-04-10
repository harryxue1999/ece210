// Copyright (c) 2014-16, Joe Krachey
// All rights reserved.
//
// Redistribution and use in binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in binary form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef __MICROPHONE_H__
#define __MICROPHONE_H__

#include <stdint.h>
#include <stdbool.h>

#include "gpio_port.h"
#include "gptimer.h"
#include "driver_defines.h"

//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the directional buttons
//*****************************************************************************
#define   MIC_GPIO_ANALOG_BASE 			GPIOE_BASE
#define   MIC_PIN      				      PE0
#define   MIC_CH							      3

#define MIC_SAMPLE_TICKS						5000


//*****************************************************************************
// Used to initialize the MIC
//*****************************************************************************
void mic_initialize(void);

//*****************************************************************************
// Returns the most current reading of the mic
//*****************************************************************************
uint16_t mic_get_data(void);


//*****************************************************************************
// Runs a test on the MIC.
//*****************************************************************************
void mic_test(void);


#endif
