#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    bool isNotDone = true;
    int checked = 0; // 완료된 작업 인덱스
    
    do
    {
        // 하루 동안의 작업
        for(int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
        
        // 배포된 작업 확인
        int cnt = 0;
        for(int i = checked; i < progresses.size(); i++)
        {
            if(progresses[i] >= 100)
            {
                cnt++;
                checked++;
            }
            else
                break;
        }
        
        // 배포된 작업 수 추가
        if(cnt != 0)
            answer.push_back(cnt);
        
        // 배포가 모두 완료되었는지 확인
        for(int i = 0; i < progresses.size(); i++)
        {
            if(progresses[i] < 100)
                break;
            else if(i == progresses.size() - 1 && progresses[i] >= 100)
                isNotDone = false;
        }
    }while(isNotDone);
    
    return answer;
}
