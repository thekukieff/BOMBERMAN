#include "Hero_sprite.hpp"
#include "Pole.hpp"

int main()
{
    RenderWindow window(sf::VideoMode(800, 800), "SFML works!", Style::Fullscreen);//запуск окна
    //RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//запуск окна
    //CircleShape shape(100.f);//создание круга

    //Image Hero_image;


    //Texture Hero_texture;


    //Sprite Hero_sprite;

    
    Image Hero_image;


    Texture Hero_texture;


    Sprite Hero_sprite;

    Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/stay_face.png");
    Hero_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Hero_texture.loadFromImage(Hero_image);
  
    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(0,1000);

    Pole DestroyStone, IndestructibleStone, BG, Wall;
    IndestructibleStone.DrawIndestructibleStone();//вся отрисовка неломающегося камня
    DestroyStone.DrawDestroyStone();//вся отрисовка ломающегося камня
    DestroyStone.Genetrate();
    BG.Background();



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();//повтор
        BG.DrawBackground(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);

        window.draw(Hero_sprite);//отрисовка

        window.display();//повтор
    }

    return 0;
}