class Solution {
    // 최대공약수
    int GCD(int a, int b){
        while(b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        
        return a;
    }
    
    // 최소공배수
    int LCM(int a, int b){
        return a * b / GCD(a,b);
    }
    
    public int[] solution(int n, int m) {
        int[] answer = { GCD(n,m), LCM(n,m)};
        
        return answer;
    }
}
