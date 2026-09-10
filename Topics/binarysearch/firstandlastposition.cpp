int lowindex(vector<int>& nums,int x){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int lowestindex=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x) {
            lowestindex=mid;
            high=mid-1;
        }
        else if(nums[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return lowestindex;
}
int highindex(vector<int>& nums,int x){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int lowestindex=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x) {
            lowestindex=mid;
            low=mid+1;
        }
        else if(nums[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return lowestindex;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowindex(nums,target);
        int second=highindex(nums,target);
        return {first,second};
    }
};