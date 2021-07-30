#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> vec_str1;
    vector<string> vec_str2;
    
    // 문자열을 소문자로 바꿈
    for(int i = 0; i < str1.size(); i++)
    {
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i < str2.size(); i++)
    {
        str2[i] = tolower(str2[i]);
    }
    
    // 다중집합으로 만들기
    for(int i = 0; i < str1.size() - 1; i++)
    {
        if((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i + 1] >= 'a' && str1[i + 1] <= 'z'))
        {
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i+1];
            vec_str1.push_back(tmp);
        }
    }
    for(int i = 0; i < str2.size() - 1; i++)
    {
        if((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i + 1] >= 'a' && str2[i + 1] <= 'z'))
        {
            string tmp = "";
            tmp += str2[i];
            tmp += str2[i+1];
            vec_str2.push_back(tmp);
        }
    }
    
    int same = 0;
    int sum = 0;
    
    // 교집합 만들기
    vector<int> check_idx;
    for(int i = 0; i < vec_str1.size(); i++)
    {   
        for(int j = 0; j < vec_str2.size(); j++)
        {
            bool IsContinue = false;
            
            // 이미 추가된 원소면 건너뛴다
            for(int k = 0; k < check_idx.size(); k++)
                if(j == check_idx[k])
                    IsContinue = true;
            
            if(IsContinue)
                continue;
            
            if(vec_str1[i] == vec_str2[j])
            {
                same++; // 교집합 크기 증가
                check_idx.push_back(j); // 추가된 원소
                break;
            }
        }
    }
    
    // 합집합 만들기
    check_idx.clear();
    sum = vec_str2.size();
        
    for(int i = 0; i < vec_str1.size(); i++)
    {
        bool IsDuplicated = false;
        
        for(int j = 0; j < vec_str2.size(); j++) // 똑같은 원소가 없으면 추가
        {
            bool IsContinue = false;
            
            // 이미 추가된 원소면 건너뛴다
            for(int k = 0; k < check_idx.size(); k++)
                if(j == check_idx[k])
                    IsContinue = true;
            
            if(IsContinue)
                continue;
            
            if(vec_str1[i] == vec_str2[j])
            {
                IsDuplicated = true;
                check_idx.push_back(j); // 추가된 원소
                break;
            }
        }
        
        if(IsDuplicated == false)
            sum++;
    }
    
    if(same == 0 && sum == 0)
        return 65536;
    
    answer = (float)same / sum * 65536; 
    
    return answer;
}
