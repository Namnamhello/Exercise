#include <bits/stdc++.h>

using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};
struct SinhVien{
	char maSV[8];
	char hoTen[50];
	char gioiTinh[10];
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};
struct Node
{
	SinhVien data;
	Node *link;
};
struct List
{
 	Node *first;
	Node *last;
};

Node* createNode(SinhVien sv){
	Node *p=new Node;
	p->data=sv;
	p->link= nullptr;
	return p;
}

void themsinhvien(List &list, SinhVien sv){
	Node *p= createNode(sv);
	
	if(list.first== nullptr){
		list.first=list.last=p;
	}
	else {
		Node *truoc = nullptr,*hientai= list.first;
		while (hientai!= nullptr&& strcmp(hientai->data.maSV,sv.maSV)<0){
			truoc=hientai;
			hientai= hientai->link;
		}
		if(truoc==nullptr){
			p->link=list.first;
			list.first=p;
		}
		else{
			p->link=hientai;
			truoc->link=p;
			if(hientai==nullptr){
				list.last=p;
			}
		}
	}
}

void nhapsinhvien(SinhVien &sv){
	cout<<"Nhap ma sinh vien: ";cin>>sv.maSV;cin.ignore();	
	cout<<"Nhap ho va ten: ";cin.getline(sv.hoTen,50);cin.ignore();	
	cout<<"Nhap gioi tinh: "; cin.getline(sv.gioiTinh,10);cin.ignore();
	cout<<"Nhap ngay thang nam sinh: ";cin>>sv.ngaySinh.ngay>>sv.ngaySinh.thang>>sv.ngaySinh.nam;
	cout<<"Nhap dia chi: "; cin.getline(sv.diaChi,100);cin.ignore();
	cout<<"Nhap lop: ";cin.getline(sv.lop,12);cin.ignore();
	cout<<"Nhap khoa: ";cin.getline(sv.khoa,7);cin.ignore();
}

void Insinhvien(SinhVien sv){
	cout<<"Ma sinh vien: "<<sv.maSV<<"\n";
	cout<<"Ho va ten: "<<sv.hoTen<<"\n";
	cout<<"Gioi tinh: "<<sv.gioiTinh<<"\n";
	cout<<"Ngay sinh: "<<sv.ngaySinh.ngay<<"/"<<sv.ngaySinh.thang<<"/"<<sv.ngaySinh.nam<<"\n";
	cout<<"Lop: "<<sv.lop<<"\n";
	cout << "Khoa: "<<sv.khoa <<"\n";
}
void xuatdanhsach(List list) {
    Node *p = list.first;
    while (p != nullptr) {
        Insinhvien(p->data);
        cout << "\n";
        p = p->link;
    }
}
int main(){
	List list;
	int n;
	cout<<"Nhap so luong sv:";
	cin>>n;
	for(int i=0;i<n;i++){
		SinhVien sv;
		nhapsinhvien(sv);
		themsinhvien(list, sv);
	}
	cout<<"Danh sach sau khi sap xep: \n";
	xuatdanhsach(list);
}