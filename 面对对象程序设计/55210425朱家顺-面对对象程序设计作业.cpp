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
}//������������ 
person::operator float(){return (money);
}
person::operator double(){return (month);
}
person& person::operator *(){
	money = money + 15000;
	month = month + 1;
	return (*this);
}//�Ӱ��¹������� 
person& person::operator --() {
	cout<<money*0.95<<"    ֧�����й��ʣ��۳�˰�ѣ�"<<endl;
	money=0;
	return (*this);
}//֧�����й��� 
int  main() {
	
	system("color 71");

	person a;
	a.aaa() = 0; a.bbb() = 0;
	cout << (++a).aaa() <<"    ��������һ���»��۹���(���������++)"<< endl;
	(--a);
	cout<<a.aaa()<<"    ֧�����ʺ������"<<endl;
	cout<<float(a)<<"    ���������float���ڲ���ʣ�๤��"<<endl;
	cout<<double(a)<<"    ���������double���ڲ��ҹ�������"<<endl;
	cout<<(*a).aaa()<<"    �Ӱ๤��һ���»��۹���(���������*)"<<endl;
	(--a); 
	cout<<a.aaa()<<"    ֧�����ʺ������"<<endl;
	cout<<float(a)<<"    ���������float���ڲ���ʣ�๤��"<<endl;
	cout<<double(a)<<"    ���������double���ڲ��ҹ�������"<<endl;
	return 0;
}
//ǰ���ã������ 

