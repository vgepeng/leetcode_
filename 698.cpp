#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// 难

// 思路：回溯+剪枝


bool backtracking(vector<int>& nums, int index, int *bucket, int &k, int &target) {
    // 结束条件
    if (index==nums.size()) {
        // 检查所有桶是否装满
        for (int i=0;i!=k;++i) {
            if (bucket[i]!=target) return false;
        }
        return true;
    }

    for (int i=0;i!=k;++i) {
        // 当前桶装不下，放入下一个
        if (bucket[i]+nums[index]>target) continue;
        // 装进当前桶
        bucket[i]+=nums[index];

        // 下一个是否能够正常装
        if (backtracking(nums, index+1, bucket, k, target)) return true;
        // 下一个桶无法正常装，该球不属于该桶，拿出球
        bucket[i]-=nums[index];
        // 如果这个桶装不下，其他桶也装不下，提前结束
        if (bucket[i]==0) break;
    }
    return false;
};


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // k份子集之和应该等于总和
    if (sum % k > 0) {
        return false;
    }
    // 得到每个子集的和
    int target = sum / k;

    int bucket[k]={0};

    return backtracking(nums, 0, bucket, k, target);
};



int main() {
    vector<int> nums{4,3,2,3,5,2,1};
    cout << canPartitionKSubsets(nums, 4) << endl;

    system("pause");
}