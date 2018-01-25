echo ""
echo "Running Diff"
echo "--------"
rm key.txt
for f in file*.txt;
do
    f=${f#tests/}
    cat key_$f >> key.txt
done
echo "--------"
