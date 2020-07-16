#include <algorithm>
#include<iostream>
#include<windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

struct Node{
	string Hoten;
	string Malop;
	string Masv;
	float DiemTB;
	int ngay;
	int thang;
	int nam;
	Node*next;
	Node*prev;
};
struct sv{
	string Hoten;
	string Malop;
	string Masv;
	float DiemTB;
	int ngay;
	int thang;
	int nam;
};
struct List {
    Node*head;
    Node*tail;
};
Node*creatNode(string Malop, string Masv, string Hoten, int ngay, int thang, int nam, float DiemTB) {
    Node*p = new Node; //ham cap phat bo nho;
    if (p == NULL) exit(1); // k dc cap phat thi thoat;
    else {

        p->Malop = Malop;
        p->Masv = Masv;
        p->Hoten = Hoten;
        p->ngay = ngay;
        p->thang = thang;
        p->nam = nam;
        p->DiemTB = DiemTB;
        p->next = NULL;
		p->prev = NULL;
        return p; //kieu ham la ham con tro nen phai tra ve con tro
    }
}
void CursorStatus(unsigned size, WINBOOL stt) {
    CONSOLE_CURSOR_INFO crs_inf = {size, stt};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &crs_inf);
}
//Cac thao tac voi List
void addHead(List &l, string Malop, string Masv, string Hoten, int ngay, int thang, int nam, float DiemTB);//chen vao dau danh sach lien ket
void addTail(List &l, string MaLop, string MSV, string Name, int day, int month, int year, float DiemTB);//chen vao cuoi danh sach lien ket
int lenghtNode(List &l);//do dai cu ds
void delList(List &l);//xoa list
void Init(List &l);
bool isEmpty(List l);
void swap(Node *a, Node *b);

//sort loai 1 : Selection sort
//sort loai 2 : Bubble sort
//sort loai 3 : Insertion sort
//sort loai 4 : Quick sort 
//Cac ham sort MSV
void sortMSV1(List &l);
void sortMSV2(List &l);
void sortMSV3(List &l);
void sortMSV4(List &l);
//Cac ham sort Malop
void sortMaLop1(List &l);
void sortMaLop2(List &l);
void sortMaLop3(List &l);
void sortMaLop4(List &l);

bool DateCompare(Node* n1, Node*n2);
//Cac ham sort Date
void sortDate1(List &l);
void sortDate2(List &l);
void sortDate3(List &l);
void sortDate4(List &l);
//Cac ham sort DTB
void sortMark1(List &l);
void sortMark2(List &l);
void sortMark3(List &l);
void sortMark4(List &l);

bool NameCompare(Node*n1, Node*n2) ;
//Cac ham sort Name
void sortName1(List &l);
void sortName2(List &l);
void sortName3(List &l);
void sortName4(List &l);

//cac ham khung menu va menu
void MakeSaveMenu();
void SaveMenu(List &l);
void MakeNewMenu1();
void MainMenu(List &l,int pos);//Menu chinh
void NewMenu1(List &l);//Menu chon nhap du lieu tu ban phim
void MakeSortMenu();
void SortMenu(List &l,int k);
void MakeNewFileMenuChoise();//Ki tu menu chon cach nhap du lieu
void NewFileChoise(List &l);//Menu chon cach chon
void MakeErrorFileMenu();
void ErrorFileMenu(List &l);//Menu chon neu file nhap du lieu bi loi
void MakeOverWriteDataMenu();
void OverWriteDataMenu(List &l);//Menu chon ghi de du lieu hay ghi tiep
void MakeSortMenu1(List &l);
void SortMenu1();
void MakeMainMenu(); //Viet Ki tu cua Menu
void MakeBorder(); //Ham tao Khung menu chinh
void MakeBorder2(int lenght);//khung cua IN Man Hinh
void MakeFindMenu();
void FindMenu(List &l);
void MakeFindMenu1();
void FindMenu1(List &l);
void MakeFindMenu2();
void FindMenu2(List &l,int k);
void MakeBorder3(int lenght) ;
void MenuThongKe(List &l);

//cac thao tac tren man hinh
void XoaManHinh();//xoa man hinh ben Menu 2
void Deleteline(int x, int y,int z);//xoa dong
void TextColor(int x);//Ham tao mau
void gotoxy(int x, int y);

//nhap xuat du lieu
float Into_Float(string s);//chuyen du lieu tu string thanh float
void InputFromFile(List &l);//nhap du lieu tu file
void OutputFile(List &l);//xuat du lieu ra file
void OutputConsole(List l);//xuat du lieu ra man hinh
void OutputConsole2(List l);//xuat du lieu 1 danh sach

bool isSameString(string s1, string s2);//so sanh 2 string

//Tim kiem
bool searchDate1(Node*p, int ngay, int thang, int nam);
bool searchDate2(Node*p, int ngay, int thang, int nam);
bool searchDate3(Node*p, int ngay, int thang, int nam);
bool searchDiemTB(Node*p, float DiemTB);
bool searchMSV(Node*p, string key);
bool searchML(Node*p, string key);
bool searchName(Node*p, string key);

bool KiemtraDate(int ngay, int thang, int nam);//Kiem tra tinh dung dan cua ngay sinh
void ChuanHoa(string *s);//chuan hoa ho ten
int ChuanHoa2(string s);//chuan hoa du lieu thanh so nguyen
void ChuanHoa3(string *s);//chuan hoa ma lop
int main(){
	List sv;
	Init(sv);
	MakeMainMenu();
	
	
	MainMenu(sv,1);
}
void Init(List &l) {
    l.head = l.tail = NULL;
}

bool isEmpty(List l) {
    if (l.head == NULL) return true;
    return false;
}
void delList(List &l) {
    while (l.head != NULL) {
        Node*p = l.head;
        l.head = l.head->next;
        delete p;
    }
}
int lenghtNode(List &l) {
    Node*p = l.head;
    int lenght = 0;
    while (p != NULL) {
        lenght++;
        p = p->next;
    }
    return lenght;
}
void addHead(List &l, string Malop, string Masv, string Hoten, int ngay, int thang, int nam, float DiemTB) {
    Node*p = creatNode(Malop, Masv, Hoten, ngay, thang, nam, DiemTB);
    if (isEmpty(l)){
    p->next=p->prev=NULL;
	l.head = l.tail = p;
	}
    else {
    	p->prev=NULL;
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)
		l.head->prev = p;
        l.head = p; //cap nhat head (lucsau);
    }
}
void addHead(List &l, Node*p) {
    if (isEmpty(l)){
    p->next=p->prev=NULL;
	l.head = l.tail = p;
	}
    else {
    	p->prev=NULL;
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)
		l.head->prev=p;
        l.head = p; //cap nhat head (lucsau);
    }
}
void addTail(List &l, string MaLop, string MSV, string Name, int day, int month, int year, float DiemTB) {
    Node*p = creatNode(MaLop, MSV, Name, day, month, year, DiemTB);
    if (isEmpty(l)) addHead(l, MaLop, MSV, Name, day, month, year, DiemTB);
    else {
    	
        l.tail->next = p; //tro thuan
        p->next=NULL;
		l.tail->prev = l.tail;
	    l.tail = p; //cap nhat tail
    }
}
void XoaManHinh() {
    for (int i = 26; i < 80; i++) {
        for (int j = 2; j < 25; j++) {
            gotoxy(i, j);
            cout << " ";
        }
    } 
}
void ChuanHoa3(string *s) {
    for (int i = 0; i < s->length(); i++) {// dua xau ve ki tu thuong
        if (s->at(i) >= 97 and s->at(i) <= 122) s->at(i) = s->at(i) - 32;
    }
}
int ChuanHoa2(string s) {
   
   if (s.size() == 0 || (s.c_str()[0] < 48 || s.c_str()[0] > 57)) return -1;
    else return atoi(s.c_str());//Neu chuoi nhap vao khac so xuat -1 nguoc lai xuat du lieu
}
bool KiemtraDate(int ngay, int thang, int nam){
		if(nam < 1900 || nam > 2020) return false;
	switch(thang){
		case 1: 
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if (ngay > 31 || ngay < 1) return false;
                else return true;
                break;
		case 2: if(nam /4 ==0){
		
				if(ngay<1 || ngay > 29) return false;
				else return true;
				}else if(ngay <1 || ngay> 28) return false;
				else return true;
				break;
		case 4:
        case 6:
        case 9:
        case 11:
                if (ngay < 1 || ngay > 30) return false;
                else return true;
                break;
        default: return false;
        	
			
	} 
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
  
}
void Buoisau()
{
	gotoxy(30,2);
	TextColor(15);
	cout<<"Buoi sau";
	gotoxy(30,3);
	TextColor(30);
	cout<<"Back";
	char ch1;
	ch1= getch();
	if(ch1 == 13){
		TextColor(15);
		XoaManHinh();
		}
}

