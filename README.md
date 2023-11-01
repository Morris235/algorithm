# 프로젝트 소개

<도서> 이것이 자료구조+알고리즘이다 with C 언어를 바탕으로 작성한 알고리즘 공부용 repository 입니다.
책의 내용은 https://morris235.github.io/algorithm 에 정리 합니다.

<img src="./images/book_cover.jpeg">

# Part 00 목차

## Chapter 00 알아두면 쓸 데 있는 자료구조와 알고리즘

    0.1 자료구조
    0.2 알고리즘
    0.3 C 언어로 메모리를 다루는 방법
        0.3.1 포인터 복습
        0.3.2 구조체 복습
        0.3.3 메모리 레이아웃 복습
        0.3.4 스택에서 데이터를 다루는 방법
        0.3.5 힙에서 데이터를 다루는 방법

---

# Part 01 자료구조

## Chapter 01 리스트

    1.1 리스트 ADT
        1.1.1 리스트의 개념
        1.1.2 리스트와 배열 비교
    1.2 링크드 리스트
        1.2.1 링크드 리스트의 노드 표현
        1.2.2 링크드 리스트의 주요 연산
        1.2.3 링크드 리스트 예제 프로그램
        1.2.4 링크드 리스트의 장단점
    1.3 더블 링크드 리스트
        1.3.1 더블 링크드 리스트의 주요 연산
        1.3.2 더블 링크드 리스트 예제 프로그램
    1.4 환형 링크드 리스트
        1.4.1 환형 더블 링크드 리스트의 주요 연산
        1.4.2 환형 더블 링크드 리스트 예제 프로그램

## Chapter 02 스택

    2.1 스택 ADT
        2.1.1 스택의 개념
        2.1.2 스택의 핵심 기능 : 삽입과 제거 연산
    2.2 배열로 구현하는 스택
        2.2.1 배열 기반 스택과 스택의 노드 표현
        2.2.2 배열 기반 스택의 기본 연산
        2.2.3 배열 기반 스택 예제 프로그램
    2.3 링크드 리스트로 구현하는 스택
        2.3.1 링크드 리스트 기반 스택과 스택의 노드 표현
        2.3.2 링크드 리스트 기반 스택의 기본 연산
        2.3.3 링크드 리스트 기반 스택 예제 프로그램
    2.4 스택의 응용 : 사칙 연산 계산기
        2.4.1 수식의 중위 표기법과 후위 표기법
        2.4.2 후위 표기식을 계산하는 알고리즘
        2.4.3 중위 표기식을 후위 표기식으로 바꾸는 알고리즘
        2.4.4 사칙 연산 계산기 예제 프로그램

## Chapter 03 큐

    3.1 큐 ADT
        3.1.1 큐의 개념
        3.1.2 큐의 핵심 기능 : 삽입과 제거 연산
    3.2 순환 큐
        3.2.1 공백 상태와 포화 상태
        3.2.2 순환 큐의 기본 연산
        3.2.3 순환 큐 예제 프로그램
    3.3 링크드 큐
        3.3.1 링크드 큐의 기본 연산
        3.3.2 링크드 큐 예제 프로그램

## Chapter 04 트리

    4.1 트리 ADT
        4.1.1 트리의 개념
        4.1.2 트리의 구성 요소
        4.1.3 트리 표현 방법
        4.1.4 노드 표현 방법
        4.1.5 트리의 기본 연산
        4.1.6 트리 예제 프로그램
    4.2 이진 트리
        4.2.1 이진 트리의 종류
        4.2.2 이진 트리의 순회
        4.2.3 이진 투리의 기본 연산
        4.2.4 이진 트리 예제 프로그램
    4.3 수식 트리
        4.3.1 수식 트리 구축 방법
        4.3.2 수식 트리의 구현
        4.3.3 수식 트리 예제 프로그램
    4.4 분리 집합
        4.4.1 분리 집합 표현
        4.4.2 분리 집합의 기본 연산
        4.4.3 분리 집합 예제 프로그램

--- 

# Part 02 알고리즘

