// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

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