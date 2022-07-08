#ifndef COINS_H
#define COINS_H
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include"Player.h"


class coins
{


     private:
        sf::CircleShape coin;
        bool playerincoin;

        void initcoins();

    public:
        coins();
        virtual ~coins();
        bool updatecoins(Player *Player);
        void rendercoins(sf::RenderTarget & target);
        void setposition(float x , float y);





};

#endif // COINS_H
