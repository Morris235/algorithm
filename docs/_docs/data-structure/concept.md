---
title: 자료구조란
description: 자료구조의 개념에 대한 문서
---

# 자료구조란

자료구조는 컴퓨터가 데이터를 효율적으로 다룰 수 있게 도와주는 **데이터 보관 방법과 데이터에 관한 연산의 총체**를 뜻한다. 예를 들어 int도 덧셈/뺄셈/나눗셈/곱셈/논리/시프트 등이 가능한 32비트의 메모리 공간을 갖는 자료구조이다. <br/>

## 자료구조의 종류

자료구조는 int와 같은 **단순 자료구조**와 **복합 자료구조**로 나뉜다. 복합 자료구조는 다시 선형 자료구조와 비선형 자료구조로 나뉜다. 

### 선형 자료구조

선형 자료구조는 데이터 요소를 순차적으로 연결하는 자료구조로, 구현하기 쉽다. 배열과 링크드 리스트, 스택, 큐 등이 여기에 해당한다. 

### 비선형 자료구조

비선형 자료구조는 선형 자료구조와 달리 데이터 요소를 비순차적으로 연결한다. 한 데이터 요소에서 여러 데이터 요소로 연결되기도 하고, 여러 데이터 요소가 하나의 데이터 요소로 연결 되기도 한다. 트리와 그래프가 여기에 해당한다.

## ADT (Abstract Data Types)

추상 데이터 형식이라고 하며 자료구조의 동작 방법을 표현하는 데이터 형식이다. 다시말해 **자료구조가 갖춰야 할 일련의 연산이다** <br/>
리스트를 예로 든다면 리스트는 데이터에 순차적으로 접근해서 그 데이터를 다룰 수 있도록 여러 기능을 제공해야 한다. 목록의 특정 위치에 있는 노드에 접근(get)하거나, 목록의 마지막에 데이터를 추가(append)하거나, 목록의 중간에 삽입(insert)하거나, 삭제(remove)하는 기능들이다.<br/>
이렇게 ADT가 청사진을 제시하면 자료구조는 이를 구현한다. 배열로 리스트를 구현한다고 가정을 하자면 배열의 길이가 곧 리스트의 길이가 되고 배열의 첫 요소는 시작 노드, 배열의 마지막 요소는 마지막 노드가 된다. 그리고 현재 다루고 있는 요소의 첨자(index)가 현재 노드가 된다. 여기에 탐색/추가/삽입/수정/삭제와 같은 기능을 구현하면 하나의 자료구조가 완성된다. 이러한 자료구조들은 C#이나 자바, 파이썬 같은 현대적 언어에선 라이브러리로 제공이 된다.

## 자료구조를 공부해야 하는 이유

라이브러리로 제공이 되지만 굳이 공부해야 하는 이유는<br/>
첫째, 자료구조의 내부를 이해하면 라이브러리에서 엉뚱한 자료구조를 선택하는 일을 피할 수 있다.<br/>
둘째, 자료구조는 알고리즘이 데이터를 효율적으로 사용할 수 있게 도와주는 핵심 부품 역할을 하기 때문이다. 다시말해, 자료구조를 모르면 알고리즘을 공부하는 데 어려움이 따른다.