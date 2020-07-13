// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>>sol;
    void sum(vector<int> cand,int tar,vector<int>ans,int k){
        int add=accumulate(ans.begin(),ans.end(),0);
        if(add==tar){
            sol.push_back(ans);
            return;
        }
        if(add>tar){
            return;
        }
        for(int i=k;i<cand.size();i++){
            ans.push_back(cand[i]);
            sum(cand,tar,ans,i);
            ans.pop_back();
        }
        return ;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;sol.clear();
        sum(candidates,target,ans,0);
        return sol;
    }
};