#!/bin/bash
set -e
bash
. ./functions.sh

# you can install oj with: $ pip3 install --user -U online-judge-tools=='6.*'
which oj > /dev/null

git checkout master
git remote set-url origin https://Tsutajiro:${GITHUB_TOKEN}@github.com/Tsutajiro/cpp_library.git

git config --global user.name "Tsutajiro"
git config --global user.email "y.sugie.15739d@gmail.com"
git config --global push.default simple

git branch -a

# auto verify
for f in $(find . -name \*.test.cpp) ; do
    echo "----------------------------------------------------------------------"
    echo "## Testing '${f}' ..."
    echo "----------------------------------------------------------------------"
    run $f
done

# auto generate readme
python3 generate_readme.py > ../README.md

git status -s
if [ -n "$(git status -s)" ]; then
    last_commit="$(git log -1 | head -1 | awk '{print $2}')"
    git add ./test
    git add ../README.md
    git commit -m "[auto-verifier] [ci skip] verify commit ${last_commit}"
    git push --quiet origin master >/dev/null 2>&1
    echo "Pushed updated branch 'master'"
fi
