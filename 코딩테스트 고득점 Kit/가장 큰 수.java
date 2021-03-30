import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        // 문자열로 변환
        String[] temp = new String[numbers.length];

        for(int i=0;i< numbers.length;++i)
            temp[i] = Integer.toString(numbers[i]);

        // 정렬
        Arrays.sort(temp, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return ((o2 + o1).compareTo(o1 + o2));
            }
        });

        // 첫번째가 0인 경우는 그 뒤로도 0이므로 답은 0
        if(temp[0].equals("0"))
            return "0";

        String answer = "";
        for(int i=0;i< numbers.length;++i)
            answer += temp[i];

        return answer;
    }
}