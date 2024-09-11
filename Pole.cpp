#include "Pole.hpp"
#include "Hero_sprite.hpp"
#include"Bomb.hpp"

void Pole::DrawIndestructibleStone()
{

    Indestrucyible_stone_image.loadFromFile("sprites/Indestructible.png");
    Indestructible_stone_texture.loadFromImage(Indestrucyible_stone_image);
    Indestructible_stone_sprite.setTexture(Indestructible_stone_texture);




}

void Pole::DrawDestroyStone()
{
    int True=0;
    Destroy_stone_image.loadFromFile("sprites/Destroy.png");
    Destroy_stone_texture.loadFromImage(Destroy_stone_image);
    Destroy_stone_sprite.setTexture(Destroy_stone_texture);
    for (int i = 1; i < COL; i++)
    {
        for (int j = 1; j < ROW; j++)
        {


               True = rand() % 3;

            
            Destroy_stone_coords[i][j] = True;

        }

    }

    for (int i = 0; i < ROW; i++)
    {
        Destroy_stone_coords[0][i] = 1;
    }//íå çàïîëíåì ïåðâûé ðÿä
}





void Pole::WindowDrawDestroy(RenderWindow& window)
{


    for (int i = 1; i < 32; i++)//len
    {
        for (int j = 1; j < 21; j++)//hight
        {



            if (!Destroy_stone_coords[i][j] && j % 2 == 0) {
                Destroy_stone_sprite.setPosition(i * 50, j * 50);
                window.draw(Destroy_stone_sprite);
            }
            else if (!Destroy_stone_coords[i][j] && i % 2 == 0) {
                Destroy_stone_sprite.setPosition(i * 50, j * 50);
                window.draw(Destroy_stone_sprite);
            }
        }
    }
}



void Pole::DrawPole(RenderWindow& window)
{


    for (int i = 1; i < COL; i += 2)
    {
        for (int j = 1; j < ROW; j += 2)
        {

            Indestructible_stone_sprite.setPosition(i * 50, j * 50);
            window.draw(Indestructible_stone_sprite);
        }
    }




    for (int i = 0; i < 33; i++)//ãðàíèöû
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

void Pole::Door(Pole stone)
{

    Door_image.loadFromFile("sprites/vorota.jpg");
    Door_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Door_texture.loadFromImage(Door_image);
    Door_sprite.setTexture(Door_texture);

    while (true)
    {
        door_x = rand() % 32 + 1;//+1 ÷òîáû íå áûëî íà ïåðâîé âåðòèêàëå
        door_y = rand() % 21 + 1;

        if (stone.Destroy_stone_coords[door_x][door_y] == 0)
        {
            if (door_x % 2 == 0 || door_y % 2 == 0)//íà âñÿêèé ñëó÷àé
            {

                
                break;
            }
        }
    }
    Door_sprite.setPosition(door_x * 50, door_y * 50);
    std::cout << door_x << " " << door_y << std::endl;

}

void Pole::DrawDoor(RenderWindow& window)
{
    window.draw(Door_sprite);
}





void Pole::Background()
{

    rectangle.setSize(Vector2f(1920, 1080));
    rectangle.setFillColor(Color(0, 200, 0));




}

void Pole::DrawBackground(RenderWindow& window)
{
    window.draw(rectangle);
}