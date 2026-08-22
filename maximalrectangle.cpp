class Solution {
  public:
  int largestRectangleArea(vector<int>& heights) {

  int n = heights.size();

  vector<int> pse(n);
  vector<int> nse(n);

  stack<int> st;

  // Previous Smaller Element
  for (int i = 0; i < n; i++) {

      while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
      }

      if (st.empty()) {
          pse[i] = -1;
      }
      else {
          pse[i] = st.top();
      }

      st.push(i);
  }

  while (!st.empty()) {
      st.pop();
  }
for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            nse[i] = n;
        }
        else {
            nse[i] = st.top();
        }

        st.push(i);
    }

    int maxarea = 0;

    for (int i = 0; i < n; i++) {

        int width = nse[i] - pse[i] - 1;

        int area = heights[i] * width;

        maxarea = max(maxarea, area);
    }

    return maxarea;
}
    int maxArea(vector<vector<int>> &mat) {
          int rows=mat.size();
          int columns=mat[0].size();
          vector<int> height(columns,0);
          int maxi=0;
          for(int i=0;i<rows;i++){
              for(int j=0;j<columns;j++){
                  if(mat[i][j]==1){
                      height[j]++;
                  }
                  else{
                      height[j]=0;
                  }
              }
              int area = largestRectangleArea(height);
              maxi=max(maxi,area);
              
          }
          return maxi;
    }
};