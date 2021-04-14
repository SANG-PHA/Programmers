#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 노란색이 1개일 경우
    if(yellow == 1)
    {
        answer.push_back(3);
        answer.push_back(3);
        return answer;
    }
    
    // 그 외의 경우
    for(int i = 1; i <= yellow; i++) // 완전탐색으로 약수를 찾는다
    {
        if(yellow % i == 0)
        {
            if(((i * 2) + ((yellow / i) * 2)) + 4 == brown) // 노란색 행,열에 따른 갈색 격자 갯수 구하는 식
            {
                answer.push_back(yellow / i + 2);
                answer.push_back(i + 2);
                return answer;
            }
        }
    }
}
