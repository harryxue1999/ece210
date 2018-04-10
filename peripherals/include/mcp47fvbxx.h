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

#ifndef __DAC_H__
#define __DAC_H__


#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "gpio_port.h"
#include "i2c.h"

//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the I2C Bus
//*****************************************************************************
#define   DAC_GPIO_BASE           GPIOA_BASE
#define   DAC_I2C_BASE            I2C1_BASE
#define   DAC_I2C_SCL_PIN         PA6
#define   DAC_I2C_SDA_PIN         PA7
#define 	DAC_I2C_SCL_PCTL_M		  GPIO_PCTL_PA6_M
#define   DAC_I2C_SCL_PIN_PCTL    GPIO_PCTL_PA6_I2C1SCL
#define 	DAC_I2C_SDA_PCTL_M		  GPIO_PCTL_PA7_M
#define   DAC_I2C_SDA_PIN_PCTL    GPIO_PCTL_PA7_I2C1SDA

// Define the 7-bit Address of the MCP23017. 
#define MCP47FVBXX_DEV_ID    		0x60

#define MCP47FVBXX_WRITE_CMD  0x00 
#define MCP47FVBXX_READ_CMD   0x06 

#define MCP47FVBXX_DAC0_R 	  0x00 
#define MCP47FVBXX_DAC1_R	    0x01
 


bool dac_init(void);
i2c_status_t dac_byte_write(uint8_t reg, uint16_t data);
i2c_status_t dac_byte_read(uint8_t reg, uint16_t *data);
#endif
