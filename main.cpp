#include <bits/stdc++.h>
#define MAX 5
using namespace std;
 

int cost[100];
int a=0;
string str[100];
bool isSafe(int row, int col, int m[][MAX],int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||col == n || visited[row][col]|| m[row][col] == 1)
        return false;
    return true;
}
 

void printPathUtil(int row, int col, int m[][MAX],int n, string& path, vector<string>&possiblePaths, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1|| col == n || visited[row][col]|| m[row][col] == 1)
        return;
    if (row == n - 1 && col == n - 1) {
        possiblePaths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Try for all the 4 directions (down, left,
    // right, up) in the given order to get the
    // paths in lexicographical order
 
    // Check if downward move is valid
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n,path, possiblePaths, visited);
        path.pop_back();

    }
 
    // Check if the left move is valid
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,path, possiblePaths, visited);
        path.pop_back();

    }
 
    // Check if the right move is valid
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n,path, possiblePaths, visited);
        path.pop_back();

    }
 
     // Check if the upper move is valid
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,path, possiblePaths, visited);
        path.pop_back();

    }
 
    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
    }
 
// Function to store and print
// all the valid paths
void printPath(int m[MAX][MAX], int n)
{
    // vector to store all the possible paths
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));
      
    // Call the utility function to
    // find the valid paths
    printPathUtil(0, 0, m, n, path,possiblePaths, visited);
    int p=1,j;
    

    // Print all possible paths
    for (int i = 0; i < possiblePaths.size(); i++)
        {
            p=1;
            str[a]="";
            cost[a]=0;
            str[a]=possiblePaths[i];
            for(j=0;j<possiblePaths[i].size();j++)
            {
                cost[a]+=p;
                p++;
            }
            a++;
        }
        
}
 
// Driver code
int main()
{
    int m[MAX][MAX] = { { 0, 0, 0, 0, 0 },
                        { 0, 1, 1, 0, 0 },
                        { 0, 1, 1, 0, 0 },
                        { 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0 } };
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n);
    int min_cost=cost[0],pos=0,i,j;
for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<a;i++)
    {
        if(cost[i]<min_cost)
        {
        min_cost=cost[i];
        pos=i;
        }
    }
    if(min_cost!=0)
        cout<<"Cost: "<<min_cost<<endl<<"Path "<<str[pos];
    else
        cout<<"No traversable path";
return 0;
}
