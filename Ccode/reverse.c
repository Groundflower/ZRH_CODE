//
// Created by 58413 on 2026/1/14.
//
#include <stdio.h>
#include <math.h>
int binSearch(int *arr,int n,int target) {
        int l=-1,r=n;
        int mid = l+(r-l)/2;
        while (r-l>1) {
                if (mid>target)r=mid;
                else l=mid;
        }
        return l;
}

void bubble_sort(int *arr,int n) {
        for (int i=0;i<n;i++) {
                for (int j=i;j<n;j++) {
                        if (arr[j]<arr[j-1]) {
                                int temp =arr[j];
                                arr[j]=arr[j-1];
                                arr[j-1]=temp;
                        }
                }
        }
}

void selection_sort(int *arr,int n) {
        for (int i=0;i<n-1;i++) {
                int min_index=i;
                for (int j=i+1;j<n;j++) {
                        if (arr[i]<arr[min_index]) min_index=i;
                }
                int temp = arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp;
        }
}

int gcf(int a,int b) {
        while (!b) {
                int temp =b;
                b%=a;
                a=temp;
        }
        return a;
}

int lcm(int a,int b) {
        return (a*b)/gcf(a,b);
}
int sushu(int a) {
        for (int i=2;i<=sqrt(a);i++) {
                if (a%i==0) return 0;
        }
        return 1;
}



int main() {

        printf("%d\n",gcf(3,6));
        printf("%d\n",lcm(3,6));
        if (sushu(3))printf("1\n");
        else printf("0\n");
}