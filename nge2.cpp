class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int index=i%n;
            while(!st.empty() && st.top()<=arr[index]){
                st.pop();
            }
            if(i<n&&!st.empty()){
                ans[index]=st.top();
            }
            st.push(arr[index]);
            }
            
        return ans;
        
    }
};