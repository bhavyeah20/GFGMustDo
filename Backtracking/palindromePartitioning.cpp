class Solution {
public:   

    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i <= (n-1)/2; i++){
            if(s[i] != s[n-1-i])
                return false;
        }
        
        return true;
    }
    
    void solve(int i, string &s, vector<string> &curr){
        if(i == s.length()){
            ans.push_back(curr);
            return ;
        }
        
        for(int j = i; j < s.length(); j++){
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])){
                dp[i][j] = 1;
                curr.push_back(s.substr(i,j-i+1));
                solve(j+1,s,curr);
                
                curr.pop_back();
            }
        }
    }
  
  
    vector<vector<string>> partition(string s) {
        dp.resize(s.length(), vector<bool> (s.length(),0));
        ans.clear();
        vector<string> curr;
        solve(0,s,curr);
        
        return ans;
    }
};
