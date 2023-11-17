/*
 * version 5.2
 * 2023 11 17 16:18
 */
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void Notify(int second);
void tryLuck(int num);
int main(void)
{
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("When number is in (1000,10000), your computer will shutdown, (1-1000) will sleep\n");
    printf("Your number: %d\n", num);
    tryLuck(num);

    return 0;
}

void tryLuck(int num)
{
    /*有60%的概率关机*/
    if (num == 10000)
    {
        printf("Good good!");
        return;
    }
    else
    {
        printf("You have to wait and stay here without doing anything\n");
        if (num > 9000)
        {
            system("shutdown -s -t 90");
            Notify(90);
        }
        else if (num > 8000)
        {
            system("shutdown -s -t 80");
            Notify(80);
        }
        else if (num > 7000)
        {
            system("shutdown -s -t 70");
            Notify(70);
        }
        else if (num > 6000)
        {
            system("shutdown -s -t 60");
            Notify(60);
        }
        else if (num > 5000)
        {
            system("shutdown -s -t 50");
            Notify(50);
        }
        else if (num > 4000)
        {
            system("shutdown -s -t 40");
            Notify(40);
        }
        else if (num > 3000)
        {
            system("shutdown -s -t 30");
            Notify(30);
        }
        else if (num > 2000)
        {
            system("shutdown -s -t 20");
            Notify(20);
        }
        else if (num > 1000)
        {
            system("shutdown -s -t 10");
            Notify(10);
        }
        else
        {
            printf("Good luck!");
            system("shutdown -h");
        }
    }
}

void Notify(int second)
{
    for (int i = second; i >= 0; i--)
    {
        printf("%d\n", i);
        Sleep(1000);
    }
}