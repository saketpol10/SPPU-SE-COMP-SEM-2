#include<iostream>

using namespace std;

class heap
{
	
	int minh[30];	
	int n;
	public:
	int i;
	void accept();
	void insert(int);
	void up_adjust(int);
	void display();
};

void heap::accept()
{
	int x;
	cout<<"Enter the size of the array : "<<endl;
	cin>>n;
	cout<<"Enter the data of "<<n-1<<" students : "<<endl;
	for(i=1;i<n;i++)
	{
		cin>>minh[i];
		x = minh[i];
		insert(x);
	}
}

void heap::insert(int x)
{
	int m;
	m = minh[0];
	minh[m+1] = x;
	minh[0] = m+1;
	up_adjust(m+1);
}

void heap::up_adjust(int i)
{
	int temp;
	while(i>1 && minh[i]<minh[i/2])
	{
		temp = minh[i];
		minh[i] = minh[i/2];
		minh[i/2] = temp;
		i = i/2;
	}
}

void heap::display()
{
	cout<<"No. of students are : "<<minh[0]<<endl;
	cout<<"Marks of students are : ";
	for(i=1;i<n;i++)
	{
		cout<<"\n"<<minh[i];
	}
	cout<<endl;
	cout<<"Minimum marks are : "<<minh[1];
}

int main()
{
	int ch;
	char ans;
	heap h1;
	do
	{
		cout<<"----------------USER MENU-----------------"<<endl;
		cout<<"Enter 1 for creatying min heap : "<<endl;
		cout<<"Enter your choice ing min heap : "<<endl;
		cout<<"Enter 2 for displa: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				h1.accept();
				break;
			case 2:
				h1.display();
				break;
			default:
				cout<<"Invalid Choice !!! "<<endl;
				break;
		}
		cout<<"Enter y to continue or any other key to exit : "<<endl;
		cin>>ans;
	}
	while(ans=='y');
	return 0;
}