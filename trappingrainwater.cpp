class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        vector<int> suffix(n);
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=i;i<n;i++){
            prefix[i]=max(prefix[i-1],arr[i]);
        }
        suffix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],arr[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            int leftmax=prefix[i];
            int rightmax=suffix[i];
            if(arr[i]<leftmax&&arr[i]<rightmax){
                total+=min(leftmax,rightmax)-arr[i];
            }
        }
        return total;
    }
};