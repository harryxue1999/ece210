// Copyright (c) 2015-16, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
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

#ifndef __ECE210_API_H__
#define __ECE210_API_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "TM4C123.h"

extern volatile bool AlertTouch;
extern volatile bool AlertButtons;
extern void GPIOF_Handler(void);
extern volatile bool ALERT_ADC;
extern volatile bool ALERT_AUDIO_COMP;

#if  !defined(TERMINAL_ALIGN_LEFT)
  #define TERMINAL_ALIGN_LEFT     0
  #define TERMINAL_ALIGN_RIGHT    1
  #define TERMINAL_ALIGN_CENTER   2
#endif

#if !defined (LCD_COLOR_WHITE)
  #define LCD_COLOR_WHITE			0xFFFF
  #define LCD_COLOR_BLACK			0x0000
  #define LCD_COLOR_RED			  0xF800
  #define LCD_COLOR_GREEN			0x07E0
  #define LCD_COLOR_GREEN2		0xB723
  #define LCD_COLOR_BLUE			0x001F
  #define LCD_COLOR_BLUE2			0x051D
  #define LCD_COLOR_YELLOW		0xFFE0
  #define LCD_COLOR_ORANGE		0xFBE4
  #define LCD_COLOR_CYAN			0x07FF
  #define LCD_COLOR_MAGENTA		0xA254
  #define LCD_COLOR_GRAY			0x7BEF 
  #define LCD_COLOR_BROWN			0xBBCA
#endif

#define PS2_CENTER						0x00
#define PS2_UP								0x01
#define PS2_DOWN							0x02
#define PS2_LEFT							0x03
#define PS2_RIGHT							0x04

#define PS2_THRESHOLD_X_HI  0xC00
#define PS2_THRESHOLD_X_LO  0x400
#define PS2_THRESHOLD_Y_HI  0xC00
#define PS2_THRESHOLD_Y_LO  0x400
  

/********************************************************************************
* Summary: 
*   Reads the values on the 4 bit switches (S600).  
*
* Returns
*   An 8-bit value where the upper four bits are always 0, and the lower 4 bits
*   represent which bit switches are turned on (1) of turned off (0)
*******************************************************************************/
uint8_t ece210_switches_read(void);


/********************************************************************************
* Summary: 
*   Reads the values on the 4 directional push buttons.  
*
* Returns
*   An 8-bit value.  
*     Bit 7       0
*     Bit 6       0
*     Bit 5       0
*     Bit 4       0
*     Bit 3       1 for RIGHT Pressed.  0 for RIGHT NOT Pressed.
*     Bit 2       1 for LEFT Pressed.  0 for LEFT NOT Pressed.
*     Bit 1       1 for DOWN Pressed.  0 for DOWN NOT Pressed.
*     Bit 0       1 for UP Pressed.  0 for UP NOT Pressed.
*******************************************************************************/
uint8_t ece210_buttons_read(void);

/********************************************************************************
* Summary: 
*   Writes the 8-bit parameter to the 8 RED leds. 
*
* Returns
*******************************************************************************/
void ece210_red_leds_write(uint8_t leds);

/********************************************************************************
* Summary: 
*   Writes the 8-bit parameter to the rgb led on the Tiva Launchpad. 
*
* Returns
*******************************************************************************/
void ece210_tiva_rgb_write(uint8_t leds);

/********************************************************************************
* Summary: 
*   Sets the color of the selected WS2812B LED
*
* Returns
*******************************************************************************/
void ece210_ws2812b_write(uint8_t led_num, uint8_t red, uint8_t green, uint8_t blue);

/*******************************************************************************
* Function Name: ece210_lcd_add_msg
********************************************************************************
* Summary:
*   Prints a message to the lowest line of the LCD screen.  Any previous
*   messages are scrolled up.  The LCD can display up to 16 lines of data.
*
* Return:
*  void
*
* Examples
*   ece210_lcd_add_msg("Hello WORLD", TERMINAL_ALIGN_RIGHT, LCD_COLOR_YELLOW);
*   ece210_lcd_add_msg("Goodbye.", TERMINAL_ALIGN_LEFT, LCD_COLOR_RED);
*   ece210_lcd_add_msg("Go Bucky!.", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
*******************************************************************************/ 
void ece210_lcd_add_msg(  char *msg, uint8_t alignment, uint32_t color );


/*******************************************************************************
* Function Name: ece210_wait_mSec
********************************************************************************
* Summary:
*   Busy waits for a set number of milliseconds
*
* Return:
*  void
*
*******************************************************************************/ 
void ece210_wait_mSec(  uint32_t mSeconds );

/*******************************************************************************
* Function Name: ece210_wait_uSec
********************************************************************************
* Summary:
*   Busy waits for a set number of microseconds
*
* Return:
*  void
*
*******************************************************************************/ 
void ece210_wait_uSec(  uint32_t uSeconds );


