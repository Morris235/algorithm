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
        // TODO : 슬라이딩 윈도우 핵심 알고리즘 구현
        while (right < n) {
            
        }
    }
}

// import java.io.*;
// import java.util.*;

// public class Main {
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringTokenizer st = new StringTokenizer(br.readLine());
        
//         int n = Integer.parseInt(st.nextToken());
//         int m = Integer.parseInt(st.nextToken());
        
//         int[] arr = new int[n];
        
//         st = new StringTokenizer(br.readLine());
//         for (int i = 0; i < n; i++) {
//             arr[i] = Integer.parseInt(st.nextToken());
//         }
        
//         int left = 0, right = 0, sum = 0, count = 0;
//         // TODO : 슬라이딩 윈도우 핵심 알고리즘 구현
//         while (right < n) {
            
//         }
//     }
// }