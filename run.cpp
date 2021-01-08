#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <cctype>
#include <ctime>
#include <vector>

using namespace std;

//prototype
void subject_fallen();
void game_start();
int main();

//global variables
vector<vector<int>> field(20, vector<int>(10));
vector<vector<char>>arr(20, vector<char>(10));

//structures
struct Game {
    static inline int speed = 120,score = 0, x = 1, y = 1, rotate = 0;
    static inline bool exits = false;
};

struct Keyboard
{
    const static inline vector<char> w = {'w'},a = {'a'},s = {'s'}, d = {'d'},space = {' '};
    static bool check_key(vector<char>keys, char key_code){
        for(int i = 0; i < keys.size(); ++i)
            if (keys[i] == tolower(key_code))
                return true;
        return false;
    }
};

struct Object
{
    static const char block = char(254),pole_block = char(219),cursor = char(248),space = char(255);
};

struct Tag {
    static const char space = ' ', t_title = '1',e_title = '2',twinkle = '3';
    static const int empty= 0, cur_pos = 1, fallen = 2 , t = 6, e = 4;
};

class Surface {
private:
    static inline COORD cord;
public:
    static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    static void off_cursor() {
        CONSOLE_CURSOR_INFO structCurInf;
        GetConsoleCursorInfo(console, &structCurInf);
        structCurInf.bVisible = false;
        SetConsoleCursorInfo(console, &structCurInf);
    }

    static void flash(int count) {
        for (int i = 0; i < count; i++) {
            system("color 20");
            Sleep(100);
            system("color 02");
            Sleep(100);
        }
    }

    static void cursor_pos(int cord_x, int cord_y) {
        cord.X = cord_x;
        cord.Y = cord_y;
        SetConsoleCursorPosition(console, cord);
    }

    static void font_size(){
        CONSOLE_FONT_INFOEX text;
        text.cbSize = sizeof(text);
        text.dwFontSize.Y = 36;
        std::wcscpy(text.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &text);
    }
};

struct Color {
    enum ConsoleColor {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Brown = 6,
        LightGray = 7,
        DarkGray = 8,
        LightBlue = 9,
        LightGreen = 10,
        LightCyan = 11,
        LightRed = 12,
        LightMagenta = 13,
        Yellow = 14,
        White = 15
    };
    static inline int random = 0, last = 0;
    static void change(int color) {
        SetConsoleTextAttribute(Surface::console, color);
    }
    static void randomize() {
        random = 1 + rand()%15;
    }
};

//classes
class Tetromino {
    vector<vector<vector<int>>> it;
    vector<vector<int>> rot_map;
public:
    void update(vector<vector<vector<int>>> it, vector<vector<int>> rot_map){
        this->it = it;
        this->rot_map = rot_map;
    }
    vector<vector<int>> get_rot_map(){return rot_map;}
    vector<vector<vector<int>>> get_it(){return it;}

    bool reload(int cord_x, int rot) {
    if (cord_x != -1 && cord_x + it[rot][0].size() != field[0].size() + 1) {
        subject_fallen();
        Game::exits = true;
    }
        return false;
    }

     bool push_check(int rot ,int cord_x, int cord_y){
            int count = 0;
            try {
                int i = cord_y, j = 0;
                for (int _y = 0; _y < it[rot].size(); ++_y) {
                    j = cord_x;
                    for (int _x = 0; _x < it[rot][_y].size(); ++_x) {
                        if (it[rot].at(_y).at(_x) == Tag::cur_pos && field.at(i).at(j) == Tag::fallen){
                            if ((cord_x - 1 == Game::x || cord_x + 1 == Game::x))
                                return false;
                            else return reload(cord_x, rot);
                        }
                        j++;
                    }
                    i++;
                }
            } catch (out_of_range) {
                return reload(cord_x, rot);
            }
            return true;
        }

     void push(int rot, int cord_x, int cord_y) {
            int i = cord_y, j = 0;
            for (int _y = 0; _y < it[rot].size(); ++_y) {
                j = cord_x;
                for (int _x = 0; _x < it[rot][_y].size(); ++_x) {
                    if (it[rot][_y][_x] == Tag::cur_pos && field[i][j] == Tag::empty)
                        field[i][j] = it[rot][_y][_x];
                    j++;
                }
                i++;
            }
        }
};

