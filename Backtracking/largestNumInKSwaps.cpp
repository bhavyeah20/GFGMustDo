class Solution{
    public:
    
    string maxString;
    
    void solve(string &s, int i, int k){
        if(k == 0 || i == s.length()){
            if(s > maxString)
                maxString = s;
                
            return ;
        }
        
        bool swapped = 0;
        
        for(int j = i+1; j < s.length(); j++){
            if(s[j]-'0' > s[i]-'0'){
                swapped = 1;
                swap(s[i], s[j]);
                solve(s,i+1,k-1);
                
                swap(s[i], s[j]);
            }
        }
        if(!swapped)
            solve(s,i+1,k);
    }
    
    string findMaximumNum(string str, int k){
        maxString = str;
        solve(str,0,k);
        return maxString;
        
    }
};


// greedily replacing with largest at farthest will fail for 
// 61892795431 and k = 2
// need not replace by largest at farthest at each step