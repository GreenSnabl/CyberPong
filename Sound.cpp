/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sound.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 2:20 PM
 */

#include "Sound.h"

void Sound::loadBuffer(std::string name)
{
    sbuff->loadFromFile(name);
}

void Sound::playSound()
{
    sf::Sound snd;
    snd.setBuffer(*sbuff);
    snd.play();
}