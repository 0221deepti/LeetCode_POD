Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*****solution*********
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
            int left=0,right=nums.size()-1,pointer=0;
            while(pointer<=right){
            if(nums[pointer]==0){
                swap(nums[pointer],nums[left]);
                left++;
                pointer++;
            }
            else if(nums[pointer]==1){
                pointer++;
            }
            else{
                swap(nums[pointer],nums[right]);
                right--;
            }
        }
        
    }
};
