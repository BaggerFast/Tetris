// tetris.cpp : This file contains the "main" function. This is where program execution begins and ends

#include "MainScene.h"
#include "Console.h"
#include "MenuScene.h"


int main()
{
    Console::setup();
    MenuScene menu = MenuScene(10, 20, 0, 3);
    menu.run();
    return 0;
}