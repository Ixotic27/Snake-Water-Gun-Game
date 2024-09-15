#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int player, playerscore, computer, computerscore;
    playerscore = 0;
    computerscore = 0;
    /*
     0->snake
     1->water
     2->gun
    */
    int n;
    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        computer = rand() % 3; // Randomize computer's choice each round

        printf("Enter your choice: 0->snake 1->water 2->gun\n");
        scanf("%d", &player);

        // Validate player's choice
        if (player < 0 || player > 2)
        {
            printf("Invalid choice, please enter 0, 1, or 2.\n");
            i--; // Decrement the counter to replay the round
            continue;
        }

        // Display player's choice
        if (player == 0)
            printf("You chose Snake\n");
        else if (player == 1)
            printf("You chose Water\n");
        else
            printf("You chose Gun\n");

        // Display computer's choice
        if (computer == 0)
            printf("Computer chose Snake\n");
        else if (computer == 1)
            printf("Computer chose Water\n");
        else
            printf("Computer chose Gun\n");

        // Determine the outcome
        if (player == computer)
        {
            printf("It's a tie\n");
            playerscore++;
            computerscore++;
        }
        else if ((player == 0 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 0))
        {
            printf("You win this round!\n");
            playerscore++;
        }
        else
        {
            printf("You lose this round!\n");
            computerscore++;
        }

        printf("------------------------------\n");
    }

    // Final score and result
    printf("Your score: %d\nComputer's score: %d\n", playerscore, computerscore);
    if (playerscore > computerscore)
    {
        printf("Congratulations, You won the game!!\n");
    }
    else if (playerscore < computerscore)
    {
        printf("Sorry, You lost the game!!\n");
    }
    else
    {
        printf("Oops, The game is a tie!!\n");
    }

    return 0;
}
