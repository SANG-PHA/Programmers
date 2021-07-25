#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    // answer배열 0으로 초기화
    for(int i = 0; i < prices.size(); i++)
        answer.push_back(0);
    
    // 시간 입력
    for(int i = 0; i < prices.size() - 1; i++)
    {
        int time = 0;
        
        for(int j = i + 1; j < prices.size(); j++)
        {
            if(prices[i] <= prices[j]) // 가격이 떨어지지 않으면
            {
                time++; // 시간 증가
                if(j == prices.size() - 1) // 마지막 인덱스에 도착했으면
                    answer[i] = time; // 시간 입력
            }
            else if(j == i + 1) // 바로 다음 인덱스에서 가격이 떨어졌으면
            {
                answer[i] = 1; // 1 입력
                break;
            }
            else // 그 외 인덱스에서 가격이 떨어졌으면
            {
                answer[i] = ++time; // 증가한 시간 입력
                break;
            }
        }
    }
    
    return answer;
}
