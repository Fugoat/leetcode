#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;//广度优先
        q.emplace(sr, sc);
        int dx[4] = { 1,0,0,-1 };//组合起来分别是向右，向上，向左，向下四个方向
        int dy[4] = { 0,1,-1,0 };
        int oldColor = image[sr][sc];
        int m = image.size(), n = image[0].size();
        if (oldColor == newColor)
        {
            return image;
        }
        image[sr][sc] = newColor;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int mx = x + dx[i];//向四个方向依次拓展
                int my = y + dy[i];
                if (mx < m && mx >= 0 && my < n && my >= 0 && image[mx][my] == oldColor)
                {
                    image[mx][my] = newColor;
                    q.emplace(mx, my);
                }
            }

        }
        return image;
    }
};
int main()
{
    Solution s1;
    s1.floodFill({{ 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } }, 1, 1, 2);
}