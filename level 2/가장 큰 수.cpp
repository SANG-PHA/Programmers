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



// sort() 실행 시, 기준이 되는 비교 함수를 재정의.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://mungto.tistory.com/22 참조
// 합친 문자 비교해서 큰순으로 정렬하기, ex ) 6, 10 이 있다면 610과 106하고 어떤게 큰지 비교
// 610이 더크므로 6, 10순으로 정렬하게 된다.
bool cmp(string a, string b) 
{
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    
    //string으로 바꾼후 벡터에 집어넣는다.
    for (auto num : numbers)
        temp.push_back(to_string(num));
    
    //더할때 오름차순으로 정렬한다.
    sort(temp.begin(), temp.end(), cmp);
    
    //처음 숫자가 0이라면 0을 반환 => 앞서 정의한 cmp함수에 의해 0이 맨 뒤에 위치한다.
    if (temp[0] == "0")        
        return "0";
    
    //처음부터 끝까지 문자열 합치고 리턴
    for (auto num : temp)
    {
        answer += num;
    }
    return answer;
}
