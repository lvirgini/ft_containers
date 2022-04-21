#! bin/bash

# remove old results
rm std.log ft.log

# compile
make

# execute and save results
./std_containers > std.log
./ft_containers > ft.log

# show the differences between std and ft
diff -a std.log ft.log