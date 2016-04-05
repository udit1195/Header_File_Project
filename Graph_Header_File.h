/*@Project*/

/*
  Hey Ya !! Guys!!
  @Developer's':
  Udit Yadav
  Pingal Dixit
  (Studying at National Institute Of Technology,Agartala,India)
*/

/*User Info Below */

/*  A Graph Header File . Include it in your library and enjoy using some basic functions related to Graph data structure.
    Functionalities this file includes are following:

    1.Creating a graph i.e using adjacency matrix;
    2.Displaying the created graph i.e displaying adjacency Matrix;



    Limitations::
    - Only for Undirected Graph
    -For Maximum 100 number of vertices in a graph.


  Developer's Message::
  Thanks for using it. Do give your valuable feedback or for any query contact at udit1195@gmail.com OR at pingaldixit@gmail.com.
  We shall be adding more funcions from time to time.
  Till than,#Happy Coding;

 */


#include<stdio.h>
#define MAX 100

int adj[MAX][MAX]={0}; /*Adjacency Matrix ,program will be working upon*/
int number=0;
int P[MAX][MAX]={0}; /*Path Matrix to be created by Warshall's Algorithm*/

void create_undirgraph(int n)  /*function for creating undirected graph;  n is no of vertices. */
{
 number=n;
 int max_edges=n*(n-1)/2;
 int i,origin,destin;

for(i=1;i<=max_edges;i++)
   {
      printf("Enter edge %d(-1 -1 to quit): ",i);
      scanf("%d %d",&origin,&destin);
      //printf("abc");
      if((origin==-1) && (destin==-1))      /*When user wants to  quit*/
         break;

      if(origin>=n || destin >=n || origin<0 || destin<0)    /*Checking If The Entries Are Valid Or not*/
        {
           printf("Invalid vertex!!\n");
           i--;
        }
       else                              /* Valid So updating the adjacency matrix*/
       {
           adj[origin][destin]=1;
       }

    }

}

void display_graph()   /* That is to display adjacency matrix */
{
    int i,j=0;
    for(i=0;i<number;i++){
        for(j=0;j<number;j++)
        printf("%d ",adj[i][j]);
    printf("\n");
    }
}

void create_pathmat()   /*For Creating a path matrix to get to know if two vertices are connected or not. */
{
  int i,j,k;
    for(i=0;i<number;i++)
        for(j=0;j<number;j++)
        P[i][j]=adj[i][j];

    for(k=0;k<number;k++)
    {
        for(j=0;j<number;j++)
            for(j=0;j<number;j++)
                P[i][j]=(P[i][j]||(P[i][k] && P[k][j]));
    }

}

void disp_pathmat()   /*To display the Path Matrix created. */
{
    int i,j;

    for(i=0;i<number;i++)
        for(j=0;j<number;j++)
         printf("%d",P[i][j]);

}

int isConnected(int u,int v)   /*Returns 1 if the vertices are connected that is they have a path between them, else the function returns 0. */
{
    if(P[u][v]==1)
        return 1;
    else
        return 0;

}
