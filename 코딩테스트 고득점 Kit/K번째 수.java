import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];       //정답 배열 생성

        // commands의 크기만큼 반복문 돌기
        for(int i=0; i<commands.length;++i){
            // Arrays.copyOfRange(배열, 시작 인덱스, 끝 인덱스): 배열의 시작 인데스 원소부터 끝 인덱스 원소까지 배열 반환
            int[] temp = Arrays.copyOfRange(array, commands[i][0] - 1, commands[i][1]);
            Arrays.sort(temp);  // 정렬
            answer[i] = temp[commands[i][2]-1];  // 정답 배열에 넣기
        }

        return answer;
    }
}