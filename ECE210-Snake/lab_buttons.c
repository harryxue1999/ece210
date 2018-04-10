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

#include "lab_buttons.h"


#define BTN_RIGHT_MASK  0x08
#define BTN_LEFT_MASK   0x04
#define BTN_UP_MASK     0x01
#define BTN_DOWN_MASK   0x02


/********************************************************************************
* Summary: 
*   Returns 'true' if the up directional button is pressed
*******************************************************************************/ 
bool  btn_up_pressed(void)
{
  uint8_t data = 0;
  
  data = ece210_buttons_read();
  
  if (data == BTN_UP_MASK)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/********************************************************************************
* Summary: 
*   Returns 'true' if the down directional button is pressed
*******************************************************************************/ 
bool  btn_down_pressed(void)
{
  uint8_t data = 0;
  data = ece210_buttons_read();
  
  if (data == BTN_DOWN_MASK)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/********************************************************************************
* Summary: 
*   Returns 'true' if the left directional button is pressed
*******************************************************************************/ 
bool  btn_left_pressed(void)
{
  uint8_t data = 0;
  data = ece210_buttons_read();
  
  if (data == BTN_LEFT_MASK)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/********************************************************************************
* Summary: 
*   Returns 'true' if the right directional button is pressed
*******************************************************************************/ 
bool  btn_right_pressed(void)
{
  uint8_t data = 0;
  data = ece210_buttons_read();
  
  if (data == BTN_RIGHT_MASK)
  {
    return true;
  }
  else
  {
    return false;
  }
}
