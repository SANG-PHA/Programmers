#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = n;
    int powN = 0;
    
    vector<int> ternary; // 3진법
    
    // n보다 작은 3의 제곱 찾기
    for(int i = 1; ; i++)
    {
        if(pow(3,i) > n)
        {
            powN = i-1;
            break;
        }
    }

    // 3진법 벡터 초기화
    for(int i = 0; i <= powN; i++)
        ternary.push_back(0);
    
    
    int idx = 0;
    // 3진법 벡터 구성
    while(num >= 1)
    {
        if(num >= pow(3,powN))
        {
            num -= pow(3,powN);
            ternary[idx]++;
        }
        else
        {
            powN--;
            idx++;
        }
    }
    
    // 3진법 앞뒤 반전
    for(int i = 0; i < ternary.size() / 2; i++)
    {
        int tmp = ternary[i];
        ternary[i] = ternary[ternary.size() - 1 - i];
        ternary[ternary.size() - 1 - i] = tmp;
    }
    
    // 10진법으로 표현
    powN = 0;
    for(int i = ternary.size() - 1; i >= 0 ; i--)
    {
        answer += pow(3,powN) * ternary[i];
        powN++;
    }
    
    return answer;
}
