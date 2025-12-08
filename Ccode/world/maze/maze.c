//
// Created by 58413 on 2025/12/6.
//

#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#define M 50//max
#define N 50//max
int high;
int width;
int a[M][N];
void readmaze(int a[][M],int *n,int *m);
void showmaze(int a[][N],int n,int m);
void update(int a[][M],int x,int y,int exitx,int exity);
int main() {
    system("chcp 65001");
    int x=1,y=1,exitx=10,exity=11;
    readmaze(a,&high,&width);
    showmaze(a,high,width);
    a[x][y]=2;
    update(a,x,y,exitx,exity);
    return 0;
}





void readmaze(int a[][M],int *n,int *m){
    FILE *p=fopen("maze.txt","r");
    if (p==NULL) {
        printf("initialoization failure");
        exit(0);
    }
    fscanf(p,"%d%d",n,m);
    for (int i=0;i<*n;i++) {
        for (int j =0;j<*m;j++) {
            fscanf(p,"%d",&a[i][j]);
        }
    }
    fclose(p);
}



void showmaze(int a[][N],int n,int m){
    for (int i =0;i<n;i++) {
        for (int j=0;j<m;j++) {
            switch(a[i][j]) {
                case 0: printf("⬜"); break;
                case 1: printf("⬛"); break;
                case 2: printf("😊"); break;
                default: printf("0"); break;
            }
        }
        printf("\n");
    }
}

void world() {
    system("cd ..&&world.exe &&1");

}
void update(int a[][M],int x,int y,int exitx,int exity) {
    while (x!=exitx|| y!=exity) {
        system("cls");
        showmaze(a,high,width);
        Sleep(100);
        char input = getch( );
        if (input == 'a'&&a[x][y-1]!=1) {
            a[x][y]=0;
            a[x][--y]=2;
        }
        if (input == 'w'&&a[x-1][y]!=1) {
            a[x][y]=0;
            a[--x][y]=2;
        }
        if (input == 's'&&a[x+1][y]!=1) {
            a[x][y]=0;
            a[++x][y]=2;
        }
        if (input == 'd'&&a[x][y+1]!=1) {
            a[x][y]=0;
            a[x][++y]=2;
        }
        if (x==1&&y==0) {
            world();
        }

    }
    system("cls");
    if (y==0)world();
    showmaze(a,high,width);
    Sleep(100);
    printf("win!\n quite after 5s");
    Sleep(5000);
    world();

}
