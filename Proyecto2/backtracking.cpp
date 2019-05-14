
#include <bits/stdc++.h>
using namespace std;
#define M 10
#define N 10

// Check if it is possible to go to (x, y) from current position. The
// function returns false if the cell has value 0 or already visited
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;

    return true;
}

// if not a valid position, return false
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0)
        return true;

    return false;
}

// Find Shortest Possible Route in a Matrix mat from source cell (0, 0)
// to destination cell (x, y)

// min_dist is passed by reference and stores length of longest path
// from source to destination found so far dist maintains length of
// path from source cell to current cell (i, j)

void findShortestPath(int mat[M][N], int visited[M][N], int i, int j, int x, int y, int& min_dist, int dist)
{
    // if destination is found, update min_dist
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }

    // set (i, j) cell as visited
    visited[i][j] = 1;

    // go to bottom cell
    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);

    // go to right cell
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);

    // go to top cell
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);

    // go to left cell
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    // go to diagonal derecha abajo cell
    if (isValid(i + 1, j+1) && isSafe(mat, visited, i + 1, j))
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);

    // go to diagonal derecha arriba cell
    if (isValid(i+1, j - 1) && isSafe(mat, visited, i, j + 1))
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);

    // go to izquierda abajo cell
    if (isValid(i - 1, j+1) && isSafe(mat, visited, i - 1, j))
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);

    // go to izquierda abajo cell
    if (isValid(i-1, j - 1) && isSafe(mat, visited, i, j - 1))
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);

    // Backtrack - Remove (i, j) from visited matrix
    visited[i][j] = 0;
}


