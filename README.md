# Filler

Filler is a game, where two players / algorithm are fighting on a map. 

A virtual machine organizes the game :
- calls the players alternatively
- give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the ennemy. 
To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin). 

The game appears on the standard input. 

The aim of the game is to put more pieces on the map than the ennemy. 

## Bonus

On big maps it's difficult to see what is really happening.

A visualizer made with the SDL2 helps us to understand what's happening. Use the left and right arrows of your keyboard to see it. 

## Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. 
Values are assigned on each case of the map. It starts from the position of the ennemy and is incremented until it reaches the board edges :

![alt text](https://github.com/mdubus/filler/blob/master/img/heat-map.png)

Then, the algorithm try to put the piece on each position of the map. One case of the piece has to overlap one of my previous. It calculates the score on each position. 
The smaller the score is, the best it is, because it will get closer of the ennemy and bother him to play. 

![alt text](https://github.com/mdubus/filler/blob/master/img/calculate-score.png)
