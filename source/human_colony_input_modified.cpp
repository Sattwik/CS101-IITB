#include<SDL2/SDL.h>
#include<iostream>
#include<stdio.h>
#include"parameters.h"

using namespace std;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 582;
const int BUTTON_WIDTH = 25;
const int BUTTON_HEIGHT = 25;
const int LESS_BUTTON_LOC_X = 970;
const int MORE_BUTTON_LOC_X = 995;
const int BUTTON_BASELOC_Y = 75;
const int BUTTON_DIFF_Y = 25;
const int INPUT_GRID_BASELOC_X = 420;
int DONE_BUTTON_XH =490, DONE_BUTTON_YH= 520;
const int DONE_BUTTON_WIDTH =100, DONE_BUTTON_HEIGHT= 50;

/*
br
nh
da
fa
str
maxfood
foodreq
homepher
foodpher
*/

bool insidedone(int x,int y);
void handleMouseEventHC( SDL_Event& e ,int x, int y, int i, SDL_Surface * black_box, SDL_Surface * white_box,SDL_Surface * gsurface_hc,
int & temp_number_of_humans,
int & temp_birth_rate,
int & temp_death_age,
int & temp_strength,
int & temp_food_max,
int & temp_food_amount,
int & temp_food_per_new_human,
int & temp_reg_pheromone_inc,
int & temp_food_pheromone_inc,
bool & in_done)
{

        if ( insidedone(x,y))
        {
            if ( e.type ==  SDL_MOUSEMOTION )
            {
                in_done=true;
            }
        }
        else in_done=false;
		//Check if mouse is in less button
		bool inside_less = true;

		//Mouse is left of the button
		if( x < LESS_BUTTON_LOC_X )
		{
			inside_less = false;
		}
		//Mouse is right of the button
		else if( x > LESS_BUTTON_LOC_X + BUTTON_WIDTH )
		{
			inside_less = false;
		}
		//Mouse above the button
		else if( y < BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT) )
		{
			inside_less = false;
		}
		//Mouse below the button
		else if( y > BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT) + BUTTON_HEIGHT )
		{
			inside_less = false;
		}


		//Mouse is inside button
		if (inside_less )
		{
			//Set mouse over sprite

			if(e.type ==  SDL_MOUSEBUTTONDOWN)
				{
					SDL_Rect pos;
					switch (i)
					{
						case 1 :
						if (temp_number_of_humans != 1)
						{

							temp_number_of_humans --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_number_of_humans);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

						case 0 :
						if (temp_birth_rate != 0 )
						{
							temp_birth_rate --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_birth_rate);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}

						break;

						case 2 :
						if (temp_death_age != 1)
						{
							temp_death_age --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_death_age);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}

						break;

						case 4 :
						if (temp_strength != 1)
						{
							temp_strength --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_strength);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

						case 5 :
						if (temp_food_max != 1)
						{
							temp_food_max --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_max);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

						case 3 :
						if (temp_food_amount != 1)
						{
							temp_food_amount --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_amount);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

						case 6 :
						if (temp_food_per_new_human != 1)
						{
							temp_food_per_new_human --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_per_new_human);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

						case 7 :
						if (temp_reg_pheromone_inc != 1)
						{
							temp_reg_pheromone_inc --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_reg_pheromone_inc);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;
						case 8 :
						if (temp_food_pheromone_inc != 1)
						{
							temp_food_pheromone_inc --;
							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_pheromone_inc);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT)+2;
							SDL_BlitSurface (white_box, NULL, gsurface_hc, &pos);
						}
						break;

					}
				}



		}
		/*********************************/

        //Check if mouse is in more button
		bool inside_more = true;

		//Mouse is left of the button
		if( x <  MORE_BUTTON_LOC_X)
		{
			inside_more = false;
		}
		//Mouse is right of the button
		else if( x >  MORE_BUTTON_LOC_X+ BUTTON_WIDTH )
		{
			inside_more = false;
		}
		//Mouse above the button
		else if( y < BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT) )
		{
			inside_more = false;
		}
		//Mouse below the button
		else if( y > BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT) + BUTTON_HEIGHT )
		{
			inside_more = false;
		}


		//Mouse is inside button
		if (inside_more )
		{
			if(e.type ==  SDL_MOUSEBUTTONDOWN)
			{
					SDL_Rect pos;
					switch (i)
					{
						case 1 :
						if (temp_number_of_humans < 20)
						{


							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_number_of_humans);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_number_of_humans ++;
						}
						break;

						case 0 :
						if (temp_birth_rate < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_birth_rate);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_birth_rate ++;
						}

						break;

						case 2 :
						if (temp_death_age < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_death_age);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_death_age ++;
						}

						break;

						case 4 :
						if (temp_strength < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_strength);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_strength ++;
						}
						break;

						case 5 :
						if (temp_food_max < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_max);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_food_max ++;
						}
						break;

						case 3 :
						if (temp_food_amount < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_amount);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_food_amount ++;
						}
						break;

						case 6 :
						if (temp_food_per_new_human < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_per_new_human);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_food_per_new_human ++;
						}
						break;

						case 7 :
						if (temp_reg_pheromone_inc < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_reg_pheromone_inc);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_reg_pheromone_inc ++;
						}
						break;
						case 8 :
						if (temp_food_pheromone_inc < 20)
						{

							pos.x = INPUT_GRID_BASELOC_X + BUTTON_WIDTH * (temp_food_pheromone_inc);
							pos.y = BUTTON_BASELOC_Y + i * (BUTTON_DIFF_Y + BUTTON_HEIGHT);
							SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
							temp_food_pheromone_inc ++;
						}
						break;

					}
				}
		}

}
bool insidedone(int x, int y)
{
	bool inside_done = true;

	//Mouse is left of the button
	if( x <  DONE_BUTTON_XH)
	{
		inside_done = false;
	}
	//Mouse is right of the button
	else if( x >  DONE_BUTTON_XH+ DONE_BUTTON_WIDTH )
	{
		inside_done = false;
	}
	//Mouse above the button
	else if( y < DONE_BUTTON_YH)
	{
		inside_done = false;
	}
	//Mouse below the button
	else if( y > DONE_BUTTON_YH + DONE_BUTTON_HEIGHT )
	{
		inside_done = false;
	}
	return inside_done;
}

