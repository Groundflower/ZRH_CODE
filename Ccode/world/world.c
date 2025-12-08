//
// Created by 58413 on 2025/12/8.
//


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define M 30
#define N 30
void update(int arr[][M],int i,int j,int num);
void getmap(int arr[][N],int i,int j);
void display(int arr[][N],int i,int j);
void maze();

int main() {
    setbuf(stdout, NULL);
    system("chcp 65001");
    int arr[M][M];
    int x=25,y=25;

    getmap(arr,M,N);
    arr[x][y]=2;
    update(arr,x,y,1);
    return 0;
}



void getmap(int arr[][N],int i,int j) {
    FILE *pmap = fopen("map.txt","r");
    if(pmap==NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    for ( i=0;i<M;i++) {
        for ( j=0;j<M;j++) {
            fscanf(pmap,"%d",&arr[i][j]);
        }
    }
    fclose(pmap);
}

void display(int arr[][N],int i,int j) {
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            if (arr[i][j]==0)printf("⬜");
            if (arr[i][j]==1)printf("⬛");
            if (arr[i][j]==2)printf("😊");

        }
        printf("\n");
    }
}
void maze() {

    system("cd maze && maze.exe");

}

void update (int arr[][M],int i,int j,int num) {
    while (j!=29) {
        system("cls");
        display(arr,i,j);
        Sleep(50);
        char input=getch();
        if(input=='w'&&arr[i-1][j]!=1) {
            arr[i][j]=0;
            arr[--i][j]=2;

        }
        if(input=='a'&&arr[i][j-1]!=1) {
            arr[i][j]=0;
            arr[i][--j]=2;

        }
        if(input=='s'&&arr[i+1][j]!=1) {
            arr[i][j]=0;
            arr[++i][j]=2;

        }
        if(input=='d'&&arr[i][j+1]!=1) {
            arr[i][j]=0;
            arr[i][++j]=2;
        }
        if (input ==1) {
             arr[i][j]=0;
             arr[24][29]=2;
         }


    }
    system("cls");
    if (i==25||i==24||i==23) {
        maze();
    }
    Sleep(5000);
}