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

#include <conio.h>
#include <io.h>

#define STATE_GAME 0
#define STATE_LEVEL_SELECT 1
#define STATE_OPTIONS_MENU 2
#define STATE_MAIN_MENU 3

#define ENTITY_TYPE_ROCK 1;

#define ROCK_STATE_DEFAULT 0;

int CURRENT_GAME_STATE = STATE_MAIN_MENU;
int CURRENT_LEVEL = 0;

int TIME_STATE = 0;

struct _Entity 
{
    int type;
    int posX;
    int posY;
    int state;
    int anim_frame;
} entity;

#define ENTITY_LIST_SIZE 64;

entity entity_list[ENTITY_LIST_SIZE];

void update_logic()
{
    if(TIME_STATE >= 100)
    {
        TIME_STATE = 0;
    }
    else
    {
        TIME_STATE++;
    }

    for(int i = 0; i < ENTITY_LIST_SIZE; i++)
    {
        
    }
}

void game_loop()
{
    update_logic();

    handle_input();

    update_physics();

    draw_background();
    draw_world();
    draw_entities();
    draw_hud();

    handle_audio();
}

void main_menu()
{
    draw_menu_background();
    draw_menu_text();
    check_input();
    if(enter_pressed)
    {
        if(current_choice == MENU_NEW_GAME)
        {
            CURRENT_GAME_STATE = STATE_GAME;
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
}

int main()
{
    show_splash();
    start_game();
}