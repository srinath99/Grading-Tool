#!/bin/bash

# Create backups directory
mkdir -p .backups;
BACKUPSIZE=`du -s .backups | awk '{print $1}'`

# Make sure the backups aren't too large
echo ""
if (( $BACKUPSIZE >= 100000 )); then
    echo "Backup size is too large at $BACKUPSIZE bytes... Replacing old backups"
    while (( $BACKUPSIZE >= 100000 )); do

        # Find oldest backup
        cd .backups
        OLDESTDIR=`ls -r | tail -n 1`

        # Delete oldest backup
        rm -r $OLDESTDIR
        echo "deleted backup: $OLDESTDIR"

        # Update backup size
        cd ..
        BACKUPSIZE=`du -s .backups | awk '{print $1}'`
    done
else
    echo "Backup size is OK at $BACKUPSIZE bytes"
fi

# Prepare to create backup
echo ""
cd .backups;
echo `pwd`
# Create directory for lastest backup
CURRENTDIRNAME=$(date '+%d-%b-%Y-%H-%M-%S');
mkdir $CURRENTDIRNAME;
echo "Creating a backup for $CURRENTDIRNAME"
cd ..;
echo `pwd`

# Copy files into new backup folder
cp -v *.txt .backups/$CURRENTDIRNAME;

# Update 'latest' link
cd .backups;
rm latest
ln -s $CURRENTDIRNAME latest;
cd ..;

#Update size for output
BACKUPSIZE=`du -s .backups | awk '{print $1}'`

# Output success messages
echo "Backup can be accessed at ./backups/$CURRENTDIRNAME"
echo "Latest backup can always be accessed at ./backups/latest"
echo "Backup complete for $CURRENTDIRNAME!"
echo ""
echo "There are now `ls -l .backups | grep -c ^d` backups existing, with a total size of $BACKUPSIZE bytes"
