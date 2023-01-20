class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans={};
        map<string,int> w;
        int si=words[0].length();
        if(s.length()<si*words.size())return ans;
        for(int i=0;i<=s.length()-(si*words.size());i++){
            w.clear();
            for(int j=0;j<words.size();j++){
                if(w.count(words[j])==0){
                    w[words[j]]=1;    
                }else{
                    w[words[j]]+=1;
                }
            }
            string tmpWord=s.substr(i,si);
            if(w.count(tmpWord)!=0){
                w[tmpWord]-=1;
            }else{
                continue;
            }
            bool maybe=true;
            int tmp=1;
            while(tmp!=words.size()){
                tmpWord=s.substr(i+si*tmp,si);
                // cout<<tmp<<" "<<w.size()<<" "<<tmpWord <<"\n";
                // cout << w.count(tmpWord)<<" "<<w[tmpWord];
                if(w.count(tmpWord)!=0 && w[tmpWord]>0){
                    w[tmpWord]-=1;
                    tmp++;
                }else{
                    maybe=false;
                    break;
                }
            }
            if(maybe){
                ans.push_back(i);
                // i+=si-1;
            }
        }
        return ans;
    }
};
