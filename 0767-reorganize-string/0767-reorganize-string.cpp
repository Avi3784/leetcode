class Solution {
public:
    string reorganizeString(string s) {
        
        int n=s.size();
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
            if(freq[c-'a']>(n+1)/2) return "";
        }
        priority_queue<pair<int,char>>pq;
        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']>0){
                pq.push({freq[ch-'a'],ch});
            }
        }
        string res="";
        while(pq.size()>=2){
            pair<int,char>p1=pq.top();pq.pop();
            pair<int,char>p2=pq.top();pq.pop();

            res.push_back(p1.second);
            res.push_back(p2.second);

            p1.first--;
            p2.first--;

            if(p1.first>0)pq.push(p1);
            if(p2.first>0)pq.push(p2);
        }

        if(!pq.empty()){
            res.push_back(pq.top().second);
        }


        return res;
    }
};