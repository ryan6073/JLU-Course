#include <iostream>

#include <time.h>

#include <conio.h>

#include <windows.h>


#include "GreedySnake.h"


#include <cstdlib>


int GameReturnFlag;

void Controller::Start()//��ʼ����

{

	SetWindowSize(41, 32);//���ô��ڴ�С (���\�߶�)

	SetColor(3);//���ÿ�ʼ������ɫ ��1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9���� 10����....��

	StartInterface *start = new StartInterface();//��̬����һ��StartInterface��start

	start->Action();//��ʼ����

	delete start;//�ͷ��ڴ�ռ�



				 /*���ùر�λ�ã��������ʾ��ȴ�������������*/

	SetCursorPosition(13, 26);

	std::cout << "Press any key to start... ";


	SetCursorPosition(13, 27);

	system("pause");

}



void Controller::Select()//ѡ�����

{

	/*��ʼ������ѡ��*/

	SetColor(3);

	SetCursorPosition(13, 26); //���λ��

	std::cout << "                          ";

	SetCursorPosition(13, 27);

	std::cout << "                          ";

	SetColor(13);
	SetCursorPosition(17, 5);
	std::cout << "̰������Ϸ";
	SetCursorPosition(15, 6);
	std::cout << "===================";
	SetCursorPosition(13, 7);
	std::cout << "         ���ִ�ѧ";
	SetCursorPosition(13, 8);
	std::cout << "      2017�����ѧԺ�Ű�";
	SetCursorPosition(13, 9);
	std::cout << "�ܼ�ΰ�����������";
	;


	SetColor(3);

	SetCursorPosition(6, 21);

	std::cout << "��ѡ����Ϸ�Ѷȣ�";

	SetCursorPosition(6, 22);

	std::cout << "(���¼�ѡ��,�س�ȷ��)";

	SetCursorPosition(27, 22);

	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��

	std::cout << "��ģʽ";

	SetCursorPosition(27, 24);

	SetColor(3);

	std::cout << "��ͨģʽ";

	SetCursorPosition(27, 26);

	std::cout << "����ģʽ";

	SetCursorPosition(27, 28);

	std::cout << "����ģʽ";

	SetCursorPosition(0, 31);

	Controller::score = 0;//��Ϸ����



						  /*���·����ѡ��ģ��*/

	int ch;//��¼����ֵ

	key = 1;//��¼ѡ�����ʼѡ���һ��

	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��

	while ((ch = getch()))

	{

		switch (ch)//��������

		{

		case 72://UP�Ϸ����

			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч

			{

				switch (key)

				{

				case 2:

					SetCursorPosition(27, 22);//����ѡ�������ñ���ɫ

					SetBackColor();//�����ı�������ɫ

					std::cout << "��ģʽ";


					SetCursorPosition(27, 24);//����ѡ����ȡ������ɫ

					SetColor(3);

					std::cout << "��ͨģʽ";



					--key;

					break;

				case 3:

					SetCursorPosition(27, 24);

					SetBackColor();

					std::cout << "��ͨģʽ";



					SetCursorPosition(27, 26);

					SetColor(3);

					std::cout << "����ģʽ";



					--key;

					break;

				case 4:

					SetCursorPosition(27, 26);

					SetBackColor();

					std::cout << "����ģʽ";



					SetCursorPosition(27, 28);

					SetColor(3);

					std::cout << "����ģʽ";



					--key;

					break;

				}

			}

			break;



		case 80://DOWN�·����

			if (key < 4)

			{

				switch (key)//keyĬ��Ϊ1 ����ģʽ

				{

				case 1:

					SetCursorPosition(27, 24);

					SetBackColor();

					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 22);

					SetColor(3);

					std::cout << "��ģʽ";



					++key;

					break;

				case 2:

					SetCursorPosition(27, 26);

					SetBackColor();

					std::cout << "����ģʽ";

					SetCursorPosition(27, 24);

					SetColor(3);

					std::cout << "��ͨģʽ";



					++key;

					break;

				case 3:

					SetCursorPosition(27, 28);

					SetBackColor();

					std::cout << "����ģʽ";

					SetCursorPosition(27, 26);

					SetColor(3);

					std::cout << "����ģʽ";



					++key;

					break;

				}

			}

			break;



		case 13://Enter�س���

			flag = true;

			break;

		default://��Ч����

			break;

		}

		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��



		SetCursorPosition(0, 31);//������������½ǣ���������˸Ӱ����Ϸ����

	}



	switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��

	{

	case 1://keyĬ��Ϊ1

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



void Controller::DrawGame()//������Ϸ����

{

	system("cls");//����



				  /*���Ƶ�ͼ*/

	SetColor(3);

	Map *init_map = new Map();

	init_map->PrintInitmap();

	delete init_map;



	/*���Ʋ����*/

	SetColor(3);

	SetCursorPosition(33, 1);

	std::cout << "Greedy Snake";

	SetCursorPosition(34, 2);

	std::cout << "̰����";

	SetCursorPosition(31, 4);

	std::cout << "�Ѷȣ�";

	SetCursorPosition(36, 5);

	switch (key)

	{

	case 1:

		std::cout << "��ģʽ";

		break;

	case 2:

		std::cout << "��ͨģʽ";

		break;

	case 3:

		std::cout << "����ģʽ";

		break;

	case 4:

		std::cout << "����ģʽ";

		break;

	default:

		break;

	}

	SetCursorPosition(31, 7);

	std::cout << "�÷֣�";

	SetCursorPosition(37, 8);

	std::cout << "     0";

	SetCursorPosition(33, 13);

	std::cout << " ������ƶ�";

	SetCursorPosition(33, 15);

	std::cout << " ESC����ͣ";

}



int Controller::PlayGame()//��Ϸ����ѭ��

{

	/*��ʼ���ߺ�ʳ��*/

	Snake *csnake = new Snake();

	Food *cfood = new Food();

	SetColor(3);

	csnake->InitSnake();

	srand((unsigned)time(NULL));//������������ӣ����û�� ʳ��ĳ���λ�ý���̶�

	cfood->DrawFood(*csnake);



	/*��Ϸѭ��*/

	while (csnake->OverEdge() && csnake->HitItself()) //�ж��Ƿ�ײǽ��ײ���������Ƿ�������

	{

		/*����ѡ��˵�*/

		if (!csnake->ChangeDirection()) //��Esc��ʱ

		{

			int tmp = Menu();//���Ʋ˵������õ�����ֵ

			switch (tmp)

			{

			case 1://������Ϸ

				break;



			case 2://���¿�ʼ

				delete csnake;

				delete cfood;

				return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ



			case 3://�˳���Ϸ

				delete csnake;

				delete cfood;

				return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ



			default:

				break;

			}

		}



		if (csnake->GetFood(*cfood)) //�Ե�ʳ��

		{

			csnake->Move();//���ƶ�����ӡ��

			UpdateScore(1);//���·�����1Ϊ����Ȩ��

			RewriteScore();//���»��Ʒ���

			cfood->DrawFood(*csnake);//������ʳ��

		}

		else

		{

			csnake->NormalMove();//�������ƶ�

		}



		if (csnake->GetBigFood(*cfood)) //�Ե���ʱʳ��

		{

			csnake->Move();

			UpdateScore(cfood->GetProgressBar() / 5);//����������ʱʳ�������ȷ��,����Ȩ��

			RewriteScore();

		}



		if (cfood->GetBigFlag()) //�����ʱ����ʱʳ���˸��

		{

			cfood->FlashBigFood();

		}



		Sleep(speed);//�����ߵ��ƶ�Ч��

	}



	/*������*/

	delete csnake;//�ͷŷ�����ڴ�ռ�

	delete cfood;

	int tmp = GameOver();//������Ϸ�������棬��������ѡ��

	switch (tmp)

	{

	case 1:

		return 1;//���¿�ʼ

	case 2:

		return 2;//�˳���Ϸ

	default:

		return 2;

	}


}



void Controller::UpdateScore(const int& tmp)//���·���

{

	Controller::score += Controller::key * 10 * tmp;//���÷���������Ϸ�Ѷȼ����˵Ĳ���tmpȷ��

}



void Controller::RewriteScore()//�ػ����

{

	/*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/

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



int Controller::Menu()//ѡ��˵�

{

	/*���Ʋ˵�*/

	SetColor(11);

	SetCursorPosition(32, 19);

	std::cout << "�˵���";

	Sleep(100);

	SetCursorPosition(34, 21);

	SetBackColor();

	std::cout << "������Ϸ";

	Sleep(100);

	SetCursorPosition(34, 23);

	SetColor(11);

	std::cout << "���¿�ʼ";

	Sleep(100);

	SetCursorPosition(34, 25);

	std::cout << "�˳���Ϸ";

	SetCursorPosition(0, 31);



	/*ѡ�񲿷�*/

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

					std::cout << "������Ϸ";

					SetCursorPosition(34, 23);

					SetColor(11);

					std::cout << "���¿�ʼ";



					--tmp_key;

					break;

				case 3:

					SetCursorPosition(34, 23);

					SetBackColor();

					std::cout << "���¿�ʼ";

					SetCursorPosition(34, 25);

					SetColor(11);

					std::cout << "�˳���Ϸ";



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

					std::cout << "���¿�ʼ";

					SetCursorPosition(34, 21);

					SetColor(11);

					std::cout << "������Ϸ";



					++tmp_key;

					break;

				case 2:

					SetCursorPosition(34, 25);

					SetBackColor();

					std::cout << "�˳���Ϸ";

					SetCursorPosition(34, 23);

					SetColor(11);

					std::cout << "���¿�ʼ";



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



	if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����

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



void Controller::Game()//��Ϸһ��ѭ��

{

	Start();//��ʼ����

	while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������

	{

		Controller::Select();//ѡ�����

		Controller::DrawGame();//������Ϸ����

		int tmp = Controller::PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp

		if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ

		{

			system("cls");

			continue;

		}

		else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ

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



int Controller::GameOver()//��Ϸ��������

{

	/*������Ϸ��������*/

	Sleep(500);

	SetColor(11);

	SetCursorPosition(10, 8);

	std::cout << "������������������������������������������������������������������������������������";

	Sleep(30);

	SetCursorPosition(9, 9);

	std::cout << " ��               Game Over !!!              ��";

	Sleep(30);

	SetCursorPosition(9, 10);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 11);

	std::cout << " ��              ���ź��������              ��";

	Sleep(30);

	SetCursorPosition(9, 12);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 13);

	std::cout << " ��             ��ķ���Ϊ��                 ��";

	SetCursorPosition(24, 13);

	std::cout << score;

	Sleep(30);

	SetCursorPosition(9, 14);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 15);

	std::cout << " ��   �Ƿ�����һ�֣�                         ��";

	Sleep(30);

	SetCursorPosition(9, 16);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 17);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 18);

	std::cout << " ��    �ţ��õ�        ���ˣ�������һ���˵�       ��";

	Sleep(30);

	SetCursorPosition(9, 19);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(9, 20);

	std::cout << " ��                                          ��";

	Sleep(30);

	SetCursorPosition(10, 21);

	std::cout << "������������������������������������������������������������������������������������";



	Sleep(100);

	SetCursorPosition(12, 18);

	SetBackColor();

	std::cout << "�ţ��õ�";

	SetCursorPosition(0, 31);



	/*ѡ�񲿷�*/

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

				std::cout << "�ţ��õ�";

				SetCursorPosition(20, 18);

				SetColor(11);

				std::cout << "���ˣ�������һ���˵�";

				--tmp_key;

			}

			break;



		case 77://RIGHT

			if (tmp_key < 2)

			{

				SetCursorPosition(20, 18);

				SetBackColor();

				std::cout << "���ˣ�������һ���˵�";

				SetCursorPosition(12, 18);

				SetColor(11);

				std::cout << "�ţ��õ�";

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

		return 1;//���¿�ʼ

	case 2:

		if (GameReturnFlag == 1)
		{
			QQTools.QQMenu();
		}
		else if (GameReturnFlag == 2)
		{
			WeiChatTools.WeiChatMenu();
		}
		
		return 2;//�˳���Ϸ

	default:

		return 1;

	}

}











