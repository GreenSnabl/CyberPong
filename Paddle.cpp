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

Paddle::Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos) {
    setSize(rect);
    setFillColor(col);
    setOrigin(getSize().x / 2, getSize().y / 2);
    setPosition(pos);
    
    initPos = pos;
    speed = 1000.f;
}

void Paddle::update(sf::RenderWindow& pWindow, sf::Time elapsed) {
    
    // Hier wird die Beschleunigung miteinbezogen
    // tempElapsedTime += elapsed;
    
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

