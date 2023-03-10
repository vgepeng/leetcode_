#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// ��

// ˼·������+��֦


bool backtracking(vector<int>& nums, int index, int *bucket, int &k, int &target) {
    // ��������
    if (index==nums.size()) {
        // �������Ͱ�Ƿ�װ��
        for (int i=0;i!=k;++i) {
            if (bucket[i]!=target) return false;
        }
        return true;
    }

    for (int i=0;i!=k;++i) {
        // ��ǰͰװ���£�������һ��
        if (bucket[i]+nums[index]>target) continue;
        // װ����ǰͰ
        bucket[i]+=nums[index];

        // ��һ���Ƿ��ܹ�����װ
        if (backtracking(nums, index+1, bucket, k, target)) return true;
        // ��һ��Ͱ�޷�����װ���������ڸ�Ͱ���ó���
        bucket[i]-=nums[index];
        // ������Ͱװ���£�����ͰҲװ���£���ǰ����
        if (bucket[i]==0) break;
    }
    return false;
};


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // k���Ӽ�֮��Ӧ�õ����ܺ�
    if (sum % k > 0) {
        return false;
    }
    // �õ�ÿ���Ӽ��ĺ�
    int target = sum / k;

    int bucket[k]={0};

    return backtracking(nums, 0, bucket, k, target);
};



int main() {
    vector<int> nums{4,3,2,3,5,2,1};
    cout << canPartitionKSubsets(nums, 4) << endl;

    system("pause");
}