class Square:public Tetromino {
public:
    Square(){
        vector<vector<vector<int>>> it = {{{Tag::cur_pos,   Tag::cur_pos},
                                                  {Tag::cur_pos,   Tag::cur_pos}}};
        vector<vector<int>> rot_map = {{0,0}};
        update(it, rot_map);
    }
};

class Point:public Tetromino {
public:
    Point(){
        vector<vector<vector<int>>> it = {{{Tag::cur_pos}}};
        vector<vector<int>> rot_map = {{0,0}};
        update(it, rot_map);
    }
};

class Stick:public Tetromino{
public:
    Stick() {
        vector<vector<vector<int>>> it = {{{Tag::cur_pos},
                                           {Tag::cur_pos},
                                           {Tag::cur_pos}},
                                          {{Tag::cur_pos,   Tag::cur_pos,   Tag::cur_pos}}};
        vector<vector<int>> rot_map = {
                {-1,1},
                {1,-1}
        };
        update(it, rot_map);
    }
    };

class Angle:public Tetromino{
public:
    vector<vector<vector<int>>> it;
    Angle() {
        it = {{{Tag::cur_pos, Tag::cur_pos},
              {Tag::empty,   Tag::cur_pos}},

              {{Tag::cur_pos, Tag::cur_pos},
               {Tag::cur_pos, Tag::empty}},

               {{Tag::cur_pos, Tag::empty},
                {Tag::cur_pos, Tag::cur_pos}},

                {{Tag::empty,   Tag::cur_pos},
                 {Tag::cur_pos, Tag::cur_pos}}};
        vector<vector<int>> rot_map = {
                {0,0},
                {0,0},
                {0,0},
                {0,0}};

        update(it, rot_map);
    }
};

class Tank:public Tetromino{
public :
vector<vector<vector<int>>> it;
    Tank(){
       it = {{{Tag::empty,    Tag::cur_pos, Tag::empty},
              {Tag::cur_pos,  Tag::cur_pos, Tag::cur_pos}},

             {{Tag::empty,    Tag::cur_pos},
              {Tag::cur_pos,  Tag::cur_pos},
              {Tag::empty,    Tag::cur_pos}},

               {{Tag::cur_pos,  Tag::cur_pos,   Tag::cur_pos},
                {Tag::empty,    Tag::cur_pos,   Tag::empty}},

                {{Tag::cur_pos,  Tag::empty},
                 {Tag::cur_pos,  Tag::cur_pos},
                 {Tag::cur_pos,  Tag::empty}}};

        vector<vector<int>> rot_map = {
                {0,0},
                {0,1},
                {1,-1},
                {-1,-1}};

        update(it, rot_map);
}
};


//functions
void draw_hud() {
    Color::change(Color::Yellow);
    Surface::cursor_pos(1, 0);
    cout << "Score: " << Game::score;
    Surface::cursor_pos(1, 1);
    cout << "Speed: " << Game::score/3+1;
    Color::change(Color::Green);
}

template<typename T>
void array_fill(vector<vector<T>> &array, T pass) {
    for(int i = 0; i < array.size(); ++i)
        for (int j = 0; j < array[i].size(); ++j)
            array[i][j] = pass;
}

void draw_head_footer() {
    for (int i = 0; i <= field.size() + 1; ++i)
        cout << Object::pole_block;
    cout << endl;
}

void remove_item(int tag_1, int tag_2){
    for (int i = 0; i < field.size(); ++i)
        for (int j = 0; j < field[i].size(); ++j)
            field[i][j] = (field[i][j] == tag_1) ? tag_2:field[i][j];
}

void subject_fallen() {
    remove_item(Tag::cur_pos, Tag::fallen);
    Color::last = Color::random;
}

template<typename T>
void setting_item(T item) {
    Game::y = 0;
    Game::rotate = rand() % item.size();
    Game::x = rand() % item[Game::rotate][0].size();

}

