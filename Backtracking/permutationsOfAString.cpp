class Solution{
    public:
    vector<string> ans;
    
    void helper(int i, string &s){
        if(i == s.size()){
            ans.push_back(s);
            return ;
        }
        
        for(int j = i; j < s.size(); j++){
            swap(s[i], s[j]);
            helper(i+1,s);
            
            swap(s[i], s[j]);
        }
    }
    
    vector<string> permute(string s){
       // code here
       ans.clear();
       helper(0,s);
       return ans;
    }
};
