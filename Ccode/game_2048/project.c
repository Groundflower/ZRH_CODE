//
// Created by 58413 on 2026/1/28.
//
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void down(int base[][4],int*eff) {
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            if (base[i][j] != 0 && base[i][j] == base[i-1][j]) {
                base[i][j] *= 2;
                base[i-1][j] = 0;
                *eff=1;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        int targetRow = 3;
        for (int row = 3; row >= 0; row--) {
            if (base[row][j] != 0) {
                if (row != targetRow) {
                    base[targetRow][j] = base[row][j];
                    base[row][j] = 0;
                    *eff=1;
                }
                targetRow--;
            }
        }
    }
}

void up(int base[][4],int*eff) {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (base[i][j] != 0 && base[i][j] == base[i+1][j]) {
                base[i][j] *= 2;
                base[i+1][j] = 0;
                *eff=1;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        int targetRow = 0;
        for (int row = 0; row < 4; row++) {
            if (base[row][j] != 0) {
                if (row != targetRow) {
                    base[targetRow][j] = base[row][j];
                    base[row][j] = 0;
                    *eff=1;
                }
                targetRow++;
            }
        }
    }
}

void left(int base[][4],int*eff) {
    for (int i=0;i<4;i++) {
        for (int j=0;j<3;j++) {
            if (base[i][j] != 0 && base[i][j] == base[i][j+1]) {
                base[i][j] *= 2;
                base[i][j+1] = 0;
                *eff=1;
            }
        }
    }
    for (int i=0;i<4;i++) {
        int target=0;
        for (int j=0;j<4;j++) {
            if (base[i][j] != 0) {
                if (j!=target) {
                    base[i][target] = base[i][j];
                    base[i][j] = 0;
                    *eff=1;
                }
                target++;
            }
        }
    }
}

void right(int base[][4],int*eff) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (base[i][j] != 0 && base[i][j] == base[i][j-1]) {
                base[i][j] *= 2;
                base[i][j-1] = 0;
                *eff=1;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int target = 3;
        for (int j = 3; j >= 0; j--) {
            if (base[i][j] != 0) {
                if (j != target) {
                    base[i][target] = base[i][j];
                    base[i][j] = 0;
                    *eff=1;
                }
                target--;
            }
        }
    }
}

void PRINT(int base[][4]) {
    printf("_____________________");
    printf("\n");
    for (int i=0;i<4;i++) {
        printf("|");
        for (int j=0;j<4;j++) {
            if (base[i][j] == 0) {
                printf("     ");
            }
            else
            printf("%5d",base[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("_____________________");
}

void random_add(int base [][4],int *a) {
    srand((unsigned)time(NULL));
    int empty[16][2];
    int count =0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (base[i][j] == 0) {
                empty[count][0] = i;
                empty[count][1] = j;
                count++;
            }
        }
    }
    if (count>0) {
        int temp=rand()%count;
        int i=empty[temp][0];
        int j=empty[temp][1];
        base[i][j] = (rand()%10==0)?4:2;
    }
    if (count==0) {
        *a=0;
    }
}

int main() {
    int sign = 2;
    int base[4][4]={0};
    random_add(base,&sign);
    random_add(base,&sign);
    while (1) {
        PRINT(base);
        int eff=0;
        char input=getch();
        switch (input) {
            case 'w':
                up(base,&eff);
                break;
            case 'a':
                left(base,&eff);
                break;
            case 'd':
                right(base,&eff);
                break;
            case 's':
                down(base,&eff);
                break;
            default:
                printf("INPUT ERROR");
                getchar();
                break;
        }
        if (eff==1) {
            random_add(base,&sign);
        }

        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                if (base[i][j] ==2048) {
                   sign =1;
                }
            }
        }
        if (sign!=2) {
            break;
        }
        system("cls");

    }
    if (sign==1) {
        printf("Win!!!");
    }
    if (sign==0) {
        printf("Lose !!!");
    }
    return 0;
}