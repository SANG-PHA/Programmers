#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer;
    
    for(int i = 0; i < numbers.size()-1; i++)
        for(int j = i+1; j < numbers.size(); j++)
        {
            int tmp = numbers[i] + numbers[j]; // 두 숫자의 덧셈
            
            bool isOK = true;
            // 중복된 결과인지 검사
            for(int k = 0; k < answer.size(); k++)
                if(answer[k] == tmp)
                    isOK = false;
            
            if(isOK) // 중복되지 않으면 추가
                answer.push_back(tmp);
        }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
