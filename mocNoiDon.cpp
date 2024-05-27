#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
	string maSV;
	string tenSV;
	string gioiTinh;
	int namSinh;
	double diemTK;
};

struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *TRO;
TRO L;
//khoi tao
void khoiTao(TRO &L){
	L = NULL;
}
//kiem tra rong
int ktRong(TRO L){
	return L == NULL;
}
//size
int size(TRO L){
	int cnt = 0;
	while(L != NULL){
		cnt++;
		L = L->next;
	}
	return cnt;
}
//nhap 1 sv
void nhapSV(SinhVien &sv){
	cout << "Ma sv: "; cin >> sv.maSV;
	if(sv.maSV == "***") return;
	cout << "Ten sv: "; cin.ignore(); getline(cin, sv.tenSV);
	cout << "Gioi tinh: "; cin >> sv.gioiTinh;
	cout << "Nam sinh: "; cin >> sv.namSinh;
	cout << "Diem tk: "; cin >> sv.diemTK;
}
//nhap ds
void nhapDS(TRO &L){
	SinhVien sv;
	TRO P, Q;
	int i = 0;
	do{
		cout << "Nhap thong tin sv thu " << i+1 << ": " << endl;
		nhapSV(sv);
		if(sv.maSV == "***") return;
		
		P = new Node();
		P->infor = sv;
		P->next = NULL;
		if(ktRong(L)) L = P;
		else{
			Q = L;
			while(Q->next != NULL){
				Q = Q->next;
			}
			Q->next = P;
		}
		i++;
	}while(1);
}
//hien thi
void hienThiDS(TRO L){
	if(ktRong(L)){
		cout << "Danh sach rong!!!";
		return;
	}
	cout << setw(10) << "STT";
	cout << setw(10) << "Ma sv";
	cout << setw(12) << "Ten sv";
	cout << setw(12) << "Gioi tinh";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Diem tk" << endl;
	TRO Q = L;
	int i = 0;
	while(Q != NULL){
		SinhVien sv = Q->infor;
		cout << setw(10) << (i+1);
		cout << setw(10) << sv.maSV;
		cout << setw(12) << sv.tenSV;
		cout << setw(12) << sv.gioiTinh;
		cout << setw(10) << sv.namSinh;
		cout << setw(10) << sv.diemTK << endl;
		Q = Q->next;i++;
	}
	cout << endl;
}
//xoa dau
void xoaDau(TRO &L){
	if(ktRong(L)) return;
	TRO Q = L;
	L = L->next;
	delete Q;
}
// xoa vi tri k
void xoaK(TRO &L, int k){
	if(ktRong(L)) return;
	if(k == 1) xoaDau(L);
	else{
		TRO Q = L;
		int count = 1;
		while(count < k-1){
			count++;
			Q = Q->next;
		}
		TRO P = Q->next;
		Q->next = P->next;
		delete P;
	}
}
//chen dau
void chenDau(TRO &L, SinhVien sv){
	TRO P = new Node();
	P->infor = sv;
	P->next = L;
	L = P;
}
//chen k
void chenK(TRO &L, int k){
	SinhVien sv;
	cout << "Thong tin can chen: " << endl;
	nhapSV(sv);
	if(k == 1) chenDau(L, sv);
	else{
		TRO Q = L;
		int count = 1;
		while(count < k-1){
			Q = Q->next;
			count++;
		}
		TRO P = new Node();
		P->infor = sv;
		P->next = Q->next;
		Q->next = P;	
	}
}
//tim vi tri k
TRO timK(TRO L, int k){
	TRO Q;
	Q = L;
	int count = 1;
	//tim den vi tri k
	while(count < k){
		Q = Q->next;
		count++;
	}
	if(count < k) return NULL;
	else return Q;
} 
//thay the
void thayThe(TRO &L, SinhVien sv){
	if(ktRong(L)) return;
	int viTriThay;
	cout << "Vi tri thay: "; cin >> viTriThay;
	TRO Q = timK(L, viTriThay);
	cout << "Thong tin thay the: " << endl;
	nhapSV(sv);
	if(Q != NULL){
		Q->infor = sv;
	}
	else cout << "Khong tim thay!!" << endl;
}
//dem sv
int demTen(TRO L, string ten){
	TRO Q = L;
	int cnt = 0;
	while(Q != NULL){
		if(Q->infor.tenSV == ten){
			cnt++;
		}
		Q = Q->next;
	}
	return cnt;
}
//sap xep
void selectionSort(TRO &L){
	if(ktRong(L)) return;
	TRO P, Q, M;
	P = L;
	while(P->next != NULL){
		M = P;
		Q = P->next;
		while(Q != NULL){
			if(Q->infor.tenSV < M->infor.tenSV){
				M = Q;
			}
			Q = Q->next;
		}
		if(M != P){
			SinhVien tmp = P->infor;
			P->infor = M->infor;
			M->infor = tmp;
		}
		P = P->next;
	}
}
//tim ten va hien thi
void timTen(TRO L){
	string ten;
	cout << "Ten can tim: "; cin.ignore(); getline(cin, ten);
	TRO Q = L;
	int i = 0;
	bool found = false;
	cout << "Thong tin can tim: " << endl;
	while(Q != NULL){
		if(Q->infor.tenSV == ten){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(12) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << Q->infor.maSV;
			cout << setw(12) << Q->infor.tenSV;
			cout << setw(12) << Q->infor.gioiTinh;
			cout << setw(10) << Q->infor.namSinh;
			cout << setw(10) << Q->infor.diemTK << endl;
		}
		Q = Q->next;i++;
	}
	if(!found) cout << "Khong tim thay!!" << endl;
} 
//remove
void remove(TRO &L, TRO T){
	TRO Q;
	if(L == T){ // phan tu can xoa la ptu dau ds
		L = T->next;
	}
	else{
		Q = L;
		while(Q->next != T){
			Q = Q->next;
		}
		Q->next = T->next;
	}
	delete T;
}
//xoa sv theo nam sinh
void xoaNam(TRO &L){
	if(ktRong(L)) return;
	int nam;
	cout << "Nam can xoa: "; cin >> nam;
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.namSinh == nam){
			remove(L, Q);
		}
		Q = Q->next;
	}
}
//tim min
SinhVien timMin(TRO L){
	SinhVien viTriMin;
	if(ktRong(L)) return viTriMin;
	
	viTriMin = L->infor; // vi tri dau tien trong ds
	TRO Q = L->next;
	while(Q != NULL){
		if(Q->infor.namSinh < viTriMin.namSinh){
			viTriMin = Q->infor;
		}
		Q = Q->next;
	}
	return viTriMin;
}
//xoa sv nam sinh nho nhat dau tien
void xoaMin(TRO &L){
	if(ktRong(L)) return;
	SinhVien min = timMin(L);
	
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.namSinh == min.namSinh){
			remove(L, Q);
			break;
		}
		Q = Q->next;
	}
}
//tim max
SinhVien timMax(TRO L){
	SinhVien viTriMax;
	if(ktRong(L)) return viTriMax;
	
	viTriMax = L->infor; //dau ds
	TRO Q = L->next;
	while(Q != NULL){
		if(Q->infor.diemTK > viTriMax.diemTK){
			viTriMax = Q->infor;
		}
		Q = Q->next;
	}
	return viTriMax;
}
//xoa max
void xoaMax(TRO &L){
	if(ktRong(L)) return;
	SinhVien max = timMax(L);
	
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.diemTK == max.diemTK){
			remove(L, Q);
			break;
		}
		Q = Q->next;
	}
}
//hien thi diem cao nhat
void diemMax(TRO L){
	SinhVien max = timMax(L);
	TRO Q = L;
	int i = 0;
	bool found = false;
	cout << "Thong tin sinh vien diem cao nhat: " << endl;
	while(Q != NULL){
		if(Q->infor.diemTK == max.diemTK){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(12) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << Q->infor.maSV;
			cout << setw(12) << Q->infor.tenSV;
			cout << setw(12) << Q->infor.gioiTinh;
			cout << setw(10) << Q->infor.namSinh;
			cout << setw(10) << Q->infor.diemTK << endl;
		}
		Q = Q->next; i++;
	}
}
//hien thi diem > 3
void diemLon3(TRO L){
	TRO Q = L;
	int i = 0;
	bool found = false;
	cout << "Thong tin sinh vien diem > 3: " << endl;
	while(Q != NULL){
		if(Q->infor.diemTK > 3){
			if(!found){
				cout << setw(10) << "STT";
				cout << setw(10) << "Ma sv";
				cout << setw(12) << "Ten sv";
				cout << setw(12) << "Gioi tinh";
				cout << setw(10) << "Nam sinh";
				cout << setw(10) << "Diem tk" << endl;
				found = true;
			}
			cout << setw(10) << (i+1);
			cout << setw(10) << Q->infor.maSV;
			cout << setw(12) << Q->infor.tenSV;
			cout << setw(12) << Q->infor.gioiTinh;
			cout << setw(10) << Q->infor.namSinh;
			cout << setw(10) << Q->infor.diemTK << endl;
		}
		Q = Q->next; i++;
	}
}


