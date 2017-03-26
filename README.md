# Grading Tool
Useful for quickly grading students' computer science assignments based on pre-defined penalties

<br>

<h4>Run Grading</h4>

`make run` To complile and start a grading session
<br>
<em>note: output is saved after each student in a file. The naming convention is as follows: 
<br>
`<class letters><class numbers>_assignment<assignment number>_results.txt`</em>
<br>
<br>
<h4>Backups</h4>
<p>
Text files can be backed up (and sometimes are automatically) 

`make backup` triggers an automatic backup that moves all the text files (existing output and keyWord list)

`make reset` removes all existing output files, but creates a full backup first

`make restore` restores the backup (full restore of both keyWord list and output file(s))
</p>
<br>
<h4>Manage Comments</h4>

`make manage` To compile and run a small program to add keys and comments to the list.

<br>
<hr>

The list of comments is stored in a text file called keyWords.txt. This file must be created in the directory
with the rest of the files for the program. The format is parsed as such:
- First string is the key/shortcut (must be one word)
- The following integer represents the deduction
- The remainder of the line represents the comment associated with the key.
- The following blank line marks the end of the list

<br>
Example listing:
<br>

`6blank 1 6 blank lines must separate each function.`
<br>
This stores a shortcut called 6blank, with a 1-point deduction, and a comment "6 blank lines must separate each function."
