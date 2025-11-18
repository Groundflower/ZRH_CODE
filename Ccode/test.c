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


#include <stdio.h>
#include<math.h>
#include <stdio.h>

int main()
{	int arr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int* i = arr;
    do{
        *i=1;
        printf("Input a month:");
        scanf("%d",i);
    }while(*i<1||*i>12);
    printf("The number of days is %d\n",arr[*i+1]);


    return 0;
}