/***********************************/

void human_colony_input(human_colony &hc)
{

	SDL_Surface * gsurface_hc = NULL;
	SDL_Surface * back_image = NULL;
	SDL_Surface * black_box = NULL;
	SDL_Surface * white_box = NULL;
	SDL_Surface * done_in = NULL;
	SDL_Surface * done_fn = NULL;

    //Variables
	/***************************************************************************/

	/*int temp_number_of_humans=max(int(hc.number_of_humans),1), temp_birth_rate=max(int(hc.birth_rate/5),1), temp_death_age=max(int(hc.death_age/5000),1);
	int temp_strength=max(int(hc.strength),1), temp_food_max=max(int(hc.food_max/100),1);
	int temp_food_amount=max(int(hc.food_amount/10),1), temp_food_per_new_human=max(int(hc.food_per_new_human/10),1);
	//int temp_pheromone_inc=max(int(hc.pheromone_inc),1);
	int temp_pheromone_inc=1;*/
	
	
	int temp_birth_rate = 0, temp_number_of_humans = 1, temp_death_age = 1,   temp_food_amount = 1,temp_strength = 1, temp_food_max = 1,temp_food_per_new_human = 1, temp_reg_pheromone_inc = 1, 
	temp_food_pheromone_inc  = 1;
	
    // making the window and setting the surface
    /***************************************************************************/

    gsurface_hc = SDL_GetWindowSurface (gwindow);


    /***************************************************************************/
	// loading start background image
	bool success = true;

	back_image = SDL_LoadBMP ("img/human_colony_input_background.bmp");
	black_box = SDL_LoadBMP ("img/black_box.bmp");
	white_box = SDL_LoadBMP ("img/white_box.bmp");
	done_in = SDL_LoadBMP ("img/DONE_INITIAL.bmp");
	done_fn = SDL_LoadBMP("img/DONE_FINAL.bmp");

	if ( black_box == NULL || back_image == NULL || white_box == NULL)
	{
		cout << " Error : " << SDL_GetError() <<endl;
		success = false;
	}

	if (! success )
	{
		cout << "FAILED TO LOAD MEDIA!!!" <<endl;
	}


	/***************************************************************************/




	// actually blitting the image
	    SDL_BlitSurface (back_image, NULL, gsurface_hc, NULL);

	    // initital input grid blitted
		SDL_Rect pos, done_pos;
		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y;
		for(int i=1;i<=temp_birth_rate;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

        pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y + BUTTON_DIFF_Y + BUTTON_HEIGHT;
		for(int i=1;i<=temp_number_of_humans;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  2*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_death_age;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  3*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_food_amount;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  4*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_strength;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  5*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_food_max;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  6*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_food_per_new_human;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  7*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_reg_pheromone_inc;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }
		pos.x = INPUT_GRID_BASELOC_X;
		pos.y = BUTTON_BASELOC_Y +  8*(BUTTON_DIFF_Y + BUTTON_HEIGHT);
		for(int i=1;i<=temp_food_pheromone_inc;i++)
		{
            SDL_BlitSurface (black_box, NULL, gsurface_hc, &pos);
            pos.x+=BUTTON_WIDTH;
        }

		done_pos.x=DONE_BUTTON_XH;
		done_pos.y=DONE_BUTTON_YH;

		bool quit_hc = false;
        bool in_done=false;
		while (!quit_hc)
		{
			SDL_Event e;

			while ( SDL_PollEvent(&e) != 0)
			{

				if (e.type == SDL_QUIT)
				{
					quit_hc = true;
					quit=true;
				}

				if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
				{

					//Get mouse position
					int x, y;
					SDL_GetMouseState( &x, &y );

					if ( insidedone(x,y))
					{

						if ( e.type ==  SDL_MOUSEBUTTONDOWN )
						{
							
							hc.strength = temp_strength;
							hc.number_of_humans = temp_number_of_humans*5;
							hc.death_age = temp_death_age*5000;
							hc.birth_rate = temp_birth_rate;
							hc.food_amount = temp_food_amount*100;
							hc.food_max = temp_food_max*10;
							hc.food_per_new_human = temp_food_per_new_human*10;
						//	hc.pheromone_inc = temp_pheromone_inc;


							quit_hc = true;




						}
					}

					for (int i = 0; i< 9 ;i ++)
					{
						handleMouseEventHC(  e,x, y, i,  black_box,white_box,gsurface_hc, temp_number_of_humans, temp_birth_rate, temp_death_age, temp_strength, temp_food_max,temp_food_amount,temp_food_per_new_human,temp_reg_pheromone_inc,temp_food_pheromone_inc,in_done);
				    }


                }
			}

		//SDL_BlitSurface (back_image, NULL, gsurface_hc, NULL);
		//SDL_BlitSurface (black_box, NULL, gsurface_hc, &dest);
        if(in_done)
            SDL_BlitSurface (done_fn, NULL, gsurface_hc, &done_pos);
        else SDL_BlitSurface(done_in, NULL, gsurface_hc, &done_pos);

       		SDL_UpdateWindowSurface(gwindow);
	    }






	/***************************************************************************/
	// closing the stuff
	SDL_FreeSurface(back_image);
	back_image = NULL;
	SDL_FreeSurface(black_box);
	black_box = NULL;
	SDL_FreeSurface(white_box);
	white_box = NULL;
	SDL_FreeSurface(done_in);
	done_in = NULL;
	SDL_FreeSurface(done_fn);
	done_fn = NULL;
	SDL_FreeSurface(gsurface_hc);
	gsurface_hc=NULL;
}
