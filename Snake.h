#pragma once
#include <SFML/Graphics.hpp>

extern int direction;
extern bool game;

extern const int width;
extern const int height;
extern int square;

extern int number;

static struct Snake {
	int x, y;
};

static struct Target {
	int x, y;
};

extern Snake snake[600];
extern Target target;

void Game();