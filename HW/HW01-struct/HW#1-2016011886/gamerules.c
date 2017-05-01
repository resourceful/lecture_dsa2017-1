#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gamerules.h"
#define MALLOC(s,p)\
	if(!((s) = malloc(p)))\
		printf("error");\
//gamerules.c
teammates* make_team(int N)
{
	int i;
	teammates* player;
	MALLOC(player,sizeof(teammates)*N)
	printf("input team name: ");
	scanf("%s",player[0].teamname);
	
	for(i =0;i<N;i++)
	{
		strcpy(player[i].teamname,player[0].teamname);
		player[i].weapon = rand()%3+1;
		player[i].life = 1;
		player[i].id = i;
	}
	return player;
}

int lifecheck(teammates* player,teammates* computer,int i,int k)
{
				int result;
	if(!player[i].life||!computer[k].life)
	{
			  //who is dead???
			  if(!player[i].life)
						 result = -1;//player is dead return -1
			  if(!computer[i].life)
						 result = -2;//computer is dead return -2
			  if(!player[i].life&&!computer[k].life)
						 result = -3;//both is dead return -3
			  return result;
	}
	else
	{
					result = 1;//no one dead
					return result;
	}

}


int fight(teammates* player,teammates* computer,int i,int k)
{
	int result, coin;
	char yn;
	if((result=lifecheck(player,computer,i,k))<0)
	{
					return result; //some player is dead
	}
	
	do{
		result = player[i].weapon - computer[k].weapon;

		//player win the game
		if(result==-1||result==2)
		{
						srand(time(NULL));
						computer[k].life = 0;
						printf("player win\n");
						print_info(player,i,1);
						printf("\n");
						printf("exchange the weapon[y/n]");
				  	scanf("%c",&yn);
				  	getchar();
				  	coin = rand()%2;
						if(yn=='y'&&coin)
						{
										printf("changed to ");
										WhatWeapon(player[i].weapon);
										player[i].weapon = computer[k].weapon;
										printf("-->");
										WhatWeapon(player[i].weapon);
										printf("\n");
						}
				  return 1;//player win:return 1
		}

		//player lose the game
		if(result==1||result==-2)
		{
					printf("player lose\n");
					print_info(computer,k,0);
					player[i].life = 0;
				  return 0;//player lose:return 0
		}
		printf("tie game\n");
		//warning!!  the weapon is changed!!!
		player[i].weapon = rand()%3+1;
		computer[k].weapon = rand()%3+1;

	}while(!result);
 return -7;//this value meaning nothing
}

int sumscore(teammates* player,int playernum)//sum player's all life
{
		  int i,sum;
		  sum = 0;
		  for (i = 0; i<playernum;i++)
					 sum += player[i].life;
		  return sum;
}

void WhatWeapon(int weapon)//definition of weapon
{
				if(weapon==1)
								printf("Rock");//1 is Rock
				if(weapon==2)
								printf("Scissor");//2 is Scisser
				if(weapon==3)
								printf("Papper");//3 is Papper
				return;
}

void print_info(teammates* player,int index,int distinguish)
{
				if(distinguish)//distinguish is 1 then show weapon
				{
								printf("team: %s\tid: %d\tweapon: ",player[0].teamname,player[index].id);
								WhatWeapon(player[index].weapon);
								printf("\tlife: %d",player[index].life);
								printf("\n");
								return;
				}

				else//distinguish is 0 then hide weapon
				{
								printf("team: %s\tid: %d",player[0].teamname,player[index].id);
								printf("\tlife: %d",player[index].life);
								printf("\n");
								return;
				}
}

