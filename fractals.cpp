
// This is the main SDL include file
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct position
{
	int x;
	int y;
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
		}
		tposition.x += opposite;
		tposition.y += adjacent;
	}

	void turn(int degrees)
	{
		angle += degrees % 360;
	}
} turtle;

turtle Turtle;

int start(double a, SDL_Renderer *renderer)
{
	// start point//

	Turtle.tposition.x = 194;
	Turtle.tposition.y = 724;

	printf("coords %d %d \n", Turtle.tposition.x, Turtle.tposition.y);
	// first triangle

	Turtle.pen_down();
	Turtle.turn(90);
	Turtle.move(a, renderer);
	printf("coords %d %d \n", Turtle.tposition.x, Turtle.tposition.y);
	Turtle.turn(120);
	Turtle.move(a, renderer);
	printf("coords %d %d \n", Turtle.tposition.x, Turtle.tposition.y);
	Turtle.turn(120);
	Turtle.move(a, renderer);
	printf("coords %d %d \n", Turtle.tposition.x, Turtle.tposition.y);
	Turtle.turn(120);
	return 0;
}

int Sierp(int n, int rd, double a, SDL_Renderer *renderer)
{
	// make this start after triangle drawn
	Turtle.move(a / 2, renderer);
	Turtle.turn(60);
	Turtle.pen_down();
	Turtle.move(a / 2, renderer);
	Turtle.turn(120);
	Turtle.move(a / 2, renderer);
	Turtle.turn(120);
	Turtle.move(a / 2, renderer);
	Turtle.turn(60);

	if (rd-1 == n)
	{

		return 1;
	}
	else
	{
		return 1 + Sierp(n + 1, rd, a / 2, renderer);
	}
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
	// test starts here for Sierpinksi
	int rd;
	printf("Choose recursion depth\n");
	scanf(" %d", &rd);
	printf(" you choose %d\n", rd);
	//
	double a = 580.00000;
	int n = 0;
	// start

	int start(double a, SDL_Renderer *renderer);
	int result2 = start(a, renderer);
	printf("Result of Sierpinski: %d\n", result2);
	int Sierp(int n, int rd, double a, SDL_Renderer *renderer);
	int result1 = Sierp(n, rd, a, renderer);
	printf("Result of Sierpinski: %d\n", result1);

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
