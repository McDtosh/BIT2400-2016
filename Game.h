/*
By: Duncan McIntosh
Whole description in Main.cpp

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
*/
#pragma once



class Game
{
public:
	//variables
	ALLEGRO_KEYBOARD_STATE key_state; //ALLEGRO_KEYBOARD_STATE is a "user define type" in Allegro
	ALLEGRO_MOUSE_STATE mouse_state;

	//Render render;
	Players players;

	Score score;

	Health health[HEALTH];

	Render render;

	Enemy enemy[NUM_ENEMIES];

	int r;
	int count;

	ALLEGRO_BITMAP* bg;

	bool end;

	//functions
	Game();
	~Game();
	void Run();
	void Update();
	void Draw();
};
