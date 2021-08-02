#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++)
    {
        bool isOver = false;
            
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                // 해당 좌석이 P이면 검사 시작
                if(places[i][j][k] == 'P')
                {
                    // 1칸 이내의 거리두기 확인
                    // 상,하,좌,우 거리두기 확인
                    if(j - 1 >= 0) // 상
                    {
                        if(places[i][j-1][k] == 'P')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(j + 1 <= 4) // 하
                    {
                        if(places[i][j+1][k] == 'P')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(k - 1 >= 0) // 좌
                    {
                        if(places[i][j][k-1] == 'P')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(k + 1 <= 4) // 우
                    {
                        if(places[i][j][k+1] == 'P')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    // 대각선 확인
                    if(j - 1 >= 0 && k - 1 >= 0) // 좌상
                    {
                        if(places[i][j-1][k-1] == 'P' && (places[i][j-1][k] != 'X' || places[i][j][k-1] != 'X'))
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(j - 1 >= 0 && k + 1 <= 4) // 우상
                    {
                        if(places[i][j-1][k+1] == 'P' && (places[i][j-1][k] != 'X' || places[i][j][k+1] != 'X'))
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(j + 1 <= 4 && k - 1 >= 0) // 좌하
                    {
                        if(places[i][j+1][k-1] == 'P' && (places[i][j+1][k] != 'X' || places[i][j][k-1] != 'X'))
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(j + 1 <= 4 && k + 1 <= 4) // 우하
                    {
                        if(places[i][j+1][k+1] == 'P' && (places[i][j+1][k] != 'X' || places[i][j][k+1] != 'X'))
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                
                    // 2칸 이내의 거리두기 확인
                    if(j - 2 >= 0) // 상
                    {
                        if(places[i][j-2][k] == 'P' && places[i][j-1][k] != 'X')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(j + 2 <= 4) // 하
                    {
                        if(places[i][j+2][k] == 'P' && places[i][j+1][k] != 'X')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(k - 2 >= 0) // 좌
                    {
                        if(places[i][j][k-2] == 'P' && places[i][j][k-1] != 'X')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                    if(k + 2 <= 4) // 우
                    {
                        if(places[i][j][k+2] == 'P' && places[i][j][k+1] != 'X')
                        {
                            answer.push_back(0);
                            isOver = true;
                            break;
                        }
                    }
                }
            }
            
            if(isOver)
                break;
        }
        
        if(!isOver)
            answer.push_back(1);
    }
 
    return answer;
}
