class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> map;
        int max=1,count=0;

        if (s.length()==0) return 0;
        int i=0;
        while(i<s.length()){
            cout << s[i] << " " << map.count(s[i]) << "\n";
            if(!(map.count(s[i])==0)){
                int tmp=i+1, checker=map[s[i]]+1;
                while(tmp<=s.length()){
                    if(s[checker]==s[tmp]){
                        checker++; tmp++;
                    }else{
                        break;
                    }
                }
                if(max<count)max=count;
                count=0;
                i=checker;
                map.clear();
            }
            map[s[i]]=i;
            count++;
            i++;
        }
        if(max<count)max=count;
        return max;
    }
};
