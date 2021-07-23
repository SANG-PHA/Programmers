#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    // 행렬 구성
    vector<vector<int>> table;
    
    int n = 1;
    for(int i = 0; i < rows; i++)
    {
        vector<int> c;
        
        for(int j = 0; j < columns; j++)
        {
            c.push_back(n);
            n++;
        }

        table.push_back(c);
    }
    
    // 회전 및 최솟값 구하기
    vector<int> answer;
    
    for(int i = 0; i < queries.size(); i++)
    {
        int row1 = queries[i][0];
        int col1 = queries[i][1];
        int row2 = queries[i][2];
        int col2 = queries[i][3];
        int min = table[row1-1][col1-1];
        int saved_num = min;
        
        // 상단 회전
        for(int j = col1; j < col2; j++)
        {
            int tmp = table[row1-1][j];
            table[row1-1][j] = saved_num;
            saved_num = tmp;
            
            if(min > saved_num) // 최솟값 갱신
                min = saved_num;
        }
        
        // 우측 회전
        for(int j = row1; j < row2; j++)
        {
            int tmp = table[j][col2-1];
            table[j][col2-1] = saved_num;
            saved_num = tmp;
            
            if(min > saved_num) // 최솟값 갱신
                min = saved_num;
        }
        
        // 하단 회전
        for(int j = col2; j > col1; j--)
        {
            int tmp = table[row2-1][j-2];
            table[row2-1][j-2] = saved_num;
            saved_num = tmp;
            
            if(min > saved_num) // 최솟값 갱신
                min = saved_num;
        }
        
        // 좌측 회전
        for(int j = row2; j > row1; j--)
        {
            int tmp = table[j-2][col1-1];
            table[j-2][col1-1] = saved_num;
            saved_num = tmp;
            
            if(min > saved_num) // 최솟값 갱신
                min = saved_num;
        }
        
        //table[row1-1][col1-1] = saved_num;
        
        answer.push_back(min);
    }
    
    
    return answer;
}
