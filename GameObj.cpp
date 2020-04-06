#include "GameObj.hpp"
#include "texturemanager.hpp"

GameObj::GameObj(const char* texturesheet, int x, int y)
{
    objtexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

void GameObj::update()
{

    xpos++;
    ypos++;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;

    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}

void GameObj::render()
{
    SDL_RenderCopy(game::renderer, objtexture, &srcRect, &destRect);
}
