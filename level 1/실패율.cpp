#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> FailRateArr; // 각 스테이지의 실패율을 저장할 벡터
    
    // 각 스테이지의 실패율 구하기
    for(int i = 1; i <= N; i++) // 1~N 스테이지
    {
        double FailRate = 0;
        int a = 0;
        int b = 0;
        for(int j = 0; j < stages.size(); j++) // 사용자 수만큼 반복
        {
            if(stages[j] == i)
                a++;
            if(stages[j] >= i)
                b++;
        }
        
        // 스테이지에 도달한 플레이어가 없는 경우 실패율은 0
        if(b == 0)
            FailRate = 0;
        else
            FailRate = (double)a/b;
        
        FailRateArr.push_back(FailRate);
    }

    
    // 실패율이 높은 스테이지부터 내림차순
    for(int j = 0; j < N; j++)
    {
        double max = -1;
        int idx = 0;
        
        for(int i = 0; i < N; i++) // 실패율이 가장 높은 스테이지 찾기
        {
            if(FailRateArr[i] > max)
            {
                max = FailRateArr[i];
                idx = i;
            }
        }
        
        answer.push_back(idx+1);
        FailRateArr[idx] = -2;
    }
    
    
    return answer;
}
