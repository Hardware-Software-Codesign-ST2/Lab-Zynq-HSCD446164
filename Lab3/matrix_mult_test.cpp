/*
 * Project: Zynq Book Tutorial 3 - HLS Matrix Multiplication Testbench
 * Author: Huỳnh Võ Gia Bảo
 * Student ID: 23119048
 */

#include <iostream>
#include "matrix_mult.h"

using namespace std;

int main() {
    mat_a_t in_mat_a[DIM][DIM];
    mat_b_t in_mat_b[DIM][DIM];
    mat_prod_t hw_result[DIM][DIM];
    mat_prod_t sw_result[DIM][DIM];
    int err_cnt = 0;

    // Khởi tạo giá trị giả lập cho 2 ma trận đầu vào A và B
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            in_mat_a[i][j] = (mat_a_t)(i + j);
            in_mat_b[i][j] = (mat_b_t)(i * j);
            hw_result[i][j] = 0;
            sw_result[i][j] = 0;
        }
    }

    // 1. Tính toán bằng phần mềm (Software expected results)
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            for(int k = 0; k < DIM; k++) {
                sw_result[i][j] += in_mat_a[i][k] * in_mat_b[k][j];
            }
        }
    }

    // 2. Chạy hàm mô phỏng phần cứng HLS (Hardware-targeted function)
    matrix_mult(in_mat_a, in_mat_b, hw_result);

    // 3. So sánh kết quả của HW và SW
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            if(hw_result[i][j] != sw_result[i][j]) {
                err_cnt++;
            }
        }
    }

    // In kết quả ra Console
    if(err_cnt == 0) {
        cout << "Test passed!" << endl;
        return 0;
    } else {
        cout << "Test failed: " << err_cnt << " mismatches." << endl;
        return 1;
    }
}