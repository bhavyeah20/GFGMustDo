class Solution{
    public:
    unordered_set<char> vis;
    unordered_set<char> path;
    unordered_map<char, vector<char>> mp;
    int biggestYet = 0;
    
    void cycle(char ch){
        vis.insert(ch);
        path.insert(ch);
        
        for(auto nbr: mp[ch]){
            if(vis.count(nbr) && path.count(nbr)){
                biggestYet = max(biggestYet, (int)path.size());
            }
            
            else if(!vis.count(nbr)){
                cycle(nbr);
            }
        }
        path.erase(ch);
    }
    
    int isCircle(int N, vector<string> A){
        vis.clear();
        mp.clear();
        biggestYet = 0;
        
        for(auto str: A){
            mp[str[0]].push_back(str[1]);
        }
        
        for(auto str: A){
            path.clear();
            if(!(vis.count(str[0]))){
                cycle(str[0]);
                if(biggestYet == A.size())
                    return true;
            }
        }
        cout<<biggestYet;
        return false;
    }
};


//l ength n cycle in undirected
