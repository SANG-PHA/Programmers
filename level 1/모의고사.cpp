#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 수포자들의 정답배열
    int first[5] = {1,2,3,4,5};
    int second[8] = {2,1,2,3,2,4,2,5};
    int third[10] = {3,3,1,1,2,2,4,4,5,5};
    int cnt[3] = {0,0,0}; // 맞춘 횟수 배열
    
    // 맞춘 횟수 구하기
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == first[i % 5])
            cnt[0]++;
        if(answers[i] == second[i % 8])
            cnt[1]++;
        if(answers[i] == third[i % 10])
            cnt[2]++;
    }
    
    // 높은 점수 받은 사람 구하기
    int MaxCnt = cnt[0];
    if(MaxCnt < cnt[1])
        MaxCnt = cnt[1];
    if(MaxCnt < cnt[2])
        MaxCnt = cnt[2];
    
    // answers배열에 추가
    for(int i = 0; i < 3; i++){
        if(cnt[i] == MaxCnt)
            answer.push_back(i + 1);
    }
    
    return answer;
}
