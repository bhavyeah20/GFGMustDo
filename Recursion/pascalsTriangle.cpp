class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        ll mod = 1e9+7;
        vector<ll> prev, curr;
        
        prev.push_back(1);
        
        for(ll i = 1; i <= n; i++){
            curr.resize(i);
            
            if(i == 1){
                curr = prev;
            }
            
            else{
                for(int j = 0; j < i; j++){
                    ll left = 0, right = 0;
                    if(j-1 >= 0)
                        left = prev[j-1] % mod;
                        
                    if(j < prev.size())
                        right = prev[j] % mod;
                        
                    curr[j] = (left + right) % mod;
                }                
            }
            
            prev = curr;
            curr.clear();
            
        }
        
        return prev;
    }
};

//or

// nCr = nCr-1 * (n-r+1/r)
class Solution{
public:
    ll mod = 1e9+7;
    ll poww(ll a, ll b){
        ll res = 1LL;
        a %= mod;
        while(b){
            if(b&1){
                res = (res % mod) * (a % mod);
                res %= mod;
            }
            
            a = (a % mod) * (a % mod);
            a %= mod;
            b >>= 1;
        }
        
        return res % mod;
    }

    vector<ll> nthRowOfPascalTriangle(int i) {
    
        vector<ll> ans;
        ll C = 1LL;
        ans.push_back(C);
        if(i == 1)
            return ans;
            
        i--;
        for(ll j = 1; j <= i; j++){
            C = (C % mod) * ((i-j+1) % mod);
            C %= mod;
            C = (C % mod) * (poww(j,mod-2) % mod);
            C %= mod;
            ans.push_back(C);
        }
    }
};