#ifndef START_HPP
#define START_HPP
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Bomb.hpp"
#include "Enemy.hpp"
class Game{
public:


   Game();
   void Load();


private:
    bool boom = false;
    bool boom_true = false;
    Font font;//רנטפע 

    Pole DestroyStone, IndestructibleStone, BG, Door;
    Hero hero;
    Bomb bomb, Boom;
    Enemy enemy1, enemy2, enemy3, enemy4, enemy5;
    Clock clock_bomb, clock_game, clock_boom;
    SoundBuffer error_bomb;
    Sound sound_error_bomb;
    Music music; 
    


    const int MAX_TIME = 350;
    int timer_bomb = 0;
    int timer_game = 0;
    int timer_boom = 0;


};







#endif START_HPP