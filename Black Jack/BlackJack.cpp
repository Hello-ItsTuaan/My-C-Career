#include <bits/stdc++.h>
using namespace std;

const int THUA = 0;
const int CUNGTHUA = 1;
const int HOA = 2;

void huyDietManHinh() {
    system("cls");
}

void tutuThoiLOL(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int ThangThatBainghiencobac() {
    return rand() % 10 + 1;
}

double THANGTHATBAI(double balance) {
    int tien;
    while (true) {
        cout << "Nhap tien cuoc (toi da " << balance << "): ";
        cin >> tien;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Vui long nhap so!\n";
        } else if (tien <= 0) {
            cout << "Tien cuoc phai lon hon 0!\n";
        } else if (tien > balance) {
            cout << "Ban khong du tien!\n";
        } else {
            return tien;
        }
    }
}

int laiNghienROI() {
    int nguoiChoi = ThangThatBainghiencobac() + ThangThatBainghiencobac();
    int nhaCai = ThangThatBainghiencobac() + ThangThatBainghiencobac();
    char luaChon;

    while (true) {
        huyDietManHinh();
        cout << "Diem cua ban: " << nguoiChoi << "\n";

        if (nguoiChoi > 21) {
            cout << "QUAC! Ban vuot qua 21.\n";
            return THUA;
        }

        cout << "Boc them? (y/n): ";
        cin >> luaChon;

        if (luaChon == 'y' || luaChon == 'Y') {
            int la = ThangThatBainghiencobac();
            cout << "Ban ThangThatBainghiencobac duoc: " << la << "\n";
            nguoiChoi += la;
            tutuThoiLOL(800);
        } else if (luaChon == 'n' || luaChon == 'N') {
            break;
        }
    }

    huyDietManHinh();
    cout << "Diem cua ban: " << nguoiChoi << "\n";
    cout << "Nha cai co: " << nhaCai << "\n";
    tutuThoiLOL(1000);

    while (nhaCai < 17) {
        int la = ThangThatBainghiencobac();
        nhaCai += la;
        cout << "Nha cai boc them: " << la << " -> " << nhaCai << "\n";
        tutuThoiLOL(1000);
    }

    cout << "\nBan: " << nguoiChoi << " | Nha cai: " << nhaCai << "\n";

    if (nhaCai > 21) {
        cout << "Nha cai QUAC!\n";
        return CUNGTHUA;
    }
    if (nguoiChoi > nhaCai) return CUNGTHUA;
    if (nguoiChoi == nhaCai) return HOA;
    return THUA;
}

int main() {
    srand(time(NULL));
    double balance = 1000;
    int menu;

    while (balance > 0) {
        huyDietManHinh();
        cout << "Ban dang co: " << balance << "\n";
        cout << "1. Bat dau\n";
        cout << "2. Thoat\n";
        cout << "> ";
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (menu == 2) {
            cout << "Tam biet!\n";
            return 0;
        }

        if (menu != 1) {
            continue;
        }

        double tienCuoc = THANGTHATBAI(balance);
        int ketQua = laiNghienROI();

        if (ketQua == CUNGTHUA) {
            balance += tienCuoc;
            cout << "BAN THANG! +" << tienCuoc << "\n";
        } else if (ketQua == THUA) {
            balance -= tienCuoc;
            cout << "Ban thua! -" << tienCuoc << "\n";
        } else {
            cout << "HOA! Hoan lai tien cuoc.\n";
        }

        cout << "So du hien tai: " << balance << "\n";
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore(1000, '\n');
        cin.get();
    }

    huyDietManHinh();
    cout << "Het tien roi! GAME OVER\n";
    return 0;
}