// 효율성 통과 못한 코드

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> infos;
    vector<vector<string>> queries;
    
    // 참가자별 info 분리
    for(int i = 0; i < info.size(); i++)
    {
        vector<string> personal_info;
        string tmp = "";
        
        for(int j = 0; j < info[i].size(); j++)
        {
            if(info[i][j] == ' ')
            {
                personal_info.push_back(tmp);
                tmp = "";
            }
            else if(j == info[i].size() - 1)
            {
                tmp += info[i][j];
                personal_info.push_back(tmp);
            }
            else
                tmp += info[i][j];
        }
        
        infos.push_back(personal_info);
    }
    
    // 쿼리 분리
    for(int i = 0; i < query.size(); i++)
    {
        vector<string> each_query;
        string tmp = "";
        int empty_cnt = 0;
        
        for(int j = 0; j < query[i].size(); j++)
        {
            if(query[i][j] == ' ')
            {
                empty_cnt++;
                each_query.push_back(tmp);
                tmp = "";
                
                if(empty_cnt <= 3)
                    j += 4;
            }
            else if(j == query[i].size() - 1)
            {
                tmp += query[i][j];
                each_query.push_back(tmp);
            }
            else
                tmp += query[i][j];
        }
        
        queries.push_back(each_query);
    }
    
    
    // 조건 확인
    for(int i = 0; i < queries.size(); i++)
    {
        vector<bool> isOK;
        for(int i = 0; i < infos.size(); i++)
            isOK.push_back(true);
        
        for(int j = 0; j < infos.size(); j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(queries[i][k] == "-")
                    continue;
                else if(isOK[j] && k == 4)
                {
                    if(stoi(queries[i][k]) > stoi(infos[j][k]))
                        isOK[j] = false;
                }
                else if(isOK[j] && queries[i][k] != infos[j][k])
                    isOK[j] = false;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < isOK.size(); i++)
            if(isOK[i])
                cnt++;
        answer.push_back(cnt);
    }
    
    return answer;
}
