#include "GameEngine.h"
#include <stdio.h>

void GameStart()
{
    printf("GameStart method");
}

void GameLoop()
{
    printf("GameLoop method\n");
}

int main(int argc, char *args[])
{
    Start(GameStart);
    Loop(GameLoop); 

    return 0;
}