package problems.baekjoon.two_pointer.BOJ_3273_두수의합;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Solution {
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(arr);
        
        int x = Integer.parseInt(br.readLine());
        int left = 0, right = arr.length - 1;
        int answer = 0;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == x) {
                answer++;
                left++;
                right--;
            } else if (sum < x) {
                left++;
            } else if (sum > x) {
                right--;
            }
        }
        
        System.out.println(answer);
    }
}