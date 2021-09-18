class Solution{
    public:
    unordered_map<char, vector<char>> mp;

    string bfs(vector<int> &in, int k){
        queue<char> q;
        string res = "";
        for(int i = 0; i < k; i++){
            if(in[i] == 0){
                q.push(i+'a');
            }
        }

        while(!q.empty()){
            char x = q.front();
            res.push_back(x);
            q.pop();

            for(auto nbr : mp[x]){
                in[nbr-'a']--;

                if(in[nbr-'a'] == 0){
                    q.push(nbr);
                }
            }
        }

        return res;
    }
    string findOrder(string arr[], int n, int k) {
        mp.clear();
        string prev = arr[0];
        vector<int> in(26,0);
        for(int i = 1; i < n; i++){
            string curr = arr[i];

            int j = 0;
            while(j < prev.length() && j < curr.length() && prev[j] == curr[j])
                j++;

            if(!(j == prev.length() || j == curr.length())){
                in[curr[j]-'a']++;
                mp[prev[j]].push_back(curr[j]);
            }

            prev = curr;
        }

        return bfs(in,k);
        
    }
};