/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.h
 * Author: snbl
 *
 * Created on April 29, 2018, 12:30 PM
 */

#ifndef BALL_H
#define BALL_H

#include "Paddle.h"
#include <memory>
#include <SFML/Audio.hpp>


class Ball : public sf::CircleShape {
public:
    Ball(float rad, sf::Color col, sf::Vector2f pos, std::shared_ptr<Paddle> pad1, std::shared_ptr<Paddle> pad2);
    void init();
    void update(sf::RenderWindow& pWindow, sf::Time elapsed);

private:
    int direction;
    float speed;
    sf::Vector2f movement;
    
    sf::Texture texture;
    
    std::shared_ptr<Paddle> pPad1;
    std::shared_ptr<Paddle> pPad2;
    
    sf::SoundBuffer bClick;
    sf::Sound sClick;
    
};

#endif /* BALL_H */

