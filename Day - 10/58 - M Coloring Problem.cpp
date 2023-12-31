/*CodeStudio solution*/

bool ispossible(vector<vector<int>> &mat,vector<int>&color,int node,int col,int n){
    for(int i=0;i<n;i++){
        if(node!=i && mat[node][i]==1 && color[i]==col)
            return false;
    }
    return true;
}

bool slv(vector<vector<int>> &mat,vector<int>&color, int n,int m,int node) {
    if(node==n) 
        return true;
    for(int i=1;i<=m;i++)
    {
       if(ispossible(mat,color,node,i,n))
       {
           color[node]=i;
           if(slv(mat,color,n,m,node+1))
               return true;
           color[node]=0;
       }
    }    
    return false;    
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int>color(n,0);
    if(slv(mat,color,n,m,0)) 
        return "YES";
    return "NO";
}

/*GeeksforGeeks solution*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], int color[], int c, int v, int n) {
       for (int i = 0; i < n; i++) {
           if (color[i] == c && graph[v][i])
               return false;
       }
       return true;
    }
   
    bool graphColoringUtil(bool graph[101][101], int color[], int m, int n, int v) {
       if (v == n)
           return true;
       for (int c = 1; c <= m; c++) {
           if (isSafe(graph, color, c, v, n)) {
               color[v] = c;
               if (graphColoringUtil(graph, color, m, n, v + 1) == true)
                   return true;
               color[v] = 0;
           }
       }
       return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if (graphColoringUtil(graph, color, m, n, 0) == false)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
