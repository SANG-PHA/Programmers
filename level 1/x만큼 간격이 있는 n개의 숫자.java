class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        
        long tmp = x;
        answer[0] = x;
        for(int i = 1; i < n; i++)
        {
            tmp += x;
            answer[i] = tmp;
        }
        
        return answer;
    }
}
