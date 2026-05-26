/*
 * Project: Zynq Book Tutorial 3 - HLS Matrix Multiplication
 * Author: Huỳnh Võ Gia Bảo
 * Student ID: 23119048
 */

#include "matrix_mult.h"

void matrix_mult(mat_a_t a[DIM][DIM], mat_b_t b[DIM][DIM], mat_prod_t prod[DIM][DIM])
{
    // Duyệt qua các hàng của ma trận A
    Row: for(int i = 0; i < DIM; i++) {
        
        // Duyệt qua các cột của ma trận B
        Col: for(int j = 0; j < DIM; j++) {
            
            // Khởi tạo giá trị ban đầu cho kết quả
            prod[i][j] = 0;
            
            // Tính tích chập (inner product)
            Product: for(int k = 0; k < DIM; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}