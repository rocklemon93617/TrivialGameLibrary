#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);

SDL_Renderer  *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

SDL_Surface *surface = SDL_GetWindowSurface(window);

class TGL
{
    public:
       void Loop();
       void Start();
       void Rectangle();

    private:
        TGL();
        ~TGL();
};


void Rectangle(int posX, int posY, int sizeX, int sizeY)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect rect = {posX, posY, sizeX, sizeY};
    SDL_RenderFillRect(renderer, &rect);
}


TGL::TGL()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        //return -1;
    }

}

TGL::~TGL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Start(void InputStart())
{
    InputStart();
}

void Loop(void InputLoop())
{

    while(true)
    {
        SDL_Event event;
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        InputLoop();

        
        SDL_RenderPresent(renderer);
    
        SDL_Delay(1000/60);
    }
}