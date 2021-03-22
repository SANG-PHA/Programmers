// 시간초과로 인해 해결하지 못한 코드

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> AllMatchNum_Int;
    vector<string> AllMatchNum_String;
    
    sort(numbers.begin(), numbers.end()); // 
    
    // 순열을 이용, 모든 숫자를 사용하여 가능한 모든 숫자 생성
    do{
        string tmp = "";
        
        for(int i = 0; i < numbers.size(); i++)
        {
            tmp += to_string(numbers[i]);
        }
        
        AllMatchNum_String.push_back(tmp);
        
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    
    // 스트링으로 변경된 숫자를 다시 정수로
    for(int i = 0; i < AllMatchNum_String.size(); i++)
        AllMatchNum_Int.push_back(stoi(AllMatchNum_String[i]));
    
    // 내림차순 정렬
    sort(AllMatchNum_Int.begin(), AllMatchNum_Int.end(), greater<>());
    
    
    answer = to_string(AllMatchNum_Int[0]);
    
    return answer;
}

