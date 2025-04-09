#pragma once
#ifndef GreedySnake_H
#define GreedySnake_H

#include <vector>
#include <deque>
#include"tools.h"


class Snake;
extern class Point;
class Map;
class Snake;
class Food;



class Point

{

public:

	Point()
	{

	}

	Point(const int x, const int y) : x(x), y(y)
	{

	}

	void Print(); //输出■

	void PrintCircular(); //输出●

	void Clear(); //清除输出

	void ChangePosition(const int x, const int y);//改变坐标

	bool operator== (const Point& point) //运算符重载
	{
		return (point.x == this->x) && (point.y == this->y);
	}

	int GetX()
	{
		return this->x;
	}

	int GetY()
	{
		return this->y;
	}

private:

	int x, y;

};

class Map

{

public:

	Map()//默认构造函数，将正方形各点压入initmap

	{

		initmap.emplace_back(Point(1, 1));

		initmap.emplace_back(Point(2, 1));

		initmap.emplace_back(Point(3, 1));

		initmap.emplace_back(Point(4, 1));

		initmap.emplace_back(Point(5, 1));

		initmap.emplace_back(Point(6, 1));

		initmap.emplace_back(Point(7, 1));

		initmap.emplace_back(Point(8, 1));

		initmap.emplace_back(Point(9, 1));

		initmap.emplace_back(Point(10, 1));

		initmap.emplace_back(Point(11, 1));

		initmap.emplace_back(Point(12, 1));

		initmap.emplace_back(Point(13, 1));

		initmap.emplace_back(Point(14, 1));

		initmap.emplace_back(Point(15, 1));

		initmap.emplace_back(Point(16, 1));

		initmap.emplace_back(Point(17, 1));

		initmap.emplace_back(Point(18, 1));

		initmap.emplace_back(Point(19, 1));

		initmap.emplace_back(Point(20, 1));

		initmap.emplace_back(Point(21, 1));

		initmap.emplace_back(Point(22, 1));

		initmap.emplace_back(Point(23, 1));

		initmap.emplace_back(Point(24, 1));

		initmap.emplace_back(Point(25, 1));

		initmap.emplace_back(Point(26, 1));

		initmap.emplace_back(Point(27, 1));

		initmap.emplace_back(Point(28, 1));

		initmap.emplace_back(Point(29, 1));

		initmap.emplace_back(Point(30, 1));

		initmap.emplace_back(Point(1, 2));

		initmap.emplace_back(Point(30, 2));

		initmap.emplace_back(Point(1, 3));

		initmap.emplace_back(Point(30, 3));

		initmap.emplace_back(Point(1, 4));

		initmap.emplace_back(Point(30, 4));

		initmap.emplace_back(Point(1, 5));

		initmap.emplace_back(Point(30, 5));

		initmap.emplace_back(Point(1, 6));

		initmap.emplace_back(Point(30, 6));

		initmap.emplace_back(Point(1, 7));

		initmap.emplace_back(Point(30, 7));

		initmap.emplace_back(Point(1, 8));

		initmap.emplace_back(Point(30, 8));

		initmap.emplace_back(Point(1, 9));

		initmap.emplace_back(Point(30, 9));

		initmap.emplace_back(Point(1, 10));

		initmap.emplace_back(Point(30, 10));

		initmap.emplace_back(Point(1, 11));

		initmap.emplace_back(Point(30, 11));

		initmap.emplace_back(Point(1, 12));

		initmap.emplace_back(Point(30, 12));

		initmap.emplace_back(Point(1, 13));

		initmap.emplace_back(Point(30, 13));

		initmap.emplace_back(Point(1, 14));

		initmap.emplace_back(Point(30, 14));

		initmap.emplace_back(Point(1, 15));

		initmap.emplace_back(Point(30, 15));

		initmap.emplace_back(Point(1, 16));

		initmap.emplace_back(Point(30, 16));

		initmap.emplace_back(Point(1, 17));

		initmap.emplace_back(Point(30, 17));

		initmap.emplace_back(Point(1, 18));

		initmap.emplace_back(Point(30, 18));

		initmap.emplace_back(Point(1, 19));

		initmap.emplace_back(Point(30, 19));

		initmap.emplace_back(Point(1, 20));

		initmap.emplace_back(Point(30, 20));

		initmap.emplace_back(Point(1, 21));

		initmap.emplace_back(Point(30, 21));

		initmap.emplace_back(Point(1, 22));

		initmap.emplace_back(Point(30, 22));

		initmap.emplace_back(Point(1, 23));

		initmap.emplace_back(Point(30, 23));

		initmap.emplace_back(Point(1, 24));

		initmap.emplace_back(Point(30, 24));

		initmap.emplace_back(Point(1, 25));

		initmap.emplace_back(Point(30, 25));

		initmap.emplace_back(Point(1, 26));

		initmap.emplace_back(Point(30, 26));

		initmap.emplace_back(Point(1, 27));

		initmap.emplace_back(Point(30, 27));

		initmap.emplace_back(Point(1, 28));

		initmap.emplace_back(Point(30, 28));

		initmap.emplace_back(Point(1, 29));

		initmap.emplace_back(Point(30, 29));

		initmap.emplace_back(Point(1, 30));

		initmap.emplace_back(Point(2, 30));

		initmap.emplace_back(Point(3, 30));

		initmap.emplace_back(Point(4, 30));

		initmap.emplace_back(Point(5, 30));

		initmap.emplace_back(Point(6, 30));

		initmap.emplace_back(Point(7, 30));

		initmap.emplace_back(Point(8, 30));

		initmap.emplace_back(Point(9, 30));

		initmap.emplace_back(Point(10, 30));

		initmap.emplace_back(Point(11, 30));

		initmap.emplace_back(Point(12, 30));

		initmap.emplace_back(Point(13, 30));

		initmap.emplace_back(Point(14, 30));

		initmap.emplace_back(Point(15, 30));

		initmap.emplace_back(Point(16, 30));

		initmap.emplace_back(Point(17, 30));

		initmap.emplace_back(Point(18, 30));

		initmap.emplace_back(Point(19, 30));

		initmap.emplace_back(Point(20, 30));

		initmap.emplace_back(Point(21, 30));

		initmap.emplace_back(Point(22, 30));

		initmap.emplace_back(Point(23, 30));

		initmap.emplace_back(Point(24, 30));

		initmap.emplace_back(Point(25, 30));

		initmap.emplace_back(Point(26, 30));

		initmap.emplace_back(Point(27, 30));

		initmap.emplace_back(Point(28, 30));

		initmap.emplace_back(Point(29, 30));

		initmap.emplace_back(Point(30, 30));

	}

