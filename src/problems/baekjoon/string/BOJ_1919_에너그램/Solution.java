package problems.baekjoon.string.BOJ_1919_에너그램;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        
        int[] cnt = new int[26];
        
        for (int i = 0; i < s1.length(); i++) {
            cnt[s1.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            cnt[s2.charAt(i) - 'a']--;
        }
        
        int answer = 0;
        for (int i = 0; i < 26; i++) {
            answer += Math.abs(cnt[i]);
        }
        
        System.out.print(answer);
    }
}