
#include<iostream>

using namespace std;

class heap
{
	
	int maxh[30];	
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
		cin>>maxh[i];
		x = maxh[i];
		insert(x);
	}
}

void heap::insert(int x)
{
	int m;
	m = maxh[0];
	maxh[m+1] = x;
	maxh[0] = m+1;
	up_adjust(m+1);
}

void heap::up_adjust(int i)
{
	int temp;
	while(i>1 && maxh[i]>maxh[i/2])
	{
		temp = maxh[i];
		maxh[i] = maxh[i/2];
		maxh[i/2] = temp;
		i = i/2;
	}
}

void heap::display()
{
	cout<<"No. of students are : "<<maxh[0]<<endl;
	cout<<"Marks of students are : ";
	for(i=1;i<n;i++)
	{
		cout<<"\n"<<maxh[i];
	}
	cout<<endl;
	cout<<"Maximum marks are : "<<maxh[1];
}

int main()
{
	int ch;
	char ans;
	heap h1;
	do
	{
		cout<<"----------------USER MENU-----------------"<<endl;
		cout<<"Enter 1 for creating max heap : "<<endl;
		cout<<"Enter 2 for displaying max heap : "<<endl;
		cout<<"Enter your choice : "<<endl;
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