int main(){
	TRO L;
	SinhVien sv;
	khoiTao(L);
	nhapDS(L);
	cout << "Danh sach ban dau" << endl;
	hienThiDS(L);
	
//	xoaDau(L);
//	cout << "Danh sach sau khi xoa:" << endl;
//	hienThiDS(L);

//	int viTriXoa;
//	cout << "Vi tri xoa: "; cin >> viTriXoa;
//	while(viTriXoa < 1 || viTriXoa > size(L)){
//		cout << "Vi tri khong hop le! Nhap lai" << endl;
//		cout << "Vi tri xoa: "; cin >> viTriXoa;
//	}
//	xoaK(L, viTriXoa);
//	cout << "Danh sach sau khi xoa:" << endl;
//	hienThiDS(L);

//	cout << "Thong tin can chen: " << endl;
//	nhapSV(sv);
//	chenDau(L, sv);
//	cout << "Danh sach sau khi chen: " << endl;
//	hienThiDS(L);
	
//	int viTriChen;
//	cout << "Vi tri chen: "; cin >> viTriChen;
//	while(viTriChen < 1 || viTriChen > size(L)){
//		cout << "Vi tri khong hop le! Nhap lai" << endl;
//		cout << "Vi tri chen: "; cin >> viTriChen;
//	}
//	chenK(L, viTriChen);
//	cout << "Danh sach sau khi chen: " << endl;
//	hienThiDS(L);
	
//	thayThe(L, sv);
//	cout << "Danh sach sau khi thay: " << endl;
//	hienThiDS(L);

//	string ten;
//	cout << "Ten can dem: "; cin.ignore(); getline(cin, ten);
//	cout << "So sv ten " << ten << ": " << demTen(L, ten) << endl;

//	selectionSort(L);
//	cout << "Danh sach sau khi sap xep: " << endl;
//	hienThiDS(L);

//	timTen(L);
	
//	xoaNam(L);
//	cout << "Danh sach sau khi xoa nam: " << endl;
//	hienThiDS(L);

//	xoaMin(L);
//	cout << "Danh sach sau khi xoa min: " << endl;
//	hienThiDS(L);

//	xoaMax(L);
//	cout << "Danh sach sau khi xoa max: " << endl;
//	hienThiDS(L);

//	diemMax(L);

	diemLon3(L);
	
	return 0;
}





