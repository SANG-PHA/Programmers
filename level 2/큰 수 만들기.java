import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder(number); // string보다 StringBuilder가 빠름
        
        int idx; // 탐색 시작 인덱스
        
        for(int j = 0; j < k; j++)
        {
            int length = answer.length() - 1; // ***length() 메소드의 호출이 반복문마다 실행되면 시간을 많이 소모함
            idx = length; // 마지막 인덱스가 가장 작은 숫자일 경우
            for(int i = 0; i < length; i++) // 첫 번째 인덱스부터 탐색 시작
            {
                if(answer.charAt(i) < answer.charAt(i+1)) // 다음 자리 숫자보다 작으면
                {
                    idx = i; // 인덱스 번호 저장
                    break;
                }
            }
            answer.deleteCharAt(idx); // 제거
        }
        
        return answer.toString();
    }
}
