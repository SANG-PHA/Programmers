#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string buffer;
    
    if(s[0] != '-') // 양수일 때
        return answer = stoi(s);
    else // 음수일 때
    {
        for(int i = 1; i < s.size(); i++) // -부호를 제외한 숫자 추출
            buffer += s[i];
        return answer = -stoi(buffer); // 정수로 변환
    }
}
