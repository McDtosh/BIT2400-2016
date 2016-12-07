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
#include "Main.h"


Game::Game()
{
	//load a background bitmap
	bg = al_load_bitmap("bg.bmp");

	players.SetX(200);	//Player starting x coordinate
	players.SetY(200);	//Player starting y coordinate
	players.bmp = al_load_bitmap("player.bmp");	//Player bitmap

	count = HEALTH;	//This helps display the health

	for (int i = 0; i < HEALTH; i++)	//Display health
	{
		health[i].x = (10 + (i * 30));
		health[i].y = 10;
	}

	//loop for all enemies
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		enemy[i].x = rand()%(WIDTH - 20);	//Random enemy x coordinates
		enemy[i].y = rand()%(HEIGHT - 20);	//Random enemy y coordinates
		int ra = rand();
		//Random starting direction
		if (ra % 2 == 0)
		{
			enemy[i].sy = -1;
			enemy[i].sx = 1;
		}
		else if (ra % 3 == 0)
		{
			enemy[i].sy = 1;
			enemy[i].sx = -1;
		}
		else if (ra % 5 == 0)
		{
			enemy[i].sy = -1;
			enemy[i].sx = -1;
		}
		else 
		{
			enemy[i].sy = 1;
			enemy[i].sx = 1;
		}
		
		//Random number for which enemy types appear
		r = i + (rand() % (100 - i));
		if (r > 50)
		{
			enemy[i].bmp = al_load_bitmap("enemy.bmp");
			enemy[i].type = false;
		}
		else if (r <= 50)
		{
			enemy[i].bmp = al_load_bitmap("enemy2.bmp");
			enemy[i].type = true;
		}
	}

	end = false;	//Closes the game if true
}
Game::~Game()
{
	//release/destroy anything we have allocated/created in this class
	al_destroy_bitmap(bg);
}
void Game::Run()
{
	//main loop
	while (!end)
	{
		Update();
		Draw();
		al_rest(0.01);
	}

}
void Game::Update()
{
	//Initialize keyboard
	al_get_keyboard_state(&key_state);

	//end program
	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) //al_key_down checks the status of a key in the key_state structure
	{
		end = true;
	}
	//change player speed using arrow keys
	players.sx = players.sy = 0;
	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
	{
		players.sx = 3;
	}
	if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
	{
		players.sx = -3;
	}
	if (al_key_down(&key_state, ALLEGRO_KEY_UP))
	{
		players.sy = -3;
	}
	if (al_key_down(&key_state, ALLEGRO_KEY_DOWN))
	{
		players.sy = 3;
	}
	//If player holds down the space bar, change sprites and stop them from moving
	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		players.bmp = al_load_bitmap("player2.bmp");
		players.sy = 0;
		players.sx = 0;
	}
	else
	{
		//When spacebar is no longer held reset the sprite
		players.bmp = al_load_bitmap("player.bmp");
	}

	//move player
	players.Move();

	//loop for all enemies
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		//Enemy movement
		enemy[i].Move(players.GetX(), players.GetY());
		//check collision
		if (players.Collision0(&enemy[i]) && al_key_down(&key_state, ALLEGRO_KEY_SPACE) != true)
		{
			players.SetH(-1);
			count--;
			health[count].bmp = NULL;

			enemy[i].x = 500;
			enemy[i].y = 500;
			enemy[i].sx = 0;
			enemy[i].sy = 0;
			players.hitCount++;
		}
		if (players.Collision0(&enemy[i]) && al_key_down(&key_state, ALLEGRO_KEY_SPACE))
		{
			enemy[i].x = 500;
			enemy[i].y = 500;
			enemy[i].sx = 0;
			enemy[i].sy = 0;
			
			score.SetS();
		}
		//Check health - If 0 close game
		if (players.GetH() < 0)
		{
			end = true;
		}

		//Check score and display associated score bitmap 
		if (score.GetS() == 0)
		{
			score.scbmp = al_load_bitmap("score0.bmp");
		}
		if (score.GetS() == 1)
		{
			score.scbmp = al_load_bitmap("score1.bmp");
		}
		if (score.GetS() == 2)
		{
			score.scbmp = al_load_bitmap("score2.bmp");
		}
		if (score.GetS() == 3)
		{
			score.scbmp = al_load_bitmap("score3.bmp");
		}
		if (score.GetS() == 4)
		{
			score.scbmp = al_load_bitmap("score4.bmp");
		}
		if (score.GetS() == 5)
		{
			score.scbmp = al_load_bitmap("score5.bmp");
		}
		if (score.GetS() == 6)
		{
			score.scbmp = al_load_bitmap("score6.bmp");
		}
		if (score.GetS() == 7)
		{
			score.scbmp = al_load_bitmap("score7.bmp");
		}
		if (score.GetS() == 8)
		{
			score.scbmp = al_load_bitmap("score8.bmp");
		}
		if (score.GetS() == 9)
		{
			score.scbmp = al_load_bitmap("score9.bmp");
		}
		if (score.GetS() >= 10 || (NUM_ENEMIES - players.hitCount - score.GetS()) == 0)
		{
			//If player eats 10 enemies, or removes all from the field, they win
			score.scbmp = al_load_bitmap("win.bmp");
		}
		
	}
}

void Game::Draw()
{
	//all drawing will be here

	//start by erasing frame
	render.Begin(bg);
	//draw objects and other content (menus, etc)
	render.Draw(&players);
	//loop for all enemies
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		render.Draw(&enemy[i]);
		
	}
	//Draws health
	for (int i = 0; i < HEALTH; i++)
	{
		render.Draw(&health[i]);
	}
	//Draws score
	render.Draw(&score);
	//put on primary buffer
	render.End();
}
