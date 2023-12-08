#include<iostream>
using namespace std; 
class person
{
	float money; int month;
public:
	float& aaa() { return(money); }
	int& bbb() { return(month); }
	person& operator ++();
	person& operator *();
	person& operator --();
	operator float(); 
	operator double();
};
person& person::operator ++() {
	money = money + 10000;
	month = month + 1;
	return(*this);
}//正常工作结算 
person::operator float(){return (money);
}
person::operator double(){return (month);
}
person& person::operator *(){
	money = money + 15000;
	month = month + 1;
	return (*this);
}//加班月工作结算 
person& person::operator --() {
	cout<<money*0.95<<"    支出所有工资（扣除税费）"<<endl;
	money=0;
	return (*this);
}//支出所有工资 
int  main() {
	
	system("color 71");

	person a;
	a.aaa() = 0; a.bbb() = 0;
	cout << (++a).aaa() <<"    正常工作一个月积累工资(重载运算符++)"<< endl;
	(--a);
	cout<<a.aaa()<<"    支出工资后工资余额"<<endl;
	cout<<float(a)<<"    重载运算符float用于查找剩余工资"<<endl;
	cout<<double(a)<<"    重载运算符double用于查找工作月数"<<endl;
	cout<<(*a).aaa()<<"    加班工作一个月积累工资(重载运算符*)"<<endl;
	(--a); 
	cout<<a.aaa()<<"    支出工资后工资余额"<<endl;
	cout<<float(a)<<"    重载运算符float用于查找剩余工资"<<endl;
	cout<<double(a)<<"    重载运算符double用于查找工作月数"<<endl;
	return 0;
}
//前引用，后对象 

