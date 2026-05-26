#include "xil_printf.h"
#include "sleep.h" // Thư viện chứa hàm sleep() để tạo độ trễ

// Biến toàn cục lưu giá trị đếm
static u32 gia_tri_dem = 0;

// Hàm in giá trị ra màn hình dưới dạng nhị phân (Mô phỏng 8 đèn LED)
void in_gia_tri_led_nhi_phan(u32 gia_tri) {
    xil_printf("[LED7 -> LED0]: ");
    // Dịch bit để in từ bit 7 xuống bit 0
    for (int i = 7; i >= 0; i--) {
        u32 bit = (gia_tri >> i) & 1;
        xil_printf("%d", bit);
    }
    xil_printf(" (He thap phan: %d)\r\n", gia_tri);
}

// Hàm giả lập hành vi khi có ngắt nút nhấn xảy ra
void xu_ly_ngat_nut_nhan_gia_lap() {
    // Tăng biến đếm
    gia_tri_dem++;
    
    // In thông báo và trạng thái LED ra Console
    xil_printf("\r\n[*] Su kien: Da gia lap nhan nut!\r\n");
    in_gia_tri_led_nhi_phan(gia_tri_dem);
}

int main() {
    xil_printf("\r\n==========================================\r\n");
    xil_printf(" BAT DAU MO PHONG LOGIC DEM NGAT TREN VITIS\r\n");
    xil_printf("==========================================\r\n");

    xil_printf("Trang thai LED ban dau:\r\n");
    in_gia_tri_led_nhi_phan(gia_tri_dem);

    // Vòng lặp giả lập thao tác nhấn nút 10 lần
    for (int lan_nhan = 1; lan_nhan <= 10; lan_nhan++) {
        sleep(1); // Dừng 1 giây để dễ quan sát trên màn hình
        
        // Gọi trực tiếp hàm xử lý ngắt (Thay vì chờ tín hiệu điện từ PL)
        xu_ly_ngat_nut_nhan_gia_lap();
    }

    xil_printf("\r\n==========================================\r\n");
    xil_printf(" HOAN THANH MO PHONG\r\n");
    xil_printf("==========================================\r\n");

    return 0;
}
