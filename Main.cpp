/*
Author: Duncan McIntosh

Note: The game may be to close (by losing, winning, leaving [esc]).

Objective: 
	Create a small game where the player must use nthe arow keys to avoid bouncing enemies, and enemies that follow them. 
	If the player gets hit while they're not holding the spacebar they lose health.

Object Description:
	Main.cpp
		Initialize Allegro and run the game.
	Main.h
		Initialize all the Header files and needed Libraries.

	Game.h
		Initialize all the variables, the constructor (and descrutor), Run, Draw and Update functions, which control the game.
	Game.cpp
		Constructor
			Initialize the variables (player location, counters, and bmps) and the Enemy types
		Run
			Loop the program - Update, Draw, Rest
		Update
			Player movement - If they hit space, switch sprites and stop moving.
			Collision - If the player hits an enemy, send them off-screen. If the space bar was held increase the players score, if not, lose 1 health point.
			Score - If score increases, change the score sprite. If they remove all the enemies, they win.
		Draw - Use the Render class to display, the background, player, enemies, health and score (in that order)

	Player.h
		Initialize the Get/Set functions for location, speed, health (because all their variables are private) and the collision functions
	Player.cpp
		Constructor
			Initialize the location, bmp and health
		SetX/GetX/SetY/GetY
			They're private, so they must have functions to retrieve and return them.
		InRect/Collision
			Enables collision between the player and the enemy entities
		Move
			Moves the position according to the speed (which is set in Game.cpp\Update)
		GetH/SetH
			Health is not being added, so when SetH is called, it decreases the players health (newH = -1)

	Enemy.h
		Initialize variables
	Enemy.cpp
		Constructor
			Give a random position by defeault - which is reset at another random location by the game
		Move
			Type is assigned in Game.cpp
			Enemy if type 1 - Moves randomly and bounces off walls
			Enemy if type 2 - Moves towards the player at a reduced speed (so that the player can escape)
			
	Render.cpp + Render.h
		The game is rendered through this function each frame.
		I didn't know how to render Score+Health images through the player function, so gave them their own render functions, because I wanted them displayed on screen.

	Score.h
		The score is private, so there's Get/Set functions for the score.
	Score.cpp
		While originally meant to hold the score images (now in Game.cpp) it wasn't working, so it was relegated to help render the score by passing it to the render function.
		The score is private, hence why there's a SetS & GetS functions which pass it outside the class. Everytime SetS is called the score is increased.

	Health.cpp + Health.h
		The only purpose of this class is to pass the health images to the render function, I couldn't do it through the Player class.

*/
#include "Main.h"

//global variable for display
ALLEGRO_DISPLAY* display = NULL; //ALLEGRO_DISPLAY is a "user defined type" in Allegro. * shows a pointer

//initialzie Allegro components
void InitAllegro(int W, int H)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	display = al_create_display(W, H);
	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
}

//End and clean up Allegro components
void EndAllegro()
{
	al_destroy_display(display);
}


//main function
void main()
{
	srand(time(NULL));

	//initialize allegro
	int sw = WIDTH;
	int sh = HEIGHT;
	InitAllegro(sw, sh);

	//create main object
	Game game;

	game.Run();

	//clean up
	EndAllegro();
}