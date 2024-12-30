#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int n = 0; 

void nhapMang() {
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("So luong phan tu vuot qua gioi han!\n");
        n = 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void inMang() {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu() {
    if (n >= MAX_SIZE) {
        printf("Mang da day!\n");
        return;
    }
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (0 -> %d): ", n);
    scanf("%d", &position);

    if (position < 0 || position > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;
}

void suaPhanTu() {
    int position, value;
    printf("Nhap vi tri can sua (0 -> %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    arr[position] = value;
}

void xoaPhanTu() {
    int position;
    printf("Nhap vi tri can xoa (0 -> %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void sapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void timKiemTuyenTinh() {
    int value, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Tim thay gia tri %d tai vi tri %d\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri %d\n", value);
    }
}

void timKiemNhiPhan() {
    int value, left = 0, right = n - 1, mid, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

 
    sapXepTangDan();

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == value) {
            printf("Tim thay gia tri %d tai vi tri %d\n", value, mid);
            found = 1;
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri %d\n", value);
    }
}

void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap mang\n");
        printf("2. In mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Sap xep mang\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: nhapMang(); break;
            case 2: inMang(); break;
            case 3: themPhanTu(); break;
            case 4: suaPhanTu(); break;
            case 5: xoaPhanTu(); break;
            case 6: {
                int subChoice;
                printf("   a. Giam dan (1)\n");
                printf("   b. Tang dan (2)\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) sapXepGiamDan();
                else if (subChoice == 2) sapXepTangDan();
                else printf("Lua chon khong hop le!\n");
                break;
            }
            case 7: {
                int subChoice;
                printf("   a. Tim kiem tuyen tinh (1)\n");
                printf("   b. Tim kiem nhi phan (2)\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) timKiemTuyenTinh();
                else if (subChoice == 2) timKiemNhiPhan();
                else printf("Lua chon khong hop le!\n");
                break;
            }
            case 8: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}

