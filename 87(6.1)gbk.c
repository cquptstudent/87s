/**
 *
 * By cquptstudent
 * Version 6.1
 * Date 2023 11 25 0:04
 *
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void Notify(int second);
void tryLuck(int num);
void level2(void);
void cl(void);
bool question1(char question[][300], char answer[][20], int quesionNo);
void level3(void);

int main(void)
{
    int time = 1200;
    char a[100];
    char answer[100] = "I love you"; /*����*/
    int try_time = 0;
    system("shutdown -sg -t 1200"); /*�ػ�1200��*/
    do
    {
        printf("Your computer will shutdown in %d seconds\n", time);
        for (int i = 0; i < (2000 - time); i++) /*����2000-time���Ǻ�*/
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
        gets_s(a, 100); /*��������*/
        for (int i = 0; i < 50; i++)
        {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        try_time++;
        /*�������1��: ʱ����1100s
        �������2��: ʱ����1000s
        �������3��: ʱ����900s
        �������4��: ʱ����800s
        �������5��: ʱ����300s
        �������6��: ʱ����60s
        �������7��: ʱ����30s
        8�μ�����: ÿ��10s
        */
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
        system("CLS"); /*�����Ļ*/
        printf("Do you want to continue guessing?\nIf no, please enter 'N' or 'n'. If yes, press other key.\n");
        char choice = getch(); /*����ѡ��*/
        if (choice == 'N' || choice == 'n')
        {
            printf("Don't give up! Really quit? enter 'Y' or 'y' to quit.\n");
            choice = getch();
            if (choice == 'Y' || choice == 'y')
            {
                printf("Really?\n");
                system("shutdown -s -t 10");  /*5.3�汾�޸�: ���shutdown -a���ܽ��ȡ��������*/
                for (int i = 10; i >= 0; i--) /*����ʱ 10s*/
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                goto Last;
            }
        }
    } while (strcmp(a, answer) != 0);
    printf("Right!\n"); /*��1�ؽ���*/
    system("shutdown -a");
    /*5.4�°汾������lv2*/
    Sleep(2000); /*��Ϣ2s*/
    printf("Do you think it is easy?");
    Sleep(2000); /*��Ϣ2s*/
    system("CLS");
    for (int i = 20; i > 0; i--)
    {
        printf("Level 2 starts\n");
        /*5.5���޸�: lv2����ı�*/
        printf("Wait a few seconds.\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
    level2();

    /*6.1 �汾�¹��ܣ�level 3*/
    system("CLS");
    printf("Also very easy? Try level 3!\n");
    Sleep(5000);
    Notify(20);
    system("shutdown -a");
    level3();
    putchar('\n');
    printf("You win!");
    Sleep(8000);

Last:
    return 0;
}

void level2(void)
{
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("When number is in (1000,10000), your computer will shutdown, (1-1000) will sleep\n");
    printf("Your number: %d\n", num);
    Sleep(2000);
    printf("Wait a few seconds.");
    printf("......................\n");
    tryLuck(num);
    printf("Now it's your turn.");
    printf("Please enter the password!\n");

    int luck = rand() % 100 + 1;
    char discard[100];
    char newPassword[100] = "I love you";
    char inputPassword[100];
    int plus = 1 /*��������*/;
    int probablity = rand() % 100 + plus;

    while (strcmp(inputPassword, newPassword) != 0)
    {
        /*5.4.0���޸ĳԵ����룬5.4.1�Ե�����Ϊ100%����bug�޸ģ�5.5���������*/
        printf("Little worm come! The probablity of it comes is %d%%\n", (100 - probablity));
        if (luck > probablity) // �и������뱻�Ե�,��������������
        {
            gets_s(discard, 100);
            printf("Your password was eaten by a little worm!\n"); /*���뱻�Ե�*/
            Sleep(2000);
            system("CLS"); /*����*/
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
                printf("Please retry!"); /*����������뱻�Ե���������1%*/
                plus++;
            }
            system("CLS");
        }
        printf("Please enter the password!\n");
        luck = rand() % 100 + 1;
        probablity = rand() % 100 + plus;
    }
}

void tryLuck(int num)
{
    /*��90%�ĸ��ʹػ�, 9.99%����ֱ�ӽ���˯��ģʽ��0.01%ֱ���˳�*/
    if (num == 10000)
    {
        printf("Good good!"); /*ֱ���˳�*/
        return;
    }

    else
    {
        // �ػ�
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
        else // ˯��
        {
            printf("Good luck!\n");
            Sleep(5000);
            system("shutdown -h");
        }
    }
}

void Notify(int second)
{
    for (int i = second; i >= 0; i--)
    {
        printf("Wait a few seconds.\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
}

void level3(void)
{
    int score = 0;
    char question[25][300] = {
        "1. He ______ with her over her frustration at not being elected as the leader of the team.\nA.confressed\nB.overwhelmed\nC.pitied\nD.Sympathized\n",
        "2. You can often see football players ______ their knees in the competition\nA.bruise\nB.damage\nC.blow\nD.cruise\n",
        "3. I have found that the commmunity has ______ great changes since I was here last.\nA.submitted\nB.undergone\nC.sustained\nD.experimented\n",
        "4. Rather than being hoodwinked, I would ______ anything.\nA.endure\nB.diverage\nC.instruct\nindulge\n",
        "5. The lion, as the king of all animals, will often stalk and ______ for hours.\nA.pray\nB.prim\nC.pry\nD.prey\n",
        "6. 1+1=______",
        "7. f(x) = secx, f'(x) = ______\nA.secxtanx\nB.sexctanx\nC.tanxscex\nD.tanxtanx\nE.secxcscx\nF.cscxcosx\nG.cosxsecx\n",
        "8. 2��10�η���:______\n",
        "9. f'(x) = cscxcotx, f'(x) = ______\nA.-cotx\nB.cotx\nC.cscxcotx\nD.����\nE.cssxctox\n",
        "10.f(x) = x, f'''(x) = ______\n",
        "11.\n#include <iostream>\nusing namespace std;\nint main()\n{\n\tint i = 0;\n\tcout << i;\n\treturn 0;\n______\n��գ�",
        "12.\nint a= (int)((float)(3.4*3.4) + 0.7 * (long)5234567878) %% (int)((float) 3.5 * (unsigned)23345 / 3.4);\nprintf(\"%d\", a);\n����a=______\n",
        "13.����ת��: 6F681(16����)ת����10����: ______\n",
        "14.���ļ�87(5.5.2).exe��,���ֹ���һ�д���\nIn the file 87\nA.#inlcude<stdio.h>\nB.system(pause)\nC.return 0;\nD.fxxk you\nE.û����87(5.5.2).exe\n",
        "15.\nint i = 0;\nprintf(\"%d\", ++i);\ni++;\ni+=i*=2;\ni = ______",
        "16.1+2+3+4+5+6+7+...+100 = ______\n",
        "17.H2+Cl2 = ______\n",
        "18.\n#include <iostream>\nusing namesp___ std;\n{\n}\nӦ����\n",
        "19.12345+54321=______\n",
        "20.-(-(-(-(-(-(-(-(-(-(-(-5))))))))))) = ______\n",
        "21.y=sinx, x=______\nA.arcsix\nB.arcosx\nC.arssinx\nD.arcsinx\nE.arcsin\nF.arsond\nG.arccotanx\nH.Arcsins\n",
        "22.#in___de <iostream>\n",
        "23.1-1+1-1+1-1+1-1+1-1=______\n",
        "24.��һ����ʲô��Ŀ����?\nA.C\nB.C++\nC.Java\nD.Kotlin\nE.English\nF.Chinese\nG.Html\n",
        "25.f'(x) = secxcscx, f'(x) = ______\nA.secxtanx\nB.sexctanx\nC.tanxscex\nD.tanxtanx\nE.secxcscx\nF.cscxcosx\nG.cosxsecx\n"};
    char answer[25][20] = {
        "D", "A", "D", "B", "D", /*6-10*/ "2", "A", "1024", "C", "0",
        /*11-15*/ "}", "15979", "456321", "C", "8",
        /*16-20*/ "5050", "HCl", "ace", "66666", "5", /*21-25*/ "D", "clu", "0", "E", "E"};
    system("shutdown -s -t 1800");
    printf("--------------------����ϵͳ-------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("----------ʱ��30���� ÿ����5��, �ܹ�100��------------\n");
    printf("-----------------------------------------------------\n");

    printf("----------------60�����Ͽ���ȡ���ػ�-----------------\n");
    printf("\n\n\tȷ������qȡ�����ԣ�������������");
    char ch = getch();
    if (ch == 'Q' || ch == 'q')
    {
        system("shutdown -p");
    }
    else
    {
        system("CLS");
        // for (int i = 10; i > 0; i--)
        // {
        // printf("����ʱ��%d", i);
        // Sleep(1000);
        // system("CLS");
        Notify(10);
        // }

        for (int i = 0; i < 15; i++)
        {
            bool b;
            b = question1(question, answer, i);
            if (b)
            {
                score += 5;
            }
        }
        printf("��������ѡ������\n");
        printf("��������ţ�����֮���пո�����\n");
        int choice[5];
        int judge;
        for (int i = 0; i < 5; i++)
        {
            judge = scanf("%d", &choice[i]);
            while (judge == 0 || (choice[i] > 25 || choice[i] < 16))
            {
                if (judge == 0)
                    cl();
                printf("������16-25�����֣�����֮���пո�����");
                judge = scanf("%d", &choice[i]);
            }
            getchar();
        }
        system("CLS");

        for (int i = 0; i < 5; i++)
        {
            bool c;
            c = question1(question, answer, choice[i] - 1);
            if (c)
            {
                score += 5;
            }
        }
    }

    if (score < 60)
    {
        system("color 0C");
        printf("��ĵ÷���: %d\n", score);
        printf("Please wait......");
        Sleep(10000);
        system("shutdown -a");
        system("shutdown -s -t 1000");
    }
    else
    {
        system("color 0A");
        printf("��ĵ÷���: %d\n", score);
        printf("Please wait......");
        Sleep(10000);
        system("shutdown -a");
    }
}

bool question1(char question[][300], char answer[][20], int quesionNo)
{
    char yourAnswer[200];
    puts(question[quesionNo]);
    printf("��������Ĵ�:\n");
    gets_s(yourAnswer, 100);
    system("cls");
    if (strcmp(yourAnswer, answer[quesionNo]) == 0)
    {
        return true;
    }
    return false;
}

void cl(void)
{
    char b;
    do
    {
        scanf("%c", &b);
    } while (b != '\n');
}