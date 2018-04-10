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

#ifndef __KEYPAD_H__
#define __KEYPAD_H__


#include <stdint.h>
#include "i2c.h"
#include "boardUtil.h"

#define CY8CMBR3110_I2C_ADDR   			0x37
#define CY8CMBR3110_CONFIG_FILE_BYTES	128


#define CY8CMBR3110_SENSOR_EN_R			0x00
#define CY8CMBR3110_SPO_CFG_R			0x4C
#define CY8CMBR3110_CTRL_CMD_R			0x86
#define CY8CMBR3110_DEVICE_ID_R			0x90
#define CY8CMBR3110_BUTTON_STAT_R		0xAA

#define CY8CMBR3110_DEVICE_ID_M			2562
#define CY8CMBR3110_SPO_CFG_SP01_M		0x70
#define CY8CMBR3110_SPO_CFG_SP01_IRQ	0x40
#define CY8CMBR3110_SENSOR_EN_M			0x01EF
#define CY8CMBR3110_CTRL_CMD_RESET		0xFF

// Lower 8 Bits
#define	KEYPAD_6_M			( 1 << 0 ) // CS0	
#define KEYPAD_DIV_M		( 1 << 1 ) // CS1
#define	KEYPAD_4_M			( 1 << 2 ) // CS2
#define	KEYPAD_5_M			( 1 << 3 ) // CS3
																	 // CS4
#define	KEYPAD_1_M			( 1 << 5 ) // CS5
#define	KEYPAD_2_M			( 1 << 6 ) // CS6
#define	KEYPAD_3_M			( 1 << 7 ) // CS7
#define KEYPAD_MUL_M		( 1 << 8 ) // CS8
																	 // CS9
	


// Upper 8 Bits
#define	KEYPAD_EQ_M			( 1 << (16 +0) ) // CS0	
#define KEYPAD_PLUS_M		( 1 << (16 +1) ) // CS1
#define	KEYPAD_0_M			( 1 << (16 +2) ) // CS2
#define	KEYPAD_DP_M			( 1 << (16 +3) ) // CS3
																	       // CS4
#define	KEYPAD_7_M			( 1 << (16 +5) ) // CS5
#define	KEYPAD_8_M			( 1 << (16 +6) ) // CS6
#define	KEYPAD_9_M			( 1 << (16 +7) ) // CS7
#define KEYPAD_SUB_M		( 1 << (16 +8) ) // CS8
																	       // CS9
typedef enum {
  ZERO, 
  ONE, 
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
	EIGHT,
	NINE,
	PLUS,
	SUB,
	MUL,
	DIV,
	DP,
	EQ
} keypad_buttons_t;

//*****************************************************************************
// Initialize devices used for keypad
//*****************************************************************************
i2c_status_t keypad_init(void);

//*****************************************************************************
// Reads the device ID from a CY8CMBR3110
//*****************************************************************************
i2c_status_t keypad_read_device_info(uint32_t base_addr, uint16_t *device_id);

//*****************************************************************************
// Reads the button status of a Cap Sense Controllers
//*****************************************************************************
i2c_status_t keypad_read_buttons(uint32_t *buttons);

//*****************************************************************************
// Test the keypad
//*****************************************************************************
void keypad_test(void);
	
	
#endif
