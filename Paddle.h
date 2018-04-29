/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paddle.h
 * Author: snbl
 *
 * Created on April 29, 2018, 12:03 PM
 */

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle : public sf::RectangleShape {
public:
    Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String tex);
    void update(sf::RenderWindow& pWindow, sf::Time elapsed);
    void init();
    void setKeyUp(sf::Keyboard::Key k);
    void setKeyDown(sf::Keyboard::Key k);

private:
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Vector2f initPos;
    sf::Time tempElapsedTime;
    sf::Texture texture;
    
    
    float speed;
    int frame;
    int frames;
    int frameWidth;
};

#endif /* PADDLE_H */

