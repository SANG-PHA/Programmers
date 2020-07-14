#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool PrimeNumber[n + 1]; // 소수임을 확인하는 bool배열, 0번 인덱스는 안쓰기 때문에 n+1의 메모리 할당
    fill_n(PrimeNumber, n + 1, true); // true로 초기화
    
    int root = (int)sqrt(n); // n의 제곱근
    
    // 에라토스테네스의 채
    for(int i = 2; i <= root; i++) // 2부터 root까지
        if(PrimeNumber[i]) // 소수를 찾으면
            for(int j = i; j * i < n + 1; j++) // 그의 배수들은 false로 입력
                PrimeNumber[j*i] = false;
    
    // 소수의 개수
    for(int i = 2; i < n + 1; i++)
        if(PrimeNumber[i])
            answer++;
    
    return answer;
}
