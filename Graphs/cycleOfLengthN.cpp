//detect cycle of length n in an undirected graph

class Solution{
    public:
    unordered_set<char> vis;
    unordered_map<char, vector<char>> mp;
    
    bool cycle(char ch, int n, char org){
        vis.insert(ch);

        for(auto nbr: mp[ch]){
            if(!(vis.count(nbr))){
                if(cycle(nbr, n-1, org))
                    return true;
            }
            
            else if(n == 1 && nbr == org)
                return true;
        }
        
        vis.erase(ch);
        return false;
        
    }
    
    int isCircle(int N, vector<string> A){
        vis.clear();
        mp.clear();
        
        for(auto str: A){
            mp[str[0]].push_back(str[str.size()-1]);
        }
        
        if(cycle(A[0][0], A.size(), A[0][0]))
            return true;
        
        return false;
    }
};