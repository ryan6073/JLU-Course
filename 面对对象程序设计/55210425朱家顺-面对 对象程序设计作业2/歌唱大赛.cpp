#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Singer{
	string name;//姓名 
	int number;//编号 
	static int sum;//总人数 
	float fraction;//分数
	int fraction1;//评委1打分 
	int fraction2;//评委2打分 
	int fraction3;//评委3打分 
public:
	  bool operator <(const Singer b)const { return ((*this).show_fraction() < (b.show_fraction())); }
	void Print()const{
		  cout <<number<<"号选手"<<name<<"目前平均得分为："<<fraction<<endl; 
	  }
	static int print_Numbernow() { return sum; }//功能2：打印当前已出场人数 
	Singer(string nam,float f1,float f2,float f3)
	{
		name=nam;
		fraction1=f1;
		fraction2=f2;
		fraction3=f3;
		fraction=(float)(f1+f2+f3)/3;
		char buf[10];
        sprintf(buf, "%.2f", fraction);
        sscanf(buf, "%f", &fraction);//这里有点小问题，不能四舍五入 
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
					ans_max.push_back(x[i]);//若有同等分数的
				else {
					max = x[i].show_fraction();
					ans_max.clear();
					ans_max.push_back(x[i]);
				}
			}
		}
		cout<<"当前最高分选手有："<<endl; 
		for (int i = 0; i < ans_max.size(); i++) { ans_max[i].Print(); }
		
		vector<Singer> ans_min;
		float min = 99;
		for (int i = 0; i < x.size(); i++) {
			if (min >= x[i].show_fraction()) {
				if (min == x[i].show_fraction())
					ans_min.push_back(x[i]);//若有同等分数的
				else {
					min = x[i].show_fraction();
					ans_min.clear();
					ans_min.push_back(x[i]);
				}
			}
		}
		cout<<endl<<"当前最低分选手有："<<endl; 
		for (int i = 0; i < ans_min.size(); i++)  ans_min[i].Print();			
}//功能1：打印当前最高分、最低分属性



void print_All_Byfraction(vector<Singer>x){
		priority_queue<Singer, vector<Singer>,less<Singer> > target;//按照降序排列的方式创建一个数据结构
		for (int i = 0; i < x.size(); i++) {
			target.push(x[i]);//插入的同时根据重载<符号自动排序
		}
		while (target.size()) {
			target.top().Print();//返回头部
			target.pop();//弹出头部
		}	
}//功能3：按照平均分由高到低打印已出场选手属性 

int main(){
	system("color 71");
	vector<Singer> riv;
	int button=1; int sum=0; int button2=0;
	cout<<"欢迎来到歌手大奖赛现场，有请第1位选手登场："<<endl;
		string nam;
		int f1, f2, f3;
		cout<<"请分别输入第"<<sum+1<<"位选手的   姓名\t三位评委的打分"<<endl; 
		cin>>nam>>f1>>f2>>f3;
	Singer one( nam, f1, f2, f3);
	riv.push_back(one); 
	sum++;
	

	while(button){
		cout<<"请输入所需功能:(输入数字)"<<endl
			<<"1.打印当前最高分、最低分选手属性"<<endl
			<<"2.打印已出场人数"<<endl
			<<"3.按照平均分由高到低打印已出场选手属性"<<endl
			<<"4.继续比赛"<<endl; //"4.有请下一位选手登场"
		cin>>button;
		system("pause&&cls");
		switch(button){
		case 1: print_Most(riv); break;
		case 2: cout<<sum<<endl; break;
		case 3: print_All_Byfraction(riv); break;
		case 4:{
			cout<<"请输入如何继续比赛："<<endl
			    <<"1.结束登场，退出比赛"<<endl
				<<"2.有请下一位选手登场"<<endl;
			cin>>button2;
			if(button2==1) return 0;
			else if(button2==2){
				string nam;
				int f1, f2, f3;
				cout<<"请分别输入第"<<sum+1<<"位选手的   姓名\t三位评委的打分"<<endl; 
				cin>>nam>>f1>>f2>>f3;
				Singer one( nam, f1, f2, f3);
				riv.push_back(one); 
				sum++; 
			}
			else {
				cout<<"输入错误，请重新输入"<<endl;
				cout<<"请输入如何继续比赛："<<endl
			    	<<"1.结束登场，退出比赛"<<endl
					<<"2.有请下一位选手登场"<<endl;
				cin>>button2; continue;
			}	 
			break;
		}
		default:{
			cout<<"输入有误，请重新输入："<<endl;
			continue;
		}
		
	}
	system("pause&&cls");

	}
	return 0;		
	} 

