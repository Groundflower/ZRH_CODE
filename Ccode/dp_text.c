#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int testmalloc() {
        int* p =malloc(10*sizeof(int));
        if (!p) {
            printf("malloc failed\n");
            return 1;
        }
        memset (p,0,10*sizeof(int));

        for(int i=0;i<10;i++) {

            printf("%d\n",*(p+i));
        }
        free(p);
        p =NULL;
    }
    int main() {
        testmalloc();
        return 0;
    }