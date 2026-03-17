#!/bin/bash

INPUT_FILE="traces.txt"
PUSH_SWAP="./push_swap"

test_num=1

while IFS= read -r line; do
    case "$line" in
        TEST*ARG:*)
            ARG="${line#*ARG:}"

            echo "========== TEST $test_num =========="
            echo "ARGS: $ARG"

            valgrind \
            --leak-check=full \
            --show-leak-kinds=all \
            --track-origins=yes \
            --error-exitcode=42 \
            "$PUSH_SWAP" $ARG > /dev/null

            if [ $? -eq 42 ]; then
                echo "❌ MEMORY LEAK DETECTED"
                exit 1
            else
                echo "✅ No leaks"
            fi

            echo
            test_num=$((test_num + 1))
            ;;
    esac
done < "$INPUT_FILE"

echo "All tests passed with no leaks."