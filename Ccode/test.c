// #include<stdio.h>
//
//
// int del_repetition(int *arr,int n) {
//     int slow = 0;
//     for (int fast = 1;fast<=n;fast++){
//         if (arr[fast]!=arr[slow]) {
//             slow++;
//             arr[slow] = arr[fast];
//         }
//     }
//     return slow;
// }
//
//
//
//
// int main() {
//     int arr[13]={0,1,1,1,1,2,3,4,5,5,5,5,6};
//     int n = del_repetition(arr,13);
//     for (int i=0;i<n;i++) {
//         printf("%d\n",arr[i]);
//     }
//     printf("%d\n",n);
// }

#include <stdio.h>

void main() {
    for (int i=0;i<30;i++) {
        for (int j=0;j<30;j++) {
            if (i==0||i==29||j==0||j==29)printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }

}
