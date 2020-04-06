#include"texturemanager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tmpsurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game::renderer, tmpsurface);
    SDL_FreeSurface(tmpsurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(game::renderer, tex, &src, &dest);
}
