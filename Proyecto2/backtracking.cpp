/*
Article title:	Rat in a Maze | Backtracking-2 - GeeksforGeeks
Website title:	GeeksforGeeks
URL:	https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/ */
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
// Maze size
#define N 10
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N],int **solution, int cont);

bool isSafe(int maze[N][N], int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0)
        return true;
    return false;
}
int** solveMaze(int maze[N][N], int x, int y)
{
    cout<<"inicio"<<endl;
    if(0>x || x>=N || 0>y || y>=N ){
        printf("Solution doesn't exist");
    }else{
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
        int cont=1;
        int** solution = new int*[30];
        solution[0]= new int[2];
        solution[0][0]=x;
        solution[0][1]=y;
        if(solveMazeUtil(maze, x, y, sol, solution, cont) == false)
        {
            printf("Solution doesn't exist");
        }else {
            cout<<"solution found"<<solution<<endl;
            return solution;;
        }
    }
}
/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N],int **solution, int cont)
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
    // Check if maze[x][y] is valid
    if( isSafe(maze, x, y) == true && sol[x][y] != 5 && sol[x][y] != 1){

        sol[x][y] = 1;
        if (solveMazeUtil(maze, x+1, y, sol, solution, cont+1) == true){
            solution[cont]= new int[2];
            solution[cont][0]=x+1;
            solution[cont][1]=y;
            return true;}
        if (solveMazeUtil(maze, x, y+1, sol, solution, cont+1) == true){
            solution[cont]= new int[2];
            solution[cont][0]=x;
            solution[cont][1]=y+1;
            return true;}
        if(solveMazeUtil(maze, x+1, y+1, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x+1;
            solution[cont][1]=y+1;
            return true;}
        if(solveMazeUtil(maze, x-1, y+1, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x-1;
            solution[cont][1]=y+1;
            return true;}
        if(solveMazeUtil(maze, x-1, y-1, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x-1;
            solution[cont][1]=y-1;
            return true;}
        if(solveMazeUtil(maze, x+1, y-1, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x+1;
            solution[cont][1]=y-1;
            return true;}
        if(solveMazeUtil(maze, x, y-1, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x;
            solution[cont][1]=y-1;
            return true;}
        if(solveMazeUtil(maze, x-1, y, sol, solution, cont+1) == true){//yooo
            solution[cont]= new int[2];
            solution[cont][0]=x-1;
            solution[cont][1]=y-1;
            return true;}
         cont-=1;
         sol[x][y] = 5;
         return false;
        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
    }
    cont=-1;
    return false;
}
