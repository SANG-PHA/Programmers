//      효율성 테스트를 통과하지 못한 코드

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 함수 원형
void mix(vector<int> &scovile, int K);
int calc_scovile(int a, int b);


int solution(vector<int> scovile, int K) {
    int answer = 0;
    bool isOverK = true;
    
    sort(scovile.begin(), scovile.end()); // 벡터 오름차순 정렬
    
    while(true)
    {
        // 모든 스코빌 지수 검사
        for(int i = 0; i < scovile.size(); i++)
            if(scovile[i] < K)
            {
                isOverK = false;
                break;
            }
        
        if(isOverK) // 모든 스코빌 지수가 K를 넘으면
            break; // 종료
        
        else if(scovile.size() == 1) // 모든 음식을 섞어도 K를 넘지 못하면
            return -1; // 종료 및 -1 리턴
        
        else // 모든 스코빌 지수가 K를 넘지 못해 음식을 섞어야 하면
            isOverK = true; // 스코빌 지수 검사 조건 초기화
        
        // 음식 섞기
        mix(scovile, K);
        sort(scovile.begin(), scovile.end()); // 벡터 오름차순 정렬
        answer++;
    }
    
    return answer;
}

void mix(vector<int> &scovile, int K)
{
    scovile[0] = calc_scovile(scovile[0],scovile[1]); // 새로 섞은 음식의 스코빌 입력
    scovile.erase(scovile.begin() + 1); // 두 번째 음식 삭제
}

// 음식을 섞었을 때 스코빌 지수를 반환해주는 함수
int calc_scovile(int a, int b)
{
    return a + (b * 2);
}





/// 효율성 테스트를 통과한 코드


#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 함수 원형
void mix(vector<int> &scovile, int K);
int calc_scovile(int a, int b);


int solution(vector<int> scovile, int K) {
    int answer = 0;
    bool isOverK = true;
    
    priority_queue< int, vector<int>, greater<int> > pq(scovile.begin(), scovile.end());
    
    while(pq.size() > 1 && pq.top() < K) // 2개 이상의 음식이 남고, 가장 안 매운 음식의 스코빌 지수가 K보다 작을 때
    {
        int food1 = pq.top();
        pq.pop();
        int food2 = pq.top();
        pq.pop();
        
        pq.push(food1 + (food2 * 2)); // 가장 안매운 2개의 음식을 섞은 후 push
        answer++;
    }
    
    if(pq.top() < K) // 모든 음식을 섞어도 K를 넘지 못할 경우
        return -1;
    
    return answer;
}
