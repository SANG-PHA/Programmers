#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    sort(s.begin(), s.end(), greater<int>()); // 아스키코드 기준으로 내림차순 정렬
                                              // 소문자가 대문자보다 아스키코드 큼
    answer = s;
    
    return answer;
}
