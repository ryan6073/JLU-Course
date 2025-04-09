#include <iostream>

#include <time.h>

#include <conio.h>

#include <windows.h>


#include "GreedySnake.h"


#include <cstdlib>


int GameReturnFlag;

void Controller::Start()//开始界面

{

	SetWindowSize(41, 32);//设置窗口大小 (宽带\高度)

	SetColor(3);//设置开始动画颜色 （1蓝 2绿 3青 4红 5紫 6黄 7白 8灰 9深蓝 10深绿....）

	StartInterface *start = new StartInterface();//动态分配一个StartInterface类start

	start->Action();//开始动画

	delete start;//释放内存空间



				 /*设置关标位置，并输出提示语，等待任意键输入结束*/

	SetCursorPosition(13, 26);

	std::cout << "Press any key to start... ";


	SetCursorPosition(13, 27);

	system("pause");

}



void Controller::Select()//选择界面

{

	/*初始化界面选项*/

	SetColor(3);

	SetCursorPosition(13, 26); //光标位置

	std::cout << "                          ";

	SetCursorPosition(13, 27);

	std::cout << "                          ";

	SetColor(13);
	SetCursorPosition(17, 5);
	std::cout << "贪吃蛇游戏";
	SetCursorPosition(15, 6);
	std::cout << "===================";
	SetCursorPosition(13, 7);
	std::cout << "         吉林大学";
	SetCursorPosition(13, 8);
	std::cout << "      2017级软件学院九班";
	SetCursorPosition(13, 9);
	std::cout << "曹佳伟、吴丰屹制作";
	;


	SetColor(3);

	SetCursorPosition(6, 21);

	std::cout << "请选择游戏难度：";

	SetCursorPosition(6, 22);

	std::cout << "(上下键选择,回车确认)";

	SetCursorPosition(27, 22);

	SetBackColor();//第一个选项设置背景色以表示当前选中

	std::cout << "简单模式";

	SetCursorPosition(27, 24);

	SetColor(3);

	std::cout << "普通模式";

	SetCursorPosition(27, 26);

	std::cout << "困难模式";

	SetCursorPosition(27, 28);

	std::cout << "炼狱模式";

	SetCursorPosition(0, 31);

	Controller::score = 0;//游戏分数



						  /*上下方向键选择模块*/

	int ch;//记录键入值

	key = 1;//记录选中项，初始选择第一个

	bool flag = false;//记录是否键入Enter键标记，初始置为否

	while ((ch = getch()))

	{

		switch (ch)//检测输入键

		{

		case 72://UP上方向键

			if (key > 1)//当此时选中项为第一项时，UP上方向键无效

			{

				switch (key)

				{

				case 2:

					SetCursorPosition(27, 22);//给待选中项设置背景色

					SetBackColor();//设置文本背景颜色

					std::cout << "简单模式";


					SetCursorPosition(27, 24);//将已选中项取消背景色

					SetColor(3);

					std::cout << "普通模式";



					--key;

					break;

				case 3:

					SetCursorPosition(27, 24);

					SetBackColor();

					std::cout << "普通模式";



					SetCursorPosition(27, 26);

					SetColor(3);

					std::cout << "困难模式";



					--key;

					break;

				case 4:

					SetCursorPosition(27, 26);

					SetBackColor();

					std::cout << "困难模式";



					SetCursorPosition(27, 28);

					SetColor(3);

					std::cout << "炼狱模式";



					--key;

					break;

				}

			}

			break;



		case 80://DOWN下方向键

			if (key < 4)

			{

				switch (key)//key默认为1 即简单模式

				{

				case 1:

					SetCursorPosition(27, 24);

					SetBackColor();

					std::cout << "普通模式";

					SetCursorPosition(27, 22);

					SetColor(3);

					std::cout << "简单模式";



					++key;

					break;

				case 2:

					SetCursorPosition(27, 26);

					SetBackColor();

					std::cout << "困难模式";

					SetCursorPosition(27, 24);

					SetColor(3);

					std::cout << "普通模式";



					++key;

					break;

				case 3:

					SetCursorPosition(27, 28);

					SetBackColor();

					std::cout << "炼狱模式";

					SetCursorPosition(27, 26);

					SetColor(3);

					std::cout << "困难模式";



					++key;

					break;

				}

			}

			break;



		case 13://Enter回车键

			flag = true;

			break;

		default://无效按键

			break;

		}

		if (flag) break;//输入Enter回车键确认，退出检查输入循环



		SetCursorPosition(0, 31);//将光标置于左下角，避免光标闪烁影响游戏体验

	}



	switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快

	{

	case 1://key默认为1

		Controller::speed = 135;

		break;

	case 2:

		Controller::speed = 100;

		break;

	case 3:

		Controller::speed = 60;

		break;

	case 4:

		Controller::speed = 30;

		break;

	default:

		break;

	}

}



