#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(), people.end(), greater<int>()); // 내림차순 정렬
    
    int weight = 0, cnt = 0, back = 0; // 현재 보트에 탑승한 무게, 인원 수, 뒤에서 부터의 인덱스
    
    for(int i = 0; i < size; i++)
    {
        if(weight + people[i] <= limit && cnt < 2) // 가장 무거운 사람부터 보트에 탈 수 있는 조건이면
        {
            weight += people[i]; // 탑승
            cnt++;
            
            if(weight + people[size - 1 - back] <= limit && cnt < 2) // 가장 가벼운 사람 검사
            {
                answer++; // 탑승 및 출발
                weight = 0;
                cnt = 0;
                back++;
            }
            else // 가장 가벼운 사람이 못타면 혼자 출발
            {
                answer++;
                weight = 0;
                cnt = 0;
            }
            
            if(i >= size-1-back) // 종료 조건
                break;
        }
    }
    return answer;
}
