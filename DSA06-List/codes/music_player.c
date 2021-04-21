typedef struct music 
{
	char musicName[15]; 
	struct music *backMusic;
	struct music *frontMusic;
} Music;

Music *headerPointer;
Music *currentMusic;

int main(void)
{
	int i;

	initMusic();
	currentMusic = headerPointer;
	char command[10];

	//Code is required.

	allFree();
	return 0;
}

void initMusic()
{
	headerPointer = (Music *)malloc(sizeof(Music));
	headerPointer -> backMusic = headerPointer;
	headerPointer -> frontMusic = headerPointer;
}

void playMusic()
{
	//Code is required.
}

void Next()
{
	//Code is required.
}


void Back()
{
	//Code is required.
}


void addMusic()
{
	char newdata[15];
	scanf("%s", newdata);
	Music *newMusic;
	newMusic = (Music *)malloc(sizeof(Music));

	//Code is required.
}


void deleteMusic()
{
	if(headerPointer -> frontMusic == headerPointer)
	{
		printf("There is no music here\n");
	}
	else
	{
		Music *deletePointer;
		deletePointer = currentMusic;

		//Code is required.

		free(deletePointer);
	}
}

void allFree()
{
	Music *iter = headerPointer;
	Music *iterNext = NULL;
	do {
		iterNext = iter -> frontMusic;
		free(iter);
		iter = iterNext;
	} while(iter != headerPointer);

	printf("____________________\n\n");
}
