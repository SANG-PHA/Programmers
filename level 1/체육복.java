class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        //현재 가지고 있는 체육복의 수 카운트 배열 선언 및 초기화
        int[] garment = new int[n];
        for(int i = 0; i < n; i++)
            garment[i] = 1;
        
        // lost, reserve 배열에 따라 garment배열 값 증감
        for(int i = 0; i < lost.length; i++)
            garment[lost[i]-1]--;
        
        for(int i = 0; i < reserve.length; i++)
            garment[reserve[i]-1]++;
        
        // 체육복 나눠주기
        for(int i = 0; i < n; i++)
        {
            if(i == 0) // 0번 인덱스일 때
            {
                if(garment[i] > 1 && garment[i+1] < 1)
                {
                    garment[i]--;
                    garment[i+1]++; // 뒷사람에게   
                }
            }
            else if(i == n - 1) // 마지막 인덱스일때
            {
                if(garment[i] > 1 && garment[i-1] < 1)
                {
                    garment[i]--;
                    garment[i-1]++; // 앞사람에게
                }
            }
            else if(garment[i] > 1 && garment[i-1] < 1) // 앞사람에게 나눠주기
            {
                garment[i]--;
                garment[i-1]++;
            }
            else if(garment[i] > 1 && garment[i+1] < 1) // 뒷사람에게 나눠주기
            {
                garment[i]--;
                garment[i+1]++;
            }
            
        }
        
        // 수업 들을 수 있는 학생 수 확인
        for(int tmp : garment)
        {
            if(tmp > 0)
                answer++;
        }
        
        return answer;
    }
}
