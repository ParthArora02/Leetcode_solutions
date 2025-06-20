class Solution {
public:


    bool ispeak(vector<vector<int>>& mat, int i, int j){
        int n=mat.size(), m= mat[0].size();
        bool top = i==0 || mat[i][j]> mat[i-1][j];
        bool left = j==0 || mat[i][j]> mat[i][j-1];
        bool bottom= i==n-1 || mat[i][j]> mat[i+1][j];
        bool right= j==m-1 || mat[i][j]> mat[i][j+1];
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
    vector<int> bscol(vector<vector<int>>& mat){
        // if cols are larger TC n log m
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=m-1;
        vector<int> res;
        while(l<=r){
            int mid=(l+r)>>1;
            int row=-1;
            int maxi=-1;
            //max element in that column , where column = mid
            // cout<<"hello "<<endl;
            // return res;
            for(int it=0;it<n;it++){
                if(mat[it][mid]>maxi){
                    maxi=mat[it][mid];
                    row=it;
                }
            }
            cout<<"row "<<row<<" col "<<mid<<endl;
            // return res;
            if(ispeak(mat,row,mid)){
                res.push_back(row);
                res.push_back(mid);
                break;
            }
            else if(mid>0 && mat[row][mid-1]>mat[row][mid]){
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // return bsrow(mat);

        vector<int> ans;
        if(n<m){
            // ans=bscol(mat);
            ans=bsrow(mat);
        }
        else ans=bscol(mat);
        return ans;
    }
};