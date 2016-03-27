//@Project

/*
  Hey Ya !! Guys!!
  @Developer's':
  Udit Yadav
  Pingal Dixit
  (Studying at National Institute Of Technology,Agartala,India)
*/

//User Info Below

/*  A Graph Header File . Include it in your library and enjoy using some basic funtions related to Graph data structure.
    Functionalities this file includes are following:

    1.Creating a graph i.e using adjacency matrix;
    2.Displaying the created graph i.e displaying adjacency Matrix;



    Limitations::
    - Only for Undirected Graph
    -For Maximum 100 number of vertices in a graph.


  Developer's Message::
  Thanks for using it. Do give your valuable feedback or for any query contact at udit1195@gmail.com OR at pingaldixit@gmail.com.
  We shall be adding more functions from time to time.
  Till than,#Happy Coding;

 */


#include<stdio.h>
#define MAX 100

int adj[MAX][MAX]={0}; /*Adjacency Matrix ,program will be working upon*/
int number=0;


void create_undirgraph(int n)  //function for creating undirected graph;  n is no of vertices.
{
 number=n;
 int max_edges=n*(n-1)/2;
 int i,origin,destin;

for(i=1;i<=max_edges;i++)
   {
      printf("Enter edge %d(-1 -1 to quit): ",i);
      scanf("%d %d",&origin,&destin);
      //printf("abc");
      if((origin==-1) && (destin==-1))      //When user wants to  quit
         break;

      if(origin>=n || destin >=n || origin<0 || destin<0)    //Checking If The Entries Are Valid Or not
        {
           printf("Invalid vertex!!\n");
           i--;
        }
       else                              // Valid So updating the adjacency matrix
       {
           adj[origin][destin]=1;
       }

    }

}

void display_graph()   // That is to display adjacency matrix
{
    int i,j=0;
    for(i=0;i<number;i++){
        for(j=0;j<number;j++)
        printf("%d ",adj[i][j]);
    printf("\n");
    }
}

