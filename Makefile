.PHONY: all run setup build clean test

all: clean setup test

run:
	# ---Running executable---
	./build/survival

setup:
	# ---Setting up build dir---
	cmake -B build

build:
	# ---Building---
	cmake --build build

clean:
	# ---Cleaning---
	rm -rf build

test: build run
