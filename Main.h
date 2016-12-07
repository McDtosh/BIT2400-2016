//By: Duncan McIntosh
//Description in Main.cpp
#pragma once

//libraries
#include <stdio.h>
//for sqrt (square root)
#include <math.h>
#include "time.h"
#include "allegro5/allegro.h"
//use image addon for loading images, dialog boxes, and primitive shapes
#include <allegro5/allegro_image.h>
//use primitives addon to draw primitive shapes like line
#include <allegro5/allegro_primitives.h>
//our header files
//include the header file for any class we use in this source file
//there are two methods:
//1. include header files only in cpp files (no #include in headers)
//2. include header files in any .h or .cpp files that need them

//The defines are in the header file because I use most in more than 1 file
#define WIDTH 640	//Width of display
#define HEIGHT 480	//Height of display

#define NUM_ENEMIES 10	//Number of enemies
#define HEALTH 3		//Amount of Health

#include "Enemy.h"
#include "Players.h"
#include "Score.h"
#include "Health.h"
#include "Render.h"
#include "Game.h"

