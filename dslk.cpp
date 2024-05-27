#include<bits/stdc++.h>
#define max 10
using namespace std;

//count < size 1 don vi

struct SinhVien{
	string maSV;
	string tenSV;
	string gioiTinh;
	int namSinh;
	int diemTK;
};

struct List{
	int count;
	SinhVien e[max];
};
List L;

//khoi tao rong
void khoiTao(List &L){
	L.count = -1;
}
//kiem tra rong
int ktRong(List L){
	return L.count == -1;
}
//kiem tra day
int ktDay(List L){
	return L.count == max - 1;
}
//size
int size(List L){
	int cnt = 0;
	for(int i = 0; i <= L.count; i++){
		cnt++;
	}
	return cnt;
}
//nhap sinh vien
void nhapSV(SinhVien &sv){
	cout << "Ma sv: "; cin >> sv.maSV;
	if(sv.maSV == "***") return;
	cout << "Ten sv: "; cin.ignore(); getline(cin, sv.tenSV);
	cout << "Gioi tinh: "; cin >> sv.gioiTinh;
	cout << "Nam sinh: "; cin >> sv.namSinh;
	cout << "Diem tk: "; cin >> sv.diemTK;
}
//them cuoi
int themCuoi(List &L, SinhVien sv){
	if(ktDay(L)) return 0;
	else{
		L.count++; //-1 + 1 = 0
		L.e[L.count] = sv;
		return 1;
	}
}
//nhap ds
void nhapDS(List &L){
	SinhVien sv;
	int i = 0;
	cout << "NHAP *** DE DUNG!!!" << endl;
	do{
		cout << "Nhap sinh vien thu " << i+1 << ": " << endl;
		nhapSV(sv);
		if(sv.maSV == "***") return; // ket thuc nhap = ***
		if(!themCuoi(L, sv)) return; // ket thuc nhap khi ds day
		i++;
	}while(1);
}
//hien thi ds
void hienThiDS(List L){
	if(ktRong(L)){
		cout << "Danh sach rong!!!" << endl;
		return;
	}
	cout << setw(10) << "STT";
	cout << setw(10) << "Ma sv";
	cout << setw(14) << "Ten sv";
	cout << setw(12) << "Gioi tinh";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Diem tk" << endl;
	for(int i = 0; i <= L.count; i++){
		cout << setw(10) << (i+1);
		cout << setw(10) << L.e[i].maSV;
		cout << setw(14) <<	L.e[i].tenSV;
		cout << setw(12) << L.e[i].gioiTinh;
		cout << setw(10) << L.e[i].namSinh;
		cout << setw(10) << L.e[i].diemTK << endl;
	}
}
//xoa dau
void xoaDau(List &L){
	if(ktRong(L)) return;
	for(int i = 1; i <= L.count; i++){
		L.e[i-1] = L.e[i];
	} 
	L.count--;
}
//xoa k
void xoaK(List &L, int k){
	if(ktRong(L)) return;
	if(k == 1) xoaDau(L);
	else{
		for(int i = k-1; i < L.count; i++){
			L.e[i] = L.e[i+1];
		}
		L.count--;
	}
}
//chen k
void chenK(List &L, int k){
	SinhVien sv;
	cout << "Thong tin can chen: " << endl;
	nhapSV(sv);
	if(!ktDay(L) && k <= L.count+2 && k >= 1){
		for(int i = L.count; i >= k-1; i--){
			L.e[i+1] = L.e[i];
		}
		L.e[k-1] = sv;
		L.count++;
	}
	else cout << "Danh sach day!!" << endl;
}
//tim kiem vi tri k
int timKiem(List L, int k){
	int i = 0;
	while(i <= L.count && i != k-1){
		i++;
	}
	if(i <= L.count) return i;
	else return -1;
}
//thay the sv vi tri k
void thayThe(List &L){
	int viTriCanThay;
	cout << "Vi tri can thay: "; cin >> viTriCanThay;
	int viTri = timKiem(L, viTriCanThay);
	if(viTri != -1){
		SinhVien sv;
		cout << "Thong tin thay the: " << endl;
		nhapSV(sv);
		L.e[viTri] = sv;
	}
	else cout << "Khong tim thay!!" << endl;
	
}
//dem sv theo ten
int demSV(List L, string ten){
	int cnt = 0;
	for(int i = 0; i <= L.count; i++){
		if(L.e[i].tenSV == ten) cnt++;
	}
	return cnt;
}
//sap xep
void selectionSort(List &L){
	for(int i = 0; i < L.count; i++){
		int m = i;
		for(int j = i+1; j <= L.count; j++){
			if(L.e[j].tenSV < L.e[m].tenSV){
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

void bubbleSort(List &L){
	for(int i = 0; i < L.count; i++){
		for(int j = L.count; j > i; j--){
			if(L.e[j].tenSV < L.e[j-1].tenSV){
				SinhVien tmp = L.e[j];
				L.e[j] = L.e[j-1];
				L.e[j-1] = tmp;
			}
		}
	}
}

void insertionSort(List &L){
	for(int i = 1; i <= L.count; i++){
		SinhVien t = L.e[i]; // dang xet
		int j = i-1;
		while(j >= 0 && t.tenSV < L.e[j].tenSV){
			L.e[j+1] = L.e[j];
			j--;
		}
		L.e[j+1] = t; // -1 + 1 = 0
	}
}
//tim ten
void timTen(List L, string name){
	int i = 0;
	bool found = false;
	cout << "Danh sach thong tin sinh vien can tim: " << endl;
	while(i <= L.count){
		if(L.e[i].tenSV == name){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(14) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << L.e[i].maSV;
			cout << setw(14) <<	L.e[i].tenSV;
			cout << setw(12) << L.e[i].gioiTinh;
			cout << setw(10) << L.e[i].namSinh;
			cout << setw(10) << L.e[i].diemTK << endl;
		}
		i++;
	}
	if(!found) cout << "Khong tim thay!" << endl;
}
//xoa sv theo nam
void xoaNam(List &L, int nam){
	if(ktRong(L)) return;
	int i = 0;
	while(i <= L.count){
		if(L.e[i].namSinh == nam){
			xoaK(L, i+1);
		}
		i++;
	}
}
//xoa sv nam sinh nho nhat dau tien
int timMin(List L){
	if(!ktRong(L)){
		int viTriMin = 0;
		for(int i = 0; i <= L.count; i++){
			if(L.e[i].namSinh < L.e[viTriMin].namSinh){
				viTriMin = i;
			}
		}
		return viTriMin;
	}
	else return -1;
}

void xoaSvMin(List &L){
	int viTri = timMin(L);
	if(viTri != -1){
		xoaK(L, viTri+1);
	}
	else cout << "Khong xoa duoc!!" << endl;
}
//xoa sv diem cao nhat dau tien
int timMax(List L){
	if(!ktRong(L)){
		int viTriMax = 0;
		for(int i = 0; i <= L.count; i++){
			if(L.e[i].diemTK > L.e[viTriMax].diemTK){
				viTriMax = i;
			}
		}
		return viTriMax;
	}
	else return -1;
}

void xoaSvMax(List &L){
	int viTri = timMax(L);
	if(viTri != -1){
		xoaK(L, viTri+1);
	}
	else cout << "Khong xoa duoc!!" << endl;
}
//hien thi sv co diem cao nhat
void diemMax(List L){
	int viTri = timMax(L);
	int i = 0;
	bool found = false;
	cout << "Danh sach sv diem cao nhat" << endl;
	while(i <= L.count){
		if(L.e[i].diemTK == L.e[viTri].diemTK){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(14) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << L.e[i].maSV;
			cout << setw(14) <<	L.e[i].tenSV;
			cout << setw(12) << L.e[i].gioiTinh;
			cout << setw(10) << L.e[i].namSinh;
			cout << setw(10) << L.e[i].diemTK << endl;
		}
		i++;
	}
}
//hien thi sv co diem > 3
void diemLon3(List L){
	int i = 0;
	bool found = false;
	cout << "Danh sach sv diem > 3" << endl;
	while(i <= L.count){
		if(L.e[i].diemTK > 3){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(14) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << L.e[i].maSV;
			cout << setw(14) <<	L.e[i].tenSV;
			cout << setw(12) << L.e[i].gioiTinh;
			cout << setw(10) << L.e[i].namSinh;
			cout << setw(10) << L.e[i].diemTK << endl;
		}
		i++;
	}
}

int main(){
	List L;
	khoiTao(L);
	nhapDS(L);
	cout << "Danh sach ban dau" << endl;
	hienThiDS(L);
	
//	xoaDau(L);
//	cout << "Danh sach sau khi xoa dau: " << endl;
//	hienThiDS(L);
	
//	int k;
//	cout << "Vi tri can xoa: "; cin >> k;
//	while(k < 1 || k > size(L)){
//		cout << "Vi tri khong hop le! Nhap lai" << endl;
//		cout << "Vi tri can xoa: "; cin >> k;
//	}
//	xoaK(L, k);
//	cout << "Danh sach sau khi xoa: " << endl;
//	hienThiDS(L);
	
	int a;
	cout << "Vi tri chen: "; cin >> a;
	chenK(L, a);
	cout << "Danh sach sau khi chen: " << endl;
	hienThiDS(L);

//	thayThe(L);
//	cout << "Danh sach sau khi thay the: " << endl;
//	hienThiDS(L);

//	string tenDem;
//	cout << "Ten can dem: "; cin.ignore(); getline(cin, tenDem);
//	cout << "So luong sv ten " << tenDem << ": " << demSV(L, tenDem) << endl; 

//	selectionSort(L);
//	cout << "Danh sach sau khi sap xep: " << endl;
//	hienThiDS(L);
	
//	bubbleSort(L);
//	cout << "Danh sach sau khi sap xep: " << endl;
//	hienThiDS(L);
	
//	insertionSort(L);
//	cout << "Danh sach sau khi sap xep: " << endl;
//	hienThiDS(L);
	
//	string tenCanTim;
//	cout << "Ten sv can tim: "; cin.ignore(); getline(cin, tenCanTim);
//	timTen(L, tenCanTim);

//	int nam;
//	cout << "Nam can xoa: "; cin >> nam;
//	xoaNam(L, nam);
//	cout << "Danh sach sv sau khi xoa theo nam: " << endl;
//	hienThiDS(L);

//	xoaSvMin(L);
//	cout << "Danh sach sau khi xoa: " << endl;
//	hienThiDS(L);

//	xoaSvMax(L);
//	cout << "Danh sach sau khi xoa max: " << endl;
//	hienThiDS(L);

//	diemLon3(L);
	
//	diemMax(L);
	
	return 0;
} 
