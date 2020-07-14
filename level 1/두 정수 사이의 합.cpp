#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long small_num;
    
    if(a < b) // 작은 수 구하기
        small_num = a;
    else small_num = b;
    
    for(int i = 0; i <= abs(a-b); i++) // 두 수의 차이만큼 반복
    {
        answer += small_num;
        small_num++;
    }
    
    return answer;
}
