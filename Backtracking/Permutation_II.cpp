// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
        vector<vector<int>>sol;
        set<vector<int>>st;
        void perm(vector<int>aval,vector<int >chosen,int n){
            if(chosen.size()==n){
                if(st.find(chosen)==st.end()){
                    sol.push_back(chosen);
                    st.insert(chosen);
                }
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>chosen;
        sol.clear();st.clear();
        perm(nums,chosen,nums.size());
        return sol;
    }
};