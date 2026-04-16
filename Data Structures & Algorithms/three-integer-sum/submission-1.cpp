class Solution {
    vector<vector<int>> getTwoSum(vector<int>& nums, int i, int j, int target) {
        vector<vector<int>> duplets;
        while(i<j) {
            if(nums[i] + nums[j] == target) {
                vector<int> duplet = {nums[i], nums[j]};
                if(duplets.size() == 0 || duplets.back() != duplet ){
                    duplets.push_back(duplet);
                }
                i++;
                j--;
            }
            else if (nums[i] + nums[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return duplets;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for(int i =0; i<nums.size();i++) {
            if(i== 0 || nums[i] != nums[i-1]) {
                vector<vector<int>> duplets = getTwoSum(nums, i+1, nums.size()-1, -1*nums[i]);
                //cout<<nums[i]<<endl;
                for(vector<int> duplet : duplets) {
                    //cout<<duplet[0]<<" "<<duplet[1]<<endl;
                    triplets.push_back({nums[i], duplet[0], duplet[1]});
                }   
                //cout<<endl;
            }
        }
        return triplets;
    }
};
