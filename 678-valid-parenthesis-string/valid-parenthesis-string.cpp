class Solution {
public:
    bool checkValidString(string s) {
        //total left-total right ka abs <= total * -necessary(but not sufficiet)
        //while traversing from left to right
        //no. of left + no. of * >= no. of right encountered until now!!
        // eg. ) ... any sequence cannot be valid !!
        int n=s.length();
        int left=0,star=0,right=0;
        // bool possible =true;
        for(int i=0;i<n;i++){
            if(s[i]=='(')left++;
            else if(s[i]==')')right++;
            else star++;
            if(left+star<right)return false;
        }
        bool possible=true;
        // cout<<left<<endl;
        // cout<<right<<endl;
        // cout<<star<<endl;
        if(abs(right-left)<=star)possible = true;
        if(!possible) return false;
        //now we need to check from the back also!!
        reverse(s.begin(),s.end());
        int rleft=0,rright=0,rstar=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')rleft++;
            else if(s[i]==')')rright++;
            else rstar++;
            if(rright+rstar<rleft)return false;
        }
        return true;
        // if(!possible)return false;
    }
};