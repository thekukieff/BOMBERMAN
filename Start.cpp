#include "Start.hpp"



Game::Game()
{

    srand(time(NULL));
    Load();
    RenderWindow window(VideoMode(1680, 1050), "Bomberman!", Style::Fullscreen);//çàïóñê îêíà
        Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
        text.setStyle(Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
        text.setFillColor(Color::Black);

    while (window.isOpen())//ãëàâíûé öèêë ïðîãðàììû

    {
        //music.play();
        timer_game = clock_game.getElapsedTime().asSeconds();   

        std::ostringstream playerTime;
        playerTime << timer_game;
        text.setString("Time "+playerTime.str()+"\\350");
        text.setPosition(0, 0);
        //text.setPosition(text.getCenter().x - 165, view.getCenter().y - 200);

        //std::cout << timer_game << std::endl;
        //std::cout << timer_bomb<<std::endl;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();//ïîâòîð
        


        if (!boom_true)
        {
            clock_boom.restart();
            timer_boom -= timer_boom;
            
        }
        if (!boom)
        {
            clock_bomb.restart();
            
            timer_bomb -= timer_bomb;
        }


        BG.DrawBackground(window);
        Door.DrawDoor(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);
        hero.Draw_Hero_Stay(window);
        window.draw(text);

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Left))//íàæàòèå êëàâèøè 
        {
            hero.Left_Hero_stay();//Àíèìàöèÿ ðàçâîðîòà

            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x - hero.move) / 50][hero.coords_y / 50])//÷òîá íå âðåçàòüñÿ â ñòåíó
            {
                if (!(hero.coords_x == bomb.x + 50 && hero.coords_y == bomb.y))
                {

                    hero.Draw_Left_Hero_Stay(window);//îòðèñîâêà 
                    event.type = Event::KeyReleased;//îòïóñêàíèå êëàâèøè
                }
            }

        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Right))
        {
            hero.Right_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x + 50) / 50][hero.coords_y / 50])
            {
                if (!(hero.coords_x == bomb.x - 50 && hero.coords_y == bomb.y))
                {
                    hero.Draw_Right_Hero_Stay(window);
                    event.type = Event::KeyReleased;

                }
            }
        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
        {
            hero.Up_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y - hero.move) / 50])
            {
                if (!(hero.coords_x == bomb.x && hero.coords_y == bomb.y + 50))
                {

                    hero.Draw_Up_Hero_Stay(window);
                    event.type = Event::KeyReleased;
                }
            }
        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
        {
            hero.Face_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y + 50) / 50])
            {
                if (!(hero.coords_x == bomb.x && hero.coords_y == bomb.y - 50))
                {

                    hero.Draw_Down_Hero_Stay(window);
                    event.type = Event::KeyReleased;
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape) || timer_game == MAX_TIME )
        {

            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");
            std::cout << "\nenemyx " << " " << enemy1.x << " " << enemy2.x << " " << enemy3.x << " " << enemy4.x << " " << enemy5.x;
            std::cout << "\nboom coords: " << Boom.boom_x << ' ' << Boom.boom_y;
            std::cout << "\nboom coords: " << Boom.x << ' ' << Boom.y;


        }//âðåìåííî

        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::W) && !bomb.bomb_count)
        {

            if ((hero.coords_x % 100 == 0 && hero.coords_y % 100 == 0) || (hero.coords_x % 100 == 50 && hero.coords_y % 100 == 0) ||
                (hero.coords_x % 100 == 0 && hero.coords_y % 100 == 50) ||
                (hero.coords_x % 100 == 50 && hero.coords_y % 100 == 50))//ìîæíî ëè ïîñòàâèòü áîìáó
            {//ïîñòàâèòü çâóê òèïî íåëüçÿ ñòàâèòü  ìèíó;
                boom = true;
                bomb.bomb_count = 1;


                bomb.DrawBomb(hero);
            }

            else {
                sound_error_bomb.setBuffer(error_bomb);
                sound_error_bomb.play();
            }
            event.type = Event::KeyPressed;

        }
        enemy1.DrawWindowEnemy(window, DestroyStone, hero);
        enemy2.DrawWindowEnemy(window, DestroyStone, hero);
        enemy3.DrawWindowEnemy(window, DestroyStone, hero);
        enemy4.DrawWindowEnemy(window, DestroyStone, hero);
        enemy5.DrawWindowEnemy(window, DestroyStone, hero);

        bomb.CollisionEnemy(enemy1);
        bomb.CollisionEnemy(enemy2);
        bomb.CollisionEnemy(enemy3);
        bomb.CollisionEnemy(enemy4);
        bomb.CollisionEnemy(enemy5);
       // std::cout << timer_boom << std::endl;


        bomb.DrawWindowBomb(window);
        if ( boom_true)
        {
            timer_boom = clock_boom.getElapsedTime().asSeconds();

            if (timer_boom == 3 )
            {
            std::cout << "\nasdasdasdasd\n";

            boom_true = false;
            timer_boom -= timer_boom;
            clock_boom.restart();
            }
            else
            {
                Boom.DrawWindowBoom(window);
             
            }
        }

        //sleep(seconds(10));


        if (hero.coords_x == Door.door_x * 50 && hero.coords_y == Door.door_y * 50)
        {
            std::cout << "çàøåë\n";
            if (!enemy1.life && !enemy2.life && !enemy3.life && !enemy4.life && !enemy5.life)
            {
                std::cout << "\nWIN";
                window.close();
            }
        }

        if (boom)
        {
            timer_bomb = clock_bomb.getElapsedTime().asSeconds();

            if (timer_bomb == 3)//òàéìåð áîìáû
            {
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy1, hero, window);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy2, hero, window);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy3, hero, window);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy4, hero, window);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy5, hero, window);

                Boom.BOOM(hero, bomb);//взрыв
                bomb.BombDelete();
                   

                clock_bomb.restart();
                timer_bomb -= timer_bomb;


                boom_true = true;
                boom = false;
                bomb.bomb_count = 0;
            }

        }
        window.display();//ïîâòîð
    }


}

void Game::Load()
{
    error_bomb.loadFromFile("music/error.mp3");
    music.openFromFile("music/music.mp3");
    font.loadFromFile("shrift/volda.otf");
    
    


    IndestructibleStone.DrawIndestructibleStone();//âñÿ îòðèñîâêà íåëîìàþùåãîñÿ êàìíÿ
    DestroyStone.DrawDestroyStone();//âñÿ îòðèñîâêà ëîìàþùåãîñÿ êàìíÿ
    BG.Background();
    Door.Door(DestroyStone);
    enemy1.DrawEnemy();
    enemy2.DrawEnemy();
    enemy3.DrawEnemy();
    enemy4.DrawEnemy();
    enemy5.DrawEnemy();
    hero.Draw_Hero_Death();
    //âûíåñòè â îòäåëüíóþ ôóíêöèþ
    //ðàçîáðàòüñÿ ñ ðàíäîìîì


    Boom.DrawBoom();
    hero.Face_Hero_stay();

}


