#include <stdio.h>
#include <string.h>
#include <windows.h>

int getKey(void);

int main() 
{
    int encryptionKey = getKey();
    char plaintext[100];
    while (1) {
        printf("输入明文: ");
        scanf("%s", plaintext);

        int isValid = 1;

        for (int i = 0; i < strlen(plaintext); i++) {
            if (!isalpha(plaintext[i])) {
                isValid = 0;
                break;
            }
        }

        if (isValid) {
            printf("明文: %s\n", plaintext);
            break; 
        } else {
            printf("明文只能包含字母字符，请重新输入。\n");
        }
    }

    char ciphertext[100];
    for (int x = 0; x < strlen(plaintext); x++) {
        if (isupper(plaintext[x])) {
            ciphertext[x] = (plaintext[x] - 'A' + encryptionKey) % 26 + 'A';
        } else if (islower(plaintext[x])) {
            ciphertext[x] = (plaintext[x] - 'a' + encryptionKey) % 26 + 'a';
        } else {
            ciphertext[x] = plaintext[x]; 
        }
    }
    
    printf("加密后的密文: %s\n", ciphertext);
    
    return 0;
}