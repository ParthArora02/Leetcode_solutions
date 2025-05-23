typedef long long ll;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 911382629;

struct Hash {
    ll h1, h2;
    bool operator==(const Hash &other) const {
        return h1 == other.h1 && h2 == other.h2;
    }
};

class StringHash {
private:
    vector<ll> hash1, hash2;
    vector<ll> pow1, pow2;
    int n;

public:
    StringHash(string &s) {
        n = s.size();
        hash1.resize(n + 1);
        hash2.resize(n + 1);
        pow1.resize(n + 1);
        pow2.resize(n + 1);

        pow1[0] = pow2[0] = 1;

        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * 1LL * BASE) % MOD1;
            pow2[i] = (pow2[i - 1] * 1LL * BASE) % MOD2;

            hash1[i] = (hash1[i - 1] * 1LL * BASE + s[i - 1]) % MOD1;
            hash2[i] = (hash2[i - 1] * 1LL * BASE + s[i - 1]) % MOD2;
        }
    }

    // Get hash of substring s[l..r], 1-based index
    Hash get_hash(int l, int r) {
        Hash res;
        res.h1 = (hash1[r] - hash1[l - 1] * pow1[r - l + 1]) % MOD1;
        if (res.h1 < 0) res.h1 += MOD1;

        res.h2 = (hash2[r] - hash2[l - 1] * pow2[r - l + 1]) % MOD2;
        if (res.h2 < 0) res.h2 += MOD2;

        return res;
    }
};

int helper(string &s, string &rev_s, StringHash &sh, StringHash &rev_sh, bool oddcase){
    int n=s.length();
    // int l=1,r=(n%2==1) ? n : n-1;
    int l=0,r=n/2+2;
    int res=0;// length 1 is always palidrome
    while(l<=r){
        //check if length=mid palidrome possible or not
        int mid=(l+r)>>1;
        int len=2*mid;
        if(oddcase)len++;
        if(len>n){
            r=mid-1;
            continue;
        }
        bool possible=false;
        for(int i=1;i<=n-len+1;i++){
            //for checking string hashing, we use 1 based indexing !!
            if(sh.get_hash(i,len+i-1)==rev_sh.get_hash(n-i+2-len,n-i+1)){
                possible=true;
                break;
            }
        }
        if(possible){
            res=max(res,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    int final_len=2*res;
    if(oddcase)final_len++;
    return final_len;
}
// int helper_even(string &s, string &rev_s, StringHash &sh, StringHash &rev_sh){

// }

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(); // given n>=1
        //here constraint is relatively small
        //but we can make an optimal solution
        //by string hashing and matching its hash with its rev we can find that 
        //it is the palindrome
        //we can run 2 binary search loops, one for odd length and one for 
        //even length 

        //
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        StringHash sh(s);
        StringHash rev_sh(rev_s);
        int odd=helper(s,rev_s,sh,rev_sh,1);
        int even=helper(s,rev_s,sh,rev_sh,0);
        int ans=max(odd,even);
        // return ans;
        int idx=-1;
        for(int i=1;i<=n-ans+1;i++){
            if(sh.get_hash(i,i+ans-1)==rev_sh.get_hash(n-i+2-ans,n-i+1)){
                idx=i;
                break;
            }
        }
        idx--;
        cout<<ans<<endl;
        string x=s.substr(idx,ans);
        return x;
    }
};