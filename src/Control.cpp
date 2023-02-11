#include "Control.h"
#include "snake.h"
#include "Board.h"
#include <vector>
#include <windows.h>
#include <SFML/Graphics.hpp>
Control::Control()
{
    this->s.push_back(new snake(100,50));  //Snake 1
    this->snake1.setRadius(15.f);
    this->snake1.setFillColor(sf::Color::Red);
    this->snake1.setPosition(s[0]->get_x() , s[0]->get_y());

    this->s.push_back(new snake(500,500));   //Snake 2
    this->snake2.setRadius(15.f);
    this->snake2.setFillColor(sf::Color::Blue);
    this->snake2.setPosition(s[1]->get_x() , s[1]->get_y());

    this->s.push_back(new snake(600,60));   //snake3
    this->snake3.setRadius(15.f);
    this->snake3.setFillColor(sf::Color::Yellow);
    this->snake3.setPosition(s[2]->get_x() , s[2]->get_y());

    this->shape.setFillColor(sf::Color::Green);   //player
    this->shape.setPosition(p.get_x() ,p.get_y());
    this->shape.setSize(sf::Vector2f(30.f , 30.f));
}
Control::~Control()
{
    for(size_t i=0 ; i <s.size() ; i++)  //Remove built snakes
    {
        delete s[i];
    }
}


void Control::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->snake1);
    target->draw(this->snake2);
    target->draw(this->snake3);
}

void Control::updatekay()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        p.move('A');
        this->shape.setPosition(p.get_x(),p.get_y());
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        p.move('D');
        this->shape.setPosition(p.get_x(),p.get_y());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        p.move('W');
        this->shape.setPosition(p.get_x(),p.get_y());
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        p.move('S');
        this->shape.setPosition(p.get_x(),p.get_y());
    }

}
void Control::updetesnake()
{

    for(size_t i =0 ; i<s.size() ; i++)
    {
        s[i]->move(p);
        if(i ==0)
            this->snake1.setPosition(s[0]->get_x() , s[0]->get_y());
        if(i==1)
            this->snake2.setPosition(s[1]->get_x() , s[1]->get_y());
        if(i == 2)
            this->snake3.setPosition(s[2]->get_x() , s[2]->get_y());

    }
}

bool Control::finished()
{
    bool f ;
    f =false;
    for(size_t i =0 ; i<s.size() ; i++)
    {
        if((s[i]->get_x() == p.get_x()) && (s[i]->get_y() == p.get_y()))
            f = true;
    }
    return f;
}

