#!/bin/bash

if [ $# -ne 1 ]; then
  echo "usage: bash part_generate.sh <filepath>"
  exit 1
fi

SCRIPTDIR=$(dirname $0)
PATHSTR="${1}/*.cpp"

for file in `\find $PATHSTR -maxdepth 1 -type f`; do
    FILENAME="${file##*/}"
    FILENAME=${FILENAME%.*}
    echo $FILENAME

    NAMESTR="${SCRIPTDIR}/${FILENAME}"

    echo $NAMESTR

    cat $SCRIPTDIR/tex_head.txt >> $NAMESTR.tex
    FILESTR=`echo "\subsection*{${FILENAME}}" | sed 's/_/\\\\_/g'`
    echo $FILESTR >> $NAMESTR.tex

    cat $SCRIPTDIR/tex_code_head.txt $file $SCRIPTDIR/tex_code_tail.txt >> $NAMESTR.tex
    cat $SCRIPTDIR/tex_tail.txt >> $NAMESTR.tex

    platex -output-directory=$SCRIPTDIR $NAMESTR.tex
    dvipdfmx -o $NAMESTR.pdf $NAMESTR.dvi

    for ext in aux dvi tex log; do
        rm $NAMESTR.$ext
    done
done