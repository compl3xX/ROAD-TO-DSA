class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        while(s<e)
        {
            if(nums[s]%2!=0&&nums[e]%2==0)
            {
                swap(nums[s],nums[e]);
                s++;
                e--;
            }
            else if(nums[s]%2!=0&&nums[e]%2!=0)
            {
                e--;
            }
            else if(nums[s]%2==0&&nums[e]%2!=0)
            {
                s++;
            }
            else 
            {
                s++;
            }
        }
        return nums;
    }
};
