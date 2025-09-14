#!/bin/bash
set -e

if [ $# -lt 1 ]; then
  echo "사용법: $0 <문제번호> [태그] [요약] [입력예시] [출력예시]"
  exit 1
fi

NUM=$1
TAGS=${2:-"문자열, 구현"}
SUMMARY=${3:-"요약 없음"}
INPUT=${4:-"예시 입력"}
OUTPUT=${5:-"예시 출력"}

# 프로젝트 루트를 스크립트 기준으로 동적 계산
HERE=$(cd "$(dirname "$0")" && pwd)
PROJ_ROOT=$(cd "$HERE/.." && pwd)

# 문제 디렉토리 찾기 (깊이에 상관없이, 사이트 무관)
SEARCH_BASE=""
if [ -d "$PROJ_ROOT/src/problems" ]; then
  SEARCH_BASE="$PROJ_ROOT/src/problems"
elif [ -d "$PROJ_ROOT/problems" ]; then
  SEARCH_BASE="$PROJ_ROOT/problems"
else
  echo "❌ problems 디렉토리를 찾을 수 없습니다. ($PROJ_ROOT/src/problems 혹은 $PROJ_ROOT/problems)"
  exit 1
fi

DIR=$(find "$SEARCH_BASE" -type d \( -name "*_${NUM}_*" -o -name "${NUM}_*" -o -name "*${NUM}*" \) | head -n 1)

echo "📂 PROJ_ROOT: $PROJ_ROOT"
echo "🔎 찾은 문제 폴더: ${DIR:-<없음>}"

if [ -z "$DIR" ]; then
  echo "❌ 문제 번호 ${NUM} 에 해당하는 폴더를 찾을 수 없습니다."
  exit 1
fi

cd "$DIR"

# metrics.json 생성
if [ ! -f "metrics.json" ]; then
  echo "📄 metrics.json 생성..."
  files=$(ls Solution*.java 2>/dev/null || true)
  if [ -z "$files" ]; then
    echo "ℹ️ Solution*.java 파일이 없어 빈 metrics.json 생성"
    echo "[]" > metrics.json
  else
    {
      echo "["
      first=1
      for f in $files; do
        [ $first -eq 0 ] && echo ","
        first=0
        cat <<EOF
  {
    "file": "$f",
    "memory_kb": 0,
    "time_ms": 0,
    "time_complexity": "O(n)",
    "idea": "TODO: 풀이 아이디어 요약"
  }
EOF
      done
      echo "]"
    } > metrics.json
  fi
else
  echo "ℹ️ metrics.json 이미 존재 → 건너뜀"
fi

# README 생성 (사이트에 따라 기본 링크 베이스를 스크립트에서 힌트 제공 가능하지만
# Python 쪽에서 problem_dir로 사이트를 판별하므로 기본값 유지)
echo "📝 README.md 생성..."
python3 "$PROJ_ROOT/tools/generate_readme.py" "$NUM" \
  --tags "$TAGS" \
  --summary "$SUMMARY" \
  --input "$INPUT" \
  --output "$OUTPUT"

echo "✅ 완료: $DIR/README.md"