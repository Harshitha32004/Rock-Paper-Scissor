#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSOR 2

// Function to implement the game logic
int game(char you, char opponent) {
    // If both players choose the same thing, it's a draw
    if (you == opponent)
        return -1;

    // If user's choice is rock and opponent's choice is paper
    if (you == 'r' && opponent == 'p')
        return 0;

    // If user's choice is paper and opponent's choice is rock
    else if (you == 'p' && opponent == 'r')
        return 1;

    // If user's choice is rock and opponent's choice is scissors
    if (you == 'r' && opponent == 's')
        return 1;

    // If user's choice is scissors and opponent's choice is rock
    else if (you == 's' && opponent == 'r')
        return 0;

    // If user's choice is paper and opponent's choice is scissors
    if (you == 'p' && opponent == 's')
        return 0;

    // If user's choice is scissors and opponent's choice is paper
    else if (you == 's' && opponent == 'p')
        return 1;

    return -1;  // Default return if something unexpected happens
}

// Function to get the computer's choice randomly
char get_computer_choice() {
    int n = rand() % 3; // We now map directly to ROCK, PAPER, or SCISSOR

    if (n == ROCK) {
        return 'r'; // Rock
    } else if (n == PAPER) {
        return 'p'; // Paper
    } else {
        return 's'; // Scissors
    }
}

// Function to get user's choice with validation
char get_user_choice() {
    char choice;
    while (1) {
        printf("\nEnter your choice (r for ROCK, p for PAPER, s for SCISSOR): ");
        scanf(" %c", &choice);

        // Input validation
        if (choice == 'r' || choice == 'p' || choice == 's') {
            break; // valid input
        } else {
            printf("\nInvalid input. Please choose 'r' for ROCK, 'p' for PAPER, or 's' for SCISSOR.\n");
        }
    }
    return choice;
}

// Function to get the second player's choice (if playing with another person)
char get_second_player_choice() {
    char choice;
    while (1) {
        printf("\nSecond player, enter your choice (r for ROCK, p for PAPER, s for SCISSOR): ");
        scanf(" %c", &choice);

        // Input validation
        if (choice == 'r' || choice == 'p' || choice == 's') {
            break; // valid input
        } else {
            printf("\nInvalid input. Please choose 'r' for ROCK, 'p' for PAPER, or 's' for SCISSOR.\n");
        }
    }
    return choice;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    char you, opponent;
    int result;
    int game_mode;

    printf("\nWelcome to Rock, Paper, Scissors game!\n");

    // Ask if the user wants to play against another person or the computer
    printf("\nChoose game mode:\n");
    printf("1. Play against the Computer\n");
    printf("2. Play against another Person\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &game_mode);

    if (game_mode == 1) {
        // Play against the computer

        while (1) {  // Continue playing until there is a winner
            // Get user choice
            you = get_user_choice();

            // Get computer choice
            opponent = get_computer_choice();

            // Determine the result
            result = game(you, opponent);

            // Output the result
            printf("You chose: %c, Computer chose: %c\n", you, opponent);

            if (result == -1) {
                printf("\nGame Draw! Let's try again.\n");
            } else if (result == 1) {
                printf("\nWow! You have won the game!\n");
                break;  // Exit the loop if user wins
            } else {
                printf("\nOh! You have lost the game! Computer wins.\n");
                break;  // Exit the loop if computer wins
            }
        }
    } else if (game_mode == 2) {
        // Play against another person

        while (1) {  // Continue playing until there is a winner
            // Get player 1's choice
            printf("Player 1's turn\n");
            you = get_user_choice();

            // Get player 2's choice
            printf("Player 2's turn\n");
            opponent = get_second_player_choice();

            // Determine the result
            result = game(you, opponent);

            // Output the result
            printf("\nPlayer 1 chose: %c, Player 2 chose: %c\n", you, opponent);

            if (result == -1) {
                printf("\nGame Draw! Let's try again.\n");
            } else if (result == 1) {
                printf("\nPlayer 1 wins the game!\n");
                break;  // Exit the loop if Player 1 wins
            } else {
                printf("\nPlayer 2 wins the game!\n");
                break;  // Exit the loop if Player 2 wins
            }
        }
    } else {
        printf("\nInvalid choice! Please restart the game and choose either 1 or 2.\n");
    }

    return 0;
}

