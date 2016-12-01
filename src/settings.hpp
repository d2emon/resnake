#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

sf::String gameTitle = "Snake game";
int winSize[2] = {800, 600};

const int M = 20;
const int N = 30;
const int blockSize = 16;
int boxSize[2] = {N * blockSize, M * blockSize};
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
sf::String blocks[2] = {
    "res/white.png",
    "res/red.png",
};

// int ballPos[2] = {300, 300};
// int ballSpeed[2] = {6, 5};
// int paddlePos[2] = {300, 440};

// sf::String ball = "res/ball.png";
// sf::String paddle = "res/paddle.png";

#endif // SETTINGS_HPP_INCLUDED
