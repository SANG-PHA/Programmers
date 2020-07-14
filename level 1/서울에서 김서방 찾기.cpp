#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    
    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i].compare("Kim") == 0)
        {
            string answer = "김서방은 " + to_string(i) + "에 있다";
            return answer; // kim은 반드시 seoul안에 한 번만 포함되어 있으므로 반복문 내에서 리턴
        }
    }    
}
