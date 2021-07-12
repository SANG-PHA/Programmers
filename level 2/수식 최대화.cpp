#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long calc(char Opt, vector<char> Operator, vector<long long> Operand, vector<char> check);

long long solution(string expression) {
    long long answer = 0;
    string tmp = "";
    
    vector<char> Operator; // 연산자 벡터
    vector<long long> Operand; // 피연산자 벡터
    vector<char> check; // 이미 연산된 연산자를 확인하는 벡터
    
    // check 초기화
    check.push_back('+');
    check.push_back('-');
    check.push_back('*');
    
    // 연산자와 피연산자 분리
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else
        {
            Operand.push_back(stoi(tmp));
            tmp = "";
            Operator.push_back(expression[i]);
        }
    }
    Operand.push_back(stoi(tmp));
    
    // 가장 큰 값 계산
    answer = max(abs(calc('+', Operator, Operand, check)), abs(calc('-', Operator, Operand, check)));
    answer = max(answer, abs(calc('*', Operator, Operand, check)));
    
    return answer;
}

long long calc(char Opt, vector<char> Operator, vector<long long> Operand, vector<char> check)
{
    // 현재 연산자를 check 벡터에서 삭제
    for(int i = 0; i < check.size(); i++)
        if(check[i] == Opt)
            check.erase(check.begin() + i);
    
    // 연산
    for(int i = 0; i < Operator.size(); i++)
    {
        if(Operator[i] == Opt)
        {
            switch(Opt)
            {
                case '+':
                    Operand[i] = Operand[i] + Operand[i+1];
                    break;
                case '-':
                    Operand[i] = Operand[i] - Operand[i+1];
                    break;
                case '*':
                    Operand[i] = Operand[i] * Operand[i+1];
                    break;
            }
            
            Operand.erase(Operand.begin() + (i+1));
            Operator.erase(Operator.begin() + i);
            i--;
        }
    }
    
    // 반환
    if(check.size() == 2)
        return max(abs(calc(check[0], Operator, Operand, check)), abs(calc(check[1], Operator, Operand, check)));
    else if(check.size() == 1)
        return abs(calc(check[0], Operator, Operand, check));
    else
        return Operand[0];
}
