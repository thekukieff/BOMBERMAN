#ifndef POLE_HPP
#define POLE_HPP
#include "Hero_sprite.hpp"
class Pole
{
public:
	void DrawIndestructibleStone();
	void DrawDestroyStone();
	void Background();
	void DrawBackground(RenderWindow &window);
	void WindowDrawDestroy(RenderWindow &window);

	void DrawPole(RenderWindow& window);
	

private:
	Texture Destroy_stone_texture, Indestructible_stone_texture;
	Sprite Destroy_stone_sprite, Indestructible_stone_sprite;
	Image Destroy_stone_image, Indestrucyible_stone_image;
	RectangleShape rectangle, up_wall, right_wall;
	static const int SIZE = 672;
	int Destroy_stone_coords[SIZE];//положение ломающегося камня


};

#endif POLE_HPP