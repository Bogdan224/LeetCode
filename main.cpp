#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;



// Task 1
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            return {i, m[target - nums[i]]};
        }
        m[nums[i]] = i;
    }
    return {};
}

// Task 2
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = new ListNode();
    ListNode *temp = l3;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    temp = l3;
    l3 = l3->next;
    delete temp;
    return l3;
}

// Task 3
int lengthOfLongestSubstring(std::string s)
{
    std::string tmp = "";
    std::string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (tmp.find(s[i]) != std::string::npos)
        {
            if (tmp.length() > result.length())
            {
                result = tmp;
            }
            tmp = tmp.substr(tmp.find(s[i]) + 1);
        }
        tmp += s[i];
    }
    return std::max(tmp.length(), result.length());
}

// Task 4
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int n = nums1.size() + nums2.size();
    int *merged = new int[n];
    int mid = n / 2;
    double median;
    int i = 0, j = 0, k = 0;
    int count = 0, curr;
    while (count < n)
    {
        if (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                curr = nums1[i++];
            }
            else
            {
                curr = nums2[j++];
            }
        }
        else if (i < nums1.size())
        {
            curr = nums1[i++];
        }
        else
        {
            curr = nums2[j++];
        }
        merged[k++] = curr;
        count++;
    }
    if (n % 2 == 0)
    {
        median = merged[mid] + merged[mid - 1];
        median /= 2;
    }
    else
    {
        median = merged[mid];
    }
    return median;
}

// Task 5
std::string longestPalindrome(std::string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    auto expand_from_center = [s](int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    };

    std::string max_str = s.substr(0, 1);

    for (int i = 0; i < s.length() - 1; i++)
    {
        std::string odd = expand_from_center(i, i);
        std::string even = expand_from_center(i, i + 1);

        if (odd.length() > max_str.length())
        {
            max_str = odd;
        }
        if (even.length() > max_str.length())
        {
            max_str = even;
        }
    }

    return max_str;
}

// Task 6
std::string convert(std::string s, int numRows)
{
    if (numRows < 2)
    {
        return s;
    }
    int zig = 0;
    int zag = 0;
    std::vector<std::string> vec(numRows, "");
    std::string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (zig < numRows)
        {
            zag = numRows - 2;
            vec[zig].push_back(s[i]);
            zig += 1;
        }
        else if (zag > 0)
        {
            vec[zag].push_back(s[i]);
            zag -= 1;
        }
        else
        {
            zig = 0;
            vec[zig].push_back(s[i]);
            zig += 1;
        }
    }
    for (int i = 0; i < numRows; i++)
    {
        result += vec[i];
    }
    return result;
}

// Task 7
int reverse(int x)
{
    long result = 0;
    while (x != 0)
    {
        result = (result * 10) + (x % 10);
        x = x / 10;
    }

    if (result > INT_MAX || result < INT_MIN)
    {
        return 0;
    }

    return result;
}

// Task 8
int myAtoi(std::string s)
{
    int len = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool negative = false;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
        {
            negative = true;
        }
        i++;
    }
    while (i < len && s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    num = negative ? -num : num;
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    return (int)num;
}

// Task 9
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    long reversed = 0;
    int y = x;

    while (y > 0)
    {
        reversed = reversed * 10 + y % 10;
        y /= 10;
    }

    return reversed == x;
}

// Task 10(unresolved)
bool isMatch(std::string s, std::string p)
{
    int i = 0;
    bool isDot = false;
    bool isStar = false;
    std::string tmp;
    while (p[i] != NULL)
    {
        if (p[i] == '.')
        {
            isDot = true;
        }
        else if (p[i] == '*')
        {
            isStar = true;
        }
        else
        {
            tmp += p[i];
        }
        i++;
    }
    i = 0;

    if (!isDot && !isStar)
    {
        if (s == p)
            return true;
        else
            return false;
    }

    while (s[i] != NULL)
    {
        if (isStar)
        {
        }
    }
}

// Task 11
int maxArea(std::vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int maxArea = 0;
    int x;
    while (i < j)
    {
        maxArea = std::max(maxArea, std::min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
    return maxArea;
}

// Task 12
std::string intToRoman(int num)
{
    std::vector<std::pair<int, std::string>> m = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    std::string res;
    for (size_t i = 0; i < m.size(); ++i)
    {
        while (num >= m[i].first)
        {
            res += m[i].second;
            num -= m[i].first;
        }
    }
    return res;
}

// Task 13
int romanToInt(std::string num)
{
    std::vector<std::pair<int, std::string>> m = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    int res = 0;
    for (size_t i = 0; i < m.size(); ++i)
    {
        while (num.find(m[i].second) == 0)
        {
            res += m[i].first;
            num.erase(0, m[i].second.size());
        }
    }
    return res;
}

// Task 14
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    int n = strs.size();
    std::string tmp = strs[0];
    int j;
    for (int i = 1; i < n; i++)
    {
        j = 0;
        for (auto x = strs[i].begin(); x <= strs[i].end(); x++)
        {
            if (tmp[j] != strs[i][j])
            {
                tmp = strs[i].substr(0, j);
                break;
            }
            j++;
        }
        if (tmp.empty())
        {
            return "";
        }
    }
    return tmp;
}

void main()
{
    // Task 1
    /*
    std::vector<int> vec = { 1,2,3,4,5 };
    twoSum(vec, 5);
    */
    // Task 2
    /*
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* l3 = addTwoNumbers(l1, l2);
    */
    // Task 3
    /*
    std::string s = "dvdf";
    std::cout « lengthOfLongestSubstring(s);
    */
    // Task 4
    /*
    std::vector<int> vec1 = { 1,2 };
    std::vector<int> vec2 = { 3,4 };
    std::cout « findMedianSortedArrays(vec1, vec2);
    */
    // Task 5
    /*
    std::cout « longestPalindrome("abcdbbfcba");
    */
    // Task 6
    /*
    std::cout « convert("PAYPALISHIRING", 0);
    */
    // Task 7
    /*
    std::cout « reverse(-123);
    */
    // Task 8
    /*
    std::cout « myAtoi(" -42");
    */
    // Task 9
    /*
    std::cout « isPalindrome(122321);
    */
    // Task 11
    /*
    std::vector<int> vector = { 1,8,6,2,5,4,8,3,7 };
    std::cout « maxArea(vector);
    */
    // Task 12
    /*
    std::cout « intToRoman(1994);
    */
    // Task 13
    /*
    std::cout « romanToInt("MMCCCXCIX");
    */
    // Task 14
    std::vector<std::string> strs = {"ab", "a"};
    std::cout << longestCommonPrefix(strs);
    return;
}

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
    if (closest == target)
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