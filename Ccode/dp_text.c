#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRINT(int *m) {
    for (int i=0;i<10;i++) {
        printf("%d\n",*(m+i));
    }

}
int testmalloc() {
        int* p =malloc(10*sizeof(int));
        if (!p) {
            printf("malloc failed\n");
            return 1;
        }
        //memset (p,0,10*sizeof(int));

        for(int i=0;i<10;i++) {
            *(p+i)=i+1;
            printf("%d\n",*(p+i));
        }
        //PRINT(p);
        free(p);
        p =NULL;
    }
int testcalloc() {
    int *bp = calloc(10,sizeof(int));
    if (!bp) {
        printf("calloc fial\n");
        return 1;
    }
    PRINT(bp);
    free(bp);

}
    int main() {
        testcalloc();
        return 0;
    }