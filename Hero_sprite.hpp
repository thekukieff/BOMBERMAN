#ifndef HERO_SPRITE
#define HERO_SPRITE

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <sstream>
using namespace sf;


class Hero {

public:
	void Face_Hero_stay();
	void Left_Hero_stay();
	void Right_Hero_stay();
	void Up_Hero_stay();
	void Draw_Down_Hero_Stay(RenderWindow& window);
	void Draw_Left_Hero_Stay(RenderWindow& window);
	void Draw_Up_Hero_Stay(RenderWindow& window);
	void Draw_Right_Hero_Stay(RenderWindow& window);
	void Draw_Hero_Stay(RenderWindow& window);
	void Draw_Hero_Death();
	void Draw_Window_Death(RenderWindow& window);
	void Death_Animation(RenderWindow& window);

	int coords_x = 0;
	int coords_y = 50;//ñòàðòîâûå êîîðäèíàòû
	int move = 5;

private:
	Image Hero_image, Death_image0, Death_image1, Death_image2, Death_image3, Death_image4, Death_image5, Death_image6, Death_image7, Death_image8, Death_image9;

	Texture Hero_texture, Death_texture0, Death_texture1, Death_texture2, 
		Death_texture3, Death_texture4, Death_texture5, Death_texture6, Death_texture7, Death_texture8, Death_texture9;

	Sprite Hero_sprite;



};





#endif HERO_SPRITE
