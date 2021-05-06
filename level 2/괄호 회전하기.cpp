#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isOK = true;
    stack<char> stk;
    
    for(int k = 0; k <= s.size() - 1; k++)
    {
        // 올바른 괄호 문자열인지 확인
        for(int i = 0; i < s.size(); i++)
        {
            
            // 열리는 괄호는 무조건 push
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
                continue;
            }
            
            // 스택이 비어있는데 닫히는 괄호가 오면 올바르지 않은 괄호 문자열이므로 반복문 종료
            if(stk.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
            {
                isOK = false;
                break;
            }
            
            // 스택의 top과 같으면 pop, 아니면 push
            else if((stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']'))
                stk.pop();
            
            else
            {
                isOK = false;
                break;
            }
        }
        
        // 스택이 비어있으면 올바른 괄호 문자열
        if(isOK && stk.empty())
            answer++;
        isOK = true;
        
        // 문자열 회전
        char tmp = s[0];
        for(int i = 0; i < s.size() - 1; i++)
            s[i] = s[i+1];
        s[s.size()-1] = tmp;
        
        // 스택 비우기
        while(!stk.empty())
            stk.pop();
    }
    return answer;
}
