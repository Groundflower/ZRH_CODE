//
// Created by 58413 on 2025/11/13.
//
#include<stdio.h>
#include<easyx.h>

void drawshape() {
    putpixel(50, 50,RED);//DIAN
    setlinestyle(PS_SOLID, 5);
    setlinecolor(BLUE);//COLOR OF LINE
    line(0, 0, 640, 480);//LINE
    line(0, getheight(), getwidth(), 0);
    rectangle(100,0,150,50);//���Σ�����䣩
    setfillcolor(RED);
    fillrectangle(100, 50, 150, 100);//���Σ���䣩
    solidrectangle(100,100,150,150);//�޿����
    roundrect(160,0,210,50,25,25);//Բ��

    solidroundrect(160, 0, 210, 50, 25, 25);



}
char drawtext() {
    outtextxy(200,200,char("love"));
    return 0;
}
int main() {
    initgraph(640, 480, EX_NOMINIMIZE);
    setbkcolor(RGB(231,114,227));
    cleardevice();
    drawshape();
    drawtext();

    getchar();

    return 0;
}