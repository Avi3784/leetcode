class Solution {
public:
    bool canmake(vector<int>&bloomDay,int mid,int k,int m){

        int bouqcount=0;
        int consec_count=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){ //  the flower has bloomed
                consec_count++;
            }
            else{
                consec_count=0; // not enough consec_count to make a bouq
            }
            if(consec_count==k){
                bouqcount++; // found a bouq
                consec_count=0; // look for othre bouq as well 
            }
        }
        return bouqcount>=m;
      }






    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0;
        int n=bloomDay.size();
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int mindays=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(canmake(bloomDay,mid,k,m)){
                mindays=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }

        }

        return mindays;






    }
};


