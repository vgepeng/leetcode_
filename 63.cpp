# include <iostream>
# include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    int table[m][n];
    // �����Ƿ񱻶�ס
    bool row=false;
    bool column=false;

    for (int i=0;i!=m;++i) {
        for (int j=0;j!=n;++j) {
            // ���0��0��
            if (i==0 || j==0) {
                // ���Ƿ��ϰ�ռ�ݷֿ�����
                if (!obstacleGrid[i][j]) {
                    // �� �Ҹø�ǰ�̲����ϰ�ռ��Ϊ1����Ϊ0
                    if ((i==0 && !row) || (j==0 && !column)) table[i][j]=1;
                    else table[i][j]=0;
                }
                else {
                    // ���ϰ�ռ�ݣ���־λ��Ϊtrue��ͬʱ�ø����Ϊ0
                    if (i==0) row=true;
                    if (j==0) column=true;
                    table[i][j]=0;
                }
            }
            // ����0�з�0��
            if (i>=1 && j>=1) {
                // ���ϰ��ø���ƣ�����Ϊ0
                if (!obstacleGrid[i][j]) {
                    table[i][j] = table[i-1][j]+table[i][j-1];
                }
                else {
                    table[i][j]=0;
                }
            }
        }
    }
    // �������λ������
    return table[m-1][n-1];
};


int main() {

    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(v) << endl;


    system("pause");
}