/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 10:54 AM
 */

#include "Game.h"

Game::Game() : running{true} , sound{new Sound}
{
    window.create(sf::VideoMode(1280,720), "CyberPong");
}

void Game::run() {
    
    
    while (window.isOpen())
    {
        now = clock.getElapsedTime();
        frameDeltaTime = (now - then);
        then = now;
        
        currentState->handleEvents(*this);
        
        window.clear(sf::Color(0, 134, 194));
        
        currentState->update(*this);
        currentState->draw(*this);
        
        window.display();
    }
}


bool Game::isRunning() {
    return running;
}

void Game::changeState(gameStates newState)
{
    switch(newState) {
        case gameStates::MAINMENU   :
            currentState = std::move(std::unique_ptr<MainMenuState>(new MainMenuState));
            break;
        case gameStates::PLAY       :      
            currentState = std::move(std::unique_ptr<PlayState>(new PlayState));
            break;
    }
}

std::string Game::numberToString(int num)
{
    return std::to_string(num);
}

Game::~Game() {
    delete sound;
}

