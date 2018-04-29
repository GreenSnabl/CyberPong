/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: snbl
 *
 * Created on April 29, 2018, 10:54 AM
 */

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "GameState.h"
#include "MainMenuState.h"
#include "PlayState.h"

#include "Sound.h"

class Game {
public:
    Game();
    ~Game();

    enum class gameStates {MAINMENU, PLAY};
    
    void run();
    bool isRunning();
    
    void changeState(gameStates newState);
    std::string numberToString(int num);
    
    
    bool running;
    sf::RenderWindow window;

    sf::Clock clock;
    sf::Time then = clock.getElapsedTime();
    sf::Time now;
    sf::Time frameDeltaTime;

    Sound* getSound();
    
private:
    std::unique_ptr<GameState> currentState;
    Sound* sound;

};

#endif /* GAME_H */

