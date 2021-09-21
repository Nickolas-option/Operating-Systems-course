outFile = "out.txt"
tempFile = $(mktemp ./lock.XX)
lockFile = ./lockfile
if ln $tempFile $lockFile
then
	echo $(($(tail -n 1 $outputFile)+1)) >> $outputFile
	rm $lockFile
else 
    echo 1
fi
