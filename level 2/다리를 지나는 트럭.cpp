#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    vector<int> left_time; // 각 트럭 별 경과 시간
    vector<int> passed_truck; // 다리를 지난 트럭
    long long current_weight = 0; // 현재 다리에 올라가있는 트럭들의 무게
    
    // 트럭 별 경과 시간 입력
    for(int i = 0; i < truck_weights.size(); i++)
        left_time.push_back(bridge_length);
        
    int time = 0; // 경과 시간
    int truck_idx = 0; // 트럭 벡터의 인덱스
    
    // 트럭이 다 건너지 못했으면 반복
    while(truck_weights.size() != passed_truck.size())
    {
        time++;
        
        // 다리가 견디는 무게가 현재 무게 + 다음 트럭의 무게보다 적으면
        if(weight >= current_weight + truck_weights[truck_idx]) 
        {
            current_weight += truck_weights[truck_idx]; // 현재 무게에 추가
            if(truck_idx < truck_weights.size())
                truck_idx++; // 트럭 인덱스 증가
        }
        
        
        for(int i = 0; i < truck_idx; i++)
        {    
            if(left_time[i] == 1) // 다리를 다 건넜다면
            {
                left_time[i]--; // 남은 시간을 0으로
                current_weight -= truck_weights[i]; // 현재 무게에서 제거
                passed_truck.push_back(truck_weights[i]); // 지나간 트럭에 추가
            }
            else if(left_time[i] > 0) // 아직 건너야 한다면
                left_time[i]--; // 경과 시간 감소
        }
    }
    time++;
    
    return time;
}
