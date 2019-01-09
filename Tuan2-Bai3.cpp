#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
struct De 
{
	string cauhoi, traloi;
	string a, b, c, d;
};
int n;

void Doccauhoi();
void Xuatcauhoi();
bool KiemTra(De &q);
void Chon();
void Doccauhoi(ifstream &f,De dsDe[]) //doc danh sach bo de tu file
{
	f>>n;
	string tam;
	getline(f, tam);
	for (int i=0; i<n; i++)
	{
		getline(f, dsDe[i].cauhoi);
		getline(f, dsDe[i].a);
		getline(f, dsDe[i].b);
		getline(f, dsDe[i].c);
		getline(f, dsDe[i].d);
		getline(f, dsDe[i].traloi);
	}
}
bool KiemTra(De &p) //ham kiem tra dap an
{
	int diem=0;
	string chon;
	cout << "Moi ban nhap dap an: ";
	cin>>chon;
	if(chon == p.traloi) //xet truong hop dap an nhap vao co dung voi cau tra loi cua bo de khong
		return true;
	else
		return false;
}
void Xuatcauhoi(De dsDe[]) //in ra man hinh cac cau hoi va hien diem nguoi choi dat duoc
{
	int diem=0;
	for(int i=0;i<n;i++)
	{
		cout<<dsDe[i].cauhoi<<endl;
		cout<<dsDe[i].a<<endl;
		cout<<dsDe[i].b<<endl;
		cout<<dsDe[i].c<<endl;
		cout<<dsDe[i].d<<endl;
		if (KiemTra(dsDe[i])==true)
		{
			cout << "TL dung !"<<endl;
			diem++;
		}
		else 
		{
			cout <<"TL Sai !"<<endl;
			cout <<"Dap an dung la "<<dsDe[i].traloi<<endl;
		}
	}
	cout <<"So diem ban dat duoc la:"<<diem<<endl;
	//ghi vao file
	ofstream l;
	l.clear();
	l.open("kq.txt", ios::app);
	l<<"So diem nguoi choi dat duoc la:"<<diem<<endl;
}
void menu()
{
	cout << "Nhap 1 de mo Bo de 1"<<endl;
	cout << "Nhap 2 de mo Bo de 2"<<endl;
	cout << "Nhap 3 de mo Bo de 3"<<endl;
	cout << "Nhap bat ki khac 1, 2, 3 de thoat!"<<endl;
}

void menu(De dsDe[]) //cac chuc nang
{
	ifstream f;
	int k; //bien lua chon
	do
	{
		system("cls"); //xoa man hinh
		cout<<"\t**********Tro choi thi do trac nghiem************"<<endl;
		cout<<"\t1.Nhap 1 de mo Bo de 1:"<<endl;
		cout<<"\t2.Nhap 2 de mo Bo de 2:"<<endl;
		cout<<"\t3.Nhap 3 de mo Bo de 3:"<<endl;
		cout<<"\t4.Nhap bat ki khac 1, 2, 3 de thoat!"<<endl;
		cout<< "Moi chon de: ";
		cin>>k;
		switch (k)
		{
			case 1:
				system("cls");
				f.open("1.txt", ios::in);
				Doccauhoi(f, dsDe);
				Xuatcauhoi(dsDe);
				system("pause"); //dung man hinh de hien thi so dap an dung
				menu(dsDe);
				break;
			case 2:
				system("cls");
				f.open("2.txt", ios::in);
				Doccauhoi(f, dsDe);
				Xuatcauhoi(dsDe);
				system("pause");
				menu(dsDe);
				break;
			case 3: 
				system("cls");
				f.open("3.txt", ios::in);
				Doccauhoi(f, dsDe);
				Xuatcauhoi(dsDe);
				system("pause");
				menu(dsDe);
				break;
			case 4:
				exit(0);
				break;
		}
	}while(k!=0);	
}

int main () //ham chinh
{
	De dsDe[200];
	menu(dsDe);
}
