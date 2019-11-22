dirs=(algorithm dp etc geometry graph math string structure)
abbrs=(algo dp etc gmtr graph math str strc)
N=`expr ${#dirs[@]} - 1`

mkdir pdf
for i in `seq 0 1 $N`
do
    dir=${dirs[${i}]}
    abbr=${abbrs[${i}]}
    bash ./part_generate.sh "../$dir"
    mkdir "./pdf/$dir"
    mv "${abbr}_"* "./pdf/${dir}"
done

