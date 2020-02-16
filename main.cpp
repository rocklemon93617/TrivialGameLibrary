#include "GameEngine.h"
#include <stdio.h>

void GameStart()
{
    printf("GameStart method");
}

void GameLoop()
{
    //printf("GameLoop method\n");
    Rectangle(300, 200, 100, 100);
}

int main(int argc, char *args[])
{
    Start(GameStart);
    Loop(GameLoop); 

    return 0;
}