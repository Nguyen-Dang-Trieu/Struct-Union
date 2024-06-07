#include <stdio.h>

// Define struct SinhVien
struct SinhVien {
    char ten[20];          // 20 bytes
    int tuoi;              // 4 bytes
    float diemTrungBinh;   // 4 bytes
};

int main() {
    // Tạo một biến struct SinhVien và khởi tạo giá trị sẵn
    struct SinhVien sv1 = {"Nguyen Dang Trieu", 23, 8.5};

    // Sử dụng con trỏ để trỏ tới struct SinhVien
    struct SinhVien *ptrSV = NULL;

    // Gán địa chỉ của sv1 cho ptrSV
    ptrSV = &sv1;

    // Size of struct SinhVien
    printf("Size of struct SinhVien: %ld bytes\n", sizeof(struct SinhVien));
    // Size of struct pointer
    printf("Size of pointer struct: %ld bytes\n", sizeof(ptrSV));

    // In thông tin của sinh viên
    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", ptrSV->ten);
    printf("Tuoi: %d\n", ptrSV->tuoi);
    printf("Diem trung binh: %.2f\n", ptrSV->diemTrungBinh);

    return 0;
}

