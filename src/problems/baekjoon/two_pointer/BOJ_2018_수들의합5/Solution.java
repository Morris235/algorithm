package problems.baekjoon.two_pointer.BOJ_2018_수들의합5;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

    public static void failed() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = i+1;
        }
        
        int count = 0;
        int left = 0, right = 0;
        int sum = 0; 
        while (right < n) {
            if (sum == n) {
                count++;
                sum -= arr[left];
                left++;
            } else if (sum > n) {
                sum -= arr[left];
                left++;
            } else if (sum < n) {
                sum += arr[right];
                right++;
            }
        }
        System.out.println(count);
    }
        
    public static void solved() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = i + 1;

        int count = 0;
        int left = 0, right = 0;
        int sum = 0;

        // 불변식: 현재 윈도우는 [left, right), sum은 그 합
        while (true) {
            if (sum == n) {
                count++;
                sum -= arr[left];
                left++;
            } else if (sum > n) {
                sum -= arr[left];
                left++;
            } else { // sum < n
                if (right == n) break; // 오른쪽을 더 못 넣고(sum<n)이면 종료
                sum += arr[right];
                right++;
            }
        }

        System.out.println(count);
    }

    public static void solved2() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int count = 0;
        int left = 0, right = 0, sum = 0;

        while (true) {
            if (sum >= n) {
                if (sum == n) count++;
                sum -= arr[left++];
            } else {
                if (right == n) break; // 오른쪽 더 못 넣으면 종료
                sum += arr[right++];
            }
        }

        System.out.println(count);
    }
}
