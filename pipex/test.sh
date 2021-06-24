#! /bin/bash

make

touch infile_test pipex_outfile shell_outfile
printf "salut\ncomment\nca\nva\n?\n" > infile_test

./pipex infile_test "cat" pipex_outfile
< infile_test cat > shell_outfile
echo -e "Test 1 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "cat" "grep a" pipex_outfile
< infile_test cat | grep a > shell_outfile
echo -e "Test 2 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "cat" "grep a" "wc -l" pipex_outfile
< infile_test cat | grep a | wc -l > shell_outfile
echo -e "Test 3 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "ls" "grep c" "wc -l" pipex_outfile
< infile_test ls | grep c | wc -l > shell_outfile
echo -e "Test 4 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "ls" "echo bonjour" pipex_outfile
< infile_test ls | echo bonjour > shell_outfile
echo -e "Test 5 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "ls" "echo bonjour" "wc -l" pipex_outfile
< infile_test ls | echo bonjour | wc -l > shell_outfile
echo -e "Test 6 diff:"
diff pipex_outfile shell_outfile

./pipex infile_test "cat" "cat" "ls" pipex_outfile
< infile_test cat | cat | ls > shell_outfile
echo -e "Test 7 diff:"
diff pipex_outfile shell_outfile

rm infile_test pipex_outfile shell_outfile