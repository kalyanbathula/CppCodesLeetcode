class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int maxoccurs = 0;

        for (int window = minSize; window <= maxSize; window++) {
            int windowSize = window;
            int start = 0;
            unordered_map<char, int> freq;
            unordered_map<string, int> freqString;
            for (int end = 0; end < s.length(); end++) {
                freq[s[end]]++;
                if (end - start + 1 == windowSize) {
                    if (freq.size() <= maxLetters) {
                        string substring = s.substr(start, windowSize);
                        freqString[substring]++;
                        maxoccurs = max(maxoccurs, freqString[substring]);
                    }
                    freq[s[start]]--;
                    if (freq[s[start]] == 0) {
                        freq.erase(s[start]);
                    }
                    start++;
                }
            }
        }
        return maxoccurs;
    }
};