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

#ifndef __LCD_TERMINAL_H__
#define __LCD_TERMINAL_H__

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "lcd.h"
#include "lcd_fonts.h"

#define TERMINAL_LINE_HEIGHT    20    // in pixels
#define TERMINAL_NUM_LINES      16    // max number of lines
#define TERMINAL_NUM_CHARS      80

#define TERMINAL_ALIGN_LEFT     0
#define TERMINAL_ALIGN_RIGHT    1
#define TERMINAL_ALIGN_CENTER   2

#define TERMINAL_INPUT_LEN      80

typedef struct
{
  char msg[TERMINAL_NUM_CHARS+1];
  lcd_justify_t alignment;
  uint32_t fg_color;
  uint32_t bg_color;
  bool     active;
} LCD_Terminal_Line_t;

typedef struct
{
  LCD_Terminal_Line_t line[TERMINAL_NUM_LINES];
  uint8_t start_line;
  uint8_t end_line;
} LCD_Terminal_t;

typedef struct
{
  const FONT_INFO * font;   
  char c;
  uint8_t ascii_min;
  uint8_t ascii_max;
  uint16_t x_pos;
  uint16_t y_pos;
} LCD_Terminal_Char_t;

/*******************************************************************************
* Function Name: terminal_init_screen
********************************************************************************
* Summary: Initializing the terminal is simply drawing a black box from the
* starting line to the end line
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_init_screen(uint8_t start_line, uint8_t end_line);

  

/*******************************************************************************
* Function Name: terminal_clear_text_entry
********************************************************************************
* Summary: The message is added to the start line.  All other messages are 
* shifted up by one and then the entire terminal is updated.
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_add_msg(  
  char *msg,
  lcd_justify_t alignment,
  uint32_t color
 );

/*******************************************************************************
* Function Name: terminal_clear_text_entry
********************************************************************************
* Summary: The message is added to the start line.  All other messages are 
* shifted up by one and then the entire terminal is updated.
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_bubble_message(  
  char *msg,
  lcd_justify_t alignment,
  uint32_t color
 );

/*******************************************************************************
* Function Name: terminal_init_input_box
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_init_input_box(  
  uint16_t x_start, 
  uint16_t x_len, 
  uint16_t y_start, 
  uint16_t y_len,
  uint16_t fg_color,
  uint16_t bg_color,
  uint16_t border_width
 );

/*******************************************************************************
* Function Name: terminal_input_rotate_char
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_rotate_char( bool up);


/*******************************************************************************
* Function Name: terminal_input_next_char
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
bool terminal_input_next_char( void );

/*******************************************************************************
* Function Name: terminal_input_prev_char
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_prev_char( void );

/*******************************************************************************
* Function Name: terminal_input_upper_case
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_upper_case( void );

/*******************************************************************************
* Function Name: terminal_input_lower_case
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_lower_case( void );

/*******************************************************************************
* Function Name: terminal_input_symbols
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_symbols( void );


/*******************************************************************************
* Function Name: terminal_input_get_string
********************************************************************************
* Summary:
*
*
* Return:
*  
*
*******************************************************************************/
void terminal_input_get_string(char *msg);
#endif