void Controller::DrawGame()//绘制游戏界面

{

	system("cls");//清屏



				  /*绘制地图*/

	SetColor(3);

	Map *init_map = new Map();

	init_map->PrintInitmap();

	delete init_map;



	/*绘制侧边栏*/

	SetColor(3);

	SetCursorPosition(33, 1);

	std::cout << "Greedy Snake";

	SetCursorPosition(34, 2);

	std::cout << "贪吃蛇";

	SetCursorPosition(31, 4);

	std::cout << "难度：";

	SetCursorPosition(36, 5);

	switch (key)

	{

	case 1:

		std::cout << "简单模式";

		break;

	case 2:

		std::cout << "普通模式";

		break;

	case 3:

		std::cout << "困难模式";

		break;

	case 4:

		std::cout << "炼狱模式";

		break;

	default:

		break;

	}

	SetCursorPosition(31, 7);

	std::cout << "得分：";

	SetCursorPosition(37, 8);

	std::cout << "     0";

	SetCursorPosition(33, 13);

	std::cout << " 方向键移动";

	SetCursorPosition(33, 15);

	std::cout << " ESC键暂停";

}



int Controller::PlayGame()//游戏二级循环

{

	/*初始化蛇和食物*/

	Snake *csnake = new Snake();

	Food *cfood = new Food();

	SetColor(3);

	csnake->InitSnake();

	srand((unsigned)time(NULL));//设置随机数种子，如果没有 食物的出现位置将会固定

	cfood->DrawFood(*csnake);



	/*游戏循环*/

	while (csnake->OverEdge() && csnake->HitItself()) //判断是否撞墙或撞到自身，即是否还有生命

	{

		/*调出选择菜单*/

		if (!csnake->ChangeDirection()) //按Esc键时

		{

			int tmp = Menu();//绘制菜单，并得到返回值

			switch (tmp)

			{

			case 1://继续游戏

				break;



			case 2://重新开始

				delete csnake;

				delete cfood;

				return 1;//将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始



			case 3://退出游戏

				delete csnake;

				delete cfood;

				return 2;//将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏



			default:

				break;

			}

		}



		if (csnake->GetFood(*cfood)) //吃到食物

		{

			csnake->Move();//蛇移动并打印蛇

			UpdateScore(1);//更新分数，1为分数权重

			RewriteScore();//重新绘制分数

			cfood->DrawFood(*csnake);//绘制新食物

		}

		else

		{

			csnake->NormalMove();//蛇正常移动

		}



		if (csnake->GetBigFood(*cfood)) //吃到限时食物

		{

			csnake->Move();

			UpdateScore(cfood->GetProgressBar() / 5);//分数根据限时食物进度条确定,分数权重

			RewriteScore();

		}



		if (cfood->GetBigFlag()) //如果此时有限时食物，闪烁它

		{

			cfood->FlashBigFood();

		}



		Sleep(speed);//制造蛇的移动效果

	}



	/*蛇死亡*/

	delete csnake;//释放分配的内存空间

	delete cfood;

	int tmp = GameOver();//绘制游戏结束界面，并返回所选项

	switch (tmp)

	{

	case 1:

		return 1;//重新开始

	case 2:

		return 2;//退出游戏

	default:

		return 2;

	}


}



