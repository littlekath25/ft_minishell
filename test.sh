#!/bin/bash

#CONFIG
cases="cases.txt"
# cases="exportvars.txt"
prompt="minishell>"
executable="minishell"

SUCCESS_COLOR="\033[01;32m"
ERROR_COLOR="\033[01;31m"
NORMAL_COLOR="\033[0m"




pass_count=0
test_count=0

while IFS= read -r line
do
	printf "$NORMAL_COLOR Testcase: $line\n"

	mini_output=$(echo $line | ./minishell | sed "/$prompt/d")
	bash_output=$(echo $line | bash)
	if [ "$mini_output" != "$bash_output" ]
	then
		printf "$ERROR_COLOR [KO!]\n"
		printf "$NORMAL_COLOR $mini_output\n"
		printf "$ERROR_COLOR Supposed to be:\n"
		printf "$NORMAL_COLOR $bash_output\n"
	else
		printf "$SUCCESS_COLOR [OK!]\n"
		((pass_count=pass_count+1))
	fi
	((test_count=test_count+1))
done < "$cases"

if [ "$pass_count" != "$test_count" ]
then
	printf "$ERROR_COLOR FAILURE [$pass_count/$test_count]\n"
else
	printf "$SUCCESS_COLOR PASSED [$pass_count/$test_count]\n"
fi

printf "$NORMAL_COLOR"
