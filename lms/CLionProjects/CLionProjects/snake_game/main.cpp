#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

char map[] = "#################################################\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#                                               #\n"
             "#################################################\n";

const int WIDTH = 50;
const int HEIGHT = 20;
const int MAX_SNAKE_SIZE = (WIDTH - 3) * (HEIGHT - 2);
bool is_active = true;
int snake_pos_x[MAX_SNAKE_SIZE] = {0};
int snake_pos_y[MAX_SNAKE_SIZE] = {0};
int snake_length = 1;
char snake = 'o';
int fps = 1;
const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;
int snake_dir = UP;
int food_pos_x;
int food_pos_y;
char food = '*';

void generate_food() {
    srand(time(nullptr));
    food_pos_x = rand() % (WIDTH - 3) + 1;   // Генерируется число от 1 до WIDTH - 3
    food_pos_y = rand() % (HEIGHT - 2) + 1;  // Генерируется число от 1 до HEIGHT - 2
}

int main() {
    snake_pos_x[0] = WIDTH / 2;
    snake_pos_y[0] = HEIGHT / 2;
    int time = clock();
    generate_food();
    while (is_active) {
        if (_kbhit()) {
            int ch = _getch(); // Считывание клавиши

            if (ch == 224) { // Если была нажата специальная клавиша (стрелка или другая)
                int arrow = _getch(); // Считываем следующий символ для определения направления

                switch (arrow) {
                    case 72:  // стрелка вверх
                        if (snake_dir == DOWN) {
                            system("cls");
                            cout << "Game over" << endl;
                            is_active = false;
                            break;
                        } else {
                            snake_dir = UP;
                        }
                    case 75:  // стрелка влево
                        if (snake_dir == LEFT) {
                            system("cls");
                            cout << "Game over" << endl;
                            is_active = false;
                            break;
                        } else {
                            snake_dir = RIGHT;
                        }
                    case 80:  // стрелка вниз
                        if (snake_dir == UP) {
                            system("cls");
                            cout << "Game over" << endl;
                            is_active = false;
                            break;
                        } else {
                            snake_dir = DOWN;
                        }
                    case 77:  // стрелка вправо
                        if (snake_dir == LEFT) {
                            system("cls");
                            cout << "Game over" << endl;
                            is_active = false;
                            break;
                        } else {
                            snake_dir = RIGHT;
                        }
                }
            } else {
                switch (ch) {
                    case 'w':
                    case 'W':
                        snake_dir = UP;
                        break;
                    case 'a':
                    case 'A':
                        snake_dir = LEFT;
                        break;
                    case 's':
                    case 'S':
                        snake_dir = DOWN;
                        break;
                    case 'd':
                    case 'D':
                        snake_dir = RIGHT;
                        break;
                    case 'q':  // Дополнительная клавиша для выхода
                    case 'Q':
                        system("cls");
                        cout << "Game over" << endl;
                        is_active = false;
                        break;
                }
            }
        }
        if ((clock() - time) / CLOCKS_PER_SEC >= 1 / fps) {
            time = clock();
            system("cls");
            for (int i = snake_length; i != 0; i--) {
                snake_pos_y[i] = snake_pos_y[i - 1];
                snake_pos_x[i] = snake_pos_x[i - 1];
            }
            if (snake_dir == UP) {
                snake_pos_y[0]--;
            }
            if (snake_dir == LEFT) {
                snake_pos_x[0]--;
            }
            if (snake_dir == DOWN) {
                snake_pos_y[0]++;
            }
            if (snake_dir == RIGHT) {
                snake_pos_x[0]++;
            }
            if (snake_pos_x[0] == 0 || snake_pos_x[0] == WIDTH - 2 || snake_pos_y[0] == 0 ||
                snake_pos_y[0] == HEIGHT - 1) {
                system("cls");
                cout << "Game over" << endl;
                is_active = false;
                break;
            }
            if (snake_pos_x[0] == food_pos_x && snake_pos_y[0] == food_pos_y) {
                generate_food();
                snake_length++;
            }
            for (int i = 0; i < snake_length; i++) {
                map[snake_pos_y[i] * WIDTH + snake_pos_x[i]] = snake;
            }
            map[food_pos_y * WIDTH + food_pos_x] = food;
            cout << map;
            for (int i = 0; i < snake_length; i++) {
                map[snake_pos_y[i] * WIDTH + snake_pos_x[i]] = ' ';
            }
            for (int i = 1; i < snake_length; i++) {
                if (snake_pos_x[i] == snake_pos_x[0] && snake_pos_y[i] == snake_pos_y[0]) {
                    system("cls");
                    cout << "Game over" << endl;
                    is_active = false;
                    break;
                }
            }
        }
    }

    return 0;
}