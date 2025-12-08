//
// Created by 58413 on 2025/12/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 20

// 当前方块结构
typedef struct {
    int shape[4][4]; // 4x4 方块模板
    int x, y;         // 当前方块位置
} Tetromino;
int map[HEIGHT][WIDTH] = {0};
int tetrominoes[7][4][4] = {
    {{0,0,0,0},
     {1,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},

    {{1,1,0,0},
     {1,1,0,0},
     {0,0,0,0},
     {0,0,0,0}},

    {{0,1,0,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},

    {{0,0,1,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},

    {{1,0,0,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},

    {{0,1,1,0},
     {1,1,0,0},
     {0,0,0,0},
     {0,0,0,0}},

    {{1,1,0,0},
     {0,1,1,0},
     {0,0,0,0},
     {0,0,0,0}}
};

// 清屏
void clearScreen() {
    system("cls");
}

// 设置光标位置
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 显示游戏
void drawGame(Tetromino *t) {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int isBlock = 0;

            // 检查当前位置是否是当前方块
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    if (t->shape[r][c] && t->x + r == i && t->y + c == j)
                        isBlock = 1;
                }
            }

            if (map[i][j])
                printf("⬛");
            else if (isBlock)
                printf("🟦");
            else
                printf("⬜");
        }
        printf("\n");
    }
}

// 检测碰撞
int checkCollision(Tetromino *t, int newX, int newY) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (t->shape[r][c]) {
                int x = newX + r;
                int y = newY + c;
                if (x >= HEIGHT || y < 0 || y >= WIDTH || (x >= 0 && map[x][y]))
                    return 1;
            }
        }
    }
    return 0;
}

// 固定
void fixToMap(Tetromino *t) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (t->shape[r][c]) {
                int x = t->x + r;
                int y = t->y + c;
                if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
                    map[x][y] = 1;
            }
        }
    }
}

// 消除
void clearLines() {
    for (int i = HEIGHT - 1; i >= 0; i--) {
        int full = 1;
        for (int j = 0; j < WIDTH; j++) {
            if (!map[i][j]) {
                full = 0;
                break;
            }
        }
        if (full) {
            for (int k = i; k > 0; k--)
                memcpy(map[k], map[k - 1], sizeof(map[0]));
            memset(map[0], 0, sizeof(map[0]));
            i++;
        }
    }
}

// 旋转
void rotate(int a[4][4]) {
    int temp[4][4];
    memcpy(temp, a, sizeof(temp));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = temp[3 - j][i];
}

//游戏推进
void gameLoop() {
    Tetromino current;
    memcpy(current.shape, tetrominoes[rand() % 7], sizeof(current.shape));
    current.x = 0;
    current.y = 3;

    while (1) {
        drawGame(&current);

        // 检测是否触底
        if (checkCollision(&current, current.x + 1, current.y)) {
            fixToMap(&current);
            clearLines();
            memcpy(current.shape, tetrominoes[rand() % 7], sizeof(current.shape));
            current.x = 0;
            current.y = 3;
            if (checkCollision(&current, current.x, current.y)) {
                drawGame(&current);
                printf("结束！\n");
                break;
            }
        } else {
            if (_kbhit()) {
                char ch = _getch();
                if (ch == 'a' && !checkCollision(&current, current.x, current.y - 1))
                    current.y--;
                else if (ch == 'd' && !checkCollision(&current, current.x, current.y + 1))
                    current.y++;
                else if (ch == 's' && !checkCollision(&current, current.x + 1, current.y))
                    current.x++;
                else if (ch == 'w') {
                    int temp[4][4];
                    memcpy(temp, current.shape, sizeof(temp));
                    rotate(current.shape);
                    if (checkCollision(&current, current.x, current.y)) {
                        memcpy(current.shape, temp, sizeof(temp)); // 回退
                    }
                }
            }
            current.x++;
        }

        Sleep(500);
    }
}

int main() {
    system("chcp 65001");
    srand((unsigned int)time(NULL));
    gameLoop();
    return 0;
}
