class Solution {
public:
    vector<string> ans;
    void dfs(int i, int co, int cc, int n, string &curr){
        
        if(i == 2*n){
            ans.push_back(curr);
            return ;
        }
        
        if(co != n){
            curr.push_back('(');
            dfs(i+1,co+1,cc, n, curr);
            curr.pop_back();
        }
        
        if(cc < co){
            curr.push_back(')');
            dfs(i+1,co,cc+1, n, curr);
            curr.pop_back();
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string curr;
        dfs(0,0,0,n,curr);
        return ans;
    }
};