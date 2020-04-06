#ifndef GAME_H
#define GAME_H
#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>

class game
{
    public:
        game();
        ~game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();
        bool running(){return isRunning;};

        static SDL_Renderer *renderer;

    private:
    bool isRunning;
    SDL_Window *window;
    int cnt = 0;
};

#endif // GAME_H
