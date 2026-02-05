#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRINT(int *m,int n) {
    for (int i=0;i<n;i++) {
        printf("%d\n",*(m+i));
    }

}
// int testmalloc() {
//         int* p =malloc(10*sizeof(int));
//         if (!p) {
//             printf("malloc failed\n");
//             return 1;
//         }
//         //memset (p,0,10*sizeof(int));
//
//         for(int i=0;i<10;i++) {
//             *(p+i)=i+1;
//             printf("%d\n",*(p+i));
//         }
//         //PRINT(p);
//         free(p);
//         p =NULL;
//     }
// int testcalloc() {
//     int *bp = calloc(10,sizeof(int));
//     if (!bp) {
//         printf("calloc fial\n");
//         return 1;
//     }
//     PRINT(bp);
//     free(bp);
//
// }


int main() {
    int input;
    int elenum=10;
    int inputele=0;
    int *arr=malloc(elenum*sizeof(int));
    int *cur=arr;
    if (!arr) {
        printf("malloc failed\n");
        return 1;
    }
    while (1) {
        scanf_s("%d",&input,4);
        if (input <0) {
            printf("Input is negative\n");
            break;
        }
        *cur=input;
        cur++;
        inputele++;
        if (inputele==elenum) {
            printf("realloc is positive");
            elenum+=elenum;
            int *temp=realloc(arr,elenum*sizeof(int));
            if (!temp) {
                printf("realloc failed\n");
                free(arr);
                arr=NULL;
                cur=NULL;
                return 1;
            }
            arr=temp;
            cur=arr+inputele;
        }
    }
    PRINT(arr,inputele);
    free(arr);
    arr=NULL;
    cur=NULL;
    printf("num of element is %d",inputele);
    return 0;


}