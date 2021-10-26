
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //二分法查找，先找到一个target,然后以此为中心向两边扩展
        int left = 0, right = nums.size() - 1, mid = 0;
        if (nums.size() == 0)
        {
            return { -1,-1 };
        }

        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }

        }
        if (nums[right] != target)
        {
            return { -1,-1 };
        }
        if (nums.size() == 1)
        {
            return { 0,0 };
        }

        int l = right, r = right;

        while (l > 0)
        {

            if (nums[l] != nums[l - 1])
            {

                break;
            }
            l -= 1;
        }
        while (r < nums.size() - 1)
        {

            if (nums[r] != nums[r + 1])
            {

                break;
            }
            r += 1;
        }

        return { l,r };
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 5,7,7,8,8,10 };
    vector<int> res = s.searchRange(nums,8);
    for (auto a : res)
    {
        cout << a << "  ";
    }
}

