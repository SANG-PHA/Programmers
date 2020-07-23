#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size = numbers.size();
    int left = 10, right = 12; // *=10, #=12
    
    for(int i = 0; i < size; i++)
    {
        if(numbers[i] == 0) // 숫자가 0이면 11로 바꿔준다
            numbers[i] = 11;
        
        if(numbers[i] % 3 == 1) // 왼손
        {
            left = numbers[i];
            answer += "L";
            continue;
        }
        else if(numbers[i] % 3 == 0) // 오른손
        {
            right = numbers[i];
            answer += "R";
            continue;
        }
        else if(numbers[i] % 3 == 2) // 양손
        {            
            // 1. 왼손, 오른손 거리 구하기
                // 위아래 거리 구하기
            int LeftDistance = abs((int)(numbers[i] / 3.1) - (int)(left / 3.1));
            int RightDistance = abs((int)(numbers[i] / 3.1) - (int)(right / 3.1));
                // 좌우 거리 구하기
            if(left % 3 == 1)
                LeftDistance++;
            if(right % 3 == 0)
                RightDistance++;
            
            // 2. 거리 가까운 손 구하기
            if(LeftDistance > RightDistance) // 오른손이 가까울 때
            {
                right = numbers[i];
                answer += "R";
            }
            else if(RightDistance > LeftDistance) // 왼손이 가까울 때
            {
                left = numbers[i];
                answer += "L";
            }
            else if(RightDistance == LeftDistance) // 거리가 같을 때
            {
                if(hand == "right") // 오른손잡이
                {
                    right = numbers[i];
                    answer += "R";
                }
                else if (hand == "left") // 왼손잡이
                {
                    left = numbers[i];
                    answer += "L";
                }
            }
        }
    }
    
    return answer;
}
