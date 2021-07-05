#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void func(int num, vector<int> checked); // 함수 원형

int answer = 0;
vector<char> arr; // 숫자가 들어갈 벡터 선언
vector<int> nums; // 생성된 정수가 들어갈 벡터 선언


int solution(string numbers) {
    vector<int> checked; // 이미 탐색된 인덱스가 들어갈 배열
    
    // 흩어진 숫자를 벡터에 입력
    for(int i = 0; i < numbers.length(); i++)
        arr.push_back(numbers[i]);

    // 완전탐색
    for(int num = 0; num < arr.size(); num++)
        func(num, checked);
    
    // 소수 확인
    for(int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        for(int k = 1; k <= nums[i]; k++)
        {
            if(nums[i] % k == 0)
                cnt++;
        }
        if(cnt == 2)
            answer++;
    }
    
    return answer;
}

void func(int num, vector<int> checked) {
        
    checked.push_back(num); // 탐색된 인덱스 입력
    
    // 정수 생성
    string tmp = "";
    for(int j = 0; j < checked.size(); j++)
        tmp += arr[checked[j]];
    int tmp2 = stoi(tmp);
        
    if(find(nums.begin(), nums.end(), tmp2) == nums.end()) // 중복되는 숫자가 없다면
    {
        nums.push_back(tmp2);
    }
    
    if(checked.size() == arr.size()) // 완전탐색이 종료됐을 경우
        return;
    else{
        // 다음 재귀 호출
        for(int i = 0; i < arr.size(); i++)
        {
            if(find(checked.begin(), checked.end(), i) == checked.end()) // 탐색되지 않은 인덱스라면
                func(i, checked); // 재귀함수 호출
        }
    }       
}
