#include "Bomb.hpp"

void Bomb::DrawBomb(Hero& hero)
{
    int x = hero.coords_x;
    int y = hero.coords_y;
    bool bomb = true;

    Bomb_big_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/Bomb_big.png");
    Bomb_big_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Bomb_big_texture.loadFromImage(Bomb_big_image);

    Bomb_big_sprite.setTexture(Bomb_big_texture);
    Bomb_big_sprite.setPosition(x, y);
    //sleep(seconds(3));
    
   

    



}

void Bomb::DrawWindowBomb(RenderWindow& window)
{


    window.draw(Bomb_big_sprite);
    

}

void Bomb::DestroyBomb(int x, int y, int Destroy_stone_coords[32][21])
{
    if (x % 100 == 0||x%100==50) {

        Destroy_stone_coords[x / 50 + Power][y / 50] = 0;
        Destroy_stone_coords[x / 50 - Power][y / 50] = 0;

    }
    if (y % 100 == 0||y%100==50) {
        Destroy_stone_coords[x / 50 ][y / 50+Power] = 0;
        Destroy_stone_coords[x / 50][y / 50 - Power] = 0;

    }



}