void Food::DrawFood(Snake& csnake)//����ʳ��

{

	/*����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��

	ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��*/

	while (true)

	{

		int tmp_x = rand() % 30; //��ʳ�ﷶΧ������2-29��(��ͼ��С)

		int tmp_y = rand() % 30;

		if (tmp_x < 2)
			tmp_x += 2;

		if (tmp_y < 2)
			tmp_y += 2;

		bool flag = false;

		for (auto& point : csnake.snake)

		{

			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
				//�ж�ʳ��λ�������Ƿ��غ�
				flag = true;

				break;

			}

		}

		if (flag)

			continue;

		Food::x = tmp_x;

		Food::y = tmp_y;

		SetCursorPosition(x, y);//���ù��λ��

		SetColor(13);

		std::cout << "��";

		++cnt;//�жϳԵ�ʳ�����

		cnt %= 5;

		if (cnt == 0)

		{

			DrawBigFood(csnake);

		}

		break;

	}

}



void Food::DrawBigFood(Snake& csnake)//������ʱʳ��

{

	SetCursorPosition(5, 0);//�ڴ˴���ӡ������

	SetColor(13);//���ý���������ɫ

	std::cout << "------------------------------------------" << "<-��ʱʳ���������ʧ";//������

	progress_bar = 42;//��������С

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
				//�ж�������ʳ���غ�
			{

				flag = true;

				break;

			}

		}

		if (flag)

			continue;



		big_x = tmp_x;

		big_y = tmp_y;

		SetCursorPosition(big_x, big_y);//��ʱʳ�������

		SetColor(18);//��ʱʳ�����ɫ

		std::cout << "��";

		big_flag = true;

		flash_flag = true;

		break;

	}

}



