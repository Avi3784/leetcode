class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;

        // count frequency of each character
        for (auto ch : text) {
            freq[ch]++;
        }

        // word we want to form
        string word = "balloon";
        int ans = INT_MAX;

        // check minimum possible count
        for (auto ch : word) {
            if (ch == 'l' || ch == 'o') {
                ans = min(ans, freq[ch] / 2);  // need 2 l's and 2 o's
            } else {
                ans = min(ans, freq[ch]);      // need 1 of others
            }
        }

        return ans;
    }
};
