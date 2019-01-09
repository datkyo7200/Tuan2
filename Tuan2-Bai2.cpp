#include<iostream>
#include<string>
#include<conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdbool.h>
#include<stdlib.h>
using namespace std;
int n,a;

struct Nhanvien
{
	int Tuoi, Manv, Luongcoban;
	string Hoten;
};

typedef struct Nhanvien nv;

void Nhap();
void NhapDSNV();
void Xuat();
void XuatDSNV();
void KiemTra();
void XoaNV();
void CapNhat();
void TimKiem();
void Ghifile();
void Menu();
void Chon();
void DocDS(ifstream &f,vector<Nhanvien> &dsnv);
void GhiDS(ofstream &f,vector<Nhanvien> &dsnv);
void TimNV(vector<Nhanvien> &DSNV);

void Nhap(Nhanvien &nv)
{
	cout<<"Ma: ";
	cin>>nv.Manv;
	cout<<"Ho ten: ";
	cin.ignore();
	getline(cin,nv.Hoten);
	cout<<"Tuoi: ";
	cin>>nv.Tuoi;
	cout<<"Luong: ";
	cin>>nv.Luongcoban;
}
void Xuat(Nhanvien &nv)
{
	cout <<nv.Manv<<"\t"<<nv.Hoten<<"\t\t"<<nv.Tuoi<<"\t"<<nv.Luongcoban<<endl;
}
//Nhap danh sach nhan vien
void NhapDSNV(vector<nv> &ds)
{	
	cout<<"Nhap vao so luong nhan vien: ";
	cin>>n;
	ds.resize(n); // tinh toan kich thuoc cua danh sach
	for(int i=0;i<ds.size();i++)  // cho vong lap chay tu dau toi cuoi danh sach
	{
		Nhap(ds[i]);
	}
}
//Xuat danh sach nhan vien
void XuatDSNV(vector<nv> &ds)
{	
	cout << "---------------------------"<<endl;
	cout << "Danh sach nhan vien hien co."<<endl;
	for(int i=0;i<ds.size();i++)
	{
		Xuat(ds[i]);
	}
}

int  KiemTra(vector<nv> ds, int manv) 
{	
	for(int i=0;i<ds.size();i++)
	{
		if(ds[i].Manv==manv)
		return i;
	}
	return -1;
}

void ThemNV(vector<nv> &ds)
{
	Nhanvien nv;
	Nhap(nv);
	if(KiemTra(ds,nv.Manv)==-1)//Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		ds.push_back(nv); 
	}
	else 
		cout<<"Ma nhan vien da ton tai"<<endl;
}

