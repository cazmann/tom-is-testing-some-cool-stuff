#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// Function to draw a Koch curve
void drawKoch(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int it) {
    float angle = 60 * M_PI / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);
    
    if (it > 0) {
        drawKoch(renderer, x1, y1, x3, y3, it - 1);
        drawKoch(renderer, x3, y3, x, y, it - 1);
        drawKoch(renderer, x, y, x4, y4, it - 1);
        drawKoch(renderer, x4, y4, x2, y2, it - 1);
    } else {
        SDL_RenderDrawLine(renderer, x1, y1, x3, y3);
        SDL_RenderDrawLine(renderer, x3, y3, x, y);
        SDL_RenderDrawLine(renderer, x, y, x4, y4);
        SDL_RenderDrawLine(renderer, x4, y4, x2, y2);
    }
}

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // Create window and renderer
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    // Coordinates of the triangle
    int x1 = 100, y1 = 300;
    int x2 = 700, y2 = 300;
    int x3 = 400, y3 = 100;
    
    // Number of iterations
    int iterations = 4;
    
    // Drawing the Koch snowflake
    drawKoch(renderer, x1, y1, x2, y2, iterations);
    drawKoch(renderer, x2, y2, x3, y3, iterations);
    drawKoch(renderer, x3, y3, x1, y1, iterations);
    
    SDL_RenderPresent(renderer);
    
    // Wait for user exit
    SDL_Delay(5000);
    
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}