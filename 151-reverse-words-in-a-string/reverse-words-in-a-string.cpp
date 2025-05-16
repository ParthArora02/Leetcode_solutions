class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]!= ' '){
                int end=i;
                while(i>=0 && s[i]!= ' ')i--;
                for(int j=i+1;j<=end;j++){//IMPORTANT!! j=i+1 is the starting point
                    ans.push_back(s[j]);
                }
                ans+=" ";
            }
        }
        if(ans.size()>1)ans.pop_back(); //because last element would have been " "
        return ans;
    }
};