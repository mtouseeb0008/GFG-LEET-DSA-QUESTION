//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long int solve(int i,int curSum,int coins[],int N,int sum,vector<vector<long>>& dp)
    {
        if(curSum==sum) return 1L;
        if(i==N) return 0L;
        
        if(dp[i][curSum]!=-1) return dp[i][curSum];
        
        if(curSum+coins[i]<=sum)
            return dp[i][curSum]=solve(i+1,curSum,coins,N,sum,dp) + solve(i,curSum+coins[i],coins,N,sum,dp);
            
        return dp[i][curSum]=solve(i+1,curSum,coins,N,sum,dp);
    }
    long long int count(int coins[], int N, int sum) {

        vector<vector<long>> dp(N,vector<long>(sum,-1));

        return solve(0,0,coins,N,sum,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends