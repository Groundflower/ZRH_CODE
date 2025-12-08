//
// Created by 58413 on 2025/12/6.
//

#include<stdio.h>
#include<windows.h>
#include<conio.h>
enum{w=1,a,s,d};
int height,width;
int wasd[][1];
void update(int *a,int height,int width);
//void show(int *a,int height,int width);
int main() {
    system("chcp 65001");
    scanf("%d%d",&height,&width);
    int x=height/2,y=width/2;
        while (1) {
            update(wasd,height,width);

        }

}







void update(int *a,int height,int width) {
    for (int i=0;i<height;i++) {
        for (int j=0;j<width;j++) {
            printf("⬜");
        }
    }

}
