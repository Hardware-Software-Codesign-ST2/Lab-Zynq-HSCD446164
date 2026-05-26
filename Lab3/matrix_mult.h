/*
 * Project: Zynq Book Tutorial 3 - HLS Matrix Multiplication
 * Author: Huỳnh Võ Gia Bảo
 * Student ID: 23119048
 */

#ifndef __MATRIXMULT_H__
#define __MATRIXMULT_H__

// Định nghĩa kích thước ma trận là 5x5 (theo như tài liệu yêu cầu 25 phần tử)
#define DIM 5

// Dựa vào báo cáo tổng hợp (Synthesis Report) ở cuối tài liệu:
// port a và b dùng dữ liệu 8-bit, port prod dùng dữ liệu 16-bit.
typedef char mat_a_t;
typedef char mat_b_t;
typedef short mat_prod_t;

// Nguyên mẫu hàm (Prototype)
void matrix_mult(mat_a_t a[DIM][DIM], mat_b_t b[DIM][DIM], mat_prod_t prod[DIM][DIM]);

#endif // __MATRIXMULT_H__