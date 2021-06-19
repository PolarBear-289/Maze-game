# Maze-game
Maze game problem using c++
Maze game is a well-known problem, where we are given a grid of 0’s and 1’s, 0’s corresponds to a place that can be traversed, and 1 corresponds to a place that cannot be traversed (i.e. a wall or barrier); the problem is to find a path from bottom left corner of grid to top right corner; immediate right, immediate left, immediate up and immediate down only are possible (no diagonal moves). We consider a variant of the maze problem where a cost (positive value) or profit (negative value) is attached to visiting each location in the maze, and the problem is to find a path of least cost through the maze.

You may solve the problem after imposing/relaxing other restrictions on the above problem on
Values of cost/profit (but not same cost/profit for all traversable cells in the grid)
Moves possible (but you cannot trivialize the problem by making the grid linear or partly linear in any way)
No. of destinations possible

Choose the most efficient algorithm possible for your specific case.


Hints: Convert the maze to a weighted graph G (V, E). Each location (i, j) in the maze corresponds to a node in the graph. The problem can have multiple solutions. Students can use any design technique such as greedy method, backtracking, dynamic programming. Students can choose their own conditions, positive or negative costs for the graph. 























 APPROACH: 
 
• Represent the maze with a 2D matrix. Start from top left square, cell (0, 0). Try to move to the square on the right, if it’s not possible to move to the square on the right because there is obstacle, try to move down. Keep doing this until we reach to the bottom right square, cell (N-1, N-1), where N is the size of the maze. On making a move to valid cell (row, column) mark the value in solutionMatrix[row][column] and increment the cost by one. 

• If we reach a dead end, a cell(row, column)from where we can neither go right nor down then backtrack(mark the value in solutionMatrix[row][column] = 0 and return false).

• Similarly in this way all the possible paths are found and the path which gives minimum cost is displayed.


DESIGN TECHNIQUE AND REASON:-

For this problem we are using BACKTRACKING method for building the solution because of the advantage of getting accurate solution and on assumption that maze size will not be too large . Backtracking is algorithm-technique for solving problem recursively by trying to build a solution incrementally, one piece at a time , removing that fail to satisfy the constraints of problem.








Algorithm:

1. Create a solution matrix, initially filled with 0’s.

2. Create a recursive function, which takes initial matrix, output matrix and position of M(i, j).

3. If the position is out of the matrix or the position is not valid then return.

4. Mark the position output[i][j] as 1 and check if the current position is destination or not. If destination is reached print the output matrix and return.

5. Recursively call for position (i+1, j) and (i, j+1).

6. Unmark position (i, j), i.e output[i][j] = 0.

