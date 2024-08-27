class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<int,int> freq;
        int maxlength=0;
        int maxFreq=0;
        int start=0;
        for(int end=0;end<s.length();end++){
            freq[s[end]]++;
            maxFreq=max(maxFreq,freq[s[end]]);
            while((end-start+1)-maxFreq>k){
                freq[s[start]]--;
                start++;
            }
            maxlength=max(maxlength,end-start+1);
        }
        return maxlength;
    }
};