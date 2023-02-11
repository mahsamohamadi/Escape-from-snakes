#include "game.h"
#include<windows.h>
#include <iostream>


game::game()
{
    this->initVariables();
    this->initwindow();
    this->initfont();
    this->inittext();
}

game::~game()
{
    delete this->window;
}

void game::initVariables()
{
    this->endgame = false;
    this->points =0;

}

void game::initwindow()
{
    this -> videomode = sf::VideoMode(800 , 600);
    this -> window = new sf::RenderWindow(this->videomode , "Scape Snake" , sf::Style::Close | sf::Style::Titlebar);
}
void game::inittext()
{
    //points text
    this->text.setFont(this->font);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(32);

    //end game text
    this->endgametext.setFont(this->font);
    this->endgametext.setFillColor(sf::Color::Red);
    this->endgametext.setCharacterSize(40);
    this->endgametext.setPosition(sf::Vector2f(20 ,300));
    this->endgametext.setString("YOU ARE DEAD, EXIT THE GAME!");
}

void game::update()
{
    this->pollEvents();
    if(!this->c.finished())
    {
        this->c.updatekay();
        this->c.updatekay();
        Sleep(5);
        this->c.updetesnake();
        this->updatepoints();
    }


}

void game::render()
{
    this->window->clear();
    this->c.render(this-> window);
    this->renderp(this->window);
    if(this->c.finished())
    {
        this->window->draw(this->endgametext);
    }
    this->window->display();
    sf::Time elapsed = startTime.getElapsedTime();
    this->points = static_cast<int> (elapsed.asSeconds());

}
void game::renderp(sf::RenderTarget* target)
{
    target->draw(this->text);
}
void game::initfont()
{
    if(!this->font.loadFromFile("actionj.ttf"))
    {
        std::cout << "ERROR!!" <<"\n";
    }
}
void game::updatepoints()
{
    std::stringstream ss;
    ss << " Points : " << this->points ;
    this->text.setString(ss.str());

}

const bool game::running() const
{
    return this->window->isOpen();
}

void game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;

        }
    }
}