void draw_point(int point) {
    switch (point) {
        case Tag::empty:    cout << Object::space; break;
        case Tag::cur_pos:  Color::change(Color::random); break;
        case Tag::fallen:   Color::change(Color::last); break;
    }
    if (point != Tag::empty)
        cout << Object::block;
    Color::change(Color::Green);
    cout << Object::space;
}

void draw_field() {
    draw_hud();
    Surface::cursor_pos(0, 3);
    draw_head_footer();
    for (int i = 0; i < field.size(); ++i) {
        cout << Object::pole_block;
        for (int j = 0; j < field[i].size(); ++j)
            draw_point(field[i][j]);
        cout << Object::pole_block << endl;
    }
    draw_head_footer();
}

void line_down(int line) {
    Sleep(50);
    for (int i = line; i > 0; --i)
        for (int j = 0; j < field[i].size(); j++) {
            field[i][j] = field[i - 1][j];
            field[i - 1][j] = Tag::empty;
        }
    Game::score++;
        Game::speed = (Game::score % 3) ? Game::speed-5: Game::speed;
    draw_hud();

}

void line_delete() {
    for (int i = field.size() - 1; i > 0; --i) {
        int count = 0;
        for (int j = 0; j < field[i].size(); ++j) {
            count += field[i][j];
            if (count == field[i].size()*Tag::fallen) {
                for (int k = 0; k < field[i].size(); ++k)
                    field[i][k] = Tag::empty;
                line_down(i);
            }
        }
    }
}
template<typename T>
void process_fall(T s){
    if(s.push_check(Game::rotate, Game::x,(Game::y+1))) {
        Game::y++;
        remove_item(Tag::cur_pos, Tag::empty);
    }
}
template<typename T>
void keyboard(T item) {
    if (kbhit()) {
        char key = getch();
        if (Keyboard::check_key(Keyboard::a, key)) {
            if (item.push_check(Game::rotate, Game::x - 1, Game::y))
                Game::x--;
        } else if (Keyboard::check_key(Keyboard::d, key)) {
            if (item.push_check(Game::rotate, Game::x + 1, Game::y))
                Game::x++;
        }
        else if (Keyboard::check_key(Keyboard::space, key)) {
            int last_rotate = Game::rotate;
            Game::rotate = (Game::rotate + 1 == item.get_rot_map().size()) ? -1 : Game::rotate;
            remove_item(Tag::cur_pos, Tag::empty);
            if (item.push_check(Game::rotate + 1, Game::x + item.get_rot_map()[last_rotate][0], Game::y + item.get_rot_map()[last_rotate][1])) {
                Game::x += item.get_rot_map()[last_rotate][0];
                Game::y += item.get_rot_map()[last_rotate][1];
                Game::rotate += 1;
            }
            Game::rotate = (Game::rotate < 0) ? 0 : Game::rotate;
        }
        else if (Keyboard::check_key(Keyboard::s, key))
            process_fall(item);
    }
}

bool game_over() {
    int count = 0;
    for (int j = 0; j < field[0].size(); ++j)
        count += field[0][j];
    return count == 0;
}

void draw_control(){
    string names[5] = {"CONTROL","a - left","d - right","s - down","space - rotate"};
    int _y = 4;
    Color::change(Color::White);
    for (int i = 0; i < 5; ++i){
        Surface::cursor_pos(23, _y);
        cout << names[i];
        _y++;
    }
}

