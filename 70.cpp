#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int climbStairs(int n) {
    vector<int> v{1, 2};
    if (n == 1 || n == 2) return n;
    for (int i=0;i!=n-2;++i){
        v.push_back(v[v.size()-1]+v[v.size()-2]);
    }
    return v[v.size()-1];
};


int main() {


    system("pause");
}