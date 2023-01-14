# Maze Generator
Maze generator, to create random maps of labyrinths without closed areas. It create a maze maps in 0 and 1 matrix format to any length.

<h3>Understand the algorithm</h3>

Basically it create a graph in the grid shape and assign random weights to each edge. From this creates a minimal tree with the algorithm of kruskal then transform this tree to an matrix of 0 and 1. On this matrix the 0 are the ways and the 1 are the walls.
