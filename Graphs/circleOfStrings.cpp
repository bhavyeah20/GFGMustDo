class Solution{
    public:
    unordered_set<char> vis;
    unordered_map<char, vector<char>> mp;
    vector<int> in, out;


    void dfs(char ch){
        vis.insert(ch);
        for(auto nbr: mp[ch]){
            if(!(vis.count(nbr))){
                dfs(nbr);
            }
        }
    }
    
    bool isConnected(char ch){
        dfs(ch);

        for(int i = 0; i < 26;i++){
            if(!(vis.count(i+'a')) && in[i] > 0)
                return false;
        }

        return true;
        
    }
    
    int isCircle(int N, vector<string> A){
        vis.clear();
        mp.clear();
        in.clear();
        out.clear();

        in.resize(26,0), out.resize(26,0);    

        for(auto str: A){
            out[str[0]-'a']++;
            in[str[str.size()-1]-'a']++;
            mp[str[0]].push_back(str[str.size()-1]);
        }

        for(int i = 0; i < 26; i++){
            if(in[i] != out[i])
                return false;
        }

        return isConnected(A[0][0]);
    }
        
};
