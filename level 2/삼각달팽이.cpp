#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> table;
    
    // 테이블 생성
    for(int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for(int j = 0; j <= i; j++)
            tmp.push_back(0);
        table.push_back(tmp);
    }
    
    int num = 1;
    int row = -1;
    int col = 0;
    
    // 값 입력
    for(int i = n; i > 0; i -= 3)
    {
        // 밑으로 진행
        for(int j = 0; j < i; j++)
        {
            table[++row][col] = num;
            num++;
        }
        
        // 오른쪽으로 진행
        for(int j = 0; j < i - 1; j++)
        {
            table[row][++col] = num;
            num++;
        }
        
        // 왼쪽 위로 진행
        for(int j = 0; j < i - 2; j++)
        {
            table[--row][--col] = num;
            num++;
        }
    }
    
    // 1차원으로 변경
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(table[i][j]);
    
    return answer;
}
