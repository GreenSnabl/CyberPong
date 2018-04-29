/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on April 29, 2018, 10:47 AM
 */

#include <SFML/Graphics.hpp>
#include "Game.h"

#include <SFML/Audio.hpp>

int main(int argc, char** argv) {

    Game cyberPong;
    cyberPong.changeState(Game::gameStates::MAINMENU);
    
    while (cyberPong.isRunning()) {
        cyberPong.run();
    }

    return 0;
}

