/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paddle.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 12:03 PM
 */

#include "Paddle.h"

Paddle::Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String tex) {
    setSize(rect);
    setFillColor(col);
    setOrigin(getSize().x / 2, getSize().y / 2);
    setPosition(pos);
        
    initPos = pos;
    speed = 1000.f;

    texture.loadFromFile(tex);
    texture.setSmooth(true);
    setTexture(&texture);
    setTextureRect(sf::IntRect(0,0,53,192));
    
    frame = 0;
    frames = 20;
    frameWidth = 53;
   
}

void Paddle::update(sf::RenderWindow& pWindow, sf::Time elapsed) {
    
    // Hier wird die Beschleunigung miteinbezogen
    tempElapsedTime += elapsed;
    
    if (tempElapsedTime.asSeconds() > .05)
    {
        if (frame < frames - 1)
        {
            frame++;
        }    
        else 
        {
            frame = 0;
        }
        
        tempElapsedTime = tempElapsedTime.Zero;
        setTextureRect(sf::IntRect(frameWidth * frame, 0, frameWidth, 196));
    }
    
    
    if (sf::Keyboard::isKeyPressed(up) && getPosition().y > getGlobalBounds().height / 2)
    {
        move(sf::Vector2f(0.f, -speed * elapsed.asSeconds()));    
    }
    
    else if (sf::Keyboard::isKeyPressed(down) && getPosition().y < (pWindow.getSize().y - getGlobalBounds().height / 2))
    {
        move(sf::Vector2f(0.f, speed * elapsed.asSeconds()));    
    }
    
}

void Paddle::init() {
    setPosition(initPos);
}

void Paddle::setKeyUp(sf::Keyboard::Key k) {
    up = k;
}


void Paddle::setKeyDown(sf::Keyboard::Key k) {
    down = k;
}

