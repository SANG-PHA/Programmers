#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    int picked = 0; 
    
    // 1. 인형뽑기
    for(int i = 0; i < moves.size(); i++) 
    {        
        for(int k = 0; k < board[1].size(); k++)
        {
            if(board[k][moves[i] - 1] != 0)
            {
                picked = board[k][moves[i] - 1];
                board[k][moves[i] - 1] = 0;
                break;
            }
        }
        
        // 2. 바구니에 삽입
        if(picked != 0)
            bucket.push_back(picked); 
        picked = 0;
        
        // 3. 인형 터지는 조건 탐색
        if(bucket.size() > 1) // 바구니의 원소 개수가 2개 이상일 때
        {
            if(bucket[bucket.size() - 1] == bucket[bucket.size() - 2]) // 인형이 2개 이상 이어지면
            {
                answer+= 2; // 정답 횟수 증가
                bucket.pop_back(); // 바구니에 원소 제거
                bucket.pop_back(); // 바구니에 원소 제거
                
            }
        }
    }
        
    return answer;
}
