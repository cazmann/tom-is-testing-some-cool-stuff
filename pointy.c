
// This is the main SDL include file
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct position
{
	int x;
	int y;
} position;

typedef struct turtle
{
	position Position;
	int angle;
	char pen;
} turtle;

void pen_up(char *pen)
{
	*pen = 0;
}

void pen_down(char *pen)
{
	*pen = 1;
}

void move(int n, turtle)
{}

void turn(int degrees)
{}


void pointy(SDL_Renderer *renderer, int width, int height)
{
	int x, y;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (x = 10, y = 10; x < width - 10; x += ((width - 20) / 20), y += ((height - 20) / 20))
	{
		SDL_RenderDrawPoint(renderer, x, y);
	}
}


int main(void)
{
	//for window structure//
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 640;
	int winHeight = 480;
	int go;
	//char array made  for user input//
	char fractal_choice[];
    char bg_color_choice[];

	/* This is our initialisation phase

	   SDL_Init is the main initialisation function for SDL
	   It takes a 'flag' parameter which we use to tell SDL what systems we are going to use
	   Here, we want to initialise everything, so we give it the flag for this.
	   This function also returns an error value if something goes wrong,
	   so we can put this straight in an 'if' statement to check and exit if need be */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) /* alternative: SDL_INIT_EVERYTHING */
	{
		/* Something went very wrong in the initialisation, all we can do is exit */
		perror("Whoops! Something went very wrong, cannot initialise SDL :( - ");
		perror(SDL_GetError());
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("My Pointy Window!!!", 
										  winPosX, winPosY,
										  winWidth, winHeight,
										  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	/* The last parameter lets us specify a number of options.
	   Here, we tell SDL that we want the window to be shown and that it can be resized.
	   You can learn more about SDL_CreateWindow here: https://wiki.libsdl.org/SDL_CreateWindow?highlight=%28\bCategoryVideo\b%29|%28CategoryEnum%29|%28CategoryStruct%29
	   The flags you can pass in for the last parameter are listed here: https://wiki.libsdl.org/SDL_WindowFlags

	   The SDL_CreateWindow function returns an SDL_Window.
	   This is a structure which contains all the data about our window (size, position, etc).
	   We will also need this when we want to draw things to the window.
	   This is therefore quite important we do not lose it! */

	/* The SDL_Renderer is a structure that handles rendering.
	   It will store all of SDL's internal rendering related settings.
	   When we create it we tell it which SDL_Window we want it to render to.
	   That renderer can only be used for this window (yes, this means we can have multiple windows). */
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	/* We are now preparing for our main loop.
	   This loop will keep going round until we exit from our program by changing the int 'go' to the value false (0).
	   This loop is an important concept and forms the basis of most SDL programs you will be writing.
	   Within this loop we generally do the following things:
		 * Check for input from the user (and do something about it!)
		 * Update our graphics- 
		 * Draw our graphics
	*/
    printf("Which fractal would you like to make?\n Koch, dragon, leaf\n");
	scanf("%s", &fractal_choice);

	switch(bg_colour)
	{
		case "red" : printf("chose red"); break; 
		case "orange" : printf("chose orange"); break; 
		case "yellow" : printf("chose yellow"); break; 
		case "green" : printf("chose green"); break; 
		case "blue" : printf("chose blue"); break; 
		case "purple" : printf("chose purple"); break; 
		case "pink" : printf("chose pink"); break; 
		case "black" : printf("chose black"); break;
		default : printf( "Colour is unrecognised\n"); break;

	}
	
    switch(bg_color_choice)
	{
		case red : break ; 
		case orange : break ; 
		case yellow : break ; 
		case green : break ; 
		case blue  : break ; 
		case purple : break ; 
		case pink : break ; 
		default : printf( "Colour is unrecognised\n") ;

	}

	go = 1;
	while (go)
	{
		/* Here we are going to check for any input events.
		   Basically when you press the keyboard or move the mouse, the parameters are stored as something called an 'event' or 'message'.
		   SDL has a queue of events. We need to check for each event and then do something about it (called 'event handling').
		   The SDL_Event is the data type for the event. */
		SDL_Event incomingEvent;

		/* SDL_PollEvent will check if there is an event in the queue - this is the program's 'message pump'.
		   If there is nothing in the queue it will not sit and wait around for an event to come along (there are functions which do this,
		   and that can be useful too!). Instead for an empty queue it will simply return 'false' (0).
		   If there is an event, the function will return 'true' (!=0) and it will fill the 'incomingEvent' we have given it as a parameter with the event data */
		while (SDL_PollEvent(&incomingEvent))
		{
			/* If we get in here, we have an event and need to figure out what to do with it.
			   For now, we will just use a switch based on the event's type */
			switch (incomingEvent.type)
			{
			case SDL_QUIT:
				/* The event type is SDL_QUIT.
				   This means we have been asked to quit - probably the user clicked on the 'x' at the top right corner of the window.
				   To quit we need to set our 'go' variable to false (0) so that we can escape out of the main loop. */
				go = 0; break;

				/* If you want to learn more about event handling and different SDL event types, see:
				  https://wiki.libsdl.org/SDL_Event
				  and also: https://wiki.libsdl.org/SDL_EventType */
			}
		}

		/* Draw our graphics */

		/* Start by clearing what was drawn before */
		/* Set the colour for drawing */
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		/* Clear the entire screen to our selected colour */
		SDL_RenderClear(renderer);

		/* Call our pointy drawing */
		pointy(renderer, winWidth, winHeight);

		/* This tells the renderer to actually show its contents to the screen. */
		SDL_RenderPresent(renderer);

		/* Turns out SDL_WaitEvent just does an SDL_PollEvent and then an SDL_Delay(10) if there is nothing to do! */
		SDL_Delay(10);
	}

	/* If we get outside the main loop, it means our user has requested we exit. */

	/* Our cleanup phase, hopefully fairly self-explanatory ;) */
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
