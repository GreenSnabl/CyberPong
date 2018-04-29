/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameState.h
 * Author: snbl
 *
 * Created on April 29, 2018, 11:03 AM
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

class GameState {
public:
    virtual void handleEvents(Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(Game& game) = 0;
    virtual      ~GameState();



};

#endif /* GAMESTATE_H */

