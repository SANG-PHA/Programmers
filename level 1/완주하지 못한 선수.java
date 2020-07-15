import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        // 2중 포문을 사용하지 않기 위해 배열 정렬
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        for(int i = 0; i < completion.length; i++) // 완주자배열 크기만큼 반복
        {
            if(!(participant[i].equals(completion[i]))) // 다른 값이 발견되면 return
                return answer = participant[i];
        }
        
        return answer = participant[participant.length - 1]; // 다른 값이 발견되지 않았으면 마지막 값이 다른 값
    }
}
