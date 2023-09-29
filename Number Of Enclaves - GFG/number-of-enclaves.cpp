//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &a) {
       int n = a.size();
        int m = a[0].size();

        // Perform DFS on boundary cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dfs(a, i, j, n, m);
                }
            }
        }

        int cnt = 0;

        // Count remaining '1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += a[i][j];
            }
        }

        return cnt;
    }


    void dfs(vector<vector<int>>& a, int x, int y, int N, int M) {
        // Out of bounds or already visited
        if (x < 0 || x >= N || y < 0 || y >= M || a[x][y] == 0) {
            return;
        }

        // Mark the cell as visited
        a[x][y] = 0;

        // Explore the 4 neighboring cells
        dfs(a, x + 1, y, N, M);
        dfs(a, x - 1, y, N, M);
        dfs(a, x, y + 1, N, M);
        dfs(a, x, y - 1, N, M);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends