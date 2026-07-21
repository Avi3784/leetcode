class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        double half=myPow(x,n/2);
        // in case of even
        if(n%2==0){
            return half*half;
        }
// in case of odd
        if(n>0){
            return half*half*x; //POSITIVE+ODD
        }
        else{
            return half*half/x; //NEGATIVE+ODD
        }
    }
};