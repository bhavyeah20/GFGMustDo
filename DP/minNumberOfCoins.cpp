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
            if(val2 > val1)
                curr.pop_back();
            return max(val1,val2);
        }
        
        return helper(i-1,N,notes,curr,ans);
    }

    vector<int> minPartition(int N){
        vector<int> notes({1,2,5,10,20,50,100,200,500,2000});
        vector<int> curr, ans;
        int val = helper(notes.size()-1,N,notes,curr,ans);
        return ans;
        
        
    }
};
