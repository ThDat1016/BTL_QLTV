#include"khaibao.h"


void ListSV::addSM(NodeSv* sv, ListSach& bookList, const string& ten, const string& tacgia, int nxb) {
    if (sv != nullptr) {
        Node* currentBook = bookList.GetHead();

        while (currentBook != nullptr) {
            if (currentBook->ThongTinSach.TenSach == ten &&
                currentBook->ThongTinSach.TacGia == tacgia &&
                currentBook->ThongTinSach.NamXuatBan == nxb &&
                currentBook->ThongTinSach.TinhTrang != "1") {
                // Kiểm tra danh sách sách mượn chưa đầy
                if (sv->sizeUse < sv->size) {
                    sv->thong_tin_sm[sv->sizeUse].ten = ten;
                    sv->thong_tin_sm[sv->sizeUse].tacgia = tacgia;
                    sv->thong_tin_sm[sv->sizeUse].nxb = nxb;
                    sv->thong_tin_sm[sv->sizeUse].id = currentBook->ThongTinSach.ID;
                    sv->sizeUse++;
                    currentBook->ThongTinSach.TinhTrang = "1";
                    cout << "Muon sach thanh cong!" << endl;
                }
                else {
                    cout << "Danh sach sach muon da day!" << endl;
                }
                return;
            }
            currentBook = currentBook->next;
        }
        cout << "Khong tim thay sach hoac sach da bi muon!" << endl;
    }
    else {
        cout << "Sinh vien khong ton tai!" << endl;
    }
}

void ListSV::Muon_Sach(const string& mssv, ListSach& listSach, ListSV& list) {
    string ten, tacgia;
    int nxb;

    NodeSv* crr = list.GetFather();
    bool found = false;
    while (crr != nullptr) {
        if (crr->ThongTinSV.GetMSSV() == mssv) {
            found = true;
            break;
        }
        crr = crr->next;
    }
    if (!found) {
        string tensv, lop;
        cout << endl << "THEM SINH VIEN";
        cin.ignore();
        cout << "Ten Sinh Vien: ";
        getline(cin, tensv);

        cout << "Lop: ";
        getline(cin, lop);

        cin.ignore();
        list.addSv(tensv, lop, mssv);
        cout << "THEM SINH VIEN THANH CONG";
    }
    else {
        cout << endl << "NHAP THONG TIN SACH MUON" << endl;
        cout << "Ten sach: ";
        getline(cin, ten);

        cout << "Tac gia: ";
        getline(cin, tacgia);

        cout << "Nam xuat ban: ";
        cin >> nxb;
        cin.ignore();
        addSM(crr, listSach, ten, tacgia, nxb);
    }
}

void ListSV::TraSach(ListSV& listSv, ListSach& bookList, const string& mssv, int maSach) {

    NodeSv* sv = listSv.GetFather();  // Lấy node gốc của danh sách sinh viên.
    bool found = false;
    while (sv != nullptr) {
        if (sv->ThongTinSV.GetMSSV() == mssv) {
            found = true;
            break;
        }
        sv = sv->next;
    }
    if (!found) {
        cout << "Khong tim thay sinh vien!" << endl;
    }
    else {
        bool foundBook = false;

        for (int i = 0; i < sv->sizeUse; i++) {
            if (sv->thong_tin_sm[i].id == maSach) {
                // Đánh dấu sách là đã trả lại ('0' là tình trạng sách đã trả).
                Node* currentBook = bookList.GetHead();

                while (currentBook != nullptr) {
                    if (currentBook->ThongTinSach.ID == sv->thong_tin_sm[i].id) {
                        currentBook->ThongTinSach.TinhTrang = '0';
                        foundBook = true;
                        break;
                    }
                    currentBook = currentBook->next;
                }

                if (!foundBook) {
                    cout << "Không tìm thấy cuốn sách!" << endl;
                }
                else {
                 
                    for (int j = i; j < sv->sizeUse - 1; j++) {
                        sv->thong_tin_sm[j] = sv->thong_tin_sm[j + 1];
                    }
                    sv->sizeUse--;
                }
                break;
            }
        }
        if (!foundBook) {
            cout << "Khong tim thay sach trong danh sach da muon!" << endl;
        }
    }
}
