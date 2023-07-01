#include <stdbool.h>
#include <stdlib.h>

// Returns true if the cell at the given index in the array is alive
bool isAlive(int array[], size_t index, size_t size)
{
    // Check if the index is within the bounds of the array
    if (index < size)
    {
        // Check if the cell at the given index is alive
        if (array[index] == 1)
        {
            return true;
        }
        return false;
    }
    return false;
}

// Returns true if the cell at the given index should die
bool shouldDie(int array[], size_t index, size_t size)
{
    // Check if the cell is at either end of the array
    if (index == 0 || index == size - 1)
    {
        return false; 
    }
    else 
    {
        // Check if the cells on either side of the given cell are alive
        if (array[index - 1] == 1 && array[index + 1] == 1) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

// Returns the number of digits in a given integer
int numOfDigits (int n) {
    // Check if the number is less than 10
    if (n < 10) 
    { 
        return 1;
    }
    // Recursively divide the number by 10 and add 1 for each digit
    return numOfDigits (n / 10) + 1;
}
