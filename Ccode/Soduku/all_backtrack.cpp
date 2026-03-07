//
// Created by 58413 on 2026/3/6.
//
#include <stdio.h>
#define SIZE 9
int space = 0;
int blanks[81][2];

int hefa(int map[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (map[row][x] == num) return 0;
    }

    for (int y = 0; y < SIZE; y++) {
        if (map[y][col] == num) return 0;
    }


    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int y = box_row; y < box_row + 3; y++) {
        for (int x = box_col; x < box_col + 3; x++) {
            if (map[y][x] == num) return 0;
        }
    }

    return 1;
}
int backtrack(int step, int map[SIZE][SIZE]) {
    if (step == space) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%3d", map[i][j]);
            }
            printf("\n");
        }
        return 1;
    }
    int row = blanks[step][0];
    int col = blanks[step][1];
    for (int num = 1; num <= SIZE; num++) {
        if (hefa(map, row, col, num)) {
            map[row][col] = num;

            if (backtrack(step + 1, map)) {
                return 1;
            }
            map[row][col] = 0;
        }
    }
    return 0;
}
int main() {
    int map[SIZE][SIZE]= {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == 0) {
                blanks[space][0] = i;
                blanks[space][1] = j;
                space++;
            }
        }
    }

    printf("outcome：\n");
    if (!backtrack(0, map)) {
        printf("it can not be resolved\n");
    }

    return 0;
}
