#include "Start.hpp"
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Bomb.hpp"

void Start()
{



    RenderWindow window(VideoMode(1680,1050), "Bomberman!");//запуск окна






    Pole DestroyStone, IndestructibleStone, BG, Door;
    Hero hero;
    Bomb bomb;


    IndestructibleStone.DrawIndestructibleStone();//вся отрисовка неломающегося камня
    DestroyStone.DrawDestroyStone();//вся отрисовка ломающегося камня
    BG.Background();
    Door.Door(DestroyStone);

    hero.Face_Hero_stay();

    while (window.isOpen())//главный цикл программы
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();//повтор



        BG.DrawBackground(window);
        Door.DrawDoor(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window, DestroyStone);
        hero.Draw_Hero_Stay(window);
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Left))//нажатие клавиши 
        {
            hero.Left_Hero_stay();//Анимация разворота

            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x - hero.move) / 50][hero.coords_y / 50])//чтоб не врезаться в стену
            {
                hero.Draw_Left_Hero_Stay(window);//отрисовка 
                event.type = Event::KeyReleased;//отпускание клавиши
            }




        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Right))
        {
            hero.Right_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x + 50) / 50][hero.coords_y / 50])
            {
                hero.Draw_Right_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
        {
            hero.Up_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y - hero.move) / 50])
            {
                hero.Draw_Up_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
        {
            hero.Face_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y + 50) / 50])
            {
                hero.Draw_Down_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");

        }//временно
        
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::W))
        {

            bomb.DrawBomb(hero);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords);
            event.type = Event::KeyPressed;


        }
        bomb.DrawWindowBomb(window);
        
        window.display();//повтор
    }


}
