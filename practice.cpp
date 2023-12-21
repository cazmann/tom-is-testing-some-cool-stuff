
// This is the main SDL include file
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
	int angle = 0;
	bool pen;
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
		}
		tposition.x += opposite;
		tposition.y += adjacent;
	}

	void turn(int degrees)
	{
		angle += degrees % 360;
	}
} turtle;


bool pen_up(turtle *Turtle)
{
	Turtle-> pen = false;
	return Turtle->pen;
}

bool pen_down(turtle *Turtle)
{
	Turtle-> pen = true;
	return Turtle -> pen;
}


void kochsnowflake()
{
}

int main(void)
{

	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 1000;
	int winHeight = 1000;
	int go;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		perror("Whoops! Something went very wrong, cannot initialise SDL :( - ");
		perror(SDL_GetError());
		return -1;
	}

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

	turtle Turtle;
	// start
	pen_up(&Turtle);
	Turtle.turn(15);
	Turtle.move(750, renderer);
	Turtle.turn(75);
	pen_down(&Turtle);
	// recurison?

	int a = 570;
	int b = a / 3;

	// line 1

	// line 1
pen_up(&Turtle);  // Lift the pen
Turtle.move(a / 3, renderer);
Turtle.turn(60);
Turtle.move(a / 3, renderer);
Turtle.turn(120);
Turtle.move(a / 3, renderer);

// Move to the next position
Turtle.move(a / 3, renderer);
pen_down(&Turtle);  // Lower the pen

Turtle.move(a / 3, renderer);
Turtle.turn(120);
// line2
Turtle.move(a / 3, renderer);
Turtle.turn(120);
// line 3
Turtle.move(a / 3, renderer);
Turtle.turn(120);

// Draw the triangle with the pen up
pen_up(&Turtle);
Turtle.move(a / 3, renderer);
Turtle.turn(60);
Turtle.move(a / 3, renderer);
Turtle.turn(120);
Turtle.move(a / 3, renderer);

// Lower the pen for the next segment
pen_down(&Turtle);

Turtle.turn(60);
Turtle.move(a / 3, renderer);
Turtle.turn(120);
Turtle.move(a / 3, renderer);

	go = 1;
	while (go)
	{
		SDL_Event incomingEvent;

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
