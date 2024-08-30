#include "Hero_sprite.hpp"
#include "Pole.hpp"

void Hero::Face_Hero_stay()//äàííûå, ñòîèò ëèöîì
{


    Hero_image.loadFromFile("sprites/stay_face.png");
    Hero_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);





}


void Hero::Left_Hero_stay()//äàííûå, ñòîèò âëåâî
{


    Hero_image.loadFromFile("sprites/stay_left.png");
    Hero_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);




}

void Hero::Right_Hero_stay()//äàííûå, ñòîèò âïðàâî
{
    Hero_image.loadFromFile("sprites/stay_right.png");
    Hero_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);



}

void Hero::Up_Hero_stay()//äàííûå, ñòîèò ñïèíîé
{
    Hero_image.loadFromFile("sprites/stay_up.png");
    Hero_image.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);


}

void Hero::Draw_Down_Hero_Stay(RenderWindow& window)//îòðèñîâêà, ñòîèò ëèöîì
{



    if (coords_x % 100 == 0) {//÷òîá íå âðåçàòüñÿ â ñòåíó
        if (coords_y + move <= 1000)//max-50(=)
        {

            Hero_sprite.setPosition(coords_x, coords_y += move);
        }
    }


    window.draw(Hero_sprite);
}

void Hero::Draw_Left_Hero_Stay(RenderWindow& window)//îòðèñîâêà, ñòîèò âëåâî
{


    if (coords_y % 100 == 0) {//÷òîá íå âðåçàòüñÿ â ñòåíó
        if (coords_x - move >= 0) {
            Hero_sprite.setPosition(coords_x -= move, coords_y);
        }

    }


    window.draw(Hero_sprite);




}

void Hero::Draw_Up_Hero_Stay(RenderWindow& window)//îòðèñîâêà, ñòîèò ñïèíîé
{


    if (coords_x % 100 == 0) {//÷òîá íå âðåçàòüñÿ â ñòåíó

        if (coords_y - move >= 50)
        {

            Hero_sprite.setPosition(coords_x, coords_y -= move);
        }

    }




    window.draw(Hero_sprite);


}

void Hero::Draw_Right_Hero_Stay(RenderWindow& window)//îòðèñîâêà, ñòîèò âïðàâî
{




    if (coords_y % 100 == 0) {//÷òîá íå âðåçàòüñÿ â ñòåíó

        if (coords_x + move <= 1550) {
            Hero_sprite.setPosition(coords_x += move, coords_y);
        }
    }


    window.draw(Hero_sprite);


}


void Hero::Draw_Hero_Stay(RenderWindow& window)//îòðèñîâêà, ñòàðò
{
    Hero_sprite.setPosition(coords_x, coords_y);
    window.draw(Hero_sprite);
}

void Hero::Draw_Hero_Death()
{

    Death_image0.loadFromFile("sprites/1.png");
    Death_image0.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture0.loadFromImage(Death_image0);
    Hero_sprite.setTexture(Death_texture0);

    Death_image1.loadFromFile("sprites/2.png");
    Death_image1.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture1.loadFromImage(Death_image1);
    //Death_sprite1.setTexture(Death_texture1);

    Death_image2.loadFromFile("sprites/3.png");
    Death_image2.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture2.loadFromImage(Death_image2);
    //Death_sprite2.setTexture(Death_texture2);

    Death_image3.loadFromFile("sprites/4.png");
    Death_image3.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture3.loadFromImage(Death_image3);
   // Death_sprite3.setTexture(Death_texture3);

    Death_image4.loadFromFile("sprites/5.png");
    Death_image4.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture4.loadFromImage(Death_image4);
   // Death_sprite4.setTexture(Death_texture4);

    Death_image5.loadFromFile("sprites/6.png");
    Death_image5.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture5.loadFromImage(Death_image5);
  //  Death_sprite5.setTexture(Death_texture5);

    Death_image6.loadFromFile("sprites/7.png");
    Death_image6.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture6.loadFromImage(Death_image6);
   // Death_sprite6.setTexture(Death_texture6);

    Death_image7.loadFromFile("sprites/8.png");
    Death_image7.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture7.loadFromImage(Death_image7);
   // Death_sprite7.setTexture(Death_texture7);

    Death_image8.loadFromFile("sprites/9.png");
    Death_image8.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture8.loadFromImage(Death_image8);
   // Death_sprite8.setTexture(Death_texture8);

    Death_image9.loadFromFile("sprites/10.png");
    Death_image9.createMaskFromColor(Color::White);//óáèðàåò áåëûé (çàäíèé ôîí)
    Death_texture9.loadFromImage(Death_image9);
  //  Death_sprite9.setTexture(Death_texture9);


} 

void Hero::Draw_Window_Death(RenderWindow& window)
{
    Font font;//шрифт 
    font.loadFromFile("shrift/volda.otf");

    Text death("", font, 100);
    death.setStyle(Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
    death.setFillColor(Color::Red);
    death.setString("YOU DEAD");
    death.setPosition(600, 500);
    
    sleep(seconds(0.5));
    Hero_sprite.setTexture(Death_texture1);
    Death_Animation(window);
    


    Hero_sprite.setTexture(Death_texture2);
    Death_Animation(window);


    Hero_sprite.setTexture(Death_texture3);

    Death_Animation(window);



    Hero_sprite.setTexture(Death_texture4);
    Death_Animation(window);

    Hero_sprite.setTexture(Death_texture5);
    Death_Animation(window);


    Hero_sprite.setTexture(Death_texture6);
    Death_Animation(window);



    Hero_sprite.setTexture(Death_texture7);

    Death_Animation(window);


    Hero_sprite.setTexture(Death_texture8);
    Death_Animation(window);


    Hero_sprite.setTexture(Death_texture9);
    Death_Animation(window);
    window.clear();

    //sleep(seconds(2));

    window.draw(death);
    window.display();
    sleep(seconds(4));

    
    exit(0);

}

void Hero::Death_Animation(RenderWindow& window)
{
    static int x = 0;
    Hero_sprite.setPosition(x + coords_x, coords_y);
    window.clear();//ïîâòîð
    window.draw(Hero_sprite);

    sleep(seconds(0.5));

    window.display();
    x += 10;


}