void Deleteline(int x, int y,int z){
	gotoxy(x,y);
	for(int i = 1; i <= z; i++){
		cout<< " ";
	}
	gotoxy(x,y);
}

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void MakeMainMenu() 
{

    TextColor(15);
    gotoxy(1, 1);
    cout << "\n\t *Menu*" << "\n\n\n  1. Them Ho So Moi " << "\n  2. In Danh Dach "
            << "\n  3. Sap Xep " << "\n  4. Tim Kiem " << "\n  5. Thong Ke " << "\n  6. Thoat \n";
    MakeBorder();
}
void MakeBorder() 
{
    TextColor(10);
    for (int i = 2; i < 25; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(80, i);
        printf("%c", 186);
    }
    for (int i = 2; i < 80; i++) {
        gotoxy(i, 1);
        printf("%c", 205);
        gotoxy(i, 25);
        printf("%c", 205);
    }
    for (int i = 2; i < 25; i++) {
        gotoxy(25, i);
        printf("%c", 186);
    }
    gotoxy(1, 1);
    printf("%c", 201);
    gotoxy(80, 1);
    printf("%c", 187);
    gotoxy(1, 25);
    printf("%c", 200);
    gotoxy(80, 25);
    printf("%c", 188);
    gotoxy(25, 1);
    printf("%c", 203);
    gotoxy(25, 25);
    printf("%c", 202);
    gotoxy(5, 25);

}
void NewMenu1(List &l){
	string Hoten;
	string Malop;
	string Masv;
	string DiemTb;
    string ngay, thang, nam;
	int k=5;
	int pos=1;
	int i=lenghtNode(l)+1;
	int n=0;
	char ch;
	TextColor(143);
    Deleteline(46, 5, 30);
    Deleteline(46, 7, 30);
    Deleteline(46, 9, 30);
    Deleteline(46, 11, 30);
    Deleteline(46, 13, 30);
    TextColor(15);
	while(1){
	do {
		TextColor(15);
        Deleteline(60, 2, 5);
        gotoxy(60, 2);
        cout << i ;
		switch(pos){
			case 1: TextColor(15);
					MakeNewMenu1();
					gotoxy(30,5);
					TextColor(20);
					cout << "Ho ten";
					char et1; et1 = getch();
					if (et1 == 13){
						TextColor(143);
                        Deleteline(46, 5, 30);
                        gotoxy(50, 5);
                        
                        CursorStatus(25, TRUE);
                        fflush(stdin);
                        getline(std::cin, Hoten);
                        CursorStatus(25, FALSE);
                       	fflush(stdin);
					    
                        ChuanHoa(&Hoten);
                        
                        Deleteline(46, 5, 30);
                        gotoxy(50, 5);
                        cout << Hoten;
                        
						}
					break;
			case 2: TextColor(15);
					MakeNewMenu1();
					gotoxy(30,7);
					TextColor(20);
					cout<<"Ma lop";
					char et2; et2= getch();
					if(et2 != -32){
					
					if(et2 == 13){
						TextColor(143);
						Deleteline(46, 7, 30);
                        gotoxy(50, 7);
                        CursorStatus(25, TRUE);
                        fflush(stdin);
                    	cin>>Malop;
                    	ChuanHoa3(&Malop);
                    	fflush(stdin);
                    	CursorStatus(25, FALSE);
                    Deleteline(46, 7, 30);
                        gotoxy(50, 7);
					cout<<Malop;
                       
					}
				}
					break;
			case 3: TextColor(15);
					MakeNewMenu1();
					gotoxy(30,9);
					TextColor(20);
					cout<<"Ma sv";
					char et3;
					et3= getch();
					if (et3 == 13){
					do{	TextColor(143);
                        Deleteline(46, 9, 30);
                        gotoxy(50, 9);
                        CursorStatus(25, TRUE);
                        fflush(stdin);
                    	cin>>Masv;
                         
						    if (Masv.length() == 0) gotoxy(46, 9);
                            
                            CursorStatus(25, FALSE);
                            fflush(stdin);
                            if (Masv.length() != 8 || ChuanHoa2(Masv) == -1){//kiem tra tinh dung dan cua MSV
                                Deleteline(46, 9, 30);
                                gotoxy(50, 9);
                                TextColor(140);
                                cout << "MSV gom 8 so";
                                Sleep(500);
                                TextColor(15);
                                continue;
                            }
                        } 
						while (Masv.length() != 8 || ChuanHoa2(Masv) == -1);//cho phep nhap lai MSV
                        Deleteline(46, 9, 30);
                        gotoxy(50, 9);
                        cout << Masv;
                        
                        
                       } 
					break;
			case 4: 
					MakeNewMenu1();
					gotoxy(30,11);
					TextColor(20);
					cout<<"DiemTb";
					char et4;
                    et4 = getch();
                    if (et4 == 13) {
                    	 
                 	 	do{
                            TextColor(143);
                            Deleteline(46, 11, 30);
                            gotoxy(50, 11);
                           
                            CursorStatus(25, TRUE);
                            fflush(stdin);
                            cin>>DiemTb;
                           
                            CursorStatus(25, FALSE);
                            if (Into_Float(DiemTb) == -1) {
                                Deleteline(46, 11, 30);
                                gotoxy(50, 11);
                                TextColor(140);
                                cout << "Nhap Lai";
                                Sleep(300);
                                TextColor(143);
                            }
                        } while (Into_Float(DiemTb) == -1);// cho phep nhap lai diem neu sai
                        
                    }
			
					break;
			case 5: TextColor(15);
					MakeNewMenu1();
					gotoxy(30,13);
					TextColor(20);
					cout<<"Ngay sinh";
					char et5; et5 = getch();
					if(et5 == 13){
						do {
							TextColor(143);
							Deleteline(46, 13, 30);
                            gotoxy(52, 13);
                            cout << "/";
                            gotoxy(55, 13);
                            cout << "/";
                            fflush(stdin);
                            gotoxy(50, 13);
                            CursorStatus(25, TRUE);
                            getline(cin, ngay);
                            CursorStatus(25, FALSE);
                            fflush(stdin);
                            gotoxy(52, 13);
                            cout << "/";
                            CursorStatus(25, TRUE);
                            getline(cin, thang);
                            CursorStatus(25, FALSE);
                            fflush(stdin);
                            gotoxy(55, 13);
                            cout << "/";
                        	
                            getline(cin, nam);
                            if (KiemtraDate(ChuanHoa2(ngay), ChuanHoa2(thang), ChuanHoa2(nam))==false) {
                                TextColor(143);
								Deleteline(46, 13, 30);
                                
                                gotoxy(50, 13);
                                TextColor(140);
                                cout << "nhap sai";
                                TextColor(143);
                                Sleep(300);
                            }
                        } while (KiemtraDate(ChuanHoa2(ngay), ChuanHoa2(thang), ChuanHoa2(nam))==false);// cho phep nhap lai ngay sinh

                        
					}
					break;
			case 6: 
					MakeNewMenu1();
					gotoxy(40,15);
					TextColor(20);
					cout<<"Add";
					TextColor(15);
					char et6;
                    et6 = getch();
                    if (et6 == 13) {
                        
                        gotoxy(40, 15);
                        TextColor(20);
                        cout << " Save!";
                        Sleep(350);
                        TextColor(15);
                        Deleteline(40, 15, 6);
                        gotoxy(40,15);
                        cout<<"Add";
                        Deleteline(60, 2, 10);
                        gotoxy(60, 2);
                        i++;
                        
                        addTail(l, Malop, Masv, Hoten, ChuanHoa2(ngay), ChuanHoa2(thang), ChuanHoa2(nam), Into_Float(DiemTb));//dua du lieu vao list
                        TextColor(143);
                        Deleteline(46, 5, 30);
                        Deleteline(46, 7, 30);
                        Deleteline(46, 9, 30);
                       	Deleteline(46, 11, 30);
                        Deleteline(46, 13, 30);
                        TextColor(15);
                        
                    }
					break;
			case 7: TextColor(15);
					MakeNewMenu1();
					gotoxy(40,16);
					TextColor(20);
					cout<<"Back";
					char et7; et7 = getch();
					if(et7 == 13){
					TextColor(15);
					MainMenu(l,1);
					}
					break;
			}
			
		ch=getch();
		if(ch == -32||ch == 72 || ch == 80){
		if(ch == 72 || ch == 80){
		
			if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 7;//dieu khien len
			if (ch == 80 && pos < 7) pos++;
			else if (ch == 80 && pos == 7) pos = 1;//dieu khien xuong
		}else {
		ch=getch();
		if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 7;//dieu khien len
			if (ch == 80 && pos < 7) pos++;
			else if (ch == 80 && pos == 7) pos = 1;//dieu khien xuong
        }
	}
  }while (!(lenghtNode(l) == n || ch == 27));
}XoaManHinh();
NewFileChoise(l);
}
void MakeErrorFileMenu() {
    TextColor(15);
    gotoxy(40, 12);
    cout << "**FILE NOT FOUND!**";
    gotoxy(45, 14);
    cout << " Try other files ";
    gotoxy(47, 16);
    cout << " Back! ";
}

void ErrorFileMenu(List &l) {
    int pos = 1;
    MakeErrorFileMenu();
    char choise;
    do {
        switch (pos) {
            case 1:
                MakeErrorFileMenu();
                gotoxy(45, 14);
                TextColor(172);
                cout << " Try other files ";
                char et1;
                et1 = getch();
                if ((int) et1 == 13) {
                    TextColor(15);
                    XoaManHinh();
                    InputFromFile(l);
                    TextColor(15);
                }
                break;
            case 2:
                MakeErrorFileMenu();
                gotoxy(47, 16);
                TextColor(172);
                cout << " Back! ";
                char et2;
                et2 = getch();
                if ((int) et2 == 13) {
                    TextColor(15);
                    XoaManHinh();
                    NewFileChoise(l);
                }
                break;
        }
       
		choise = getch();
        if(choise == 72 && pos > 1) pos--; else if(choise == 72 && pos == 1) pos =2;
        if(choise == 80 && pos < 2) pos++; else if(choise == 80 && pos == 2) pos =1;
	
    } while (1);
}
void MakeOverWriteDataMenu() {
    TextColor(15);
    gotoxy(38, 12);
    cout << "** Muon ghi de danh sach ?**";
    gotoxy(45, 14);
    cout << " Ghi de ";
    gotoxy(43, 16);
    cout << " Ghi vao cuoi ";
}

void OverWriteDataMenu(List &l) {
    int pos = 1;
    MakeOverWriteDataMenu();
    char choise;
    do {
        switch (pos) {
            case 1:
                MakeOverWriteDataMenu();
                gotoxy(45, 14);
                TextColor(150);
                cout << " Ghi de ";
                char et1;
                et1 = getch();
                if ((int) et1 == 13) {
                    TextColor(15);
                    XoaManHinh();
                    delList(l);
                    NewFileChoise(l);
                    TextColor(15);
                }
                break;
            case 2:
                MakeOverWriteDataMenu();
                gotoxy(43, 16);
                TextColor(150);
                cout << " Ghi vao cuoi ";
                char et2;
                et2 = getch();
                if ((int) et2 == 13) {
                    TextColor(15);
                    XoaManHinh();
                    NewFileChoise(l);
                }
                break;
        }
       
		choise = getch();
        if(choise == 72 && pos > 1) pos--; else if(choise == 72 && pos == 1) pos =2;
        if(choise == 80 && pos < 2) pos++; else if(choise == 80 && pos == 2) pos =1;
	

    } while (1);
}
void MakeNewFileMenuChoise() {
    TextColor(15);
    gotoxy(32, 6);
    cout << "Nhap DL Tu File      ";
    gotoxy(32, 9);
    cout << "Nhap DL Tu Ban Phim ";
    gotoxy(36, 12);
    cout << "Back!";
}
void NewFileChoise(List &l) {
    int pos = 1;
    MakeNewFileMenuChoise();
    char choise;

    do {

        switch (pos) {
            case 1: MakeNewFileMenuChoise();
                gotoxy(32, 6);
                TextColor(172);
                cout << "Nhap DL Tu File     ";

                if (getch() == 13) {
                    TextColor(15);
                    XoaManHinh();
                    InputFromFile(l);
                    MakeNewFileMenuChoise();
                    TextColor(15);

                }
                TextColor(15);
                break;
            case 2: MakeNewFileMenuChoise();
                gotoxy(32, 9);
                TextColor(172);
                cout << "Nhap DL Tu Ban Phim";
                char et2;
                et2 = getch();
                if (int(et2) == 13) {
                    TextColor(15);
                    XoaManHinh();
                    MakeNewMenu1();
                    NewMenu1(l);
                    XoaManHinh();
                    MakeNewFileMenuChoise();
                }
                TextColor(15);
                break;
            case 3: MakeNewFileMenuChoise();
                gotoxy(36, 12);
                TextColor(172);
                cout << "Back!";
                char et3;
                et3 = getch();
                if (int(et3) == 13) {
                    TextColor(15);
                    system("cls");
                    MainMenu(l,1);
                    fflush(stdin);
                }
                break;


        }
		
		
        choise = getch();
        if(choise == 72 && pos > 1) pos--; else if(choise == 72 && pos == 1) pos =3;
        if(choise == 80 && pos < 3) pos++; else if(choise == 80 && pos == 3) pos =1;
		
    } while (1);

}

