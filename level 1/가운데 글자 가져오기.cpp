#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int size = s.size() / 2;
    
    if(s.size() % 2 == 0) // 짝수일 때
    {
        answer += s[size - 1];
        answer += s[size];
    }        
    
    
    else // 홀수일 때
        answer += (s[size]);
    
    return answer;
}
