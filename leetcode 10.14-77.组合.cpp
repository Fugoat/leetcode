
#include <iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int n, int k, int start)
    {

        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i)
        {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();

        }

    }
public:
    vector<vector<int>> combine(int n, int k) {

        backtracking(n, k, 1);
        return res;



    }
};

int main()
{
    Solution s1;
    vector<vector<int>> mat = s1.combine(4, 2);
    for (auto a : mat)
    {
        for (auto b : a)
        {
            cout << b;
        }
       cout<< endl;
    }
    

}


