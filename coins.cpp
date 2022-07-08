#include "coins.h"
#include <iostream>
#include<cstdlib>
coins::coins()
{
    //ctor
    this->initcoins();
}

coins::~coins()
{
    //dtor
}

void coins::initcoins()
{
    this->coin.setRadius(10.f);
    this->coin.setFillColor(sf::Color::Yellow);
}
void coins::rendercoins(sf::RenderTarget & target)
{

    target.draw(this->coin);

}
void coins::setposition(float x ,float y){
    this->coin.setPosition(x,y);

}

bool coins::updatecoins(Player *player){
if(this->coin.getGlobalBounds().intersects(player->sprite.getGlobalBounds())){

    return true;
}


 }



