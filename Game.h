#ifndef GAME_H
#define GAME_H

#include <iostream>
#include<ctime>
#include<cstdlib>

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
#include "Enemy.h"
#include"block.h"


class Game
{

    private:
        block black1;
        block black2;
        block black3;
        Enemy enemytangle;
        std::vector<block> b1;
        block block;


        sf::VideoMode video;
        sf::RenderWindow window;
        Player* player;
        bool endgame;
        sf::Event ev;
        bullet bullets[10];
        coins* coin;
        coins* coin1;
        coins* coin2;
        coins* coin3;
        coins* coin4;
        sf::Texture backtexture;
        sf::Sprite backsprite;
        sf::Vector2u backgroundsize;


        std::vector<coins*> coinpoint;

        void initcoins();
        void initwindow();
        void initvariables();
        void initplayer();
        void initvector();


    public:
        Game();
        ~Game();
        const bool running() const;
        void update();
        void updateplayer();
        void render();
        const sf::RenderWindow & getWindow() const;

};

#endif // GAME_H
