#include "Pole.hpp"
#include "Hero_sprite.hpp"

void Pole::DrawIndestructibleStone()
{

    Indestrucyible_stone_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/Indestructible.png");
    Indestructible_stone_texture.loadFromImage(Indestrucyible_stone_image);
    Indestructible_stone_sprite.setTexture(Indestructible_stone_texture);




}

void Pole::DrawDestroyStone()
{
    Destroy_stone_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/Destroy.png");
    Destroy_stone_texture.loadFromImage(Destroy_stone_image);
    Destroy_stone_sprite.setTexture(Destroy_stone_texture);




}

void Pole::WindowDrawDestroy(RenderWindow& window)
{

    int True;
    static int Recurs = 0;
    srand(time(NULL));

    if (!Recurs)

    {

        for (int i = 1; i < COL; i++)
        {
            for (int j = 1; j < ROW; j++)
            {

            True = rand() % 2;
            Destroy_stone_coords[i][j] = True;
            
            }

        }
    for (int i = 0; i < ROW; i++)
    {
        Destroy_stone_coords[0][i] = 0;
    }//не заполнем первый ряд
    }

        for (int i = 1; i < 32; i++)//len
        {
            for (int j = 1; j < 21; j++)//hight
            {



                if (Destroy_stone_coords[i][j] && j % 2 == 0) {
                    Destroy_stone_sprite.setPosition(i * 50, j * 50);
                    window.draw(Destroy_stone_sprite);
                }
                else if (Destroy_stone_coords[i][j] && i % 2 == 0) {
                    Destroy_stone_sprite.setPosition(i * 50, j * 50);
                    window.draw(Destroy_stone_sprite);
                }
            }
        }

        Recurs = 1;


}



void Pole::DrawPole(RenderWindow& window)
{
    
    
    for  (int i = 1;  i < COL; i+=2)
    {
        for (int j = 1; j < ROW; j+=2)
        {

            Indestructible_stone_sprite.setPosition(i*50, j*50);
            window.draw(Indestructible_stone_sprite);
        }
    }




    for (int i = 0; i < 33; i++)//границы
    {
        Indestructible_stone_sprite.setPosition(i * 50, 0);
        window.draw(Indestructible_stone_sprite);
    }
    for (int i = 0; i < 22; i++)
    {
        Indestructible_stone_sprite.setPosition(1630, i * 50);
        window.draw(Indestructible_stone_sprite);
    }



    Destroy_stone_sprite.setPosition(200, 200);


}

void Pole::DrawBomb()
{

    Bomb_big_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/Bomb_big.png");
    Bomb_big_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Bomb_big_texture.loadFromImage(Bomb_big_image);

    Bomb_big_sprite.setTexture(Bomb_big_texture);



}

void Pole::DrawWindowBomb(RenderWindow& window, Hero& hero)
{
    int x = hero.coords_x;
    int y = hero.coords_y;

    DrawBomb();
    Bomb_big_sprite.setPosition(x,y);

    window.draw(Bomb_big_sprite);
}










void Pole::Background()
{
    
    rectangle.setSize(Vector2f(1920, 1080));
    rectangle.setFillColor(Color(0,200,0));




}

void Pole::DrawBackground(RenderWindow& window)
{
    window.draw(rectangle);
}
