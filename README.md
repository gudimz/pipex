# Pipex.

## Instructions.

This program simulates the work of pipes and redirects

## Examples.

 `$> ./pipex infile ``ls -l'' ``wc -l'' outfile`

should be the same as `“< infile ls -l | wc -l > outfile”`

`$> ./pipex infile ``grep a1'' ``wc -w'' outfile`
should be the same as `“< infile grep a1 | wc -w > outfile”`
***

## How to use?

`make`

`$> ./pipex file1 cmd1 cmd2 file2`


## How to use test?

`make test`

## Good Luck!
