#include "block.h"
#include<iostream>

block::block()
{
    //ctor
    if(!this->texture.loadFromFile("Adventurer/Minecraft/Grass.png")){
            throw "could not load file";
        }
        this->blocksprite.setTexture(this->texture);
        this->blocksprite.setOrigin(40,40);






}

block::~block()
{
    //dtor
}
void block::update(Player *player)
{
    sf::FloatRect resultant;


    if(player->sprite.getGlobalBounds().intersects(this->blocksprite.getGlobalBounds(),resultant))
        {


            //std::cout<<player->velocity.y<<std::endl;
            //std::cout<<this->blocksprite.getPosition().y<<std::endl;

            std::cout<<resultant.width<<std::endl;

            player->lockaxis();

            sf::Vector2f pos=player->sprite.getPosition();
            if(player->sprite.getPosition().y<this->blocksprite.getPosition().y&& resultant.width>12){
                player->inair=false;

                    player->velocity.y=0;


                pos.y -= resultant.height;


            }
            else if(player->sprite.getPosition().y>this->blocksprite.getPosition().y&&resultant.width>=12){


                pos.y += resultant.height;
            }

            else if(player->sprite.getPosition().x<this->blocksprite.getPosition().x&& resultant.height>=24.f){
                pos.x-=resultant.width;

            }
            else if(player->sprite.getPosition().x>this->blocksprite.getPosition().x&& resultant.height>=24.f){
                pos.x+=resultant.width;
            }

            player->sprite.setPosition(pos);






        }
}

void block::setposition(float x, float y){
    this->blocksprite.setPosition(x,y);

}

void block::renderblock(sf::RenderTarget & target)
{
    target.draw(this->blocksprite);


}
