#include "Hero_sprite.hpp"
#include "Pole.hpp"

int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << fmod(100, 13)<<std::endl;
    RenderWindow window(sf::VideoMode(800, 800), "SFML works!", Style::Fullscreen);//������ ����
    //RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//������ ����
    //CircleShape shape(100.f);//�������� �����

    //Image Hero_image;


    //Texture Hero_texture;


    //Sprite Hero_sprite;

    


   

    Pole DestroyStone, IndestructibleStone, BG, Wall;
    IndestructibleStone.DrawIndestructibleStone();//��� ��������� ������������� �����
    DestroyStone.DrawDestroyStone();//��� ��������� ����������� �����
    BG.Background();

    Hero Stay_face;
    //Stay_left.Left_Hero_stay();
    Stay_face.Face_Hero_stay();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();//������



        BG.DrawBackground(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);
        Stay_face.Draw_Hero_Stay(window);
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            
            Stay_face.Draw_Left_Hero_Stay(window);
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            Stay_face.Draw_Right_Hero_Stay(window);
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            Stay_face.Draw_Up_Hero_Stay(window);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            Stay_face.Draw_Down_Hero_Stay(window);
        }
        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");
        }
        
        window.display();//������
    }

    return 0;
}