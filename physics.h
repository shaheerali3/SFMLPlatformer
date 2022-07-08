#ifndef PHYSICS_H
#define PHYSICS_H
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>


class physics
{
    private:
        sf::Vector2f velocity;
        sf::Vector2f accel;
        sf::Vector2f deceleration;
        sf::Vector2f gravity;


    public:
        physics();
        ~physics();

        void updatephysics();
        void initphysics();





};

#endif // PHYSICS_H
