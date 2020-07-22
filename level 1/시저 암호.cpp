#include <string>
#include <vector>

using namespace std;

string solution(string sChars, int n) {
    
    for(int i = 0; i < sChars.length(); i++)
    {
        if(sChars[i] == ' ') // 공백일 경우
            continue;
        else if(sChars[i] >= 65 && sChars[i] <= 90) // 대문자일 경우
        {
            if(sChars[i] + n > 90)
                sChars[i] = (64 + (n + sChars[i] - 90));
            else sChars[i] += n;
        }
        else if(sChars[i] >= 97 && sChars[i] <= 122) // 소문자일 경우
        {
            if(sChars[i] + n > 122)
                sChars[i] = (96 + (n + sChars[i] - 122));
            else sChars[i] += n;
        }
    }
    return sChars;
}
