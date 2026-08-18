class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int leftmax=0;
        int rightmax=0;
        int total=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(leftmax>arr[l]){
                    total+=leftmax-arr[l];
                }
                else{
                    leftmax=arr[l];
                }
                l++;
            }
            else{
                    if(rightmax>arr[r]){
                        total+=rightmax-arr[r];
                    }
                    else{
                        rightmax=arr[r];
                    }
                    r--;
                }
            }
        return total;
    }
};