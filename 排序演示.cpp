#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <shellapi.h> 
using namespace std;
int a[200],aa[200],n;
int cn=0,mn=0,T=1,nn=0;//����������� 
int hcn,hmn,H=1,md=0,mdd=0,dui_p=0;

string s="D:/a_kuaipai.txt";
string s1="D:/a_kuaipai_n.txt";
string s2="D:/a_kuaipai_num.txt";
string s3="D:/a_duipai.txt";

string s5="D:/a_duipai_num.txt";
ofstream out3(s2.c_str(),ios::out);
ofstream out1(s.c_str(),ios::out);
ofstream out2(s1.c_str(),ios::out);
ofstream out4(s3.c_str(),ios::out);

ofstream out6(s5.c_str(),ios::out);

int menu();
void print_a();
void init_a();
void select();
void to_text();
void maopao();
void jiandan();
void zhicha();
void shell();
void zheban();
void kuaipaiex();
void qs2(int l,int r);
int partition2(int l,int r);
void fswap(int i, int j);
void duipai();
void hs();
void hadjust(int s,int n);
void print_aa();
void print_aa_text(string s);
void num_text(int a,string s);
void open_exe(); 

int main()
{
	srand(111);
	init_a();
	to_text(); 
	select();
}
int menu()
{
	cout<<"��ѡ��������ݻ����Լ���������?"<<endl;
	cout<<"1.ѡ��ϵͳ���ɵ�8�������"<<endl;
	cout<<"2.�Լ��������������"<<endl;
	cout<<"3.ѡ����������1-8"<<endl;
	cout<<"4.ѡ��������8-1"<<endl;
	int sel;
	cin>>sel;
	return sel; 
}
void print_a()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
void init_a()
{
	int sel=menu();
	n=8;
	if(sel==1)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=rand()%100;
		}
	}
	else if(sel==2)
	{
		cout<<"��������������ݸ���"<<endl;
		cin>>n;
		cout<<"��˳�����������"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	}
	else if(sel==3)
	{
		//cout<<'@'<<endl;
		for(int i=0;i<n;i++)
		{
		//	cout<<"#"<<endl;
			a[i]=i+1;
			//cout<<a[i]<<endl;
		}
	}
	else if(sel==4)
	{
		//cout<<"@"<<endl;
		for(int i=0;i<n;i++)
		{
			a[i]=8-i;
		}
	}
	cout<<"����ʵ����ʹ�õ�����Ϊ��"<<endl;
	print_a(); 
	cout<<"������֧�����µ����򷽷���ʾ"<<endl;
}
void open_exe()//�򿪳��� 
{
	cout<<"������......"<<endl;
	Sleep(200);//����ʱ�� 
	ShellExecute(NULL, "open", "D:\\lan_qiao\\qq����\\�����廯\\�����廯\\bin\\Debug\\�����廯.exe",NULL, NULL,SW_SHOW );//����#include <windows.h>��#include <shellapi.h> 
}
void select()
{
	cout<<"1.ð������"<<endl;
	cout<<"2.�۰�����"<<endl; 
	cout<<"3.ϣ������"<<endl;
	cout<<"4.ֱ�Ӳ�������"<<endl;
	cout<<"5.��ѡ������"<<endl;
	cout<<"6.��������"<<endl;
	cout<<"7.������"<<endl;
	cout<<"8.���򷽷�ʱ��Ƚ�"<<endl;
	cout<<"9.�����ȶ���"<<endl;
	cout<<"ϵͳ������......"<<endl;
	Sleep(200);
	open_exe();
}
void to_text()
{
	maopao();
	jiandan(); 
	zhicha();
	shell();
	zheban();
	kuaipaiex(); 
	duipai();
}
void hadjust(int s,int n)//sΪ�����Ľڵ��±� 
{
	int i,j;
	int temp;
	for(i=s;2*i+1<n;i=j)
	{
		//cout<<i<<endl;
		out6<<i<<endl;
		j=2*i+1;//���ӽڵ� 
		if((j<n-1)&&(aa[j]<aa[j+1]))//j<n-1�ж��Ƿ��������� 
		{
			j++;
			hcn++;
		}//ȷ���ӽڵ������ 
		if(aa[i]<aa[j])
		{
			temp=aa[i];
			aa[i]=aa[j];
			aa[j]=temp;//�������Ƿ��ӽڵ���� 
			hcn++;
			hmn++;
			//cout<<"#";
			//print_aa();
			print_aa_text(s3);
			if(dui_p==0)
				md++;
			else
				mdd++;
		}
		else
		{
			//cout<<"@";
			//print_aa();
			print_aa_text(s3);
			if(dui_p==0)
				md++;
			else
				mdd++;
			break;
		}
			
		
	}
}
void hs()
{
	int temp;
	for(int i=n/2-1;i>=0;i--)//��ȫ�������ĵ�һ����Ҷ�ӽڵ� 
	{
		hadjust(i,n);
		//cout<<"��"<<H++<<"������Ľ��Ϊ:  ";
		//print_aa();
	}
	dui_p=1;
	
	for(int i=n-1;i>0;i--)//�����ʼ�ݼ� 
	{
		temp=aa[i];
		aa[i]=aa[0];
		aa[0]=temp;//�����һ��ǰ����ͷ��� 
		hmn++;
		out6<<i*10<<endl;
		//cout<<'$';
		//print_aa();
		print_aa_text(s3);
		if(dui_p==0)
			md++;
		else
			mdd++;
		hadjust(0,i);//���Ʋ�����i 
	//	cout<<"��"<<H++<<"������Ľ��Ϊ:  ";
		//print_aa();
	}
}
void duipai()
{
	string s4="D:/a_duipai_n.txt";
	ofstream out5(s4.c_str(),ios::out);
	hcn=0;
	hmn=0;
	T=1;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	//print_aa();
	print_aa_text(s3);
	md++;
	hs();
	//cout<<"����Ƚϴ���: "<<hcn<<"  �����ƶ������� "<<hmn<<endl; 
	//cout<<md<<endl;
	out5<<md<<endl;
	out5<<mdd<<endl;
	out4.close();
	out5.close();
	out6.close();
}
void fswap(int i, int j)
{
	int temp;
	temp = aa[i];
	aa[i] = aa[j];
	aa[j] = temp;
	mn++;
	//cout<<'@'; 
	//print_aa();
}
int partition2(int l,int r)//6 1 2 7 9 3 4 8
{	
	int t=1,p=1;
	//	out1.close();
	//cout<<'#'<<l<<' '<<r<<endl; 
	int ll=l;
	//l++;
	int pivokey=aa[l];//��׼�� 
	
	while(l<r)//��û������ʱ 
	{//ÿ�ζ����ұߵ����� 
		if(p==1)
		{
			t=1;
			p=0;
			out2<<l<<' '<<r<<endl;
		}
		else
			t=0;
		
		while(l<r&&aa[r]>=pivokey)
		{
			r--;
			cn++;
			t++;
			//cout<<l<<' '<<r<<endl;
			out2<<l<<' '<<r<<endl;
		}//�ҵ�һ���Ȼ�׼��С�� 
		//fswap(l,r);
		while(l<r&&aa[l]<=pivokey)
        {
			l++;
			cn++;
			t++;
			//cout<<l<<' '<<r<<endl;
			out2<<l<<' '<<r<<endl;
        }
		fswap(l,r);
		//cout<<t<<endl;
		out3<<t<<endl;
		nn++;
		t=0;	
		//cout<<"��"<<T++<<"������Ľ��Ϊ:  ";
		//cout<<'#';
		//print_aa();
		print_aa_text(s);
	}
	fswap(ll,l);
	//cout<<"��"<<T++<<"������Ľ��Ϊ:  ";
	//	print_aa();
	return l;//���ػ�׼������λ��
	
}
void qs2(int l,int r)
{
	int pivot;
	if(l<r)
	{
		pivot=partition2(l,r);//����
		qs2(l,pivot-1);//�������ֽ������� 
		qs2(pivot+1,r);
	}
	
}
void kuaipaiex()
{
	string ss="D:/a_kuaipai_nn.txt";
	ofstream out4(ss.c_str(),ios::out);
	cn=0;
	mn=0;
	T=1;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	print_aa_text(s);
	qs2(0,n-1);	
	//cout<<"����Ƚϴ���: "<<cn<<"  �����ƶ������� "<<mn<<endl; 
	//print_aa();
	print_aa_text(s);
	//cout<<nn<<endl; 
	out4<<nn<<endl;
	out1.close();
	out2.close();
	out3.close();
	out4.close();
}
void zheban()
{
	string s="D:/a_zheban.txt";
	string s1="D:/a_zheban_n.txt";
	string s2="D:/a_zheban_num.txt";
	ofstream out(s.c_str(),ios::out);
	ofstream out2(s1.c_str(),ios::out);
	ofstream out3(s2.c_str(),ios::out);
	out.close();
	int num=1;
	int comnum=0,movnum=0;
	int temp;
	int l,m,r;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	//cout<<"��ǰ����������г���Ϊ: "<<n<<endl;
	for(int i=1;i<n;i++)
	{
		l=0;
		r=i-1;//��ǰ��������Ϊ0-0,m=0 
		temp=aa[i];
		m=0;
		while(l<=r)//l==rΪ�������뵱ǰ����ͬʱ 
		{
			m=(l+r)/2;
			//cout<<l<<' '<<m<<' '<<r<<endl;
			out2<<l<<' '<<r<<' '<<m<<endl;
			if(temp<aa[m])
				r=m-1;
			//else if(temp>aa[m])
			else
				l=m+1;
			comnum++;
			//print_aa();
			print_aa_text(s);
			
		}
		for(int j=i;j>l;j--)
			aa[j]=aa[j-1];
		aa[l]=temp;
		movnum++;
		//cout<<"��"<<num++<<"������Ľ��Ϊ:  ";
		//print_aa();
		
	}
	//cout<<"����Ƚϴ���: "<<comnum<<"  �����ƶ������� "<<movnum<<endl; 
	out3<<comnum<<endl;
	print_aa_text(s);

}
void shell()
{
	string s="D:\\a_shell.txt";
	string s1="D:/a_shell_n.txt";
	ofstream out(s.c_str(),ios::out);
	ofstream out2(s1.c_str(),ios::out);
	out.close();
	int num=1;
	int comnum=0,movnum=0;
	int temp;
	int k,dk,t;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	for(dk=n/2;dk>0;dk=dk/2)
	{
		for(int i=0;i<dk;i++)
		{
			t=0;
			for(int j=i+dk;j<n;j=j+dk)
			{
				
				if(aa[j]<aa[j-dk])
				{
					temp=aa[j];
					k=j-dk;
					while(k>=0&&aa[k]>temp)
					{
						aa[k+dk]=aa[k];
						k-=dk;
					}
					aa[k+dk]=temp;
					movnum++;
				}
				//print_aa();
				print_aa_text(s);
				comnum++;
				t++; 
			}
			//cout<<'#'<<t<<endl;
			out2<<t<<endl;
		}
		//cout<<"��"<<num++<<"������Ľ��Ϊ:  ";
		//print_aa();
	}
	//cout<<"����Ƚϴ���: "<<comnum<<"  �����ƶ������� "<<movnum<<endl; 
	out2.close();

}
void zhicha()//3 4 5 2 1 8 7 6
{
	string s="D:\\a_zhicha.txt";
	string s1="D:/a_zhicha_n.txt";
	ofstream out(s.c_str(),ios::out);
	ofstream out2(s1.c_str(),ios::out);
	out.close();
	int num=1,j;
	int comnum=0,movnum=0;
	int temp;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		int c=0;
		print_aa_text(s);
		if(aa[i]<aa[i-1])
		{
			temp=aa[i];
			for(j=i-1;j>=0;j--)
			{
				if(temp<aa[j])
				{
					aa[j+1]=aa[j];
					comnum++;
					c++;
				}
				else
				{
					//cout<<c<<endl;
					//cout<<"#"<<endl;
					
					//print_aa_text(s);
					break;
					comnum++;
				}
				//print_aa();
				print_aa_text(s);
			}
			
			aa[j+1]=temp;
			movnum++;
		}
		else
		{
			//cout<<0<<endl;
			out2<<0<<endl;
			//print_aa_text(s);
			comnum++;
			continue;
		}
		//cout<<c<<endl;
		out2<<c<<endl;
		//cout<<"��"<<num++<<"������Ľ��Ϊ:  ";
		//print_aa_text(s);
		//print_aa();
	}
	print_aa_text(s);
	//cout<<"����Ƚϴ���: "<<comnum<<"  �����ƶ������� "<<movnum<<endl; 
	out2.close();
}
void jiandan()
{
	string s="D:\\a_jiandan.txt";
	ofstream out(s.c_str(),ios::out);
	out.close();
	int num=1,t;
	int comnum=0,movnum=0;
	int temp;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		temp=aa[i];
		t=i;
		for(int j=i+1;j<n;j++)
		{
			if(aa[j]<temp)
			{
				temp=aa[j];
				t=j;
			}
			comnum++;
			//print_aa();
			print_aa_text(s);
		}
		temp=aa[i];
		aa[i]=aa[t];
		aa[t]=temp;//��������С�Ľ����滻
		movnum++; 
		
		//cout<<"��"<<num++<<"������Ľ��Ϊ:  ";
		//print_aa();
	}
	print_aa_text(s);
	//cout<<"����Ƚϴ���: "<<comnum<<"  �����ƶ������� "<<movnum<<endl; 

}
void maopao()
{
	string s="D:\\a_maopao.txt";
	ofstream out(s.c_str(),ios::out);
	out.close();
	int num=1;
	int comnum=0,movnum=0;
	int temp;
	for(int i=0;i<n;i++)
	{
		aa[i]=a[i];
	}
	//cout<<"��ǰ����������г���Ϊ: "<<n<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			comnum++;
			if(aa[j]>aa[j+1])
			{
				temp=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=temp;
				movnum++;
				
			}
			//print_aa();	
			print_aa_text(s);
		} 
		//cout<<"��"<<num++<<"������Ľ��Ϊ:  ";
		//print_aa();
	} 
	//cout<<"����Ƚϴ���: "<<comnum<<"  �����ƶ������� "<<movnum<<endl; 
	num_text(comnum,"D:\\a_maopao_n.txt");
}
void print_aa()
{
	for(int i=0;i<n;i++)
	{
		cout<<aa[i]<<' ';
	}
	cout<<endl;
}
void print_aa_text(string s)
{
	ofstream out(s.c_str(),ios::app);//���ļ� 
	if(!out)
	{
		cout<<"�洢�ļ�����"<<endl;
		exit(1);
	}//�쳣���� 
	for(int i=0;i<n;i++)
	{
		if(i==0)
			out<<aa[i];
		else
			out<<' '<<aa[i];
	}
	out<<endl;
}
void num_text(int a,string s)
{
	ofstream out(s.c_str(),ios::out);//���ļ� 
	if(!out)
	{
		cout<<"��Ŀ�洢�ļ�����"<<endl;
		exit(1);
	}//�쳣���� 
	out<<a<<endl;
}