	void PrintInitmap();//绘制初始地图

private:

	std::vector<Point> initmap;//保存初始地图

							   /*Map类可自定义多种地图，只需将表示地图的各个点保存在相应的map中，并在Snake类中增加相应判断撞墙函数即可

							   std::vector<Point> map1;

							   std::vector<Point> map2;

							   */

};

class Controller

{

public:

	Controller() : speed(200), key(1), score(0)
	{

	}

	void Start();

	void Select();

	void DrawGame();

	int PlayGame();

	void UpdateScore(const int&);

	void RewriteScore();

	int Menu();

	void Game();

	int GameOver();

private:

	int speed;//默认为200

	int key;//默认为1

	int score;//默认为0

};

class Food

{

public:

	Food() : cnt(0), flash_flag(false), big_flag(false), x(0), y(0), big_x(0), big_y(0), progress_bar(0)
	{

	}

	void DrawFood(Snake&);

	void DrawBigFood(Snake&);

	int GetCnt();

	void FlashBigFood();

	bool GetBigFlag();

	int GetProgressBar();

private:

	int cnt; //判断吃到食物个数

	bool flash_flag;//闪烁标记默认为false

	bool big_flag;//是否有限时食物标记默认为false

	int x, y;//默认为0

	int big_x, big_y;//默认为0

	int progress_bar;//限时食物进度条，默认为0

	friend class Snake;

};


class Snake

{

public:

	enum Direction { UP, DOWN, LEFT, RIGHT };//方向



	Snake() {

		snake.emplace_back(14, 8); //蛇出生位置

		snake.emplace_back(15, 8);

		snake.emplace_back(16, 8);

		direction = Direction::DOWN; //蛇出生移动方向

	}

	void InitSnake();

	void Move();

	void NormalMove();

	bool OverEdge();

	bool HitItself();

	bool ChangeDirection();

	bool GetFood(const Food&);

	bool GetBigFood(Food&);

private:

	std::deque<Point> snake;//蛇的容器

	Direction direction;

	friend class Food;//将Food类置为友元，以便访问其私有元素

};

class StartInterface

{

public:

