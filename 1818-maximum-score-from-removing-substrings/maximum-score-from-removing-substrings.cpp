class Solution {
public:
    string chek(string s, string m){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == m[1] && !st.empty() && st.top() == m[0])st.pop();
            else
            st.push(s[i]);
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        string mx = (x>y)? "ab":"ba";
        string mi = (x<y)? "ab":"ba";
        string temp = chek(s,mx);
        int cnt = n - temp.size();
        int ans = (cnt/2)*max(x,y);
        string temp_2 = chek(temp,mi);
        ans += ((temp.size()-temp_2.size())/2)*min(x,y);
        return ans;

        
    }
};