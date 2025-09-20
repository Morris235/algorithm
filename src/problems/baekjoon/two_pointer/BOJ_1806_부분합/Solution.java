package problems.baekjoon.two_pointer.BOJ_1806_부분합;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Solution {
    public static void solve() throws IOException {
        // 풀이 보류 : 기본 투포인터 연습이 더 필요함
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
    }

    public static void failed() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 한줄에 출력되고 나눠야 함으로 st로 나눠서 입력받아야 했음
        int n = Integer.parseInt(br.readLine());
        int s = Integer.parseInt(br.readLine());
        
        int[] arr = new int[n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        int left = 0, right = 0;
        int len = 0, sum = 0;
        
        // FIX: 반복 구간이 right <=로 되어 있으므로 out of bounds 발생
        while (right <= n) {
            // FIX: sum <= s일 때만 확장하면 sum < s에서 right == n이면 진행 불가/무한 루프
            if (sum <= s) {
                // 구간을 넓히며 탐색
                sum += arr[right++];
                // FIX: sum == s가 아니라 sum >= s를 찾는 문제임
                if (sum == s) {
                    // s와 일치하는 구간을 발견하면 길이를 갱신하고 다음 구간으로 이동
                    len = right + 1;
                    sum -= arr[left++];
                    sum += arr[right++];
                    // 기존 len보다 더 작은 구간을 발견하면 갱신
                    if (len < right) { // FIX : len = right + 1 계산이 현재 윈도우 정의와 불일치
                        len = right + 1;
                    }
                }
            } else {
                // sum이 s 보다 클 경우 left를 이동하여 구간 축소
                left++;
            }
        }
        System.out.println(len);
    }
}
