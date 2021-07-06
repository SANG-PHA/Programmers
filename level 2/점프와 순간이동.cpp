// 재귀함수 버전
// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> battery_arr; // 배터리 사용량을 위한 벡터 전역으로 선언

// 위치, 배터리 사용량 구조체
class info{
    public:
        int location;
        int battery_usage;
};

// 함수 원형
int start(int n);
void jump(int n, info tmp);
void warp(int n, info tmp);
    
int solution(int n)
{
    int ans = 0;
    
    ans = start(n);

    return ans;
}

int start(int n)
{
    info tmp;
    tmp.location = 0;
    tmp.battery_usage = 0;
        
    jump(n, tmp);

    
    sort(battery_arr.begin(), battery_arr.end()); // 벡터 오름차순 정렬
    
    return battery_arr[0]; // 가장 작은 값 반환
}

void jump(int n, info tmp)
{
    tmp.location = tmp.location + 1;
    tmp.battery_usage = tmp.battery_usage + 1;
    
    if(tmp.location == n)
    {
        battery_arr.push_back(tmp.battery_usage);
        return;
    }
    
    else if(tmp.location > n)
        return;
    
    else
    {
        jump(n, tmp);
        warp(n, tmp);
    }
}

void warp(int n, info tmp)
{
    tmp.location = tmp.location * 2;
    
    if(tmp.location == n)
    {
        battery_arr.push_back(tmp.battery_usage);
        return;
    }
    
    else if(tmp.location > n)
        return;
    
    else
    {
        jump(n, tmp);
        warp(n, tmp);
    }
}
