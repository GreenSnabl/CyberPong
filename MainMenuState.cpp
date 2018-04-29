/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuState.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 11:06 AM
 */

#include <cstring>

#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    font.loadFromFile("./assets/font/UbuntuMono-B.ttf");
    txtStartGame.setFont(font);
    txtStartGame.setString("Spiel starten");
    txtStartGame.setCharacterSize(30);
    txtStartGame.setPosition(400.f, 500.f);
    
    txtQuitGame.setFont(font);
    txtQuitGame.setString("Spiel beenden");
    txtQuitGame.setCharacterSize(30);
    txtQuitGame.setPosition(400.f, 530.f);
}

void MainMenuState::handleEvents(Game& game) {
    sf::Event event;
    
    while (game.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            game.window.close();
            game.running = false;
        }
        
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (bStartGameSelected) {
                game.changeState(Game::gameStates::PLAY);
            }
            else if (bQuitGameSelected) {
                game.window.close();
                game.running = false;            
            }   
        }
    }
}


/* Hier werden ein paar Maus-Aktionen implementiert: Interessant!*/

void MainMenuState::update(Game& game) {
    if (txtStartGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y))
    {
        txtStartGame.setColor(sf::Color::Green);
        bStartGameSelected = true;
    }
    else if (txtQuitGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y))
    {
        txtQuitGame.setColor(sf::Color::Green);
        bQuitGameSelected = true;
    }
    else {
        txtStartGame.setColor(sf::Color::White);
        txtQuitGame.setColor(sf::Color::White);
        bStartGameSelected = false;
        bQuitGameSelected = false;
    }    
}

void MainMenuState::draw(Game& game) {
    game.window.draw(txtStartGame);
    game.window.draw(txtQuitGame);
}

MainMenuState::~MainMenuState() {
    std::cout << "~MainMenuState() wurde aufgerufen" << std::endl;
}