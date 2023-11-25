/**
 *
 * By cquptstudent
 * Version 5.7
 * Date 2023 11 24 22:34
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
/*??????*/
void cl(void);
bool question1(char question[][300], char answer[][20], int quesionNo);
int main(void)
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
        "25.f'(x) = secxcscx, f'(x) = ______\nA.secxtanx\nB.sexctanx\nC.tanxscex\nD.tanxtanx\nE.secxcscx\nF.cscxcosx\nG.cosxsecx\n"};
    char answer[25][20] = {
        "D", "A", "D", "B", "D", /*6-10*/ "2", "A", "1024", "C", "0",
        /*11-15*/ "}", "15979", "456321", "C", "8",
        /*16-20*/ "5050", "HCl", "ace", "66666", "5", /*21-25*/ "D", "clu", "0", "E", "E"};
    system("shutdown -s -t 1800");
    printf("--------------------答题系统-------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("----------时间30分钟 每个题5分, 总共100分------------\n");
    printf("-----------------------------------------------------\n");

    printf("----------------60分以上可以取消关机-----------------\n");
    printf("\n\n\t确定？按q取消考试，按其他键继续");
    char ch = getch();
    if (ch == 'Q' || ch == 'q')
    {
        system("shutdown -p");
    }
    else
    {
        system("CLS");
        for (int i = 10; i > 0; i--)
        {
            printf("倒计时：%d", i);
            Sleep(1000);
            system("CLS");
        }

        for (int i = 0; i < 15; i++)
        {
            bool b;
            b = question1(question, answer, i);
            if (b)
            {
                score += 5;
            }
        }
        printf("接下来是选做部分\n");
        printf("请输入题号，数字之间有空格连接\n");
        int choice[5];
        int judge;
        for (int i = 0; i < 5; i++)
        {
            judge = scanf("%d", &choice[i]);
            while (judge == 0 || (choice[i] > 25 || choice[i] < 16))
            {
                if (judge == 0)
                    cl();
                printf("请输入16-25的数字，数字之间有空格连接");
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
        printf("你的得分是: %d\n", score);
        printf("Please wait......");
        Sleep(10000);
        system("shutdown -a");
        system("shutdown -s -t 1000");
    }
    else
    {
        system("color 0A");
        printf("你的得分是: %d\n", score);
        printf("Please wait......");
        Sleep(10000);
        system("shutdown -a");
    }

    return 0;
}

bool question1(char question[][300], char answer[][20], int quesionNo)
{
    char yourAnswer[200];
    puts(question[quesionNo]);
    printf("请输入你的答案:\n");
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