#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将32位二进制字符串转换为IP地址
unsigned long binaryToIP(const char binary[32]) {
    unsigned long ip = 0;

    for (int i = 0; i < 32; i++) {
        // 检查是否为有效字符
        if (binary[i] != '0' && binary[i] != '1') {
            printf("错误：包含非二进制字符 '%c' 在位置 %d\n", binary[i], i);
            return 0xFFFFFFFF;  // 返回特殊值表示错误
        }

        // 设置位值
        ip <<= 1;  // 左移一位
        if (binary[i] == '1') {
            ip |= 1;  // 如果当前位为1，则设置最低位
        }
    }

    return ip;
}

int main() {
    char binary[33] = {0};

    printf("输入二进制数:\n");
    fgets(binary, sizeof(binary), stdin);

    // 去除可能的换行符
    binary[strcspn(binary, "\n")] = '\0';

    // 检查输入长度
    //printf("%d",strlen(binary));
    if (strlen(binary) != 32) {
        printf("错误：输入必须是32位二进制数\n");
        return 1;
    }

    // 转换为IP地址
    unsigned long ipValue = binaryToIP(binary);

    if (ipValue == 0xFFFFFFFF) {
        return 1;  // 发生错误
    }

    // 提取IP地址的四个部分
    unsigned char part1 = (ipValue >> 24) & 0xFF;
    unsigned char part2 = (ipValue >> 16) & 0xFF;
    unsigned char part3 = (ipValue >> 8) & 0xFF;
    unsigned char part4 = ipValue & 0xFF;

    printf("IP:\n");
    printf("%d.%d.%d.%d\n", part1, part2, part3, part4);

    return 0;
}

int trap(int* height, int heightSize) {
    int n =heightSize;
    int maxl[100]={0};
    int maxr[100]={0};
    for (int i = 0; i < heightSize; i++) {
        maxl[i]=height[i]>maxl[i]?height[i]:maxl[i];
        maxr[i]=height[n-i-1]>maxr[n-i-1]?height[n-i-1]:maxr[n-1-i];
    }
    int rain[100]={0};
    int sum=0;
    for (int i = 0; i < heightSize; i++) {
        int real=maxl[i]<rain[i]?maxl[i]:rain[i];
        rain[i]=real-height[i];
        sum+=rain[i];
    }

    return sum;
}