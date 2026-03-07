//
// Created by 58413 on 2026/2/9.
//

#include <stdio.h>
#include <string.h>

int space=0 ;

int dev_pos(int i,int j) {
    switch (i) {
        case 0:
        case 1:
        case 2:
            switch (j) {
                    case 0:
                    case 1:
                    case 2:return 1;
                    case 3:
                    case 4:
                    case 5:return 2;
                    case 6:
                    case 7:
                    case 8:return 3;
                    default: return 0;
            }
        case 3:
        case 4:
        case 5:
            switch (j) {
                    case 0:
                    case 1:
                    case 2:return 4;
                    case 3:
                    case 4:
                    case 5:return 5;
                    case 6:
                    case 7:
                    case 8:return 6;
                    default: return 0;
            }
        case 6:
        case 7:
        case 8:switch (j) {
            case 0:
                case 1:
                case 2:return 7;
                case 3:
                case 4:
                case 5:return 8;
                case 6:
                case 7:
                case 8:return 9;
                default: return 0;
        }
            default: return 0;
    }
}
void trave_pos(int i,int j,int map[9][9],int sel[9][9][9]) {
    int pos = dev_pos(i,j);
    switch (pos) {
            case 1:
            for (int a=0;a<3;a++) {
                for (int b=0;b<3;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
            case 2:
            for (int a=0;a<3;a++) {
                for (int b=3;b<6;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
            case 3:
            for (int a=0;a<3;a++) {
                for (int b=6;b<9;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
            case 4:
            for (int a=3;a<6;a++) {
                for (int b=0;b<3;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
            case 5:
            for (int a=3;a<6;a++) {
                for (int b=3;b<6;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
        case 6:
            for (int a=3;a<6;a++) {
                for (int b=6;b<9;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
        case 7:
            for (int a=6;a<9;a++) {
                for (int b=0;b<3;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
        case 8:
            for (int a=6;a<9;a++) {
                for (int b=3;b<6;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
        case 9:
            for (int a=6;a<9;a++) {
                for (int b=6;b<9;b++) {
                    if (map[a][b]!=0) {
                        sel[i][j][map[a][b]-1]=0;
                    }
                }
            }
            break;
            default: return;
    }
}
void trave_line(int i,int j,int map[9][9],int sel[9][9][9]) {
    for (int a=i,b=0;b<9;b++) {
        if (b==j)continue;
        if (map[a][b]!=0) {
            sel[i][j][map[a][b]-1]=0;
        }
    }
    for (int b=j,a=0;a<9;a++) {
        if (a==i)continue;
        if (map[a][b]!=0) {
            sel[i][j][map[a][b]-1]=0;
        }
    }
}
void move(int nums[]) {
    int left = 0; // 用于放置非零元素的位置

    // 第一步：将所有非零元素前移
    for (int right = 0; right < 9; right++) {
        if (nums[right] != 0) {
            nums[left++] = nums[right];
        }
    }

    // 第二步：将剩余位置填充为 0
    while (left < 9) {
        nums[left++] = 0;
    }
}
void PRINT(int map[][9]) {
    for (int a=0;a<9;a++) {
        for (int b=0;b<9;b++) {
            printf("%d ",map[a][b]);
        }
        printf("\n");
    }
}
int won(int map[9][9]) {
    int i, j, k, valid;
    int row_check[9], col_check[9], box_check[9];

    // 检查每一行
    for (i = 0; i < 9; i++) {
        valid = 1;
        for (j = 0; j < 9; j++) {
            if (map[i][j] == 0) {
                valid = 0;
                break;
            }
        }
        if (!valid) return 0;
    }

    // 检查每一列
    for (j = 0; j < 9; j++) {
        valid = 1;
        for (i = 0; i < 9; i++) {
            if (map[i][j] == 0) {
                valid = 0;
                break;
            }
        }
        if (!valid) return 0;
    }

    // 检查每个3x3子网格
    for (int box_row = 0; box_row < 9; box_row += 3) {
        for (int box_col = 0; box_col < 9; box_col += 3) {
            valid = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (map[box_row + i][box_col + j] == 0) {
                        valid = 0;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (!valid) return 0;
        }
    }

    // 检查行是否有重复
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            row_check[j] = 0;
        }
        for (j = 0; j < 9; j++) {
            row_check[map[i][j] - 1]++;
            if (row_check[map[i][j] - 1] > 1) return 0;
        }
    }

    // 检查列是否有重复
    for (j = 0; j < 9; j++) {
        for (k = 0; k < 9; k++) {
            col_check[k] = 0;
        }
        for (i = 0; i < 9; i++) {
            col_check[map[i][j] - 1]++;
            if (col_check[map[i][j] - 1] > 1) return 0;
        }
    }

    // 检查3x3子网格是否有重复
    for (int box_row = 0; box_row < 9; box_row += 3) {
        for (int box_col = 0; box_col < 9; box_col += 3) {
            for (k = 0; k < 9; k++) {
                box_check[k] = 0;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    box_check[map[box_row + i][box_col + j] - 1]++;
                    if (box_check[map[box_row + i][box_col + j] - 1] > 1) return 0;
                }
            }
        }
    }

    return 1;
}
void sel_init(int sel[9][9][9]) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                sel[i][j][k]=k+1;

            }
        }
    }
}
void backtrack(int sel[9][9][9],int step) {
    if (step==space)return;
    int used[space];
    memset(used,0,sizeof(used));
    for (int i=0;i<9;i++) {}
}
int main() {
    // //int map[9][9],map_cpy[9][9];
    //
    // //make map
    // printf("input start");
    // for (int i=0;i<9;i++) {
    //     for (int j=0;j<9;j++) {
    //         scanf("%d",&map[i][j]);
    //     }
    // }
    // printf("input finished");
    int map[9][9] = {
        {5, 3, 4, 6, 7, 8, 0, 0, 0},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 0, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (map[i][j] == 0) {
                space++;
            }
        }
    }

    // //copy
    // for (int i=0;i<9;i++) {
    //     for (int j=0;j<9;j++) {
    //         map_cpy[i][j] = map[i][j];
    //     }
    // }
    //make sel
    int sel[9][9][9];
    sel_init(sel);
    int ccc=0;
while (!won(map)) {
    //if (ccc>500) break;
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (map[i][j] == 0) {
                trave_pos(i,j,map,sel);
                trave_line(i,j,map,sel);
                move(sel[i][j]);
            }
        }
    }

    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            int count =0;
            for (int k=0;k<9;k++) {
                if(sel[i][j][k]!=0)count++;
            }
            if (count==1&&map[i][j]==0) {
                map[i][j]=sel[i][j][0];

            }
        }
    }
    ccc++;
}
    PRINT(map);

    return 0;

}
