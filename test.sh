gcc -Wall -Wextra -Werror ft_printf.c main.c -I
./a.out < . > result_mine

rm -f a.out

cp ft_printf.h real/
gcc -Wall -Wextra -Werror real/main2.c -I
./a.out < . > result_real

rm -f a.out

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