class Solution {
public:


    bool ispeak(vector<vector<int>>& mat, int i, int j){
        int n=mat.size(), m= mat[0].size();
        bool left = i==0 || mat[i][j]> mat[i-1][j];
        bool top = j==0 || mat[i][j]> mat[i][j-1];
        bool right= i==n-1 || mat[i][j]> mat[i+1][j];
        bool bottom= j==m-1 || mat[i][j]> mat[i][j+1];
        return left && top && right && bottom;
    }

    vector<int> bsrow(vector<vector<int>>& mat){
        //if rows are larger  m log n
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=n-1;
        vector<int> res;
        while(l<=r){
            int mid=(l+r)>>1;
            cout<<"row "<<mid<<" ";
            //find the col of the largest element in the row = mid
            int col=-1;
            int maxi=-1;
            for(int it=0;it<m;it++){
                if(mat[mid][it]>maxi){
                    maxi=mat[mid][it];
                    col=it;
                }
            }
            cout<<"col "<<col<<endl;
            if(ispeak(mat,mid,col)){
                res.push_back(mid);
                res.push_back(col);
                return res;
                break;
            }
            else if(mid >0 && mat[mid-1][col]>mat[mid][col]){
                r=mid-1;
            }
            else l=mid+1;
            //
        }
        return res;
    }
    // vector<int> bscol(vector<vector<int>>& mat){
    //     // if cols are larger
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     int l=0,r=m-1;
    //     vector<int> res;
    //     while(l<=r){

    //     }
    // }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // return bsrow(mat);

        vector<int> ans;
        if(n<m){
            // ans=bscol(mat);
            ans=bsrow(mat);
        }
        else ans=bsrow(mat);
        return ans;
    }
};