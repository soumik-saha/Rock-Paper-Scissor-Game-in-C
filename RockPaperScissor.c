/*Rock-Paper-Scissor Game in C programming*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int StonePaperScissor(char user, char pc) // Declaration of RockPaperScissor Function
{
    /*  
        return 1 if user win
        return -1 if user lose
        return 0 if drawn
    */
    if(user == pc) // for drawn 
    {
        return 0; // Drawn
    }
    /*
    Cases:
    Case 1 - if user choose Rock and pc choose Paper
    Case 2 - if user choose Rock and pc choose Scissor
    Case 3 - if user choose Paper and pc choose Rock
    Case 4 - if user choose Paper and pc choose Scissor
    Case 5 - if user choose Scissor and pc choose Rock
    Case 6 - if user choose Scissor and pc choose Paper
    */
    else if(user == 'r' && pc == 'p') // Case 1
    {
        return -1; // User Lose and PC Win 
    }
    else if(user == 'r' && pc == 's') // Case 2
    {
        return 1; // User Win and PC Lose  
    }
    else if(user == 'p' && pc == 'r') // Case 3
    {
        return 1; // User Win and PC Lose       
    }
    else if(user == 'p' && pc == 's') // Case 4
    {
        return -1; // User Lose and PC Win    
    }
    else if(user == 's' && pc == 'r') // Case 5
    {
        return -1; // User Lose and PC Win    
    }
    else if(user == 's' && pc == 'p') // Case 6
    {   
        return 1; // User Win and PC Lose
    }
}

int main() // Main Function
{
    printf("*****WELCOME TO ROCK-PAPER-SCISSOR GAME*****\n\n");

    // Variable Declaration

    char user, pc;
    int countPlayed = 0, countWin = 0, countLose = 0, countDrawn = 0;
    char name[50];
    
    // Username 
    
    printf("User Name : ");
    scanf("%s",&name);

    Replay: // Declare a label (It will use in Line 178)
    countPlayed++; // Increment countPlayed
    
    // Generate Random Numbers as a choice of PC

    srand(time(0));
    int number = rand()%3 + 1;

    // Conditions for getting equal probability of choice of PC
    
    if (number == 1)
    {
        pc = 'r';
    }
    else if (number == 2)
    {
        pc = 'p';
    }
    else if (number == 3)
    {
        pc = 's';
    }
    
    // Choices for user

    printf("\nr for Rock\np for Paper\ns for Scissor\n");
    printf("\nEnter Your Choice: ");
    fflush(stdin);
    user = getchar();

    // Call StonePaperScissor function

    int result = StonePaperScissor(user,pc);

    // Conditions for printing the choices of User and PC

    if (user == 'r') // When user choose Rock
    {
        if (pc == 'r') // When PC choose Rock 
        {
            printf("\nYou chose Rock\nComputer chose Rock\n\n");
        }
        else if (pc == 'p') // When PC choose Paper
        {
            printf("\nYou chose Rock\nComputer chose Paper\n\n");
        }
        else if (pc == 's') // When PC choose Scissor
        {
            printf("\nYou chose Rock\nComputer chose Scissor\n\n");
        }
    }
    else if (user == 's') // When user choose Scissor
    {
        if (pc == 'r') // When PC choose Rock
        {
            printf("\nYou chose Scissor\nComputer chose Rock\n\n");
        }
        else if (pc == 'p') // When PC choose Paper
        {
            printf("\nYou chose Scissor\nComputer chose Paper\n\n");
        }
        else if (pc == 's') // When PC choose Scissor
        {
            printf("\nYou chose Scissor\nComputer chose Scissor\n\n");
        }
    }
    else if (user = 'p') // When user choose Paper
    {
        if (pc == 'r') // When PC choose Rock
        {
            printf("\nYou chose Paper\nComputer chose Rock\n\n");
        }
        else if (pc == 'p') // When PC choose Paper
        {
            printf("\nYou chose Paper\nComputer chose Paper\n\n");
        }
        else if (pc == 's') // When PC choose Scissor
        {
            printf("\nYou chose Paper\nComputer chose Scissor\n\n");
        }
    }
    
    // Conditions for printing result

    if (result == 1) // Winning of User
    {
        printf("Congratulations, you have won this game.\n");
        countWin++; // Increment countWin
    }
    else if (result == -1) // Losing of User
    {
        printf("Oops, You have lost this game.\n");
        countLose++; // Increment countLose
    }
    else if(result == 0) // Match Drawn
    {
        printf("This game is drawn.\n");
        countDrawn++; // Increment countDrawn
    }

    // Replay Or Exit the game

    int roe; // roe stands for <Replay Or Exit>
    printf("\nReplay:\tPress [1]\n");
    printf("Exit:\tPress [2]\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&roe);

    if (roe == 1) // If user to play again <Replay>
    {
        printf("\nYou have chosen to play this game again!\n\n");
        goto Replay; // Goto Label "Replay" [Line 67]
    }
    else // If user want to leave the game <Exit>
    {
        printf("\nThanks %s For Playing This Game!\n\n",name);
        printf("*****FINAL RESULT*****\n");
        printf("Played: %d\n",countPlayed); // Number of times user played this game
        printf("Win: %d\n",countWin); // Number of times user win this game
        printf("Drawn: %d\n",countDrawn); // Number of times user drawn this game
        printf("Lose: %d\n",countLose); // Number of times user lose this game
    }

    return 0;
}