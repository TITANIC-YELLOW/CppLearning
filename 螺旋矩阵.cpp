class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        int sum = rows*cols;
        vector<int> ans;
        if (rows==0||cols==0) return ans;

        int top=0, bottom=rows-1, left=0, right=cols-1;

        while (top<=bottom&&left<=right)
        {
            cout<<top<<" "<<bottom<<" "<<left<<" "<<right<<endl;
            for (int i=left; i<=right; ++i)
            {
                ans.push_back(matrix[top][i]);
            }
            if (ans.size()==sum) break;
            for (int i=top+1; i<=bottom; ++i)
            {
                ans.push_back(matrix[i][right]);
            }
            if (ans.size()==sum) break;
            for (int i=right-1; i>=left; --i)
            {
                ans.push_back(matrix[bottom][i]);
            }
            if (ans.size()==sum) break;
            for (int i=bottom-1; i>top; --i)
            {
                ans.push_back(matrix[i][left]);
            }
            if (ans.size()==sum) break;
            ++top;
            ++left;
            --bottom;
            --right;
        }
        return ans;
    }
};
