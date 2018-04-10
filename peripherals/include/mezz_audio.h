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

#ifndef __MEZZ_AUDIO_H__
#define __MEZZ_AUDIO_H__

#include <stdint.h>
#include <stdbool.h>

#include "gpio_port.h"
#include "spi_select.h"
#include "dac122s085.h"
#include "adc.h"
#include "gptimer.h"
#include "driver_defines.h"

extern volatile bool ALERT_ADC;
extern volatile uint16_t AUDIO_DATA;

//*****************************************************************************
// Fill out the #defines below to configure the pin connected to the comparator
//*****************************************************************************
#define MEZZ_AUDIO_PIN          		3
#define MEZZ_AUDIO_GPIO_BASE    		GPIOD_BASE
#define MEZZ_AUDIO_PORT         		GPIOD
#define MEZZ_AUDIO_PIN_M        		(1<<MEZZ_AUDIO_PIN)
#define MEZZ_AUDIO_ADC_BASE					ADC1_BASE
#define MEZZ_AUDIO_ADC_CHANNEL			4
#define MEZZ_AUDIO_ADC							ADC1


/********************************************************************************
* Summary: 
*   Writes data to the headphone jack 
*
* Returns

*******************************************************************************/
void mezz_audio_set_headphone(uint16_t data);

/********************************************************************************
* Summary: 
*   Writes data to the buzzer 
*
* Returns

*******************************************************************************/
void mezz_audio_set_buzzer(uint16_t data);

//*****************************************************************************
// 
//*****************************************************************************
bool mezz_audio_init(uint32_t micro_seconds);


#endif

