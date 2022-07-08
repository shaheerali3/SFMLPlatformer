#include "Game.h"

Game::Game()
{
    //ctor

    this->initcoins();
    this->initvector();
    this->initwindow();
    this->initplayer();


    this->backtexture.loadFromFile("Adventurer/planet_1_0.png");
    backtexture.setRepeated(true);
    this->backgroundsize=backtexture.getSize();
    backsprite.setTexture(this->backtexture);

    backsprite.setScale(2.0,2.0);
}

Game::~Game()
{
    //dtor

    delete this->player;
    delete this->coin;
}
void Game::initplayer()
{
    this->player=new Player();
}
void Game::initcoins(){

this->coin=new coins();
this->coin1=new coins();
this->coin2=new coins();
this->coin3=new coins();
this->coin4=new coins();



}

void Game::initvector()
{

        this->coin->setposition(300,270);
        this->coin1->setposition(350,270);
        this->coin2->setposition(400,270);
        this->coin3->setposition(float(rand()%200),300);
        this->coin4->setposition(float(rand()%200),300);


      coinpoint.push_back(coin);
      coinpoint.push_back(coin1);
      coinpoint.push_back(coin2);
      coinpoint.push_back(coin3);
      coinpoint.push_back(coin4);

      this->block.setposition(300,350);
      this->black1.setposition(380,350);
      this->black2.setposition(500,200);
      this->black3.setposition(580,200);


        this->b1.push_back(block);
        this->b1.push_back(black1);
        this->b1.push_back(black2);
        this->b1.push_back(black3);

}


void Game::initwindow()
{

    this->window.create(sf::VideoMode(800,600),"2dplatformer",sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);

}

const sf::RenderWindow & Game::getWindow() const
{
    return this->window;
}
void Game::update()
{
    while(this->window.pollEvent(this->ev))
    {
        if(this->ev.type==sf::Event::Closed){
            this->window.close();
        }
        else if(this->ev.type==sf::Event::KeyPressed && this->ev.key.code==sf::Keyboard::Escape){
            this->window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    this->player->firebullet(bullets);
    }
    }

    this->updateplayer();
    for(int i=0; i<coinpoint.size(); i++){
        if(coinpoint[i]->updatecoins(this->player)){
            coinpoint.erase(this->coinpoint.begin()+i);
        }
    }
    for(int i=0; i<b1.size(); i++){
    this->b1[i].update(this->player);
    }
    for(int i =0; i<10; i++){
        this->bullets[i].update();
    }
    this->enemytangle.update(this->player,this->block);


}
void Game::render()
{

    this->window.clear();
    //this->window.draw(m_grass);
    this->window.draw(this->backsprite);


    this->player->render(this->window);
    //this->enemytangle.render(this->window);
    //this->coin->rendercoins(this->window);
    //this->block.renderblock(this->window);
    for(auto &i: coinpoint)
        {
           i->rendercoins(this->window);
        }
    for(auto &g:b1){
        g.renderblock(this->window);
    }
    for(int i=0; i<10; i++){
        this->bullets[i].renderbullet(window);
    }

    this->window.display();
}

void Game::updateplayer()
{
    this->player->update();
}