//kiem tra dieu kien va xoa nhan vien
void XoaNV(vector <nv> &ds)
{	
	int x, nvid;
	Nhanvien nv;
	cout<<"Nhap ma nhan vien can xoa:";
	cin>>nvid;
	if(KiemTra(ds,nvid)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien khong ton tai"<<endl;
	}
	else 
	{	
		x=KiemTra(ds,nvid);
		ds.erase(ds.begin()+x); // xoa phan tu tai vi tri x
	}
}
void CapNhat(vector <nv> &ds)
{	
	Nhanvien nv;
	int nvid, x;
	cout<<"Nhap ma nhan vien can cap nhat: ";
	cin>>nvid;
	if(KiemTra(ds,nvid)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Khong tim thay nhan vien co ma nay."<<endl;
	}
	else 
	{	
		x=KiemTra(ds,nvid);
		cout<<"Ho ten:";
		cin.ignore();
		getline(cin,nv.Hoten); // nhan khoang trang 
		cout<<"Tuoi: ";
		cin>>nv.Tuoi;
		cout<<"Luong:";
		cin>>nv.Luongcoban;
		ds[x].Hoten=nv.Hoten; 
		ds[x].Tuoi=nv.Tuoi;
		ds[x].Luongcoban=nv.Luongcoban;
	}
}
// kiem tra dieu kien roi  sau do tim
void TimKiem(vector <nv> ds)
{
	Nhanvien nv;
	int nvid,x;
	cout<<"Nhap ma nhan vien can tim: ";
	cin>>nvid;
	if(KiemTra(ds,nvid)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien vua nhap khong ton tai."<<endl;
	}
	else 
	{
		x=KiemTra(ds,nvid);
		cout<<"============================"<<endl;
		cout<<"Thong tin nhap vien can tim: "<<endl;
		Xuat(ds[x]);
	}
}
void Ghifile(ofstream &outfile,Nhanvien &nv)
{
	//ghi vao file du lieu 1 nhan vien
	outfile<<nv.Manv<<endl;
	outfile<<nv.Hoten<<endl;
	outfile<<nv.Tuoi<<endl;
	outfile<<nv.Luongcoban<<endl;
}
void Docfile(ifstream &infile,Nhanvien &nv)
{
	//doc tu file du lieu 1 nhan vien
	infile>>nv.Manv;
	string temp;	
	getline(infile,temp);
	getline(infile,nv.Hoten);
	infile>>nv.Tuoi;
	infile>>nv.Luongcoban;
}
void DocDS(ifstream &f,vector<Nhanvien> &dsnv)
{
	//doc tu file danh sach nhan vien.
	int n;
	f>>n;
	dsnv.resize(n);
	for(int i = 0; i< dsnv.size(); i++)
	{
		Docfile(f,dsnv[i]);
	}
}
void GhiDS(ofstream &f,vector<Nhanvien> &dsnv)
{
	//ghi vao file danh sach nhan vien
	f << dsnv.size()<<endl;
	for(int i = 0; i<dsnv.size();i++)
	{
		Ghifile(f,dsnv[i]);
	}
}

void ShowMenu(){
	cout<<"Phan Thanh Dat 58131284\n\n\n";
	cout << "1: Them 1 nhan vien." << endl;
	cout << "2: Xoa 1 nhan vien theo ma nhan vien." << endl;
	cout << "3: Sua 1 nhan vien theo ma nhan vien." << endl;
	cout << "4: Tim kiem thong tin 1 nhan vien theo ma." << endl;
	cout << "5: In danh sach nhan vien." << endl;
	cout << "6: Ghi danh sach vao file."<<endl;
	cout << "7: EXIT"<<endl;
 }
 
int ChonMenu()
{
	int n=0;
	cout<<"\n\nHay nhan chon yeu cau:";
	cin>>n;
	if(n > 0 || n < 6) return n;
		else return ChonMenu();
}
void LuaChon(vector <nv> ds)
{	
	ShowMenu();
	int select ;
	cout<<"Nhap vao lua chon cua ban: ";
	cin>>select;
	switch(select)
	{					
		case 1: 
			cout<<"Nhap thong tin nhan vien can them. "<<endl;
//			cin.ignore(); // xoa bo nho dem.
			ThemNV(ds);
			XuatDSNV(ds);
			LuaChon(ds);
			break;
		case 2 :
		     XoaNV(ds);
			XuatDSNV(ds);
			LuaChon(ds);
			break;
		case 3:	
			CapNhat(ds);
			XuatDSNV(ds);
			LuaChon(ds);	
			break;
		case 4:
			TimKiem(ds);
			LuaChon(ds);	
			break;
		case 5:
			//Ghifile(ds);
			cout<<"Da ghi du lieu vao file!"<<endl;
			LuaChon(ds);
			break;
		case 6:
			exit(0);
			break;
		default:
			cout<<"Moi ban nhap lai (1=>6): "<<endl;
			LuaChon(ds);
	}	
}
void ShowMenu();		
void LuaChon();	
int ChonMenu(); 
int main()
{   
	vector <nv> employee;
	NhapDSNV(employee);
	LuaChon(employee);
		getch();
}