void MakeNewMenu1()
{	TextColor(15);
	gotoxy(45,2); 
	cout<<"Sinh vien thu: ";
	gotoxy(30,5);
	cout<<"Ho ten   :";
	gotoxy(30,7);
	cout<<"Ma lop   :";
	gotoxy(30,9); 
	cout<<"Ma sv    :";
	gotoxy(30,11);
	cout<<"DiemTb   :";
	gotoxy(30,13);
	cout<<"Ngay sinh:";
	gotoxy(40,15); cout<<"Add";
	gotoxy(40,16); cout<<"Back";
	gotoxy(35,20); cout<<"Press Enter to continue";
}
void OutputConsole2(List l) {
    CursorStatus(25, FALSE);

    TextColor(15);
    system("cls");
    MakeBorder3(lenghtNode(l));
    Node *p = l.head;
	int i=5;
    
   while (p != NULL) {
        TextColor(10);
		gotoxy(3, i);
        cout << p->Hoten;
       
        gotoxy(32, i);
        cout << p->Malop;
        gotoxy(46, i);
        cout << p->Masv;
        gotoxy(60, i);
        cout << p->ngay << "/" << p->thang << "/" << p->nam;
        gotoxy(77, i);
        cout << p->DiemTB;		
		
        p = p->next;
       	i++;
        }
        
}
void OutputConsole(List l) {
    CursorStatus(25, FALSE);

    TextColor(15);
    system("cls");
    MakeBorder2(6);
    Node *p = l.head;
	
	Node *k,*i,*j,*x,*y,*z;
		i=j=x=y=z=k=NULL;
	int v;
    int m=5;
   while (p != NULL) {
        TextColor(10);
		gotoxy(3, m);
        cout << p->Hoten;
       
        gotoxy(32, m);
        cout << p->Malop;
        gotoxy(46, m);
        cout << p->Masv;
        gotoxy(60, m);
        cout << p->ngay << "/" << p->thang << "/" << p->nam;
        gotoxy(77, m);
        cout << p->DiemTB;
		m++;
		p=p->next;
		if(m>=10){
		m=5;
		char c; c =getch();
		if(c == 27){
			MainMenu(l,1);
		}
		if(c == 13){
			system("cls");
            SaveMenu(l);
		}
		if(c==-32){
		c=getch();
		if(c == 77){
			if(k !=p){
			
		z=y; y=x; x=j;j=i;i=k;
		k=p;
		}
       
       
        if(p==NULL){
        	p=k;
        	v=1;
		}
		 system("cls");
        MakeBorder2(6);
        }
        if(c == 75){
        	if(k==NULL){
        		p=l.head;
			}
        	if(k!=NULL){
			if(v == 1){
				p=i;
			}else
			p =k ;
		
        	if(i != NULL){
        		k=i;
			}
			if(j != NULL){
				i=j;
			}
			if(x != NULL){
				j=x;
			}
			if(y != NULL){
				x=y;
			}
			if(z != NULL){
				y=z;
			}
        	system("cls");
            MakeBorder2(6);
        }
    }
        	
		}
		
      }
      	
    }



}
void InputFromFile(List &l) {
    fstream InFile;
    string f;
   
    Node *p;
    int n;
    int i = 0;
   

    do {
        gotoxy(32, 10);
        cout << "File Name: ";
        TextColor(252);
        Deleteline(44, 10, 30);
        gotoxy(45, 10);
        CursorStatus(25, TRUE);
        fflush(stdin);
        getline(cin, f);
        CursorStatus(25, FALSE);

        TextColor(15);
        InFile.open(f.c_str(), ios::in);
        if (!InFile.is_open()) {
            TextColor(15);
            XoaManHinh();
            ErrorFileMenu(l);
        } else {
            
            Deleteline(32, 10, 45);
            gotoxy(35, 10);
            cout << "Du lieu dang duoc nhap";
            Sleep(350);
            while (!InFile.eof()) {
                
                string Malop = " ";
                string Masv = " ";
                string Hoten = " ";
                int ngay = 0;
                int thang = 0;
                int nam = 0;
                float DiemTB = 0;

               
               	InFile>>Malop;
                ChuanHoa3(&Malop);
                InFile.ignore();
                InFile>>Masv;
                InFile.ignore();
                getline(InFile, Hoten);
                ChuanHoa(&Hoten);
                InFile>>ngay;
                InFile>>thang;
                InFile>>nam;
                InFile>>DiemTB;

                if (Masv != " " || Malop != " ") addTail(l, Malop, Masv, Hoten, ngay, thang, nam, DiemTB);
                
            }
            Deleteline(32, 10, 45);
            gotoxy(35, 10);
            cout << "Enter to continue!";
            Sleep(300);
            XoaManHinh();
            
        }
    } while (!InFile.is_open());
   
    NewFileChoise(l);

    InFile.close();
}
void MakeBorder2(int lenght) {
   
    TextColor(9);

    int pos_y = 6;

    for (int i = 2; i < lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(30, i);
        printf("%c", 186);
        gotoxy(45, i);
        printf("%c", 186);
        gotoxy(55, i);
        printf("%c", 186);
        gotoxy(75, i);
        printf("%c", 186);
        gotoxy(80, i);
        printf("%c", 186);
    }

    for (int i = 2; i < 80; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
        gotoxy(i, 4);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y);
        printf("%c", 205);
    }
    gotoxy(1, 2);
    printf("%c", 201);
    gotoxy(80, 2);
    printf("%c", 187);
    gotoxy(1, lenght + pos_y);
    printf("%c", 200);
    gotoxy(80, lenght + pos_y);
    printf("%c", 188);
    gotoxy(30, 2);
    printf("%c", 203);
    gotoxy(30, lenght + pos_y);
    printf("%c", 202);
    gotoxy(45, 2);
    printf("%c", 203);
    gotoxy(45, lenght + pos_y);
    printf("%c", 202);
    gotoxy(55, 2);
    printf("%c", 203);
    gotoxy(55, lenght + pos_y);
    printf("%c", 202);
    gotoxy(75, 2);
    printf("%c", 203);
    gotoxy(75, lenght + pos_y);
    printf("%c", 202);

    gotoxy(30, 4);
    printf("%c", 206);
    gotoxy(45, 4);
    printf("%c", 206);
    gotoxy(55, 4);
    printf("%c", 206);
    gotoxy(75, 4);
    printf("%c", 206);


    gotoxy(30, 1);
    TextColor(12);
    cout << "__***IN Danh Sach Sinh Vien***__    ";
    TextColor(14);
    gotoxy(74,1);
    cout << "next ->";
    TextColor(14);
    gotoxy(2,1);
    cout <<"<-preview";
	gotoxy(40,20);
	cout <<"Press Enter to Save";
	gotoxy(40,21);
	cout <<"Press ESC to Exit";
	gotoxy(5,3);	
    TextColor(11);
    cout << " Ho va ten ";
    gotoxy(32, 3);
    cout << " Ma Lop ";
    gotoxy(48, 3);
    cout << " MSV ";
    gotoxy(60, 3);
    cout << " Ngaysinh";
    gotoxy(76, 3);
    cout << "DTB";
    gotoxy(2, 5);
    TextColor(15);
	

}
void MakeBorder3(int lenght) {
   
    TextColor(9);

    int pos_y = 6;

    for (int i = 2; i < lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(30, i);
        printf("%c", 186);
        gotoxy(45, i);
        printf("%c", 186);
        gotoxy(55, i);
        printf("%c", 186);
        gotoxy(75, i);
        printf("%c", 186);
        gotoxy(80, i);
        printf("%c", 186);
    }

    for (int i = 2; i < 80; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
        gotoxy(i, 4);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y);
        printf("%c", 205);
    }
    gotoxy(1, 2);
    printf("%c", 201);
    gotoxy(80, 2);
    printf("%c", 187);
    gotoxy(1, lenght + pos_y);
    printf("%c", 200);
    gotoxy(80, lenght + pos_y);
    printf("%c", 188);
    gotoxy(30, 2);
    printf("%c", 203);
    gotoxy(30, lenght + pos_y);
    printf("%c", 202);
    gotoxy(45, 2);
    printf("%c", 203);
    gotoxy(45, lenght + pos_y);
    printf("%c", 202);
    gotoxy(55, 2);
    printf("%c", 203);
    gotoxy(55, lenght + pos_y);
    printf("%c", 202);
    gotoxy(75, 2);
    printf("%c", 203);
    gotoxy(75, lenght + pos_y);
    printf("%c", 202);

    gotoxy(30, 4);
    printf("%c", 206);
    gotoxy(45, 4);
    printf("%c", 206);
    gotoxy(55, 4);
    printf("%c", 206);
    gotoxy(75, 4);
    printf("%c", 206);


    gotoxy(25, 1);
    TextColor(12);
    cout << "__***IN Danh Sach Sinh Vien***__    ";
    TextColor(14);
    gotoxy(61,1);
    cout <<"Press Enter to Save";
    TextColor(14);
    gotoxy(2,1);
    cout <<"Press ESC to Exit";
	
    TextColor(11);
    gotoxy(5,3);
    cout << " Ho va ten ";
    gotoxy(32, 3);
    cout << " Ma Lop ";
    gotoxy(48, 3);
    cout << " MSV ";
    gotoxy(60, 3);
    cout << " Ngaysinh";
    gotoxy(76, 3);
    cout << "DTB";
    gotoxy(2, 5);
    TextColor(15);
	

}
void OutputFile(List &l) {
    Node *p = l.head;

    fstream outfile;

    string f2Name;
    TextColor(63);
    for (int x = 33; x <= 70; x++) {
        for (int y = 12; y <= 16; y++) {
            gotoxy(x, y);
            cout << " ";
        }

    }
    gotoxy(35, 14);
    cout << "File Name: ";

    do {
        TextColor(126);
        Deleteline(47, 14, 20);
        gotoxy(47, 14);
        CursorStatus(25, TRUE);
        getline(std::cin, f2Name);
        CursorStatus(25, FALSE);
        if (strlen(f2Name.c_str()) == 0) {
            Deleteline(47, 14, 22);
            gotoxy(47, 14);
            TextColor(124);
            cout << "FileName Empty!";
            Sleep(150);

        }
    } while (strlen(f2Name.c_str()) == 0);


    outfile.open(f2Name.c_str(), ios::out);

    

    while (p != NULL) {

        
        if (p->next == NULL) {
            outfile << p->Malop << endl;
            outfile << p->Masv << endl;
            outfile << p->Hoten << endl;
            outfile << p->ngay << " " << p->thang << " " << p->nam << endl;
            outfile << p->DiemTB;
        } else {
            outfile << p->Malop << endl;
            outfile << p->Masv << endl;
            outfile << p->Hoten << endl;
            outfile << p->ngay << " " << p->thang << " " << p->nam << endl;
            outfile << p->DiemTB << "\n";
        }
		
        p = p->next;

       
    }

    
    outfile.close();
    TextColor(15);

}
void MakeSaveMenu() {
    TextColor(15);
    gotoxy(35, 12);
    cout << "**Do you want to save File? **";
    gotoxy(45, 14);
    cout << "  YES  ";
    gotoxy(38, 16);
    cout << "  NO, Back to Main  ";
}

