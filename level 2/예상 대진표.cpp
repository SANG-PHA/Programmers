#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int power = 0;
    vector<int> table;
    vector<int> idx;
    
    // n이 2의 몇 제곱인지 구하기
    for(int i = n; i > 1; i /= 2)
        power++;
    
    // 토너먼트 테이블 구성
    for(int i = 0; i < n; i++)
        table.push_back(i+1);
    
    // 대진
    for(int i = 0; i < power; i++)
    {
        for(int j = 0; j < table.size(); j += 2)
        {   
            // a와 b가 만났을 때
            if((table[j] == a && table[j+1] == b) || (table[j] == b && table[j+1] == a))
            {
                return i+1;
            }
            // 대진에 a,b가 없을 경우
            else if(table[j] != a && table[j+1] != b && table[j] != b && table[j+1] != a )
                idx.push_back(table[j]);
            // 앞 번호가 a나 b일 경우
            else if(table[j] == a || table[j] == b)
                idx.push_back(table[j]);
            // 뒷 번호가 a나 b일 경우
            else if(table[j+1] == a || table[j+1] == b)
                idx.push_back(table[j+1]);
        }
    
        table.clear();
        // 진 사람 제거
        for(int j = 0; j < idx.size(); j++)
            table.push_back(idx[j]);
        
        idx.clear();
    }
}