	StartInterface() : speed(50) {

		startsnake.emplace_back(Point(0, 14));//Éß //向容器内添加一个点 

		startsnake.emplace_back(Point(1, 14));

		startsnake.emplace_back(Point(2, 15));

		startsnake.emplace_back(Point(3, 16));

		startsnake.emplace_back(Point(4, 17));

		startsnake.emplace_back(Point(5, 18));

		startsnake.emplace_back(Point(6, 17));

		startsnake.emplace_back(Point(7, 16));

		startsnake.emplace_back(Point(8, 15));

		startsnake.emplace_back(Point(9, 14));



		textsnake.emplace_back(Point(-26, 14));//S

		textsnake.emplace_back(Point(-25, 14));

		textsnake.emplace_back(Point(-27, 15));

		textsnake.emplace_back(Point(-26, 16));

		textsnake.emplace_back(Point(-25, 17));

		textsnake.emplace_back(Point(-27, 18));

		textsnake.emplace_back(Point(-26, 18));



		textsnake.emplace_back(Point(-23, 14));//N

		textsnake.emplace_back(Point(-23, 15));

		textsnake.emplace_back(Point(-23, 16));

		textsnake.emplace_back(Point(-23, 17));

		textsnake.emplace_back(Point(-23, 18));

		textsnake.emplace_back(Point(-22, 15));

		textsnake.emplace_back(Point(-21, 16));

		textsnake.emplace_back(Point(-20, 17));

		textsnake.emplace_back(Point(-19, 14));

		textsnake.emplace_back(Point(-19, 15));

		textsnake.emplace_back(Point(-19, 16));

		textsnake.emplace_back(Point(-19, 17));

		textsnake.emplace_back(Point(-19, 18));



		textsnake.emplace_back(Point(-17, 18));//A

		textsnake.emplace_back(Point(-16, 17));

		textsnake.emplace_back(Point(-15, 16));

		textsnake.emplace_back(Point(-14, 15));

		textsnake.emplace_back(Point(-14, 16));

		textsnake.emplace_back(Point(-13, 14));

		textsnake.emplace_back(Point(-13, 16));

		textsnake.emplace_back(Point(-12, 15));

		textsnake.emplace_back(Point(-12, 16));

		textsnake.emplace_back(Point(-11, 16));

		textsnake.emplace_back(Point(-10, 17));

		textsnake.emplace_back(Point(-9, 18));



		textsnake.emplace_back(Point(-7, 14));//K

		textsnake.emplace_back(Point(-7, 15));

		textsnake.emplace_back(Point(-7, 16));

		textsnake.emplace_back(Point(-7, 17));

		textsnake.emplace_back(Point(-7, 18));

		textsnake.emplace_back(Point(-6, 16));

		textsnake.emplace_back(Point(-5, 15));

		textsnake.emplace_back(Point(-5, 17));

		textsnake.emplace_back(Point(-4, 14));

		textsnake.emplace_back(Point(-4, 18));



		textsnake.emplace_back(Point(-2, 14));//E

		textsnake.emplace_back(Point(-2, 15));

		textsnake.emplace_back(Point(-2, 16));

		textsnake.emplace_back(Point(-2, 17));

		textsnake.emplace_back(Point(-2, 18));

		textsnake.emplace_back(Point(-1, 14));

		textsnake.emplace_back(Point(-1, 16));

		textsnake.emplace_back(Point(-1, 18));

		textsnake.emplace_back(Point(0, 14));

		textsnake.emplace_back(Point(0, 16));

		textsnake.emplace_back(Point(0, 18));

	}

	void PrintFirst();//蛇从左边出现到完全出现的过程

	void PrintSecond();//蛇从左向右移动的过程

	void PrintThird();//蛇从接触右边到消失的过程

	virtual void PrintText();//动画界面文字

	void ClearText();//清空动画界面文字

	void Action();//蛇三个动画的集合

protected:

	std::deque<Point> startsnake;//开始动画中的蛇

	std::vector<Point> textsnake;//开始动画中的文字

	int speed;//动画的速度

};

class StartChatInterface:public StartInterface
{
public:

	StartChatInterface() : speed(50)
	{
		//startsnake.emplace_back(Point(0, 14));//c //向容器内添加一个点 

		//startsnake.emplace_back(Point(1, 14));

		//startsnake.emplace_back(Point(2, 15));

		//startsnake.emplace_back(Point(3, 16));

		//startsnake.emplace_back(Point(4, 17));

		//startsnake.emplace_back(Point(5, 18));

		//startsnake.emplace_back(Point(6, 17));

		//startsnake.emplace_back(Point(7, 16));

		//startsnake.emplace_back(Point(8, 15));

		//startsnake.emplace_back(Point(9, 14));



		textsnake.emplace_back(Point(-26+30 +5, 14));//C

		textsnake.emplace_back(Point(-25 + 30 + 5, 14));

		textsnake.emplace_back(Point(-27 + 30 + 5, 15));

		textsnake.emplace_back(Point(-27 + 30 + 5, 16));

		textsnake.emplace_back(Point(-27 + 30 + 5, 17));

		textsnake.emplace_back(Point(-25 + 30 + 5, 18));

		textsnake.emplace_back(Point(-26 + 30 + 5, 18));



		textsnake.emplace_back(Point(-23 + 30 + 5, 14));//H

		textsnake.emplace_back(Point(-23 + 30 + 5, 15));

		textsnake.emplace_back(Point(-23 + 30 + 5, 16));

		textsnake.emplace_back(Point(-23 + 30 + 5, 17));

		textsnake.emplace_back(Point(-23 + 30 + 5, 18));

		textsnake.emplace_back(Point(-22 + 30 + 5, 16));

		textsnake.emplace_back(Point(-21 + 30 + 5, 16));

		textsnake.emplace_back(Point(-20 + 30 + 5, 16));

		textsnake.emplace_back(Point(-19 + 30 + 5, 14));

		textsnake.emplace_back(Point(-19 + 30 + 5, 15));

		textsnake.emplace_back(Point(-19 + 30 + 5, 16));

		textsnake.emplace_back(Point(-19 + 30 + 5, 17));

		textsnake.emplace_back(Point(-19 + 30 + 5, 18));



		textsnake.emplace_back(Point(-17 + 30 + 5, 18));//A

		textsnake.emplace_back(Point(-16 + 30 + 5, 17));

		textsnake.emplace_back(Point(-15 + 30 + 5, 16));

		textsnake.emplace_back(Point(-14 + 30 + 5, 15));

		textsnake.emplace_back(Point(-14 + 30 + 5, 16));

		textsnake.emplace_back(Point(-13 + 30 + 5, 14));

		textsnake.emplace_back(Point(-13 + 30 + 5, 16));

		textsnake.emplace_back(Point(-12 + 30 + 5, 15));

		textsnake.emplace_back(Point(-12 + 30 + 5, 16));

		textsnake.emplace_back(Point(-11 + 30 + 5, 16));

		textsnake.emplace_back(Point(-10 + 30 + 5, 17));

		textsnake.emplace_back(Point(-9 + 30 + 5, 18));



		//textsnake.emplace_back(Point(-7, 14));//K

		//textsnake.emplace_back(Point(-7, 15));

		//textsnake.emplace_back(Point(-7, 16));

		//textsnake.emplace_back(Point(-7, 17));

		//textsnake.emplace_back(Point(-7, 18));

		//textsnake.emplace_back(Point(-6, 16));

		//textsnake.emplace_back(Point(-5, 15));

		//textsnake.emplace_back(Point(-5, 17));

		//textsnake.emplace_back(Point(-4, 14));

		//textsnake.emplace_back(Point(-4, 18));


		textsnake.emplace_back(Point(-3 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(-4 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(-5 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(-1 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(-0 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(1 + 30 -2 + 5, 14));

		textsnake.emplace_back(Point(-2 + 30 -2 + 5, 14));//T

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 15));

		/*textsnake.emplace_back(Point(-2 - 2, 16));*/

		textsnake.emplace_back(Point(-2 + 30 -2 + 5, 16));

		textsnake.emplace_back(Point(-2 + 30 -2 + 5, 17));

		textsnake.emplace_back(Point(-2 + 30 -2 + 5, 18));

		/*textsnake.emplace_back(Point(-2 + 30, 19));*/

		textsnake.emplace_back(Point(-1 + 30 -2 + 5, 14));

		/*textsnake.emplace_back(Point(-1, 16));*/

		/*textsnake.emplace_back(Point(-1 + 30, 18));*/

	/*	textsnake.emplace_back(Point(0 + 30, 14));*/

		/*textsnake.emplace_back(Point(0, 16));*/

		//textsnake.emplace_back(Point(0 + 30, 18));

		void PrintText();
	}

	void PrintText();

private:

	int speed;

};

class PrintfChat
{
public:
	PrintfChat()
	{
		//startsnake.emplace_back(Point(0, 14));//c //向容器内添加一个点 

		//startsnake.emplace_back(Point(1, 14));

		//startsnake.emplace_back(Point(2, 15));

		//startsnake.emplace_back(Point(3, 16));

		//startsnake.emplace_back(Point(4, 17));

		//startsnake.emplace_back(Point(5, 18));

		//startsnake.emplace_back(Point(6, 17));

		//startsnake.emplace_back(Point(7, 16));

		//startsnake.emplace_back(Point(8, 15));

		//startsnake.emplace_back(Point(9, 14));



		textsnake.emplace_back(Point(-26 + 30 + 5, 14-10));//C

		textsnake.emplace_back(Point(-25 + 30 + 5, 14-10));

		textsnake.emplace_back(Point(-27 + 30 + 5, 15-10));

		textsnake.emplace_back(Point(-27 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-27 + 30 + 5, 17 - 10));

		textsnake.emplace_back(Point(-25 + 30 + 5, 18 - 10));

		textsnake.emplace_back(Point(-26 + 30 + 5, 18 - 10));



		textsnake.emplace_back(Point(-23 + 30 + 5, 14 - 10));//H

		textsnake.emplace_back(Point(-23 + 30 + 5, 15 - 10));

		textsnake.emplace_back(Point(-23 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-23 + 30 + 5, 17 - 10));

		textsnake.emplace_back(Point(-23 + 30 + 5, 18 - 10));

		textsnake.emplace_back(Point(-22 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-21 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-20 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-19 + 30 + 5, 14 - 10));

		textsnake.emplace_back(Point(-19 + 30 + 5, 15 - 10));

		textsnake.emplace_back(Point(-19 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-19 + 30 + 5, 17 - 10));

		textsnake.emplace_back(Point(-19 + 30 + 5, 18 - 10));



		textsnake.emplace_back(Point(-17 + 30 + 5, 18 - 10));//A

		textsnake.emplace_back(Point(-16 + 30 + 5, 17 - 10));

		textsnake.emplace_back(Point(-15 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-14 + 30 + 5, 15 - 10));

		textsnake.emplace_back(Point(-14 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-13 + 30 + 5, 14 - 10));

		textsnake.emplace_back(Point(-13 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-12 + 30 + 5, 15 - 10));

		textsnake.emplace_back(Point(-12 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-11 + 30 + 5, 16 - 10));

		textsnake.emplace_back(Point(-10 + 30 + 5, 17 - 10));

		textsnake.emplace_back(Point(-9 + 30 + 5, 18 - 10));



		//textsnake.emplace_back(Point(-7, 14));//K

		//textsnake.emplace_back(Point(-7, 15));

		//textsnake.emplace_back(Point(-7, 16));

		//textsnake.emplace_back(Point(-7, 17));

		//textsnake.emplace_back(Point(-7, 18));

		//textsnake.emplace_back(Point(-6, 16));

		//textsnake.emplace_back(Point(-5, 15));

		//textsnake.emplace_back(Point(-5, 17));

		//textsnake.emplace_back(Point(-4, 14));

		//textsnake.emplace_back(Point(-4, 18));


		textsnake.emplace_back(Point(-3 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(-4 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(-5 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(-1 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(-0 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(1 + 30 - 2 + 5, 14 - 10));

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 14 - 10));//T

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 15 - 10));

		/*textsnake.emplace_back(Point(-2 - 2, 16));*/

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 16 - 10));

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 17 - 10));

		textsnake.emplace_back(Point(-2 + 30 - 2 + 5, 18 - 10));

		/*textsnake.emplace_back(Point(-2 + 30, 19));*/

		textsnake.emplace_back(Point(-1 + 30 - 2 + 5, 14 - 10));

		/*textsnake.emplace_back(Point(-1, 16));*/

		/*textsnake.emplace_back(Point(-1 + 30, 18));*/

		/*	textsnake.emplace_back(Point(0 + 30, 14));*/

		/*textsnake.emplace_back(Point(0, 16));*/

		//textsnake.emplace_back(Point(0 + 30, 18));

	}
	void PrintText();

private:
	std::deque<Point> startsnake;//开始动画中的蛇

	std::vector<Point> textsnake;//开始动画中的文字

	int speed;//动画的速度
};

void SetWindowSize(int cols, int lines);//窗口大小

void SetCursorPosition(const int x, const int y);//坐标位置

void SetColor(int colorID);//文本颜色

void SetBackColor();//文本背景颜色

#endif