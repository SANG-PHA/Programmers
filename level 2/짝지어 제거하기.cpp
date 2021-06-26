// 틀린 코드
// 효율성 테스트에서 통과하지 못함

#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    bool isDone = true;

    while(true)
    {
        isDone = true;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i-1])
            {
                s.replace(i-1,2,"");
                i-= 2;
                isDone = false;
            }
        }
        
        if(isDone)
            break;
        
    }
    
    if(s.size() == 0)
        return 1;
    else 
        return 0;
}

// 정답 코드
// 스택을 사용하여 시간복잡도 O(n)으로 구성

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    string tmp;
    int top = -1;
    
    // 문자열이 홀수면 무조건 0 리턴
    if(s.size() % 2 == 1)
        return 0;

    for(int i = 0; i < s.size(); i++)
    {
        // 스택에 알파벳 집어넣기
        tmp += s[i];
        top++;
        
        // 스택의 크기가 1초과이고 짝지어 제거하기 조건이 맞춰지면
        if(top != 0 && tmp[top - 1] == tmp[top])
        {
            tmp.replace(top - 1, 2, ""); // replace를 사용하여 제거
            top-=2; // top 감소
        }
    }
    
    if(tmp.size() == 0)
        return 1;
    else 
        return 0;
}
