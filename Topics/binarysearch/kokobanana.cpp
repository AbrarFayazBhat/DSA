/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.*/
long long totalhours(vector<int>& piles,int hourly){
    int n=piles.size();
    long long totaltime=0;
    for(int i=0;i<n;i++){
        totaltime+=ceil(double(piles[i]) / double(hourly));
    }
    return totaltime;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
          long long high = *max_element(piles.begin(), piles.end());
        long long ans=INT_MAX;
        while(low<=high){
            long long mid=(low+high)/2;
            long long requiredtime=totalhours(piles,mid);
            if(requiredtime<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};