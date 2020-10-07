----------------------------------------------------INSTRUCTIONS-----------------------------------------------------------------

These are the instructions for the game "Snakes and Ladders" written in C++ by Diego Mejía Suárez.

To be able to play, only two or more players willing to participate are needed. Then, it is necessary to compile and run the 
code to be able to start the game. 

At the time of execution, you should be able to observe in the terminal the following message entries (besides it will explain
which message entries to use in them):

 - Number of tile in total: ' -> here you define the number of tiles in the board, which has to be greater than 0.
 - Number of snakes: ' -> here you define the number of snakes on the board, which has to be greater than 0.
 - Number of ladders: ' -> here you define the number of ladders on the board, which has to be bigger than 0.
 - Snake penalty: ' -> here you define the squares that are moved back if you fall on a snake, which has to be bigger than 0.
 - Ladder reward: ' -> here you define the squares that are advanced if you fall on a ladder, which has to be bigger than 0.
 - Number of players: ' -> here you define the number of players, which has to be bigger than 2.
 - Number of turns: ' -> here you define the number of turns, which has to be bigger than 0.
 - Game type: ' -> here you define the type of game, varying between automatic or manual, this has to be 'A' or 'M' (without 
    whether it is upper or lower case).

After you have defined all these variables, if the game is defined as automatic, the code will run on its own. But 
if it is defined as manual, then it will be set as progressing the game. 

The following message appears if the game is manual:

"Press 'C' to continue next turn, or 'E' to end the game:"

When you see this message, press 'C' or 'c' on the terminal to start the game, and 'E' or 'e' to end the game 
the process of the game at any time possible that accepts input text, any other key or number only prints you 
the correct instructions to be able to continue with the game.

When you press the key to continue the game or if the game is running automatically, the following 
information can be viewed in the terminal:

"Turn: ... / Player: ... / Current tile: ... / Says roll: ... / Landed tile name: ... / Landed tile num: ..."

 - Turn': the turn the game is on, plus the game can only go up to a maximum of 20 turns.
 - Player': the number of the player who has all the following information
 - Current tile': The square in which the player is in relation to the board, which has 30 squares in total.
 - Dice roll': Random number generated between 1 and 6 to simulate a die.
 - Landed tile name': The letter of the square in which the player is located with respect to the die. The meaning
    of each of the letters is:
     - "N": normal box that does not have any special attribute.
     - "S": snake cassil that moves back to the player 3 squares.
     - "L": staircase that advances to the player 3 squares.
 - Landed tile num': the number of the square in which the player is after having moved with respect to the die
    and to the special box, if the case may apply. 

After all this information is printed for player #1, it is the turn of player #2 to continue with the game. This has 
the option to continue the game by pressing the 'C' or 'c' key, or in the same way to end the game with 'E' or 'e' and so
successively for all players until they reach player #1. This process is repeated until one 
following conditions are met:

 - One of the players reaches the last square of the board, in which the respective player is declared the winner of the game. 
 - The game reaches the maximum number of turns established.
 - One of the players presses the 'E' or 'e' key to end the game, if the game type is manual. 

Translated with www.DeepL.com/Translator (free version)
