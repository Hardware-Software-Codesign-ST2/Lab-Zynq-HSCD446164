# Khởi tạo project mới
open_project -reset matrix_mult_prj

# Đặt hàm top-level
set_top matrix_mult

# Thêm các file nguồn thiết kế
add_files matrix_mult.cpp
add_files matrix_mult.h

# Thêm file testbench
add_files -tb matrix_mult_test.cpp

# Tạo solution1
open_solution -reset "solution1"

# Chọn vi mạch ZedBoard (Zynq-7020)
set_part {xc7z020clg484-1}

# Đặt xung nhịp 5ns
create_clock -period 5 -name default

# Chạy mô phỏng C (C Simulation)
csim_design

# Chạy tổng hợp C sang RTL (C Synthesis)
csynth_design

# Thoát script
exit