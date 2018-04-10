#// Copyright (c) 2014-16, Joe Krachey
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

#ifndef __DAC122S085_H__
#define __DAC122S085_H__


#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "gpio_port.h"
#include "spi.h"

//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the I2C Bus
//*****************************************************************************
//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the nordic wirless radio
//*****************************************************************************
#define   SPI_DAC_GPIO_BASE         GPIOA_BASE
#define   SPI_DAC_BASE              SSI0_BASE
#define   SPI_DAC_CS_PORT           GPIOA

#define   SPI_DAC_CLK_PIN           PA2
#define   SPI_DAC_CS_PIN            PA3
#define   SPI_DAC_MISO_PIN          PA4
#define   SPI_DAC_MOSI_PIN          PA5


#define   SPI_DAC_CLK_PCTL_M        GPIO_PCTL_PA2_M
#define   SPI_DAC_CS_PCTL_M         GPIO_PCTL_PA3_M
#define   SPI_DAC_MISO_PCTL_M       GPIO_PCTL_PA4_M
#define   SPI_DAC_MOSI_PCTL_M       GPIO_PCTL_PA5_M

#define   SPI_DAC_CLK_PIN_PCTL      GPIO_PCTL_PA2_SSI0CLK
#define   SPI_DAC_CS_PIN_PCTL       GPIO_PCTL_PA3_SSI0FSS
#define   SPI_DAC_MISO_PIN_PCTL     GPIO_PCTL_PA4_SSI0RX
#define   SPI_DAC_MOSI_PIN_PCTL     GPIO_PCTL_PA5_SSI0TX

#define   SPI_DAC_WRITE_UPDATE      ( 1 << 4 )
#define   SPI_DAC_CHANNEL_S         6 

 


bool spi_dac_init(void);
void spi_dac_byte_write(uint8_t channel, uint16_t data);
#endif
