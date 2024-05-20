class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
    int totalXor = 0;
    
    // Compute the bitwise OR of all elements in the array
    for (int element : nums) {
        totalXor |= element;
    }
    
    // Multiply the result by 2^(nums.size() - 1)
    return totalXor * static_cast<int>(pow(2, nums.size() - 1));
}
};
