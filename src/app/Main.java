package app;

import algo.sort.BubbleSort;
import util.FastScanner;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        // 입력 예시: n과 배열 입력
        int n = fs.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = fs.nextInt();

        // 버블 정렬 실행
        BubbleSort.sort(arr);
        for (int x : arr) System.out.print(x + " ");
        System.out.println();

        // 피보나치 실행
        // System.out.println("Fib(10) = " + Fibonacci.fib(10));
    }
}