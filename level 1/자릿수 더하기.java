public class Solution {
    public int solution(int n) {
        int answer = 0;

        // 자릿수 별로 쪼개기
        while(n > 0)
        {
            answer += n % 10;
            n = n / 10;
        }

        return answer;
    }
}
