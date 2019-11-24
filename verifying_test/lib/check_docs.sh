#!/bin/bash

CXX=${CXX:-g++}
CXXFLAGS="${CXXFLAGS:--std=c++14 -O3}"
ulimit -s 65532

list_dependencies() {
    file="$1"
    $CXX $CXXFLAGS -I . -MD -MF /dev/stdout -MM "$file" | sed '1s/[^:].*: // ; s/\\$//' | xargs -n 1
}

list_defined() {
    file="$1"
    $CXX $CXXFLAGS -I . -dM -E "$file"
}

get_docspath() {
    file="$1"
    list_defined "$file" | grep '^#define DOCS ' | sed 's/^#define DOCS "\(.*\)"$/\1/'
}

get_url() {
    file="$1"
    list_defined "$file" | grep '^#define PROBLEM ' | sed 's/^#define PROBLEM "\(.*\)"$/\1/'
}

get_error() {
    file="$1"
    list_defined "$file" | grep '^#define ERROR ' | sed 's/^#define ERROR "\(.*\)"$/\1/'
}

get_last_commit_date() {
    file="$1"
    list_dependencies "$file" | xargs git log -1 --date=iso --pretty=%ad
}

file="$1"
get_docspath $file
