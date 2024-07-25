#include "Hero_sprite.hpp"


//RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//������ ����
//CircleShape shape(100.f);//�������� �����
//
//Image Hero_image;
//
//
//Texture Hero_texture;
//
//
//Sprite Hero_sprite;



//Hero_texture.loadFromImage(Hero_image);
//Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/norm_sprite.png");
//shape.setFillColor(sf::Color::Green);//��������� ���� �������
//Hero_sprite.setTexture(Hero_texture);
//Hero_sprite.setPosition(25, 25);

void Hero::Face_Hero_stay()//������, ����� �����
{


    Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/stay_face.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);





}

void Hero::Collision()
{
           // std::cout << "x: " << coords_x%100 << std::endl << "y: " << coords_y%100 <<std::endl;
            if (coords_x%100== 50 && coords_y % 100 ==50)
            {
                std::cout << "������������";
            }
            else {



            }



}

void Hero::Left_Hero_stay()//������, ����� �����
{


    Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/stay_left.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);
    




}

void Hero::Right_Hero_stay()//������, ����� ������
{
    Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/stay_right.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);



}

void Hero::Up_Hero_stay()//������, ����� ������
{
    Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/stay_up.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);


}

void Hero::Draw_Down_Hero_Stay(RenderWindow& window)//���������, ����� �����
{
    Face_Hero_stay();

    Hero_sprite.setPosition(coords_x, coords_y+=10);
    Collision();
    window.draw(Hero_sprite);
}

void Hero::Draw_Left_Hero_Stay(RenderWindow& window)//���������, ����� �����
{

    Left_Hero_stay();

    Hero_sprite.setPosition(coords_x-=10, coords_y);
    Collision();
    window.draw(Hero_sprite);




}

void Hero::Draw_Up_Hero_Stay(RenderWindow& window)//���������, ����� ������
{

        Up_Hero_stay();
        Hero_sprite.setPosition(coords_x, coords_y -= 10);
        Collision();
        window.draw(Hero_sprite);


}

void Hero::Draw_Right_Hero_Stay(RenderWindow& window)//���������, ����� ������
{


        Right_Hero_stay();

        Hero_sprite.setPosition(coords_x += 10, coords_y);
        Collision();
        window.draw(Hero_sprite);


}


void Hero::Draw_Hero_Stay(RenderWindow& window)//���������, �����
{
    window.draw(Hero_sprite);
}


