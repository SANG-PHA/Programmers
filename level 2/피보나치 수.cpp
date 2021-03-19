#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    
    long long param1 = 0, param2 = 1, result = 1;
    
    // 시간 효율을 위해 재귀가 아닌 반복으로 피보나치 구현
    for(int i = 2; i <= n; i++)
    {
        // (A + B) % C = ((A % C) + (B % C)) % C 성질을 이용, 정수 범위를 벗어나지 않게 계산
        result = (param1 + param2) % 1234567;
        param1 = param2 % 1234567;
        param2 = result;
    }
    
    return result % 1234567;
}
