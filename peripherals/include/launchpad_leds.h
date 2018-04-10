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

#ifndef __LAUNCHPAD_IO__
#define __LAUNCHPAD_IO__
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "TM4C123.h"

// ADD CODE 01
#define   RED_PIN       1
#define   BLUE_PIN      2
#define   GREEN_PIN     3
#define   SW1_PIN       4
#define   SW2_PIN       0

#define   RED_M     (1 << RED_PIN)        // RED LED is connected to PF.1   ( Port F, Pin 1)
#define   BLUE_M    (1 << BLUE_PIN)       // BLUE LED is connected to PF.2  ( Port F, Pin 2)
#define   GREEN_M   (1 << GREEN_PIN)      // GREEN LED is connected to PF.3 ( Port F, Pin 3)

#define   SW1_M     (1 << SW1_PIN)
#define   SW2_M     (1 << SW2_PIN)


/*******************************************************************************
* Function Name: lp_leds_init()
********************************************************************************
* Summary:
* Configures the GPIO pins connected to the Launchpad
*
*******************************************************************************/
void lp_leds_init(void);

/*******************************************************************************
* Function Name: lp_leds_init()
********************************************************************************
* Summary:
* Configures the digital comparators to use SSMUX0.  The function assumes that
* the ADC peripheral has already been turned on.
*
* Return:
*  void
*
*******************************************************************************/
void lp_leds_(void);

#endif
