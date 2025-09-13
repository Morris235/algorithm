package problems.baekjoon.string.BOJ_1157_단어공부;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Character, Integer> map = new HashMap<>();
        
        String word = br.readLine().toUpperCase();
        단어공부
        for (int i = 0; i < word.length(); i++) {
            map.put(word.charAt(i), map.getOrDefault(word.charAt(i), 0) + 1);
        }
        
        Map.Entry<Character, Integer> maxCount = Collections.max(map.entrySet(), Map.Entry.comparingByValue());
        int count = 0;
        
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue().equals(maxCount.getValue())) {
                count++;
                if (count >= 2) {
                    System.out.print("?");   
                    return;
                }
            }
        }
        System.out.print(maxCount.getKey());
    }
}
