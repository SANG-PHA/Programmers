// 완전탐색 실행시간 초과
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int search(string word, string check, char appended, int depth, int& answer, bool& isOver, vector<char> chars)
{
    // 종료 조건
    if(isOver)
        return answer;
    if(word == check)
    {
        isOver = true;
        return answer;   
    }        
    if(depth == 6)
        return 0;
    
    // 알파벳 추가
    check += appended;
    
    // 재귀 호출
    answer++;
    for(int i = 0; i < chars.size(); i++)
        search(word, check, chars[i], depth++, answer, isOver, chars);
}

void set_vector(vector<char>& chars)
{
    chars.push_back('A');
    chars.push_back('E');
    chars.push_back('I');
    chars.push_back('O');
    chars.push_back('U');
}

int solution(string word) {
    int answer = 1;
    bool isOver = false;
    vector<char> chars;
    
    set_vector(chars);
    
    for(int i = 0; i < 5; i++)
        answer = search(word, "", chars[i], 1, answer, isOver, chars);
    
    return answer;
}


// DFS 완전탐색으로 다시 구성
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void DFS(string s, vector<string>& dict){
    if(s.size() == 5)
        return;
    
    for(auto c : string("AEIOU"))
    {
        string tmp = s + c;
        dict.push_back(tmp);
        DFS(tmp, dict);
    }
}


int solution(string word) {
    int answer = 0;
    vector<string> dict;
    
    DFS("", dict);
    sort(dict.begin(), dict.end());
    answer = lower_bound(dict.begin(), dict.end(), word) - dict.begin() + 1;
    
    return answer;
}
