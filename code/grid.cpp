#include <bits/stdc++.h>
using namespace std;

int R,C;
int A[1010][1010];
int visited[1010][1010];
int cycnt;
int cylen;

void DFS(int r,int c,int pr,int pc)
{
  if((A[r][c] == 2 || A[r][c] == 4 || A[r][c] == 5) && r+1 <= R) // r+1
  {
    if(A[r+1][c] == 2 || A[r+1][c] == 3 || A[r+1][c] == 6)
    {
      if(visited[r+1][c] && pr != r+1)
      {
        cycnt++;
        cylen = max(cylen,abs(visited[r][c] - visited[r+1][c])+1);
      }
      if(!visited[r+1][c])
      {
        visited[r+1][c] = visited[r][c] + 1;
        DFS(r+1,c,r,c);
      }
    }
  }
  if((A[r][c] == 2 || A[r][c] == 3 || A[r][c] == 6) && r-1 >= 1) // r-1
  {
    if(A[r-1][c] == 2 || A[r-1][c] == 4 || A[r-1][c] == 5)
    {
      if(visited[r-1][c] && pr != r-1)
      {
        cycnt++;
        cylen = max(cylen,abs(visited[r][c] - visited[r-1][c])+1);
      }
      if(!visited[r-1][c])
      {
        visited[r-1][c] = visited[r][c] + 1;
        DFS(r-1,c,r,c);
      }
    }
  }
  if((A[r][c] == 1 || A[r][c] == 3 || A[r][c] == 4) && c+1 <= C) // c+1
  {
    if(A[r][c+1] == 1 || A[r][c+1] == 5 || A[r][c+1] == 6)
    {
      if(visited[r][c+1] && pc != c+1)
      {
        cycnt++;
        cylen = max(cylen,abs(visited[r][c] - visited[r][c+1])+1);
      }
      if(!visited[r][c+1])
      {
        visited[r][c+1] = visited[r][c] + 1;
        DFS(r,c+1,r,c);
      }
    }
  }
  if((A[r][c] == 1 || A[r][c] == 5 || A[r][c] == 6) && c-1 >= 1) // c-1
  {
    if(A[r][c-1] == 1 || A[r][c-1] == 3 || A[r][c-1] == 4)
    {
      if(visited[r][c-1] && pc != c-1)
      {
        cycnt++;
        cylen = max(cylen,abs(visited[r][c] - visited[r][c-1])+1);
      }
      if(!visited[r][c-1])
      {
        visited[r][c-1] = visited[r][c] + 1;
        DFS(r,c-1,r,c);
      }
    }
  }
}
int main()
{
  cin>>R>>C;
  for(int i=1;i<=R;i++)
  {
    for(int j=1;j<=C;j++)
    {
      cin>>A[i][j];
    }
  }
  for(int i=1;i<=R;i++)
  {
    for(int j=1;j<=C;j++)
    {
      if(!visited[i][j])
      {
        visited[i][j] = 1;
        DFS(i,j,i,j);
      }
    }
  }
  cout<<cycnt/2<<" "<<cylen;
  return 0;
}
