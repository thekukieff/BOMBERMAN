#ifndef BOMB_HPP
#define BOMB_HPP
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Enemy.hpp"
class Bomb {
public:
	void BOOM(Hero& hero, Bomb& bomb);
	void DrawBomb(Hero& hero);
	void DrawWindowBomb(RenderWindow& window);
	void DestroyBomb(int Destroy_stone_coords[32][21], Enemy& enemy, Hero& hero, RenderWindow& window);
	void CollisionEnemy(Enemy& enemy);
	void DrawBoom();
	void DrawWindowBoom(RenderWindow& window);
	void BombDelete();
	void Kill(Enemy &enemy);


	int x = -100;
	int y = -100;
	int boom_x = -100;
	int boom_y = -100;
	int bomb_count = 0;
private:
	Texture Bomb_big_texture, Boom_texture;
	Sprite  Bomb_big_sprite, Boom_sprite;
	Image  Bomb_big_image, Boom_image;
	int Power = 1;




};






#endif BOMB_HPP
