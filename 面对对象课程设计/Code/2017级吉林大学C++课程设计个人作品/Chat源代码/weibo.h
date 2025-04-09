#pragma once
#ifndef WEIBO_H
#define WEIBO_H
#include"qq.h"
#include<string>
#include<vector>

class WeiBo_CHC : public Tencent_CHC
{

	WeiBo_CHC(string qq) { LinkedQQ = qq; }




private:

	string LinkedQQ;

	vector<string> WeiBoContent;

};
#endif