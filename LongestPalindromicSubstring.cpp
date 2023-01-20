class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        if(s.length()==1) return s;
        int max=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            int count=0;
            for(int j=s.length()-1;j>i;j--){
                if(s[i]==s[j]){
                    int ii=i, jj=j;
                    while(s[ii]==s[jj] && ii<=jj){
                        ii++;
                        jj--;
                    }
                    if(ii-jj==1 || ii-jj==2){
                        if(j-i+1>max){
                            ans=s.substr(i,j-i+1);
                            max=j-i+1;
                        }
                    }
                }
            }
        }
        cout << max;
        if(max==0)return ans+s[0];
        return ans;
    }
};
