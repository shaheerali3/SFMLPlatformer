#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
    this->enemysize.x=50.f;
    this->enemysize.y=50.f;
    this->rect.setFillColor(sf::Color::Blue);
    this->rect.setSize(this->enemysize);
    this->rect.setOrigin(25.f,25.f);
    this->rect.setPosition(600,300);

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::render(sf::RenderWindow & target){
    target.draw(this->rect);

}

sf::Vector2f Enemy::normalize(sf::Vector2f &point)
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

float Enemy::dot(sf::Vector2f &point1 ,sf::Vector2f &point2)
{
    float scaler =(point1.x*point2.x)+(point1.y*point2.y);
    return scaler;



}
//void Enemy::detect(Player &player){


//}
void Enemy::update(Player *player, block & block){

    double pi=3.14159265;
    this->enemyfacing =block.blocksprite.getPosition()-this->rect.getPosition();

    sf::Vector2f point1=normalize(this->enemyfacing);
    sf::Vector2f guardtohero=player->sprite.getPosition()-this->rect.getPosition();
    sf::Vector2f point2=normalize(guardtohero);
    float dotvalue=dot(point1,point2);
    double angle=acos(dotvalue*pi /180);
    double newangle=angle*180/pi;
    std::cout<<newangle<<std::endl;
    if(newangle>=60&&newangle<=120){
        this->rect.move(point2);
    }


}


