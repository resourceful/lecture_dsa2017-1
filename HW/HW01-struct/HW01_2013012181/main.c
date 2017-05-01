#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX_SIZE 100
char teamA[MAX_SIZE], teamB[MAX_SIZE];//변수선언
int teamnum, teamA_life, teamB_life, winner = 0, changeluk;
int i, k, j;
int y, n;
i = 0;
j = 0;
y = 0;
n = 0;
teamnum = 0;



typedef struct teamates//구조체를 이용하여 팀 데이터 선언
{
   char *teamname;
   int id;
   int weapon;
   int life;
} teamate;

void function(teamate member[], char name[], int num)//사용자가 입력한 만큼 함수를 이용하여 구성원 정보 부여
{
    int h;
    for (h = 0; h < num; h++)
    {
        member[h].teamname = name;
        member[h].id = h+1;
        member[h].weapon = (rand() % 3) + 1;
        member[h].life = 1;
    }
}

int main(void)//메인함수
{
    teamate *teamAA, *teamBB;
    srand(time(NULL));

    printf("--------------------------------------------------\n");
    printf("M:게임을 시작합니다.\n");
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("M:당신의 팀 이름은? : ");//본인 팀이름 받음
    gets(teamA);
    printf("M:상대의 팀 이름은? : ");//상대 팀이름 받음
    gets(teamB);
    printf("M:각 팀의 멤버수를 입력하시오 : ");//팀원수 받음
    scanf("%d", &teamnum);
    printf("\n");
    teamA_life = teamnum;//팀 전체 목숨은 팀인원수와 같다
    teamB_life = teamnum;//팀 전체 목숨은 팀인원수와 같다

    teamAA = (int *)malloc(teamnum * sizeof(teamate));//malloc을 이용하여 포인터변수 공간 할당
    teamBB = (int *)malloc(teamnum * sizeof(teamate));//malloc을 이용하여 포인터변수 공간 할당

   for (i = 0; i < teamnum; i++)//selection함수를 호출하여 각 팀 구성원 정보 부여
    {
        function(teamAA, teamA, teamnum);
        function(teamBB, teamB, teamnum);
    }
    printf("--------------------------------------------------\n");
    printf("M:다음은 당신의 팀의 정보입니다. (이 정보는 본인 팀만 열람할 수 있습니다.)\n");
    printf("M:무기는 가위(1), 바위(2), 보(3)입니다.\n");
    printf("--------------------------------------------------\n");
    printf("\n");

   for (i = 0; i < teamnum; i++)//for구문을 사용하여 본인팀 구성원별 정보 출력
    {
        printf("팀이름:%s, id:%d, 무기:%d, 목숨:%d\n", teamAA[i].teamname, teamAA[i].id, teamAA[i].weapon, teamAA[i].life);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    printf("M:다음은 상대 팀의 정보입니다. (이 정보는 본인 팀만 열람할 수 있습니다.)\n");
    printf("M:무기는 가위(1), 바위(2), 보(3)입니다.\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    for (k = 0; k < teamnum; k++)//for구문을 사용하여 상대팀 구성원별 정보 출력
    {
        printf("팀이름:%s, id:%d, 무기:%d, 목숨:%d\n", teamBB[k].teamname, teamBB[k].id, teamBB[k].weapon, teamBB[k].life);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("M:게임시작!!!!\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    j = 1;
    for (i = 0, k = 0; (i < teamnum) && (k < teamnum);)//for구문을 사용하여 가위바위보 게임 실행
    {
        printf("--------------------------------------------------\n");
        printf("M:제 %d차전!\n", j);
        printf("M:가위 바위 보!\n");
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");

        if ((teamAA[i].weapon == 1) && (teamBB[k].weapon == 3))//1 : A팀이 이기고 B팀이 질경우(가위-보)
        {
            teamBB[k].life = 0;//B팀 한명을 잃음
            printf("\n");
            printf("M:A[%d]가 이겼습니다!\n", i);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamAA[i].weapon = teamBB[k].weapon;//팀A[i] 무기가 팀B[k]무기로 바뀜
                    printf("M:A[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B팀 선수 교체
                    teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                k = k + 1;//B팀 선수 교체
                teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
            }
        }

        else if ((teamAA[i].weapon == 2) && (teamBB[k].weapon == 1))//2 : A팀이 이기고 B팀이 질경우(바위-가위)
        {
            teamBB[k].life = 0;//B팀 한명을 잃음
            printf("\n");
            printf("M:A[%d]가 이겼습니다!\n", i);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamAA[i].weapon = teamBB[k].weapon;//팀A[i] 무기가 팀B[k]무기로 바뀜
                    printf("M:A[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B팀 선수 교체
                    teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                k = k + 1;//B팀 선수 교체
                teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
            }
        }

        else if ((teamAA[i].weapon == 3) && (teamBB[k].weapon == 2))//3 : A팀이 이기고 B팀이 질경우(보-바위)
        {
            teamBB[k].life = 0;//B팀 한명을 잃음
            printf("\n");
            printf("M:A[%d]가 이겼습니다!\n", i);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamAA[i].weapon = teamBB[k].weapon;//팀A[i] 무기가 팀B[k]무기로 바뀜
                    printf("M:A[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B팀 선수 교체
                    teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                k = k + 1;//B팀 선수 교체
                teamB_life = teamB_life - 1;//팀B 목숨 하나 잃음
            }
        }

        else if ((teamAA[i].weapon == 1) && (teamBB[k].weapon == 2))//4 : A팀이 지고 B팀이 이길경우(가위-바위)
        {
            teamAA[i].life = 0;//A팀 한명을 잃음
            printf("\n");
            printf("M:B[%d]가 이겼습니다!\n", k);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamBB[k].weapon = teamAA[i].weapon;//팀B[k] 무기가 팀A[i]무기로 바뀜
                    printf("M:B[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A팀 선수 교체
                    teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                i = i + 1;//A팀 선수 교체
                teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
            }
        }

        else if ((teamAA[i].weapon == 2) && (teamBB[k].weapon == 3))//5 : A팀이 지고 B팀이 이길경우(바위-보)
        {
            teamAA[i].life = 0;//A팀 한명을 잃음
            printf("\n");
            printf("M:B[%d]가 이겼습니다!\n", k);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamBB[k].weapon = teamAA[i].weapon;//팀B[k] 무기가 팀A[i]무기로 바뀜
                    printf("M:B[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A팀 선수 교체
                    teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                i = i + 1;//A팀 선수 교체
                teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
            }
        }

        else if ((teamAA[i].weapon == 3) && (teamBB[k].weapon == 1))//6 : A팀이 지고 B팀이 이길경우(보-가위)
        {
            teamAA[i].life = 0;//A팀 한명을 잃음
            printf("\n");
            printf("M:B[%d]가 이겼습니다!\n", k);
            printf("M:무기를 바꾸시겠습니까?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//무기를 바꿀 경우
            {
                changeluk = (rand() % 2);//승자의 무기를 바꿀 50%의 확률 결정

                if (changeluk == 0)//무기를 바꿉니다
                {
                    teamBB[k].weapon = teamAA[i].weapon;//팀B[k] 무기가 팀A[i]무기로 바뀜
                    printf("M:B[%d]의 무기가 '%d'로 바뀌었습니다.(이 정보는 본인 팀만 열람할 수 있습니다.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A팀 선수 교체
                    teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
                }
            }

            else if(y == 1);//무기를 안바꿀 경우
            {
                i = i + 1;//A팀 선수 교체
                teamA_life = teamA_life - 1;//팀A 목숨 하나 잃음
            }
        }

        else if (teamAA[i].weapon == teamBB[k].weapon)//7 : 비길경우
        {
            printf("M:비겼습니다!\n");
            printf("\n");
            printf("M:무기 재배정!\n");
            teamAA[i].weapon = (rand() % 3) + 1;//팀A 무기변경
            teamBB[k].weapon = (rand() % 3) + 1;//팀B 무기변경
        }
        j = j + 1;//다음 게임으로
    }

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("M:결과!!!!\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    for (i = 0; i < teamnum; i++)//게임후 팀A 구성원 정보 출력
      {
        printf("팀이름:%s, id:%d, 무기:%d, 목숨:%d\n", teamAA[i].teamname, teamAA[i].id, teamAA[i].weapon, teamAA[i].life);
        printf("\n");
      }

    for (k = 0; k < teamnum; k++)//게임후 팀B 구성원 정보 출력
      {
        printf("팀이름:%s, id:%d, 무기:%d, 목숨:%d\n", teamBB[k].teamname, teamBB[k].id, teamBB[k].weapon, teamBB[k].life);
        printf("\n");
      }

    if (teamA_life == teamB_life)//비길경우 문구 출력
        printf("M:비겼습니다!\n");
    else//승부가 결정날 경우
        winner = (teamA_life < teamB_life) ? 1 : -1;

    if (winner > 0)//팀B가 이길경우 승리문구 출력
        printf("M:이긴 팀은! %s!\n", teamB);
    else if (winner < 0)//팀A가 이길경우 승리문구 출력
        printf("M:이긴 팀은! %s!\n", teamA);

    //malloc 해제
    free(teamAA);
    free(teamBB);

    return 0;
}
