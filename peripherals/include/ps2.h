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
#ifndef __PS2_H__
#define __PS2_H__

#define STAFF   1
#define DCOMP_ENABLE  0



#if STAFF
#include <stdint.h>
#include <stdbool.h>

#include "gpio_port.h"
#include "adc.h"
#include "gptimer.h"
#include "driver_defines.h"

//=============================================================================
// STAFF STAFF STAFF STAFF STAFF STAFF STAFF STAFF STAFF STAFF STAFF STAFF 
//=============================================================================

typedef enum{
  PS2_DIR_UP,
  PS2_DIR_DOWN,
  PS2_DIR_LEFT,
  PS2_DIR_RIGHT,
  PS2_DIR_CENTER,
} PS2_DIR_t;





//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the directional buttons
//*****************************************************************************
#define   PS2_GPIO_ANALOG_BASE 			GPIOE_BASE
#define   PS2_X_DIR_PIN      				PE3
#define   PS2_X_DIR_CH							1
#define   PS2_Y_DIR_PIN      				PE2
#define   PS2_Y_DIR_CH							0

#define   PS2_ADC_BASE              ADC0_BASE

#define PS2_ADC_LOW_THRESHOLD		    0x0400
#define PS2_ADC_HIGH_THRESHOLD	    0x0C0

#define PS2_SAMPLE_TICKS						5000

// Set the analog channel for each direction
#define   PS2_X_ADC_CHANNEL  1
#define   PS2_Y_ADC_CHANNEL  0

#define ADC_LOW_THRESHOLD		0x0600
#define ADC_MID_THRESHOLD	  0x0800
#define ADC_HIGH_THRESHOLD	0x0A00

//*****************************************************************************
// Used to initialize the PS2 joystick for both the analog inputs and the 
// push button.  
//
// Configuration Info
//		Fill out relevant information in boardUtil.h.  boardUtil.h defines 
//		how various peripherals are physically connected to the board.
//*****************************************************************************
void ps2_initialize(void);

//*****************************************************************************
// Returns the most current reading of the X direction  Only the lower 12-bits
// contain data.
//*****************************************************************************
uint16_t ps2_get_x(void);

//*****************************************************************************
// Returns the most current reading of the Y direction.  Only the lower 12-bits
// contain data.
//*****************************************************************************
uint16_t ps2_get_y(void);

//*****************************************************************************
// STAFF: Returns if the pushbutton is currently pressed.
//*****************************************************************************
bool ps2_get_pressed(void);

//*****************************************************************************
// STAFF: Returns the most current direction that was pressed.
//*****************************************************************************
PS2_DIR_t ps2_get_direction(void);


//=============================================================================
// STUDENT STUDENT STUDENT STUDENT STUDENT STUDENT STUDENT STUDENT STUDENT
//=============================================================================
#else

#include <stdint.h>
#include <stdbool.h>

#include "gpio_port.h"
#include "adc.h"
#include "driver_defines.h"


// ADD CODE
// Define the base addresses for the GPIO port that is connected to the PS2 Joystick
#define   PS2_GPIO_BASE    GPIOE_BASE

// ADD CODE
// Define which pin number ( 0 through 7) each signal is connected to on the GPIO port.
// This pin number is NOT the value listed in the Pin Number column of the datasheet.  
// As an example, if the analog input was connected to pin PD2, you would set the pin
// number to 2.
#define   PS2_X_PIN_NUM      3
#define   PS2_Y_PIN_NUM      2

// Macros passed to the gpio functions that are used to configure the GPIO port.
#define   PS2_X_DIR_MASK     (1 << PS2_X_PIN_NUM)
#define   PS2_Y_DIR_MASK     (1 << PS2_Y_PIN_NUM)

// ADD CODE
// Define the base addresses of the the ADC you are going to use to either ADC0 or ADC1.
// Either will work.
#define   PS2_ADC_BASE     ADC0_BASE

// ADD CODE
// Set the analog channel for each direction.  Each analog channel is associated with a
// single GPIO pin.  Make sure to see table 13-1 to see how the GPIO pin maps to an 
// analog channel.  Specifically, look at the column Pin Name.
#define   PS2_X_ADC_CHANNEL  0
#define   PS2_Y_ADC_CHANNEL  1

/*******************************************************************************
* Function Name: ps2_initialize
********************************************************************************
* Initializes the GPIO pins connected to the PS2 Joystick.  It also configures
* ADC0 to use Sample Sequencer #3 to convert a programmable channel number.
*******************************************************************************/
void ps2_initialize(void);

/*******************************************************************************
* Function Name: ps2_get_x
********************************************************************************
*Returns the most current reading of the X direction  Only the lower 12-bits
* contain data.
********************************************************************************/
uint16_t ps2_get_x(void);

/*******************************************************************************
* Function Name: ps2_get_y
********************************************************************************
* Returns the most current reading of the Y direction.  Only the lower 12-bits
*  contain data.
********************************************************************************/
uint16_t ps2_get_y(void);

#endif


#endif
