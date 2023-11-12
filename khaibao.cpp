#include "khaibao.h"

using namespace std;
void pressAnyKey() {
    system("cls");
}
void GoTo(SHORT posX, SHORT posY) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    SetConsoleCursorPosition(hStdout, Position);
}

void printText(const string& text, bool isSelected) {
    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31); // Set text color to red
        cout << "> " << text << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset text color to default (white)
    }
    else {
        cout << "  " << text << endl;
    }
}




void MenuChinh(int currentOption, int totalOptions) {
    system("cls");
    
    for (int i = 1; i <= totalOptions; i++) {
        GoTo(7 * 10, (10 + i));


        switch (i) {
        case 1:
            printText("Quan Ly Sach", i == currentOption);
            break;
        case 2:
            printText("Quan Ly Muon Tra", i == currentOption);
            break;
        case 3:
            printText("Thoat Chuong Trinh", i == currentOption);
            break;
        }
    }
}

int ChucNangMenuChinh(ListSach& listSach, ListSV& listSV, string& tenSach, string& tacGia, string& mssv, int namXb, int maSach, int& choice, int& maxChoice) {
    int copyChoice = choice, copyMaxChoice = maxChoice;
    MenuChinh(copyChoice, copyMaxChoice);
    char key = _getch();
    if (key == 13) {
        switch (copyChoice) {
        case 1:
            MenuChucNangQLS(listSach, listSV, tenSach, tacGia, choice, maxChoice, namXb);
            break;
        case 2:
            MenuChucNangQLMT(listSach, listSV, tenSach, tacGia, mssv, namXb, maSach, choice, maxChoice);
            break;
        case 3:
            return 0;
        }
    }
    else if (key == 72) { // Mũi tên lên
        if (choice > 1) {
            choice--;
        }
    }
    else if (key == 80) { // Mũi tên xuống
        if (choice <= 3) {
            choice++;
        }
    }
    return 1;
}
void MenuQuanLySach(int currentOption, int totalOptions) {
    system("cls");

    for (int i = 1; i <= totalOptions; i++) {
        GoTo(7 * 10, (10 + i));

        switch (i) {
        case 1:
            printText("Them Sach", i == currentOption);
            break;
        case 2:
            printText("Xoa Sach", i == currentOption);
            break;
        case 3:
            printText("Danh Sach Cac Cuon Sach", i == currentOption);
            break;
        case 4:
            printText("Tim Kiem Theo Ten Sach", i == currentOption);
            break;
        case 5:
            printText("Ghi File", i == currentOption);
            break;
        case 6:
            printText("Quay Ve Menu Chinh", i == currentOption);
            break;
        }
    }
}

void MenuQuanLyMuonTra(int currentOption, int totalOptions) {

    system("cls");

    for (int i = 1; i <= totalOptions; i++) {
        GoTo(7 * 10, (10 + i));

        switch (i) {
        case 1:
            printText("Danh Sach Sinh Vien", i == currentOption);
            break;
        case 2:
            printText("Muon Sach", i == currentOption);
            break;
        case 3:
            printText("Xoa Sach Muon", i == currentOption);
            break;
        case 4:
            printText("Xoa Sinh vien", i == currentOption);
            break;
        case 5:
            printText("Ghi File", i == currentOption);
            break;
        case 6:
            printText("Quay Ve Menu Chinh", i == currentOption);
            break;
        }
    }
}

int MenuChucNangQLS(ListSach& listSach, ListSV& listSV, string& tenSach, string& tacGia, int& choice, int& maxChoice, int namXb) {

    bool check = true;
    while (check) {
        MenuQuanLySach(choice, maxChoice);
        char key = _getch();
        if (key == 13) {
            switch (choice) {
            case 1: {
                pressAnyKey();
                cout << "Nhap thong tin sach:" << std::endl;

                cout << "Ten sach: ";
                getline(cin, tenSach);

                cout << "Tac gia: ";
                getline(cin, tacGia);

                cout << "Nam xuat ban: ";
                cin >> namXb;
                cin.ignore();
                listSach.addSach(tenSach, tacGia, namXb);
                cout << "Sach da duoc them vao danh sach." << endl;
                _getch();
                break;
            }
            case 2:
                pressAnyKey();
                cout << "Nhap Ten Sach Muon Xoa: ";
                getline(cin, tenSach);
                cin.ignore();
                listSach.xoaSach(tenSach);
                break;
            case 3:
                pressAnyKey();
                listSach.PrintSach();
                _getch();
                break;
            case 4:
            {
                pressAnyKey();
                string tenSach;
                cin.ignore(); // Loại bỏ dấu xuống dòng sau khi đọc lựa chọn.
                cout << "Nhap Ten Sach: ";
                getline(cin, tenSach);
                listSach.searchBook(tenSach);
                _getch();
                break;
            }
            case 5:
                pressAnyKey();
                listSach.saveToFile("ThongTinSach1.txt");
                _getch();
                break;
            case 6:
                check = false;
                return 0;
            }
        }
        else if (key == 72) { // Mũi tên lên
            if (choice > 1) {
                choice--;
            }
        }
        else if (key == 80) { // Mũi tên xuống
            if (choice < maxChoice) {
                choice++;
            }
        }
    }
    return 1;
}
int MenuChucNangQLMT(ListSach& listSach, ListSV& listSV, string& tenSach, string& tacGia, string& mssv, int namXb, int maSach, int& choice, int& maxChoice) {
    bool check = true;
    while (check) {
        MenuQuanLyMuonTra(choice, maxChoice);
        char key = _getch();
        if (key == 13) {
            switch (choice) {
            case 1:
                pressAnyKey();
                listSV.ShowSV();
                _getch();
                break;
            case 2:
            {
                pressAnyKey();
                cout << endl << "Nhap ma so sinh vien: ";
                getline(cin, mssv);
                cin.ignore();
                listSV.Muon_Sach(mssv, listSach, listSV);
                _getch();
                break;
            }
            case 3:
            {
                pressAnyKey();
                cin.ignore(); // Loại bỏ dấu xuống dòng và ký tự thừa

                cout << endl << "Nhap Ma So Sinh Vien: ";
                getline(cin, mssv);

                DanhSachSachMuon(listSV, mssv);

                cout << endl << "Nhap Ma Sach De Tra: ";
                cin >> maSach;

                cin.ignore(); // Loại bỏ dấu xuống dòng và ký tự thừa

                listSV.TraSach(listSV, listSach, mssv, maSach);

                cout << "Nhan Enter de tiep tuc...";
                cin.get(); // Đợi người dùng nhập Enter trước khi tiếp tục
                break;
            }
            case 4: {
                pressAnyKey();
                cout << endl << "Nhap ma so sinh vien muon xoa: ";
                getline(cin, mssv);
                cin.ignore();
                listSV.DeleteSV(mssv);
                _getch();
                break;
            }
            case 5:
                pressAnyKey();
                listSach.saveToFile("ThongTinSach1.txt");
                listSV.saveSvToFile("ThongTinSV1.txt");
                _getch();
                break;
            case 6:
                check = false;
                return 0;
                pressAnyKey();
            }
        }
        else if (key == 72) { // Mũi tên lên
            if (choice > 1) {
                choice--;
            }
        }
        else if (key == 80) { // Mũi tên xuống
            if (choice < maxChoice) {
                choice++;
            }
        }
    }
    return 1;
}