int Food::GetCnt()//ʳ��������

{

	return cnt;

}



void Food::FlashBigFood()//��˸��ʱʳ��

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

		std::cout << "��";

		flash_flag = true;

	}



	SetCursorPosition(26, 0);

	SetColor(13);

	for (int i = 42; i >= progress_bar; --i)//����������

		std::cout << "\b \b"; //����˸��

	--progress_bar;

	if (progress_bar == 0) //��ʱʳ����ʧ
	{

		SetCursorPosition(big_x, big_y);

		std::cout << "  ";

		big_flag = false;//ʳ����ʧ����ʱʳ������Ϊfalse

		big_x = 0;

		big_y = 0;

	}

}



bool Food::GetBigFlag()

{

	return Food::big_flag;//������ʱʳ����

}



int Food::GetProgressBar()

{

	return Food::progress_bar;//����ʣ�������������������Ϸ����

}


void Map::PrintInitmap()//���Ƴ�ʼ��ͼ

{

	for (auto& point : initmap)

	{

		point.Print();

		Sleep(10);//����Sleep������Ӫ�춯��Ч��

	}

}


void Point::Print()//�������

{

	SetCursorPosition(x, y);

	std::cout << "��";

}



void Point::PrintCircular()//���Բ��

{

	SetCursorPosition(x, y);

	std::cout << "��";

}



