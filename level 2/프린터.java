import java.util.*;

// 데이터구조 <문서, 우선순위>
class doc{
    public char ch;
    public int prior;
    
    public doc(char ch_, int prior_)
    {
        ch = ch_;
        prior = prior_;
    }
}

class Solution {
    public int solution(int[] priorities, int location) {
        
        ArrayList<doc> wait = new ArrayList<>(); // 인덱스를 통한 값 접근을 위해 ArrayList 사용
        
        // 데이터 삽입
        char character = 'A';
        for(int i = 0; i < priorities.length; i++)
        {
            wait.add(new doc(character, priorities[i]));
            character += 1;
        }
        
        char key = wait.get(location).ch; // 반환되어야 할 문서 저장
        
        // 인쇄
        boolean IsReturned = false; // 원하는 location의 문서가 반환되었는가
        int cnt = 0; // 인쇄된 순서
        
        while(!IsReturned)
        {
            doc tmp = wait.get(0);

            for(int i = 1; i < wait.size(); i++)
            {   
                if(tmp.prior < wait.get(i).prior) // 우선순위가 더 큰 값이 발견되면 맨 뒤로 이동
                {
                    wait.remove(0);
                    wait.add(tmp);
                    tmp = null;
                    break;
                }
            }
            
            if(tmp != null) // tmp != null 이면 우선순위가 제일 높으므로 인쇄되어야 함
            {
                if(tmp.ch == key) // 인쇄된 문서가 찾는 키 값이면
                    IsReturned = true; // while문 종료
                cnt++; // 인쇄된 순서 증가
                wait.remove(0); // 인쇄되었으므로 리스트에서 삭제
            }
        }
        
        return cnt;
    }
}
