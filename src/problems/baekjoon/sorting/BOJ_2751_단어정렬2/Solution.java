package problems.baekjoon.sorting.BOJ_2751_단어정렬2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {
    public static void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int num = Integer.parseInt(br.readLine());
        int[] arr = new int[num];
        
        for (int i = 0; i < num; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        
        Arrays.sort(arr);
        
        for (int v : arr) {
            sb.append(v).append('\n');
        }
        
        System.out.print(sb.toString());
    }
}