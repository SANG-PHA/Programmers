#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt = 0;
    
    while(cnt < 500)
    {
        if(num == 1) // 1일 때
            break;
        
        cnt++;
        
        if(num % 2 == 0) // 짝수일 때
            num /= 2;
        else if(num % 2 == 1) // 홀수일 때
            num = (num * 3) + 1;
    }
    
    if(cnt >= 500)
        cnt = -1;
    
    return cnt;
}
