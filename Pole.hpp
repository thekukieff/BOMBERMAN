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
	void DrawBomb();
	void DrawWindowBomb(RenderWindow& window, Hero& hero);


	static const int COL = 32;
	static const int ROW = 21;
	int Destroy_stone_coords[COL][ROW];//положение ломающегося камня
private:
	Texture Destroy_stone_texture, Indestructible_stone_texture, Bomb_big_texture;
	Sprite Destroy_stone_sprite, Indestructible_stone_sprite, Bomb_big_sprite;
	Image Destroy_stone_image, Indestrucyible_stone_image, Bomb_big_image;
	RectangleShape rectangle, up_wall, right_wall;




};

#endif POLE_HPP