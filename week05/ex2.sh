lockfile -r 0 file.lock || exit 1 # Lock the file

while true
do
    var=$(tail -1 file.txt | grep -oE '^[0-9]+$')
    echo $((var + 1)) >> file.txt
done

rm -f file.lock # Unlock the file

# Race condition manifests itself just in seconds.
# The critical region is the file.txt.
#
# Without locking the file both background and foreground scripts
# have access to the file.
#
# With locking only one script has access to the file. The second
# one cannot even start: "Sorry, giving up on "file.lock""