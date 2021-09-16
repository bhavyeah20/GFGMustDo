
class Solution{   
public:
    bool is1winner(int N,int arr[]) {
        //Player one can control all blocks
        if(N%2 == 0)
            return 1;

        // dp[i][j] -> max score by the player starting first
        vector<vector<int>> dp(N, vector<int> (N,0));
        int total = 0;

        for(int i = 0; i < N; i++){
            dp[i][i] = arr[i];
            total += arr[i];
        }

        for(int k = 1; k < N; k++){
            for(int i = 0; i < N-k; i++){
                int j = i + k;
                int a = 0, b = 0, c = 0;
                if(i+2 < N)
                    a = dp[i+2][j];

                if(i+1 < N && j-1 >= 0)
                    b = dp[i+1][j-1];

                if(j-2 >= 0)
                    c = dp[i][j-2];
                dp[i][j] = max(arr[i] + min(a,b), arr[j] + min(c, b));
            }
        }

        return 2*dp[0][N-1] >= total;
    }
};


//or


class Solution{   
public:

    vector<vector<vector<pair<int,int>>>> dp;

    pair<int,int> score(int start, int end, int arr[], int playerOne){
        pair<int,int> scores;
        scores.first = 0, scores.second = 0;

        if(start == end - 1){
            if(playerOne)
                scores.first += max(arr[start], arr[end]), scores.second = min(arr[start], arr[end]);
            else
                scores.second += max(arr[start], arr[end]), scores.first = min(arr[start], arr[end]); 

            return scores;
        }
        
        if(playerOne){
            if(dp[playerOne][start][end].first != -1)
                return dp[playerOne][start][end];
        }
        
        else{
            if(dp[playerOne][start][end].second != -1)
                return dp[playerOne][start][end];
        }


        if(playerOne){
            if(arr[start] + score(start+1,end,arr,1-playerOne).first > arr[end] + score(start,end-1,arr,1-playerOne).first){
                scores.first += arr[start] + score(start+1,end,arr,1-playerOne).first;
                scores.second += score(start+1,end,arr,1-playerOne).second;
            }

            else{
                scores.first += arr[end] + score(start,end-1,arr,1-playerOne).first;
                scores.second += score(start,end-1,arr,1-playerOne).second;
            }
        }


        else{
            if(arr[start] + score(start+1,end,arr,1-playerOne).second > arr[end] + score(start,end-1,arr,1-playerOne).second){
                scores.second += arr[start] + score(start+1,end,arr,1-playerOne).second;
                scores.first += score(start+1,end,arr,1-playerOne).first;
            }

            else{
                scores.second += arr[end] + score(start,end-1,arr,1-playerOne).second;
                scores.first += score(start,end-1,arr,1-playerOne).first;
            }
        }

        

   
        return dp[playerOne][start][end] = scores;
            

    }

    bool is1winner(int N,int arr[]) {
        dp.clear();
        dp.resize(2, vector<vector<pair<int,int>>> (N, vector<pair<int,int>> (N,{-1,-1})));
        int total = 0;
        for(int i = 0; i < N; i++)
            total += arr[i];

        return 2*score(0,N-1,arr,1).first >= total;
    }
};
