// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <vector>
#include <conio.h>

#include "Tetromino.h"
#include "Console.h"
#include "GameBoard.h"

using namespace std;

struct Tetrominos {
    static inline vector<vector<bool>>
    T{
        { 1, 1, 1 },
        { 0, 1, 0 },
        { 0, 0, 0 },
    },
    Q{
        { 1, 1 },
        { 1, 1 },
    },
    I{
        { 0, 1, 0 },
        { 0, 1, 0 },
        { 0, 1, 0 },
    },
    Z{
        { 1, 1, 0 },
        { 0, 1, 1 },
        { 0, 0, 0 },
    },
    S{
        { 0, 1, 1 },
        { 1, 1, 0 },
        { 0, 0, 0 },
    },
    O{
        { 1 },
    },
    J{
        { 0, 1, 0 },
        { 0, 1, 0 },
        { 1, 1, 0 },
    },
    L{
        { 0, 1, 0 },
        { 0, 1, 0 },
        { 0, 1, 1 },
    },
    X{
        { 0, 1, 0 },
        { 1, 1, 1 },
        { 0, 1, 0 },
    },
    U{
        { 0, 0, 0 },
        { 1, 0, 1 },
        { 1, 1, 1 },
    };
};


void run() {
    system("cls");
    vector<vector<vector<bool>>> figures = {
       Tetrominos::T,
       Tetrominos::Q,
       Tetrominos::I,
       Tetrominos::Z,
       Tetrominos::S,
       Tetrominos::O,
       Tetrominos::J,
       Tetrominos::L,
       Tetrominos::X,
       Tetrominos::U,
    };
    srand(time(0));
    COORD coord;
    while (true) {
        coord.X = 0;
        coord.Y = 0;
        Tetromino figure = Tetromino(figures[rand() % figures.size()], coord);
        while (figure.isFallen() != true) {
            figure.process_logic();
            figure.fall(GameBoard::field);
            figure.process_draw(GameBoard::field);
            GameBoard::draw();
            Sleep(125);
        }
    }
}

int main()
{
    Console::setup();
    run();
    return 0;
}