# include <iostream>
# include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // 数组定义
    int table[m][n];
    // 数组赋值
    for (int i=0;i!=m;++i) {
        for (int j=0;j!=n;++j) {
            // 处理0行0列
            if (i==0 || j==0) {
                table[i][j]=1;
            }
            else {
                table[i][j]=0;
            }
            // 处理非0行非0列
            if (i>=1 && j>=1) {
                table[i][j]=table[i-1][j]+table[i][j-1];
            }
        }
    }
    return table[m-1][n-1];
};


int main() {

    cout << uniquePaths(3, 7) << endl;


    system("pause");
}