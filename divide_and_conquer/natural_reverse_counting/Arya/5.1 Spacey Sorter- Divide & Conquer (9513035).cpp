#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

long long MergeAndCountInversionsInPlace(std::vector<int> &nums, int start, int middle, int end)
{
    long long inversions = 0;

    std::vector<int> sorted(end - start + 1);
    int i = start, j = middle, cursor = 0;
    while (i < middle && j <= end)
    {
        if (nums[i] > nums[j])
        {
            inversions += middle - i;
            sorted[cursor++] = nums[j++];
        }
        else
        {
            sorted[cursor++] = nums[i++];
        }
    }
    while (i < middle)
    {
        sorted[cursor++] = nums[i++];
    }
    while (j <= end)
    {
        sorted[cursor++] = nums[j++];
    }

    for (auto i = 0; i < sorted.size(); i++)
    {
        nums[start + i] = sorted[i];
    }
    return inversions;
}

long long CountInversionsInPlace(std::vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    auto left_inversions = CountInversionsInPlace(nums, start, mid);
    auto right_inversions = CountInversionsInPlace(nums, mid + 1, end);
    auto merge_inversions = MergeAndCountInversionsInPlace(nums, start, mid + 1, end);
    return merge_inversions + left_inversions + right_inversions;
}

long long CountInversionsInPlace(std::vector<int> &nums)
{
    return CountInversionsInPlace(nums, 0, nums.size() - 1);
}

int GetSortRunningTime(std::vector<int> nums)
{
    auto counter = CountInversionsInPlace(nums);
    return counter % (int(1e9) + 7);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::cout << GetSortRunningTime(nums) << std::endl;

    return 0;
}
