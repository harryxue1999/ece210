//*****************************************************************************
// main.c for A/D and D/A
// Author: Parker and Harry
//Modified by Allie
//*****************************************************************************
#include "lab_buttons.h"

/******************************************************************************
 * Global Variables
 *****************************************************************************/



//*****************************************************************************
//*****************************************************************************

int 
main(void)
{
  ece210_initialize_board();
		
  ece210_lcd_add_msg("Audio Test Code A/D",TERMINAL_ALIGN_CENTER,LCD_COLOR_BLUE);
	ece210_lcd_add_msg("Parker and Harry",TERMINAL_ALIGN_CENTER,LCD_COLOR_YELLOW);
		

}	// end main
