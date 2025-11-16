//
// Created by 58413 on 2025/11/13.
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void PRINT(int arr[]) {
    int n = 0;
    for (n = 0;n <= 9;n++) {
        printf("%d  ",arr[n]);
    }
}

int arr[10] = { 2,3,64,656,756,566,45,99,10,8 };

//ð������
void solution_1() {
    int temp;
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9 - i;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

}

//ѡ������
void solution_2() {
    for (int i = 0;i < 9;i++) {
        int min = i;
        for (int j = i; j < 10;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }

}

//��������
void solution_3() {
    int j;
    for (int i = 1;i < 10;i++) {
        int temp = arr[i];
        for(j=i-1;j>0;j--){
            if (temp >= arr[j])break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}







void main() {
    solution_2();
    PRINT(arr);
    putchar("\n");
    srand((unsigned int)time(NULL));
    int d = rand()%100+1;
    printf("%d", d);
}