#include<iostream>
using namespace std;
//�����ݴ��淽ʽ��Ϊ���У���ͷָ�������������ѻ���ʿ�����й������Ա�� 
class Female;
class Male{
public:
	Male();
	Female* &getwife() { return pWife;}
	static Male* pFirst;
	Male* pNext;
private:
	Female* pWife; 
};
Male* Male::pFirst=NULL;
Male::Male(){
	pNext=pFirst;
	pFirst=this; 
}
class Female{
public:
	static Male* pMove;
	Male* getHusband();
};
Male* Female::pMove=Male::pFirst;
Male* Female::getHusband(){
	
 	if(pMove->getwife()==this){
 		return pMove;
	 }
	for(Male* pS=pMove;pS;pS=pS->pNext){
		if(pS->pNext->getwife()==this){
			return pS->pNext; 
		}
	}
	return 0;
}
int main(){
	Male a,b;
	Female c,d;
	a.getwife()=&c;
	
	return 0;
}
