#include <iostream>
#include<vector>
#include <queue>
using namespace std;
class Solution {
public:
    //仅限于3*3以内的矩阵 - 。-|||

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> que;
        int x = 0, y = 0;

        int dx[] = { 0,1,-1,0 };//右下上左
        int dy[] = { 1,0,0,-1 };
        int i = 0;
        int m = mat.size();
        int n = mat[0].size();
        int j, k;
        for (j = 0; j < m; ++j)
        {
            for (k = 0; k < n; ++k)
            {
                if (mat[j][k] == 1)
                {
                    x = j;
                    y = k;
                    que.emplace(x, y);//将标号为1的位置全都加入队列

                }
            }
        }
        vector<vector<int>> visited(m, vector<int>(n));//标记该位置是否已经搜索过


        while (!que.empty())
        {
            x = que.front().first;
            y = que.front().second;
            que.pop();
            visited[x][y] = 1;//标识为已搜索过
            if (mat[x][y] != 0)
            {

                for (i=0; i < 4; ++i)
                {
                    int mx = x + dx[i]; //右下上左
                    int my = y + dy[i];
                    if (mx >= 0 && mx < m && my>=0 && my < n && mat[mx][my] == 1 && visited[mx][my] != 1)
                    {
                        mat[x][y] = mat[mx][my] + 1;
                    }
                    else if (mx >= 0 && mx < m && my>=0 && my < n && mat[mx][my]==0)
                    {
                        mat[x][y] = 1;
                        break;
                    }

                }



            }




        }
        return mat;
    }
};
int main()
{
    vector<vector<int>> mat({ {0, 0, 0},{0, 1, 0},{1, 1, 1} });
    Solution s1;
    s1.updateMatrix(mat);
    for (auto a : mat)
    {
        for (auto b : a)
        {
            cout << b;
       }
    }
    }
    

