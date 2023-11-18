/*
 * version: 5.4 (6.1 dev)
 * 2023 11 18 20:54
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Notify(int second);
void tryLuck(int num);
void level2(void);

int main(void)
{
    int time = 1200;
    char a[100];
    char answer[100] = "I love you";
    int try_time = 0;
    system("shutdown -sg -t 1200");
    do
    {
        printf("Your computer will shutdown in %d seconds\n", time);
        for (int i = 0; i < (2000 - time); i++)
        {
            putchar('*');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        for (int i = 0; i < 50; i++)
        {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        printf("Please enter the password:");
        gets_s(a, 100);
        for (int i = 0; i < 50; i++)
        {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        try_time++;
        switch (try_time)
        {
        case 1:
            system("shutdown -a");
            system("shutdown -sg -t 1100");
            time -= 100;
            break;
        case 2:
            system("shutdown -a");
            system("shutdown -sg -t 1000");
            time -= 100;
            break;
        case 3:
            system("shutdown -a");
            system("shutdown -sg -t 900");
            time -= 100;
        case 4:
            system("shutdown -a");
            system("shutdown -sg -t 800");
            time -= 300;
            break;
        case 5:
            system("shutdown -a");
            system("shutdown -sg -t 300");
            time -= 300;
            break;
        case 6:
            system("shutdown -a");
            system("shutdown -sg -t 60");
            time -= 240;
            break;
        case 7:
            system("shutdown -a");
            system("shutdown -sg -t 30");
            time -= 30;
        default:
            system("shutdown -a");
            system("shutdown -s -t 10");
            break;
        }
        if (strcmp(a, answer) != 0)
        {
            printf("Wrong!");
        }
        else
        {
            break;
        }
        system("CLS");
        printf("Do you want to continue guessing?\nIf no, please enter 'N' or 'n'. If yes, press other key.\n");
        char choice = getch();
        if (choice == 'N' || choice == 'n')
        {
            printf("Don't give up! Really quit? enter 'Y' or 'y' to quit.\n");
            choice = getch();
            if (choice == 'Y' || choice == 'y')
            {
                printf("Really?\n");
                for (int i = 10; i >= 0; i--)
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                system("shutdown -s -t 0");
                goto Last;
            }
        }
    } while (strcmp(a, answer) != 0);
    printf("Right!");
    system("shutdown -a");
    Sleep(2000);
    printf("Do you think it is easy?");
    system("CLS");
    printf("Level 2\n");
    for (int i = 20; i > 0; i--)
    {
        printf("%d\n", i);
        Sleep(1000);
        system("CLS");
    }
    level2();
    system("shutdown -a");

    printf("You win!");
    Sleep(10000);

Last:
    return 0;
}

void level2(void)
{
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("When number is in (1000,10000), your computer will shutdown, (1-1000) will sleep\n");
    printf("Your number: %d\n", num);
    printf("Wait a few seconds.");
    printf("......................\n");
    tryLuck(num);
    printf("Now it's your turn.");
    printf("Please enter the password!\n");

    int luck = rand() % 100 + 1;
    char discard[100];
    char newPassword[100] = "I love you";
    char inputPassword[100];
    int probablity = rand() % 100 + 1;

    while (strcmp(inputPassword, newPassword) != 0)
    {
        printf("Little worm come! The probablity of it comes is %d%%\n", (100-probablity));
        if (luck > probablity) // 有80%-100%概率密码被吃掉
        {
            gets_s(discard, 100);
            printf("Your password was eaten by a little worm!\n");
            Sleep(2000);
            system("CLS");
        }
        else
        {
            gets_s(inputPassword, 100);
            if (strcmp(inputPassword, newPassword) == 0)
            {
                return;
            }
            else
            {
                printf("Please retry!");
            }
            system("CLS");
        }
        printf("Please enter the password!\n");
        luck = rand() % 100 + 1;
        probablity = rand() % 100 + 1;
    }
}

void tryLuck(int num)
{
    /*有90%的概率关机, 9.99%概率直接进入睡眠模式，0.01%直接退出*/
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
            system("shutdown -s -t 900");
            Notify(90);
        }
        else if (num > 8000)
        {
            system("shutdown -s -t 800");
            Notify(80);
        }
        else if (num > 7000)
        {
            system("shutdown -s -t 700");
            Notify(70);
        }
        else if (num > 6000)
        {
            system("shutdown -s -t 600");
            Notify(60);
        }
        else if (num > 5000)
        {
            system("shutdown -s -t 500");
            Notify(50);
        }
        else if (num > 4000)
        {
            system("shutdown -s -t 400");
            Notify(40);
        }
        else if (num > 3000)
        {
            system("shutdown -s -t 300");
            Notify(30);
        }
        else if (num > 2000)
        {
            system("shutdown -s -t 200");
            Notify(20);
        }
        else if (num > 1000)
        {
            system("shutdown -s -t 100");
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
        system("CLS");
    }
}