class Solution{
    public:
    int longestSubsequence(int n, int arr[]){
       vector<int> dp;
       for(int i = 0; i < n; i++){
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            if(it != dp.end()){
                dp[it-dp.begin()] = arr[i];
            }
            
            else
                dp.push_back(arr[i]);
       }
       
       return dp.size();
    }
};

//or

class Solution{
    public:
    int longestSubsequence(int n, int arr[]){
       vector<int> dp(n,1);
       int ans = 1;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < i; j++){
               if(arr[j] < arr[i]){
                   dp[i] = max(dp[i], 1 + dp[j]);
               }
           }
           ans = max(ans, dp[i]);
       }
       
       return ans;
    }
};