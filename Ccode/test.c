#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// int hefa(long long int *a, long long int *b) {
//     printf("input\n");
//     int result = scanf_s("%d%d", a, b);
//
//     // 处理输入错误：清空缓冲区并提示重新输入
//     if (result != 2) {
//         printf("input error\n");
//         int c;
//         while ((c = getchar()) != '\n' && c != EOF);
//         return 0;
//     }
//     return 1;
// }
//
// int max(int *a, int *b) {
//     return *a > *b ? *a : *b;
// }
//
// int main() {
//     long long int a, b;
//     char c = 'y';
//     do {
//         // 循环获取合法输入，直到成功为止
//         while (hefa(&a, &b) == 0);
//
//         printf("max is %d\n", max(&a, &b));
//         printf("continue?(y/n):");
//
//         // 处理getchar()读取残留换行符的问题
//         while ((c = getchar()) == '\n');  // 跳过所有残留的换行符
//
//     } while (c == 'y' || c == 'Y');  // 支持大写Y
//
//     printf("exit\n");
//     return 0;
// }

void swap(int *a,int*b) {
    int temp = *a;
    *a=*b;
    *b = temp;
}
int datainput(int *arr) {
    int i = -1;
    do {
        i++;
        scanf("%d", &arr[i]);
    }while (arr[i]>=0);
    return i;
}
int date(int *arr,int n) {
    for (int i=0;i<n;i++) {
        int min =i;
        for (int j=i+1;j<n;j++) {
            arr[j]<arr[min]?min=j:1;
        }
        swap(&arr[i],&arr[min]);
    }
    return 0;
}

int main() {
    int arr[100]={};
    int n= datainput(arr);
    date(arr,n);
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}