void SaveMenu(List &l) {
    int pos = 0;
    MakeSaveMenu();
    char choise;
    do {
        switch (pos) {
            case 1:
                MakeSaveMenu();
                gotoxy(45, 14);
                TextColor(172);
                cout << "  YES  ";
                char et1;
                et1 = getch();
                if ((int) et1 == 13) {
                    TextColor(15);

                    OutputFile(l);
                    MainMenu(l,2);
                    TextColor(15);
                    char et; et= getch();
                    et= getch();
                }
                break;
            case 2:
                MakeSaveMenu();
                gotoxy(38, 16);
                TextColor(172);
                cout << "  NO, Back to Main  ";
                char et2;
                et2 = getch();
                if ((int) et2 == 13) {
                    TextColor(15);
                    MainMenu(l,2);
                }
                break;
        }
   			choise = getch();
        if(choise == 72 && pos > 1) pos--; else if(choise == 72 && pos == 1) pos =2;
        if(choise == 80 && pos < 2) pos++; else if(choise == 80 && pos == 2) pos =1;

    } while (1);
}

float Into_Float(string s) {


    if (s.size() == 0 || atof(s.c_str()) < 0 || atof(s.c_str()) > 10 || (s.c_str()[0] < 48 || s.c_str()[0] > 57)) return -1;
    else return atof(s.c_str());
}
void ChuanHoa(string *s) {
	int i;
    while (s->at(0) == ' ') s->erase(0, 1);//xoa khoang trong phia truoc

    while (s->at(s->length() - 1) == ' ' || s->at(s->length() - 1) < 65 || s->at(s->length() - 1) > 122 )s->erase(s->length() - 1, 1);
//xoa khoang trong phia so
    for (int i = 0; i < s->length() - 1; i++) {//xoa trung
        if (s->at(i) == s->at(i + 1)  || (s->at(i) < 65 || s->at(i) > 122)&& s->at(i) != 32 ) {
            s->erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < s->length(); i++) {// dua xau ve ki tu thuong
        if (s->at(i) >= 65 and s->at(i) <= 90) s->at(i) = s->at(i) + 32;
    }

    s->at(0) = s->at(0) - 32;
    for (int i = 0; i < s->length() - 1; i++) {//xoa cac khoang trong o giua
        if (s->at(i) == ' ') s->at(i + 1) = s->at(i + 1) - 32;
    }
    if(s->size()==0) s=s+' ';
    while(s->at(i) < s->length() )   //xoa cac ki tu khong phai la chu cai
    if((s->at(i)!=' ')&&(!isalpha(s->at(i))))
        s->erase(i, 1);
     else ++i;
}
void swap(Node *a, Node *b){
	sv temp;
	temp.DiemTB=a->DiemTB;
	temp.Hoten=a->Hoten;
	temp.Malop=a->Malop;
	temp.Masv=a->Masv;
	temp.nam=a->nam;
	temp.thang=a->thang;
	temp.ngay=a->ngay;
	a->DiemTB=b->DiemTB;
	a->Hoten=b->Hoten;
	a->Malop=b->Malop;
	a->Masv=b->Masv;
	a->nam=b->nam;
	a->thang=b->thang;
	a->ngay=b->ngay;
	b->DiemTB=temp.DiemTB;
	b->Hoten=temp.Hoten;
	b->Malop=temp.Malop;
	b->Masv=temp.Masv;
	b->nam=temp.nam;
	b->thang=temp.thang;
	b->ngay=temp.ngay;
	
}
void sortMSV1(List &l){
Node *q,*p,*min;
    p=l.head;
    
    while (p!=l.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(q->Masv<min->Masv)  min=q;
            q=q->next;
        }
       	swap(p,min);
        p=p->next;
    }


}
void sortMSV2(List &l){
	List l1;
	List l2;
	Init(l1);
	Init(l2);
	
	for(l1.head = l.head; l1.head->next != NULL; l1.head=l1.head->next){
		for(l2.head=l1.head->next; l2.head!=NULL; l2.head= l2.head-> next){
			if(l1.head->Masv > l2.head->Masv){
			swap(l1.head,l2.head);
			}
		}
	}
	
}
void sortMSV3(List &l){
	List l1,l2;
	Init(l1);
	Init(l2);
	l1.head=l.head;
	
        while(l1.head){
            if(l1.head->next){
                l2.head=NULL;
                if(l1.head->Masv > l1.head->next->Masv){
                    l2.head=l1.head->next;
                    l1.head->next = l1.head->next->next;
                }
                if(l2.head){
                    Node *temp=l.head,*prev=NULL;
                    while(temp && temp->Masv < l2.head->Masv)
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    if(prev){
                        l2.head->next = prev->next;
                        prev->next = l2.head;
                    }
                    else{
                        l2.head->next = l.head;
                        l.head = l2.head;
                    }
                    continue;
                }
            }
            l1.head=l1.head->next;
        }
	
}
void sortMSV4(List &l) {

    List l1, l2;
    Node*tag, *p;
    if (l.head == l.tail) return;

    Init(l1);
    Init(l2);
    tag = l.head;
    l.head = l.head->next; //cap nhat lai head
    tag->next = NULL; //co lap tag


    while (l.head != NULL) {
        p = l.head; //co lap head
        l.head = l.head->next; //cap nhat head

        p->next = NULL;
        if (p->Masv <= tag->Masv) addHead(l1, p);
        else addHead(l2, p);
    }
    sortMSV4(l1); //goi de quy sap xep  l1,l2
    sortMSV4(l2);

    //Noi l1,tag,l2
    if (l1.head != NULL) {
        l.head = l1.head;
        l1.tail->next = tag;

    } else {
        l.head = tag;
    }
    if (l2.head != NULL) {
        tag->next = l2.head;
        l.tail = l2.tail;
    } else {
        l.tail = tag;
    }

}
void sortMaLop1(List &l) {
	Node *q,*p,*min;
    p=l.head;
    
    while (p!=l.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(q->Malop<min->Malop)  min=q;
            q=q->next;
        }
       	swap(p,min);
        p=p->next;
    }

}
void sortMaLop2(List &l){
	List l1;
	List l2;
	Init(l1);
	Init(l2);
	
	for(l1.head = l.head; l1.head->next != NULL; l1.head=l1.head->next){
		for(l2.head=l1.head->next; l2.head!=NULL; l2.head= l2.head-> next){
			if(l1.head->Malop > l2.head->Malop){
			swap(l1.head,l2.head);
			}
		}
	}
}
void sortMaLop3(List &l){
	List l1,l2;
	Init(l1);
	Init(l2);
	l1.head=l.head;
	
        while(l1.head){
            if(l1.head->next){
                l2.head=NULL;
                if(l1.head->Malop > l1.head->next->Malop){
                    l2.head=l1.head->next;
                    l1.head->next = l1.head->next->next;
                }
                if(l2.head){
                    Node *temp=l.head,*prev=NULL;
                    while(temp && temp->Malop < l2.head->Malop)
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    if(prev){
                        l2.head->next = prev->next;
                        prev->next = l2.head;
                    }
                    else{
                        l2.head->next = l.head;
                        l.head = l2.head;
                    }
                    continue;
                }
            }
            l1.head=l1.head->next;
        }
}
void sortMaLop4(List &l) {

    List l1, l2;
    Node*tag, *p;
    if (l.head == l.tail) return;

    Init(l1);
    Init(l2);
    tag = l.head;
    l.head = l.head->next; //cap nhat lai head
    tag->next = NULL; //co lap tag


    while (l.head != NULL) {
        p = l.head; //co lap head
        l.head = l.head->next; //cap nhat head

        p->next = NULL;
        if (p->Malop <= tag->Malop) addHead(l1, p);
        else addHead(l2, p);
    }
    sortMaLop4(l1); //goi de quy sap xep  l1,l2
    sortMaLop4(l2);

    //Noi l1,tag,l2
    if (l1.head != NULL) {
        l.head = l1.head;
        l1.tail->next = tag;

    } else {
        l.head = tag;
    }
    if (l2.head != NULL) {
        tag->next = l2.head;
        l.tail = l2.tail;
    } else {
        l.tail = tag;
    }



}
//so sanh ngay thang nam

bool DateCompare(Node* n1, Node*n2) { //so sanh ngay sinh cua hai sinh vien
    if (n1->nam > n2->nam) return true;
    else if (n1->nam < n2->nam) return false;
    else {
        if (n1->thang > n2->thang) return true;
        else if (n1->thang < n2->thang) return false;
        else {
            if (n1->ngay > n2->ngay) return true;
            else if (n1->ngay < n2->ngay) return false;
            else return true;
        }
    }

}
void sortDate1(List &l){
Node *q,*p,*min;
    p=l.head;
    
    while (p!=l.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(DateCompare(min,q))  min=q;
            q=q->next;
        }
       	swap(p,min);
        p=p->next;
    }
}
void sortDate2(List &l){
	List l1;
	List l2;
	Init(l1);
	Init(l2);
	
	for(l1.head = l.head; l1.head->next != NULL; l1.head=l1.head->next){
		for(l2.head=l1.head->next; l2.head!=NULL; l2.head= l2.head-> next){
			if(DateCompare(l1.head,l2.head)){
			swap(l1.head,l2.head);
			}
		}
	}
}
void sortDate3(List &l){
	List l1,l2;
	Init(l1);
	Init(l2);
	l1.head=l.head;
	
        while(l1.head){
            if(l1.head->next){
                l2.head=NULL;
                if(DateCompare(l1.head,l1.head->next)){
                    l2.head=l1.head->next;
                    l1.head->next = l1.head->next->next;
                }
                if(l2.head){
                    Node *temp=l.head,*prev=NULL;
                    while(temp && DateCompare(l2.head,temp))
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    if(prev){
                        l2.head->next = prev->next;
                        prev->next = l2.head;
                    }
                    else{
                        l2.head->next = l.head;
                        l.head = l2.head;
                    }
                    continue;
                }
            }
            l1.head=l1.head->next;
        }
}
void sortDate4(List &l) { //sap xep Ngay Sinh

    List l1, l2;
    Node*tag, *p;
    if (l.head == l.tail) return;

    Init(l1);
    Init(l2);
    tag = l.head;
    l.head = l.head->next; //cap nhat lai head
    tag->next = NULL; //co lap tag


    while (l.head != NULL) {
        p = l.head; //co lap head
        l.head = l.head->next; //cap nhat head

        p->next = NULL;
        if (DateCompare(tag, p)) addHead(l1, p);
        else addHead(l2, p);
    }
    sortDate4(l1); //goi de quy sap xep  l1,l2
    sortDate4(l2);

    //Noi l1,tag,l2
    if (l1.head != NULL) {
        l.head = l1.head;
        l1.tail->next = tag;

    } else {
        l.head = tag;
    }
    if (l2.head != NULL) {
        tag->next = l2.head;
        l.tail = l2.tail;
    } else {
        l.tail = tag;
    }

}
void sortMark1(List &l){
	Node *q,*p,*min;
    p=l.head;
    
    while (p!=l.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(q->DiemTB<min->DiemTB)  min=q;
            q=q->next;
        }
       	swap(p,min);
        p=p->next;
    }

}
void sortMark2(List &l){
	List l1;
	List l2;
	Init(l1);
	Init(l2);
	
	for(l1.head = l.head; l1.head->next != NULL; l1.head=l1.head->next){
		for(l2.head=l1.head->next; l2.head!=NULL; l2.head= l2.head-> next){
			if(l1.head->DiemTB > l2.head->DiemTB){
			swap(l1.head,l2.head);
			}
		}
	}
}
void sortMark3(List &l){
	List l1,l2;
	Init(l1);
	Init(l2);
	l1.head=l.head;
	
        while(l1.head){
            if(l1.head->next){
                l2.head=NULL;
                if(l1.head->DiemTB > l1.head->next->DiemTB){
                    l2.head=l1.head->next;
                    l1.head->next = l1.head->next->next;
                }
                if(l2.head){
                    Node *temp=l.head,*prev=NULL;
                    while(temp && temp->DiemTB < l2.head->DiemTB)
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    if(prev){
                        l2.head->next = prev->next;
                        prev->next = l2.head;
                    }
                    else{
                        l2.head->next = l.head;
                        l.head = l2.head;
                    }
                    continue;
                }
            }
            l1.head=l1.head->next;
        }
}
void sortMark4(List &l) { // sap xep DTB

    List l1, l2;
    Node*tag, *p;
    if (l.head == l.tail) return;

    Init(l1);
    Init(l2);
    tag = l.head;
    l.head = l.head->next; //cap nhat lai head
    tag->next = NULL; //co lap tag


    while (l.head != NULL) {
        p = l.head; //co lap head
        l.head = l.head->next; //cap nhat head

        p->next = NULL;
        if (p->DiemTB < tag->DiemTB) addHead(l1, p);
        else addHead(l2, p);
    }
    sortMark4(l1); //goi de quy sap xep  l1,l2
    sortMark4(l2);

    //Noi l1,tag,l2
    if (l1.head != NULL) {
        l.head = l1.head;
        l1.tail->next = tag;

    } else {
        l.head = tag;
    }
    if (l2.head != NULL) {
        tag->next = l2.head;
        l.tail = l2.tail;
    } else {
        l.tail = tag;
    }

}

