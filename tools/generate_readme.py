#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import argparse, json, os, re
from datetime import datetime
from textwrap import dedent

def find_problem_dir(root: str, num: str):
    """
    src/problems/ 또는 problems/ 이하를 재귀 탐색해서
    - BOJ_<num>_*  또는
    - <num>_*
    폴더를 찾는다. (첫 번째 매치 반환)
    """
    patterns = (f"BOJ_{num}_", f"{num}_")
    candidate_roots = [
        os.path.join(root, "src", "problems"),
        os.path.join(root, "problems"),
    ]
    for target_root in candidate_roots:
        if not os.path.isdir(target_root):
            continue
        for dirpath, dirnames, _ in os.walk(target_root):
            for d in dirnames:
                if d.startswith(patterns):
                    return os.path.join(dirpath, d)
    return None

def parse_dirname(dirname: str):
    m = re.match(r'([A-Za-z]+)_(\d+)_?(.*)', dirname)
    if m:
        site, num, title_raw = m.group(1), m.group(2), (m.group(3) or "").strip()
        return site, num, title_raw.replace('_', ' ') if title_raw else ''
    # 접두사 없는 순수 숫자 기반 디렉토리도 허용: 1234_제목
    m2 = re.match(r'(\d+)_?(.*)', dirname)
    if m2:
        num, title_raw = m2.group(1), (m2.group(2) or "").strip()
        return None, num, title_raw.replace('_', ' ') if title_raw else ''
    # 안전장치: 패턴에 안 맞으면 제목만 추정
    return None, None, dirname.replace('_', ' ')

def compute_link(site_code: str, num: str, problem_dir: str, default_base: str):
    """사이트/경로를 바탕으로 문제 링크를 추론한다.
    - BOJ/baekjoon: https://www.acmicpc.net/problem/{num}
    - programmers: https://school.programmers.co.kr/learn/courses/30/lessons/{num}
    - leetcode: https://leetcode.com/problems (번호만으론 slug를 모름)
    기타: default_base 사용 (num 있으면 /{num})
    """
    dir_lower = problem_dir.lower()
    # 우선 site_code로 판별
    if (site_code and site_code.upper() in ("BOJ", "BAEKJOON")) or "baekjoon" in dir_lower:
        return f"https://www.acmicpc.net/problem/{num}" if num else "https://www.acmicpc.net"
    if (site_code and site_code.upper() in ("PGM", "PRG", "PROGRAMMERS")) or "programmers" in dir_lower:
        # programmers는 보통 lessons/{num}
        return f"https://school.programmers.co.kr/learn/courses/30/lessons/{num}" if num else "https://school.programmers.co.kr/learn/challenges"
    if (site_code and site_code.upper() in ("LC", "LEETCODE")) or "leetcode" in dir_lower:
        # slug가 필요하므로 컬렉션으로 링크
        return "https://leetcode.com/problems"
    # 알 수 없는 경우 기본 베이스 사용
    return f"{default_base}/{num}" if num else default_base

def load_metrics(path="metrics.json"):
    if not os.path.exists(path):
        return {}
    with open(path, "r", encoding="utf-8") as fp:
        data = json.load(fp)
    # 파일명 → 항목 매핑
    return {row["file"]: row for row in data}

def percent_delta(old, new):
    if old in (None, 0) or new is None:
        return None
    return round((old - new) / old * 100)

def format_perf_delta(mem_old, mem_new, time_old, time_new):
    lines = []
    pm = percent_delta(mem_old, mem_new)
    pt = percent_delta(time_old, time_new)
    if pm is not None:
        lines.append(f"- **메모리**: {mem_old:,} KB → {mem_new:,} KB (약 **{pm}% 절감**)")
    if pt is not None:
        lines.append(f"- **실행시간**: {time_old:,} ms → {time_new:,} ms (약 **{pt}% 개선**)")
    return "\n".join(lines) if lines else ""

def get_created_timestamp(file_path: str):
    """파일 생성시각(가능하면) 또는 수정시각을 반환 (epoch seconds)."""
    st = os.stat(file_path)
    ts = getattr(st, "st_birthtime", None)
    if ts is None:
        ts = st.st_mtime
    return ts

def format_timestamp(ts: float) -> str:
    return datetime.fromtimestamp(ts).strftime("%Y-%m-%d %H:%M")

