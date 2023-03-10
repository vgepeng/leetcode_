#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>


using namespace std;

// ˼·����ϣ��

int findPairs(vector<int>& nums, int k) {
    unordered_set<int> visited;
    unordered_set<int> res;
    for (int num : nums) {
        // �ӷ��ʹ���Ԫ���в���ƥ�䣬����С��ֵ�����ϣ������Ӱ��������ȷ��
        if (visited.count(num - k)) {
            res.emplace(num - k);
        }
        if (visited.count(num + k)) {
            res.emplace(num);
        }
        visited.emplace(num);
    }
    // ���ؽ����size
    return res.size();
};


int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << findPairs(nums, k) << endl;

    system("pause");
}