#include "Hero_sprite.hpp"
#include "Pole.hpp"

int main()
{
    float a = 100;
    float b = 13;
    setlocale(LC_ALL, "RU");
    std::cout << std::fmod(a, b)<<std::endl;
    RenderWindow window(sf::VideoMode(800, 800), "SFML works!", Style::Fullscreen);//запуск окна
    //RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//запуск окна
    //CircleShape shape(100.f);//создание круга

    //Image Hero_image;


    //Texture Hero_texture;


    //Sprite Hero_sprite;

    


   

    Pole DestroyStone, IndestructibleStone, BG, Wall;
    IndestructibleStone.DrawIndestructibleStone();//вся отрисовка неломающегося камня
    DestroyStone.DrawDestroyStone();//вся отрисовка ломающегося камня
    BG.Background();

    Hero Stay_face;
    //Stay_left.Left_Hero_stay();
    Stay_face.Face_Hero_stay();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();//повтор



        BG.DrawBackground(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);
        Stay_face.Draw_Hero_Stay(window);
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::Left))
        {



                Stay_face.Draw_Left_Hero_Stay(window);
                event.type = Event::KeyPressed;
        }
       
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::Right))
        {
            Stay_face.Draw_Right_Hero_Stay(window);
            event.type = Event::KeyPressed;
        }
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::Up))
        {
            Stay_face.Draw_Up_Hero_Stay(window);
            event.type = Event::KeyPressed;
        }
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::Down))
        {
            Stay_face.Draw_Down_Hero_Stay(window);
            event.type = Event::KeyPressed;

        }
        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");
        }
        
        window.display();//повтор
    }

    return 0;
}