## Chapter 05 정렬

    5.1 정렬 알고리즘의 개요
    5.2 버블 정렬
        5.2.1 버블 정렬의 성능 측정
        5.2.2 버블 정렬 예제 프로그램
    5.3 삽입 정렬
        5.3.1 삽입 정렬의 성능 측정
        5.3.2 삽입 정렬 예제 프로그램
    5.4 퀵 정렬
        5.4.1 퀵 정렬 사용 전 해결해야 하는 2가지 문제
        5.4.2 퀵 정렬 예제 프로그램
        5.4.3 퀵 정렬의 성능 측정
    5.5. C 언어 표준라이브러리의 퀵 정렬 함수 : qsort()
        5.5.1 qsort() 함수 예제 프로그램 
        5.5.2 qsort() 응용 문제

## Chapter 06 탐색

    6.1 탐색 알고리즘의 개요
    6.2 순차 탐색
        6.2.1 전진 이동법
        6.2.2 전위법
        6.2.3 계수법
    6.3 이진 탐색
        6.3.1 이진 탐색의 성능 측정
        6.3.2 이진 탐색의 구현
        6.3.3 이진 탐색 예제 프로그램 : 두 번째 최종 시험 문제
        6.3.5 bsearch() 함수 예제 프로그램
    6.4 이진 탐색 트리
        6.4.1 이진 탐색 트리 표현
        6.4.2 이진 탐색 트리의 기본 연산
        6.4.3 이진 탐색 트리 예제 프로그램
        6.4.4 이진 탐색 트리의 문제점
    6.5 레드 블랙 트리
        6.5.1 레드 블랙 트리의 구현 규칙
        6.5.2 레드 블랙 트리의 기본 연산
        6.5.3 레드 블랙 트리 예제 프로그램

## Chapter 07 우선순위 큐와 힙

    7.1 우선순위 큐
        7.1.1 우선순위 큐의 삽입/제거 연산
        7.1.2 우선순위 큐의 구현
    7.2 힙
        7.2.1 힙의 삽입 연산 
        7.2.2 힙의 최솟값 삭제 연산
        7.2.3 힙의 구현
        7.2.4 힙 예제 프로그램
    7.3 힙 기반 우선순위 큐의 구현

## Chapter 08 해시 테이블

    8.1 해시 테이블의 개요
        8.1.1 해시
        8.1.2 해시 테이블
    8.2 해시 함수
        8.2.1 나눗셈법
        8.2.2 자릿수 접기
        8.2.3 해시 함수의 한계 : 충돌
    8.3 충돌 해결 기법
        8.3.1 체이닝
        8.3.2 개방 주소법
        
## Chapter 09 그래프

    9.1 그래프의 개요
        9.1.1 그프의 탄생 배경 : 오ㄹ러의 문제 해결 도구
        9.1.2 그프의 정의
    9.2 그래프 표현 방법
        9.2.1 인접 행렬
        9.2.2 인접 리스트
    9.3 그래프 순회 기법
        9.3.1 깊이 우선 탐색
        9.3.2 너비 우선 탐색
        9.3.3 그래프 순회 예제 프로그램
    9.4 위상 정렬
        9.4.1 위상 정렬의 동작 방식
        9.4.2 위상 정렬 예제 프로그램
    9.5 최소 신장 트리
        9.5.1 프림 알고리즘
        9.5.2 크루스칼 알고리즘
        9.5.3 최소 신장 트리 예제 프로그램
    9.6 최단 경로 탐색 : 데이크스트라 알고리즘
        9.6.1 테이크스트라 알고리즘의 개념
        9.6.2 데이크스트라 알고리즘 예제 프로그램

## Chapter 10 문자열 탐색

    10.1 문자열 탐색 알고리즘의 개요
    10.2 고지식한 탐색 알고리즘
        10.2.1 고지식한 탐색의 동작 방식
        10.2.2 고지식한 탐색 알고리즘 예제 프로그램
    10.3 카프-라빈 알고리즘
        10.3.1 카프-라빈 알고리즘의 동작 방식
        10.3.2 카프-라빈 알고리즘 예제 프로그램
    10.4 KMP 알고리즘
        10.4.1 KMP 알고리즘의 동작 방식
        10.4.2 경제 정보 사전 계산 방식
        10.4.3 KMP 알고리즘 예제 프로그램
    10.5 보이어-무어 알고리즘
        10.5.1 나쁜 문자 이동
        10.5.2 착한 접미부 이동
        10.5.3 보이어-무어 알고리즘의 전처리 과정
        10.5.4 보이어-무어 알고리즘 예제 프로그램