void Controller::UpdateScore(const int& tmp)//更新分数

{

	Controller::score += Controller::key * 10 * tmp;//所得分数根据游戏难度及传人的参数tmp确定

}



void Controller::RewriteScore()//重绘分数

{

	/*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/

	SetCursorPosition(37, 8);

	SetColor(11);

	int bit = 0;

	int tmp = Controller::score;

	while (tmp != 0)

	{

		++bit;

		tmp /= 10;

	}

	for (int i = 0; i < (6 - bit); ++i)

	{

		std::cout << " ";

	}

	std::cout << score;

}



int Controller::Menu()//选择菜单

{

	/*绘制菜单*/

	SetColor(11);

	SetCursorPosition(32, 19);

	std::cout << "菜单：";

	Sleep(100);

	SetCursorPosition(34, 21);

	SetBackColor();

	std::cout << "继续游戏";

	Sleep(100);

	SetCursorPosition(34, 23);

	SetColor(11);

	std::cout << "重新开始";

	Sleep(100);

	SetCursorPosition(34, 25);

	std::cout << "退出游戏";

	SetCursorPosition(0, 31);



	/*选择部分*/

	int ch;

	int tmp_key = 1;

	bool flag = false;

	while ((ch = getch()))

	{

		switch (ch)

		{

		case 72://UP

			if (tmp_key > 1)

			{

				switch (tmp_key)

				{

				case 2:

					SetCursorPosition(34, 21);

					SetBackColor();

					std::cout << "继续游戏";

					SetCursorPosition(34, 23);

					SetColor(11);

					std::cout << "重新开始";



					--tmp_key;

					break;

				case 3:

					SetCursorPosition(34, 23);

					SetBackColor();

					std::cout << "重新开始";

					SetCursorPosition(34, 25);

					SetColor(11);

					std::cout << "退出游戏";



					--tmp_key;

					break;

				}

			}

			break;



		case 80://DOWN

			if (tmp_key < 3)

			{

				switch (tmp_key)

				{

				case 1:

					SetCursorPosition(34, 23);

					SetBackColor();

					std::cout << "重新开始";

					SetCursorPosition(34, 21);

					SetColor(11);

					std::cout << "继续游戏";



					++tmp_key;

					break;

				case 2:

					SetCursorPosition(34, 25);

					SetBackColor();

					std::cout << "退出游戏";

					SetCursorPosition(34, 23);

					SetColor(11);

					std::cout << "重新开始";



					++tmp_key;

					break;

				}

			}

			break;



		case 13://Enter

			flag = true;

			break;



		default:

			break;

		}



		if (flag)

		{

			break;

		}

		SetCursorPosition(0, 31);

	}



	if (tmp_key == 1) //选择继续游戏，则将菜单擦除

	{

		SetCursorPosition(32, 19);

		std::cout << "      ";

		SetCursorPosition(34, 21);

		std::cout << "        ";

		SetCursorPosition(34, 23);

		std::cout << "        ";

		SetCursorPosition(34, 25);

		std::cout << "        ";

	}

	return tmp_key;

}



void Controller::Game()//游戏一级循环

{

	Start();//开始界面

	while (true)//游戏可视为一个死循环，直到退出游戏时循环结束

	{

		Controller::Select();//选择界面

		Controller::DrawGame();//绘制游戏界面

		int tmp = Controller::PlayGame();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp

		if (tmp == 1) //返回值为1时重新开始游戏

		{

			system("cls");

			continue;

		}

		else if (tmp == 2) //返回值为2时退出游戏

		{
			/*QQTools_CHC QQTools;
*/
			QQTools.QQMenu();

			break;

		}

		else

		{

			break;

		}

	}

}



