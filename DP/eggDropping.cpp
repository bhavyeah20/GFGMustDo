class Solution{
public:
    vector<vector<int>> dp;

    int attempts(int n, int k){
        if(n == 1 || k == 0 || k == 1)
            return k;

        if(dp[n][k] != -1)
            return dp[n][k];

        int ans = 201;

        int l = 1, h = k;
        while(l <= h){
            int mid = (l+h)/2;

            int temp = max({1+attempts(n-1,mid-1), 1+attempts(n,k-mid)});

            if(attempts(n-1,mid-1) < attempts(n,k-mid)){
                l = mid+1;
            }

            else
                h = mid-1;
                
            ans = min(ans, temp);
        }

        return dp[n][k] = ans;
    }


    int eggDrop(int n, int k) {
        dp.clear();
        dp.resize(n+1,vector<int> (k+1,-1));
        return attempts(n,k);
    }
};

//or

class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    vector<vector<int>> dp;

    int attempts(int n, int k){
        if(n == 1 || k == 0 || k == 1)
            return k;

        if(dp[n][k] != -1)
            return dp[n][k];

        int ans = -1;

        for(int j = 1; j <= k; j++){
            ans = min(ans, 1 + max(attempts(n-1,j-1), attempts(n,k-j)));
        }

        return dp[n][k] = ans;
    }


    int eggDrop(int n, int k) {
        dp.clear();
        dp.resize(n+1,vector<int> (k+1,-1));
        return attempts(n,k);
    }
};
