class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, ans=1;
        while(i<nums.size() && nums[i]<=0){
            i++;
        }
        while(i<nums.size()){
            if(nums[i]!=ans)return ans;
            while(i<nums.size() && nums[i]==ans)i++;
            ans++;
        }
        return ans;
    }
};
