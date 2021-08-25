class Solution{
public:
    vector<int> optimal;

    long long helper(int N){
        if(N <= 6)
            return N;
            
        if(optimal[N] != -1)
            return optimal[N];
            
        long long ans = 0;
        for(int i = N - 3; i >= 1; i--){
            ans = max(ans, (N-(i+2)+1)*helper(i));
        }
        
        return optimal[N] = ans;    
    }

    long long int optimalKeys(int N){
        // code here
        optimal.resize(N+1,-1);
        return helper(N);
    }
};
