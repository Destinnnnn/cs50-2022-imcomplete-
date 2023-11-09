#include <stdio.h>
#include <string.h>
#include <windows.h>
int points[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int computer_score(char* word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i];
        if (c >= 'A' && c <= 'Z')
        {
            score += points[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z')
        {
            score += points[c - 'a'];
        }
    }
    return score;
}

int main()
{
    char word1[100];
    printf("User1输入一个单词：");
    scanf("%s",word1);

    char word2[100];
    printf("User2输入一个单词：");
    scanf("%s",word2);

    int score1 = computer_score(word1);
    int score2 = computer_score(word2);

    if (score1 > score2)
    {
        printf("User1 win");
    }
    else if (score1 == score2)
    {
        printf("Tie");
    }
    else
        printf("User2 win");
    system("pause");
}

