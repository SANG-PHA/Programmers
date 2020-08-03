#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int digit = 0, tmp = x;
    
    while(tmp > 0)
    {
        digit = digit + (tmp % 10); // 마지막 자릿수 덧셈
        tmp /= 10;    
    }
    
    if(x % digit == 0)
        answer = true;
    else answer = false;
    
    return answer;
}
