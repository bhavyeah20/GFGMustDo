class Solution{
public:

    int mod = 1003;
    string s;
    vector<vector<vector<int>>> dp;

    int ways(int start, int end, bool exp){

        if(start == end){
            if(exp){
                return s[start] == 'T' ? 1 : 0;
            }

            return s[start] == 'F' ? 1 : 0;
        }

        int ans = 0;

        if(dp[exp][start][end] != -1)
            return dp[exp][start][end];

        for(int i = start+1; i < end; i += 2){

            if(exp){
                if(s[i] == '|'){
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 1) % mod;
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 0) % mod;
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 1) % mod;
                }

                else if(s[i] == '&'){
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 1) % mod;
                }

                else{
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 0) % mod;
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 1) % mod;


                }
            }

                else{
                if(s[i] == '|'){
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 0) % mod;
                }

                else if(s[i] == '&'){
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 0) % mod;
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 1) % mod;
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 0) % mod;
                }

                else{
                    ans += ways(start, i-1, 1) % mod * ways(i+1, end, 1) % mod;
                    ans += ways(start, i-1, 0) % mod * ways(i+1, end, 0) % mod;
                }
            }
        }

        return  dp[exp][start][end] = ans % mod;
    }

    int countWays(int N, string S){
        dp.clear();
        dp.resize(2, vector<vector<int>> (N, vector<int> (N, -1)));
        s = S;
        return ways(0,N-1,1);
    }
};