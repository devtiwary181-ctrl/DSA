class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int current =arr[i];
            bool alive =true;
            while(!st.empty()&&st.top()>0&&current<0){
                if(st.top()<abs(current)){
                    st.pop();
                }
                else if(st.top()==abs(current)){
                    st.pop();
                    alive =false;
                    break;
                }
                else{
                    alive=false;
                    break;
                }
            }
            if(alive){
                st.push(current);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};