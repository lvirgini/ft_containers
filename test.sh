#! bin/bash

# remove old results
rm std.log ft.log

# compile
make

# execute and save results
echo "time for std:"
time ./std_containers > std.log
echo " -------------------- * "
echo "time for ft:"
time ./ft_containers > ft.log
echo " -------------------- * "

# show the differences between std and ft
diff -a std.log ft.log