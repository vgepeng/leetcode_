# include <iostream>
# include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // ���鶨��
    int table[m][n];
    // ���鸳ֵ
    for (int i=0;i!=m;++i) {
        for (int j=0;j!=n;++j) {
            // ����0��0��
            if (i==0 || j==0) {
                table[i][j]=1;
            }
            else {
                table[i][j]=0;
            }
            // �����0�з�0��
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