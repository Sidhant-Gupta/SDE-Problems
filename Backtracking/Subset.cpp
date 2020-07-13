// https://leetcode.com/problems/subsets/     (Link to the question)


class Solution {
public:
    vector<vector<int> > sub(vector<int>& nums,vector<vector<int>> sol,int ind,vector<int> curr){
        int n=nums.size();
        if(ind==n){
            sol.push_back(curr);
            return sol;
        }
        sol=sub(nums,sol,ind+1,curr);
        curr.push_back(nums[ind]);
        sol=sub(nums,sol,ind+1,curr);
        return sol;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;vector<int>curr;
        return sub(nums,ans,0,curr);
        
    }
};