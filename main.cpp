#include "khaibao.h"

int main() {
    ListSach listSach;
    ListSV listSV;
    int choice = 1;
    int maxChoice = 10; 
    static string tenSach, tacGia, mssv;
    static int namXuatBan, maSach;
    ifstream filein, filein1;

    filein.open("D:\\Project4\\ThongTinSach.txt", ios_base::in);
    filein1.open("D:\\Project4\\ThongTinSinhVien.txt", ios_base::in);
    if (!filein.is_open() || !filein1.is_open()) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
   
    DocFileSach(filein, listSach);
    DocFileSV(filein1, listSV);
    filein.close();
    filein1.close();
    while (true) {      
        if (ChucNangMenuChinh(listSach, listSV, tenSach, tacGia, mssv, namXuatBan, maSach, choice, maxChoice) == 0) break;
        else ChucNangMenuChinh(listSach, listSV, tenSach, tacGia, mssv, namXuatBan, maSach, choice, maxChoice);
    }

    
    return 0;
}





