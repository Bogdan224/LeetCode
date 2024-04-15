#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

using std::vector;

// 15 Task
vector<vector<int>> threeSum(vector<int> &nums)
{
    int target = 0;
    sort(nums.begin(), nums.end());
    std::set<vector<int>> s;
    vector<vector<int>> output;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    for (auto triplets : s)
        output.push_back(triplets);
    return output;
}

// 16 Task
int threeSumClosest(vector<int> &nums, int target)
{
    int closest = nums[0] + nums[1] + nums[2];
    if(closest == target)
        return closest;
    
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                return sum;
            }
            if (abs(target - sum) < abs(target - closest))
                closest = sum;
            if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return closest;
}

int main()
{
    // 15 Task
    //  vector<int> nums = {0, 0, 0};
    //  auto vec = threeSum(nums);

    // 16 Task
    // vector<int> nums = {-1,2,1,-4};
    // std::cout << threeSumClosest(nums, 1) << '\n';

    
}