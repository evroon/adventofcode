#!/bin/bash

# Based on: https://github.com/bertptrs/adventofcode/blob/master/2020/download.sh

if [[ -z $YEAR ]]; then
	YEAR=$(date +%-Y)
fi

if [[ -z $AOC_SESSION ]]; then
	echo "AOC_SESSION not set"
	exit 1
fi

if [[ $# -ge 1 ]]; then
	# Get rid of leading zeroes
	(( DAY = $1 * 1 ))
else
	DAY=$(date +%-d)
fi

TARGET_FILE=$(printf "$YEAR/inputs/day%02d.txt" "$DAY")

echo "Going to download input of year $YEAR and day $DAY to $TARGET_FILE"

if [[ -s $TARGET_FILE ]]; then
	echo "Target file exists"
else
	curl --output "$TARGET_FILE" \
		--header "Cookie: session=$AOC_SESSION" \
		--fail \
		"https://adventofcode.com/$YEAR/day/$DAY/input"
fi
