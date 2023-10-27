class Solution {
public:
     int t[1001][1001];
     bool solve(string &s, int i, int j){
         if(i>=j) return 1;
         if(t[i][j]!= -1)return t[i][j];
         if(s[i] == s[j])
         return t[i][j] = solve(s,i+1,j-1);
         else
         return t[i][j] = 0;
     }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(t,-1,sizeof(t));
        int maxl = INT_MIN;
        int sp = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(solve(s,i,j) == true){
                   if(j-i+1>maxl){
                       maxl = j-i+1;
                       sp = i;
                   }
                }
            }
        }
        return s.substr(sp,maxl);
          
    } 
};