class Solution {
public:
     bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mpOdd,mpEven;
        if(s1.length()!=s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                mpEven[s1[i]]++;
            }
            else{
                mpOdd[s1[i]]++;
            }
        }
        for(int i=0;i<s1.length();i++){
            if(i%2==0 ){
                if(mpEven[s2[i]]==0)  return false;
                mpEven[s2[i]]--;
            }
            else{
                if(mpOdd[s2[i]]==0) return false;
                mpOdd[s2[i]]--;
            }
        }
        return true;
    }
};