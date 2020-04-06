#include "game.hpp"
#include "texturemanager.hpp"
#include "GameObj.hpp"
#include"map.hpp"

GameObj* player;
Map* map;

SDL_Renderer* game::renderer = nullptr;

game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout<<"subsystems initialized"<<std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window)
        {
            std::cout<<"window created"<<std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"renderer created"<<std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new GameObj("img/boi.png", 0, 0);
    map = new Map();
}

void game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
        break;

        default:
        break;
    }
}

void game::update()
{
    player->update();
}

void game::render()
{
    SDL_RenderClear(renderer);
    //add render stuff here
    map->DrawMap();
    player->render();
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"game is working no more"<<std::endl;
}
