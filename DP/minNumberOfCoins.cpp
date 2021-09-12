class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> ans;
        vector<int> notes({2000,500,200,100,50,20,10,5,2,1});
        for(int i = 0; i < notes.size(); i++){
            while(N >= notes[i]){
                N -= notes[i];
                ans.push_back(notes[i]);
            }
        }
        
        return ans;
        
    }
};

//or

class Solution{
public:

    int helper(int i, int N, vector<int> &notes, vector<int> &curr, vector<int> &ans){
        if(N == 0){
            if(ans.empty()){
                ans = curr;
            }
            else{
                if(curr.size() < ans.size()){
                    ans = curr;
                }
            }
            return 0;
        }
        
        if(i == -1){
            return 1e7;
        }
        
        if(notes[i] <= N){
            int val2 =  helper(i-1,N,notes,curr,ans);
            curr.push_back(notes[i]);
            int val1 = 1 + helper(i,N-notes[i],notes,curr,ans);
            curr.pop_back();
            return max(val1,val2);
        }
        
        return helper(i-1,N,notes,curr,ans);
    }

    vector<int> minPartition(int N){
        vector<int> notes({2000,500,200,100,50,20,10,5,2,1});

        vector<int> curr, ans;
        int val = helper(notes.size()-1,N,notes,curr,ans);
        sort(ans.rbegin(), ans.rend());

        return ans;
        
        
    }
};


//or

class Solution{
public:

    vector<int> bfs(int &target, vector<int> &notes){
        unordered_set<int> vis;
        unordered_map<int,int> parent;
        vector<int> ans;
        queue<int> q;
        for(int note: notes){
            q.push(note);
            vis.insert(note);
            parent[note] = -1;
        }
        
        bool found = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int note: notes){
                if(!(vis.count(curr+note))){
                    parent[curr+note] = curr;
                    q.push(curr+note);
                    vis.insert(curr+note);
                }
                
                if(target == curr+note){
                    found = 1;
                    break;
                }
            }
            
            if(found)
                break;
        }
        
        while(parent[target] != -1){
            ans.push_back(target-parent[target]);
            target = parent[target];
        }
        
        ans.push_back(target);
        return ans;
    }

    vector<int> minPartition(int N){
        // code here
        vector<int> notes({2000,500,200,100,50,20,10,5,2,1});
        vector<int> ans = bfs(N,notes);
        sort(ans.rbegin(), ans.rend());
        return ans;
        
    }
};
