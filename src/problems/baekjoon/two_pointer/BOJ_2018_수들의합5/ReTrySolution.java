package problems.baekjoon.two_pointer.BOJ_2018_수들의합5;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ReTrySolution {
    public static void solved() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;    
        }
        
        int count = 0;
        int left = 0, right = 0;
        int sum = 0;
        
        while (true) {
            if (sum >= n) {
                if (sum == n) count++;
                sum -= arr[left++];
            } else if (sum <= n) {
                if (right == n) break;
                sum += arr[right++];
            }
        }
        System.out.println(count);
    }
}