void Point::Clear()//������

{

	SetCursorPosition(x, y);

	std::cout << "  ";

}



void Point::ChangePosition(const int x, const int y)//�ı�����

{

	this->x = x;

	this->y = y;

}


void Snake::InitSnake()//��ʼ����

{

	for (auto& point : snake)

	{

		point.PrintCircular();//���Բ��

	}

}



void Snake::Move()//������

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



void Snake::NormalMove()//�������ƶ���ͷ������β����

{

	Move();

	snake.front().Clear();

	snake.pop_front();

}



bool Snake::OverEdge()//�����߽�

{

	return snake.back().GetX() < 30 &&

		snake.back().GetY() < 30 &&

		snake.back().GetX() > 1 &&

		snake.back().GetY() > 1;

}



bool Snake::HitItself()//ײ������

{

	std::deque<Point>::size_type cnt = 1;

	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������

	for (auto& point : Snake::snake) //���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������

	{
		//��ͷ�����������غ�
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



bool Snake::ChangeDirection()//�ı��ߵķ���

{

	char ch;

	if (kbhit())//kbhit��������ֵΪ��������ע��

	{

		ch = getch();

		switch (ch)

		{

		case -32:

			ch = getch();

			switch (ch)

			{

			case 72://�ϼ���assic

				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч

					direction = Direction::UP;

				break;

			case 80://�¼���assic

				if (direction != Direction::UP)

					direction = Direction::DOWN;

				break;

			case 75://�����assic

				if (direction != Direction::RIGHT)

					direction = Direction::LEFT;

				break;

			case 77://�Ҽ���assic

				if (direction != Direction::LEFT)

					direction = Direction::RIGHT;

				break;

			default:

				break;

			}

			return true;



		case 27://ESC assic�˵�

			return false;



		default:

			return true;


		}

	}

	return true;

}



bool Snake::GetFood(const Food& cfood)//�߳Ե�ʳ��

{

	if (Snake::snake.back().GetX() == cfood.x && Snake::snake.back().GetY() == cfood.y)
		//��ͷ��������β��
		return true;

	else

		return false;

}



bool Snake::GetBigFood(Food& cfood)//�߳Ե���ʱʳ��

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


void StartInterface::PrintFirst()//�ߴ���߳��ֵ���ȫ���ֵĹ���

{

	for (auto& point : startsnake)

	{

		point.Print();//�������

		Sleep(speed);

	}

}



void StartInterface::PrintSecond()//�ߴ��������ƶ��Ĺ���

{

	for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40

	{

		/*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/

		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);

		startsnake.emplace_back(Point(i, j));//���������һ����ͷλ������startsnake��

		startsnake.back().Print();//��ӡ��һ����ͷ

		startsnake.front().Clear();//�ڵ�һ��Ԫ��λ�ô�ӡ" "

		startsnake.pop_front();//������һ���󣬻��տռ�

		Sleep(speed);//�ӳ�

	}

}



void StartInterface::PrintThird()//�ߴӽӴ��ұߵ���ʧ�Ĺ���

{

	while (!startsnake.empty() || textsnake.back().GetX() < 33) //���߻�û��ʧ������û�ƶ���ָ��λ��

	{

		if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�

		{

			startsnake.front().Clear();

			startsnake.pop_front();

		}

		ClearText();//�����������

		PrintText();//���Ƹ���λ�ú������

		Sleep(speed);

	}

}



void StartInterface::PrintText()//�ߣ���ӡ�ߵ�����ͼ��

{

		for (auto& point : textsnake)
		{
	
			if (point.GetX() >= 0)
			{
	
				
				point.Print();
			}
	
		}

}



void StartInterface::ClearText()//�����ͬʱ�����������������ƶ�һ��

{

	for (auto& point : textsnake)

	{

		if (point.GetX() >= 0)

			point.Clear();

		point.ChangePosition(point.GetX() + 1, point.GetY());

	}

}



void StartInterface::Action()//�����������ļ���

{

	PrintFirst();

	PrintSecond();

	PrintThird();

}



void SetWindowSize(int cols, int lines)//���ô��ڴ�С

{

	//system("̰����--���ִ�ѧ");//���ô��ڱ���
	//Sleep(10000);
	char cmd[30];

	sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ��ռ�����ַ����ʿ�ȳ���2

	system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�

}



void SetCursorPosition(const int x, const int y)//���ù��λ��

{

	COORD position;  //��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����

	position.X = x * 2;

	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}



void SetColor(int colorID)//�����ı���ɫ

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);

}



void SetBackColor()//�����ı�����ɫ

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