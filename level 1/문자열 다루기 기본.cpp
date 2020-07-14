#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    // 길이 검사
    if(s.size() != 4 && s.size() != 6)
        return answer = false;
    
    // 원소 검사
    for(int i = 0; i < s.size(); i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return answer = false;
    }
    
    return answer;
}
