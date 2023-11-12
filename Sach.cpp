#include "khaibao.h"

void ListSach::addSach(const string& TenSach, const string& TacGia, int NamXuatBan) {
	Node* crr = this->GetHead();
	// Tạo đối tượng sách mới với thông tin từ tham số
	Sach newSach(TenSach, TacGia, NamXuatBan);
	int id = newSach.randomId();
	newSach.SoLuong += 1;

	// Tạo một bản sao của tên sách để đảm bảo không thay đổi dữ liệu gốc
	string TenSachCopy = TenSach;

	// Lưu thông tin vào node mới
	Node* newNode = new Node(newSach);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}


void ListSach::PrintSach() {
	Node* crr = this->GetHead();
	if (!crr) {
		cout << "Danh sach sach trong." << endl;
		return;
	}

	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| " << setw(6) << left << "ID" << " | " << setw(50) << left << "Ten sach" << " | "
		<< setw(30) << left << "Tac gia" << " | " << setw(15) << left << "Nam xuat ban" << " | " << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

	while (crr != nullptr) {
			cout << "| " << setw(6) << left << crr->ThongTinSach.ID << " | "
				<< setw(50) << left << crr->ThongTinSach.TenSach << " | "
				<< setw(30) << left << crr->ThongTinSach.TacGia << " | "
				<< setw(15) << left << crr->ThongTinSach.NamXuatBan << " | " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		crr = crr->next;
	}
}

void ListSach::searchBook(const string& TenSach) {
	if (this->GetHead() == nullptr) {
		cout << "\nKhong Co Cuon Sach Nao";
		return;
	}
	cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "| " << setw(6) << left << "ID" << " | " << setw(30) << left << "Ten sach" << " | " << setw(20) << left << "Tac gia" << " | "
				<< setw(15) << left << "Nam xuat ban" << " | " << setw(10) << left << "So Luong" << " |" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			Node* crr = this->GetHead();

			while (crr != nullptr) {
				if(TenSach == crr->ThongTinSach.TenSach)
				{
					cout << "| " << setw(5) << left << crr->ThongTinSach.ID << " | "
						<< setw(30) << left << crr->ThongTinSach.TenSach << " | "
						<< setw(20) << left << crr->ThongTinSach.TacGia << " | "
						<< setw(15) << left << crr->ThongTinSach.NamXuatBan << " | "
						<< setw(10) << left << crr->ThongTinSach.SoLuong << " |" << endl;
					cout << "-------------------------------------------------------------------------------------------------" << endl;
				}
				crr = crr->next;
			}
			crr = this->GetHead();
			cout << endl << "ID Sach Chua Duoc Muon: ";
			while (crr != nullptr) {
				if(crr->ThongTinSach.TenSach == TenSach && crr->ThongTinSach.TinhTrang == "0")
					cout << crr->ThongTinSach.ID << "  ";
				crr = crr -> next;
			}
		
	return;
}
int ListSach::SoLuong() {
	Node* crr = head;
	int count = 0;
	while (crr != nullptr) {
		count++;
		crr = crr->next;
	}
	return count;
}

int ListSach::duyetSach(const string& tenSach) {
	Node* crr = head;
	Node* prev = nullptr;
	while (crr != nullptr && tenSach != crr->ThongTinSach.TenSach) {
		prev = crr;
		crr = crr->next;
	}
	if (crr == nullptr) {
		return 0;
	}
	else {
		if (prev == nullptr) {
			head = crr->next;
		}
		else {
			prev->next = crr->next;
		}
		delete crr;
		return 1;
	}
}


void ListSach::xoaSach(const string& tenSach) {
	ListSach list;
	while (duyetSach(tenSach) != 0) {
		duyetSach(tenSach);
	}
}