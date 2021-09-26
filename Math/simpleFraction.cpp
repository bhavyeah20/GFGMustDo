class Solution{
	public:
	string fractionToDecimal(int num, int denom) {
	    string ans = "";
        unordered_map<int, int> mp;
	    int rem;
	    
        ans += to_string(num/denom);
        rem = num % denom;
        num = rem*10;
        
        if(!rem)
            return ans;
            
        ans.push_back('.');
        mp[rem] = ans.size();

	    while(num){
	        
	        ans += to_string(num/denom);
	        rem = num%denom;
	        num = rem*10;
	        
	        if(mp.find(rem) != mp.end()){
                int j = mp[rem];
                ans.insert(j,  1,'(');
                ans.push_back(')');
	    
	            return ans;
	        }
	    
	        if(!rem)
	            return ans;
	   
	        mp[rem] = ans.size();
	        
	    }
	    
	    return ans;
	    

	    
	}
};