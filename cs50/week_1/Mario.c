#include <stdio.h>
#include <windows.h>

int main(void) {
    int blocks;
    
    
    printf("请输入塔的高度(1-8): ");
    
    do {
        
        scanf("%d", &blocks);

       
        while (getchar() != '\n');
        
        
        if (blocks < 1 || blocks > 8) {
            printf("无效输入,请输入1到8之间的数字: ");
        }
    } while (blocks < 1 || blocks > 8);

    for (int h = 0; h < blocks; h++) {
        for (int x = blocks - h; x > 1; x--) {
            printf(" ");
        }

        for (int w = 0; w <= h; w++) {
            printf("#");
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}




    
