#pragma once
#include"khaibao.h"
#include"Muon_Tra.h"
class Sach {
public:
	string TenSach, TacGia, TinhTrang, SinhVienMuon;
	int NamXuatBan, SoLuong, ID;
	Sach() {};
	Sach(const string& TenSach, const string& TacGia, int NamXuatBan) {
		this->NamXuatBan = NamXuatBan;
		SoLuong = 0;
		this->TacGia = TacGia;
		this->TenSach = TenSach;
		ID = randomId();
		SinhVienMuon = "";// neu co sv muon thi gan mssv vao bien nay, tra sach thi quay ve = 0
		TinhTrang = '0';
	}
	int randomId() const {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(100000, 999999);
		return dis(gen);
	}
};
class Node {
public:
	Sach ThongTinSach;
	Node* next;
	Node(Sach& ThongTinSach) : ThongTinSach(ThongTinSach), next(nullptr) {}
};
class ListSach {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void addSach(const string& TenSach, const string& TacGia, int NamXuatBan);
	Node* GetHead() const {
		return head;
	}
	void SetHead(Node* crr) {
		head = crr;
	}

	void PrintSachTQ();
	void PrintSach();
	//void sort_AZ(); // sap xep chu cai
	void searchBook(const string& TenSach);
	void GetSachID(const string& TenSach, const string& TacGia, int NamXuatBan);
	void deleteBook(const string& id);
	void saveToFile(const string& filename);
	void SoLuong();
};

class NodeSv;
class SV {
private:
	string MSSV;
	string TenSv, Lop;
	int idSach;
public:
	//SV() {};
	SV(const string& TenSv, const string& Lop, const string& MSSV) {
		this->Lop = Lop;
		this->MSSV = MSSV;
		this->TenSv = TenSv;
		idSach = 0;
	}
	string GetMSSV() const {
		return MSSV;
	}
	void SetMSSV(const string& newMSSV) {
		MSSV = newMSSV;
	}
	string GetTenSv() const {
		return TenSv;
	}
	void SetTenSv(const string& ten) {
		TenSv = ten;
	}
	string GetLop() const {
		return Lop;
	}
	void SetLop(const string& lop) {
		Lop = lop;
	}
	int GetIdSach() {
		return idSach;
	}
	void SetIdSach(int id) {
		idSach = id;
	}
};

class NodeSv {
public:
	SV ThongTinSV;
	NodeSv* left;// noi sach da muon cua moi sinh vien
	NodeSv* right;// noi cac sinh vien voi nhau
	NodeSv(SV& ThongTinSV) : ThongTinSV(ThongTinSV), left(nullptr), right(nullptr) {}
};

class ListSV {
private:
	NodeSv* father = nullptr;

public:
	NodeSv* GetFather() {
		return father;
	}
	void SetFaTher(NodeSv* head) {
		father = head;
	}
	void addSv(const string& tenSV, const string& lop, const string& mssv);
	void TraSach(const string& mssv, const string& TrinhTrang);
};