int Controller::GameOver()//游戏结束界面

{

	/*绘制游戏结束界面*/

	Sleep(500);

	SetColor(11);

	SetCursorPosition(10, 8);

	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(30);

	SetCursorPosition(9, 9);

	std::cout << " ┃               Game Over !!!              ┃";

	Sleep(30);

	SetCursorPosition(9, 10);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 11);

	std::cout << " ┃              很遗憾！你挂了              ┃";

	Sleep(30);

	SetCursorPosition(9, 12);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 13);

	std::cout << " ┃             你的分数为：                 ┃";

	SetCursorPosition(24, 13);

	std::cout << score;

	Sleep(30);

	SetCursorPosition(9, 14);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 15);

	std::cout << " ┃   是否再来一局？                         ┃";

	Sleep(30);

	SetCursorPosition(9, 16);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 17);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 18);

	std::cout << " ┃    嗯，好的        不了，返回上一级菜单       ┃";

	Sleep(30);

	SetCursorPosition(9, 19);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(9, 20);

	std::cout << " ┃                                          ┃";

	Sleep(30);

	SetCursorPosition(10, 21);

	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";



	Sleep(100);

	SetCursorPosition(12, 18);

	SetBackColor();

	std::cout << "嗯，好的";

	SetCursorPosition(0, 31);



	/*选择部分*/

	int ch;

	int tmp_key = 1;

	bool flag = false;

	while ((ch = getch()))

	{

		switch (ch)

		{

		case 75://LEFT

			if (tmp_key > 1)

			{

				SetCursorPosition(12, 18);

				SetBackColor();

				std::cout << "嗯，好的";

				SetCursorPosition(20, 18);

				SetColor(11);

				std::cout << "不了，返回上一级菜单";

				--tmp_key;

			}

			break;



		case 77://RIGHT

			if (tmp_key < 2)

			{

				SetCursorPosition(20, 18);

				SetBackColor();

				std::cout << "不了，返回上一级菜单";

				SetCursorPosition(12, 18);

				SetColor(11);

				std::cout << "嗯，好的";

				++tmp_key;

			}

			break;



		case 13://Enter

			flag = true;

			break;



		default:

			break;

		}



		SetCursorPosition(0, 31);

		if (flag) {

			break;

		}

	}



	SetColor(11);

	switch (tmp_key)

	{

	case 1:

		return 1;//重新开始

	case 2:

		if (GameReturnFlag == 1)
		{
			QQTools.QQMenu();
		}
		else if (GameReturnFlag == 2)
		{
			WeiChatTools.WeiChatMenu();
		}
		
		return 2;//退出游戏

	default:

		return 1;

	}

}











void Food::DrawFood(Snake& csnake)//绘制食物

{

	/*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。

	同时每5颗食物就出现一颗限时食物*/

	while (true)

	{

		int tmp_x = rand() % 30; //将食物范围限制在2-29内(地图大小)

		int tmp_y = rand() % 30;

		if (tmp_x < 2)
			tmp_x += 2;

		if (tmp_y < 2)
			tmp_y += 2;

		bool flag = false;

		for (auto& point : csnake.snake)

		{

			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
				//判断食物位置与蛇是否重合
				flag = true;

				break;

			}

		}

		if (flag)

			continue;

		Food::x = tmp_x;

		Food::y = tmp_y;

		SetCursorPosition(x, y);//设置光标位置

		SetColor(13);

		std::cout << "★";

		++cnt;//判断吃到食物个数

		cnt %= 5;

		if (cnt == 0)

		{

			DrawBigFood(csnake);

		}

		break;

	}

}



void Food::DrawBigFood(Snake& csnake)//绘制限时食物

