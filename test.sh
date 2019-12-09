gcc -g -Wall -Wextra -Werror *.c
./a.out > result_mine

rm -f a.out
rm -rf a.out.dSYM/

gcc -Wall -Wextra -Werror real/main2.c -o real.out
./real.out > result_real

rm -f real.out

echo "Mine :"
echo "-----------------------------------"

cat result_mine

echo "\n-----------------------------------\n"

echo "Real :"
echo "-----------------------------------"

cat result_real

echo "\n-----------------------------------\n"

echo "Diff :"
echo "==================================="

diff result_mine result_real

echo "==================================="

rm -f result_mine
rm -f result_real
