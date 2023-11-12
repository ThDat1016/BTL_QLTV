#include "khaibao.h"

void ListSV::addSv(const string& tenSV, const string& lop, const string& mssv) {
    SV sv(tenSV, lop, mssv);

    NodeSv* newNode = new NodeSv(sv);

    if (!father) {
        father = newNode;
        tailSv = newNode;
    }
    else {
        tailSv->next = newNode;
        tailSv = newNode;
    }

    quick_sort();
 
}

void ListSV::DeleteSV(const string& mssv) {
    NodeSv* crr = father;
    NodeSv* prev = nullptr;

    while (crr != nullptr && crr->ThongTinSV.GetMSSV() != mssv) {
        prev = crr;
        crr = crr->next;
    }

    if (crr == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
    }
    else {
        if (crr->sizeUse == 0) {
            // Sinh viên đã trả hết sách, có thể xóa
            if (prev == nullptr) {
                // Xóa đầu danh sách
                father = crr->next;
            }
            else {
                prev->next = crr->next;
            }

            delete crr;
            cout << "Xoa sinh vien thanh cong!" << endl;
        }
        else {
            cout << "Sinh vien chua tra het sach, khong the xoa!" << endl;
        }
    }
}

void ListSV::ShowSV() {
    NodeSv* crr = father;

    if (crr == nullptr) {
        cout << endl << "Danh sach trong!";
        return;
    }
    else {
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "| " << setw(10) << left << "MSSV" << " | " << setw(30) << left << "Ten sinh vien" << " | " << setw(20) << left << "Lop" << " | " << setw(20) << left << "So Luong Sach Muon" << " | " <<endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;

        while (crr != nullptr) {
            cout << "| " << setw(10) << left << crr->ThongTinSV.GetMSSV() << " | " << setw(30) << left << crr->ThongTinSV.GetTenSv() << " | " << setw(20) << left << crr->ThongTinSV.GetLop() << " | " << setw(20) << left << crr->sizeUse << " | " <<endl;
            crr = crr->next;
        }

        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
} 

void DanhSachSachMuon(ListSV& list, const string& mssv) {
    NodeSv* sv = list.GetFather();

    // Tìm sinh viên có mã số sinh viên (MSSV) tương ứng
    while (sv != nullptr) {
        if (sv->ThongTinSV.GetMSSV() == mssv) {
            break;
        }
        sv = sv->next;
    }

    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien co MSSV " << mssv << endl;
        return;
    }

    cout << "Ten\t\tTacGia\t\tNam Xuat Ban\t\tMa Sach" << endl;
    for (int i = 0; i < sv->sizeUse; i++) {
        cout << sv->thong_tin_sm[i].ten << "\t\t" << sv->thong_tin_sm[i].tacgia << "\t\t" << sv->thong_tin_sm[i].nxb << "\t\t\t" << sv->thong_tin_sm[i].id << endl;
    }
}
void quick_sort() {
    ListSV list;
    quick_sort_helper(list.GetFather(), list.GetTailSV());
}

NodeSv* partition(NodeSv* first, NodeSv* last) {
    NodeSv* pivot = first;
    NodeSv* front = first;
    SV temp("", "", "");
    while (front != nullptr && front != last) {
        if (front->ThongTinSV.GetTenSv().compare(last->ThongTinSV.GetTenSv()) < 0) {
            pivot = first;

            temp = first->ThongTinSV;
            first->ThongTinSV = front->ThongTinSV;
            front->ThongTinSV = temp;

            // Visiting the next node
            first = first->next;
        }

        // Visiting the next node
        front = front->next;
    }

    // Change last node value to current node
    temp = first->ThongTinSV;
    first->ThongTinSV = last->ThongTinSV;
    last->ThongTinSV = temp;
    return pivot;
}

void quick_sort_helper(NodeSv* first, NodeSv* last) {
    if (first == last || first == nullptr || last == nullptr) {
        return;
    }
    NodeSv* pivot = partition(first, last);

    if (pivot != nullptr && pivot->next != nullptr) {
        quick_sort_helper(pivot->next, last);
    }

    if (pivot != nullptr && first != pivot) {
        quick_sort_helper(first, pivot);
    }
}