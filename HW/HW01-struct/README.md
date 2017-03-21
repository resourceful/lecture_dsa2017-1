# Assignment 1 - Stone Paper Scissor Game
## Team members
Each user has ID, a weapon, a life. The user is in a team. Following is the data structure to represent the player. You may optimize the given data structure.
```
typedef struct teamates {
    char *teamname;
    int id;
    int weapon;
    int life;
} teamate;
```

## Starting a game
Before beginning the game, the player has to decide 
1. the player’s team name
2. the opponent’s team name
3. number of players in each team

Each teammate is randomly given one of following three weapons. The game master notifies which weapon each players received, but not the weapons of opponents. The weapons are as follows:
* Weapon #1: Scissor
* Weapon #2: Stone
* Weapon #3: Paper

## The game
Always the number 1 player in user’s team starts the game. The user chooses the player in the opponent’s team to play the game. The player cannot choose an opponent player with zero life. 

The rule of the game is simply.
* Scissor wins paper
* Stone wins scissor
* Paper wins stone
* The same weapon draws

## The winner
The user can choose to exchange the weapon with the looser’s weapon. When the user decides to exchange the weapon, the user has 50% chance of successfully exchanging the weapon. The game master notifies the user about the weapon now the user possesses.

## The looser
The lost player can no longer participate in the game. The next player plays the game. The looser’s team does not know if the winner has successfully exchanged the weapon. 

## The tie game
The both players randomly chooses a weapon and replays the game. 

## The end game
After all the players played the game, the game master counts the number of lives for each team. The team with more lives is the winner

## Managerial information
Create your directory with your student ID under HW01 directory.  For example, the student ID of 1004 and 2048 is uploading their works. Directory structure will be as follows:
 —HW01
  |_ HW01_1004
  |_ HW01_2048

The student must provide *Makefile*, *C source code* with sufficient comments, and other necessary *files to successfully compile* and run the program. All filenames must be in English. 

The students must also provide the report in either doc or hwp format. The report must include the programming environments such as version of OS, version of the compiler, and system specification. It must also include the purpose, design of the program, and brief description of the data structure and the algorithm. It is recommend to provide Time and Space complexity of the program. The screen capture of the running program with description must be included in the report as well. 

**No late submission.** 

## Code of conduct
If you are found cheating, the person who gave the work and the person who copied the work will given a zero for the assignment. 

## Deadline
The work must be uploaded to the system within two weeks of time counting the day of the announcement. 

## The Score
* **10 points:** Program compiles and runs successfully. Report with all the required information, Makefile, c and other related files uploaded on time. 
* **5 points:** Program does not compile or does not run as required.  Report with all the required information, Makefile, c and other related files uploaded on time. 
* **2 points:** Program does not compile or does not run as required. Required files are partially uploaded on time.
* **0 points:** files are not uploaded on time. Or, cheat others work (O points for the person who gave the work as well)


_adopted from HYU course_
