#! bin/bash

# remove old results
rm std.log ft.log ft_err.log std_err.log

# compile
make

# execute and save results
echo " -------------------- * "
echo "time for std:"
time ./std_containers 42 > std.log 2> std_err.log
echo " -------------------- * "
echo "time for ft:"
time ./ft_containers 42 > ft.log 2> ft_err.log
echo " -------------------- * "


# show the differences between std and ft
echo "diff between ft and std stdin"
diff -a std.log ft.log
echo " -------------------- * "


# show the differences error between std and ft
echo "diff between ft and std stderr"
diff -a std_err.log ft_err.log
echo " -------------------- * "
