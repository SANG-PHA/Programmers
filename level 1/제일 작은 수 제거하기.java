class Solution {
    public int[] solution(int[] arr) {
        
        // arr의 원소가 1개일 때
        if(arr.length == 1)
        {
            int[] answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        
        // 최솟값 찾기
        int min = arr[0];
        for(int i = 1; i < arr.length; i++)
        {
            if(arr[i] < min)
                min = arr[i];
        }
        
        // 최솟값 삭제
        int[] answer = new int[arr.length - 1];
        int idx = 0;
            
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] == min)
                continue;
            answer[idx] = arr[i];
            idx++;
        }
        
        return answer;
    }
}
