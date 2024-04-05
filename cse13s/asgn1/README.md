# briefly describes program

<p>The game is a random dice game that uses the positions of a pig instead of a die. Each position carries points but one position has zero points. The user inputs the number of players that can play(2 players or more but less than ten). Then the user will need to launch the random seed generator by typing a number, this will launch the game to start and pass the pig begins. The pig will keep being rolled until the player gets the pig position side, then it moves on to the next player. The first player who gets 100 points or more wins the game.<p>

# describes how to build program
<p>Import name.h file 
Import stdbool.h
Import inttypes.h
Import time.h
Make the enums for the pig positions.
Make the array for the players and assign variables from the name.h file
Make points array and start all points at 0
First I will make a while loop to check if all the array values “points” are less than 100. If it's less than 100 the game continues.
Using a For loop go through each players turn 
If the user inputs the player number less than 2 or more than 10 and IF statement will be put to give the default value as 2 and tell the user that the input is invalid
Do the srandom(seed)% to roll the pig. Use scanf to get the seed from the user.
If the output for the random seed is not an integer , a printf() command will show an error message.
Use a while loop to continue the rolls until a player gets side then it breaks and goes to the next player.Using SWITCH statements, assign/add  points for the given position of the pig when the random number is outputted. Type the pig position so the user knows which pig position the pig rolled to and give points depending on the position.
If the position is SIDE then the player turns end and the next player turn begins
When the while loop is exited and someone has over 100 points, print a congrats message and the points they have with the winner’s name provided.<p>



# describes how to run program
<p>Once you run the program by doing clang -Wall -Wpedantic -Werror -Wextra -c pig.c, the first question will be to the user how many players do you want to play. Input the number of players . Then the question of random seed is required to launch the randok number gnerator to the the pig roll for each player. The program will run by itself and put up each players name and the positions they got in there turn until they get the Position side.
THen goes to the next players turn until a winner is declared. The first player to gets 100 points or more gets congratulatory message and wins the game.<p>
