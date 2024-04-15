#include<bits\stdc++.h>
using namespace std;

struct SinhVien{
	char maSV[10];
	char hoTen[50];
	char gioiTinh[5];
	int namSinh;
	double diemTK;
};

struct Node{
	SinhVien infor;
	Node *next;
};

typedef Node *TRO;

// khoi tao ds rong
void create(TRO &L){
	L = NULL;
}

// kiem tra ds rong
int empty(TRO L){
	return L == NULL;
}

// nhap thong tin sinh vien
SinhVien taoSV(const char maSV[10], const char hoTen[50], const char gioiTinh[5], int namSinh, double diemTK){
	SinhVien sv;
	strcpy(sv.maSV, maSV);
	strcpy(sv.hoTen, hoTen);
	strcpy(sv.gioiTinh, gioiTinh);
	sv.namSinh = namSinh;
	sv.diemTK = diemTK;
	return sv; // tra ve gia tri cua sinh vien
}

//them 1 sinh vien vao cuoi ds
void add(TRO &L, SinhVien sv){
	TRO P, Q;
	P = new Node;
	P->infor = sv;
	P->next = NULL;
	if(empty(L)) L = P;
	else{
		Q = L;
		while(Q->next != NULL){
			Q = Q->next;
		}
		Q->next = P;
	}
}

// them sinh vien vao danh sach
void creatList(TRO &L){
	add(L, taoSV("SV1001", "Tran Van Thanh", "Nam", 1999, 7.5));
	add(L, taoSV("SV1002", "Nguyen Thi Huong", "Nu", 2000, 7.3));
	add(L, taoSV("SV1003", "Nguyen Van Binh", "Nam", 1998, 6.4));
	add(L, taoSV("SV1004", "Bui Thi Hong", "Nu", 1998, 5.8));
	add(L, taoSV("SV1005", "Duong Van Giang", "Nam", 1999, 8.3));
}

// hien thi sinh vien
void display(SinhVien sv){
	cout << setw(5) << sv.maSV;
	cout << setw(20) << sv.hoTen;
	cout << setw(10) << sv.gioiTinh;
	cout << setw(15) << sv.namSinh;
	cout << setw(18) << sv.diemTK << endl;
}

// hien thi danh sach
void show(TRO L){
	TRO Q;
	if(!empty(L)) {
		cout << setw(5) << "Ma SV";
		cout << setw(18) << "Ho Ten";
		cout << setw(15) << "Gioi Tinh";
		cout << setw(15) << "Nam Sinh";
		cout << setw(18) << "Diem TK" << endl;
		
		Q = L;
		while(Q != NULL){
			display(Q->infor);
			Q = Q->next;
		}
	}
	else {
		cout << "Danh sach rong!";	
		return;
	}
	cout << endl;
}

void firstDelete(TRO &L){
	if(empty(L)){
		cout << "Danh sach rong!";
		return;
	}
	TRO Q;
	Q = L;
	L =  L->next;
	delete Q;
	
	cout << "------------------DANH SACH SAU KHI XOA--------------" << endl;
	show(L);
}

// tim vi tri k - 1, Q tro vao node nay
TRO search(TRO L, int k){
	TRO Q = L;
	int count = 1; // dem sl phan tu trong ds
	while(Q != NULL && count < k - 1){
		count++;
		Q = Q->next;
	}
	// danh sach it hon k - 1 phan tu
	if(count < k - 1){
		return NULL;
	}
	return Q;
}

void insert(TRO &L, TRO Q, SinhVien sv){
	TRO P;
	P = new Node;
	P->infor = sv;
	// ghep node
	P->next = Q->next;
	Q->next = P;
}

void chenViTriThu3(TRO &L){
	TRO Q = search(L, 3);
	if(Q == NULL){
		cout << "Chen khong thanh cong!";
	}
	else{
		insert(L, Q, taoSV("SV1006", "Le Thi Doan", "Nu", 1998, 7.6));
		cout << "------------------DANH SACH SAU KHI THEM---------------" << endl;
		show(L);
	}
}

void sapXepTang(TRO &L){
	TRO P, Q, M;
	// P = i , Q = j, M = min
	P = L;
	while(P->next != NULL){
		M = P;
		Q = P->next; // j = i+1
		while(Q != NULL){
			if(strcmp(Q->infor.hoTen, M->infor.hoTen) < 0){
				M = Q;
			}
			Q = Q->next; // j++
		}
		if(M != P){ // m != i
			SinhVien tmp = P->infor;
			P->infor = M->infor;
			M->infor = tmp;
		}
		P = P->next; // i++ cua vong for 1
	}
	cout << "----------------DANH SACH SAU KHI SAP XEP-----------------" << endl;
	show(L);
} 

int main(){
	TRO L;
	create(L);
	creatList(L);
	cout << "-------------------DANH SACH SINH VIEN------------------" << endl;
	show(L);
	
	//xoa
	firstDelete(L);
	
	//them
	chenViTriThu3(L);
	
	//sap xep
	sapXepTang(L);
	
	return 0;
}
