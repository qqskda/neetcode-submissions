class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int, int>> st;
        vector<int> ans(arr.size());
        for(int i = arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= st.top().second){
                st.pop();
            }
            if (st.empty()){
                ans[i] = 0;
            } else {
                ans[i] = st.top().first - i;
            }
            st.push({i,arr[i]});
        }
        return ans;
    }
};
