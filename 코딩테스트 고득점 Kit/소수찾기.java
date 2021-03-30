import java.util.*;

class Solution {
    boolean[] visit = new boolean[7];

    public int solution(String numbers) {
        int[] arr = new int[numbers.length()];
        for (int i = 0; i < numbers.length(); ++i) {
            arr[i] = numbers.charAt(i) - '0';
        }
        Set<Integer> set = new TreeSet<Integer>();

        permutation(0, "", arr, set);

        return set.size();
    }

    // 소수 판별
    public boolean isPrime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;

        // 제곱근을 활용하여 소수 판별
        for (int i = 2; i <= Math.sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // 순열
    public void permutation(int depth, String num, int[] arr, Set<Integer> set) {
        if (depth == arr.length) {
            //소수 판별 후 소수가 맞다면 set에 추가
            if (!num.equals("") && isPrime(Integer.parseInt(num)))
                set.add(Integer.parseInt(num));
        } else {
            for (int i = 0; i < arr.length; ++i) {
                if (!visit[i]) {
                    visit[i] = true;
                    permutation(depth + 1, num + Integer.toString(arr[i]), arr, set);
                    permutation(depth + 1, num, arr, set);
                    visit[i] = false;
                }
            }
        }
    }
}