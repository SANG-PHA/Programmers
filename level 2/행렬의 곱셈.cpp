#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int row = arr1.size();
    int col = arr2[0].size();
    
    for(int i = 0; i < row; i++)
    {
        vector<int> tmp;
        
        for(int j = 0; j < col; j++)
        {
            int num = 0;
            
            for(int k = 0; k < arr1[0].size(); k++)
                num += arr1[i][k] * arr2[k][j];
            
            tmp.push_back(num);
        }
        
        answer.push_back(tmp);
    }
    
    return answer;
}
