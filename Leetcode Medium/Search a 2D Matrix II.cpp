class Solution {
public:
    bool bin1(int lx,int ly,int hx,int hy,vector<vector<int>>& matrix, int target)
    {
        if(lx < 0 || ly < 0 || hx >= matrix.size() || hy >= matrix[0].size()) return false;
        if(lx > hx) return false;
        if(ly > hy) return false;
        if(matrix[lx][ly]==target || matrix[hx][hy]==target) return true;
        if(matrix[lx][hy]==target || matrix[hx][ly]==target) return true;
        if(target < matrix[lx][ly] || target > matrix[hx][hy]) return false;
        int midx = (lx + hx)/2;
        int midy = (ly + hy)/2;
        if(matrix[midx][midy]==target) return true;
        if(bin1(lx,ly,midx,midy,matrix,target)) return true;
        if(bin1(lx,midy+1,midx,hy,matrix,target)) return true;
        if(bin1(midx+1,midy+1,hx,hy,matrix,target)) return true;
        if(bin1(midx+1,ly,hx,midy,matrix,target)) return true;
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        return bin1(0,0,n-1,m-1,matrix,target);
    }
};
