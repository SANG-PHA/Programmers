#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int i = 0; i < commands.size(); i++)
    {
        // commands 조건에 따라 tmp 벡터에 원소 추가
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
            tmp.push_back(array[j]);
        
        sort(tmp.begin(), tmp.end()); // tmp 벡터 정렬
        answer.push_back(tmp[commands[i][2] - 1]); // n번째 해당하는 값 answer에 추가
        tmp.clear(); // tmp 벡터 초기화
    }
    
    return answer;
}
