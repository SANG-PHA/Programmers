class Solution {
    public String solution(String s) {
        int idx = 0; // 단어별로 작/홀수 인덱스 판단하기 위한 변수
        char[] sChars = s.toCharArray(); // 인덱스 사용을 위해 char 배열로 복사
        
        for(int i = 0; i < sChars.length; i++)
        {
            if(sChars[i] == ' ') // 공백이면
            {
                idx = 0; // idx 초기화
                continue;
            }
            else if(idx % 2 == 0 && sChars[i] >= 97 && sChars[i] <= 122 ) // idx가 짝수, 소문자이면
                sChars[i] -= 32; // 대문자로 변경, 아스키코드
            else if(idx % 2 == 1 && sChars[i] >= 65 && sChars[i] <= 90) // idx가 홀수, 대문자이면
                sChars[i] += 32; // 소문자로 변경, 아스키코드
            idx++;
        }
        
        return s = String.valueOf(sChars);
    }
}
