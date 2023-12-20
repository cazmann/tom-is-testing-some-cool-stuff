
// This is the main SDL include file
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct position
{
	int x = 0;
	int y = 0;
} position;

typedef struct colour
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
} colour;

typedef struct turtle
{
	position tposition;
	int angle;
	bool pen;

	void pen_up()
	{
		pen = 0;
	}

	void pen_down()
	{
		pen = 1;
	}

	void move(int n, SDL_Renderer *renderer)
	{
		int opposite;
		int adjacent;
		opposite = n * sin(angle * M_PI / 180);
		adjacent = n * cos(angle * M_PI / 180);
		if (pen)
		{
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderDrawLine(renderer, tposition.x, tposition.y, opposite + tposition.x, adjacent + tposition.y);
			SDL_RenderPresent(renderer);
			printf(" %d\n %d\n %d\n %d\n %d\n", tposition.x, tposition.y, opposite + tposition.x, adjacent + tposition.y, angle);
		}
		tposition.x += opposite;
		tposition.y += adjacent;
	}

	void turn(int degrees)
	{
		angle = degrees % 360;
	}
} turtle;

void kochsnowflake()
{
}
// make pen structure with =pens position- x & y, angle pointing/heading, pen drawing/not drawing

// make

int main(void)
{
	/* These are some variables to help show you what the parameters are for the initialisation function.
	   You can experiment with the numbers to see what they do. */
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 1000;
	int winHeight = 1000;
	int go;

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

	/* Now we have got SDL initialised, we are ready to create a window! */

	char fractal_choice;
	printf("Which fractal would you like to make?\n a, b, c \n");
	scanf("%c", &fractal_choice);

	char bg_colour[7];
	fflush(stdin);
	printf("Choose your background colour\n");
	scanf("%s", bg_colour);

	colour bg;
	const colour red = {205, 0, 0};
	const colour orange = {255, 127, 36};
	const colour yellow = {255, 205, 36};
	const colour green = {98, 206, 53};
	const colour blue = {86, 190, 233};
	const colour purple = {157, 90, 213};
	const colour pink = {255, 98, 173};
	const colour black = {0, 0, 0};
	const colour white = {255, 255, 255};

	if (!strcmp(bg_colour, "red"))
	{
		bg = red;
	}

	else if (!strcmp(bg_colour, "orange"))
	{
		bg = orange;
	}

	else if (!strcmp(bg_colour, "yellow"))
	{
		bg = yellow;
	}

	else if (!strcmp(bg_colour, "green"))
	{
		bg = green;
	}

	else if (!strcmp(bg_colour, "blue"))
	{
		bg = blue;
	}

	else if (!strcmp(bg_colour, "purple"))
	{
		bg = purple;
	}

	else if (!strcmp(bg_colour, "pink"))
	{
		bg = pink;
	}

	else if (!strcmp(bg_colour, "black"))
	{
		bg = black;
	}

	else if (!strcmp(bg_colour, "white"))
	{
		bg = white;
	}

	SDL_Window *window = SDL_CreateWindow("Fractal Window",
										  winPosX, winPosY,
										  winWidth, winHeight,
										  SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	int recdepth = 7;
	turtle Turtle;
	// start
	Turtle.pen_up();
	Turtle.turn(15);
	Turtle.move(750, renderer);

	// recurison?

	// line 1
	int a = 570;
	int b = a / 3;
	Turtle.pen_down();
	Turtle.turn(90);
	Turtle.move(a / 3, renderer);

	Turtle.pen_up();
	Turtle.turn(90);
	Turtle.move(a / 3, renderer);

	Turtle.pen_down();
	Turtle.turn(90);
	Turtle.move(a / 3, renderer);

	// line2
	Turtle.turn(-150);
	Turtle.move(a / 3, renderer);

	Turtle.pen_up();
	Turtle.turn(-150);
	Turtle.move(a / 3, renderer);

	Turtle.pen_down();
	Turtle.turn(-150);
	Turtle.move(a / 3, renderer);

	// line 3
	Turtle.turn(-30);
	Turtle.move(a / 3, renderer);

	Turtle.pen_up();
	Turtle.turn(-30);
	Turtle.move(a / 3, renderer);

	Turtle.pen_down();
	Turtle.turn(-30);
	Turtle.move(a / 3, renderer);

	if (bool pen = 1 )
	{

		Turtle.pen_down();
		Turtle.turn(90);
		Turtle.move(a / 3, renderer);
		Turtle.turn(30);
		Turtle.move(a / 3, renderer);
		Turtle.turn(150);
		Turtle.move(a / 3, renderer);
	}
	printf("B = %d ", b);

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
			switch (incomingEvent.type)
			{
			case SDL_QUIT:
				go = 0;
				break;
			}
		}

		SDL_Delay(10);
	}

	SDL_RenderPresent(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
