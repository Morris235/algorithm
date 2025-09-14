package problems.baekjoon.string.BOJ_1157_단어공부;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SolutionArray {
    public static void solve () throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine().toUpperCase();
        
        int[] freq = new int[26];
        int max = 0;
        char result = '?';
        
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int idx = c - 'A';
            
            freq[idx]++;
            
            if (freq[idx] > max) {
                max = freq[idx];
                result = c;
            } else if (freq[idx] == max) {
                result = '?';
            }
        }
        System.out.println(result);
    }
}    
