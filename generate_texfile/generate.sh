#!/bin/bash

if [ $# -ne 3 ]; then
  echo "usage: bash generate.sh <filepath> <texfilename> <pagetitle>"
  exit 1
fi

PAGETITLE="\\\\title{$3}"

SCRIPTDIR=$(dirname $0)
PATHSTR="${1}/*.cpp"
NAMESTR="${SCRIPTDIR}/${2}"

sed "s/\\\\title{}/${PAGETITLE}/" $SCRIPTDIR/tex_head.txt >> $NAMESTR.tex

for file in `\find $PATHSTR -maxdepth 1 -type f`; do
    FILENAME="${file##*/}"
    FILESTR=`echo "\subsection*{${FILENAME}}" | sed 's/_/\\\\_/g'`
    echo $FILESTR >> $NAMESTR.tex
    cat $SCRIPTDIR/tex_code_head.txt $file $SCRIPTDIR/tex_code_tail.txt >> $NAMESTR.tex
done

cat $SCRIPTDIR/tex_tail.txt >> $NAMESTR.tex

platex -output-directory=$SCRIPTDIR $NAMESTR.tex
dvipdfmx -o $NAMESTR.pdf $NAMESTR.dvi

for ext in aux dvi tex log; do
    rm $NAMESTR.$ext
done