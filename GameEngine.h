#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

class TGL
{
    public:
       void Loop();
       void Start();

    private:
        TGL();
        ~TGL();

};

SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);
SDL_Renderer  *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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

        //demo color
        Uint8 red = rand() % 255;
        Uint8 green = rand() % 255;
        Uint8 blue = rand() % 255;
        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

        InputLoop();

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    
        SDL_Delay(1000/60);
    }
}