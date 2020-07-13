//  https://leetcode.com/problems/subsets-ii/

class Solution {
public:
        vector<vector<int> >fans;
        void sub(vector<int>& nums,set<vector<int>> &st,int ind,vector<int> curr){
            int n=nums.size();
            if(st.find(curr)==st.end()){
                fans.push_back(curr);
                st.insert(curr);
            }
            if(ind==n){
                return;
            }
            curr.push_back(nums[ind]);
            sub(nums,st,ind+1,curr);
            curr.pop_back();
            sub(nums,st,ind+1,curr);
            return;
        }  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        set<vector<int> > st;
        vector<int>curr;
        fans.clear();
        sub(nums,st,0,curr);
        return fans;
    }
};