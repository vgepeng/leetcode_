# include <iostream>
# include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    int table[m][n];
    // 行列是否被堵住
    bool row=false;
    bool column=false;

    for (int i=0;i!=m;++i) {
        for (int j=0;j!=n;++j) {
            // 填充0行0列
            if (i==0 || j==0) {
                // 以是否被障碍占据分开讨论
                if (!obstacleGrid[i][j]) {
                    // 空 且该格前继不被障碍占据为1否则为0
                    if ((i==0 && !row) || (j==0 && !column)) table[i][j]=1;
                    else table[i][j]=0;
                }
                else {
                    // 被障碍占据，标志位置为true，同时该格计数为0
                    if (i==0) row=true;
                    if (j==0) column=true;
                    table[i][j]=0;
                }
            }
            // 填充非0行非0列
            if (i>=1 && j>=1) {
                // 无障碍该格递推，否则为0
                if (!obstacleGrid[i][j]) {
                    table[i][j] = table[i-1][j]+table[i][j-1];
                }
                else {
                    table[i][j]=0;
                }
            }
        }
    }
    // 返回最后位置数据
    return table[m-1][n-1];
};


int main() {

    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(v) << endl;


    system("pause");
}