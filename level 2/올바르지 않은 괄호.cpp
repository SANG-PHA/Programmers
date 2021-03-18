#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk; // 괄호를 저장할 스택

    for(int i = 0; i < s.size(); i++) // 문자열 전체 순회
    {
        if(stk.size() == 0 && s[i] == ')') // 스택이 비어있는데 ')'가 온다면
            answer = false; // 올바르지 않은 괄호
        else if(s[i] == '(') // '('이 온다면
            stk.push('('); // 스택에 입력
        else if(stk.top() == '(' && s[i] == ')') // 스택에 '('이 있고, ')'이 온다면
            stk.pop(); // pop()
    }

    if(stk.size() != 0) // 문자열 순회를 마쳤는데 스택이 비어있지 않다면
        answer = false; // 올바르지 않은 괄호
    
    return answer;
}
