#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsVisited(int idx, vector<int> idxs)
{
    for(int i = 0; i < idxs.size(); i++)
    {
        if(idxs[i] == idx)
            return true;
    }
    
    return false;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int tmp_budget = 0;
    int min, idx; // 현재 최솟값과 인덱스
    vector<int> idxs; // 이미 방문한 인덱스들의 벡터
    
    for(int i = 0; i < d.size() ; i++) // d 벡터 한 번 반복
    {
        min = 100001; // 초기 최솟값과 인덱스 값
        idx = -1;
        
        // d 내에서 최솟값 찾기
        for(int j = 0; j < d.size(); j++)
        {
            if(d[j] <= min && !(IsVisited(j, idxs))) // 최솟값이고 방문하지 않았다면
            {
                min = d[j]; // 업데이트
                idx = j;
            }
        }
    
        // 예산 더하기
        if(tmp_budget + min <= budget) // 현재 예산에 최솟값을 더한게 최종 예산보다 작거나 같다면
        {
            // 업데이트
            tmp_budget += min;
            answer ++;
            idxs.push_back(idx); // 방문 벡터에 인덱스 추가
        }
        else
            break; // 예산이 넘으면 break
    }
    
    return answer;
}
