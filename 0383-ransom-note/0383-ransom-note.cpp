class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ans = true;
        unordered_map<char, int> m;

        for (char x : magazine) {
            m[x]++;
        }

        for (char x : ransomNote) {
            if (m[x] < 1) {
                ans = false;
            }
            m[x]--;
        }

        return ans;
    }
};