/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuState.h
 * Author: snbl
 *
 * Created on April 29, 2018, 11:06 AM
 */

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "Game.h"

class MainMenuState : public GameState {
public:
    MainMenuState();
    ~MainMenuState();

    void handleEvents(Game& game);
    void update(Game& game);
    void draw(Game& game);
    
    private:
        bool bStartGameSelected;
        bool bQuitGameSelected;
        sf::Font font;
        sf::Text txtStartGame;
        sf::Text txtQuitGame;
    
};

#endif /* MAINMENUSTATE_H */

