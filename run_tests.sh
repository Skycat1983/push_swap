#!/bin/bash

INPUT_FILE="traces.txt"
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

test_num=1

while IFS= read -r line; do
    case "$line" in
        TEST*ARG:*)
            ARG="${line#*ARG:}"
            OPS=$("$PUSH_SWAP" $ARG)
            COUNT=$(printf "%s\n" "$OPS" | wc -l)
            RESULT=$(printf "%s\n" "$OPS" | "$CHECKER" $ARG)

            echo "========== TEST $test_num =========="
            echo "Count: $COUNT"
            echo "Result: $RESULT"
            echo

            test_num=$((test_num + 1))
            ;;
    esac
done < "$INPUT_FILE"