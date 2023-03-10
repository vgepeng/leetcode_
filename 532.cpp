#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>


using namespace std;

// 思路：哈希表

int findPairs(vector<int>& nums, int k) {
    unordered_set<int> visited;
    unordered_set<int> res;
    for (int num : nums) {
        // 从访问过的元素中查找匹配，将较小的值放入哈希表，不会影响结果的正确性
        if (visited.count(num - k)) {
            res.emplace(num - k);
        }
        if (visited.count(num + k)) {
            res.emplace(num);
        }
        visited.emplace(num);
    }
    // 返回结果的size
    return res.size();
};


int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << findPairs(nums, k) << endl;

    system("pause");
}