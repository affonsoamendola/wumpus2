/*  Copyright 2018 Affonso Amendola
    
    This file is part of Fofonso's Wumpus Hunt 2.

    Wumpus 2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Wumpus 2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Wumpus 2.  If not, see <https://www.gnu.org/licenses/>
*/

#include <bios.h>
#include <dos.h>
#include <memory.h>
#include <math.h>
#include <time.h>

#include <keyb.h>

#include <conio.h>
#include <io.h>

#include <vga.h>

#define True 1
#define False 0

#define STATE_GAME 0
#define STATE_LEVEL_SELECT 1
#define STATE_OPTIONS_MENU 2
#define STATE_MAIN_MENU 3

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3

#define OBJ_PLAYER 1
#define OBJ_WALL 2
#define OBJ_PUSHABLE 4

int CURRENT_GAME_STATE = STATE_MAIN_MENU;
int CURRENT_LEVEL = 0;

int PLAYER_CONTROL = True;

int GAME_RUNNING = True;

int WAS_DIRECTIONAL_PRESSED = False;
int WHAT_DIRECTIONAL_PRESSED = DIRECTION_UP;

typedef struct
{
	int x;
	int y;
	int flags;
} Object;

Object PLAYER_OBJECT;

void main_loop();
void game_loop();
void update_logic();

void init_game();
void main_menu();

void show_splash();

void main_loop()
{
    if(CURRENT_GAME_STATE == STATE_GAME)
    {
        //game_loop();
    }
    else if(CURRENT_GAME_STATE == STATE_MAIN_MENU)
    {
        main_menu();
    }
}
/*
void game_loop()
{
    if(ANIM_PLAYING == False)
    {
        if(PLAYER_CONTROL == True)
        {
            handle_input();
        }
        update_logic(); 
    }
    
    draw_background();
    draw_world();
    draw_objects();
    draw_hud();

    handle_audio();
    wait_for_vblank();
}
*/
/*
void update_logic()
{
	Object* object;

	if(WAS_DIRECTIONAL_PRESSED == True)
	{
		object = adjacent_player(WHAT_DIRECTIONAL_PRESSED);
		//Find out what is in the direction the player wanted to move

		if(object != NULL)
		{
			if(((*object).flags & OBJ_PUSHABLE) != 0)
			{
				//IF OBJECT IS PUSHABLE, BEGIN PUSHING SAID OBJECT
				start_move_object(object, WHAT_DIRECTIONAL_PRESSED);
				start_move_object(PLAYER_OBJECT, WHAT_DIRECTIONAL_PRESSED);
			
			}
			else if(((*object).flags & OBJ_WALL) != 0)
			{
				//LITERALLY NOTHING HAPPENS, MIGHT ADD A HUMPF NOISE EVENTUALLY, OR A TENTATIVE MOVE.
			}
		}
		else
		{
			//IF object is NULL, it means that the path is clear, so the player can just move there.
			start_move_object(PLAYER_OBJECT, WHAT_DIRECTIONAL_PRESSED);
		}
	}	
}
*/
/*
void init_game()
{
	PLAYER_OBJECT.x = 0;
	PLAYER_OBJECT.y = 0;
	PLAYER_OBJECT.flags |= OBJ_PLAYER;
}
*/

void draw_menu()
{
	//DRAW BACKGROUND

	//DRAW STATIC TEXT
	
	//DRAW DYNAMIC TEXT
}


void main_menu()
{
	
    draw_menu();
    handle_input();
    
    /*
    if(enter_pressed)
    {
        if(current_choice == MENU_NEW_GAME)
        {
            CURRENT_GAME_STATE = STATE_GAME;
            init_game();
        }
        else if (current_choice == MENU_LEVEL_SELECT)
        {
            CURRENT_GAME_STATE = STATE_LEVEL_SELECT;
        }
        else if (current_choice == MENU_OPTIONS)
        {
            CURRENT_GAME_STATE = STATE_OPTIONS_MENU;
        }
        else if (current_choice == MENU_EXIT)
        {
            show_dialog_box(SCREEN_WIDTH/2-200, 400, SCREEN_HEIGHT/2-100, 200, random_exit_message());
        }
    }
    */
}

void show_splash()
{

    flip_front_page();
    getch();
}

void init_game()
{
	set_graphics_mode(GRAPHICS_MODEX);
}

int main()
{
	init_game();
    show_splash();
    /*
    while(GAME_RUNNING)
    {
        main_loop();
    }
    show_credits();
    print_order_info();*/
}