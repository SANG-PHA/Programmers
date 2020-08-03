#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int TheNumberOfDays[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; // x월의 마지막 일
    string date[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"}; // 요일 - 원형 큐로 구현
    
    int idx_date = 0; // 원형 큐 인덱스
    for(int i = 1; i < a; i ++) // a월 전까지의 요일 계산
        for(int j = 1; j <= TheNumberOfDays[i-1]; j++)
            idx_date = (idx_date + 1) % 7;
    
    for(int i = 1; i < b; i++) // a월의 b일 요일 계산
        idx_date = (idx_date + 1) % 7;
    
    return date[idx_date];
}
