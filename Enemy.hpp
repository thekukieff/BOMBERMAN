#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Hero_sprite.hpp"
#include "Pole.hpp"



class Enemy {
public:
	void DrawEnemy();
	void DrawEnemyLeft();
	void DrawEnemyRight();
	void DrawEnemyUp();
	void DrawEnemyDown();

	void DrawWindowEnemy(RenderWindow& window, Pole& Stone, Hero& hero);


	int x;
	int coords_x = 0;
	int coords_y = 0;
	int y;
	int move = 1;
	int move_y = 0;
	bool life = true;//æèâåò èëè íåò
private:
	bool first_y = false;
	bool first_x = false;
	int up_down, left_right;
	bool move_x = true;
	Image Enemy_image;
	Sprite Enemy_sprite;
	Texture Enemy_texture;
};






#endif ENEMY_HPP