{

	SetCursorPosition(5, 0);//在此处打印进度条

	SetColor(13);//设置进度条的颜色

	std::cout << "------------------------------------------" << "<-限时食物进度条消失";//进度条

	progress_bar = 42;//进度条大小

	while (true)

	{

		int tmp_x = rand() % 30;

		int tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;

		if (tmp_y < 2) tmp_y += 2;

		bool flag = false;

		for (auto& point : csnake.snake)

		{

			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
				//判断蛇身与食物重合
			{

				flag = true;

				break;

			}

		}

		if (flag)

			continue;



		big_x = tmp_x;

		big_y = tmp_y;

		SetCursorPosition(big_x, big_y);//限时食物的坐标

		SetColor(18);//限时食物的颜色

		std::cout << "■";

		big_flag = true;

		flash_flag = true;

		break;

	}

}



int Food::GetCnt()//食物次数标记

{

	return cnt;

}



void Food::FlashBigFood()//闪烁限时食物

{

	SetCursorPosition(big_x, big_y);

	SetColor(18);

	if (Food::flash_flag)

	{

		std::cout << "  ";

		flash_flag = false;

	}

	else

	{

		std::cout << "■";

		flash_flag = true;

	}



	SetCursorPosition(26, 0);

	SetColor(13);

	for (int i = 42; i >= progress_bar; --i)//进度条缩短

		std::cout << "\b \b"; //输出退格键

	--progress_bar;

	if (progress_bar == 0) //限时食物消失
	{

		SetCursorPosition(big_x, big_y);

		std::cout << "  ";

		big_flag = false;//食物消失则将限时食物标记设为false

		big_x = 0;

		big_y = 0;

	}

}



bool Food::GetBigFlag()

{

	return Food::big_flag;//返回限时食物标记

}



int Food::GetProgressBar()

{

	return Food::progress_bar;//返回剩余进度条，用来更新游戏分数

}


void Map::PrintInitmap()//绘制初始地图

{

	for (auto& point : initmap)

	{

		point.Print();

		Sleep(10);//调用Sleep函数可营造动画效果

	}

}


void Point::Print()//输出方块

{

	SetCursorPosition(x, y);

	std::cout << "■";

}



void Point::PrintCircular()//输出圆形

{

	SetCursorPosition(x, y);

	std::cout << "●";

}



void Point::Clear()//清除输出

{

	SetCursorPosition(x, y);

	std::cout << "  ";

}



void Point::ChangePosition(const int x, const int y)//改变坐标

{

	this->x = x;

	this->y = y;

}


void Snake::InitSnake()//初始化蛇

{

	for (auto& point : snake)

	{

		point.PrintCircular();//输出圆形

	}

}



void Snake::Move()//蛇增长

{

	switch (direction)

	{

	case Direction::UP:

		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));

		break;

	case Direction::DOWN:

		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));

		break;

	case Direction::LEFT:

		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));

		break;

	case Direction::RIGHT:

		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));

		break;

	default:

		break;

	}

	SetColor(14);

	snake.back().PrintCircular();

}



void Snake::NormalMove()//蛇正常移动，头增长，尾缩短

{

	Move();

	snake.front().Clear();

	snake.pop_front();

}



bool Snake::OverEdge()//超出边界

{

	return snake.back().GetX() < 30 &&

		snake.back().GetY() < 30 &&

		snake.back().GetX() > 1 &&

		snake.back().GetY() > 1;

}



bool Snake::HitItself()//撞到自身

{

	std::deque<Point>::size_type cnt = 1;

	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//获得头部坐标

	for (auto& point : Snake::snake) //如果整条蛇中与蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身

	{
		//蛇头碰到自身后会重合
		if (!(point == *head))

			++cnt;

		else

			break;

	}

	delete head;

	if (cnt == snake.size())

		return true;

	else

		return false;

}



bool Snake::ChangeDirection()//改变蛇的方向

