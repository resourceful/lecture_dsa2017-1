#include <stdio.h>
#include <stdlib.h>
#include "gamerules.h"
#define MALLOC(s,p)\
	if(!((s) = malloc(p)))\
		printf("error");\

//game.c
int main(void)
{
	int playernum,comnum,playern,comn,i;
	teammates *play,*com;
	printf("input players number: ");
	scanf("%d",&playernum);
	play = make_team(playernum);//make player's team
	printf("input computers number: ");
	scanf("%d",&comnum);
	com = make_team(comnum);//make computer's team
	playern = playernum;//save max index
	comn = comnum;//save max index
	while(playernum >= 0 && comnum >= 0)
	{
		i = fight(play, com, playernum, comnum);
		if(i==-1)//player is dead so change the index
		{
				  playernum--;
		}
		else if(i==-2)//computer is dead so change the index
		{
				  comnum--;
		}
		else if(i==-3)//both is dead so change the index
		{
				  playernum--;
				  comnum--;
		}
		else if(i)//player is win
		{
			comnum--;//opponent is dead so change the opponent
		}
		else//player is lose so change the player
		{
			playernum--;
		}
	}
	playernum = sumscore(play,playern);//save scores into "playernum" variation
	comnum = sumscore(com,comn);//save scores into "comnum" variation
	if(playernum == comnum)//tie game when the score is same
	{
			  printf("tie");
			  return 0;
	}
	if(playernum>comnum)//player is win print the info about player
	{

		 printf("\n%s is win\n",play[0].teamname);
		 for(i = 0;i<playern;i++)
		 {
						 print_info(play,i,1);
		 }
		 printf("\nscore: %d",playernum);
	}

	if(playernum<comnum)//player is lose print the info about computer
	{
		 printf("\n%s is win\n",com[0].teamname);
		 for(i = 0;i<comn;i++)
		 {
						 print_info(com,i,1);
		 }
		 printf("\nscore: %d",comnum);
	}
	free(play);
	free(com);
	return 0;
}