bool NameCompare(Node*n1, Node*n2) { //so sanh ten cua 2 sv
    string s1 = n1->Hoten;
    string s2 = n2->Hoten;
    string lastName1, lastName2, midName1, midName2,firstName1,firstName2;

    int pos1, pos2;

    for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1.at(i) == ' ') {
            lastName1 = s1.substr(i + 1, s1.size() - 1 - (i));
            for (int j = 0; j <=i; j++) {
                if (s1.at(j) == ' ') {
                    firstName1 = s1.substr(0, j);
                    midName1 = s1.substr(j+1, i-(j+1));
                    break;
                } 
            }
            break;
        } else if (i == 0) {
            lastName1 = s1;
        }
    }


   for (int i = s2.size() - 1; i >= 0; i--) {
        if (s2.at(i) == ' ') {
            lastName2 = s2.substr(i + 1, s2.size() - 1 - (i));
            for (int j = 0; j <=i; j++) {
                if (s2.at(j) == ' ') { 
                    firstName2 = s2.substr(0, j);
                    midName2 = s2.substr(j+1, i-(j+1));
                    break;
                } 
            }
            break;
        } else if (i == 0) {
            lastName2 = s2;
        }
    }

    if (lastName1.length() < lastName2.length()) {
        if (lastName1 < lastName2.substr(0, lastName1.length())) return true;
        else return false;
    } else if (lastName1.length() > lastName2.length()) {
        if (lastName1.substr(0, lastName2.length()) < lastName2) return true;
        else return false;
    } else {
        if (lastName1 < lastName2) return true;
        else if (lastName1 == lastName2) {
            if (firstName1 < firstName2) return true;
            else {
                if(firstName1 > firstName2) return false;
                else{
                    if(midName1<midName2) return true;
                    else return false;
                }
            }
        } else return false;
    }
   

}
void sortName1(List &l){
	Node *q,*p,*min;
    p=l.head;
    
    while (p!=l.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(NameCompare(q, min))  min=q;
            q=q->next;
        }
       	swap(p,min);
        p=p->next;
    }

}
void sortName2(List &l){
	List l1;
	List l2;
	Init(l1);
	Init(l2);
	
	for(l1.head = l.head; l1.head->next != NULL; l1.head=l1.head->next){
		for(l2.head=l1.head->next; l2.head!=NULL; l2.head= l2.head-> next){
			if(NameCompare(l2.head, l1.head)){
			swap(l1.head,l2.head);
			}
		}
	}
}
void sortName3(List &l){
	List l1,l2;
	Init(l1);
	Init(l2);
	l1.head=l.head;
	
        while(l1.head){
            if(l1.head->next){
                l2.head=NULL;
                if(NameCompare(l1.head->next, l1.head)){
                    l2.head=l1.head->next;
                    l1.head->next = l1.head->next->next;
                }
                if(l2.head){
                    Node *temp=l.head,*prev=NULL;
                    while(temp && NameCompare(temp, l2.head))
                    {
                        prev=temp;
                        temp=temp->next;
                    }
                    if(prev){
                        l2.head->next = prev->next;
                        prev->next = l2.head;
                    }
                    else{
                        l2.head->next = l.head;
                        l.head = l2.head;
                    }
                    continue;
                }
            }
            l1.head=l1.head->next;
        }
}
void sortName4(List &l) { //sx ten

    List l1, l2;
    Node*tag, *p;
    if (l.head == l.tail) return;

    Init(l1);
    Init(l2);
    tag = l.head;
    l.head = l.head->next; //cap nhat lai head
    tag->next = NULL; //co lap tag


    while (l.head != NULL) {
        p = l.head; //co lap head
        l.head = l.head->next; //cap nhat head

        p->next = NULL;
        if (NameCompare(p, tag)) addHead(l1, p);
        else addHead(l2, p);
    }
    sortName4(l1); //goi de quy sap xep  l1,l2
    sortName4(l2);

    //Noi l1,tag,l2
    if (l1.head != NULL) {
        l.head = l1.head;
        l1.tail->next = tag;

    } else {
        l.head = tag;
    }
    if (l2.head != NULL) {
        tag->next = l2.head;
        l.tail = l2.tail;
    } else {
        l.tail = tag;
    }
}
void MakeSortMenu1(){
	TextColor(22);
	gotoxy(45,3);
	cout<<"CHON KIEU SAP XEP";
	TextColor(15);
	gotoxy(30,5);
	cout<<"1.Selection sort";
	gotoxy(30,7);
	cout<<"2.Bubble sort";
	gotoxy(30,9);
	cout<<"3.Insertion sort";
	gotoxy(30,11);
	cout<<"4.Quick Sort";
	gotoxy(30,13);
	cout<<"5.BACK";
}
void SortMenu1(List &l){
	TextColor(15);
	XoaManHinh();
	char ch;
	
	int pos =1;
	while(1){
		switch(pos){
			case 1: MakeSortMenu1();
					TextColor(172);
					gotoxy(30,5);
					cout<<"1.Selection sort";
					char et1; et1= getch();
					if(et1 == 13){
						TextColor(15);
						XoaManHinh();
						
						MakeSortMenu();
						SortMenu(l,1);
					}
					break;
			case 2: MakeSortMenu1();
					TextColor(172);
					gotoxy(30,7);
					cout<<"2.Bubble sort";
					char et2; et2= getch();
					if(et2 == 13){
						TextColor(15);
						XoaManHinh();
						
						MakeSortMenu();
						SortMenu(l,2);
					}
					break;
			case 3: MakeSortMenu1();
					TextColor(172);
					gotoxy(30,9);
					cout<<"3.Insertion sort";
					char et3; et3= getch();
					if(et3 == 13){
						TextColor(15);
						XoaManHinh();
						
						MakeSortMenu();
						SortMenu(l,3);
					}
					break;
			case 4: MakeSortMenu1();
					TextColor(172);
					gotoxy(30,11);
					cout<<"4.Quick Sort";
					char et4; et4= getch();
					if(et4 == 13){
						TextColor(15);
						XoaManHinh();
						
						MakeSortMenu();
						SortMenu(l,4);
					}
					break;
			case 5: MakeSortMenu1();
					TextColor(172);
					gotoxy(30,13);
					cout<<"5.BACK";
					char et5; et5= getch();
					if(et5 == 13){
					TextColor(15);
			   		system("cls");
			   	
			   		MainMenu(l,3);	
					}
					break;
		}ch= getch();
		if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 5;//dieu khien len
			if (ch == 80 && pos < 5) pos++;
			else if (ch == 80 && pos == 5) pos = 1;//dieu khien xuong
	}
}
void MakeSortMenu(){
	TextColor(30);
	gotoxy(45,2);
	cout<<"Kieu sap xep:";
	TextColor(14);
	gotoxy(45,4);
	cout<<"CHON TRUONG SAP XEP";
	TextColor(15);
	gotoxy(45,6);
	cout<<"1.MA SINH VIEN";
	gotoxy(45,7);
	cout<<"2.MA LOP";
	gotoxy(45,8);
	cout<<"3.HO TEN";
	gotoxy(45,9);
	cout<<"4.NGAY SINH";
	gotoxy(45,10);
	cout<<"5.DIEM TRUNG BINH TICH LUY";
	gotoxy(45,15);
	cout<<"BACK";
	
}
void SortMenu(List &l,int k){
	MakeSortMenu();
	if (k == 1){
		TextColor(15);
		gotoxy(60,2); cout<<"Selection sort";
	 }
	if (k == 2){
	TextColor(15);
	gotoxy(60,2); cout<<"Bubble sort";
	}
	if (k == 3){
	TextColor(15);
	gotoxy(60,2); cout<<"Insertion sort";
	}
	if(k == 4){
	TextColor(15);
	gotoxy(60,2); cout<<"Quick sort";	
	}
	TextColor(15);

	char ch;
	int pos = 1;
	do{
		switch(pos){
		case 1:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,6);
			   cout<<"1.MA SINH VIEN";
			   char et1; et1 = getch();
			   if(et1 == 13){
			   	if (k == 1){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Selection sort";
			   		TextColor(15);
			   		sortMSV1(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
				if (k == 2){
					
					TextColor(15);
			   		gotoxy(60,2); cout<<"Bubble sort";
					TextColor(15);
			   		sortMSV2(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 3){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Insertion sort";
			   		TextColor(15);
			   		sortMSV3(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
			   	if (k == 4){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Quick sort";
			   		TextColor(15);
			   		sortMSV4(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
			   }
			   break;
		case 2:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,7);
			   cout<<"2.MA LOP";
			   char et2; et2 = getch();
			   if(et2 == 13){
			   	if (k == 1){
			   			TextColor(15);
			   		gotoxy(60,2); cout<<"Selection sort";
			   		TextColor(15);
			   		sortMaLop1(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
				if (k == 2){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Bubble sort";
			   		TextColor(15);
			   		sortMaLop2(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 3){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Insertion sort";
			   		TextColor(15);
			   		sortMaLop3(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
			   	if(k == 4){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Quick sort";
			   		TextColor(15);
			   		sortMaLop4(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
			   }
			   break;
		case 3:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,8);
			   cout<<"3.HO TEN";
			   char et3; et3 = getch();
			   if(et3 == 13){
			   	if (k == 1){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Selection sort";
			   		TextColor(15);
			   		sortName1(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
				if (k == 2){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Bubble sort";
			   		TextColor(15);
			   		sortName2(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 3){
					TextColor(152);
			   		gotoxy(60,2); cout<<"Insertion sort";
			   		TextColor(15);
			   		sortName3(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
			   	if(k == 4){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Quick sort";
			   		TextColor(15);
			   		sortName4(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				   }
			   	
			   }
			   break;
		case 4:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,9);
			   cout<<"4.NGAY SINH";
			   char et4; et4 = getch();
			   if(et4 == 13){
			   	if (k == 1){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Selection sort";
			   		TextColor(15);
			   		sortDate1(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 2){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Bubble sort";
			   		TextColor(15);
			   		sortDate2(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 3){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Insertion sort";
			   		TextColor(15);
			   		sortDate3(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
			   	if(k == 4){
				   TextColor(15);
			   		gotoxy(60,2); cout<<"Quick sort";
			   		TextColor(15);
			   		sortDate4(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
                }
			   }
			   break;
		case 5:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,10);
			   cout<<"5.DIEM TRUNG BINH TICH LUY";
			   char et5; et5 = getch();
			   if(et5 == 13){
			   	if (k == 1){
			   		TextColor(15);
			   		gotoxy(60,2); cout<<"Selection sort";
			   		TextColor(15);
			   		sortMark1(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 2){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Bubble sort";
			   		TextColor(15);
			   		sortMark2(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
				if (k == 3){
					TextColor(15);
			   		gotoxy(60,2); cout<<"Insertion sort";
			   		TextColor(15);
			   		sortMark3(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
				}
			   	if(k==4){
				    TextColor(15);
			   		gotoxy(60,2); cout<<"Quick sort";
			   		TextColor(15);
			   		sortMark4(l);
                    OutputConsole(l);
                    cout<<"\n\n\n\n\n\n"<<endl;
                    system("PAUSE");
                    system("cls");
                    MakeMainMenu();
                    SortMenu(l,k);
                }
			   }
			   break;
		case 6:MakeSortMenu();
			   TextColor(172);
			   gotoxy(45,15);
			   cout<<"BACK";
			   char et6; et6 = getch();
			   if(et6 == 13){
			   	TextColor(15);
			   	XoaManHinh();
			   	SortMenu1(l);
			   }
			   break;
	}ch= getch();
		if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 6;//dieu khien len
			if (ch == 80 && pos < 6) pos++;
			else if (ch == 80 && pos == 6) pos = 1;//dieu khien xuong
}while(1);
}
bool isSameString(string s1, string s2) {//so sanh 2 string
    if (s1.find(s2) == -1) return false;
    else return true;
}

bool searchDate1(Node*p, int ngay, int thang, int nam) {
    if (p->ngay == ngay and p->thang == thang and p->nam == nam) return true;
    else return false;
}

bool searchDate2(Node*p, int ngay, int thang, int nam) {
    if (p->ngay == ngay and p->thang == thang) return true;
    else return false;
}

bool searchDate3(Node*p, int ngay, int thang, int nam) {
    if (p->nam == nam and p->thang == thang) return true;
    else return false;
}

bool searchDiemTB(Node*p, float DiemTB) { //tim diem trung binh
    
    if (p->DiemTB == DiemTB)return true;
   
    return false;
}
bool searchDiemTB_etc(Node* p, float DiemTB){
    if (int(p->DiemTB) == int(DiemTB))return false;
    return true;
}

bool searchMSV(Node*p, string key) { //TIM KIEM Msv
    
    if (isSameString(p->Masv, key))return true;

    
    return false;
}

bool searchML(Node*p, string key) {
    if (isSameString(p->Malop, key))return true;
    
    return false;
}

bool searchName(Node*p, string key) {

    if (isSameString(p->Hoten, key))return true;
    return false;
}
void MakeFindMenu2(){
	TextColor(14);
	gotoxy(30,4);
	cout<<"Chon khoa can tim kiem";
	TextColor(15);
	gotoxy(35,6);
	cout<<"1.Ma Lop";
	gotoxy(35,7);
	cout<<"2.Ma sinh vien";
	gotoxy(35,8);
	cout<<"3.Ho ten";
	gotoxy(35,9);
	cout<<"4.Ngay sinh";
	gotoxy(35,10);
	cout<<"5.Diem trung binh tich luy";
	gotoxy(42,12);
	cout<<"BACK TO MAINMENU";
}
void FindMenu2(List &l, int k){
	TextColor(15);
	XoaManHinh();
	char ch;
	int pos=1;
	while(1){
		switch(pos){
			case 1: MakeFindMenu2();
					TextColor(172);
					gotoxy(35,6);
					cout<<"1.Ma Lop";
					char et1; et1= getch();
					if(et1 == 13){
						TextColor(15);
						XoaManHinh();
						string key;
						
						gotoxy(38, 10);
						TextColor(11);
        				cout << "Key: ";
        				TextColor(252);
       					Deleteline(44, 10, 30);
        				gotoxy(45, 10);
        				CursorStatus(25, TRUE);
        				fflush(stdin);
        				getline(cin, key);
        				CursorStatus(25, FALSE);
        			
        				OutputConsole2(l);
						Node*p;
						p=l.head;
						int i=5,h=0;
						ChuanHoa3(&key);
        				while(p!=NULL){
        					if(searchML(p,key)) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							i++;
							p=p->next;
							
        					
						}
						if(h==0) {
						system("cls");
						gotoxy(50,10);
						TextColor(14);
						cout<<"Du lieu khong ton tai";
						Sleep(1500);
						system("cls");
						MakeMainMenu();
						FindMenu2(l,k);
						}
						else{
							char c; c =getch();
							if(c == 27){
								system("cls");
								MakeMainMenu();
								FindMenu2(l,1);
								}
							if(c == 13){
								system("cls");
            					SaveMenu(l);
								}
						}
						
					} 
					break;
			case 2: MakeFindMenu2();
					TextColor(172);
					gotoxy(35,7);
					cout<<"2.Ma sinh vien";
					char et2; et2= getch();
					if(et2 == 13){
						TextColor(15);
						XoaManHinh();
						string key;
						
						gotoxy(38, 10);
						TextColor(11);
        				cout << "Key: ";
        				TextColor(252);
       					Deleteline(44, 10, 30);
        				gotoxy(45, 10);
        				CursorStatus(25, TRUE);
        				fflush(stdin);
        				getline(cin, key);
        				CursorStatus(25, FALSE);
        			
        				OutputConsole2(l);
						Node*p;
						p=l.head;
						int i=5,h=0;
						
        				while(p!=NULL){
        					if(searchMSV(p,key)) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							i++;
							p=p->next;
							
        					
						}
						if(h==0) {
						system("cls");
						gotoxy(50,10);
						TextColor(14);
						cout<<"Du lieu khong ton tai";
						Sleep(1500);
						system("cls");
						MakeMainMenu();
						FindMenu2(l,k);
						}
						else{
							char c; c =getch();
							if(c == 27){
								system("cls");
								MakeMainMenu();
								FindMenu2(l,1);
								}
							if(c == 13){
								system("cls");
            					SaveMenu(l);
								}
						}
					} 
					break;
			case 3: MakeFindMenu2();
					TextColor(172);
					gotoxy(35,8);
					cout<<"3.Ho ten";
					char et3; et3= getch();
					if(et3 == 13){
						TextColor(15);
						XoaManHinh();
						string key;
						
						gotoxy(38, 10);
						TextColor(11);
        				cout << "Key: ";
        				TextColor(252);
       					Deleteline(44, 10, 30);
        				gotoxy(45, 10);
        				CursorStatus(25, TRUE);
        				fflush(stdin);
        				getline(cin, key);
        				CursorStatus(25, FALSE);
        			
        				OutputConsole2(l);
						Node*p;
						p=l.head;
						int i=5,h=0;
						ChuanHoa(&key);
        				while(p!=NULL){
        					if(searchName(p,key)) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							i++;
							p=p->next;
							
        					
						}
						if(h==0) {
						system("cls");
						gotoxy(50,10);
						TextColor(14);
						cout<<"Du lieu khong ton tai";
						Sleep(1500);
						system("cls");
						MakeMainMenu();
						FindMenu2(l,k);
						}
						else{
							char c; c =getch();
							if(c == 27){
								system("cls");
								MakeMainMenu();
								FindMenu2(l,1);
								}
							if(c == 13){
								system("cls");
            					SaveMenu(l);
								}
						}
					} 
					break;
			case 4: MakeFindMenu2();
					TextColor(172);
					gotoxy(35,9);
					cout<<"4.Ngay sinh";
					char et4; et4= getch();
					if(et4 == 13){
						string day, month, year;
						do {	TextColor(15);
						XoaManHinh();
						    
						gotoxy(32, 10);
						TextColor(11);
        				cout << "Key Date: ";
        				
        				gotoxy(45, 10);
        				TextColor(143);
    					cout << "      ";
    					TextColor(15);
    					cout<<" - ";
    					TextColor(143);
    					cout << "      ";
						TextColor(15);
    					cout << " - ";
    					TextColor(143);
  						cout << "      ";
        				gotoxy(46, 10);
                            
                            fflush(stdin);
                            CursorStatus(25, TRUE);
                            getline(cin, day);
                            CursorStatus(25, FALSE);
                            fflush(stdin);
                            gotoxy(55, 10);

                            CursorStatus(25, TRUE);
                            getline(cin, month);
                            CursorStatus(25, FALSE);
                            fflush(stdin);
                            gotoxy(63, 10);
                            
                            CursorStatus(25, TRUE);
                            getline(cin, year);
                            CursorStatus(25, FALSE);
        				if (KiemtraDate(ChuanHoa2(day), ChuanHoa2(month), ChuanHoa2(year))==false) {
                                TextColor(12);
                                gotoxy(40, 7);
                                cout << "DateError! Try again..";
                                Sleep(400);
                                Deleteline(40, 7, 24);
                            } else {
                                TextColor(15);
                            }
                        } while (KiemtraDate(ChuanHoa2(day), ChuanHoa2(month), ChuanHoa2(year))==false);
        				OutputConsole2(l);
						Node*p;
						p=l.head;
						int i=5,h=0;
						
        				while(p!=NULL){
        					if(searchDate1(p, ChuanHoa2(day), ChuanHoa2(month), ChuanHoa2(year))) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							if(searchDate2(p, ChuanHoa2(day), ChuanHoa2(month), ChuanHoa2(year))) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							if(searchDate3(p, ChuanHoa2(day), ChuanHoa2(month), ChuanHoa2(year))) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							i++;
							p=p->next;
							
        					
						}
						if(h==0) {
						system("cls");
						gotoxy(50,10);
						TextColor(14);
						cout<<"Du lieu khong ton tai";
						Sleep(1500);
						system("cls");
						MakeMainMenu();
						FindMenu2(l,k);
						}
						else{
							char c; c =getch();
							if(c == 27){
								system("cls");
								MakeMainMenu();
								FindMenu2(l,1);
								}
							if(c == 13){
								system("cls");
            					SaveMenu(l);
								}
						}
						
					} 
					break;
			case 5:MakeFindMenu2();
					TextColor(172);
					gotoxy(35,10);
					cout<<"5.Diem trung binh tich luy";
					char et5; et5= getch();
					if(et5 == 13){
							TextColor(15);
						XoaManHinh();
						float key;
						
						gotoxy(38, 10);
						TextColor(11);
        				cout << "Key: ";
        				TextColor(252);
       					Deleteline(44, 10, 30);
        				gotoxy(45, 10);
        				CursorStatus(25, TRUE);
        				fflush(stdin);
        				cin>>key;
        				CursorStatus(25, FALSE);
        			
        				OutputConsole2(l);
						Node*p;
						p=l.head;
						int i=5,h=0;
						
        				while(p!=NULL){
        					if(searchDiemTB(p,key)) {
        						TextColor(15);
        						gotoxy(3, i);
        						cout << p->Hoten;
       
        						gotoxy(32, i);
        						cout << p->Malop;
        						gotoxy(46, i);
        						cout << p->Masv;
        						gotoxy(60, i);
        						cout << p->ngay << "/" << p->thang << "/" << p->nam;
        						gotoxy(77, i);
        						cout << p->DiemTB;
        						h=1;	
							}
							i++;
							p=p->next;
							
        					
						}
						if(h==0) {
						system("cls");
						gotoxy(50,10);
						TextColor(14);
						cout<<"Du lieu khong ton tai";
						Sleep(1500);
						system("cls");
						MakeMainMenu();
						FindMenu2(l,k);
						}
						else{
							char c; c =getch();
							if(c == 27){
								system("cls");
								MakeMainMenu();
								FindMenu2(l,1);
								}
							if(c == 13){
								system("cls");
            					SaveMenu(l);
								}
						
					} 
				}
					break;
			case 6:MakeFindMenu2();
					TextColor(172);
					gotoxy(42,12);
					cout<<"BACK TO MAINMENU";
					char et6; et6= getch();
					if(et6 == 13){
						MainMenu(l,4);
					} 
					break;
		}ch = getch();
		if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 6;//dieu khien len
			if (ch == 80 && pos < 6) pos++;
			else if (ch == 80 && pos == 6) pos = 1;//dieu khien xuong
	}
}
void MakeFindMenu1(){
	TextColor(22);
	gotoxy(30,3);
	cout<<"CHON KIEU TIM KIEM";
	TextColor(15);
	gotoxy(30,5);
	cout<<"1.Tim kiem tuan tu";
	gotoxy(30,7);
	cout<<"2.Tim kiem nhi phan";
	gotoxy(30,9);
	cout<<"BACK";
	
}
void FindMenu1(List &l){
	TextColor(15);
	char ch;
	
	int pos=1;
	do {
	switch(pos){
		case 1: 
				MakeFindMenu1();
				TextColor(172);
				gotoxy(30,5);
				cout<<"1.Tim kiem tuan tu";
				char et1; et1=getch();
				if(et1==13){
					TextColor(15);
					XoaManHinh();
					FindMenu2(l,1);
					
				}
				break;
		case 2: MakeFindMenu1();
				TextColor(172);
				gotoxy(30,7);
				cout<<"2.Tim kiem nhi phan";
				char et2; et2= getch();
				if (et2==13){
					TextColor(15);
					XoaManHinh();
					FindMenu2(l,2);
				}
				break;
		case 3:MakeFindMenu1();
				TextColor(172);
				gotoxy(30,9);
				cout<<"BACK";
				char et3; et3= getch();
				if (et3==13){
					MainMenu(l,4);
				}
				break;
	}ch = getch();
		if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 3;//dieu khien len
			if (ch == 80 && pos < 3) pos++;
			else if (ch == 80 && pos == 3) pos = 1;//dieu khien xuong
}while(1);
}
void MakeFindMenu(){
	TextColor(14);
	gotoxy(42,10);
	cout<<"Danh sach da sap xep chua?";
	TextColor(15);
	gotoxy(50,12);
	cout<<"Yes";
	gotoxy(58,12);
	cout<<"No";
}
void FindMenu(List &l){
	int pos=1;
	char ch;
	do { 
		switch(pos){
		case 1: MakeFindMenu();
				TextColor(172);
				gotoxy(50,12);
				cout<<"Yes";
				
				char et; et= getch();
				if(et == 13){
					TextColor(15);
					XoaManHinh();
					FindMenu1(l);
				}
				break;
		case 2: MakeFindMenu();
				TextColor(172);
				gotoxy(58,12);
				cout<<"No";
				char et1; et1= getch();
				if(et1==13){
						TextColor(15);
						XoaManHinh();
						TextColor(13);
						gotoxy(40,10);
						cout<<"CHI CHO PHEP TIM KIEM TUAN TU";
						Sleep(1000);
						FindMenu2(l,1);
					}
				
	}ch = getch();
	if (ch == 75 && pos > 1) pos--;
			else 	if (ch == 75 && pos == 1) pos = 2;//dieu khien len
			if (ch == 77 && pos < 2) pos++;
			else if (ch == 77 && pos == 2) pos = 1;//dieu khien xuong
 }while(1);
}
int NumOfClassCode(List& l) {
    Node*p = l.head;
    if (isEmpty(l)) {
        return 0;
    } else if (l.head == l.tail) return 1;
    else {

        sortMaLop4(l);
        int num = 1;
        while (p->next != NULL) {
            if (p->Malop != p->next->Malop) num++;
            p = p->next;
        }
        return num;
    }



}
void Border4(int lenght){
TextColor(15);
	system("cls");
    TextColor(9);
int pos_y=8;
  

    for (int i = 2; i < lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(15, i);
        printf("%c", 186);
        gotoxy(28, i);
        printf("%c", 186);
        gotoxy(41, i);
        printf("%c", 186);
        gotoxy(54, i);
        printf("%c", 186);
        gotoxy(67, i);
        printf("%c", 186);
    }
	for(int i=4; i< lenght+ pos_y;i++){
		gotoxy(22, i);
        printf("%c", 186);
        gotoxy(35, i);
        printf("%c", 186);
        gotoxy(48, i);
        printf("%c", 186);
        gotoxy(61, i);
        printf("%c", 186);
	}
    for (int i = 2; i < 67; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
        
        gotoxy(i, 6);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y - 2);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y);
        printf("%c", 205);
    }
    for(int i=15;i<67;i++){
    	gotoxy(i, 4);
        printf("%c", 205);
	}

    gotoxy(1, 2);
    printf("%c", 201);
   
    gotoxy(1, lenght + pos_y);
    printf("%c", 200);
  
    gotoxy(15, 2);
    printf("%c", 203);
    gotoxy(15, lenght + pos_y);
    printf("%c", 202);
    gotoxy(22, 4);
    printf("%c", 203);
    gotoxy(22, lenght + pos_y);
    printf("%c", 202);
    gotoxy(28, 2);
    printf("%c", 203);
    gotoxy(28, lenght + pos_y);
    printf("%c", 202);
    gotoxy(35, 4);
    printf("%c", 203);
    gotoxy(35, lenght + pos_y);
    printf("%c", 202);
    gotoxy(41, 2);
    printf("%c", 203);
    gotoxy(41, lenght + pos_y);
    printf("%c", 202);
    gotoxy(48, 4);
    printf("%c", 203);
    gotoxy(48, lenght + pos_y);
    printf("%c", 202);
    gotoxy(54, 2);
    printf("%c", 203);
    gotoxy(54, lenght + pos_y);
    printf("%c", 202);
    gotoxy(61, 4);
    printf("%c", 203);
    gotoxy(61, lenght + pos_y);
    printf("%c", 202);
    gotoxy(67, 2);
    printf("%c", 187);
    gotoxy(67, lenght + pos_y);
    printf("%c",188);


    for (int i = 0; i < 4; i++) {
        gotoxy(15 + i * 13, 4);
        printf("%c", 206);
    }

for (int i = 0; i < 4; i++) {
        gotoxy(15 + i * 13, 6);
        printf("%c", 206);
    }

for (int i = 0; i < 4; i++) {
        gotoxy(22 + i * 13, 6);
        printf("%c", 206);
    }
    for (int i = 0; i < 4; i++) {
        gotoxy(15 + i * 13, lenght + pos_y - 2);
        printf("%c", 206);
    }
for (int i = 0; i < 4; i++) {
        gotoxy(22 + i * 13, lenght + pos_y - 2);
        printf("%c", 206);
    }

    gotoxy(15, 1);
    TextColor(12);
    cout << "__***Thong Ke Du Lieu SV***__    ";
    TextColor(14);
    cout << "Enter: continue!";
    gotoxy(2, 4);
    TextColor(11);
    cout << "  -Ma Lop-";
    gotoxy(18, 3);
    cout << " -Gioi-";
    gotoxy(31, 3);
    cout << "  -Kha-";
    gotoxy(44, 3);
    cout << "  -TB-";
    gotoxy(57, 3);
    cout << "  -YEU-";
    gotoxy(4, lenght + pos_y - 1);
    cout << "-*-TOng-*-";
    gotoxy(18,5);
    cout<<"SL";
    gotoxy(25,5);
    cout<<"%";
    gotoxy(31,5);
    cout<<"SL";
    gotoxy(38,5);
    cout<<"%";
    gotoxy(44,5);
    cout<<"SL";
    gotoxy(51,5);
    cout<<"%";
    gotoxy(57,5);
    cout<<"SL";
    gotoxy(64,5);
    cout<<"%";
    TextColor(15);

}
void Border5(int lenght){
	TextColor(15);
	system("cls");
    TextColor(9);

    int pos_y=8;
 	
 	
  for (int i = 2; i < lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        
        gotoxy(41, i);
        printf("%c", 186);
        gotoxy(54, i);
        printf("%c", 186);
        
       
    }
    for (int i = 2; i < lenght+ pos_y-2; i++){
    	gotoxy(15, i);
        printf("%c", 186);
	}
       for (int i = 2; i < 54; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
        gotoxy(i, 4);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y - 2);
        printf("%c", 205);
        gotoxy(i, lenght + pos_y);
        printf("%c", 205);
    }
     gotoxy(1, 2);
    printf("%c", 201);
   	gotoxy(1, lenght + pos_y);
    printf("%c", 200);
    gotoxy(15, 2);
    printf("%c", 203);
   
    gotoxy(41, 2);
    printf("%c", 203);
    gotoxy(41, lenght + pos_y);
    printf("%c", 202);
    gotoxy(54, 2);
    printf("%c", 203);
    gotoxy(54, lenght + pos_y);
    printf("%c", 202);
 	 
        gotoxy(15, 4);
        printf("%c", 206);
        gotoxy(41, 4);
        printf("%c", 206);
		gotoxy(54, 4);
        printf("%c", 206);
		gotoxy(41, lenght + pos_y - 2);
        printf("%c", 206);
		gotoxy(54, lenght + pos_y - 2);
        printf("%c", 206);
		gotoxy(15, lenght + pos_y - 2);
        printf("%c", 202);
  		 gotoxy(14, 1);
    TextColor(12);
    cout << "__***Thong Ke SV***__    ";
    TextColor(14);
    cout << "Enter: continue!";
    gotoxy(2, 3);
    TextColor(11);
    cout << "  -Ma Lop-";
    gotoxy(24, 3);
    cout << " -Ten Lop-";
 
    gotoxy(44, 3);
    cout << " *-TOng-*";
    
    gotoxy(23, lenght + pos_y - 1);
    cout << "-*-TOng-*-";
    TextColor(15);
}
void Thongkesoluong(List &l){
	sortMaLop4(l);
	int lenght=NumOfClassCode(l)-1;
	int sl=1,sum=0;
	int i=5;
		Border5(lenght);
		Node *k=l.head;
	while(k->next!=NULL){
		if(k->Malop!=k->next->Malop){
			gotoxy(2,i);
			cout<<k->Malop;
			gotoxy(20,i);
			cout<<k->Malop;
			gotoxy(42,i);
			cout<<sl;
			sum+=sl;
			i++;
			sl=0;
		}
		sl++;
		k=k->next;
	}
	gotoxy(2,i);
			cout<<k->Malop;
			gotoxy(20,i);
			cout<<k->Malop;
			gotoxy(42,i);
			cout<<sl;
			sum+=sl;
			i+=2;
	gotoxy(42,i);
	cout<<sum;
	char et; et=getch();
	if(et==13){
		system("cls");
		MainMenu(l,5);
	}else{
		system("cls");
		MainMenu(l,5);
	}
}
void Thongkexeploai(List &l){
	int sl=lenghtNode(l);
	sortMaLop4(l);
	int lenght=NumOfClassCode(l)+1;
	int G=0,K=0,TB=0,Y=0;
	int sumG=0,sumK=0,sumTB=0,sumY=0,sum=0;
	Node *k=l.head;
	Border4(lenght);
	int i=7;
	while(k->next!=NULL){
		
	
		sum++;
		if(k->DiemTB>=8) G++;
		else
		if(k->DiemTB>=7) K++;
		else
		if(k->DiemTB>=5) TB++;
		else Y++;
		
		if(k->Malop!=k->next->Malop){
		gotoxy(2,i);
		cout<<k->Malop;	
		gotoxy(18,i);
		cout<<G;
		gotoxy(24,i);
		
		if((float(G*100)/float(sum))-(G*100)/sum >= 0.5)
		cout<<(G*100)/sum+1;else cout<<(G*100)/sum;
		gotoxy(31,i);
		cout<<K;
		gotoxy(37,i);
			if((float(K*100)/float(sum))-(K*100)/sum >= 0.5)
		cout<<(K*100)/sum+1;else cout<<(K*100)/sum;
	
		gotoxy(44,i);
		cout<<TB;
		gotoxy(50,i);
			if((float(TB*100)/float(sum))-(TB*100)/sum >= 0.5)
		cout<<(TB*100)/sum+1;else cout<<(TB*100)/sum;
	
		gotoxy(57,i);
		cout<<Y;
		gotoxy(63,i);
			if((float(Y*100)/float(sum))-(Y*100)/sum >= 0.5)
		cout<<(Y*100)/sum+1;else cout<<(Y*100)/sum;
	
		i++;
		sumG+=G;sumK+=K;sumTB+=TB;sumY+=Y;
		sum=0;
		G=K=TB=Y=0;
		}
		k=k->next;
	}
		sum++;
		if(k->DiemTB>=8) G++;
		else
		if(k->DiemTB>=7) K++;
		else
		if(k->DiemTB>=5) TB++;
		else Y++;
		gotoxy(2,i);
		cout<<k->Malop;	
		gotoxy(18,i);
		cout<<G;
		gotoxy(24,i);
		
		if((float(G*100)/float(sum))-(G*100)/sum >= 0.5)
		cout<<(G*100)/sum+1;else cout<<(G*100)/sum;
		gotoxy(31,i);
		cout<<K;
		gotoxy(37,i);
			if((float(K*100)/float(sum))-(K*100)/sum >= 0.5)
		cout<<(K*100)/sum+1;else cout<<(K*100)/sum;
	
		gotoxy(44,i);
		cout<<TB;
		gotoxy(50,i);
			if((float(TB*100)/float(sum))-(TB*100)/sum >= 0.5)
		cout<<(TB*100)/sum+1;else cout<<(TB*100)/sum;
	
		gotoxy(57,i);
		cout<<Y;
		gotoxy(63,i);
			if((float(Y*100)/float(sum))-(Y*100)/sum >= 0.5)
		cout<<(Y*100)/sum+1;else cout<<(Y*100)/sum;
	
		sumG+=G;sumK+=K;sumTB+=TB;sumY+=Y;
		i+=2;
		gotoxy(18,i);
		cout<<sumG;
		gotoxy(24,i);
			if((float(sumG*100)/float(sl))-(sumG*100)/sl >= 0.5)
		cout<<(sumG*100)/sl+1;else cout<<(sumG*100)/sl;
		gotoxy(31,i);
		cout<<sumK;
		gotoxy(37,i);
		if((float(sumK*100)/float(sl))-(sumK*100)/sl >= 0.5)
		cout<<(sumK*100)/sl+1;else cout<<(sumK*100)/sl;
		
		gotoxy(44,i);
		cout<<sumTB;
		gotoxy(50,i);
		if((float(sumTB*100)/float(sl))-(sumTB*100)/sl >= 0.5)
		cout<<(sumTB*100)/sl+1;else cout<<(sumTB*100)/sl;
	
		gotoxy(57,i);
		cout<<sumY;
		gotoxy(63,i);
		if((float(sumY*100)/float(sl))-(sumY*100)/sl >= 0.5)
		cout<<(sumY*100)/sl+1;else cout<<(sumY*100)/sl;
		char et; et=getch();
	if(et==27){
		system("cls");
		MainMenu(l,5);
	}else{
		system("cls");
		MainMenu(l,5);
	}
}
void MakeMenuThongKe(){
	TextColor(14);
	gotoxy(40,5);
	cout<<"CHON KIEU BAO CAO";
	TextColor(15);
	gotoxy(40,8);
	cout<<"1.So luong sinh vien theo lop";
	TextColor(15);
	gotoxy(40,10);
	cout<<"2.Ty le phan loai ket qua hoc tap";
	TextColor(15);
	gotoxy(40,12);
	cout<<"BACK";
}
void MenuThongKe(List &l){
	int pos=1;
	char ch;
	while(1){
		switch(pos){
					case 1: MakeMenuThongKe();
							TextColor(172);
							gotoxy(40,8);
							cout<<"1.So luong sinh vien theo lop";
							char et1; et1= getch();
							if(et1==13){
								Thongkesoluong(l);
							}
							break;
					case 2: MakeMenuThongKe();
							TextColor(172);
							gotoxy(40,10);
							cout<<"2.Ty le phan loai ket qua hoc tap";
							char et2; et2= getch();
							if(et2==13){
								Thongkexeploai(l);
							}
							break;
					case 3:MakeMenuThongKe();
							TextColor(172);
							gotoxy(40,12);
							cout<<"BACK";
							char et; et= getch();
							if(et==13){
								TextColor(15);
								XoaManHinh();
								MainMenu(l,5);
							}
							break;
	}
		ch= getch();
			if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 3;//dieu khien len
			if (ch == 80 && pos < 3) pos++;
			else if (ch == 80 && pos == 3) pos = 1;//dieu khien xuong
	}
	
}
void MainMenu(List &l,int pos){
TextColor(15);
CursorStatus(25, FALSE);
fflush(stdin);
system("cls");
char ch;
	while( 1) {
	    switch(pos){
		case 1: TextColor(15);
				MakeMainMenu();
				gotoxy(2,5);
				TextColor(30); 
				cout<<"1. Them Ho So Moi";
				char et1;
				et1 = getch();
				if (et1 == 13){
				    if (isEmpty(l)) {
                        NewFileChoise(l);
                    } else {
                        OverWriteDataMenu(l);
                    }
					}	
				
				break;
		case 2: TextColor(15);
				MakeMainMenu();
				gotoxy(2,6);
				TextColor(30); 
				cout<<"2. In Danh Sach";
				char et2;	et2 = getch();
				if (et2 == 13){
					if (!isEmpty(l)) {
					TextColor(15);
                    OutputConsole(l);
                    
                        
						char c; c = getch();
						
                        system("cls");
                        SaveMenu(l);
                      	
                      	
                    }else{
                    	gotoxy(40,10);
						TextColor(14);
						cout<<"Vui long nhap du lieu";
						Sleep(500);
						TextColor(15);
						Deleteline(40,10,25);
					 	MainMenu(l,2);
					}
				}
				break;
		case 3: TextColor(15);
				MakeMainMenu();
				gotoxy(2,7);
				TextColor(30); 
				cout<<"3. Sap Xep";
				char et3; 	et3 = getch();
				if (et3 == 13){
					if(l.head == NULL){
						gotoxy(40,10);
						TextColor(14);
						cout<<"Vui long nhap du lieu";
						Sleep(500);
						TextColor(15);
						Deleteline(40,10,25);
						MainMenu(l,3);
					}else
					SortMenu1(l);
				}
				break;
		case 4: TextColor(15);
				MakeMainMenu();
				gotoxy(2,8);
				TextColor(30);
				cout<<"4. Tim Kiem";
				char et4;	et4 = getch();
				if (et4 == 13){
				    if(!isEmpty(l)){
				    	FindMenu(l);
					}else{
						gotoxy(40,10);
						TextColor(14);
						cout<<"Vui long nhap du lieu";
						Sleep(500);
						TextColor(15);
						Deleteline(40,10,25);
						MainMenu(l,4);
					}
					
				}
				break;
		case 5: TextColor(15);
				MakeMainMenu();
				gotoxy(2,9);
				TextColor(30);
				cout<<"5. Thong Ke"; 
				char et5;	et5 = getch();
				if (et5 == 13){
				   if(!isEmpty(l)){
				    	MenuThongKe(l);
					}else{
						gotoxy(40,10);
						TextColor(14);
						cout<<"Vui long nhap du lieu";
						Sleep(500);
						TextColor(15);
						Deleteline(40,10,25);
						MainMenu(l,4);
					}
				}
				break;
		case 6: TextColor(15);
				MakeMainMenu();
				gotoxy(2,10);
				TextColor(30); 
				cout<<"6. Thoat";
				char et6; 	et6 = getch();
				if (et6 == 13){
				gotoxy(1,26);
				exit(1);}
				break;
		
	}	ch=getch();
		
			if (ch == 72 && pos > 1) pos--;
			else 	if (ch == 72 && pos == 1) pos = 6;//dieu khien len
			if (ch == 80 && pos < 6) pos++;
			else if (ch == 80 && pos == 6) pos = 1;//dieu khien xuong
		
	}
}
