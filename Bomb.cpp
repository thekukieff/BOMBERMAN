#include "Bomb.hpp"


void Bomb::DrawBomb(Hero& hero)
{
    x = hero.coords_x;
    y = hero.coords_y;
    Bomb_big_image.loadFromFile("sprites/Bomb_big.png");
    Bomb_big_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Bomb_big_texture.loadFromImage(Bomb_big_image);

    Bomb_big_sprite.setTexture(Bomb_big_texture);
    Bomb_big_sprite.setPosition(x, y);

}

void Bomb::DrawBoom()
{

    Boom_image.loadFromFile("sprites/Boom.png");
    Boom_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Boom_texture.loadFromImage(Boom_image);

    Boom_sprite.setTexture(Boom_texture);
    Boom_sprite.setPosition(-200, -200);
}

void Bomb::DrawWindowBomb(RenderWindow& window)
{


    window.draw(Bomb_big_sprite);


}

void Bomb::DestroyBomb(int Destroy_stone_coords[32][21], Enemy& enemy, Hero& hero, RenderWindow &window)

{


    if (x % 100 == 0 || x % 100 == 50) {
        Destroy_stone_coords[x / 50 + Power][y / 50] = 1;
        Destroy_stone_coords[x / 50 - Power][y / 50] = 1;

    }
    if (y % 100 == 0 || y % 100 == 50) {
        Destroy_stone_coords[x / 50][y / 50 + Power] = 1;
        Destroy_stone_coords[x / 50][y / 50 - Power] = 1;

    }
    for (int i = 0; i < 51; i++)//êîëëèçèÿ ñ ìîíñòðîì
    {


        if (x + i == enemy.x  )//collision for X
            {
            //std::cout << "FOR X\n";

            for (int xx = 0; xx < 75; xx++)
            {

                if (y + xx == enemy.y || y - xx == enemy.y)
                {
                  

                    Kill(enemy);
                    break;
                } 
            }
            }
        else if (x - i == enemy.x)
        {
            for (int xx = 0; xx < 75; xx++)
            {

                if (y + xx == enemy.y || y - xx == enemy.y)
                {

                    Kill(enemy);
                    break;
                }
            }
        }
        else//collision for y
            if (y - i == enemy.y) {
                for (int j = 0; j < 75; j++)
                {

                    if (enemy.x == x - j || enemy.x == x + j)//âðàã è áîìáà
                    {
                        Kill(enemy);
                        break;
                    }
                }
            }
            else if (y + i == enemy.y)
            {
                for (int j = 0; j < 75; j++)
                {

                    if (enemy.x == x - j || enemy.x == x + j)
                    {
                        std::cout << "3\n";
                        Kill(enemy);
                        break;
                    }
                }

            }

        if (x + i == hero.coords_x)//collision for X
        {
            //std::cout << "FOR X\n";

            for (int xx = 0; xx < 50; xx++)
            {

                if (y + xx == hero.coords_y || y - xx == hero.coords_y)
                {

                    hero.Draw_Window_Death(window);
                    
                    break;
                }
            }
        }
        else if (x - i == hero.coords_x)
        {
            for (int xx = 0; xx < 50; xx++)
            {

                if (y + xx == hero.coords_y || y - xx == hero.coords_y)
                {

                    hero.Draw_Window_Death(window);

                    break;
                }
            }
        }
        else//collision for y
            if (y - i == hero.coords_y) {
                for (int j = 0; j < 50; j++)
                {

                    if (hero.coords_x == x - j || hero.coords_x == x + j)//âðàã è áîìáà
                    {
                        hero.Draw_Window_Death(window);

                        break;
                    }
                }
            }
            else if (y + i == hero.coords_y)
            {
                for (int j = 0; j < 50; j++)
                {

                    if (hero.coords_x == x - j || hero.coords_x == x + j)
                    {
                        std::cout << "3\n";
                        hero.Draw_Window_Death(window);

                        break;
                    }
                }

            }

        
    
    }






}
void Bomb::CollisionEnemy(Enemy& enemy)
{
    if (x == enemy.x+50 && enemy.move == 1&&enemy.y==y)
    {
        enemy.DrawEnemyLeft();
        enemy.move = -1;
    }
    else if (x == enemy.x-50 && enemy.move == -1&&enemy.y == y)
    {
        enemy.DrawEnemyRight();
        enemy.move = 1;
    }
    
    if (y == enemy.y-50&&enemy.move_y == -1 && enemy.x == x)
    {
        enemy.DrawEnemyDown();
        enemy.move_y = 1;
    }
    else if (y == enemy.y + 50 && enemy.move_y == 1 && enemy.x == x)
    {
        enemy.DrawEnemyUp();
        enemy.move_y = -1;
    }
    
}

void Bomb::DrawWindowBoom(RenderWindow& window)
{
    
    window.draw(Boom_sprite);
    std::cout << boom_x<< boom_y <<std::endl;
}

void Bomb::BombDelete()
{
    x = -200;
    y = -200;
    Bomb_big_sprite.setPosition(x,y);
}

void Bomb::Kill(Enemy &enemy)
{

    enemy.life = false;//÷òîá íå äâèãàëñÿ
    enemy.move_y = 0;
    enemy.move = 0;
    enemy.x = -100;
    enemy.y = -100;
}



void Bomb::BOOM(Hero &hero, Bomb &bomb) {

    //Bomb_big_sprite.setPosition(-200, -200);
    boom_x = bomb.x;
    boom_y = bomb.y;
    Boom_sprite.setPosition(boom_x, boom_y );

}