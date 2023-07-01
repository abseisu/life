#include "life_dynamic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
    // Check the number of command line arguments
    if (argc != 4)
    {
        // Return 1 if the number of arguments is incorrect
        return 1; 
    }

    // Convert the first command line argument to an integer and assign to time_steps
    int time_steps = atoi(argv[1]); 

    // Check if the number of time steps is negative
    if (time_steps < 0)
    {
        // Return 1 (error) if the number of time steps is negative
        return 1;
    }

    // Convert the second command line argument to an integer and assign to game_size
    int game_size = atoi(argv[2]); 

    // Check if the game size is less than or equal to zero
    if (game_size <= 0)
    {
        // Return 1 (error) if the game size is invalid
        return 1;
    }

    // Check if the length of the third command line argument is less than the game size
    if (game_size > strlen(argv[3]))
    {
        // Return 1 (error) if the length of the string is smaller than the game size
        return 1; 
    }

    // Store the third command line argument as a char array
    char* start = argv[3];

    // Create an array to store the initial values of the game
    int* array = malloc(game_size * (sizeof(int)));

    // Iterate over the characters in the start string
    int i;
    for (i = 0; i < game_size; i++)
    {
        // Store the value of each character as either 0 or 1 in the array
        if (start[i] == '0') {
            array[i] = 0;
        } else if (start[i] == '1') {
            array[i] = 1;
        } else {
            // Return 1 (error) if a character in the string is not '0' or '1'
            return 1;
        }
    }

    // Print the initial values in the array
    printf("Initial values                   ");
    printf("[");
    for (i = 0; i < game_size; i++)
    {
        if (i == game_size - 1)
        {
            printf("%i", array[i]);
        } else {
            printf("%i, ", array[i]);
        }
    }
    printf("]\n");

    int* new_array = malloc(game_size * (sizeof(int)));

    // This loop iterates through each time step
    for (i = 0; i < time_steps; i++)
    {
        int j;

        // This inner loop iterates through each element of the array
        for (j = 0; j < game_size; j++)
        {
            // Check if the current element is the first element in the array
            if (j == 0)
            { 
                // If the first element is alive, it stays alive
                if (isAlive(array, j, game_size))
                {
                    new_array[j] = array[j]; 
                }
                else 
                {
                    // If the first element is dead, check if its right neighbor is alive, in which case the first element becomes arrive
                    if (isAlive(array, j+1, game_size))
                    {
                        new_array[j] = 1;
                    }
                    else
                    {
                        // If the right neighbor is dead too, copy the first element stays dead
                        new_array[j] = array[j];
                    }
                }
            }
            // Check if the current element is the last element in the array
            if (j == game_size - 1)
            { 
                // If the last element is alive, it stays alive
                if (isAlive(array, j, game_size))
                {
                    new_array[j] = array[j];
                }
                else
                {
                    // If the current element is dead, check if its left neighbor is alive, in which case the last elment becomes alive
                    if (isAlive(array, j-1, game_size))
                    {
                        new_array[j] = 1;
                    }
                    else 
                    {
                        // If the left neighbor is dead too, the last element stays dead
                        new_array[j] = array[j];
                    }
                }
            }
            // For all other elements that have left and right neighbors
            else 
            {
                // If the current element is alive
                if (isAlive(array, j, game_size))
                {
                    // Check if it should die, in which case kill it
                    if (shouldDie(array, j, game_size))
                    {
                        new_array[j] = 0;
                    }
                    else 
                    {  
                        // If it shouldn't die, it stays alive
                        new_array[j] = array[j];
                    }
                }
                else 
                {
                    // If the current element is dead, check if either of its neighbors are alive, in which case it becomes alive
                    if (isAlive(array, j - 1, game_size) || isAlive(array, j + 1, game_size))
                    {
                        new_array[j] = 1;
                    }
                    else
                    {
                        // If neither of its neighbors are alive, it stays dead
                        new_array[j] = array[j];
                    }
                }
            }
        }
    
        // Print the values after each time step
        printf("Values after timestep %d", i+1);

        // Add spaces to align the output
        int m;
        for (m = 0; m < 34 - (23 + numOfDigits(i+1)); m++)
        {
            printf(" ");
        }

        // Print the values in the array
        printf("[");
        int l;
        for (l = 0; l < game_size; l++)
        {
            // Update the array with new values
            array[l] = new_array[l];

            // Print the value in the array
            if (l == game_size - 1)
            {
                printf("%i", array[l]);
            }
            else
            {
                printf("%i, ", array[l]);
            }
        }
        printf("]\n");  
    }

    free(new_array);
    free(array);

    // Return 0 to indicate success
    return 0;
}
