// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "MainScene.h"
#include "Console.h"


int main()
{
    Console::setup();
    MainScene main = MainScene(15, 20);
    main.processLogic();
    return 0;
}