/*C/C++ program to solve Rat in a Maze problem using
   backtracking */
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
// Maze size
#define N 10
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
/* A utility function to print solution matrix sol[N][N] */

int** printSolution(int sol[N][N])
{
    int** path= new int*[30];
    int ruta=0;
    int j=0;
    int i =0;
    path[ruta]= new int[2];
    path[ruta][0]=0;
    path[ruta][1]=0;
    ruta++;
    while(i<N && j<N){
        if(i==9 && j==9){
            return path;
        }else if (i==0 && j==0 ) {
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j+1]==1){
                sol[i+1][j+1]=7;
                i=i+1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (i==9 && j==0) {
            if(sol[i-1][j]==1){
                sol[i-1][j]=7;
                i=i-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j+1]==1){
                sol[i-1][j+1]=7;
                i=i-1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (i==0 && j==9) {
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j-1]==1){
                sol[i+1][j-1]=7;
                i=i+1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j-1]==1){
                sol[i][j-1]=7;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (i==0) {
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j+1]==1){
                sol[i+1][j+1]=7;
                i=i+1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j-1]==1){
                sol[i+1][j-1]=7;
                i=i+1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j-1]==1){
                sol[i][j-1]=7;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (j==0) {
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j+1]==1){
                sol[i+1][j+1]=7;
                i=i+1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j+1]==1){
                sol[i-1][j+1]=7;
                i=i-1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j]==1){
                sol[i-1][j]=7;
                i=i-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (i==9) {
            if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j+1]==1){
                sol[i-1][j+1]=7;
                i=i-1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j]==1){
                sol[i-1][j]=7;
                i=i-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j-1]==1){
                sol[i-1][j-1]=7;
                i=i-1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j-1]==1){
                sol[i][j-1]=7;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }else if (j==9) {
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j-1]==1){
                sol[i+1][j-1]=7;
                i=i+1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j-1]==1){
                sol[i][j-1]=7;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j-1]==1){
                sol[i-1][j-1]=7;
                i=i-1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j]==1){
                sol[i-1][j]=7;
                i=i-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }

        }else{
            if(sol[i+1][j]==1){
                sol[i+1][j]=7;
                i=i+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j+1]==1){
                sol[i+1][j+1]=7;
                i=i+1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j+1]==1){
                sol[i][j+1]=7;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i+1][j-1]==1){
                sol[i+1][j-1]=7;
                i=i+1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i][j-1]==1){
                sol[i][j-1]=7;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j-1]==1){
                sol[i-1][j-1]=7;
                i=i-1;
                j=j-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j]==1){
                sol[i-1][j]=7;
                i=i-1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
            else if(sol[i-1][j+1]==1){
                sol[i-1][j+1]=7;
                i=i-1;
                j=j+1;
                path[ruta]= new int[2];
                path[ruta][0]=i;
                path[ruta][1]=j;
                ruta++;
            }
        }
    }
    return path;
}
/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0)
        return true;
    return false;
}
/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
int** solveMaze(int maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
    }else {
        int** back= printSolution(sol);
        return back;;
    }
}
/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true && sol[x][y] != 5 && sol[x][y] != 1)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == true)
            return true;
        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y+1, sol) == true)
            return true;
        if(solveMazeUtil(maze, x+1, y+1, sol) == true)//yooo
            return true;
        if(solveMazeUtil(maze, x-1, y+1, sol) == true)//yooo
            return true;
        if(solveMazeUtil(maze, x-1, y-1, sol) == true)//yooo
            return true;
        if(solveMazeUtil(maze, x+1, y-1, sol) == true)//yooo
            return true;
         sol[x][y] = 5;
         return false;
        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
    }
    return false;
}
