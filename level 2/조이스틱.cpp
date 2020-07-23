#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    
    int *ChangeAlphabet = new int[length]; // 위/아래 이동 횟수
    
    // ChangeAlphabet 초기화
    for(int i = 0; i < length; i++)
        ChangeAlphabet[i] = name[i] - 'A';
    
    // 계산
    bool Done = false;
    int MoveRight = 0, MoveLeft = 0, ChangeCnt = 0;
    int idx = 0;
    
    while(true)
    {
        // 종료 조건 검사, 커서 이동이 필요하면 false
        Done = true;
        for(int i = 0; i < length; i++)
            if(ChangeAlphabet[i] != 0)
                Done = false;
        
        if(Done)
            break;
        
        // 왼쪽/오른쪽 이동
        for(int jump = 0; ; jump++) // *** 각 조건이 개별로 검사되도록 else if문을 쓰지 않는다.
        {
            if(idx + jump < length) // 오른쪽 이동 - 인덱스 초과 X
            {
                if(ChangeAlphabet[idx + jump] != 0)
                {
                    idx += jump; // 인덱스 이동
                    MoveRight += jump; // 조이스틱 조작 횟수 증가
                    break;
                }
            }
            if(idx + jump >= length) // 오른쪽 이동 - 인덱스 초과 O
            {
                if(ChangeAlphabet[(idx+jump) % length] != 0)
                {
                    idx += (idx+jump) % length; // 인덱스 이동
                    MoveRight += jump; // 조이스틱 조작 횟수 증가
                    break;
                }
            }
            if(idx - jump >= 0) // 왼쪽 이동 - 인덱스 초과 X
            {
                if(ChangeAlphabet[idx - jump] != 0)
                {
                    idx = idx - jump; // 인덱스 이동
                    MoveLeft += jump; // 조이스틱 조작 횟수 증가
                    break;
                }
            }
            if(idx - jump < 0) // 왼쪽 이동 - 인덱스 초과 O
            {
                if(ChangeAlphabet[length + (idx - jump)] != 0)
                {
                    idx = length + (idx - jump); // 인덱스 이동
                    MoveLeft += jump; // 조이스틱 조작 횟수 증가
                    break;
                }
            }
        }
        
        // 위/아래 이동
        if(ChangeAlphabet[idx] != 0)
        {
            if(ChangeAlphabet[idx] > 13) // 아래로 이동
            {
                ChangeCnt += 26 - ChangeAlphabet[idx];
                ChangeAlphabet[idx] = 0;
            }
            else // 위로 이동
            {
                ChangeCnt += ChangeAlphabet[idx];
                ChangeAlphabet[idx] = 0;
            }
        }
    }
    
    delete[] ChangeAlphabet;

    return answer = MoveLeft + MoveRight + ChangeCnt;
}
