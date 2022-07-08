#include "bullet.h"

bullet::bullet()
{
    //ctor
    this->bullets.setRadius(5.f);
    this->bullets.setFillColor(sf::Color::Red);
    this->bullets.setOrigin(1.5f,1.5f);






}

bullet::~bullet()
{
    //dtor
}

void bullet::loadbullet(sf::Vector2f position,sf::Vector2f bulletdirection)
{
    this->bullets.setPosition(bulletdirection);
    this->direction=normalize(position);
    std::cout<<this->direction.x<<std::endl;
    isactive=true;


}

sf::Vector2f bullet::normalize(sf::Vector2f & point)
{
    float length=sqrt((point.x*point.x)+(point.y*point.y));
    if(length!=0)
        {
            return sf::Vector2f(point.x/length,point.y/length);
        }
    else
        {
            return point;
        }
}

void bullet::update()
{
    if(isactive==true){

        this->bullets.move(direction*speed);



    }

}

void bullet::renderbullet(sf::RenderTarget & target)
{
    target.draw(this->bullets);

}


