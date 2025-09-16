package problems.baekjoon.string.BOJ_6996_애너그램;
import java.util.Scanner;
import java.util.Arrays;

public class Solution {

    private static boolean solveAnagrams(String first, String second ) {
        if (first.length() != second.length()) return false;
        
        char[] firstChars = first.toCharArray();
        char[] secondChars = second.toCharArray();
        Arrays.sort(firstChars);
        Arrays.sort(secondChars);
        
        return Arrays.equals(firstChars, secondChars);
    }

    public static void solve(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numTests = sc.nextInt();

        for (int i = 0; i < numTests; i++) {
            String first = sc.next().toLowerCase();
            String second = sc.next().toLowerCase();

            System.out.println(first + " & " + second + " are " + (solveAnagrams(first, second) ? "anagrams." : "NOT anagrams."));
        }
    }
}
