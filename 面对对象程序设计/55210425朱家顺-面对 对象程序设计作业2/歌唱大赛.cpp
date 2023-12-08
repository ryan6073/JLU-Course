#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Singer{
	string name;//���� 
	int number;//��� 
	static int sum;//������ 
	float fraction;//����
	int fraction1;//��ί1��� 
	int fraction2;//��ί2��� 
	int fraction3;//��ί3��� 
public:
	  bool operator <(const Singer b)const { return ((*this).show_fraction() < (b.show_fraction())); }
	void Print()const{
		  cout <<number<<"��ѡ��"<<name<<"Ŀǰƽ���÷�Ϊ��"<<fraction<<endl; 
	  }
	static int print_Numbernow() { return sum; }//����2����ӡ��ǰ�ѳ������� 
	Singer(string nam,float f1,float f2,float f3)
	{
		name=nam;
		fraction1=f1;
		fraction2=f2;
		fraction3=f3;
		fraction=(float)(f1+f2+f3)/3;
		char buf[10];
        sprintf(buf, "%.2f", fraction);
        sscanf(buf, "%f", &fraction);//�����е�С���⣬������������ 
		sum++;
		number=sum;
	}
	  float show_fraction()const { return fraction; }
};

int Singer::sum=0;
void print_Most(vector<Singer>x){
		vector<Singer> ans_max;
		float max=0;
		for (int i = 0; i < x.size(); i++) {
			if (max <= x[i].show_fraction()) {
				if (max == x[i].show_fraction())
					ans_max.push_back(x[i]);//����ͬ�ȷ�����
				else {
					max = x[i].show_fraction();
					ans_max.clear();
					ans_max.push_back(x[i]);
				}
			}
		}
		cout<<"��ǰ��߷�ѡ���У�"<<endl; 
		for (int i = 0; i < ans_max.size(); i++) { ans_max[i].Print(); }
		
		vector<Singer> ans_min;
		float min = 99;
		for (int i = 0; i < x.size(); i++) {
			if (min >= x[i].show_fraction()) {
				if (min == x[i].show_fraction())
					ans_min.push_back(x[i]);//����ͬ�ȷ�����
				else {
					min = x[i].show_fraction();
					ans_min.clear();
					ans_min.push_back(x[i]);
				}
			}
		}
		cout<<endl<<"��ǰ��ͷ�ѡ���У�"<<endl; 
		for (int i = 0; i < ans_min.size(); i++)  ans_min[i].Print();			
}//����1����ӡ��ǰ��߷֡���ͷ�����



void print_All_Byfraction(vector<Singer>x){
		priority_queue<Singer, vector<Singer>,less<Singer> > target;//���ս������еķ�ʽ����һ�����ݽṹ
		for (int i = 0; i < x.size(); i++) {
			target.push(x[i]);//�����ͬʱ��������<�����Զ�����
		}
		while (target.size()) {
			target.top().Print();//����ͷ��
			target.pop();//����ͷ��
		}	
}//����3������ƽ�����ɸߵ��ʹ�ӡ�ѳ���ѡ������ 

int main(){
	system("color 71");
	vector<Singer> riv;
	int button=1; int sum=0; int button2=0;
	cout<<"��ӭ�������ִ����ֳ��������1λѡ�ֵǳ���"<<endl;
		string nam;
		int f1, f2, f3;
		cout<<"��ֱ������"<<sum+1<<"λѡ�ֵ�   ����\t��λ��ί�Ĵ��"<<endl; 
		cin>>nam>>f1>>f2>>f3;
	Singer one( nam, f1, f2, f3);
	riv.push_back(one); 
	sum++;
	

	while(button){
		cout<<"���������蹦��:(��������)"<<endl
			<<"1.��ӡ��ǰ��߷֡���ͷ�ѡ������"<<endl
			<<"2.��ӡ�ѳ�������"<<endl
			<<"3.����ƽ�����ɸߵ��ʹ�ӡ�ѳ���ѡ������"<<endl
			<<"4.��������"<<endl; //"4.������һλѡ�ֵǳ�"
		cin>>button;
		system("pause&&cls");
		switch(button){
		case 1: print_Most(riv); break;
		case 2: cout<<sum<<endl; break;
		case 3: print_All_Byfraction(riv); break;
		case 4:{
			cout<<"��������μ���������"<<endl
			    <<"1.�����ǳ����˳�����"<<endl
				<<"2.������һλѡ�ֵǳ�"<<endl;
			cin>>button2;
			if(button2==1) return 0;
			else if(button2==2){
				string nam;
				int f1, f2, f3;
				cout<<"��ֱ������"<<sum+1<<"λѡ�ֵ�   ����\t��λ��ί�Ĵ��"<<endl; 
				cin>>nam>>f1>>f2>>f3;
				Singer one( nam, f1, f2, f3);
				riv.push_back(one); 
				sum++; 
			}
			else {
				cout<<"�����������������"<<endl;
				cout<<"��������μ���������"<<endl
			    	<<"1.�����ǳ����˳�����"<<endl
					<<"2.������һλѡ�ֵǳ�"<<endl;
				cin>>button2; continue;
			}	 
			break;
		}
		default:{
			cout<<"�����������������룺"<<endl;
			continue;
		}
		
	}
	system("pause&&cls");

	}
	return 0;		
	} 

