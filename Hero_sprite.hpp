#ifndef HERO_SPRITE
#define HERO_SPRITE
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>
using namespace sf;

class Hero {

public:
	void Face_Hero_stay();
	void Left_Hero_stay();
	void Right_Hero_stay();
	void Up_Hero_stay();
	void Draw_Down_Hero_Stay(RenderWindow& window);
	void Draw_Left_Hero_Stay(RenderWindow &window);
	void Draw_Up_Hero_Stay(RenderWindow& window);
	void Draw_Right_Hero_Stay(RenderWindow& window);
	void Draw_Hero_Stay(RenderWindow &window);
	void Collision(float x, float y);
private:
	Image Hero_image;
	Texture Hero_texture;
	Sprite Hero_sprite;
	float coords_x = 0;
	float coords_y = 0;//стартовые координаты


};





#endif HERO_SPRITE