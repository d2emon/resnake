#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

sf::String gameTitle = "Rerkanoid";
int winSize[2] = {800, 600};

const int M = 450;
const int N = 520;
int boxSize[2] = {N, M};
int fps = 60;

int backgroundsCount = 10;
sf::String backgrounds[10] = {
    "res/background/1.png",
    "res/background/2.png",
    "res/background/3.png",
    "res/background/4.png",
    "res/background/5.png",
    "res/background/6.png",
    "res/background/7.png",
    "res/background/8.png",
    "res/background/9.png",
    "res/background/10.png",
};

// int blocksCount = 1000;
// int blockCols = 10;
// int blockRows = 10;
// int blockW = 43;
// int blockH = 20;
// int posNowhere[2] = {-100, 0};
sf::String blocks[5] = {
    "res/block01.png",
    "res/block02.png",
    "res/block03.png",
    "res/block04.png",
    "res/block05.png",
};

// int ballPos[2] = {300, 300};
// int ballSpeed[2] = {6, 5};
// int paddlePos[2] = {300, 440};

// sf::String ball = "res/ball.png";
// sf::String paddle = "res/paddle.png";

#endif // SETTINGS_HPP_INCLUDED
