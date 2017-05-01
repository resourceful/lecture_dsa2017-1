typedef struct teammates{
	char teamname[100];
	int id;
	int weapon;
	int life;
}teammates;


teammates* make_team(int);

int fight(teammates* player,teammates* computer,int i,int k);

int lifecheck(teammates* player,teammates* computer,int i,int k);

int sumscore(teammates* player,int playernum);

void WhatWeapon(int weapon);

void print_info(teammates* player,int index,int distinguish);
