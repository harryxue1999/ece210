//*****************************************************************************
// main.c for A/D and D/A
// Author: Parker and Harry
//Modified by Allie
//*****************************************************************************
#include "lab_buttons.h"
#include <stdlib.h>

/******************************************************************************
 * Global Variables
 *****************************************************************************/
#define SCREEN_HEIGHT 320
#define SCREEN_WIDTH 240
#define FPS 20 // frames per second
#define BLOCK_SIZE 10
#define MAX_LENGTH 10
#define SNAKE_COLOR LCD_COLOR_GREEN
#define APPLE_COLOR LCD_COLOR_RED
void shift(int arr[MAX_LENGTH][2]);
void push (int arr[MAX_LENGTH][2], int dir);
void display_snake(int arr[MAX_LENGTH][2]);
bool apple_eaten (int arr[MAX_LENGTH][2]);
bool snake_hit (int arr[MAX_LENGTH][2]);
//*****************************************************************************
//*****************************************************************************

// Snake length
int snake_length = 2;
int apple[2] = {SCREEN_WIDTH / BLOCK_SIZE / 2, SCREEN_HEIGHT / BLOCK_SIZE / 2};

int main(void)
{
  ece210_initialize_board();
		
  //ece210_lcd_add_msg("Snake",TERMINAL_ALIGN_CENTER,LCD_COLOR_BLUE);
	//ece210_lcd_add_msg("Parker and Harry",TERMINAL_ALIGN_CENTER,LCD_COLOR_YELLOW);
	
	// Previous snake positions

	int coords[MAX_LENGTH][2] = {{1,1}};

	
	// Direction: 0: up, 1: right, 2: down, 3: left
	int dir = 1;
	
	int curX = 0, curY = 0;
	
	bool eaten = false;
	
	while (!snake_hit(coords) && snake_length < MAX_LENGTH) {
		
		if (AlertButtons) {
			AlertButtons = false;
			
			if (btn_up_pressed() && dir != 2) dir = 0;
			if (btn_right_pressed() && dir != 3) dir = 1;
			if (btn_down_pressed() && dir != 0) dir = 2;
			if (btn_left_pressed() && dir != 1) dir = 3;
			
		}
		
		// increase snake length if apple is eaten
		if (apple_eaten(coords)) {
			push(coords, dir);
			apple[0] = rand() % (SCREEN_WIDTH / BLOCK_SIZE);
			apple[1] = rand() % (SCREEN_HEIGHT / BLOCK_SIZE);
		}
		
		shift(coords);
		push(coords, dir);
		
		display_snake(coords);
		
	
		
		ece210_wait_mSec(1000/FPS);
	}
	
	// Clear screen and game over
	ece210_lcd_draw_rectangle(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, LCD_COLOR_BLACK);

	if (snake_length != MAX_LENGTH) ece210_lcd_add_msg("You Lose!", TERMINAL_ALIGN_CENTER,LCD_COLOR_BLUE);
	else ece210_lcd_add_msg("You Win!", TERMINAL_ALIGN_CENTER,LCD_COLOR_BLUE);
 
}	// end main

void shift (int arr[MAX_LENGTH][2]) {
	// Clears first position
	ece210_lcd_draw_rectangle(arr[0][0] * BLOCK_SIZE, BLOCK_SIZE, arr[0][1] * BLOCK_SIZE, BLOCK_SIZE, LCD_COLOR_BLACK);
	for (int i = 0; i < snake_length - 1; i++) {
		arr[i][0] = arr[i+1][0];
		arr[i][1] = arr[i+1][1];
	}
	
	snake_length--;
}

void push (int arr[MAX_LENGTH][2], int dir) {
	// Left/right direction changed
	int new_x, new_y;
	
	if (dir % 2 == 1) {
		new_y = arr[snake_length - 1][1];
		new_x = arr[snake_length - 1][0] - (dir - 2);
	}
	
	// Up/down direction changed
	else {
		new_x = arr[snake_length - 1][0];
		new_y = arr[snake_length - 1][1] + (dir - 1);
	}
	
	if (new_x < 0) new_x = SCREEN_WIDTH / BLOCK_SIZE - 1;
	else if (new_x >= SCREEN_WIDTH / BLOCK_SIZE) new_x = 0;
	
	if (new_y < 0) new_y = SCREEN_HEIGHT / BLOCK_SIZE - 1;
	else if (new_y >= SCREEN_HEIGHT / BLOCK_SIZE) new_y = 0; 
	
	arr[snake_length][0] = new_x;
	arr[snake_length][1] = new_y;
	
	snake_length++;
}

void display_snake (int arr[MAX_LENGTH][2]) {
	for (int i = 0; i < snake_length; i++) {
		ece210_lcd_draw_rectangle(arr[i][0] * BLOCK_SIZE, BLOCK_SIZE, arr[i][1] * BLOCK_SIZE, BLOCK_SIZE, SNAKE_COLOR);
	}
	
	ece210_lcd_draw_rectangle(apple[0] * BLOCK_SIZE, BLOCK_SIZE, apple[1] * BLOCK_SIZE, BLOCK_SIZE, APPLE_COLOR);
	
}

bool apple_eaten (int arr[MAX_LENGTH][2]) {
	return arr[snake_length - 1][0] == apple[0] && arr[snake_length - 1][1] == apple[1];
}

bool snake_hit (int arr[MAX_LENGTH][2]) {
	for (int i = 0; i < snake_length - 1; i++) {
		int head_pos[2] = { arr[snake_length - 1][0], arr[snake_length - 1][1] };
		
		if (head_pos[0] == arr[i][0] && head_pos[1] == arr[i][1]) return true;
	}
	return false;
}
