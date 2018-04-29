/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayState.cpp
 * Author: snbl
 * 
 * Created on April 29, 2018, 11:43 AM
 */

#include "PlayState.h"

PlayState::PlayState() : GameState() {
    spPad1 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::White, sf::Vector2f(30.f, 310.f), "./assets/gfx/BLUE/sheet2.png");
    spPad2 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::White, sf::Vector2f(1250.f, 310.f), "./assets/gfx/RED/sheet2.png");
    upBall = std::unique_ptr<Ball>(new Ball(20.f, sf::Color::White, sf::Vector2f(640.f, 310.f), spPad1, spPad2));

    tBackground.loadFromFile("./assets/gfx/background2.png");
    tBackground.setSmooth(true);
    sBackground.setTexture(tBackground);

    font.loadFromFile("./assets/font/UbuntuMono-B.ttf");
    txtPointsLeft.setFont(font);
    txtPointsLeft.setCharacterSize(50);
    txtPointsLeft.setString("0");
    txtPointsLeft.setPosition(500.f, 10.f);

    txtPointsRight.setFont(font);
    txtPointsRight.setCharacterSize(50);
    txtPointsRight.setString("0");
    txtPointsRight.setPosition(700.f, 10.f);


    spPad1->setKeyUp(sf::Keyboard::Key::Up);
    spPad1->setKeyDown(sf::Keyboard::Key::Down);
    spPad2->setKeyUp(sf::Keyboard::Key::W);
    spPad2->setKeyDown(sf::Keyboard::Key::S);

    pointsLeft = 0;
    pointsRight = 0;


    bLose.loadFromFile("./assets/snd/Pong_schnuzzel.wav");
    sLose.setBuffer(bLose);


}

void PlayState::handleEvents(Game& game) {

    sf::Event event;

    while (game.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.window.close();
            game.running = false;
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Space) {
                upBall->init();
            }
        }
    }
}

void PlayState::update(Game& game) {

    upBall->update(game.window, game.frameDeltaTime);
    spPad1->update(game.window, game.frameDeltaTime);
    spPad2->update(game.window, game.frameDeltaTime);

    if (upBall->getPosition().x < 0) {
        sLose.play();
        ++pointsRight;
        upBall->init();

    }
    else if (upBall->getPosition().x > game.window.getSize().x) {
        sLose.play();
        ++pointsLeft;
        upBall->init();
    }

    txtPointsLeft.setString(game.numberToString(pointsLeft));
    txtPointsRight.setString(game.numberToString(pointsRight));
}

void PlayState::draw(Game& game) {

    game.window.draw(sBackground);
    game.window.draw(*upBall);
    game.window.draw(*spPad1);
    game.window.draw(*spPad2);
    game.window.draw(txtPointsLeft);
    game.window.draw(txtPointsRight);

}

PlayState::~PlayState() {
    std::cout << "~PlayState() wurde aufgerufen" << std::endl;
}