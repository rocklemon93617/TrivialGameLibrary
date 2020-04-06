#include"game.hpp"

class GameObj
{
    public:
        GameObj(const char* texturesheet, int x, int y);
        ~GameObj();

        void update();
        void render();

    private:
    int xpos;
    int ypos;

    SDL_Texture* objtexture;
    SDL_Rect srcRect, destRect;

};
