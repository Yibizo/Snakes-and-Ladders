----------------------------------------------------INSTRUCCIONES-----------------------------------------------------------------

Estas son las instrucciones para el juego "Snakes and Ladders" (Serpientes y Escaleras) escrito en C++ por Diego Mejía Suárez.

Para poder jugar, solo se necesitan dos o más jugadores dispuestos a participar. Después, es necesario compilar y correr el 
código para poder comenzar con el juego. 

Al momento de ejecutarlo, se deberá poder observar en la terminal las siguientes entradas de mensaje (además de que se explicará
que entradas de mensaje utilizar en las mismas):

 - 'Number of tile in total: ' -> aquí se define el número de casillas en el tablero, que tiene que ser mayor que 0.
 - 'Number of snakes: ' -> aquí se define el número de serpientes en el tablero, que tiene que ser mayor que 0.
 - 'Number of ladders: ' -> aquí se define el número de escaleras en el tablero, que tiene que ser mayor que 0.
 - 'Snake penalty: ' -> aquí se define las casillas que se retroceden si se cae en una serpiente, que tiene que ser mayor que 0.
 - 'Ladder reward: ' -> aquí se define las casillas que se avanzan si se cae en una escalera, que tiene que ser mayor que 0.
 - 'Number of players: ' -> aquí se define el número de jugadores, que tiene que ser mayor que 2.
 - 'Number of turns: ' -> aquí se define el número de turnos, que tiene que ser mayor que 0.
 - 'Game type: ' -> aquí se deine el tipo de juego, variando entre automático o manual, este tiene que ser 'A' o 'M' (sin 
    importar que sea mayúscula o minúscula).

Después de haber definido todas estas variables, si el juego es definido como automático, el código correrá por su cuenta. Pero 
si se define como manual, a continuación se establecerá como progresar el juego. 

El siguiente mensaje aparece si el juego es manual:

"Press 'C' to continue next turn, or 'E' to end the game:"

Cuando veas este mensaje, presiona la tecla 'C' o 'c' en la terminal para comenzar con el juego, y 'E' o 'e' para acabar con 
el proceso del juego en cualquier momento posible que se acepte texto de entrada, cualquier otra tecla o número solo te imprime 
las instrucciones correctas para poder continuar con el juego.

Al momento de presionar la tecla para continuar el juego o si el juego se está ejecutando de manera automática, la siguiente 
información se puede ver en la terminal:

"Turn: ... / Player: ... / Current tile: ... / Dice roll: ... / Landed tile name: ... / Landed tile num: ..."

 - 'Turn': el turno en el que el juego esta, además de que el juego solo puede llegar a 20 turnos como máximo.
 - 'Player': el número del jugador al que le corresponde toda la siguiente información.
 - 'Current tile': El casilla en el que se encuentra el jugador con respecto al tablero, que tiene 30 casillas en total.
 - 'Dice roll': Número aleatorio generado entre 1 y 6 para simular un dado.
 - 'Landed tile name': la letra de la casilla en la que se encuentra el jugador con respecto al dado. El significado
    de cada una de las letras es:
     - "N": casilla normal que no tiene ningún atributo especial.
     - "S": cassila serpiente que retrocede al jugador 3 casillas.
     - "L": casilla escalera que avanza al jugador 3 casillas.
 - 'Landed tile num': el numero de la casilla en la que se encuentra el jugador después de haberse movido con respecto al dado
    y a la casilla especial, si se puede aplicar el caso. 

Después de que toda esta información es impresa para el jugador #1, es turno del jugador #2 para continuar con el juego. Este tiene 
la opción de continuar con el juego presionando la tecla 'C' o 'c', o de la misma manera acabar el juego con 'E' o 'e' y así
sucesivamente para todos los jugadores hasta llegar de regreso al jugador #1. Este proceso se repite hasta que una de las 
siguientes condiciones se cumpla:

 - Uno de los jugadores llega a última casilla del tablero, en la cual el respectivo jugador es declarado el ganador del juego. 
 - El juego llega al máximo número de turnos establecido.
 - Uno de los jugadores presiona la tecla 'E' o 'e' para acabar el juego, si el tipo de juego es manual. 

----------------------------------------------------------------------------------------------------------------------------------

Uno de los principales cambios que hice en mi código es dividir varios métodos del mismo en diferentes clases, y adjuntarlos 
al juego de serpientes y escaleras utilizando agregación como de composición, además de que las dividí en 
archivos 'hpp' en vez de tenerlo todo junto en un archivo 'cpp'. Después de esto, seguí las recomendaciones dadas e hice uso 
de tanto listas de inicialización para hacer uso de métodos del dado y del tipo de juego en el juego de serpientes y escaleras,
e igualmente implementación de estos métodos fuera de la propiedad pública de la clase utilizando 'scope resolution' para 
eliminar cualquier tipo de ambiguedad.

La forma en la que uso herencia, a pesar de que no estuviera implementada de la mejor manera posible, fue hacer que el juego
de serpientes y escalera heredara de manera pública de la clase 'Game'. De esta manera, se heredan todos los atributos y 
métodos del mismo. 

Así pues, la manera en la que hice uso de herencia fue mencionada previamente, pero lo que hace toda esta jerarquía de diversos códigos
polimórfica es el hecho de que, a lo largo de la escritura del código del mismo hice uso de apuntadores, creación de objetos 
usando estos mismos apuntadores, y se estableció un método virtual, este siendo 'setPlayerTurn', para que después su hijo 
'SnakesAndLadders' cambie este método a uno que pueda ser adaptado a diferentes jugadores, y no solo a dos como en la versión 
anterior del código del juego entregado. 

Por otro lado, las clases 'Dice' y 'GameType', debido a que dependen del juego para ser creadas y destruidas, se implementan de
manera que el juego se componga de las mismas. Asimismo, las vectores de clases 'Tile' y 'Player',debido a que solo forman parte
del juego, se implemetaron de manera que se agreguen al juego. Estas últimas podrían haber sido usadas mediante composición, pero 
no tenía muy claro como usar estos vectores con apuntadores y declararlos en el constructor. 

Con todo esto establecido, considero que todo este código es polimórfico, además de que hace uso de herencia a través del mismo. 