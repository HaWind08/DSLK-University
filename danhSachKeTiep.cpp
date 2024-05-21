#include<bits\stdc++.h>
#define MAX 10
using namespace std;

struct SinhVien{
	char maSV[10];
	char hoDem[20];
	char ten[10];
	char gioiTinh[5];
	int namSinh;
	double diemTK;
};

struct List{
	int count;
	SinhVien e[MAX];
};

SinhVien taoSV(const char maSV[10], const char hoDem[20], const char ten[10], const char gioiTinh[5], int namSinh, double diemTK){
	SinhVien sv;
	strcpy(sv.maSV, maSV); //copy chuoi
	strcpy(sv.hoDem, hoDem);
	strcpy(sv.ten, ten);
	strcpy(sv.gioiTinh, gioiTinh);
	sv.namSinh = namSinh;
	sv.diemTK = diemTK;
	return sv;
}

//khoi tao danh sach rong
void khoiTao(List &L){
	L.count = -1;
}

//kiem tra ds rong
int empty(List L){
	return L.count == -1;
}

// kiem tra ds day
int full(List L){
	return L.count == MAX - 1;
}

int add(List &L, SinhVien sv){
	if(full(L)) return 0;
	else{
		L.e[L.count + 1] = sv;
		L.count++;
		return 1;
	}
}

void nhap(List &L){
	add(L, taoSV("SV1001", "Tran Van", "Thanh", "Nam" , 1999, 7.5));
	add(L, taoSV("SV1002", "Nguyen Thi", "Huong", "Nu" , 2000, 7.3));
	add(L, taoSV("SV1003", "Nguyen Van", "Binh", "Nam" , 1998, 6.4));
	add(L, taoSV("SV1004", "Bui Thi", "Hong", "Nu" , 2000, 5.8));
	add(L, taoSV("SV1005", "Duong Van", "Giang", "Nam" , 1998, 8.3));
}

void hienThiDanhSach(List L){
	cout << setw(5) << "STT";
	cout << setw(10) << "Ma SV";
	cout << setw(15) << "Ho Dem";
	cout << setw(10) << "Ten";
	cout << setw(15) << "Gioi Tinh";
	cout << setw(10) << "Nam sinh";
	cout << setw(18) << "Diem tong ket" << endl;
	
	for(int i = 0; i <= L.count; i++){
		cout << setw(5) << (i + 1);
		cout << setw(10) << L.e[i].maSV;
		cout << setw(15) << L.e[i].hoDem;
		cout << setw(10) << L.e[i].ten;
		cout << setw(15) << L.e[i].gioiTinh;
		cout << setw(10) << L.e[i].namSinh;
		cout << setw(18) << L.e[i].diemTK << endl;
	}
}

// xoa phan tu dau tien
int xoaDau(List &L){
	if(empty(L)) return 0;
	for(int i = 1; i <= L.count; i++){
		L.e[i - 1] = L.e[i];
	}
	L.count--;
	return 1;
}

//chen vao vi tri thu 3(k = 3)
int chen(List &L, int k, SinhVien sv){
	if(k <= L.count + 1 && k > 0 && !full(L)){
		for(int i = L.count; i >= k - 1; i--){
			L.e[i + 1] = L.e[i];
		}
		L.e[k-1] = sv;
		L.count++;
		return 1;
	}
	else return 0;
}

//sap xep tang dan (selection sort)
void sepXepTang(List &L){
	for(int i = 0; i < L.count; i++){
		int m = i; // min
		for(int j = i + 1; j <= L.count; j++){
			if(strcmp(L.e[j].ten, L.e[m].ten) < 0){ // j < m
				 m = j;
			}
		}
		if(m != i){
			SinhVien tmp = L.e[i];
			L.e[i] = L.e[m];
			L.e[m] = tmp;
		}
	}
}

int main(){
	List L;
	khoiTao(L);
	nhap(L);
	
	cout << "--------------------DANH SACH SINH VIEN--------------------" << endl;
	hienThiDanhSach(L);
	cout << endl;
	
	//xoa
	if(xoaDau(L)){
		cout << "Xoa thanh cong!" << endl;
		cout << "--------------------DANH SACH SINH VIEN SAU KHI XOA--------------------" << endl;
		hienThiDanhSach(L);
		cout << endl;
	}
	else cout << "Xoa khong thanh cong!";
	
	//them
	if(chen(L, 3, taoSV("SV1006", "Le Thi", "Doan", "Nu", 1998, 7.6))){
		cout << "Them thanh cong!" << endl;
		cout << "--------------------DANH SACH SINH VIEN SAU KHI THEM--------------------" << endl;
		hienThiDanhSach(L);
		cout << endl;
	}
	else cout << "Them khong thanh cong!";
	
	//sap xep
	sepXepTang(L);
	cout << "--------------------DANH SACH SINH VIEN SAU KHI SAP XEP--------------------" << endl;
	hienThiDanhSach(L);
	cout << endl;
	
	return 0;
}
