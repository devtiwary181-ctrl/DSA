class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n=arr.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
           int width=nse[i]-pse[i]-1;
           int area=arr[i]*width;
           maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};