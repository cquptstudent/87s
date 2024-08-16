/**
 *
 * @author xhily_
 * Version 6.4
 * Date 2024 6 28 0:16
*/
/*
 * 6.3版本更新：延长时间，加入中文
 * 第一关密码：xhily_
 * 第二关密码：xhily_@outlook
 *
 * 6.4版本更新：加入密码提示
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
    char answer[100] = "xhily_"; /*密码*/
    int try_time = 0;
    int shutdownTime_first = 12000000;
    level0();
    // time = shutdownTime_first;
    char str[100];
    sprintf(str, "shutdown -sg -t %d", shutdownTime_first);
    system(str); /*关机12000秒*/
    do {
        printf("你的电脑将在%d秒内关机\n", time);
        for (int i = 0; i < (2000 - time); i++) /*输入2000-time个星号*/
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
        printf("请输入密码:");
        gets(a); /*输入密码*/
        for (int i = 0; i < 50; i++) {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        try_time++;
        /*密码错误1次: 时间变成1100s
        密码错误2次: 时间变成1000s
        密码错误3次: 时间变成900s
        密码错误4次: 时间变成800s
        密码错误5次: 时间变成300s
        密码错误6次: 时间变成60s
        密码错误7次: 时间变成30s
        8次及以上: 每次10s
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
            printf("密码错误!");
        } else {
            break;
        }
        system("CLS"); /*清除屏幕*/
        printf("继续?\n退出请按'n'或'N'，继续请按其他键\n");
        char choice = _getch(); /*输入选项*/
        if (choice == 'N' || choice == 'n') {
            printf("不要放弃！ 真的要退出吗？按'Y' 或 'y' 退出.\n");
            choice = _getch();
            if (choice == 'Y' || choice == 'y') {
                printf("真的吗?\n");
                system("shutdown -s -t 1000000"); /*5.3版本修改: 解决shutdown -a不能解决取消的问题*/
                for (int i = 10; i >= 0; i--) /*倒计时 10s*/
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                goto Last;
            }
        }
    } while (strcmp(a, answer) != 0);
    printf("密码正确!\n"); /*第1关结束*/
    system("shutdown -a");
    /*5.4新版本：增加lv2*/
    Sleep(2000); /*休息2s*/
    printf("是不是太简单了?");
    Sleep(2000); /*休息2s*/
    system("CLS");
    for (int i = 20; i > 0; i--) {
        printf("第二关！\n");
        /*5.5新修改: lv2界面改变*/
        printf("稍等...\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
    level2();

    /*6.1 版本新功能：level 3*/
    system("CLS");
    printf("还是很简单？试试第3关!\n");
    Sleep(5000);
    Notify(20);
    system("shutdown -a");
    level3();
    putchar('\n');
    printf("你成功了！");
    Sleep(8000);
    level4();

Last:
    system("shutdown -a");
    return 0;
}

void level2(void) {
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("如果这个数字在(1000,10000)范围内，你的电脑会关机。在(1-1000)范围内会进入睡眠模式。\n");
    printf("数字: %d\n", num);
    Sleep(2000);
    printf("稍等...");
    printf("......................\n");
    tryLuck(num);
    printf("到你了.");
    printf("请输入密码!\n");

    int luck = rand() % 100 + 1;
    char discard[100];
    char newPassword[100] = "xhily_@outlook";
    char inputPassword[100];
    int plus = 1 /*概率增加*/;
    int probablity = rand() % 100 + plus;

    while (strcmp(inputPassword, newPassword) != 0) {
        /*5.4.0新修改吃掉密码，5.4.1吃掉密码为100%概率bug修改，5.5增加随机数*/
        printf("注意!有虫会吃掉你的密码！密码被吃掉的概率是：%d%%\n", (100 - probablity));
        if (luck > probablity) // 有概率密码被吃掉,这个概率是随机数
        {
            gets(discard);
            printf("你的密码被吃了!\n"); /*密码被吃掉*/
            Sleep(2000);
            system("CLS"); /*清屏*/
        } else {
            gets(inputPassword);
            if (strcmp(inputPassword, newPassword) == 0) {
                return;
            } else {
                printf("密码错误!"); /*密码错误，密码被吃掉概率增加1%*/
                plus++;
            }
            system("CLS");
        }
        printf("请输入密码!\n");
        luck = rand() % 100 + 1;
        probablity = rand() % 100 + plus;
    }
}

void tryLuck(int num) {
    /*有90%的概率关机, 9.99%概率直接进入睡眠模式，0.01%直接退出*/
    if (num == 10000) {
        printf("非常好，你通过了！"); /*直接退出*/
        return;
    }

    else {
        // 关机
        printf("你现在什么都不能做，稍等......\n");
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
        } else // 睡眠
        {
            printf("运气不错!准备睡眠模式\n");
            Sleep(5000);
            system("shutdown -h");
        }
    }
}

void Notify(int second) {
    for (int i = second; i >= 0; i--) {
        printf("稍等......\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        printf("注意：现在不要按任何键");
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
        "8. 2的10次方是:______\n",
        "9. f'(x) = cscxcotx, f'(x) = ______\nA.-cotx\nB.cotx\nC.cscxcotx\nD.不会\nE.cssxctox\n",
        "10.f(x) = x, f'''(x) = ______\n",
        "11.\n#include <iostream>\nusing namespace std;\nint main()\n{\n\tint i = 0;\n\tcout << i;\n\treturn 0;\n______\n填空：",
        "12.\nint a= (int)((float)(3.4*3.4) + 0.7 * (long)5234567878) %% (int)((float) 3.5 * (unsigned)23345 / 3.4);\nprintf(\"%d\", a);\n最后的a=______\n",
        "13.进制转换: 6F681(16进制)转换成10进制: ______\n",
        "14.在文件87(5.5.2).exe中,出现过哪一行代码\nIn the file 87\nA.#inlcude<stdio.h>\nB.system(pause)\nC.return 0;\nD.fxxk you\nE.没见过87(5.5.2).exe\n",
        "15.\nint i = 0;\nprintf(\"%d\", ++i);\ni++;\ni+=i*=2;\ni = ______",
        "16.1+2+3+4+5+6+7+...+100 = ______\n",
        "17.H2+Cl2 = ______\n",
        "18.\n#include <iostream>\nusing namesp___ std;\n{\n}\n应该填\n",
        "19.12345+54321=______\n",
        "20.-(-(-(-(-(-(-(-(-(-(-(-5))))))))))) = ______\n",
        "21.y=sinx, x=______\nA.arcsix\nB.arcosx\nC.arssinx\nD.arcsinx\nE.arcsin\nF.arsond\nG.arccotanx\nH.Arcsins\n",
        "22.#in___de <iostream>\n",
        "23.1-1+1-1+1-1+1-1+1-1=______\n",
        "24.第一题是什么科目的题?\nA.C\nB.C++\nC.Java\nD.Kotlin\nE.English\nF.Chinese\nG.Html\n",
        "25.f'(x) = secxcscx, f'(x) = ______\nA.secxtanx\nB.sexctanx\nC.tanxscex\nD.tanxtanx\nE.secxcscx\nF.cscxcosx\nG.cosxsecx\n"
    };
    char answer[25][20] = {
        "D\n", "A\n", "D\n", "B\n", "D\n", /*6-10*/ "2\n", "A\n", "1024\n", "C\n", "0\n",
        /*11-15*/ "}\n", "15979\n", "456321\n", "C\n", "8\n",
        /*16-20*/ "5050\n", "HCl\n", "ace\n", "66666\n", "5\n", /*21-25*/ "D\n", "clu\n", "0\n", "E\n", "E\n"
    };
    system("shutdown -s -t 1800");
    printf("--------------------答题系统-------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("----------时间30分钟 每个题5分, 总共100分------------\n");
    printf("-----------------------------------------------------\n");

    printf("----------------60分以上可以取消关机-----------------\n");
    printf("\n\n\t确定？按q取消考试，按其他键继续");
    char ch = getch();
    if (ch == 'Q' || ch == 'q') {
        system("shutdown -p");
    } else {
        system("CLS");
        // for (int i = 10; i > 0; i--)
        // {
        // printf("倒计时：%d", i);
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
        printf("接下来是选做部分\n");
        printf("请输入题号，数字之间有空格连接\n");
        int choice[5];
        int judge;
        for (int i = 0; i < 5; i++) {
            judge = scanf("%d", &choice[i]);
            while (judge == 0 || (choice[i] > 25 || choice[i] < 16)) {
                if (judge == 0)
                    cl();
                printf("请输入16-25的数字，数字之间有空格连接");
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
        printf("你的得分是: %d\n", score);
        printf("稍等......");
        Notify(10000);
        system("shutdown -a");
        system("shutdown -s -t 1000000");
    } else {
        system("color 0A");
        printf("你的得分是: %d\n", score);
        printf("稍等......");
        Notify(10000);
        system("shutdown -a");
    }
}

bool question1(char question[][300], char answer[][20], int quesionNo) {
    char yourAnswer[200];
    puts(question[quesionNo]);
    printf("请输入你的答案:\n");
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
    /*6.4版本新增功能：猜数字*/
    char str[100] = "";
    int small_number = 1, big_number = 100;
    printf("请输入一个%d到%d的数字:", small_number, big_number);
    scanf("%s", str);
    srand((unsigned)time(NULL));
    int numberToGuess = rand() % 100 + 1;
    int guessed = atoi(str);
    while (numberToGuess != guessed || small_number < big_number) {
        if (numberToGuess < small_number || numberToGuess > big_number) {
            printf("请输入有效的数字!\n");
        } else if (numberToGuess > guessed) {
            printf("太小了！\n");
            small_number = guessed + 1;
        } else if (numberToGuess < guessed) {
            printf("太大了！\n");
            big_number = guessed - 1;
        } else {
            break;
        }
        system("cls");
        printf("请输入一个%d到%d的数字:", small_number, big_number);
        scanf("%s", str);
        numberToGuess = rand() % 100 + 1;
    }
    printf("You are a big clever!");
}

void level0(void) {
    printf("87.exe (6.4)\n");
    printf("By: xhily_ (xhily_@outlook)\n");
    printf("中文翻译：xhily_\n");
    printf("2024.6.28\n");
    system("pause");
    system("cls");
    printf("现在你该做的就是推测两个密码！\n");
    printf("以下是一堆提示，你要在这里面选一个正确的作为后面的密码，并记住。\n");
    printf("第一个密码：\n");
    printf("+SXCVB       有一个字母是正确的但位置不对 符号错误\n");
    printf("FUC-YK       有一个字母位置对了\n");
    printf("LI_XMH       这次是字符对了5个但是位置一个都不对。\n");
    printf("XJOLY=       这次密码中有的字母位置都是对的\n");
    printf("ACSBV[       除了符号位置对了其他都不对（符号都不对）\n");
    printf("S_SLYP       有两个字母的位置是对的，一个字符位置不对\n");
    printf("             密码没有重复字符\n");
    printf("ABCEDF       没有一个是对的\n");
    printf("             密码一共六位，5个小写字母一个字符，需要把所有字母变成小写\n");
    printf("             记好了请按任意键\n");
    system("pause");
    system("cls");
    printf("第二个密码是在第一个密码后面然后加一个@然后加7个字母\n");
    printf("例如，如果第一个密码是xxxxxx,第二个密码是xxxxxx@_______\n");
    printf("以下是7个字母的提示：\n");
    printf("OSPLKUT      字符对的最多的一个\n");
    printf("             有个字母重复出现3次\n");
    printf("             是一个单词\n");
    printf("KPSHABI      只有一个字母是对的\n");
    printf("             所有密码我之前都告诉你了\n");
    printf("             记好了请按任意键\n");
    system("pause");
    system("cls");
}