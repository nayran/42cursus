make re
make bonus

function ko ()
{
	if [ $1 == "KO" ]; then
		echo "OK"
	else
		echo "ERROR"
	fi
}

function error ()
{
	if [ $1 == "Error" ]; then
		echo "OK"
	else
		echo "ERROR"
	fi
}

function arg ()
{
	Y=$(./push_swap $1 | wc -l)
	X=$(./push_swap $1 | ./checker_Mac $1)
	echo "$X - $Y"
}


echo "Errors"
error $(./push_swap sad)
error $(./push_swap 1 1 2)
error $(./push_swap 1 2 2)
error $(./push_swap 2147483648)
error $(./push_swap -2147483648)

echo "\nNothing"
./push_swap 2147483647
./push_swap -2147483647
./push_swap
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
echo "OK"

echo "\n3 args (max 3)"
ARG="2 1 0"
arg "$ARG"
ARG="1 0 2"
arg "$ARG"
ARG="0 2 1"
arg "$ARG"

echo "\n5 args (max 12)"
ARG="1 5 2 4 3"
arg "$ARG"
ARG="`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`"
arg "$ARG"

echo "\n100 args (max 1500)"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"

echo "\n500 args (max 11500)"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"

echo "\n\nBONUS\n"

echo "Errors"
error $(./checker sad)
error $(./checker 1 1 2)
error $(./checker 1 2 2)
error $(./checker 2147483648)
error $(./checker -2147483648)
echo "Give a wrong action"
error $(./checker 3 2 1)
echo "Give an action with several spaces"
error $(./checker 3 2 1)

echo "\nNothing"
./checker
echo "OK"

echo "\nCommands: sa, pb, rrr"
ko $(./checker 0 9 1 8 2 7 3 6 4 5)
echo "\nTry some random valid actions"
ko $(./checker 4 2 1 3)

echo "\nMust be OKs"
echo "\nOnly ctrl D"
./checker 0 1 2
echo "\nCommands: pb, ra, pb, ra, sa, ra, pa, pa"
./checker 0 9 1 8 2