def main():
    ap = argparse.ArgumentParser(description="Generate README.md for a BOJ problem folder")
    ap.add_argument("num", help="문제 번호 (예: 1157)")
    ap.add_argument("--tags", default="문자열, 구현")
    ap.add_argument("--summary", default="힌트: 입력 범위·핵심 규칙·자료구조·에지 케이스를 한 줄로 요약")
    ap.add_argument("--input", default="예시 입력")
    ap.add_argument("--output", default="예시 출력")
    ap.add_argument("--metrics", default="metrics.json")
    ap.add_argument("--link_base", default="https://www.acmicpc.net/problem")
    args = ap.parse_args()

    # tools/ 기준 루트 계산 (심볼릭/alias 상관없이 안전)
    HERE = os.path.dirname(os.path.abspath(__file__))
    proj_root = os.path.abspath(os.path.join(HERE, ".."))

    problem_dir = find_problem_dir(proj_root, args.num)
    print(f"🔎 problem_dir: {problem_dir or '<not found>'}")

    if not problem_dir:
        print(f"❌ 문제 번호 {args.num} 에 해당하는 폴더를 찾을 수 없습니다.")
        return

    dirname = os.path.basename(problem_dir)
    site, num, title = parse_dirname(dirname)
    problem_title = (title or dirname.replace('_', ' ')).strip()
    link = compute_link(site, num, problem_dir, args.link_base)

    # metrics.json 읽기
    metrics_path = os.path.join(problem_dir, args.metrics)
    metrics = load_metrics(metrics_path)

    # 솔루션 파일 스캔 + 작성일 계산
    solution_files = [
        f for f in os.listdir(problem_dir)
        if f.startswith("Solution") and f.endswith(".java")
    ]
    entries = []
    for f in solution_files:
        file_path = os.path.join(problem_dir, f)
        created_ts = get_created_timestamp(file_path)
        created_str = format_timestamp(created_ts)
        meta = metrics.get(f, {})
        mem, tm = meta.get("memory_kb"), meta.get("time_ms")
        tc, idea = meta.get("time_complexity", ""), meta.get("idea", "")
        entries.append({
            "file": f,
            "created_ts": created_ts,
            "created_str": created_str,
            "mem": mem,
            "tm": tm,
            "tc": tc,
            "idea": idea,
        })

    # 작성일 오름차순 정렬
    entries.sort(key=lambda e: e["created_ts"])

    rows, mems, times = [], [], []
    for e in entries:
        mem, tm = e["mem"], e["tm"]
        file_cell = f"[`{e['file']}`](./{e['file']})"
        rows.append(
            f"| {e['created_str']} | {file_cell} | {f'{mem:,} KB' if isinstance(mem, int) else ''} | "
            f"{f'{tm:,} ms' if isinstance(tm, int) else ''} | {e['tc']} | {e['idea']} |"
        )
        if isinstance(mem, int): mems.append(mem)
        if isinstance(tm, int): times.append(tm)

    perf_block = ""
    if len(mems) >= 2 or len(times) >= 2:
        perf_block = format_perf_delta(
            mems[0] if len(mems) >= 2 else None,
            mems[-1] if len(mems) >= 2 else None,
            times[0] if len(times) >= 2 else None,
            times[-1] if len(times) >= 2 else None,
        )
        if perf_block:
            perf_block = f"> 📊 성능 개선:  \n{perf_block}"

    # README.md 내용 생성
    title_line = f"# {site} {num} {problem_title}".strip() if site or num else f"# {problem_title}"
    md = dedent(f"""
    {title_line}

    - **문제 링크:** [{link}]({link})  
    - **분류:** {args.tags}
    - **요약:** {args.summary}

    --- 

    ## 입출력 예시
    입력: {args.input}  
    출력: {args.output}

    ---

    ## 풀이 파일 & 성능

    | 작성일 | 풀이 파일 | 메모리 | 시간 | 시간복잡도 | 핵심 아이디어 |
    |---|---|---:|---:|---|---|
    """).lstrip()

    md += "\n".join(rows if rows else ["| - | (풀이 파일 없음) | | | | |"])
    if perf_block:
        md += "\n\n" + perf_block

    md += dedent("""

    ---

    ## 접근 방식
    - 각 풀이 파일에 주석으로 핵심 아이디어를 기록.
    - 표의 ‘핵심 아이디어’ 열을 요약으로 사용.

    ---

    ## 복수 풀이 비교
    - 

    ---

    ## 메모
    - 
    """)

    out_path = os.path.join(problem_dir, "README.md")
    with open(out_path, "w", encoding="utf-8") as fp:
        fp.write(md)
    print(f"✅ README.md 생성 완료: {out_path}")

if __name__ == "__main__":
    main()