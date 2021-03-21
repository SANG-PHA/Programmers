#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> calc; // 계산된 각 점수들의 벡터
    int score = 0; // 점수
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        if(dartResult[i] == '1' && dartResult[i+1] == '0') // 숫자가 10인지 검사
        {
            score = 10;
            i++;
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9') // 0~9
        {
            score = dartResult[i] - 48;
        }
        else if(dartResult[i] == 'S') // S,D,T일 경우 n제곱 후 벡터에 추가
        {
            calc.push_back(pow(score, 1));
        }
        else if(dartResult[i] == 'D')
        {
            calc.push_back(pow(score, 2));
        }
        else if(dartResult[i] == 'T')
        {
            calc.push_back(pow(score, 3));
        }
        else if(dartResult[i] == '*')
        {
            if(calc.size() == 1) // 첫 점수면 해당 값만 2배
                calc[0] *= 2;
            else // 이전, 현재 값 2배
            {
                calc[calc.size()-2] *= 2;
                calc[calc.size()-1] *= 2;
            }
        }
        else if(dartResult[i] == '#')
        {
            calc[calc.size()-1] *= -1;
        }
    }
    
    // 총 점수 계산
    for(int i = 0; i < calc.size(); i++)
        answer += calc[i];
    
    return answer;
}
