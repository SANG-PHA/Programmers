#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> numbers; // 공백으로 구분된 숫자를 저장하는 벡터
    
    string tmp;
    for(int i = 0; i < s.size(); i++)
    {   
        if(s[i] != ' ') // 공백이 아니면 tmp에 추가
        {
            tmp += s[i];
            if(i == s.size() - 1) // 마지막 문자면 무조건 벡터에 추가
                numbers.push_back(stoi(tmp));
        }
        else // 공백이면 지금까지 저장된 tmp를 벡터에 추가
        {
            numbers.push_back(stoi(tmp));
            tmp = "";
        }
    }
    
    // 최댓값, 최솟값 찾기
    int min = numbers[0];
    int max = numbers[0];
    
    for(int i = 1; i < numbers.size(); i++)
    {
        if(min > numbers[i])
            min = numbers[i];
        if(max < numbers[i])
            max = numbers[i];
    }
    
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    
    return answer;
}
