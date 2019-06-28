class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows == 0) return res;
        int cols = matrix[0].size();
        if(rows == 1) res = matrix[0];
        else if(cols == 1)
        {
            for(vector<int> v : matrix) res.push_back(v[0]);
        }
        else
        {
            bool right=true,left=false,
            down=false,up=false;
            int curR=0, curC=0;
            int rowLen = cols-1;
            int colLen = rows-1;
            int cnt=0;
            while(res.size() < cols*rows)
            {
                res.push_back(matrix[curR][curC]);
                if(rowLen<=0)
                {
                    curC++;
                    continue;
                }
                if(colLen<=0)
                {
                    curC++;
                    continue;
                }
                if(right)
                {
                    cnt++;
                    if(cnt==rowLen)
                    {
                        right=false;
                        down=true;
                        cnt = 0;
                    }
                    curC++;
                    continue;
                }
                if(down)
                {
                    cnt++;
                    if(cnt==colLen)
                    {
                        down=false;
                        left=true;
                        cnt=0;
                    }
                    curR++;
                    continue;
                }
                if(left)
                {
                    cnt++;
                    if(cnt==rowLen)
                    {
                        left=false;
                        up = true;
                        cnt=0;
                    }
                    curC--;
                    continue;
                }
                if(up)
                {
                    cnt++;
                    if(cnt==colLen)
                    {
                        up=false;
                        right=true;
                        cnt=0;
                        curC++;
                        colLen -= 2;
                        rowLen -= 2;
                    }
                    else curR--;
                    continue;
                }
            }
        }
        return res;
    }
};