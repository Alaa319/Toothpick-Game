#define ROUNDS 3//defining ROUNDS as 3, so that the players can only play up to 3 games
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting();
int playRound(int round); //play one round
int humanPick(); //retrieve the user's guess
int computerPick(int choice, int leftover); //computer makes its pick
int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
void winnerAnnouncment(int user); //overall winner of round announcement

int main()
{
	greeting();//greeting the players and stating the rules 
	
	for(int x = 0; x < ROUNDS; ++x)//creating a loop so that the players can play up to 3 games
	{
		int result = playRound(x + 1); //calling playRound
		winnerAnnouncment(result);//passing by result
	}

	printf("********************************************************\n");
	printf("Thank you for playing!\n");//Saying goodbye!
	printf("********************************************************\n");
	
	return 0;
}

/*
Function 1: 
-Welcomes players to the game
-states the rules
*/
void greeting()
{
    printf("This is the Toothpick Game. Play at your own risk!\n");
	printf("********************************************************\n");
    printf("How the game works:\n");
    printf("1) There are 31 toothpicks on the table.\n"); 
    printf("2) We will be taking turns taking either 1, 2, or no more than 3 toothpicks off the table at a time.\n");
    printf("3) Whoever picks up the last toothpick looses the game.\n");
    printf("Good luck and here we go!\n");
	printf("********************************************************\n");

}

/*
Function 2: 
-the actual playing of the game
*/
int playRound(int round)
{
	printf("Welcome to a new round %d!\n", round);//stating the number round we are in
	printf("You may go first!\n");//telling the human that they are going first 
		
	int toothpicks = 31; //number of toothpicks to start with
	//declaring the different variables
	int choice; 
	int leftover; 
	int taken; 
	int user; 

	printf("********************************************************\n");

	while(toothpicks != 0)//keeps track of toothpicks until respective no more toothpicks left
	{
		printf("Number of toothpick(s) on table: %d\n", toothpicks);//stating number of toothpicks left on the table

		int human = humanPick();// declaring a variable and assigning that variable to humanPick() function
		
		if(human >= 1 && human <= 3 && human <= toothpicks)//stating the conditions of the game 
		{
			toothpicks = leftOnTable(toothpicks, human); 

			if(toothpicks == 0)
			{
				return 1; 
			}

			int option = computerPick(human, toothpicks);//declaring a variable and assigning that variable to computerPick() function

			toothpicks = leftOnTable(toothpicks, option); 

			if(toothpicks == 0)
			{
				return 2; 
			} 

			printf("********************************************************\n");
		}

		else if(human < 1 || human >= 4 || human > toothpicks)
		{
			printf("BREACH OF RULES!\tBREACH OF RULES!\tBREACH OF RULES!\n"); 
			printf("********************************************************\n");
		}
		
	}
	
	return 0;
}

/*
Function 3: 
-allowing the user to choose the number of toothpicks they want to take off the table 
*/
int humanPick()
{
	int h; 

	printf("Enter the number of toothpicks you want to take off the table: ");
	scanf("%d", &h);

	return h; 
}


/*
Function 4: 
-stating the conditions that the computer can choose 
-stating what the computer chose 
-returning the value
*/
int computerPick(int choice, int leftover)
{
	int option; 
	if(leftover > 4)
	{
		option = 4 - choice; 
	}
	else if(leftover >= 2 && leftover <= 4)
	{
		option = leftover - 1; 
	}

	else if(leftover == 1)
	{
		option = 1; 
	}

	printf("I want to take %d toothpicks off the table.\n", option);

	return option; 

}


/*
Function 5: 
-counting the number of toothpicks on the table 
*/
int leftOnTable(int toothpicks, int taken)
{
	return toothpicks - taken; 

}

/*
Function 6: 
-announcing who won the game
*/
void winnerAnnouncment(int user)
{
	if(user == 2)
	{
		printf("You won! I'll let you have this one.\n"); 
		printf("********************************************************\n");
	}

	else if(user == 1)
	{
		printf("I won! Haha better luck next time!\n"); 
		printf("********************************************************\n");
	}
}