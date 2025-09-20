package problems.baekjoon.two_pointer.BOJ_2003_수들의합2;

import java.io.*;
import java.util.*;

public class Solution {
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        int[] arr = new int[n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        int left = 0, right = 0, sum = 0, count = 0;

        // 무한루프
        // while (right < n) {
        //     sum += arr[right++];
        //     if (sum == m) {
        //         count++;
        //         sum -= arr[left];
        //         right++;
        //         left++;
        //     } else if (sum > m) {
                
        //     }
        // }
        
        // 슬라이딩 윈도우 탐색 풀이 : 기존 풀이
        // while (true) {
        //     if (sum >= m) {
        //         if (sum == m) count++;
        //         sum -= arr[left++];
        //     } else if (right == n) {
        //         break;
        //     } else {
        //         sum += arr[right++];
        //     }
        // }

        // 슬라이딩 윈도우 탐색 : 의도개선
        while (right <= n) {
            if (sum >= m) {
                // 조건 충족 시 카운트 증가
                if (sum == m) count++;
                // 윈도우 왼쪽 축소
                sum -= arr[left++];
            } else {
                // 더 이상 확장할 수 없으면 종료
                if (right == n) break;
                // 윈도우 오른쪽 확장
                sum += arr[right++];
            }
        }

        System.out.println(count);
    }
}