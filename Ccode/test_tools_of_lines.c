//
// Created by 58413 on 2025/11/27.
//
#include <stdio.h>
#define N 10
void del(int arr[],int i);
void insert(int arr[],int i,int num);
int search_1(int arr[],int num);

int main() {
    int arr[N];
    for (int i=0;i<N;i++) {
        arr[i] = i;
    }

    //insert(arr,0,200);
    //del(arr,3);
    int a = search_1(arr,1);
    if (a == -1) printf("none\n");

    for (int i=0;i<N;i++) {
        printf("%d\n",arr[i]);
    }

}


void del(int arr[],int i) {
    for (int j=i;j<N;j++) {
        arr[j] = arr[j+1];
    }
}

void insert(int arr[],int i,int num) {
    for (int j=N;j>i;j--) {
        arr[j] = arr[j-1];
    }
    arr[i] = num;
}

int search_1(int arr[],int num) {
    int count =0;
    for (int i=0;i<N;i++) {
        if (arr[i] == num) {
            count++;
            printf("position:%d\n",i);
        }
    }
    return count==0? -1: count;
}