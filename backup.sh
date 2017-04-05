#!/bin/bash

mkdir -p .backups;
cd .backups;
CURRENTDIRNAME=$(date '+%d-%b-%Y-%H-%M-%S');
mkdir $CURRENTDIRNAME;
cd ..;

cp *.txt .backups/$CURRENTDIRNAME;

cd .backups;

ln -sfn $CURRENTDIRNAME/ latest;

cd ..;

echo "Backup complete for $CURRENTDIRNAME!"
