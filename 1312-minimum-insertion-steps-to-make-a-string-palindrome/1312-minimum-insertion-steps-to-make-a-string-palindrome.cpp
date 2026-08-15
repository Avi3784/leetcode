class Solution {
public:
    int t[1001][1001];
    int lcs(string &x,string &y,int n , int m){

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                     t[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }

        }
        return t[n][m];
    }
    int minInsertions(string s) {
        int l=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        return l-lcs(s,s1,l,l);
        
    }
};