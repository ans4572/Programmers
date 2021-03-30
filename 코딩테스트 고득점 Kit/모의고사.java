import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[][] pattern = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };

        int[] pAns = new int[3];
        for (int i = 0; i < answers.length; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (answers[i] == pattern[j][i % pattern[j].length]) pAns[j]++;
            }
        }

        int max = Math.max(pAns[0], Math.max(pAns[1], pAns[2]));
        List<Integer> temp = new ArrayList<Integer>();
        for (int i = 0; i < 3; ++i) {
            if (pAns[i] == max) temp.add(i + 1);
        }

        int[] answer = new int[temp.size()];
        for (int i = 0; i < temp.size(); ++i)
            answer[i] = temp.get(i);

        return answer;
    }
}