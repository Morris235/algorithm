# 알고리즘 스터디

자바(Java) 기반의 알고리즘 문제 풀이 저장소입니다. 백준(BOJ), 프로그래머스, 리트코드 등의 문제를 사이트별/분류별로 정리하고, 문제 폴더마다 자동으로 README를 생성합니다.

## 폴더 구조

- `src/problems`:
  - 사이트/분류/문제 폴더 구조. 예: `src/problems/baekjoon/string/BOJ_1157_단어공부`
  - 문제 폴더에는 `Solution*.java`, `metrics.json`, `README.md`가 위치합니다.
- `tools`:
  - `genproblem.sh`: 문제 폴더에서 `metrics.json` 생성 및 문제 `README.md` 자동 생성
  - `generate_readme.py`: 문제 `README.md` 생성기(직접 실행 가능)
- `src/algo`, `src/util`, `src/app`, `src/playground`: 공용 알고리즘/유틸/실행 테스트 코드 등

## 문제 폴더 네이밍 규칙

- 기본: `SITE_NUM_TITLE` 형태 권장 (예: `BOJ_1157_단어공부`)
- 접두사가 없더라도 `NUM_TITLE`, `NUM`도 인식합니다.

## README 자동 생성

문제 폴더를 찾은 뒤, `metrics.json`이 없으면 템플릿을 생성하고 `README.md`를 만듭니다.

### 쉘 스크립트 사용(genproblem.sh)

```bash
bash tools/genproblem.sh <문제번호> [태그] [요약] [입력예시] [출력예시]

# 예시
bash tools/genproblem.sh 1157 "문자열, 구현" "" "" ""
```

### 파이썬 스크립트 직접 사용(generate_readme.py)

```bash
python3 tools/generate_readme.py <문제번호> \
  --tags "문자열, 구현" \
  --summary "힌트: 입력 범위·핵심 규칙·자료구조·에지 케이스를 한 줄로 요약" \
  --input "예시 입력" \
  --output "예시 출력"
```

## metrics.json

문제 폴더 내 `metrics.json`은 각 `Solution*.java`에 대한 메타데이터를 기록합니다.

- 필드: `file`, `memory_kb`, `time_ms`, `time_complexity`, `idea`
- 초기 생성 시 기본값이 채워지며, 제출/측정 결과에 따라 수동 갱신하세요.

## 문제 README 표 구성

문제 `README.md`의 “풀이 파일 & 성능” 표는 다음을 포함합니다.

- 작성일(오름차순)
- 풀이 파일(상대 링크로 GitHub에서 클릭 시 해당 파일로 이동)
- 메모리/실행시간/시간복잡도/핵심 아이디어

작성일은 파일 생성시간이 지원되지 않는 환경에선 수정시간으로 대체됩니다.

## 새 문제 추가 가이드

1. 폴더 생성: 예) `src/problems/baekjoon/sorting/BOJ_2750_수정렬하기/`
2. 풀이 파일 추가: `Solution.java` 또는 복수 풀이 시 `SolutionArray.java` 등
3. README 생성 실행:

```bash
bash tools/genproblem.sh 2750 "정렬" "" "예시 입력" "예시 출력"
```

## 기타

- 링크 자동화: 사이트/경로를 기반으로 BOJ/Programmers/LeetCode 링크를 추론합니다.
- 표의 파일명은 상대 링크(`[파일](./파일)`)로 생성되어 GitHub에서 바로 열 수 있습니다.


---

<!-- AUTO_INDEX:START -->

## 문제

<details>
<summary><strong>sorting</strong></summary>

<details>
<summary>BOJ 단어정렬</summary>

| 업데이트 | 파일 이름 | 문제 링크 |
|---|---|---|
| 2025-09-14 13:16:20 | [Solution.java](./src/problems/baekjoon/sorting/BOJ_1181_단어정렬/Solution.java) | [문제 링크](https://www.acmicpc.net/problem/1181) |
</details>

<details>
<summary>BOJ 단어정렬2</summary>

| 업데이트 | 파일 이름 | 문제 링크 |
|---|---|---|
| 2025-09-14 13:16:32 | [Solution.java](./src/problems/baekjoon/sorting/BOJ_2751_단어정렬2/Solution.java) | [문제 링크](https://www.acmicpc.net/problem/2751) |
</details>

<details>
<summary>BOJ 수정렬하기</summary>

| 업데이트 | 파일 이름 | 문제 링크 |
|---|---|---|
| 2025-09-14 13:16:10 | [Solution.java](./src/problems/baekjoon/sorting/BOJ_2750_수정렬하기/Solution.java) | [문제 링크](https://www.acmicpc.net/problem/2750) |
</details>

</details>

<details>
<summary><strong>string</strong></summary>

<details>
<summary>BOJ 단어공부</summary>

| 업데이트 | 파일 이름 | 문제 링크 |
|---|---|---|
| 2025-09-14 13:12:13 | [SolutionArray.java](./src/problems/baekjoon/string/BOJ_1157_단어공부/SolutionArray.java) | [문제 링크](https://www.acmicpc.net/problem/1157) |
| 2025-09-14 13:12:19 | [SolutionHashMap.java](./src/problems/baekjoon/string/BOJ_1157_단어공부/SolutionHashMap.java) | [문제 링크](https://www.acmicpc.net/problem/1157) |
</details>

</details>

<!-- AUTO_INDEX:END -->
