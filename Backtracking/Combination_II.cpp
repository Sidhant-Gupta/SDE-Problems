// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>>sol;
    set<vector<int >>st;
    void sum(vector<int> cand,int tar,vector<int>ans,int k){
        int add=accumulate(ans.begin(),ans.end(),0);
        if(add==tar){
            if(st.find(ans)==st.end()){
                sol.push_back(ans);
                st.insert(ans);
            }
            return;
        }
        if(add>tar){
            return;
        }
       
        for(int i=k;i<cand.size();i++){
            if(k>0)
                if(cand[k]==cand[k-1] && i>k)
                    return;
            ans.push_back(cand[i]);
            sum(cand,tar,ans,i+1);
            ans.pop_back();
        }
        return ;
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;sol.clear();st.clear();
        sort(candidates.begin(),candidates.end());
        sum(candidates,target,ans,0);
        return sol;
    }
};