# -Labyrinth-generator
Labyrinth generator, to create random maps of labyrinths without closed areas. In the matrix format of int, corridors represented by 0 and walls by 1.
<h3>Knowing the idea</h3>

Basically he create a graph in the grid shape and assign random weights to each edge. From this creates a minimal tree with the algorithm of kruskal then transform this tree is an array of 0 and 1.

<hr/>
Gerador de Labirintos, para criar mapas de labirintos aleatorios sem areas fechadas. no formato matrix de int , corredores representados por 0 e paredes 1.

<h3>Conhecendo a ideia</h3>

Basicamente ele criar um grafo na forma de grade e atribue pesos aleatorio para cada aresta. A partir disso cria uma arvore mínima com o algoritimo de kruskal então tranforma essa arvore for uma matriz de 0 e 1. 
