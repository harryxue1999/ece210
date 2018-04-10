// Copyright (c) 2016, Joe Krachey
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

#ifndef __LCD_BUTTONS_H__
#define __LCD_BUTTONS_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lcd.h"

typedef struct {
  int16_t               x;
  int16_t               y;
  uint8_t               width;
  uint8_t               height;
  const uint8_t        * image; 
  int16_t               range;
  uint16_t              fg_color;
  uint16_t              bg_color;
  bool                  active;
} LCD_BUTTON_t;

/*******************************************************************************
* Function Name: button_draw
********************************************************************************
* Summary:
*
*
* Return:
*  void
*
*******************************************************************************/
void button_draw( LCD_BUTTON_t *button_array, uint8_t button_index);

/*******************************************************************************
* Function Name: button_clear
********************************************************************************
* Summary:
*
*
* Return:
*  void
*
*******************************************************************************/
void button_clear( LCD_BUTTON_t *button_array, uint8_t button_index);

/*******************************************************************************
* Function Name: button_detect
********************************************************************************
* Summary:
*
*
* Return:
*  void
*
*******************************************************************************/
int16_t button_detect( 
  LCD_BUTTON_t *button_array, 
  uint8_t array_size, 
  int16_t x, 
  int16_t y
);

/*******************************************************************************
* Function Name: button_register
********************************************************************************
* Summary:
*
*
* Return:
*  void
*
*******************************************************************************/
void button_init( 
  LCD_BUTTON_t          *button_array,
  int16_t           index,
  int16_t           x,
  int16_t           y,
  uint8_t           width,
  uint8_t           height,
  const uint8_t     * image, 
  int16_t           range,
  uint16_t          fg_color,
  uint16_t          bg_color,
  bool              active
);

  /*******************************************************************************
* Function Name: button_deactivate_buttons
********************************************************************************
* Summary:
*
*
* Return:
*  void
*
*******************************************************************************/
void button_deactivate_buttons( LCD_BUTTON_t *button_array, uint16_t num_buttons);
  
#endif
