#include "Hero_sprite.hpp"


//RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//запуск окна
//CircleShape shape(100.f);//создание круга
//
//Image Hero_image;
//
//
//Texture Hero_texture;
//
//
//Sprite Hero_sprite;



//Hero_texture.loadFromImage(Hero_image);
//Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/norm_sprite.png");
//shape.setFillColor(sf::Color::Green);//заполнить круг зеленым
//Hero_sprite.setTexture(Hero_texture);
//Hero_sprite.setPosition(25, 25);

void Hero::Face_Hero_stay()//данные, стоит лицом
{


    Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/stay_face.png");
    Hero_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);





}

void Hero::Collision()
{
           // std::cout << "x: " << coords_x%100 << std::endl << "y: " << coords_y%100 <<std::endl;
            if (coords_x%100== 50 && coords_y % 100 ==50)
            {
                std::cout << "СТОЛКНОВЕНИЕ";
            }
            else {



            }



}

void Hero::Left_Hero_stay()//данные, стоит влево
{


    Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/stay_left.png");
    Hero_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);
    




}

void Hero::Right_Hero_stay()//данные, стоит вправо
{
    Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/stay_right.png");
    Hero_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);



}

void Hero::Up_Hero_stay()//данные, стоит спиной
{
    Hero_image.loadFromFile("F:/Игорь/C++/07.06.24/sprites/stay_up.png");
    Hero_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);


}

void Hero::Draw_Down_Hero_Stay(RenderWindow& window)//отрисовка, стоит лицом
{
    Face_Hero_stay();

    Hero_sprite.setPosition(coords_x, coords_y+=10);
    Collision();
    window.draw(Hero_sprite);
}

void Hero::Draw_Left_Hero_Stay(RenderWindow& window)//отрисовка, стоит влево
{

    Left_Hero_stay();

    Hero_sprite.setPosition(coords_x-=10, coords_y);
    Collision();
    window.draw(Hero_sprite);




}

void Hero::Draw_Up_Hero_Stay(RenderWindow& window)//отрисовка, стоит спиной
{

        Up_Hero_stay();
        Hero_sprite.setPosition(coords_x, coords_y -= 10);
        Collision();
        window.draw(Hero_sprite);


}

void Hero::Draw_Right_Hero_Stay(RenderWindow& window)//отрисовка, стоит вправо
{


        Right_Hero_stay();

        Hero_sprite.setPosition(coords_x += 10, coords_y);
        Collision();
        window.draw(Hero_sprite);


}


void Hero::Draw_Hero_Stay(RenderWindow& window)//отрисовка, старт
{
    window.draw(Hero_sprite);
}