{

	char ch;

	if (kbhit())//kbhit函数返回值为两个，需注意

	{

		ch = getch();

		switch (ch)

		{

		case -32:

			ch = getch();

			switch (ch)

			{

			case 72://上键的assic

				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效

					direction = Direction::UP;

				break;

			case 80://下键的assic

				if (direction != Direction::UP)

					direction = Direction::DOWN;

				break;

			case 75://左键的assic

				if (direction != Direction::RIGHT)

					direction = Direction::LEFT;

				break;

			case 77://右键的assic

				if (direction != Direction::LEFT)

					direction = Direction::RIGHT;

				break;

			default:

				break;

			}

			return true;



		case 27://ESC assic菜单

			return false;



		default:

			return true;


		}

	}

	return true;

}



bool Snake::GetFood(const Food& cfood)//蛇吃到食物

{

	if (Snake::snake.back().GetX() == cfood.x && Snake::snake.back().GetY() == cfood.y)
		//蛇头部在容器尾部
		return true;

	else

		return false;

}



bool Snake::GetBigFood(Food& cfood)//蛇吃到限时食物

{

	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)

	{

		cfood.big_flag = false;

		cfood.big_x = 0;

		cfood.big_y = 0;

		SetCursorPosition(1, 0);

		std::cout << "                                                            ";

		return true;

	}

	else

		return false;

}


void StartInterface::PrintFirst()//蛇从左边出现到完全出现的过程

{

	for (auto& point : startsnake)

	{

		point.Print();//输出方块

		Sleep(speed);

	}

}



void StartInterface::PrintSecond()//蛇从左向右移动的过程

{

	for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40

	{

		/*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/

		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);

		startsnake.emplace_back(Point(i, j));//将计算的下一个蛇头位置填入startsnake中

		startsnake.back().Print();//打印下一个蛇头

		startsnake.front().Clear();//在第一个元素位置打印" "

		startsnake.pop_front();//弹出第一个后，回收空间

		Sleep(speed);//延迟

	}

}



void StartInterface::PrintThird()//蛇从接触右边到消失的过程

{

	while (!startsnake.empty() || textsnake.back().GetX() < 33) //当蛇还没消失或文字没移动到指定位置

	{

		if (!startsnake.empty()) //如果蛇还没消失，继续移动

		{

			startsnake.front().Clear();

			startsnake.pop_front();

		}

		ClearText();//清除已有文字

		PrintText();//绘制更新位置后的文字

		Sleep(speed);

	}

}



void StartInterface::PrintText()//蛇，打印蛇的文字图像

{

		for (auto& point : textsnake)
		{
	
			if (point.GetX() >= 0)
			{
	
				
				point.Print();
			}
	
		}

}



void StartInterface::ClearText()//清除的同时将蛇文字整体向右移动一格

{

	for (auto& point : textsnake)

	{

		if (point.GetX() >= 0)

			point.Clear();

		point.ChangePosition(point.GetX() + 1, point.GetY());

	}

}



void StartInterface::Action()//蛇三个动画的集合

{

	PrintFirst();

	PrintSecond();

	PrintThird();

}



void SetWindowSize(int cols, int lines)//设置窗口大小

{

	//system("贪吃蛇--吉林大学");//设置窗口标题
	//Sleep(10000);
	char cmd[30];

	sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形占两个字符，故宽度乘以2

	system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度

}



void SetCursorPosition(const int x, const int y)//设置光标位置

{

	COORD position;  //表示一个字符在控制台屏幕上的坐标

	position.X = x * 2;

	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}



void SetColor(int colorID)//设置文本颜色

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);

}



void SetBackColor()//设置文本背景色

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),

		FOREGROUND_BLUE |

		BACKGROUND_BLUE |

		BACKGROUND_GREEN |

		BACKGROUND_RED);

}

void StartChatInterface::PrintText()
{
	for (auto& point : textsnake)
	{

		if (point.GetX() >= 1)
		{

			Sleep(50);
			point.Print();
		}

	}
}

void PrintfChat::PrintText()
{
	for (auto& point : textsnake)
	{

		if (point.GetX() >= 1)
		{


			point.Print();
		}

	}
}