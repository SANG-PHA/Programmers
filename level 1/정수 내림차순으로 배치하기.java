import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        ArrayList<Long> partial = new ArrayList<>(); // 각 자릿수 숫자를 담을 ArrayList
        
        // 자릿수 별로 쪼개기
        while(n > 0) // 10의 자릿수 이상 일때
        {
            partial.add(n % 10); // 나머지연산을 이용해 1의 자릿수부터 추가
            n = n / 10;
        }
        
        // 내림차순 정렬
        Collections.sort(partial);
        Collections.reverse(partial);
        
        // 자릿수 합치기
        for(int i = 0; i < partial.size(); i++)
        {
            answer *= 10;
            answer += partial.get(i);
        }
        
        return answer;
    }
}
