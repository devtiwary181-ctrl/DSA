class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n=arr.size();
        long long MOD = 1e9 +7;
        long long ans=0;
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
        }
        if(st.empty()){
            left[i]=i+1;
        }
        else{
            left[i]=i-st.top();
        }
        st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            }
            else {
                right[i] = st.top() - i;
            }

            st.push(i);
        }


        for(int i=0;i<n;i++){
            long long contribution = (long long)arr[i] * left[i]* right[i];
            ans=(ans+contribution)%MOD;
            
        }
        return ans;
    }
};