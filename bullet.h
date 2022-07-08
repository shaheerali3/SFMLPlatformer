#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>



class bullet
{
    public:

        sf::CircleShape bullets;

        void update();

        void renderbullet(sf::RenderTarget & target);
        void loadbullet(sf::Vector2f position,sf::Vector2f bulletdirection);
        bullet();
        virtual ~bullet();
        bool isactive=false;

    protected:

    private:

        sf::Vector2f normalize(sf::Vector2f &point);


        sf::Vector2f direction;
        float speed = 5.0f;
        sf::Clock bulletclock;



};

#endif // BULLET_H
