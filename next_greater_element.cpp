class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    ans[i]=arr[j];
                    break;
                }
            }
            if(ans[i]==-1){
                for(int j=0;j<i;j++){
                    if(arr[j]>arr[i]){
                        ans[i]=arr[j];
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};