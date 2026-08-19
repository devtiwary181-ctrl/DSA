class Solution {
  public:
    string removeKdig(string &s, int k) {
        string st;
        for(int i=0;i<s.size();i++){
            char digit=s[i];
            while(!st.empty()&& k>0 && st.back()>digit){
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
            while(k>0&&!st.empty()){
                st.pop_back();
                k--;
            }
            int i=0;
            while(i<st.size()&&st[i]=='0'){
                i++;
            }
        st=st.substr(i);
        if(st.empty()){
            return "0";
        }
        return st;
    }
};