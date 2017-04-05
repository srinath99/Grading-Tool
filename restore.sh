#!/bin/bash

if [ ! -d backups ]; then
	echo "No backups exist!"
	exit 0
fi

cp backups/latest/*.txt .;

echo "Restore complete!"
