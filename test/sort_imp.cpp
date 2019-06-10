/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.52%)
 * Total Accepted:    298.3K
 * Total Submissions: 718.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note:Â You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with aÂ one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution
{
  public:
    void bublesort(vector<int> &a)
    {
        int len = a.size();
        //   if (a.size() <= 1)
        //       return;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            }
        }
    }

    void selectsort(vector<int> &a)
    {
        int len = a.size();
        for (int t = len - 1; t > 0; t--)
        {
            int maxp = 0;
            for (int i = 1; i <= t; i++)
            {
                if (a[i] > a[maxp])
                    maxp = i;
            }
            swap(a[maxp], a[t]);
        }
        return;
    }

    void shellsort(vector<int> &a)
    {
        int len = a.size();
        for (int jump = 31; jump >= 1; jump = jump / 2)
        {
            for (int i = 0; i < len - jump; i++)
            {
                if (a[i] > a[i + jump])
                {
                    swap(a[i], a[i + jump]);
                    int p = i - jump;
                    while (p >= 0 && a[p] > a[p + jump])
                    {
                        swap(a[p], a[p + jump]);
                        p -= jump;
                    }
                }
            }
        }
        return;
    }

    int mid_of_three(vector<int> &a, int i, int j)
    {
        int mid = (j - i) / 2 + i;
        if (a[i] >= a[mid])
        {
            if (a[j] >= a[i])
                return i;
            else if (a[mid] > a[j])
                return mid;
            else
                return j;
        }
        else
        {
            if (a[j] >= a[mid])
                return mid;
            else if (a[i] > a[j])
                return i;
            else
                return j;
        }
    }

    int partition1(vector<int> &a, int i, int j)
    {
        if (i == j)
            return i;
        int p = mid_of_three(a, i, j);
        swap(a[i], a[p]);
        int v = a[i];
        p = i;
        while (i < j)
        {
            while (j > i && a[j] > v)
                j--;
            if (j > i)
                a[i] = a[j];
            while (i < j && a[i] <= v)
                i++;
            if (j > i)
                a[j] = a[i];
        }
        a[i] = v;
        return i;
    }

    // [i,j]
    void mysort(vector<int> &a, int i, int j)
    {
        if (i >= j)
            return;
        int p = partition1(a, i, j);
        mysort(a, i, p - 1);
        mysort(a, p + 1, j);
        return;
    }

    void sortColors(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return;
        mysort(nums, 0, len - 1);
    }
};