class Base_scene{
private:
    bool exit = false;
public:
    int cur_y = 7;
    int cur_x = 1;
    void print_word(string word, int cord_x, int cord_y) {
        for (int i = 0; i < word.length(); ++i)
            arr[cord_y][cord_x+i] = word[i];
    }
    bool array_compare(int start, int end, int var) {
        for (int i = start; i <= end; ++i)
            if (var == i)
                return true;
        return false;
    }
    void draw_block(int colors, char block) {
        Color::change(colors);
        cout << block << " ";
    }
    void keyboard_control() {
        if (kbhit()) {
            char key = getch();
            if (Keyboard::check_key(Keyboard::w, key)) {
                if (cur_y > 7) {
                    arr[cur_y][cur_x] = Tag::space;
                    cur_y -= 2;
                }
            }
            else if (Keyboard::check_key(Keyboard::s, key)) {
                if (cur_y < 8) {
                    arr[cur_y][cur_x] = Tag::space;
                    cur_y += 2;
                }
            }
            else if (Keyboard::check_key(Keyboard::space, key)) {
                if (cur_y == 7)
                    game_start();
                else if (cur_y == 9)
                    this->exit = true;
            }
        }
    }
    virtual void fill() = 0;
    virtual void objects(char tag) = 0;
    virtual void draw_control() = 0;
    int start() {
        array_fill(arr, Tag::space);
        while (!this->exit) {
            draw_control();
            Color::change(Color::Green);
            Surface::cursor_pos(0, 1);
            draw_head_footer();
            fill();
            for (int i = 0; i < field.size(); ++i) {
                cout << Object::pole_block;
                for (int j = 0; j < field[i].size(); ++j){
                    arr[cur_y][cur_x] = Object::cursor;
                    objects(arr[i][j]);
                }
                cout << Object::pole_block << endl;
            }
            draw_head_footer();
            keyboard_control();
            Sleep(150);
        }
        return 0;
    }
};

class Menu: public Base_scene{
    void draw_on_field(int x,int x_size, int y,int y_size, char pass) {
        for (int i = y; i <= y_size; ++i)
            for(int j = x; j <= x_size; ++j)
                arr[i][j] = pass;
    }
    void draw_stairs(int x, int y, char pass) {
        for (int i = y; i < 20; ++i) {
            for (int j = 0; j < x + 1; ++j) {
                arr[i][j] = pass;
            }
            x = x + 1;
        }
    }
    void fill() override {
        print_word("START", 2, 7);
        print_word("EXIT", 2, 9);
        //T
        draw_on_field(0,2,1,1,Tag::t_title);
        draw_on_field(1,1,2,5,Tag::t_title);
        draw_on_field(7,9,1,1,Tag::t_title);
        draw_on_field(8,8,2,5,Tag::t_title);
        //е
        draw_on_field(4,4,1,5,Tag::e_title);
        draw_on_field(4,5,1,1,Tag::e_title);
        draw_on_field(4,5,3,3,Tag::e_title);
        draw_on_field(4,5,5,5,Tag::e_title);

        draw_stairs(0,10,Tag::twinkle);
    };
    void objects(char tag) override  {
        int index = int(tag) - 48;
        Color::randomize();
        int item_settings[][2] = {{Color::Cyan, Object::block}, {Color::LightBlue, Tag::t}, {Color::Red, Tag::e}, {Color::random, Object::block}};
        if (array_compare(0, 3, index))
            draw_block(item_settings[index][0], item_settings[index][1]);
        else draw_block(Color::White, tag);
        Color::change(Color::Green);
    }
    void draw_control() override {
        string names[4] = {"CONTROL","w - up", "s - down", "space - choice"};
        int _y = 4;
        Color::change(Color::White);
        for (int i = 0; i < 4; ++i){
            Surface::cursor_pos(24, _y);
            cout << names[i];
            _y++;
        }
    }
};

void game_start() {
    system("cls");
    Game::speed = 120;
    Game::score = 0;
    draw_control();
    array_fill(field, Tag::empty);
    do{
        Color::change(Color::Green);
        vector<Tetromino*>items = {new Point, new Square, new Stick, new Angle, new Tank};
        Color::randomize();
        Tetromino item = *items[rand() % items.size()];
        setting_item(item.get_it());
        while(!Game::exits) {
            keyboard(item);
            item.push(Game::rotate,Game::x,Game::y);
            draw_field();
            process_fall(item);
            line_delete();
            Sleep(Game::speed);
        }
        Game::exits = false;
    }while(game_over());
    Sleep(2000);
    Surface::flash(3);
    system("cls");
    Menu menu;
    menu.start();
}

int main(){
    SetConsoleCP(1251);
    Surface::off_cursor();
    Surface::font_size();
    system("mode con cols=40 lines=27");
    srand(time(NULL));
    Menu menu;
    menu.start();
    return 0;
}

