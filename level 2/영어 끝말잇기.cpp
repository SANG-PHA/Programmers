#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> said_words;
    char end_of_word = words[0][words[0].size() - 1];
    said_words.push_back(words[0]);
    int cycle = 1;
    
    for(int i = 1; i < words.size(); i++)
    {
        // 차례 증가
        if(i % n == 0)
            cycle++;
        
        // 끝말을 이어가는지 확인
        if(words[i][0] != end_of_word)
        {
            answer.push_back((i % n) + 1); // 번호
            answer.push_back(cycle); // 차례
            return answer;
        }
        
        // 이전에 말한 단어인지 확인
        for(int j = 0; j < said_words.size(); j++)
        {
            if(words[i] == said_words[j])
            {
                answer.push_back((i % n) + 1); // 번호
                answer.push_back(cycle); // 차례
                return answer;
            }
        }
        
        end_of_word = words[i][words[i].size() - 1]; // 끝말 갱신
        said_words.push_back(words[i]); // 말한 단어 갱신
    }

    // 이상없이 끝났을 때
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}
