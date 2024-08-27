class Solution {
public:
    int getMin(vector<int> &nums){
        int low=0;
        int high=nums.size()-1;
        if(nums[low]<=nums[high]) return nums[low];
        int len=nums.size()-1;
        while(low<=high){
            
            int mid=(low+high)/2;
            if(mid>0 and nums[(mid-1)%len]>nums[mid] and nums[mid]<nums[(mid+1)%len]){
                return nums[mid];
            }
            else if(nums[mid]<=nums[high]){
                high=mid-1;
            }
            else if(nums[low]<=nums[mid]){
                low=mid+1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        return getMin(nums);
    }
};