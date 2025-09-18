package problems.baekjoon.dfs.BOJ_6443_애너그램;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < num; i++) {
            String str = br.readLine().toLowerCase();
            char[] chars = str.toCharArray();
            // TODO: bfs로 풀어야함
        }
    }
}