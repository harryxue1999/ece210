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

#ifndef __LCD_FONTS_H__
#define __LCD_FONTS_H__

#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"

typedef struct {
  uint16_t    font_width_bits;
  uint16_t    font_offset;
} FONT_CHAR_INFO;

typedef struct {
  uint16_t        character_height;
  char            start_character;
  char            end_character;
  const FONT_CHAR_INFO * font_info;
  const uint8_t        * font_table;  
} FONT_INFO;


/* Font data for Verdna 12pt */
extern const FONT_INFO calibri_14ptFontInfo;
extern const FONT_INFO calibri_48ptFontInfo;

bool lcd_print_char(  
                    const FONT_INFO *font, 
                    char c, 
                    uint16_t *x_pos, 
                    uint16_t y_pos, 
                    uint16_t fg_color, 
                    uint16_t bg_color,
                    uint8_t rounded_corners
);

bool lcd_print_string( 
                      const FONT_INFO *font, 
                      char* string, 
                      uint16_t x_pos, 
                      uint16_t y_pos, 
                      uint16_t fg_color, 
                      uint16_t bg_color, 
                      lcd_justify_t justify,
                      bool rounded_corners
);

#endif
