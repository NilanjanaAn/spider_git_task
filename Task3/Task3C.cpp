// SPIDER INDUCTIONS: TASK 3 (C) - Nilanjana Thakur (205121064) - ! WRONG ANSWER !

#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
vector<int>xq; // queue to hold x indeces
vector<int>yq; // queue to hold y indeces
int dx[4]={0,0,1,-1}; // x direction for bottom, top, right, left respectively
int dy[4]={1,-1,0,0}; // y direction for bottom, top, right, left respectively
int xindex,yindex; // to hold the dequeued x,y value pair
int vis[1002][1002]; // visited matrix for bfs
int dist[1002][1002]; // distance matrix for bfs
char a[1002][1002]; // original grid

void enqueue(int i,int j) // inserts an x,y value pair into the queue rear
{
    xq.push_back(i);
    yq.push_back(j);
}

void dequeue() // removes an x,y value pair from the queue front
{
    xindex=xq[0];
    xq.erase(xq.begin());
    yindex=yq[0];
    yq.erase(yq.begin());
}

void visitAdj(int x,int y) // visit the adjacent indeces of a given index on the grid
{
    for(int i=0;i<4;i++) // for each direction
    {
        int xi=x+dx[i];
        int yi=y+dy[i];
        if(vis[xi][yi]==1||a[xi][yi]=='#') // do not insert into queue if it's blocked or already visited
            continue;
        enqueue(xi,yi);
        dist[xi][yi]=dist[x][y]+1; // increment distance as parent distance + 1
    }
    vis[x][y]=1; // mark as visited
}

void minPath() // to find to the minimum path using bfs
{
    bool found=false;
    enqueue(1,1);
    memset(vis,0,sizeof(vis));
    vis[1][1]=1;
    dist[1][1]=0;
    while(xq.size()>0&&yq.size()>0 && !found) // searching for target index
    {
        dequeue();
        if(xindex==n&&yindex==m) // target index reached
        {
            found=true;
            cout<<dist[n][m];
        }
        else
        {
        	vis[x][y]=1;
            visitAdj(xindex,yindex); // visit the adjacent vertices of this vertex
        }
    }
    if(!found&&xq.size()<=0&&yq.size()<=0) // if target index was not found, i.e. unreachable
        cout<<"0";
}

int main() 
{
    cin>>n>>m;
    memset(a,'#',sizeof(a)); // set all values in the grid to # to avoid checking the left, right, top and bottom limits
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    minPath();
    return 0;
}
