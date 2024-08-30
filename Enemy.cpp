#include "Enemy.hpp"


void Enemy::DrawEnemy()
{
    static int j = 1;//ïåðåõîä âíèç
    DrawEnemyLeft();

    x = rand() % 1500 + 50;


    while (true)
    {
        y = rand() % 550 + 50;
        if (y % 100 == 0)
        {
            break;
        }
    }
    up_down = rand() % 2;//ââåðõ èëè âíèç
    left_right = rand() % 2;//âëåâî èëè âïðàâî

    y += j * 100;
    j++;
}

void Enemy::DrawEnemyLeft()
{
    Enemy_image.loadFromFile("sprites/Enemy_left.png");
    Enemy_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);
    
}

void Enemy::DrawEnemyRight()
{
    Enemy_image.loadFromFile("sprites/Enemy_right.png");
    Enemy_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);
}

void Enemy::DrawEnemyUp()
{
    Enemy_image.loadFromFile("sprites/Enemy_up.png");
    Enemy_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);
}

void Enemy::DrawEnemyDown()
{
    Enemy_image.loadFromFile("sprites/Enemy_down.png");
    Enemy_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);
}

void Enemy::DrawWindowEnemy(RenderWindow& window, Pole& Stone, Hero& hero)
{
    int true_y;
    int true_x;
    coords_x++;

    // std::cout << move << std::endl;

    if (coords_x == 10) {
        x += move;
        y += move_y;
        //std::cout << "x " << x << std::endl;
        //std::cout << "y " << y << std::endl;
        if (Stone.Destroy_stone_coords[(x + 50) / 50][y / 50] || x >= 1550)//÷òîá íå âðåçàòüñÿ â ñòåíó
        {
            if (move_x)
            {
                DrawEnemyLeft();
                move = -1;
            }
        }



        else if (Stone.Destroy_stone_coords[(x - move) / 50][y / 50] == 1 || x <= 0)//÷òîá íå âðåçàòüñÿ â ñòåíó
        {
            if (move_x)
            {
                DrawEnemyRight();

                move = 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {

        if ((x - i == hero.coords_x && y == hero.coords_y) || (x + i == hero.coords_x && y == hero.coords_y)
            ||(y-i==hero.coords_y&&x==hero.coords_x)||(y + i == hero.coords_y && x == hero.coords_x))//êîëëèçèÿ ñ èãðîêîì
        {
            x = -200;
            y = -200;
            Enemy_sprite.setPosition(x, y);
            hero.Draw_Window_Death(window );
            //äîáàâèòü àíèìàöèþ
            //sleep(seconds(3));
            //window.close();
        }
        }

        coords_x = 0;
    }
    if (life)
    {

        if (x % 100 == 0)//äâèæåíèå ââåðõ/âíèç
        {
            true_y = rand() % 200;
            if (!true_y)
            {
                if (up_down && !first_y)
                {
                    DrawEnemyDown();

                    move_y = 1;
                    first_y = true;

                }
                else {
                    if (!first_y)
                    {
                        DrawEnemyUp();
                        move_y = -1;
                        first_y = true;

                    }
                }
                if (y - move_y <= 70)//÷òîá íå âðåçàòüñÿ â ïîë è ïîòîëîê
                {
                    move_y = 1;
                    DrawEnemyDown();
                    //true_y = 0;
                }
                else if (y + move_y >= 1000)
                {
                    // true_y = 0;
                    DrawEnemyUp();
                    move_y = -1;
                }
                move = 0;
                move_x = false;
                first_x = false;
            }
            if (Stone.Destroy_stone_coords[x / 50][(y + 50) / 50] && move_y == 1)//÷òîá íå âðåçàòüñÿ â ñòåíó
            {
                DrawEnemyUp();
                move_y = -1;
            }
            else if (Stone.Destroy_stone_coords[x / 50][y / 50] && move_y == -1)//÷òîá íå âðåçàòüñÿ â ñòåíó
            {
                DrawEnemyDown();
                move_y = 1;
            }

        }
        if (y % 100 == 0 && move == 0)
        {
            true_x = rand() % 200;
            if (!true_x)
            {
                if (left_right && !first_x)
                {
                    DrawEnemyRight();
                    move = 1;
                    first_x = true;
                }
                else {
                    if (!first_x)
                    {
                        DrawEnemyLeft();
                        move = -1;
                        first_x = true;

                    }
                }
                if (x - move <= 70)//÷òîá íå âðåçàòüñÿ â ïîë è ïîòîëîê
                {
                    DrawEnemyRight();
                    move = 1;
                    //true_y = 0;
                }
                else if (x + move >= 1000)
                {
                    // true_y = 0;
                    DrawEnemyLeft();
                    move = -1;
                }
                move_y = 0;
                move_x = true;
                first_y = false;//÷òîá âåðíèëñÿ îáðàòíî
            }
            if (Stone.Destroy_stone_coords[(x + 50) / 50][y / 50] && move == 1)//÷òîá íå âðåçàòüñÿ â ñòåíó
            {
                DrawEnemyLeft();
                move = -1;
            }
            else if (Stone.Destroy_stone_coords[x / 50][y / 50] && move_y == 1)//÷òîá íå âðåçàòüñÿ â ñòåíó
            {
                DrawEnemyRight();
                move = 1;
            }



        }
    }
    Enemy_sprite.setPosition(x, y);
    window.draw(Enemy_sprite);
    //std::cout <<"x: "<< x << '\n';
    //çàãóãëèòü ïî÷åìó ó ðàçíûõ ýêçýìïëÿðîâ êëàññà îäèí è òîò æå x


}
