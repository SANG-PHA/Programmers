#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int i;
    for(i = 0; i < arr.size() - 1; i++) // 쓰레기값과의 비교를 피하기 위해 size - 1까지 loop
    {
        if(arr[i] != arr[i+1]) // 다음 인덱스가 다르면 현재 인덱스 값 추가
            answer.push_back(arr[i]);
    }
    
    answer.push_back(arr[i]); // 마지막 원소 추가
    
    return answer;
}
