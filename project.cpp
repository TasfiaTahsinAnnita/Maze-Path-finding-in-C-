#include<iostream>
#include<vector>
using namespace std;
vector<int>List[100];
int c[100];
int d[100];
int f[100];
int p[100];
int t=0;
int A[100];

//Backtracks the parent array to give final result using recursion

int BackTrack(int m)
{
    if(m==0)return 0;
    int q=p[m];
    A[m]=1;
    BackTrack(q);

}

// DFS traversal starting from vertex m

void DFS(int m)
{

    int u=m;
    c[u]=1;
    ++t;
    d[u]=t;

    for(auto x:List[u])
    {
        if(c[x]==0)
        {
            p[x]= u;
            DFS(x);
        }
    }
    f[u]= ++t;
    c[u]=2;
}

int main()
{

// Initializing the path array as zero

    for(int i=0; i<100; i++)
    {
        A[i]=0;
    }

    for(int i=0; i<100; i++)
    {
        c[i]=0;
        d[i]=9999;
        f[i]=9999;
        p[i]=0;
    }
    int m,n;
    cout<<" Enter maze size (should be given n*n size) ";
    cin>>n;
    int adj[n][n];
    cout<<endl<<" 0 is for block and 1 is for Open way "<<endl;
    cout<<" 1st value is the starting point and destination is the last value "<<endl<<endl;

// taking the input matrix

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>m;
            adj[i][j]= m;
        }
    }

// introduced a counter k

    int k=1;

// converting the matrix to tree

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adj[i][j]==1)
            {
                if(adj[i][j+1]==1&&j!=n-1)
                {
                    List[k].push_back(k+1);
                }
                if(adj[i+1][j]==1)
                {
                    List[k].push_back(k+n);
                }
            }
            k++;
        }
    }

//Recursive call of dfs and backtrack
    DFS(1);
    BackTrack(n*n);


    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<" The Solution of this maze "<<endl;

    cout<<endl;

//printing the final path after backtrack

    for(int i=1; i<=n*n; i++)
    {
        cout<<A[i]<<" ";
        if(i%n==0)
        {
            cout<<endl;
        }
    }

}
