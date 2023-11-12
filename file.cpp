#include "khaibao.h"

void ListSach::saveToFile(const string& fileName) {
	ofstream outFile(fileName); // Mở tệp tin để ghi thông tin

	if (!outFile.is_open()) {
		cerr << "Khong the mo file " << fileName << " de ghi." << endl;
		return; // Thoát nếu không thể mở tệp tin
	}

	Node* crr = this->GetHead();
	

	while (crr != nullptr) {
		outFile << crr->ThongTinSach.ID<<"-" << crr->ThongTinSach.TenSach << "-" << left << crr->ThongTinSach.TacGia << "," << crr->ThongTinSach.NamXuatBan << endl;
		crr = crr->next;
	}

	outFile.close(); // Đóng tệp tin sau khi ghi xong
	cout << "Thong tin sach da duoc luu vao file! " << fileName << endl;
}

void ListSV::saveSvToFile(const string& fileName) {
	ofstream outFile(fileName); // Mở tệp tin để ghi thông tin

	if (!outFile.is_open()) {
		cerr << "Khong the mo file " << fileName << " de ghi." << endl;
		return; // Thoát nếu không thể mở tệp tin
	}

	NodeSv* crr = this->GetFather();
	

	while (crr != nullptr) {
		outFile << crr->ThongTinSV.GetTenSv() << "-"
			<< crr->ThongTinSV.GetLop() << ","
			<< crr->ThongTinSV.GetMSSV() << "," << endl;
		crr = crr->next;
	}

	outFile.close(); 
	cout << "Thong tin sach da duoc luu vao file! " << fileName << endl;
}
void DocFileSach(ifstream& filein, ListSach& danhSach) {
	string TenSach, TacGia;
	int NamXuatBan;
	while (!filein.eof() ){
		if (filein.eof()) break; 
		getline(filein, TenSach, '-');
		getline(filein, TacGia, ',');
		filein >> NamXuatBan;
		if (!filein.fail()) {
			danhSach.addSach(TenSach, TacGia, NamXuatBan);
			filein.ignore();
		}
	}
}

void DocFileSV(ifstream& filein, ListSV& danhSach) {
	string TenSV, Lop, mssv;
	while (getline(filein, TenSV, ',')) {
		getline(filein, Lop, ',');
		getline(filein, mssv);

		// Kiểm tra và xóa kí tự xuống dòng cuối cùng trong chuỗi mssv
		if (!mssv.empty() && mssv[mssv.length() - 1] == '\n') {
			mssv.erase(mssv.length() - 1);
		}

		if (!filein.fail()) {
			danhSach.addSv(TenSV, Lop, mssv);
		}
	}
}





