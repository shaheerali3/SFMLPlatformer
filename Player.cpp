#include "Player.h"
#include<iostream>



Player::Player()
{
    //ctor
    this->initvariable();
    this->initatexture();
    this->initsprite();
    this->initphysics();


}

Player::~Player()
{

}

void Player::initatexture()
{

    if(!this->texture.loadFromFile("Adventurer/chpepper2squirePNG-trimmy.png")){
        throw "could not load file";
    }
}

void Player::initsprite()
{

    this->sprite.setTexture(this->texture);
    this->currentsprite=sf::IntRect(9,0,19,31);
    this->sprite.setOrigin(15.33,16);
    this->sprite.setTextureRect(this->currentsprite);
    this->sprite.setScale(4.f,2.f);

    this->sprite.setPosition(0,groundheight);

}
void Player::initphysics(){

this->movespeed=3.f;
this->jumpspeed=13.f;
this->gravity=.39f;
velocity.x=0;
velocity.y=0;
this->inair=false;


}

void Player::movement()
{
    //std::cout<<this->sprite.getPosition().x<<std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->state=LEFT;
        velocity.x=-movespeed;


    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->state=RIGHT;
        velocity.x=movespeed;

    }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)&&this->sprite.getPosition().y>0 && this->inair==false)
    {
        this->state=UP;
        velocity.y=-jumpspeed;
        this->inair=true;

    }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->state=DOWN;
            this->sprite.move(0.f,1.f);
    }
    else{
        this->state=IDLE;
        velocity.x=0;
    }


    if(this->sprite.getPosition().y + this->sprite.getTexture()->getSize().y < groundheight || velocity.y<0){
        velocity.y+=gravity;

    }
    else{
        this->sprite.setPosition(this->sprite.getPosition().x,groundheight-32);
        velocity.y=0;


    }
    if(velocity.y==0)
    {
        this->inair=false;
    }

    this->sprite.move(velocity.x,velocity.y);


}
void Player::firebullet(bullet bulletarray[])
{

    direction=this->mousy-this->sprite.getPosition();
    bulletarray[this->activebullet].loadbullet(direction,this->sprite.getPosition());
    std::cout<<"bullet loaded"<<std::endl;
    this->activebullet++;
    if(this->activebullet==8)
    {
        this->activebullet=0;

    }

}

void Player::lockaxis()
{
    this->sprite.setPosition(this->sprite.getPosition().x,this->sprite.getPosition().y);
}
void Player::initvariable()
{
    this->state=IDLE;
    this->moving=false;
    this->groundheight=530;
}

void Player::animate()
{
if(this->state==IDLE){
if(this->clock.getElapsedTime().asSeconds()>=0.5f){

    this->currentsprite=sf::IntRect(x*32,0,32,32);
    x++;

    if(x*32>64.f){
        x=0;
    }
    clock.restart();
    this->sprite.setTextureRect(this->currentsprite);
}
}
if(this->state==LEFT){
        if(this->clock.getElapsedTime().asSeconds()>=0.1f){
        this->currentsprite=sf::IntRect((x*16),32,16,32);
        x++;
        if(x*16>32.f){
        x=0;
    }
    clock.restart();
    this->sprite.setTextureRect(currentsprite);

        }
}
else if(this->state==RIGHT){
        if(this->clock.getElapsedTime().asSeconds()>=0.1f){

        this->currentsprite=sf::IntRect((x*16),64,16,32);
        x++;
        if(x*16>32.f){
        x=0;
    }
    clock.restart();
    this->sprite.setTextureRect(currentsprite);

        }
}
else{
    clock.restart();
}

}

void Player::update()
{

    this->movement();
    this->animate();

}
void Player::render(sf::RenderWindow & window)
{
    this->mousy=window.mapPixelToCoords(sf::Mouse::getPosition(window));
    window.draw(this->sprite);
}

