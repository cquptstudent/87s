/**
 *
 * @author xhily_
 * Version 6.4
 * Date 2024 6 28 0:16
*/
/*
 * 6.3�汾���£��ӳ�ʱ�䣬��������
 * ��һ�����룺xhily_
 * �ڶ������룺xhily_@outlook
 *
 * 6.4�汾���£�����������ʾ
 */
#define _CRT_SECURE_NO_WARNINGS 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
 // #include <>

void Notify(int second);
void tryLuck(int num);
void level2(void);
void cl(void);
bool question1(char question[][300], char answer[][20], int quesionNo);
void level3(void);
void level0(void);
void level4(void);

int main(void) {
    int time = 1200;
    char a[100];
    char answer[100] = "xhily_"; /*����*/
    int try_time = 0;
    int shutdownTime_first = 12000000;
    level0();
    // time = shutdownTime_first;
    char str[100];
    sprintf(str, "shutdown -sg -t %d", shutdownTime_first);
    system(str); /*�ػ�12000��*/
    do {
        printf("��ĵ��Խ���%d���ڹػ�\n", time);
        for (int i = 0; i < (2000 - time); i++) /*����2000-time���Ǻ�*/
        {
            putchar('*');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        for (int i = 0; i < 50; i++) {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        printf("����������:");
        gets(a); /*��������*/
        for (int i = 0; i < 50; i++) {
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
        switch (try_time) {
        case 1:
            system("shutdown -a");
            system("shutdown -sg -t 110000");
            time -= 100;
            break;
        case 2:
            system("shutdown -a");
            system("shutdown -sg -t 100000");
            time -= 100;
            break;
        case 3:
            system("shutdown -a");
            system("shutdown -sg -t 900000");
            time -= 100;
        case 4:
            system("shutdown -a");
            system("shutdown -sg -t 800000");
            time -= 300;
            break;
        case 5:
            system("shutdown -a");
            system("shutdown -sg -t 300000");
            time -= 300;
            break;
        case 6:
            system("shutdown -a");
            system("shutdown -sg -t 600000");
            time -= 240;
            break;
        case 7:
            system("shutdown -a");
            system("shutdown -sg -t 300000");
            time -= 30;
        default:
            system("shutdown -a");
            system("shutdown -s -t 1000000");
            break;
        }
        if (strcmp(a, answer) != 0) {
            printf("�������!");
        } else {
            break;
        }
        system("CLS"); /*�����Ļ*/
        printf("����?\n�˳��밴'n'��'N'�������밴������\n");
        char choice = _getch(); /*����ѡ��*/
        if (choice == 'N' || choice == 'n') {
            printf("��Ҫ������ ���Ҫ�˳��𣿰�'Y' �� 'y' �˳�.\n");
            choice = _getch();
            if (choice == 'Y' || choice == 'y') {
                printf("�����?\n");
                system("shutdown -s -t 1000000"); /*5.3�汾�޸�: ���shutdown -a���ܽ��ȡ��������*/
                for (int i = 10; i >= 0; i--) /*����ʱ 10s*/
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                goto Last;
            }
        }
    } while (strcmp(a, answer) != 0);
    printf("������ȷ!\n"); /*��1�ؽ���*/
    system("shutdown -a");
    /*5.4�°汾������lv2*/
    Sleep(2000); /*��Ϣ2s*/
    printf("�ǲ���̫����?");
    Sleep(2000); /*��Ϣ2s*/
    system("CLS");
    for (int i = 20; i > 0; i--) {
        printf("�ڶ��أ�\n");
        /*5.5���޸�: lv2����ı�*/
        printf("�Ե�...\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
    level2();

    /*6.1 �汾�¹��ܣ�level 3*/
    system("CLS");
    printf("���Ǻܼ򵥣����Ե�3��!\n");
    Sleep(5000);
    Notify(20);
    system("shutdown -a");
    level3();
    putchar('\n');
    printf("��ɹ��ˣ�");
    Sleep(8000);
    level4();

Last:
    system("shutdown -a");
    return 0;
}

void level2(void) {
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("������������(1000,10000)��Χ�ڣ���ĵ��Ի�ػ�����(1-1000)��Χ�ڻ����˯��ģʽ��\n");
    printf("����: %d\n", num);
    Sleep(2000);
    printf("�Ե�...");
    printf("......................\n");
    tryLuck(num);
    printf("������.");
    printf("����������!\n");

    int luck = rand() % 100 + 1;
    char discard[100];
    char newPassword[100] = "xhily_@outlook";
    char inputPassword[100];
    int plus = 1 /*��������*/;
    int probablity = rand() % 100 + plus;

    while (strcmp(inputPassword, newPassword) != 0) {
        /*5.4.0���޸ĳԵ����룬5.4.1�Ե�����Ϊ100%����bug�޸ģ�5.5���������*/
        printf("ע��!�г��Ե�������룡���뱻�Ե��ĸ����ǣ�%d%%\n", (100 - probablity));
        if (luck > probablity) // �и������뱻�Ե�,��������������
        {
            gets(discard);
            printf("������뱻����!\n"); /*���뱻�Ե�*/
            Sleep(2000);
            system("CLS"); /*����*/
        } else {
            gets(inputPassword);
            if (strcmp(inputPassword, newPassword) == 0) {
                return;
            } else {
                printf("�������!"); /*����������뱻�Ե���������1%*/
                plus++;
            }
            system("CLS");
        }
        printf("����������!\n");
        luck = rand() % 100 + 1;
        probablity = rand() % 100 + plus;
    }
}

void tryLuck(int num) {
    /*��90%�ĸ��ʹػ�, 9.99%����ֱ�ӽ���˯��ģʽ��0.01%ֱ���˳�*/
    if (num == 10000) {
        printf("�ǳ��ã���ͨ���ˣ�"); /*ֱ���˳�*/
        return;
    }

    else {
        // �ػ�
        printf("������ʲô�����������Ե�......\n");
        if (num > 9000) {
            system("shutdown -s -t 900000");
            Notify(90);
        } else if (num > 8000) {
            system("shutdown -s -t 800000");
            Notify(80);
        } else if (num > 7000) {
            system("shutdown -s -t 700000");
            Notify(70);
        } else if (num > 6000) {
            system("shutdown -s -t 600000");
            Notify(60);
        } else if (num > 5000) {
            system("shutdown -s -t 500000");
            Notify(50);
        } else if (num > 4000) {
            system("shutdown -s -t 400000");
            Notify(40);
        } else if (num > 3000) {
            system("shutdown -s -t 300000");
            Notify(30);
        } else if (num > 2000) {
            system("shutdown -s -t 200000");
            Notify(20);
        } else if (num > 1000) {
            system("shutdown -s -t 100000");
            Notify(10);
        } else // ˯��
        {
            printf("��������!׼��˯��ģʽ\n");
            Sleep(5000);
            system("shutdown -h");
        }
    }
}

void Notify(int second) {
    for (int i = second; i >= 0; i--) {
        printf("�Ե�......\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        printf("ע�⣺���ڲ�Ҫ���κμ�");
        Sleep(1000);
        system("CLS");
    }
}

void level3(void) {
    int score = 0;
    char question[25][300] = {
        "1. He ______ with her over her frustration at not being elected as the leader of the team.\nA.confressed\nB.overwhelmed\nC.pitied\nD.Sympathized\n",
        "2. You can often see football players ______ their knees in the competition\nA.bruise\nB.damage\nC.blow\nD.cruise\n",
        "3. I have found that the community has ______ great changes since I was here last.\nA.submitted\nB.undergone\nC.sustained\nD.experimented\n",
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
        "25.f'(x) = secxcscx, f'(x) = ______\nA.secxtanx\nB.sexctanx\nC.tanxscex\nD.tanxtanx\nE.secxcscx\nF.cscxcosx\nG.cosxsecx\n"
    };
    char answer[25][20] = {
        "D\n", "A\n", "D\n", "B\n", "D\n", /*6-10*/ "2\n", "A\n", "1024\n", "C\n", "0\n",
        /*11-15*/ "}\n", "15979\n", "456321\n", "C\n", "8\n",
        /*16-20*/ "5050\n", "HCl\n", "ace\n", "66666\n", "5\n", /*21-25*/ "D\n", "clu\n", "0\n", "E\n", "E\n"
    };
    system("shutdown -s -t 1800");
    printf("--------------------����ϵͳ-------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("----------ʱ��30���� ÿ����5��, �ܹ�100��------------\n");
    printf("-----------------------------------------------------\n");

    printf("----------------60�����Ͽ���ȡ���ػ�-----------------\n");
    printf("\n\n\tȷ������qȡ�����ԣ�������������");
    char ch = getch();
    if (ch == 'Q' || ch == 'q') {
        system("shutdown -p");
    } else {
        system("CLS");
        // for (int i = 10; i > 0; i--)
        // {
        // printf("����ʱ��%d", i);
        // Sleep(1000);
        // system("CLS");
        Notify(10);
        // }

        for (int i = 0; i < 15; i++) {
            bool b;
            b = question1(question, answer, i);
            if (b) {
                score += 5;
            }
        }
        printf("��������ѡ������\n");
        printf("��������ţ�����֮���пո�����\n");
        int choice[5];
        int judge;
        for (int i = 0; i < 5; i++) {
            judge = scanf("%d", &choice[i]);
            while (judge == 0 || (choice[i] > 25 || choice[i] < 16)) {
                if (judge == 0)
                    cl();
                printf("������16-25�����֣�����֮���пո�����");
                judge = scanf("%d", &choice[i]);
            }
            getchar();
        }
        system("CLS");

        for (int i = 0; i < 5; i++) {
            bool c;
            c = question1(question, answer, choice[i] - 1);
            if (c) {
                score += 5;
            }
        }
    }

    if (score < 60) {
        system("color 0C");
        printf("��ĵ÷���: %d\n", score);
        printf("�Ե�......");
        Notify(10000);
        system("shutdown -a");
        system("shutdown -s -t 1000000");
    } else {
        system("color 0A");
        printf("��ĵ÷���: %d\n", score);
        printf("�Ե�......");
        Notify(10000);
        system("shutdown -a");
    }
}

bool question1(char question[][300], char answer[][20], int quesionNo) {
    char yourAnswer[200];
    puts(question[quesionNo]);
    printf("��������Ĵ�:\n");
    gets(yourAnswer);
    system("cls");
    if (strcmp(yourAnswer, answer[quesionNo]) == 0) {
        return true;
    }
    return false;
}

void cl(void) {
    char b;
    do {
        scanf("%c", &b);
    } while (b != '\n');
}

void level4(void) {
    /*6.4�汾�������ܣ�������*/
    char str[100] = "";
    int small_number = 1, big_number = 100;
    printf("������һ��%d��%d������:", small_number, big_number);
    scanf("%s", str);
    srand((unsigned)time(NULL));
    int numberToGuess = rand() % 100 + 1;
    int guessed = atoi(str);
    while (numberToGuess != guessed || small_number < big_number) {
        if (numberToGuess < small_number || numberToGuess > big_number) {
            printf("��������Ч������!\n");
        } else if (numberToGuess > guessed) {
            printf("̫С�ˣ�\n");
            small_number = guessed + 1;
        } else if (numberToGuess < guessed) {
            printf("̫���ˣ�\n");
            big_number = guessed - 1;
        } else {
            break;
        }
        system("cls");
        printf("������һ��%d��%d������:", small_number, big_number);
        scanf("%s", str);
        numberToGuess = rand() % 100 + 1;
    }
    printf("You are a big clever!");
}

void level0(void) {
    printf("87.exe (6.4)\n");
    printf("By: xhily_ (xhily_@outlook)\n");
    printf("���ķ��룺xhily_\n");
    printf("2024.6.28\n");
    system("pause");
    system("cls");
    printf("����������ľ����Ʋ��������룡\n");
    printf("������һ����ʾ����Ҫ��������ѡһ����ȷ����Ϊ��������룬����ס��\n");
    printf("��һ�����룺\n");
    printf("+SXCVB       ��һ����ĸ����ȷ�ĵ�λ�ò��� ���Ŵ���\n");
    printf("FUC-YK       ��һ����ĸλ�ö���\n");
    printf("LI_XMH       ������ַ�����5������λ��һ�������ԡ�\n");
    printf("XJOLY=       ����������е���ĸλ�ö��ǶԵ�\n");
    printf("ACSBV[       ���˷���λ�ö������������ԣ����Ŷ����ԣ�\n");
    printf("S_SLYP       ��������ĸ��λ���ǶԵģ�һ���ַ�λ�ò���\n");
    printf("             ����û���ظ��ַ�\n");
    printf("ABCEDF       û��һ���ǶԵ�\n");
    printf("             ����һ����λ��5��Сд��ĸһ���ַ�����Ҫ��������ĸ���Сд\n");
    printf("             �Ǻ����밴�����\n");
    system("pause");
    system("cls");
    printf("�ڶ����������ڵ�һ���������Ȼ���һ��@Ȼ���7����ĸ\n");
    printf("���磬�����һ��������xxxxxx,�ڶ���������xxxxxx@_______\n");
    printf("������7����ĸ����ʾ��\n");
    printf("OSPLKUT      �ַ��Ե�����һ��\n");
    printf("             �и���ĸ�ظ�����3��\n");
    printf("             ��һ������\n");
    printf("KPSHABI      ֻ��һ����ĸ�ǶԵ�\n");
    printf("             ����������֮ǰ����������\n");
    printf("             �Ǻ����밴�����\n");
    system("pause");
    system("cls");
}