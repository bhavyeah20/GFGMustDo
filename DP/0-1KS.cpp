class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int helper(int i, int W, int wt[], int val[]){
        if(i == -1)
            return 0;
            
        if(i != -1 && dp[i][W] != -1)
            return dp[i][W];
            
        if(wt[i] <= W){
            return dp[i][W] = max(val[i] + helper(i-1, W-wt[i],wt,val), helper(i-1,W,wt,val));
        }
        
        return dp[i][W] = helper(i-1,W,wt,val);
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
       // Your code here
       dp.clear();
       dp.resize(n+1,vector<int> (W+1,-1));
       return helper(n-1,W,wt,val);
       
    }
};
