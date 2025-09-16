# BOJ 6996 애너그램

- **문제 링크:** [https://www.acmicpc.net/problem/6996](https://www.acmicpc.net/problem/6996)  
- **분류:** 문자열, 구현
- **요약:** 두 단어가 애너그램인지 아닌지 구하는 프로그램을 작성.

--- 

## 입출력 예시
입력: blather reblath
출력: blather & reblath are anagrams.

---

## 풀이 파일 & 성능

| 작성일 | 풀이 파일 | 메모리 | 시간 | 시간복잡도 | 핵심 아이디어 |
|---|---|---:|---:|---|---|
| 2025-09-16 15:25:27 | [`Solution.java`](./Solution.java) | 18592 KB | 200 ms | O(n log n) | 문자열을 문자로 변환후 정렬하여 Arrays.equals로 비교 |

---

## 접근 방식
- 문자열의 길이가 같지 않다면 애너그램이 아니므로 false.
- 두 문자열을 문자로 변환후 정렬하여 비교.
