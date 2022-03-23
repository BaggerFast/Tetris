// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>

#include "Tetromino.h"
#include "Сonsole.h"

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

struct Block {
    static const char
        BLOCK = char(254),
        FIELD_BLOCK = char(219),
        SPACE = char(255);
};

void draw_head_footer(vector<vector<int>> field) {
    for (int i = 0; i <= field.size(); ++i)
        cout << char(219);
    cout << endl;
}

void draw_point(int point) {
    switch (point) {
    case 0: cout << Block::SPACE; break;
    case 1: cout << Block::BLOCK; break;
    }
    cout << Block::SPACE;
}

void draw_field(vector<vector<int>> field) {
    Console::setCursorPos(0, 0);

    draw_head_footer(field);
    for (int i = 0; i < field.size(); ++i) {
        cout << char(219);
        for (int j = 0; j < field[i].size(); ++j)
            draw_point(field[i][j]);
        cout << '\b';
        cout << char(219) << endl;
    }
    draw_head_footer(field);
}

void run() {
    system("cls");
    vector<vector<int>> field(20, vector<int>(10, 0));
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
    coord.X = 0;
    coord.Y = 0;
    Tetromino figure = Tetromino(figures[rand() % figures.size()], coord);
    while (true) {
        figure.process_logic();
        figure.fall(field);
        figure.process_draw(field);
        draw_field(field);
        Sleep(1000);
    }
}

int main()
{
    Console::setup();
    run();
    return 0;
}