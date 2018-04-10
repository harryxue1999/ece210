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

#ifndef __IO_EXPANDER_H__
#define __IO_EXPANDER_H__


#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "gpio_port.h"
#include "i2c.h"

//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the I2C Bus
//*****************************************************************************
#define   IO_EXPANDER_GPIO_BASE           GPIOA_BASE
#define   IO_EXPANDER_I2C_BASE            I2C1_BASE
#define   IO_EXPANDER_I2C_SCL_PIN         PA6
#define   IO_EXPANDER_I2C_SDA_PIN         PA7
#define 	IO_EXPANDER_I2C_SCL_PCTL_M		  GPIO_PCTL_PA6_M
#define   IO_EXPANDER_I2C_SCL_PIN_PCTL    GPIO_PCTL_PA6_I2C1SCL
#define 	IO_EXPANDER_I2C_SDA_PCTL_M		  GPIO_PCTL_PA7_M
#define   IO_EXPANDER_I2C_SDA_PIN_PCTL    GPIO_PCTL_PA7_I2C1SDA

#define   IO_EXPANDER_IRQ_GPIO_BASE       GPIOF_BASE
#define   IO_EXPANDER_IRQ_PIN_NUM         PF0

#define   DIR_BTN_UP_PIN                  0
#define   DIR_BTN_DOWN_PIN                1
#define   DIR_BTN_LEFT_PIN                2
#define   DIR_BTN_RIGHT_PIN               3

// Define the 7-bit Address of the MCP23017. 
#define MCP23017_DEV_ID    		0x27

#define MCP23017_IODIRA_R 	  0x00 
#define MCP23017_IODIRB_R	    0x01 
#define MCP23017_IPOLA_R 	    0x02 
#define MCP23017_IPOLB_R	    0x03 
#define MCP23017_GPINTENA_R   0x04 
#define MCP23017_GPINTENB_R   0x05
#define MCP23017_DEFVALA_R 	  0x06
#define MCP23017_DEFVALB_R 	  0x07
#define MCP23017_INTCONA_R 	  0x08
#define MCP23017_INTCONB_R 	  0x09
#define MCP23017_IOCONA_R	    0x0A
#define MCP23017_IOCONB_R 	  0x0B
#define MCP23017_GPPUA_R 	    0x0C
#define MCP23017_GPPUB_R 	    0x0D
#define MCP23017_INTFA_R 	    0x0E 
#define MCP23017_INTFB_R 	    0x0F
#define MCP23017_INTCAPA_R 	  0x10 
#define MCP23017_INTCAPB_R 	  0x11 
#define MCP23017_GPIOA_R 	    0x12 
#define MCP23017_GPIOB_R 	    0x13 
#define MCP23017_OLATA_R 	    0x14 
#define MCP23017_OLATB_R	    0x15 




bool io_expander_init(void);
void io_expander_write_reg(uint8_t reg, uint8_t data);
uint8_t io_expander_read_reg(uint8_t);
#endif
