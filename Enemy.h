#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include<ctime>
#include<cstdlib>
#include"block.h"
#include<time.h>
#include"Player.h"
#include"coins.h"
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <vector>
#include "bullet.h"
#include "TileMap.h"
#include <math.h>


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void update(Player *player,block & block);
        void render(sf::RenderWindow & target);
        void detect(Player &player);
        void setpos();


    protected:

    private:
        sf::Vector2f enemysize;
        sf::RectangleShape rect;
        sf::Vector2f enemyfacing;
        sf::Vector2f normalize(sf::Vector2f &point);
        float dot(sf::Vector2f &point1 ,sf::Vector2f &point2);



};

#endif // ENEMY_H
