class Solution {
public:
    unordered_map<int, string> mp;
    vector<string> ans;

    void bt(string &digits, int i, string &curr){
        if(i == digits.size()){
            if(curr.length())
                ans.push_back(curr);
            return;
        }

        string letters = mp[digits[i]-'0'];
        for(int idx = 0; idx < letters.size(); idx++){
            curr.push_back(letters[idx]);
            bt(digits, i+1, curr);

            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string curr = "";
        mp.clear();
        ans.clear();
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        bt(digits, 0, curr);
        return ans;
    }
};