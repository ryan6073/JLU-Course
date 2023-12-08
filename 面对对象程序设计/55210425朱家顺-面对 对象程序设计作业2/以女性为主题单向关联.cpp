//改为以女性为主体单向关联 ,数组管理，最多容纳一百名女性主体 
#include<iostream>
using namespace std;
class Male;
class Female{
public:
	Female() { m_buffer[m_sum++]=this;}
	Male* &getHusband() { return pHusband;}
	static Female* m_buffer[100];
	static int m_sum;
private:
	Male* pHusband; 
};
int Female::m_sum=0;
Female* Female::m_buffer[100]={0};
class Male{
public:
	Female* getWife();
};
Female* Male::getWife(){
	for(int i=0;i<Female::m_sum;i++)
	  if(Female::m_buffer[i]->getHusband()==this)
	    return Female::m_buffer[i];
	return 0;
}
int main(){
	Male a,b;
	Female c,d;
    c.getHusband()=&a;
	d.getHusband()=&b;
	return 0;
}
