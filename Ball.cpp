/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 12:30 PM
 */

#include "Ball.h"

Ball::Ball(float rad, sf::Color col, sf::Vector2f pos, std::shared_ptr<Paddle> pad1, std::shared_ptr<Paddle> pad2) 
{
    setRadius(rad);
    setFillColor(col);
    setOrigin(getRadius() / 2, getRadius() / 2);
    setPosition(pos);
    
    pPad1 = pad1;
    pPad2 = pad2;
    
    direction = 1;
    speed = 0.f;
    movement = sf::Vector2f(0.f, 0.f);

}

void Ball::init()
{
    speed = 800.f;
    direction = rand() & 2;
    if (direction == 0) {
        movement = sf::Vector2f(speed, 0.f);
    }
    else {
        movement = sf::Vector2f(-speed, 0.f);    
    }
    
    setPosition(640.f, 310.f);
}

void Ball::update(sf::RenderWindow& pWindow, sf::Time elapsed) {

    float bx = getPosition().x;
    float by = getPosition().y;
    
    sf::Vector2f p1p = pPad1->getPosition();
    sf::Vector2f p2p = pPad2->getPosition();
    
    // Fliegt der Ball gegen die horizontalen Grenzen
    if (by < 0) 
    {
        movement.y = speed;    
    } else if (by >= pWindow.getSize().y - getRadius())
    {
        movement.y = -speed;
    }
    
    // Fliegt der Ball gegen einen Schläger?
    // linker Schläger
    
    if      (getGlobalBounds().left < p1p.x + (pPad1->getSize().x / 2) && 
             getGlobalBounds().left + getGlobalBounds().width >  p1p.x - (pPad1->getSize().x / 2) &&
             getGlobalBounds().top + getGlobalBounds().height >= p1p.y - (pPad1->getSize().y / 2) &&
             getGlobalBounds().top <= p1p.y + pPad1->getSize().y/2)
    {
        setFillColor(pPad1->getFillColor());
        
        // ball oben, unten oder mitte vom Schläger eingetroffen?
        if (by < p1p.y)
        {
            movement.x = speed;
            movement.y = -speed;
        
        }
        else if (by > p1p.y)
        {
            movement.x = speed;
            movement.y = speed;
        }
        else 
        {
            movement.x = speed;        
        }
    } // rechter Schläger
    else if (getGlobalBounds().left < p2p.x + (pPad2->getSize().x / 2) && 
             getGlobalBounds().left + getGlobalBounds().width >  p2p.x - (pPad2->getSize().x / 2) &&
             getGlobalBounds().top + getGlobalBounds().height >= p2p.y - (pPad2->getSize().y / 2) &&
             getGlobalBounds().top <= p2p.y + pPad2->getSize().y/2)
    {
        setFillColor(pPad2->getFillColor());
        
        // ball oben, unten oder mitte vom Schläger eingetroffen?
        if (by < p2p.y)
        {
            movement.x = -speed;
            movement.y = -speed;
        
        }
        else if (by > p2p.y)
        {
            movement.x = -speed;
            movement.y = speed;
        }
        else 
        {
            movement.x = -speed;        
        }
    }
    
    move(movement.x * elapsed.asSeconds(), movement.y * elapsed.asSeconds());
}


