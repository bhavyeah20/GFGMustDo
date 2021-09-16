
class Solution{
public:

    vector<vector<int>> dp;

    int cost(int start, int end, int arr[]){
        if(end == start + 1)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 1e9;


        for(int i = start; i < end-1; i++){
            ans = min(ans, cost(start, i+1, arr) + cost(i+1,end, arr) + arr[start] * arr[i+1] * arr[end]);
        }

        return dp[start][end] = ans;

    }


    int matrixMultiplication(int N, int arr[]){
        dp.clear();
        dp.resize(N, vector<int> (N,-1));
        return cost(0,N-1,arr);
    }
};
