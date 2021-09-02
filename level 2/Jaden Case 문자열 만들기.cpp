#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int idx = 1;
    for(int i = 0; i < s.size(); i++)
    {
        // 첫 글자가 알파벳 소문자면 대문자로 변환
        if(idx == 1 && (s[i] >= 'a' && s[i] <= 'z'))
            s[i] = toupper(s[i]);
        
        // 공백일 때
        else if(s[i] == ' ')
            idx = 0;
        
        // 첫 글자가 아니고 대문자면 소문자로 변환
        else if(idx != 1 && (s[i] >= 'A' && s[i] <= 'Z'))
            s[i] = tolower(s[i]);
        
        idx++;
        answer += s[i];
    }
    
    return answer;
}
