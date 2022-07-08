#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "bullet.h"

 enum animationstate
 {
    IDLE,LEFT,RIGHT,UP,DOWN
 };

class Player
{
    private:

        int state;

        sf::IntRect currentsprite;
        int activebullet=0;
        int groundheight;
        float jumpspeed;
        float movespeed;
        float gravity;
        sf::Vector2f mousy;
        sf::Vector2f direction{ 0.0f,0.0f };


        float x=0.f;
        sf::Clock clock;
        bool moving;

        void initvariable();
        void initatexture();
        void initsprite();
        void initphysics();



    public:
        bullet barry[10];
        sf::Vector2f velocity;
        bool inair;
        sf::Sprite sprite;
        sf::Texture texture;
        Player();
        virtual ~Player();

        void firebullet(bullet bulletarray[]);
        void lockaxis();
        void update();
        void render(sf::RenderWindow & window);
        void movement();
        void animate();

};

#endif // PLAYER_H
