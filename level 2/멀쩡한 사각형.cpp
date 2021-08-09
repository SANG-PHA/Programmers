// 틀린 코드
// w,h가 1억까지 고려되므로 double로는 두 숫자의 곱을 표현할 수 없어
// 오버플로우 발생

#include <cmath>
#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = w * h;
    long long cnt = 0;
    
    // 너비, 높이를 x,y축으로 생각하여 함수 정의
    double dx = -(double)h / w; // 기울기
    long double y; // y = -h/w * x + h
    long long preY = h;
    
    for(int i = 0; i <= w; i++)
    // 0부터 w까지 반복
    // 1씩 증가하면서 거치는 사각형의 갯수를 구하여 더해나감
    // 시작점과 도착점의 y좌표를 저장한다
    {
        y = (-(long long)h * (double)i / (long long)w) + (long long)h; // 시작점
        cnt += preY - floor(y); // floor(y)가 도착점, 내림 함수 사용
        preY = ceil(y); // 새로운 시작점, 올림 함수 사용
    }
    
    return answer - cnt;
}

// 정답 코드
// 사용할 수 없는 정사각형의 발생에 일정한 패턴이 있음
// w,h의 최대공약수 만큼 반복
// 사용할 수 있는 사각형의 개수는 (w * h) - (w + h- 최대공약수)

using namespace std;

int gcd(int w, int h){
    int c;
    while (h != 0)
    {
        c = w % h;
        w = h;
        h = c;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h - (w+h);
    answer += gcd(w,h);
    return answer;
}
