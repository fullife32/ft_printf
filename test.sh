gcc -g -Wall -Wextra -Werror ft_printf.a main/main.c -o mine.out
./mine.out > result_mine

rm -f mine.out
rm -rf mine.out.dSYM/

gcc -Wall -Wextra -Werror main/main2.c -o real.out
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
