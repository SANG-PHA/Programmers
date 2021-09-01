#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i = 0; i < scores.size(); i++)
    {
        
        // 최대 점수, 최소 점수 구하기
        int min = scores[0][i]; int max = scores[0][i];
        for(int j = 0; j < scores.size(); j++)
        {
            if(min > scores[j][i])
                min = scores[j][i];
            if(max < scores[j][i])
                max = scores[j][i];
        }
        
        // 자신이 준 점수가 최소, 최대인지 확인
        bool isMAXorMIN = false;
        if(min == scores[i][i] || max == scores[i][i])
            isMAXorMIN = true;
        
        // 자신이 준 점수가 유일한 최소, 최대인지 확인
        bool isOnly = false;
        if(isMAXorMIN == true)
        {
            isOnly = true;
            if(scores[i][i] == max)
            {
                for(int j = 0; j < scores.size(); j++)
                {
                    if(j == i)
                        continue;
                
                    if(max == scores[j][i])
                    {
                        isOnly = false;
                        break;
                    }
                }
            }
            else if(min == scores[i][i])
            {
                for(int j = 0; j < scores.size(); j++)
                {
                    if(j == i)
                        continue;
                
                    if(min == scores[j][i])
                    {
                        isOnly = false;
                        break;
                    }
                }
            }
        }
        
        // 학점 계산
        int sum = 0;
        if(isOnly == true) // 자신의 점수가 유일한 최고 or 최저일 때
        {
            for(int j = 0; j < scores.size(); j++)
            {
                if(j == i)
                    continue;
                
                sum += scores[j][i];
                cout << scores[j][i] << " ";
            }
            
            sum = sum / (scores.size() - 1);
        }
        
        else // 그 외
        {
            for(int j = 0; j < scores.size(); j++)
            {
                sum += scores[j][i];
                cout << scores[j][i] << " ";
            }
            
            sum = sum / scores.size();
        }
        cout << endl;
            
        if(sum < 50)
            answer += "F";
        else if(sum < 70)
            answer += "D";
        else if(sum < 80)
            answer += "C";
        else if(sum < 90)
            answer += "B";
        else 
            answer += "A";
    }
    
    return answer;
}
