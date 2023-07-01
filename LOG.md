```markdown
# Author
Adnan Bseisu 
dab262

# Estimate of time to complete assignment
5.5 hours

# Actual time to complete assignment
| Date | Time Started | Time Spent | Work completed |
| :--: | -----------: | ---------: | :------------- |
| 02/08 |      9:00pm |       0:45 | read assignment and played several games (by hand) to help me understand the rules. |
| 02/08 |      9:45pm |       0:45 | wrote high level pseudocode for the algorithm in my notebook, thinking specifically about how shouldDie(), isAlive(), and the part of the main function that updates the array after each timestep should work |
| 02/09 |      3:00pm |       1:00 | wrote code for the isAlive() and shouldDie() functions, testing them to make sure they worked as intended|
| 02/09 |      4:00pm |       1:00 | coded main function in main.c, encountering some errors with declaration of arrays and conversion of string values to integers, and then assigment of those integers to indices in the array. By the end of this period, I had successfully managed to take in the 3 command line arguments and assign them to respective integers (hadn't started the time_step loop yet)  |
| 02/09 |      5:00pm |       1:00 | coded the time_step loop, leveraging my high level pseudo code and already coded isAlive() and shouldDie() functions. Tested throughout to make sure the algorithm was producing values at each time step that matched the games being played in the spec   |
| 02/09 |      6:00pm |       0:30 | spent a lot of time figuring out how to start printing the timestep arrays at column 34. I initially used the log10 function in math.h to get the number of digits in the timestep index, but then this wasn't compatible with the autograder, so I went back and made my own funcion in life.c   |
| 02/09 |      6:30pm |       0:30 | passed all but one public test cases, which was where game_size was less than the length of the start state string. Fixed this by changing my conditional to check if game_size > length of start state (instead of checking if it is not equal to)  |
|      |              |            |                |
|      |              |       5:55 | total time spent |

# Collaboration
I discussed my solution with no one.

# Discussion
There were several challenges I encountered at several stages of this PSET. The first was initializing the array that would hold the values of the cells, since the string command line argument needed to be converted to an integer and then each element in the string had to be assigned to the corresponding index in the array. Ultimately, I went back to my lecture notes about statically allocated arrays and, with the help of atoi, overcame this challenge. Another significant challenge was figuring out how to start printing the timestep arrays at column 34 once the algorithm itself was working (the games played correctly). I initially tried to use the log10 funciton in math.h but found that this was incompatible with the autograder. I eventually solved this by designing my own recursive function numOfDigits that takes in a number n and returns its number of digits. 
```
