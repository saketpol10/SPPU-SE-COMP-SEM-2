#include <iostream>
#include <fstream>
using namespace std;
class student
{
public:
int rollno;
char div;
char name[10];
char address[10];
void getdata();
void displaydata();
int retrollno();
};
void student::getdata()
{
cout<<"Enter the division : ";
cin>>div;
cout<<"Enter the Roll No : ";
cin>>rollno;
cout<<"Enter the Name : ";
cin>>name;
cout<<"Enter the address : ";
cin>>address;
}
void student::displaydata()
{
cout<<" "<<div<<" "<<rollno<<" "<<name<<" "<<address<<endl;
}

int student::retrollno()
{
return rollno;
}
void writeRecord()
{
ofstream fobj;
fobj.open("studentInfo.txt",ios::out | ios::app);
student s1;
s1.getdata();
fobj <<s1.rollno <<endl;
fobj << s1.name <<endl;
fobj << s1.div <<endl;
fobj << s1.address <<endl;
fobj.close();
}
void displayRecords()
{
ifstream fobj;
fobj.open("studentInfo.txt", ios::in);
student s1;
while (!fobj.eof())
{
fobj >> s1.rollno;
fobj >> s1.name;
fobj >> s1.div;
fobj >> s1.address;
s1.displaydata();
}
fobj.close();
}
void searchRecord(int rollno)
{
bool flag=false;
ifstream fobj;
fobj.open("studentInfo.txt", ios::in);
student s1;
while (!fobj.eof())
{
fobj >> s1.rollno;
fobj >> s1.name;
fobj >> s1.div;
fobj >> s1.address;
if(s1.retrollno()==rollno)
{

flag = true;
s1.displaydata();
fobj.close();
return;
}
}
if(flag!=true)
{
cout<<"Entry not found !"<<endl;
}
fobj.close();
}
int main()
{
student s();
int rollno;
int ch;
do{
cout<<"1.ADD RECORD\n2.DISPLAY RECORDS\n3.SEARCH RECORD\n4.EXIT"<<endl;
cout<<"Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
writeRecord();
break;
case 2:
displayRecords();
break;
case 3:
cout<<"Enter roll no of the student to be searched : ";
cin>>rollno;
searchRecord(rollno);
break;
case 4:
cout<<"Exiting..."<<endl;
break;
}
}while(ch!=5);
return 0;

}