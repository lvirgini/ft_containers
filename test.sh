
rm std.log ft.log

make

./std_containers > std.log
./ft_containers > ft.log

diff std.log ft.log