/********************************************************************************
* Summary: 
*   Returns the raw value of the x direction of the PS2 joystick  
*
* Returns

*******************************************************************************/
uint16_t ece210_ps2_read_x(void);

/********************************************************************************
* Summary: 
*   Returns the raw value of the y direction of the PS2 joystick  
*
* Returns

*******************************************************************************/
uint16_t ece210_ps2_read_y(void);


/********************************************************************************
* Summary: 
*   Returns the raw value of the x direction of the PS2 joystick  
*
* Returns

*******************************************************************************/
uint8_t ece210_ps2_read_position(void);

/********************************************************************************
* Summary: 
*   Sets a single pixel to a given color 
*
* Returns

*******************************************************************************/
void ece210_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

/********************************************************************************
* Summary: 
*   Sets a single pixel to a given color 
*
* Returns

*******************************************************************************/
void ece210_lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

/*******************************************************************************
* Function Name: ece210_lcd_draw_rectangle
********************************************************************************
* Summary:
*   Draws a solid rectangle witht he supplied color.  The position of the
*   rectangle using the lower right hand corner of the rectangle.
*
* Return:
*  void
*******************************************************************************/ 
void ece210_lcd_draw_rectangle  (uint16_t x_start, uint16_t x_len, uint16_t y_start, uint16_t y_len, uint16_t color);


/*******************************************************************************
* Function Name: ece210_lcd_draw_image
********************************************************************************
* Summary: Prints an image where the lower right corner of the image is
*          positioned at the coordinates x_start, y_start.
* Returns:
*  Nothing
*******************************************************************************/
void ece210_lcd_draw_image(
    uint16_t x_start, 
    uint16_t image_width_bits, 
    uint16_t y_start, 
    uint16_t image_height_pixels, 
    const uint8_t *image, 
    uint16_t fColor, 
    uint16_t bColor  
);

/********************************************************************************
* Summary: 
*   Draws a 1-pixel wide line
*
* Returns

*******************************************************************************/
void ece210_lcd_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);

 /*******************************************************************************
* Function Name: ece210_lcd_draw_filled_circle
********************************************************************************
* Summary: Draws a circle on the LCD
* Returns:
*  Nothing
*******************************************************************************/ 
void ece210_lcd_draw_circle(int16_t x0, int16_t y0, int16_t radius, uint32_t color);

 /*******************************************************************************
* Function Name: ece210_lcd_print_string
********************************************************************************
* Summary: Prints a string at the specificed location.
* Returns:
*  Nothing
*******************************************************************************/ 
void ece210_lcd_print_string(char* string, uint16_t x_pos, uint16_t y_pos, uint16_t fg_color, uint16_t bg_color);

  
/********************************************************************************
* Summary: 
*   Initializes system resources so that data from the microphone can be
*   examined.
*
* Returns

*******************************************************************************/
bool ece210_audio_init(uint32_t micro_seconds);

/********************************************************************************
* Summary: 
*   Returns the raw reading of the audio signal
*
* Returns

*******************************************************************************/
uint16_t ece210_audio_read(void);


/********************************************************************************
* Summary: 
*   Sets the headphone data output 
*
* Returns

*******************************************************************************/
void ece210_audio_headphone_out(uint16_t data);

/********************************************************************************
* Summary: 
*   Write Data to the buzzer 
*
* Returns

*******************************************************************************/
void ece210_audio_buzzer_out(uint16_t data);


/********************************************************************************
* Summary: 
*   Configures the wirless radio's local and remote IDs.  Each ID needs to be
*   5 bytes.
*
* Returns

*******************************************************************************/
void ece210_wireless_init(uint8_t local_id, uint8_t remote_id);

/********************************************************************************
* Summary: 
*   Sends a 32-bit value to the remote board.
*
* Returns

*******************************************************************************/
bool ece210_wireless_send(uint32_t data);

/********************************************************************************
* Summary: 
*   Determines if a new 32-bit value has been received from the remote board.
*
* Returns

*******************************************************************************/
bool ece210_wireless_data_avaiable(void);

/********************************************************************************
* Summary: 
*   Returns a 32-bit value from the remote board.
*
* Returns

*******************************************************************************/
uint32_t ece210_wireless_get(void);

/*******************************************************************************
* Function Name: ece210_platform_initialize_board
********************************************************************************
* Summary:
*   Configures the hardware resources on the ECE353/210 board
*
* Return:
*  void
*
*******************************************************************************/ 
void ece210_initialize_board(void);

//*****************************************************************************
//*****************************************************************************
void DisableInterrupts(void);

//*****************************************************************************
//*****************************************************************************
void EnableInterrupts(void);


#endif