---

# Part 02 알고리즘 설계 기법

## Chapter 11 알고리즘 성능 분석

    11.1 알고리즘 성능 측정 기준과 수행 시간
        11.1.1 알고리즘 성능 측정 기준
        11.1.2 알고리즘 수행 시간 분석
    11.2 점근 표기법
        11.2.1 O 표시법
        11.2.2 Ω (Big Omega) 표기법
        11.2.3 Θ (Big Theta) 표기법
    11.3 재귀 알고리즘 성능 분석
        11.3.1 재귀 방정식과 재귀 알고리즘
        11.3.2 퀵 정렬의 성능 분석
        11.3.3 마스터 정리

## Chapter 12 분할 정복

    12.1 분할 정복 기법의 개요
        12.1.1 분할 정복 전술의 탄생 배경 : 아우스터리츠 전투
        12.1.2 분할 정복 알고리즘의 개념
    12.2 병합 정렬
        12.2.1 병합 정렬 동작 방식
        12.2.2 병합 정렬 알고리즘의 구현
    12.3 거듭 제곱 계산
        12.3.1 거듭 제곱 계산법
        12.3.2 거듭 제곱 계산 알고리즘의 구현
    12.4 분할 정복 기반 파보나치 수 구하기
        12.4.1 파보나치 수를 구하는 방법
        12.4.2 분할 정복으로 파보나치 수를 구하는 방법
        12.4.3 분할 정복 기반 파보나치 수 구하기 알고리즘의 구현

## Chapter 13 동적 계획법

    13.1 동적 계획법의 개요
        13.1.1 동적 계획법의 탄생 배경
        13.1.2 동적 계획법의 개념
    13.2 동적 계획법 기반 파보나치 수 구하기
        13.2.1 동적 계획법으로 파보나치 수를 구하는 방법
        13.2.2 동적 계획법 기반 파보나치 수 구하기 알고리즘의 구현
    13.3 최장 공통 부분 수열
        13.3.1 LCS 알고리즘
        13.3.2 동적 계획법 기반 LCS 알고리즘의 구현

## Chapter 14 탐욕 알고리즘

    14.1 탐욕 알고리즘의 개요
    14.2 거스름돈 줄이기 문제
        14.2.1 거스름돈 계산 예제 프로그램
        14.2.2 탐욕 알고리즘의 중요한 속성
    14.3 크루스칼 알고리즘 다시 보기
    14.4 데이크스트라 알고리즘 다시 보기
    14.5 허프만 코딩
        14.5.1 고정 길이 코드와 접두어 코드
        14.5.2 허프만 트리 구축
        14.5.3 데이터 압축
        14.5.4 데이터 압축 해제
        14.5.5 허프만 코딩 예제 프로그램

## Chapter 15 백트래킹

    15.1 백트래킹의 개요
        15.1.1 백트래킹의 사례 : 테세우스 이야기
        15.1.2 백트래킹의 개념
    15.2 미로 탈출로 찾기
        15.2.1 재귀 호출 기반 백트래킹
        15.2.2 미로 탈출 알고리즘의 구현
        15.2.3 미로 탈출 알고리즘 예제 프로그램
    15.3 8개의 퀸 문제
        15.3.1 8개의 퀸이 만드는 해동간과 백트래킹
        15.3.2 N개의 퀸 문제 풀이 알고리즘의 구현
        15.3.3 N개의 퀸 문제 풀이 예제 프로그램

<!-- a. sort
    - bubble
    - selection
    - insertion
    - quick
    - merge
b. search
    - binary
    - sequential
c. graph
    - breadth first search
    - depth first search
    - shortest path algorithm
    - dijkstra algorithm
    - minimum spanning tree
d. etc -->
