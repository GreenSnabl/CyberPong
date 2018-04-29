/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayState.h
 * Author: snbl
 *
 * Created on April 29, 2018, 11:43 AM
 */

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"


class PlayState : public GameState {
public:
    PlayState();
    ~PlayState();
    void handleEvents(Game& game);
    void update(Game& game);
    void draw(Game& game);

    
private:
    std::unique_ptr<Ball> upBall;
    std::shared_ptr<Paddle> spPad1;
    std::shared_ptr<Paddle> spPad2;
    
    sf::Font font;
    sf::Text txtPointsLeft;
    sf::Text txtPointsRight;
    sf::Texture tBackground;
    sf::Sprite sBackground;
    
    
    int pointsLeft;
    int pointsRight;
    
    sf::SoundBuffer bLose;
    sf::Sound sLose;
    
};

#endif /* PLAYSTATE_H */

