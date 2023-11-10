#include<iostream>

using namespace std;

class graph
{
	int m[20][20];
	int visited[20];
	int n;
	public:
	void accept();
	void display();
	void bfs(int);
	int returnN()
	{
		return n;
	}
};

class queue
{
	int que[20];
	int front,rear;
	public:
	queue()
	{
		front = -1;
		rear = -1;	
	}	
	bool is_empty()
	{
		if((rear==-1) || (front>rear))
		return true;
		else
		return false;
	}
	void enque(int);
	int deque();
};

void queue::enque(int i)
{
	if(front==-1)
		front++;
	que[++rear]=i;
}

int queue::deque()
{
	return que[front++];
}

void graph::accept()
{
	cout<<"Enter the number of vertices : "<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	cout<<"Enter the adjacency matrix : "<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>m[i][j];
		}
	}
}

void graph::display()
{
	cout<<"The adjacency matrix is : "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
		{
			cout<<"\t"<<m[i][j];
		}
	}
	cout<<endl;
}

void graph::bfs(int v)
{
	queue q;
	visited[v]=1;
	cout<<"\n"<<v;
	q.enque(v);
	while(!q.is_empty())
	{
		v=q.deque();
		for(int j=1;j<=n;j++)
		{
			if(m[v][j]==1)
			{
				if(visited[j]==0)
				{
					q.enque(j);
					visited[j]=1;
					cout<<"\n"<<j;
				}
			}
		}
	}
}

int main()
{
	graph g;
	int ch;
	char ans;
	do
	{
		cout<<"---------------------USER MENU---------------------"<<endl;
		cout<<"Enter 1 to accept : "<<endl;
		cout<<"Enter 2 to display : "<<endl;
		cout<<"Enter 3 to perform non-recursive bfs : "<<endl;
		cout<<"Enter your choice  : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.accept();
				break;
			case 2:
				g.display();
				break;
			case 3:
				int start;
				cout<<"Breadth first display of vertices is : "<<endl;
				g.bfs(1);
				cout<<endl;
				break;
			default:
				cout<<"Invalid choice !!! "<<endl;	
		}
		//cout<<endl;
		cout<<"Enter y to continue or any key to exit : "<<endl;
		cin>>ans;
	}
	while(ans=='y');
	return 0;
}
