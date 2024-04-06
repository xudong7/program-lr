// https://leetcode.cn/problems/4sum/solutions/436368/si-shu-zhi-he-by-leetcode-solution

# include<iostream>
# include<bits/stdc++.h>
# include<vector>

using namespace std;

class Solution {
public:
    // 多数求和为某一值的问题
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        // 四个数的问题 
        // 小于4 直接返回
        if (nums.size() < 4) {
            return quadruplets;
        }
        // 排序 便于去重
        sort(nums.begin(), nums.end());
        int length = nums.size();
        // 上限取length-3 保证四个数
        for (int i = 0; i < length - 3; i++) {
            // 下一个数不大于该数 跳过以去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 当前值与当前值后三个值之和大于目标值 之后都不会等于目标值 直接break
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            // 当前值和倒数三个值都小于目标值 说明当前值要增大 continue到下一轮
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            // 第二个数的循环
            // 类似操作
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                // 后两个数用双指针来代替
                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 剪枝
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        // left为较小指针 增大
                        left++;
                    } else {
                        // right为较大指针 减小
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};
