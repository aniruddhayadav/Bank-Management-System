#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<conio.h>
class Bank
{
	int acno;
	char name[20],type[20];
	int bal;
	public:
		void puts();
		void delect_account(int);
		void intro();
		void choice();
		void add_account();
		void getdata();
		void deposite(int);
		void deposites();
		void withdraw(int);
		void withdrawal();
		void list();
		int reacno();
};
void Bank::deposite(int n)
{bal+=n;}
void Bank::withdraw(int n)
{bal-=n;}
int Bank::reacno()
{return acno;}
void Bank:: withdrawal()
{
	Bank b;
	fstream file;
	int mrno=0,w;
	int recsize=sizeof(Bank);
	clrscr();
	file.open("data.dat",ios::in|ios::out|ios::binary);
	if(!file)
	{
		cout<<"FILE OPEN ERROR  ";getch();return;}
		file.seekg(ios::beg);
		list();
		cout<<"\n\tEnter account number\n";
		cin>>mrno;
		while(file.read((char*)&b,recsize))
		{
			if(b.reacno()==mrno)
			{
				cout<<"\n\tEnter the amount to be Withdrawed::Rs ";
				cin>>w;
				b.withdraw(w);
				file.seekg(-1*recsize,ios::cur);
				file.write((char*)&b,recsize);
			}
		}
		cout<<"\n\tTransection Complet";
		file.close();
		getch();
}
void Bank::deposites()
{
  Bank b;
  fstream file;
  int mrno=0, w;
  int recsize=sizeof(Bank);
  clrscr();
  file.open("data.dat",ios::in|ios::out|ios::binary);
  if(!file)
  {
  cout<<"\nFILE OPEN ERROR  ";getch();return;}
  file.seekg(ios::beg);
  list();
  cout<<"\nEnter Account Number";
  cin>>mrno;
  while(file.read((char*)&b,recsize))
  {
	  if(b.reacno()==mrno)
  {
  cout<<"\nEnter the Amount to be Diposited ::Rs ";
  cin>>w;
  b.deposite(w);
  file.seekg(-1*recsize,ios::cur);
  file.write((char*)&b,recsize);
  }
  }
  cout<<"\n\tTransection Complet";
  getch();
  file.close();
}

void Bank::delect_account(int n)
{
	fstream file ;
	file.open("data.dat", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(Bank)) ;
		if ( file.eof() )
			break ;
		if ( acno != n )
			temp.write((char *) this, sizeof(Bank)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("data.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(Bank)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(Bank)) ;

	}
	cout<<"\n\n\t\tRecord Delected";
	delay(666);
	file.close() ;
	temp.close() ;}
void Bank::add_account(void)
{
	Bank b;
	ofstream file;
	file.open("data.dat",ios::in|ios::app);
	char op;
	do
	{
		b.getdata();
		file.write((char *)&b,sizeof(Bank));
		cout<<"One row created\n";
		cout<<"ADD new record[Y|N]";
		cin>>op;
	}while (op=='y'||op=='Y');
	file.close();
}
void Bank::getdata(void)
{
	cout<<"Enter The AC no =";cin>>acno;
	cout<<"Enter The Name ="; cin>>name;
	cout<<"Enter The Type (S/C) =";cin>>type;
	cout<<"Enter the Intial Amount =";cin>>bal;
}
void Bank::list(void)
{
	Bank b;
	char a;
	ifstream file("data.dat",ios::in);
	file.read((char *)&b,sizeof(Bank));
	cout<<"-------------------------------------------\n";
	cout<<" AC No.\t Name  \t\tType \t   Amount\n";
	cout<<"-------------------------------------------\n";
	while(!file.eof())
	{
		b.puts();
		file.read((char *)&b,sizeof(Bank));
		cout<<"\n";
	}
	file.close();
	cout<<"Enter Y to Move Forward :-";
	cin>>a;
}
void Bank::puts(void)
{
	cout<<" "<<acno<<"\t "<<name<<"  \t  "<<type<<"  \t  "<<bal<<"  \n  ";
}
void Bank::choice(void)
{
	clrscr();
	int a,no;
	cout<<"\n\n\n\t\t\tEnter Your Choice";
	cout<<"\n\n\t\t\t1) Add Account";
	cout<<"\n\n\t\t\t2) Deposit Amount";
	cout<<"\n\n\t\t\t3) Withdraw Amount";
	cout<<"\n\n\t\t\t4) Show List";
	cout<<"\n\n\t\t\t5) Delect Account";
	cout<<"\n\n\t\t\t6) Exit"<<endl;
	cout<<"\n\n\n\t\tEnter Your Choice::";
	cin>>a;
	switch(a){
	case 1: clrscr();
			add_account();
			choice();
			break;
	case 2: clrscr();
			deposites();
			choice();
			break;
	case 3: clrscr();
			withdrawal();
			choice();
			break;
	case 4: clrscr();
			list();
			choice();
			break;
	case 5: clrscr();
			cout<<"\n\n\t\tEnter the Account no:";cin>>no;
			delect_account(no);
			choice();
			break;
	case 6: clrscr();
			char a=1,b=4;
			textbackground(3);
	textcolor(BLACK);
	gotoxy(23,11);cprintf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	textcolor(BLACK+BLINK);
	gotoxy(30,12);cprintf("\t\t\t\t--Thank You--\t\t\t\t");
	textcolor(BLACK);
	gotoxy(23,13);cprintf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b);
			break;
	default:
			clrscr();
			cout<<"Enter Wrong Choice";
			choice();
			break;
	
	}
}
void Bank::intro(void)
{
	clrscr();
	char a;
	textcolor(BLACK+BLINK);
	textbackground(CYAN);
	gotoxy(12,11);
	cprintf("====================================================");
	gotoxy(24,12);
	cprintf("\t\t\t\t-WELCOME TO BANK-\t\t\t\t");
	gotoxy(12,13);
	cprintf("====================================================");
	textcolor(WHITE);textbackground(BLACK);
	gotoxy(25,20);
	cout<<"Enter Y To Main Menu :-";
	cin>>a;
	clrscr();
	if(a=='y'||a=='Y')
	{
	choice();
	}
}
void main()
{
	Bank b;
	b.intro();
	getch();
}
