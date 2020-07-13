// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>>sol;
    void perm(vector<int>aval,vector<int >chosen,int n){
        if(chosen.size()==n){
            sol.push_back(chosen);
            return;
        }
        for(int i=0;i<aval.size();i++){
            chosen.push_back(aval[i]);
            aval.erase(aval.begin()+i);
            perm(aval,chosen,n);
            aval.insert(aval.begin()+i,chosen[chosen.size()-1]);
            chosen.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>chosen;sol.clear();
        perm(nums,chosen,nums.size());
        return sol;
    }
};