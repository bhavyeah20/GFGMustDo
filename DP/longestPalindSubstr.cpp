//Cant reverse and find LCsubstring eg abcdcba

class Solution {
public:

    int findLongest(string &s, int i, int j){
        if(s[i] != s[j])
            return 0;

        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }

        return j-i-1;
    }

    string longestPalindrome(string s){
        int n = s.length();
        int res = 1, start = 0;
        for(int i = 0; i < n-1; i++){
            int len = max(findLongest(s,i,i), findLongest(s,i,i+1));
            if(len > res){
                res = len;
                start = i-(len-1)/2;
            }
        }

        return s.substr(start,res);
    }
};

//or

class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.length();
        int start = 0, end = 0;
        vector<vector<bool>> dp(n+1, vector<bool> (n+1,0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                int j = i+k;
                if(s[i] == s[j] && (j-i == 1 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                }
                if(dp[i][j]){
                    if(j-i > end - start)
                        start = i, end = j;
                }
            }
        }

        return s.substr(start, end-start+1);
    }
};