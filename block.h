#ifndef BLOCK_H
#define BLOCK_H
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


class block
{
    private:
        sf::Texture texture;






    public:
        block();
        virtual ~block();
        sf::Sprite blocksprite;
        void update(Player *player);
        void renderblock(sf::RenderTarget & target);
        void setposition(float x ,float y);



    protected:


};

#endif // BLOCK_H
