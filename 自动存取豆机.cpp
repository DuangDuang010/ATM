#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"
#include"iostream"
#include"cstdlib"
#include"ctime"
#include"cmath"



//光标定位
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

void start();

//中文
void C_Sign_Up();                      //中文注册
void C_Sign_In();                      //中文登录 
void C_Main_Menu();                    //中文主菜单页
void C_DepositMoney();                 //中文存豆业务
void C_DepositMoney1();                //中文存豆失败选项
void C_DepositMoney2();                //中文存豆成功选项
void C_Withdraw_Money();               //中文取豆业务
void C_Withdraw_Money1();              //中文取豆失败选项
void C_Withdraw_Money2();              //中文取豆成功选项
void C_Transfer_Money();               //中文转豆业务
void C_Transfer_Money1();              //中文转豆失败选项
void C_Transfer_Money2();              //中文转豆失败选项
void C_Enquiry();                      //中文查询业务
void C_Enquiry_balance();              //中文查询余豆
void C_Enquiry_Information();          //中文查询个人信息
void C_Enquiry_Record();               //中文查询流水记录
void C_Change_Information();           //中文修改信息选项页
void C_Change_User();                  //中文修改用户名称
void C_Change_AccountNum();            //中文修改账户
void C_Change_phone();                 //中文修改联系电话
void C_Change_Password();              //中文修改密码

//English
void E_Sign_Up();                      //英文注册
void E_Sign_In();                      //英文登录 
void E_Main_Menu();                    //英文菜单页
void E_DepositMoney();                 //英文存豆业务
void E_Withdraw_Money();               //英文取豆业务
void E_Transfer_Money();               //英文转账业务
void E_Enquiry();                      //英文查询业务
void E_Enquiry_balance();              //英文查询余豆
void E_Enquiry_Information();          //英文查询个人信息
void E_Enquiry_Record();               //英文查询流水记录
void E_Change_Information();           //英文修改信息选项页
void E_Change_User();                  //英文修改用户名称
void E_Change_AccountNum();            //英文修改账户
void E_Change_phone();                 //英文修改联系电话
void E_Change_Password();              //英文修改密码

//中文简洁
void C_Easy_Main_Menu();               //中文简洁主菜单页
void C_Easy_DepositMoney1();           //中文简洁存豆成功选项
void C_Easy_DepositMoney2();           //中文简洁存豆失败选项
void C_Easy_Withdraw_Money1();         //中文简洁取豆成功选项
void C_Easy_Withdraw_Money2();         //中文简洁取豆失败选项
void C_Easy_Transfer_Money1();         //中文简洁转豆成功选项
void C_Easy_Transfer_Money2();         //中文简洁转豆失败选项

//CE
void gotoxy();
void getPassword();
void CE_Time();                       //系统时间
void CE_Close_Account();              //注销账户选项页
void CE_Close_Account1();             //注销账户
void CE_Save_User_Data();             //保存用户数据
void CE_Save_Transaction_Data();      //保存交易数据
void CE_Initial_Password();           //初始化密码函数
void CE_Initialize_User_Data();       //初始化用户数据
void CE_Initialize_Transaction_Data();//初始化交易数据
void CE_Set_Name();                   //中英文设置姓名
void CE_Set_Password();               //中英文设置密码
void CE_Set_PhoneNumber();            //中英文设置电话号码
void CE_Add_Account_Number();         //中英文设置账户号码函数
void CE_Game_Transaction();           //游戏收入交易
void CE_GameOut_Transaction();        //游戏支出交易
void CE_Deposit_Transaction();        //存豆交易
void CE_Withdraw_Transaction();       //取豆交易
void CE_Transfer_Transaction();       //转豆交易
void CE_SXF();                        //手续费
void CE_SXF_Transaction();            //手续费交易
void CE_Print_Transaction();          //打印交易记录
void CE_Game();
void CE_Game_KK();
void TCS();                           //贪吃蛇游戏
void hide();
void print_wall();
void print_snake();
bool is_correct();
bool print_food();
bool go_ahead();
void locate();
void STJDB();                         //猜拳游戏
void DZ();                            //打字游戏

int Language, Sin, Bank;
int Random_Number;           //随机数
int ACCOUNT;                 //当前账号数值
int TACCOUNT;                //当前对方账号数值
int SXF;                     //手续费
float SXFmoey;               //手续费金额
int AccountNum1 = 1231231000;//一号很行
int AccountNum2 = 1231232000;//二号很行
int AccountNum3 = 1231233000;//三号很行
int TCSm, TCSn;
char str[50];

//贪吃蛇结构体
struct TCSnode
{
	int x, y;
}snake[1000];
int snake_length, dir;
TCSnode food;
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

//用户信息链表
struct Account
{
	//char bank[100];//银行
	char name[100];//用户名称
	char account_number[50];//账户账号
	char phone_number[12];//电话号码
	char password[10];//密码
	float balance;//余豆

	struct Account* next;
};

//交易信息链表
struct Trade
{
	char Taccount_number[50];//账户账号
	char Time[100];//时间
	char Operation[100];//操作类型
	char TarUse[50];//目标账户账号
	float Money;//操作数量

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;

//用户信息
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account IV;

//交易信息
Trade* Thead = NULL;
Trade* Ttail = NULL;
Trade* TcurAccount;
Trade TA;
char tmp1[100];

//选项光标
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
using namespace std;


//游戏界面
void CE_Game()
{
	int a, a1, k = 0;
	while (k < 3)
	{
		printf("\n【小游戏攒豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t【1】贪吃蛇\n");
		printf("\n\n\t\t【2】猜拳游戏\n");
		printf("\n\n\t\t【3】打字游戏\n");
		printf("\n\n\t\t【4】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			k = 0;
			while (k < 3)
			{
				printf("\n【贪吃蛇】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|----------------------贪吃蛇-----------------------\n");
				printf("\t|【1】请注意窗口大小,以免发生错位.建议将窗口调为最大。\n\t|\n");
				printf("\t|【2】先选择难度.请在1-10中输入1个数,1最简单,10则最难。\n\t|\n");
				printf("\t|【3】游戏结束后,可获得长度X100豆的奖励，加油攒豆吧。\n\t|\n");
				printf("\t|【4】进入游戏后将自动扣取您的欢乐豆，告知后，不能退还。\n\t|\n");
				printf("\t|【5】进入游戏画面后,以*方向键*控制方向.祝你游戏愉快!\n");
				printf("\t|---------------------------------------------------\n");
				printf("\n\n\t\t【价格￥】1000豆/局\n");
				printf("\n\n\t\t【1】购买后继续游戏\n");
				printf("\n\n\t\t【2】返回上一页\n");
				printf("\n\n\t\t【3】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t你的选择：___\b\b\b");
				scanf("%d", &a1);
				switch (a1)
				{
				case 1:
					system("cls");
					TCS();
					k = 3;
					break;
				case 2:
					system("cls");
					CE_Game();
					k = 3;
					break;
				case 3:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					system("cls");
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
			k = 3;
			break;
		case 2:
			system("cls");
			k = 0;
			while (k < 3)
			{
				printf("\n【猜拳游戏】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|----------------------猜拳游戏-----------------------\n");
				printf("\t|【1】这是一个猜拳的小游戏，你根据你的想法出拳打败电脑。\n\t|\n");
				printf("\t|【2】电脑为随机出拳，每次游戏将消耗您所确定筹码等额的欢乐豆。\n\t|\n");
				printf("\t|【3】筹码需为100的整数，单次押注不得超过10000，否者无效。\n\t|\n");
				printf("\t|【4】您和电脑打成平手，系统将加赠奖励你100欢乐豆以示鼓励。\n\t|\n");
				printf("\t|【5】每打败电脑，你将获得你筹码两倍的欢乐豆，祝你游戏愉快!\n");
				printf("\t|-----------------------------------------------------\n");
				printf("\n\n\t\t【1】开始游戏\n");
				printf("\n\n\t\t【2】返回上一页\n");
				printf("\n\n\t\t【3】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t你的选择：___\b\b\b");
				scanf("%d", &a1);
				switch (a1)
				{
				case 1:
					system("cls");
					STJDB();
					k = 3;
					break;
				case 2:
					system("cls");
					CE_Game();
					k = 3;
					break;
				case 3:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					system("cls");
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
			k = 3;
			break;
		case 3:
			system("cls");
			k = 0;
			while (k < 3)
			{
				printf("\n【打字游戏】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|------------------------打字游戏-------------------------\n\t|\n");
				printf("\t|【1】输入任意键开始，根据屏幕显示输入字符，输入正确有*号提示。\n\t|\n");
				printf("\t|【2】游戏过程中可按 ESC 暂停或结束游戏，并获得游戏豆奖励。\n\t|\n");
				printf("\t|【3】此游戏仅需100豆/局，可提升玩家的反应能力 打字速度 视力。\n\t|\n");
				printf("\t|【4】10个以下无奖金，10个起 每正确10个可获得100欢乐豆的奖励。\n\t|\n");
				printf("\t|【5】告知扣款后将无法追后退款，最后.祝你游戏愉快!\n");
				printf("\t|-------------------------------------------------------\n");
				printf("\n\n\t\t【1】开始游戏\n");
				printf("\n\n\t\t【2】返回上一页\n");
				printf("\n\n\t\t【3】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t你的选择：___\b\b\b");
				float z;
				scanf("%d", &a1);
				switch (a1)
				{
				case 1:
					system("cls");
					TA.Money = -100.00;
					z = -TA.Money;
					printf("\n\t\t\t已经收取您的%0.2f欢乐豆，已告知。\n", z);
					CE_Game_KK();
					DZ();
					k = 3;
					break;
				case 2:
					system("cls");
					CE_Game();
					k = 3;
					break;
				case 3:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					system("cls");
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
			k = 3;
			break;
		case 4:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}
//光标
void locate(int x, int y)
{
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};
//隐藏光标
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cursor_info);
}
//生成随机数
double random(double start, double end)
{
	return start + (end - start) * rand() / (RAND_MAX + 1.0);
}
//贪吃蛇输出墙
void print_wall()
{
	printf(" ");
	for (int i = 1; i <= TCSn; i++)
		printf("-");
	printf("\n");
	for (int j = 0; j <= TCSm - 1; j++)
	{
		printf("|");
		for (int i = 1; i <= TCSn; i++) printf(" ");
		printf("|\n");
	}
	printf(" ");
	for (int i = 1; i <= TCSn; i++)
		printf("-");
}
//贪吃蛇输出墙
void print_snake()
{
	locate(snake[0].x, snake[0].y);
	printf("O");
	for (int i = 1; i <= snake_length - 1; i++)
	{
		locate(snake[i].x, snake[i].y);
		printf("o");
	}
}
//判断是否撞墙或者自撞
bool is_correct()
{
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == TCSm + 1 || snake[0].y == TCSn + 1) return false;
	for (int i = 1; i <= snake_length - 1; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) return false;
	}
	return true;
}
//随机生成并输出食物位置
bool print_food()
{
	srand((unsigned)time(0));
	bool e;
	while (1)
	{
		e = true;
		int i = (int)random(0, TCSm) + 1, j = (int)random(0, TCSn) + 1;
		food.x = i; food.y = j;
		for (int k = 0; k <= snake_length - 1; k++)
		{
			if (snake[k].x == food.x && snake[k].y == food.y)
			{
				e = false; break;
			}
		}
		if (e) break;
	}
	locate(food.x, food.y);
	printf("8");
	return true;
}
//蛇的前进
bool go_ahead()
{
	TCSnode temp;
	bool e = false;
	temp = snake[snake_length - 1];
	for (int i = snake_length - 1; i >= 1; i--)
		snake[i] = snake[i - 1];
	snake[0].x += direct[dir][0];
	snake[0].y += direct[dir][1];
	locate(snake[1].x, snake[1].y);
	printf("o");
	/*** 吃到了食物 ***/
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		snake_length++;
		e = true;
		snake[snake_length - 1] = temp;
	}
	/*** 输出此时蛇状态 ***/
	if (!e)
	{
		locate(temp.x, temp.y);
		printf(" ");
	}
	else
		print_food();
	locate(snake[0].x, snake[0].y);
	printf("O");
	/*** 如果自撞 ***/
	if (!is_correct())
	{
		system("cls");
		TA.Money = snake_length * 100.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t你输了！\n");
		printf("\n\t\t\t你的成绩为：%d\n", snake_length);
		printf("\n\t\t\t你获得的奖励为：%0.2f欢乐豆，请查收！\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t【1】重新开始游戏\n");
			printf("\n\n\t\t【2】退出游戏\n");
			printf("\n\n\t\t【3】返回主页\n");
			printf("\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				TCS();
				k = 3;
				break;
			case 2:
				system("cls");
				CE_Game();
				k = 3;
				break;
			case 3:
				system("cls");
				C_Main_Menu();
				k = 3;
				break;
			case 0:
				system("cls");
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
		return false;
	}
	return true;
}
//贪吃蛇游戏
void TCS()
{
	TA.Money = -1000.00;
	float z = -TA.Money;
	CE_Game_KK();
	printf("\n\t\t\t已经收取您的%0.2f欢乐豆，已告知。\n", z);
	TCSm = 25;
	TCSn = 40;
	if (TCSm < 10 || TCSn < 10 || TCSm>25 || TCSn>40)
	{
		printf("\n\t\t\tERROR\n");
		system("pause");
		exit(0);
	}
	int hard;
	printf("\n\n\n\n\t\t\t\t选择难度为：__\b\b");
	scanf("%d", &hard);
	if (hard <= 0 || hard > 100)
	{
		printf("\n\t\t\tERROR\n");
		system("pause");
		exit(0);
	}
	/*** 数据全部初始化，包括蛇长，位置，方向 ***/
	snake_length = 5;
	clock_t a, b;
	char ch;
	double hard_len;
	for (int i = 0; i <= 4; i++)
	{
		snake[i].x = 1;
		snake[i].y = 5 - i;
	}
	dir = 3;
	/*** 输出初始地图，蛇与食物 ***/
	system("cls");
	hide();
	print_wall();
	print_food();
	print_snake();
	locate(TCSm + 2, 0);
	printf("现在的长度:");
	/*** 开始游戏 ***/
	while (1)
	{
		/*** 难度随长度增加而提高 ***/
		hard_len = (double)snake_length / (double)(TCSm * TCSn);
		/*** 调节时间，单位是ms ***/
		a = clock();
		while (1)
		{
			b = clock();
			if (b - a >= (int)(400 - 30 * hard) * (1 - sqrt(hard_len))) break;
		}
		/*** 接受键盘输入的上下左右，并以此改变方向 ***/
		if (kbhit())
		{
			ch = getch();
			if (ch == -32)
			{
				ch = getch();
				switch (ch)
				{
				case 72:
					if (dir == 2 || dir == 3)
						dir = 0;
					break;
				case 80:
					if (dir == 2 || dir == 3)
						dir = 1;
					break;
				case 75:
					if (dir == 0 || dir == 1)
						dir = 2;
					break;
				case 77:
					if (dir == 0 || dir == 1)
						dir = 3;
					break;
				}
			}
		}
		/*** 前进 ***/
		if (!go_ahead()) break;
		/*** 在最后输出此时长度 ***/
		locate(TCSm + 2, 12);
		printf("%d", snake_length);
	}
	system("pause");
	exit(0);
}

//猜拳游戏
void STJDB()
{
	int gamer;   // 玩家出拳
	int CM;      //筹码
	int computer;// 电脑出拳
	srand((unsigned)time(NULL));  // 随机数种子
	computer = (rand() % 3) + 1;        // 产生随机数并取余，得到电脑出拳
	printf("\n\n\t\t\t请输入你的筹码：_____\b\b\b\b\b");
	scanf("%d", &CM);
	TA.Money = CM * -1.00;
	float z = -TA.Money;
	CE_Game_KK();
	int k11 = 0;
	while (k11 < 3)
	{
		system("cls");
		printf("\n\t\t\t已经收取您的%0.2f欢乐豆，已告知。\n", z);
		printf("\n\n\t\t\t请输入你要出的拳头：___\b\b\b\n");
		printf("\n\n\t1:剪刀\n\n\n\t2:石头\n\n\n\t3:布\n\n\n\t0:不玩了\n");
		scanf("%d", &gamer) || scanf("%c", gamer);
		switch (gamer)
		{
		case 1:
			k11 = 3;
			break;
		case 2:
			k11 = 3;
			break;
		case 3:
			k11 = 3;
			break;
		case 0:
			system("cls");
			exit(0);
		default:
			printf("你的选择为 %d 选择错误\n", gamer);
			k11++;
			break;
		}
	}
	printf("电脑出了—");
	switch (computer)
	{
	case 1:
		printf("【剪刀】");
		break;
	case 2:
		printf("【石头】");
		break;
	case 3:
		printf("【布】");
		break;
	}
	printf("你出了—");
	switch (gamer)
	{
	case 1:
		printf("【剪刀】\n");
		break;
	case 2:
		printf("【石头】\n");
		break;
	case 3:
		printf("【布】\n");
		break;
	}
	if ((computer == 1 && gamer == 2) || (computer == 2 && gamer == 3) || (computer == 3 && gamer == 1))
	{
		printf("\t\t\t\t\t\t》【你赢了!】《\n\n");
		TA.Money = CM * 2.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t你获得的奖金%0.2f欢乐豆，请查收！\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t【1】再来一局\n");
			printf("\n\n\t\t【2】退出游戏\n");
			printf("\n\n\t\t【3】返回主页\n");
			printf("\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				STJDB();
				k = 3;
				break;
			case 2:
				system("cls");
				CE_Game();
				k = 3;
				break;
			case 3:
				system("cls");
				C_Main_Menu();
				k = 3;
				break;
			case 0:
				system("cls");
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else if (gamer == computer)
	{
		printf("\t\t\t\t\t\t》【平手】《\n\n");
		TA.Money = CM * 1.00 + 100.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t你获得的奖励金并已退回筹码共%0.2f欢乐豆，请查收！\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t【1】再来一局\n");
			printf("\n\n\t\t【2】退出游戏\n");
			printf("\n\n\t\t【3】返回主页\n");
			printf("\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				STJDB();
				k = 3;
				break;
			case 2:
				system("cls");
				CE_Game();
				k = 3;
				break;
			case 3:
				system("cls");
				C_Main_Menu();
				k = 3;
				break;
			case 0:
				system("cls");
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		printf("\t\t\t\t\t\t》【你输掉了】《\n\n");
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t【1】再来一局\n");
			printf("\n\n\t\t【2】退出游戏\n");
			printf("\n\n\t\t【3】返回主页\n");
			printf("\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				STJDB();
				k = 3;
				break;
			case 2:
				system("cls");
				CE_Game();
				k = 3;
				break;
			case 3:
				system("cls");
				C_Main_Menu();
				k = 3;
				break;
			case 0:
				system("cls");
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
}

//打字游戏
void DZ() {
	const int ESCKEY = 27; //定义整型常量ESCKEY，赋值为ESC键的ASCII编码
	int pos, posmax = 72;  //当前位置，右边界最大位置
	int win = 0, loss = 0; //已赢局数和已输局数
	getchar();
	int ch = 0, key = 0; //随机字符，玩家键入字符
	srand(time(0)); //设置随机数种子
	while (key != ESCKEY)//主循环。key 不是 ESC键时玩游戏
	{
		ch = rand() % ('z' + 1 - 'a') + 'a'; //产生随机字符
		for (pos = 0; pos < posmax && key != 27; pos++)
		{
			printf("\b--%c", (char)ch);
			pos++;
			Sleep(150);
			if (kbhit() && (key = getch()) == ch)
			{
				win++;
				printf("*\a");//输出 * 并响铃
				break;
			}
		}
		if (key == ESCKEY) //用户键入ESC键，需要确认
		{
			printf("\n结束游戏吗？\n");
			printf("\n\n\t\t【1】是\n");
			printf("\n\n\t\t【2】否");
			printf("\n\n\t\t__\b\b");
			while ((key = tolower(getchar())) != '1' && ch != '2')
				;    //空循环体
			key = (key == '1' ? ESCKEY : 0);
		}
		if (pos >= posmax)
		{
			loss++;
		}
		printf("\n");
	}
	int win1 = win / 10 - 1;
	if (win1 < 0)
		win1 = 0;
	TA.Money = win1 * 100.00;
	float z = TA.Money;
	curAccount->balance = curAccount->balance + TA.Money;
	printf("字符练习个数：%d\n", win + loss);
	printf("正确键入个数：%d\n", win);
	printf("\n\t\t\t你获得的奖励为：%0.2f欢乐豆，请查收！\n", z);
	CE_Game_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t【1】重新开始游戏\n");
		printf("\n\n\t\t【2】退出游戏\n");
		printf("\n\n\t\t【3】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			DZ();
			k = 3;
			break;
		case 2:
			system("cls");
			CE_Game();
			k = 3;
			break;
		case 3:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}



	printf("游戏结束，谢谢使用\n");
}

//游戏扣款
void CE_Game_KK()
{
	CE_Time();
	if (curAccount->balance + TA.Money < 0)
	{
		int k = 0, b;
		system("cls");
		printf("\n\n\n欢乐豆不足!!!!\n");
		while (k < 3)
		{
			printf("\n\n\n\t\t【1】去存豆");
			printf("\n\n\n\t\t【2】返回上一页");
			printf("\n\n\n\t\t【3】返回主页");
			printf("\n\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				C_DepositMoney();
				k = 3;
				break;
			case 2:
				system("cls");
				CE_Game();
				k = 3;
				break;
			case 3:
				system("cls");
				C_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		CE_GameOut_Transaction();
	}
}

//中英文游戏支出流水记录
void CE_GameOut_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		CE_Time();
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "GB");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "购买游戏");
		CE_Save_Transaction_Data();
	}
}

//中英文游戏收入流水记录
void CE_Game_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		CE_Time();
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "GA");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "游戏奖励");
		CE_Save_Transaction_Data();
	}
}

//星号密码
void getPassword(char* storePw, int maxPwLen)
{
	char c = '\0';          //存放用户键入的每个字符
	char* pc = storePw;    //为方便指向密码字符串中每个字符
	int pwlen = 0;          //当前password的长度

	while (1)
	{
		c = getch();

		//如果用户按下回车符，停止循环
		if (c == '\r')
			break;

		//将用户输入的有效字符存入密码串，不考虑空字符'\0'
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

//查找当前账户
int findAccount(Account IV1)//登录时查找当前账户
{
	Account* curP = head;
	Trade* TcurP = Thead;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV1.account_number) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//验证当前账户密码
int findPassword(Account IV1)//登录时查找当前账户密码
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV1.account_number) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//查找是否被已有账户
int findAccount2(Account IV)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV.account_number) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//查找转账对象
int findAccount3(Account TT)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->account_number, TT.account_number) == 0)
		{
			int b, k = 0;
			if (Language == 1)
				printf("\n不能给自己转账！！！\n");
			else
				printf("\nYou can't transfer money to yourself! ! !\n");
			while (k < 3)
			{
				if (Language == 1)
				{
					printf("\n\n\n\t\t【1】重新输入对方账户号码");
					printf("\n\n\n\t\t【2】返回主页");
					printf("\n\n\n\t\t【0】退出系统\n\n");
				}
				else
				{
					printf("\n\n\n\t\t【1】Re-enter the account number of the other party");
					printf("\n\n\n\t\t【2】Return to the homepage");
					printf("\n\n\n\t\t【0】Exit the system\n\n");
				}
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					if (Language == 1)
						C_Transfer_Money();
					else
						E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else if (strcmp(curP->account_number, TT.account_number) == 0)
		{
			curAccountO = curP;//当前转账对象账户
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//时间
void CE_Time()
{
	time_t t = time(0);
	Random_Number = time(0) % 4 + 1;
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strftime(tmp1, sizeof(tmp), "%Y-%m-%d", localtime(&t));
	strcpy(TA.Time, tmp);
}

//注销
void CE_Close_Account()
{
	printf("\n\n\t此界面为注销账户界面，是否继续注销该账户？\n\n\t【温馨提示】1.注销前请确认余额是否清0，如果账户余额未清0，账号将无法注销成功。\n\n\t\t2.如果继续注销账号将会被回收，届时您将无法再次登录该账号。");
	int aaa, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t【1】继续注销\n");
		printf("\n\n\t\t【2】不了，返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		scanf("%d", &aaa);
		switch (aaa)
		{
		case 1:
			system("cls");
			CE_Close_Account1();
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\t输入错误！\n");
			k1 = 1;
			break;
		}
	}
}

//注销
void CE_Close_Account1()
{
	if (curAccount->balance != 0)
	{
		printf("\n\n\t\t注销失败：欢乐豆未清零。\n");
		printf("\n\n\t\t欢乐豆余额：%d\n", curAccount->balance);
		int a, k1 = 1;
		while (k1)
		{
			k1 = 0;
			printf("\n\n\t\t【1】去转账\n");
			printf("\n\n\t\t【2】返回主页\n");
			printf("\n\n\t\t【0】退出系统\n");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				C_Transfer_Money();
				break;
			case 2:
				system("cls");
				C_Main_Menu();
				break;
			case 0:
				system("cls");
				CE_Save_User_Data();
				exit(0);
				break;
			default:
				system("cls");
				printf("\n\n\t\t输入错误！\n");
				k1 = 1;
				break;
			}
		}
	}
	else
	{
		printf("\n\n\t\t注销成功，欢迎您下次光临。\n");
		strcpy(curAccount->name, "XXXX");
		strcpy(curAccount->account_number, "XXXX");
		strcpy(curAccount->phone_number, "XXXX");
		strcpy(curAccount->password, "XXXX");
		CE_Save_User_Data();
		exit(0);
	}

}

//保存用户数据
void CE_Save_User_Data()
{
	FILE* fp = fopen("D:/atm.txt", "w");//保存用户数据
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->account_number, curP->name, curP->phone_number, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

//保存交易数据
void CE_Save_Transaction_Data()
{
	FILE* Tfp = fopen("D:/atmtrade.txt", "at+");//保存交易数据
	if (Tfp != NULL)
	{
		Trade* TcurP = Thead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%s\t%f\n", TcurP->Taccount_number, TcurP->Time, TcurP->Operation, TcurP->TarUse, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

//初始化用户信息
void CE_Initialize_User_Data()
{
	FILE* fp = fopen("D:/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->account_number, newNodeP->name, newNodeP->phone_number, newNodeP->password, &newNodeP->balance);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

//初始化交易信息
void CE_Initialize_Transaction_Data()
{
	FILE* Tfp = fopen("D:/atmtrade.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%s\t%f\n", TnewNodeP->Taccount_number, TnewNodeP->Time, TnewNodeP->Operation, TnewNodeP->TarUse, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (Thead == NULL)
			{
				Thead = TnewNodeP;
				Ttail = TnewNodeP;
			}
			else
			{
				Ttail->Tnext = TnewNodeP;
				Ttail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

//初始化密码
void CE_Initial_Password()
{
	strcpy(curAccount->password, "XXXXXX");
}

//中英文设置姓名
void CE_Set_Name()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>请输入你的姓名：\n");
		}
		else
			printf("\n\t>>Please enter your name:\n");
		scanf("%s", IV.name);
		if (strlen(IV.name) < 100)
		{
			strcpy(Pset->name, IV.name);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\t你的姓名设置过长。\n\n\t请重新设置：\n");
			}
			else
				printf("\n\t\tYour name is set too long.\n\n\tPlease reset it:\n");
		}
	}
}

//中英文设置密码
void CE_Set_Password()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>请设置你的账户密码【6位】：\n");
		}
		else
			printf("\n\t>>Please set your account password [6 digits]：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(IV.password, storePassword);
		if (strlen(IV.password) == 6)
		{
			strcpy(Pset->password, IV.password);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\t密码为六位，你的密码设置有误！\n\n\t请重新设置：\n");
			}
			else
				printf("\n\t\tThe password is six digits, your password is set incorrectly！\n\n\tPlease reset it:\n");

		}
	}
}

//中英文设置电话号
void CE_Set_PhoneNumber()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>请输入你的电话号码【11位】：\n");
		}
		else
			printf("\n\t>>Please enter your phone number [11 digits]:\n");
		scanf("%s", IV.phone_number);
		if (strlen(IV.phone_number) == 11)
		{
			strcpy(Pset->phone_number, IV.phone_number);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\t预留号码应为十一位数，你的预留号码设置有误！\n\n\t请重新输入：\n");
			}
			else
				printf("\n\t\tThe reserved number should be eleven digits, your reserved number is set incorrectly!\n\n\tPlease reset it:\n");
		}
	}
}

//中英文增加账户账号
void CE_Add_Account_Number()
{
	switch (Bank)
	{
	case 1:
		AccountNum1++;
		itoa(AccountNum1, IV.account_number, 10);
		break;
	case 2:
		AccountNum2++;
		itoa(AccountNum2, IV.account_number, 10);
		break;
	case 3:
		AccountNum3++;
		itoa(AccountNum3, IV.account_number, 10);
		break;
	}
	while (findAccount2(IV))
	{
		switch (Bank)
		{
		case 1:
			AccountNum1++;
			itoa(AccountNum1, IV.account_number, 10);
			break;
		case 2:
			AccountNum2++;
			itoa(AccountNum2, IV.account_number, 10);
			break;
		case 3:
			AccountNum3++;
			itoa(AccountNum3, IV.account_number, 10);
			break;
		}

	}
}

//中英文存豆流水记录
void CE_Deposit_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "AA");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "由本账户存豆");
		CE_Save_Transaction_Data();
	}
}

//中英文取豆流水记录
void  CE_Withdraw_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BB");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "由本账户取豆");
		CE_Save_Transaction_Data();
	}
}

//中英文转豆转出流水记录
void  CE_Transfer_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BA");
		strcpy(TP->TarUse, curAccountO->account_number);
		TP->Money = TA.Money;
		CE_Save_Transaction_Data();
	}


	//转账转入流水记录

	Trade* TPi = (Trade*)malloc(sizeof(Trade));//定义交易结构体 变量 转入TPi
	TPi->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TPi;
		Ttail = TPi;
	}
	else
	{
		Ttail->Tnext = TPi;
		Ttail = TPi;//我滴天哪
		strcpy(TPi->Taccount_number, curAccountO->account_number);//当前转入账号赋值给TPi
		strcpy(TPi->Time, TA.Time);//当前时间赋值给TPi
		strcpy(TPi->Operation, "AB");//当前操作类型赋值给TPi
		strcpy(TPi->TarUse, curAccount->account_number);
		TPi->Money = -TA.Money;//当前交易金额赋值给TPi
		CE_Save_Transaction_Data();
	}
}

//中英文手续费倍率
void CE_SXF()
{
	int HX;
	if (TACCOUNT >= AccountNum1 && TACCOUNT < AccountNum2)      //对方账户为一号很行
	{
		HX = 1;
	}
	else if (TACCOUNT >= AccountNum2 && TACCOUNT < AccountNum3) //对方账户为二号很行
	{
		HX = 2;
	}
	else if (TACCOUNT >= AccountNum3 && TACCOUNT < 1231234000)  //对方账户为三号很行
	{
		HX = 3;
	}
	if (ACCOUNT >= AccountNum1 && ACCOUNT < AccountNum2)        //当前账户为一号很行
	{
		if (HX == 1)             //同行
			SXF = 2;
		else                     //异行
			SXF = 5;
	}
	else if (ACCOUNT >= AccountNum2 && ACCOUNT < AccountNum3)   //当前账户为二号很行
	{
		if (HX == 2)
			SXF = 2;
		else
			SXF = 5;
	}
	else if (ACCOUNT >= AccountNum3 && ACCOUNT < 1231234000)   //当前账户为三号很行
	{
		if (HX == 3)
			SXF = 2;
		else
			SXF = 5;
	}
}

//中英文手续费流水记录
void CE_SXF_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;//我滴天哪
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "CC");
		strcpy(TP->TarUse, "本账户转豆");
		TP->Money = -SXFmoey;
		CE_Save_Transaction_Data();
	}
}


//AA存款
//BB取款 
//AB转帐
//CC手续费 
//GAB游戏

//中英文打印流水
void CE_Print_Transaction()
{
	int k = 0, w = 0;
	Trade* TcurP = Thead;
	if (Language == 1)
		printf("\n序号\t时间：\t\t\t\t交易类型：\t\t交易欢乐豆数量：\t交易备注：\n\n");
	else
		printf("\nNum:\tTime:\t\t\t\tTrading Type:\t\tTrading Bean quantity:\tRemark:\n\n");
	while (TcurP != NULL)//交易记录
	{
		if (strcmp(curAccount->account_number, TcurP->Taccount_number) == 0)
		{
			w++;
			TcurAccount = TcurP;
			if (Language == 1)
			{
				if (strcmp(TcurAccount->Operation, "AA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t存豆/收入\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t存豆/收入\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t取豆/支出\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t取豆/支出\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t转豆/支出\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t转豆/支出\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "AB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t转豆/收入\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t转豆/收入\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "CC") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t手续费/支出\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t手续费/支出\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "GB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t游戏/支出\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t游戏/支出\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "GA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t游戏/收入\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t游戏/收入\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}

			}
			else
			{
				if (strcmp(TcurAccount->Operation, "AA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSave\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSave\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tTake\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tTake\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "AB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSend\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSend\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSend\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSend\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "CC") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\thandling fee\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\thandling fee\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
			}

			k++;
		}
		TcurP = TcurP->Tnext;
	}
	if (k == 0)
	{
		if (Language == 1)
			printf("\n\t暂=无=交=易=记=录\n\t\t\n\n");
		else
			printf("\n\tNo transaction record now.\n\t\t\n\n");
	}
}

//选择很行
void CE_ChooseBank()
{
	int a, k = 1;
	while (k)
	{
		k = 0;
		if (Language == 1)
		{
			printf("\n请选择你要注册账号的所属很行：\n\n");
			printf("\n\n\t\t【1】一号很行\n");
			printf("\n\n\t\t【2】二号很行\n");
			printf("\n\n\t\t【3】三号很行\n");
			printf("\n\n\t\t【4】成年人不想做选择，请随便来一个\n");
			printf("\n\n\t\t【0】退出系统\n");
			printf("\n\n\t\t\t你的选择：___\b\b\b");
		}
		else
		{
			printf("\nPlease 选择你要注册账号的所属很行：\n\n");
			printf("\n\n\t\t【1】One Bean Bank\n");
			printf("\n\n\t\t【2】Two Bean Bank\n");
			printf("\n\n\t\t【3】Three Bean Bank\n");
			printf("\n\n\t\t【4】Any Bank\n");
			printf("\n\n\t\t【0】Exit the system\n");
			printf("\n\n\t\t\tYour choice：___\b\b\b");
		}
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Bank = 1;
			break;
		case 2:
			Bank = 2;
			break;
		case 3:
			Bank = 3;
			break;
		case 4:
			Bank = 1;
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\tEnter eroor！\n");
			k = 1;
			break;
		}
	}
}

//中文注册
void C_Sign_Up()//中文注册函数
{
	int a, k = 0;
	system("cls");
	printf("\n【注册】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_ChooseBank();
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//已定义
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//如果这是第一个创建的结点，则将头 尾指针指向这个结点
	}
	else
		tail->next = Pset; //如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
	CE_Set_Name();//跳转中文设置姓名函数
	CE_Add_Account_Number();//跳转到中文设置账户号码函数
	strcpy(Pset->account_number, IV.account_number);
	CE_Set_PhoneNumber();//跳转到中文设置预留电话函数
	CE_Set_Password();//跳转到中文设置密码函数
	Pset->balance = 0;
	CE_Save_User_Data();
	while (k < 3)
	{
		system("cls");
		printf("\n\t\t注=册=成=功\n");
		printf("\n\t>>你的账户号码为 %s\n", Pset->account_number);
		printf("\n\n\t\t【1】返回登录\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		if (a == 1)
		{
			system("cls");
			C_Sign_In();
			break;
		}
		else if (a == 0)
		{
			exit(0);
		}
		else
		{
			k++;
			printf("\n密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//英语注册
void E_Sign_Up()//英语注册函数
{
	int a, k = 0;
	printf("\n==============Welcome to register================\n\n");

	CE_ChooseBank();
	Pset->next = NULL;
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;
	}
	else
	{
		tail->next = Pset;
		CE_Set_Name();
		CE_Add_Account_Number();
		strcpy(Pset->account_number, IV.account_number);
		CE_Set_PhoneNumber();
		CE_Set_Password();
		Pset->balance = 0;
		CE_Save_User_Data();
		while (k < 3)
		{
			system("cls");
			printf("\n\t\tRegistration Success!\n");
			printf("\n\t>>Your account number is  %s\n", Pset->account_number);
			printf("\n\n\t\t【1】 Return to login\n");
			printf("\n\n\t\t【0】 Exit the system\n");
			printf("\n\n\t\t\tYour chioce：___\b\b\b");
			scanf("%d", &a);
			if (a == 1)
			{
				system("cls");
				E_Sign_In();
				break;
			}
			else if (a == 0)
			{
				exit(0);
			}
			else
			{
				k++;
				printf("\nPassword entered incorrectly! \t%d\tPlease re-enter as prompted:\n", 3 - k);
			}
		}
	}
}

//中文登录
void C_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3次输入错账号将退出系统
	{
		Account IV1;//账户中间变量1
		printf("\n【登录】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>请输入账号：\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3次输入错密码将退出系统
			{
				printf("\n【登录】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\n\n\n\t>>请输入密码：\n");
				char storePassword[10] = { '\0' };    //存储用户输入的密码
				printf("\n\n\t\t\t______\b\b\b\b\b\b");
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (findPassword(IV1))
				{
					m = 3;
					n = 3;
					if (Sin == 1)
						C_Main_Menu();
					else if (Sin == 3)
						C_Easy_Main_Menu();
					else
						C_Main_Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\n\t该账号已经被冻结，请联系后台找回。\n");
						CE_Initial_Password();
						break;
					}
					else
					{
						printf("\n\n\t密码错误  %d次机会后账号将会被冻结\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\t没有查找到该用户!  %d  请重新输入：\n", 3 - m);
			if (m == 3)
			{
				printf("\n\n\t错误，已退出系统\n");
				CE_Save_User_Data();
				exit(0);
			}
		}
	}
}

//英语登录
void E_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3次输入错账号将退出系统
	{
		Account IV1;//账户中间变量1
		printf("\nSign in\n==========================================\n");
		printf("\n\n\t>>Please enter account number:\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3次输入错密码将退出系统
			{
				printf("\nSign in\n========================================\n\n\n\t>>>>Please enter password:\n");
				char storePassword[10] = { '\0' };    //存储用户输入的密码
				printf("\n\n\t\t\t______\b\b\b\b\b\b");
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");

				if (findPassword(IV1))
				{
					m = 3;
					n = 3;
					printf("\nMenu\n========================================\n");
					E_Main_Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\n\tThe account has been frozen, please contact the background to retrieve it.\n");
						CE_Initial_Password();
						break;
					}
					else
					{
						printf("\n\n\tThe password is wrong, the account will be frozen after %d chance\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\tThe user was not found! %d Please re-enter:\n", 3 - m);
			if (m == 3)
			{
				printf("\n\n\tError, logged out\n");
				CE_Save_User_Data();
				exit(0);
			}
		}
	}
}

//中文菜单页
void C_Main_Menu()//
{
	printf("\n【菜单】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t【1】存豆\n");
		printf("\n\n\t\t【2】取豆\n");
		printf("\n\n\t\t【3】转帐\n");
		printf("\n\n\t\t【4】查询\n");
		printf("\n\n\t\t【5】修改个人资料\n");
		printf("\n\n\t\t【6】注销账号\n");
		printf("\n\n\t\t【7】小游戏攒豆\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			break;
		case 2:
			system("cls");
			C_Withdraw_Money();
			break;
		case 3:
			system("cls");
			C_Transfer_Money();
			break;
		case 4:
			system("cls");
			C_Enquiry();
			break;
		case 5:
			system("cls");
			C_Change_Information();
			break;
		case 6:
			system("cls");
			CE_Close_Account();
			break;
		case 7:
			system("cls");
			CE_Game();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n【菜单】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t\t输入错误！\n");
			k1 = 1;
			break;
		}
	}
}

//中文菜单页，简洁
void C_Easy_Main_Menu()
{
	printf("\n【菜单】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	int index = 0;
	char ch;
	string select[] = { "【1】存豆","【2】取豆","【3】转帐","【4】退出系统","","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 7; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 3;
				else if (index > 3)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_DepositMoney();
					break;
				case 2:
					system("cls");
					C_Withdraw_Money();
					break;
				case 3:
					system("cls");
					C_Transfer_Money();
					break;
				case 4:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//英语菜单页
void E_Main_Menu()//
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t【1】Deposit money\n");
		printf("\n\n\t\t【2】Withdraw money\n");
		printf("\n\n\t\t【3】Transfer money\n");
		printf("\n\n\t\t【4】Inquire\n");
		printf("\n\n\t\t【5】Modify personal information\n");
		printf("\n\n\t\t【6】Logout\n");
		printf("\n\n\t\t【0】Exit system\n");
		printf("\n\n\t\t\tYour chioce：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_DepositMoney();
			break;
		case 2:
			system("cls");
			E_Withdraw_Money();
			break;
		case 3:
			system("cls");
			E_Transfer_Money();
			break;
		case 4:
			system("cls");
			E_Enquiry();
			break;
		case 5:
			system("cls");
			E_Change_Information();
			break;
		case 6:
			system("cls");
			CE_Close_Account();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\tIncorrect input!\n");
			k1 = 1;
			break;
		}
	}
}

//中文存豆业务
void C_DepositMoney()
{
	int a;
	printf("\n【存豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t【温馨提示】1.欢乐豆数量须为100的整数。\n\n\t\t     2.单笔存豆不得超过10000。");
	printf("\n\n\n\t>>请输入你要存入的欢乐豆：\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n【存豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("单笔存豆不得超过10000。\n\n");
			}
			else
				printf("欢乐豆数额须为100的整数。\n\n");
			C_DepositMoney1();//存豆失败选项
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t单笔存豆不得超过10000。\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\t欢乐豆数额须为100的整数。\n\n");
			C_Easy_DepositMoney1();
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		printf("\n【存豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		CE_Save_User_Data();
		CE_Deposit_Transaction();
		if (Sin == 1)
		{
			printf("\n\t您本次已成功存入%.2f欢乐豆!!!!\n", TA.Money);
			C_DepositMoney2();//存豆成功选项
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t您本次已成功存入%.2f欢乐豆!!!!\n", TA.Money);
			C_Easy_DepositMoney2();
		}
	}
}

//存豆失败选项
void C_DepositMoney1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t【1】重新输入欢乐豆数额\n");
		printf("\n\n\t\t【2】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//存豆成功选项
void C_DepositMoney2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t【1】再存一笔\n");
		printf("\n\n\t\t【2】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//存豆失败选项，简洁
void C_Easy_DepositMoney1()
{
	int index = 0;
	char ch;
	string select[] = { "【1】重新输入欢乐豆数额","【2】返回主页","【3】退出系统","","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_DepositMoney();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//存豆成功选项，简洁
void C_Easy_DepositMoney2()
{
	int index = 0;
	char ch;
	string select[] = { "【1】再存一笔","【2】返回主页","【3】退出系统" ,"","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_DepositMoney();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//英语存豆业务
void E_DepositMoney()
{
	int a;
	printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t[Reminder] 1. The number of happy beans must be an integer of 100.\n\n\t\t2. A single deposit of beans cannot exceed 10,000.");
	printf("\n\n\n\t>>Please enter the happy bean you want to deposit:\n");
	printf("\n\n\t\t\tYour chioce：___\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		int k = 0, b;
		system("cls");
		printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (a > 10000)
		{
			printf("Single deposit must not exceed 10000.\n\n");
		}
		else
			printf("The amount of happy beans must be an integer of 100.\n\n");
		while (k < 3)
		{
			printf("\n\n\t\t【1】Re-enter the amount of happy beans\n");
			printf("\n\n\t\t【2】Return to homepage\n");
			printf("\n\n\t\t【0】Exit the system\n");
			printf("\n\n\t\t\tYour chioce：___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_DepositMoney();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\nYou have successfully deposited %.2f Happy Beans!!!!\n", TA.Money);
		CE_Save_User_Data();
		CE_Deposit_Transaction();
		int k = 0, b;
		while (k < 3)
		{
			printf("\n\n\t\t【1】Save another one\n");
			printf("\n\n\t\t【2】Return to homepage\n");
			printf("\n\n\t\t【0】Exit the system\n");
			printf("\n\n\t\t\tYour chioce：___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_DepositMoney();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
}

//中文取豆业务
void C_Withdraw_Money()
{
	int a;
	printf("\n【取豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t\t【温馨提示】1.欢乐豆数量须为100的整数。");
	printf("\n\n\n\t\t\t     2.单笔取豆不得超过10000。");
	printf("\n\n\n\t\t>>请输入你要取出的欢乐豆：______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n【取豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("单笔取豆不得超过10000。\n\n");
			}
			else
				printf("欢乐豆数额须为100的整数。\n\n");
			C_Withdraw_Money1();//取豆失败选项
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t单笔取豆不得超过10000。\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\t欢乐豆数额须为100的整数。\n\n");
			C_Easy_Withdraw_Money1();//取豆失败选项，简洁
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n【取豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			if (Sin == 1)
			{
				printf("\n\t欢乐豆不足!!!!\n");
				C_Withdraw_Money1();//取豆失败选项
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t欢乐豆不足!!!!\n");
				C_Easy_Withdraw_Money1();//取豆失败选项，简洁
			}
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			printf("\n【取豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			if (Sin == 1)
			{
				printf("\n\t取豆成功!!!!\n");
				C_Withdraw_Money2();//取豆成功选项
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t取豆成功!!!!\n");
				C_Easy_Withdraw_Money2();//取豆成功选项，简洁
			}
		}
	}
}

//取豆失败选项
void C_Withdraw_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t【1】重新输入欢乐豆数额");
		printf("\n\n\n\t\t【2】返回主页");
		printf("\n\n\n\t\t【0】退出系统");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Withdraw_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//取豆成功选项
void C_Withdraw_Money2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t【1】再次取豆");
		printf("\n\n\n\t\t【2】返回主页");
		printf("\n\n\n\t\t【0】退出系统\n\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Withdraw_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//取豆失败选项，简洁
void C_Easy_Withdraw_Money1()
{
	int index = 0;
	char ch;
	string select[] = { "【1】重新输入欢乐豆数额","【2】返回主页","【3】退出系统" ,"","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_Withdraw_Money();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//取豆成功选项，简洁
void C_Easy_Withdraw_Money2()
{
	int index = 0;
	char ch;
	string select[] = { "【1】再取一笔","【2】返回主页","【3】退出系统","","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_Withdraw_Money();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//英语取豆业务
void E_Withdraw_Money()
{
	int a;
	printf("\n【Take Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t\t[Reminder] 1. The number of happy beans must be an integer of 100.");
	printf("\n\n\n\t\t\t2. A single fetch must not exceed 10000.");
	printf("\n\n\n\t\t>>Please enter the happy bean you want to take out:\n\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		int k = 0, b;
		system("cls");
		printf("\n【Take Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (a > 10000)
		{
			printf("Single deposit must not exceed 10000.\n\n");
		}
		else
			printf("The amount of happy beans must be an integer of 100.\n\n");
		while (k < 3)
		{
			printf("\n\n\n\t\t【1】 Re-enter the amount of happy beans");
			printf("\n\n\n\t\t【2】 Return to home page");
			printf("\n\n\n\t\t【0】 Exit the system");
			printf("\n\n\t\t\tYour chioce：___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_Withdraw_Money();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			int k = 0, b;
			system("cls");
			printf("\n【Take Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nNot enough happy beans!!!!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t【1】 Re-enter the amount of happy beans");
				printf("\n\n\n\t\t【2】 Return to home page");
				printf("\n\n\n\t\t【0】 Exit the system\n");
				printf("\n\n\t\t\tYour chioce：___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Withdraw_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			printf("\n【Take Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nGet the beans successfully!!!!\n");
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t【1】 Take beans again");
				printf("\n\n\n\t\t【2】 Return to home page");
				printf("\n\n\n\t\t【0】 Exit the system\n\n");
				printf("\n\n\t\t\tYour chioce：___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Withdraw_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
	}
}

//转豆业务
void C_Transfer_Money()
{
	int a = 100;
	printf("\n【转豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\t---------------------》转豆须知《----------------------\n");
	printf("\t1◆单笔转豆不得超过10000欢乐豆。\n\t\n");
	printf("\t2◆同行转豆将收取2%%的手续费。\n\t\n");
	printf("\t3◆异行转豆将收取5%%的手续费。\n\t\n");
	printf("\t2◆汇豆短信莫当真，陌生电话要谨慎。\n\t\n");
	printf("\t  遇到陷阱知深浅，正心律己要实诚。\n");
	printf("\t----------------------------------------------------\n");
	printf("\n\n\n\n\t\t>>请输入你要转出到的账户：__________\b\b\b\b\b\b\b\b\b\b");
	Account TT;//目标账户
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		ACCOUNT = atoi(curAccount->account_number);//当前账户转换为数值
		TACCOUNT = atoi(TT.account_number);        //当前对方账户转换为数值
		system("cls");
		printf("\n【转豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			printf("\t---------------------》转豆须知《----------------------\n");
			printf("\t1◆单笔转豆不得超过10000欢乐豆。\n\t\n");
			printf("\t2◆同行转豆将收取2%%的手续费。\n\t\n");
			printf("\t3◆异行转豆将收取5%%的手续费。\n\t\n");
			printf("\t2◆汇豆短信莫当真，陌生电话要谨慎。\n\t\n");
			printf("\t  遇到陷阱知深浅，正心律己要实诚。\n");
			printf("\t----------------------------------------------------\n");
			printf("\n\n\t\t>>请输入你要转出的欢乐豆数额：______\b\b\b\b\b\b");
		}
		else if (Sin == 3)
		{
			printf("\n\n\t\t>>请输入你要转出的欢乐豆数额：______\b\b\b\b\b\b");
		}
		scanf("%d", &a);
		if (a > 10000)
		{

			if (Sin == 1)
			{
				printf("\n\t单笔转豆不得超过10000。\n\n");
				C_Transfer_Money1();//取豆失败选项
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t单笔转豆不得超过10000。\n\n");
				C_Easy_Transfer_Money1();//取豆失败选项，简洁
			}
		}
		else
		{
			CE_SXF();
			CE_Time();
			TA.Money = a * -1.00;
			SXFmoey = SXF * 0.01 * a;
			if (curAccount->balance + TA.Money - SXFmoey < 0)
			{
				system("cls");
				printf("\n【转豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");

				if (Sin == 1)
				{
					printf("\n\t欢乐豆不足!!!!\n");
					C_Transfer_Money1();          //转豆失败选项
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\t欢乐豆不足!!!!\n");
					C_Easy_Transfer_Money1();      //转豆失败选项，简洁
				}
			}
			else
			{
				system("cls");
				printf("\n【转豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				curAccount->balance = curAccount->balance + TA.Money - SXFmoey;//当前账户减去转账金额和手续费
				curAccountO->balance = curAccountO->balance - TA.Money;      //对方账户加上转账金额
				CE_Transfer_Transaction();
				CE_SXF_Transaction();
				CE_Save_User_Data();
				if (Sin == 1)
				{
					printf("\n\t转豆成功!!!!\n");
					C_Transfer_Money2();           //转豆成功选项
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\t转豆成功!!!!\n");
					C_Easy_Transfer_Money2();      //转豆成功选项，简洁
				}
			}
		}
	}
	else
	{
		system("cls");
		printf("\n【转豆】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			printf("\n\t对方账户不存在！！！！");
			C_Transfer_Money1();             //取豆失败选项
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t对方账户不存在！！！！");
			C_Easy_Transfer_Money1();        //取豆失败选项，简洁
		}
	}
}

//转豆失败选项
void C_Transfer_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t【1】重新转账");
		printf("\n\n\n\t\t【2】返回主页");
		printf("\n\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Transfer_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//转豆成功选项
void C_Transfer_Money2()
{
	int k2 = 0, b;
	while (k2 < 3)
	{
		printf("\n\n\n\t\t【1】再次转豆");
		printf("\n\n\n\t\t【2】返回主页");
		printf("\n\n\n\t\t【0】退出系统\n\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Transfer_Money();
			k2 = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k2 = 3;
			break;
		case 0:
			k2 = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k2++;
			break;
		}
	}
}

//转豆失败选项，简洁
void C_Easy_Transfer_Money1()
{
	int index = 0;
	char ch;
	string select[] = { "【1】重新输入","【2】返回主页","【3】退出系统","","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 3; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_Transfer_Money();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//转豆成功选项，简洁
void C_Easy_Transfer_Money2()
{
	int index = 0;
	char ch;
	string select[] = { "【1】再取一笔","【2】返回主页","【3】退出系统","","","方向键 ↑ ↓ 选择功能，回车键确定" };
	string str = "▲ ";
	gotoxy(5, 1);
	//printf("方向键 ↑ ↓ 选择功能，回车键确定。\n");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, 3 + i);
		cout << select[i];
	}
	gotoxy(5, 3);
	cout << str + "     " + select[0];

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 72 || ch == 80)
			{
				if (ch == 27) //退出
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //上
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//下
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index++;
				}
				if (index < 0)
					index = 2;
				else if (index > 2)
					index = 0;
			}
			gotoxy(5, 3 + index);
			printf("   ");
			Sleep(50);
			cout << str + select[index];
			if (ch == '\r')
			{
				switch (index + 1)
				{
				case 1:
					system("cls");
					C_Transfer_Money();
					break;
				case 2:
					system("cls");
					C_Easy_Main_Menu();
					break;
				case 3:
					system("cls");
					CE_Save_User_Data();
					exit(0);
					break;
				}
			}
		}
	}
}

//转豆业务
void E_Transfer_Money()
{
	int a = 100;
	printf("\n【Send Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t【Reminder】1. No more than 10000 happy beans can be sent at a time.\n");
	printf("\n\n\t\t2.Beware of scams.");
	printf("\n\n\t\t>>Please enter the account you want to send to:\n\n");
	printf("\n\n\t\t\t___\b\b\b");
	Account TT;
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		system("cls");
		printf("\n【Send Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t【Reminder】1. No more than 10000 happy beans can be sent at a time.\n");
		printf("\n\n\t\t2.Beware of scams.");
		printf("\n\n\t\t>>Please enter the amount of Happy Beans you want to send:\n");
		scanf("%d", &a);
		if (a > 10000)
		{
			printf("\n\tSingle delivery of beans must not exceed 10000\n\t\t\n\n");
			E_Transfer_Money();
		}
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			int k = 0, b;
			system("cls");
			printf("\n【Send Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nNot enough happy beans!!!!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t【1】 Re-enter the amount of happy beans");
				printf("\n\n\n\t\t【2】 Return to home page");
				printf("\n\n\n\t\t【0】 Exit the system\n");
				printf("\n\n\t\t\tYour chioce：___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			system("cls");
			printf("\n【Send Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nSuccessful delivery of beans!!!!\n");
			curAccount->balance = curAccount->balance + TA.Money;//当前账户减去转账金额
			curAccountO->balance = curAccountO->balance - TA.Money;//对方账户加上转账金额
			CE_Transfer_Transaction();
			CE_Save_User_Data();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t[1] Transfer beans again");
				printf("\n\n\n\t\t[2] Return to the home page");
				printf("\n\n\n\t\t[0] Exit the system\n");
				printf("\n\n\t\t\tYour chioce：___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
	}
	else
	{
		int b, k = 0;
		system("cls");
		printf("\n【Send Beans】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\nThe account of the other party does not exist!!!!");
		while (k < 3)
		{
			printf("\n\n\n\t\t【1】 Re-enter the other party's account number");
			printf("\n\n\n\t\t【2】 Return to home page");
			printf("\n\n\n\t\t【0】 Exit the system\n\n");
			printf("\n\n\t\t\tYour chioce：___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_Transfer_Money();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
}

//查询业务页
void C_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n【查询】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t【1】账户余额查询\n");
		printf("\n\n\t\t【2】个人信息查询\n");
		printf("\n\n\t\t【3】交易记录查询\n");
		printf("\n\n\t\t【4】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry_balance();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Enquiry_Information();
			k = 3;
			break;
		case 3:
			system("cls");
			C_Enquiry_Record();
			k = 3;
			break;
		case 4:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//查询业务页
void E_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n【Inquire】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t【1】Account balance inquiry\n");
		printf("\n\n\t\t【2】Personal information query\n");
		printf("\n\n\t\t【3】Transaction record query\n");
		printf("\n\n\t\t【4】Return to homepage\n");
		printf("\n\n\t\t【0】Exit the system\n");
		printf("\n\n\t\t\tYour choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry_balance();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Enquiry_Information();
			k = 3;
			break;
		case 3:
			system("cls");
			E_Enquiry_Record();
			k = 3;
			break;
		case 4:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//账户余额查询
void C_Enquiry_balance()
{
	printf("\n【账户余豆查询】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Time();
	printf("\n\t您的欢乐豆余额为：\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t【1】返回上一页\n");
		printf("\n\n\t\t【2】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//账户余额查询
void E_Enquiry_balance()
{
	printf("\n【Account balance query】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Time();
	printf("\n\tYour Happy Beans also include:\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t【1】Return to the previous page\n");
		printf("\n\n\t\t【2】Return to homepage\n");
		printf("\n\n\t\t【0】Exit the system\n");
		printf("\n\n\t\t\tYour choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//个人信息查询
void C_Enquiry_Information()
{
	printf("\n【个人信息查询】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\t姓名：\n\t\t%s\n", curAccount->name);
	printf("\n\t账号：\n\t\t%s\n", curAccount->account_number);
	printf("\n\t预留手机号：\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t【1】返回上一页\n");
		printf("\n\n\t\t\t【2】返回主页\n");
		printf("\n\n\t\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//个人信息查询
void E_Enquiry_Information()
{
	printf("\n【Personal information inquiry】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\tName：\n\t\t%s\n", curAccount->name);
	printf("\n\tAccount number：\n\t\t%s\n", curAccount->account_number);
	printf("\n\tReserved phone number：\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t【1】Return to the previous page\n");
		printf("\n\n\t\t\t【2】Return to homepage\n");
		printf("\n\n\t\t\t【0】Exit the system\n");
		printf("\n\n\t\t\tYour chioce：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//交易记录查询
void C_Enquiry_Record()
{
	printf("\n【交易记录查询】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t【1】返回上一页\n");
		printf("\n\n\t\t【2】返回主页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//交易记录查询
void E_Enquiry_Record()
{
	printf("\n【Transaction record query】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t【1】Return to the previous page\n");
		printf("\n\n\t\t【2】Return to homepage\n");
		printf("\n\n\t\t【0】Exit the system\n");
		printf("\n\n\t\t\tYour choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//修改信息选项页
void C_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{
		printf("\n【修改个人资料】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t【1】修改用户名称\n");
		printf("\n\n\t\t【2】修改账户号码\n");
		printf("\n\n\t\t【3】修改联系电话\n");
		printf("\n\n\t\t【4】修改账户密码\n");
		printf("\n\n\t\t【9】返回上一页\n");
		printf("\n\n\t\t【0】退出系统\n");
		printf("\n\n\t\t\t你的选择：___\b\b\b");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			C_Change_User();
			k2 = 0;
			break;
		case 2:
			C_Change_AccountNum();
			k2 = 0;
			break;
		case 3:
			C_Change_phone();
			k2 = 0;
			break;
		case 4:
			C_Change_Password();
			k2 = 0;
			break;
		case 9:
			C_Main_Menu();
			k2 = 0;
			break;
		case 0:
			CE_Save_User_Data();
			exit(0);
		default:
			system("cls");
			printf("输入错误！\t请按照提示重新输入：\n");
			break;
		}
	}
}

//修改信息选项页
void E_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{

		printf("\n【Modify personal information】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t【1】Modify user name\n");
		printf("\n\n\t\t【2】Modify account number\n");
		printf("\n\n\t\t【3】Modify contact number\n");
		printf("\n\n\t\t【4】Change account password\n");
		printf("\n\n\t\t【9】Go back to the last page\n");
		printf("\n\n\t\t【0】Exit system\n");
		printf("\n\n\t\t\tYour chioce：___\b\b\b");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			E_Change_User();
			k2 = 0;
			break;
		case 2:
			E_Change_AccountNum();
			k2 = 0;
			break;
		case 3:
			E_Change_phone();
			k2 = 0;
			break;
		case 4:
			E_Change_Password();
			k2 = 0;
			break;
		case 9:
			E_Main_Menu();
			k2 = 0;
			break;
		case 0:
			CE_Save_User_Data();
			exit(0);
		default:
			system("cls");
			printf("input error! \tPlease re-enter as prompted:\n");
			break;
		}
	}
}

//修改用户
void C_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【修改用户名称】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>请输入密码：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【修改用户名称】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>请输入新用户名称:\n");
			printf("\n\n\t___\b\b\b\n");
			scanf("%s", curAccount->name);
			printf("\n【修改用户名称】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t用户名称修改成功！\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】返回上一页\n");
				printf("\n\n\t\t【2】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t您的选择：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//修改用户
void E_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【Modify user name】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【Modify user name】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new user name:\n");
			scanf("%s", curAccount->name);
			printf("\n【Modify user name】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\tUser name modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】Return to the previous page\n");
				printf("\n\n\t\t【2】Return to homepage\n");
				printf("\n\n\t\t【0】Exit the system\n");
				printf("\n\n\t\t\tYour chioce：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("Wrong password entered! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//修改账户
void C_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【修改账户号码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>请输入密码：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【修改账户号码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>请输入新账户号码:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n【修改账户号码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t账户号码修改成功！\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】返回上一页\n");
				printf("\n\n\t\t【2】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t您的选择：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//修改账户
void E_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【Modify account number】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【Modify account number】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter new account number:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n【Modify account number】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\tThe account number has been modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】Return to the previous page\n");
				printf("\n\n\t\t【2】Return to homepage\n");
				printf("\n\n\t\t【0】Exit the system\n");
				printf("\n\n\t\t\tYour choice：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("Wrong password entered! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//修改联系电话
void C_Change_phone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【修改联系电话】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>请输入密码：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【修改联系电话】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>请输入新联系电话号码:\n");
			scanf("%s", curAccount->phone_number);
			system("cls");
			printf("\n【修改联系电话】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t联系电话修改成功！\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】返回上一页\n");
				printf("\n\n\t\t【2】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t您的选择：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//修改联系电话
void E_Change_phone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>Please enter your password:\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new contact phone number:\n");
			scanf("%s", curAccount->phone_number);
			system("cls");
			printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\tContact phone number modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】Go back to the last page\n");
				printf("\n\n\t\t【2】Return to home page\n");
				printf("\n\n\t\t【0】Exit system\n");
				printf("\n\n\t\t\tYour choice：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("\n\n\tPassword entered incorrectly! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//修改密码
void C_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【修改账户密码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>请输入原始密码：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【修改账户密码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>请输入新密码:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n【修改账户密码】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】返回上一页\n");
				printf("\n\n\t\t【2】返回主页\n");
				printf("\n\n\t\t【0】退出系统\n");
				printf("\n\n\t\t\t您的选择：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("\n\n\t密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//修改密码
void E_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n【Change account password】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>Please enter your password:\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n【Change account password】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new password:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n【Change account password】\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t【1】Go back to the last page\n");
				printf("\n\n\t\t【2】Return to home page\n");
				printf("\n\n\t\t【0】Exit system\n");
				printf("\n\n\t\t\tYour choice：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("\n\n\t密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}

//开始界面
void start()
{
	printf("\n\t----------------------》欢迎使用自动存取豆机《---------------------\n");
	printf("\t     Welcome to the Automated Deposit/Withdrawal Beans Machine\n\n");
	printf("\t1◆本自动存取豆机支持两种语言模式，中文，英语。\n\t\n");
	printf("\t   This machine supports two language modes, Chinese, English.\n\t\n");
	printf("\t2◆选项页面需要键入对应选项数字，按回车键确认选项（简洁模式除外）。\n\t\n");
	printf("\t   Enter the option number and press Enter to confirm the option.\n\t\n");
	printf("\t-------------------------------------------------------------------");
	int k = 1;
	while (k)
	{
		printf("\n\n\t\t※请选择语言：\t");
		printf("※Please choose language：\n");
		printf("\n\n\t\t\t【1】中文\n");
		printf("\n\n\t\t\t【2】English\n");
		printf("\n\n\t\t\t【0】退出 Exit\n\n\n\t\t\t");
		printf("\n\n\t\t\t▲您的选择/Your choice：___\b\b\b");
		scanf("%d", &Language);
		switch (Language)
		{
		case 1:
			system("cls");
			printf("\n\t----------------------》用户须知《------------------------------\n");
			printf("\t1◆用户登录时请正确输入帐户号码，输入错误三次后将自动退出系统。\n\t\n");
			printf("\t2◆登录密码输入错误三次后帐户将锁定并退出系统，仅管理员可解封。\n\t\n");
			printf("\t3◆用户注册时请按提示输入相关信息，输入有误三次将自动退出系统。\n\t\n");
			printf("\t4◆用户注册时有三个银行可供选择，注意：不同银行手续费可能不同。\n\t\n");
			printf("\t----------------------------------------------------------------\n");
			printf("\n\n\t\t\t【1】用户登录\n");
			printf("\n\n\t\t\t【2】用户注册\n");
			printf("\n\n\t\t\t【3】中文登录简洁版\n");
			printf("\n\n\t\t\t【其它】返回上一页\n");
			printf("\n\n\t\t\t|您的选择：___\b\b\b");
			break;
		case 2:
			system("cls");
			printf("\n\n\t\t\t【1】Sign in\n");
			printf("\n\n\t\t\t【2】Sign up\n");
			printf("\n\n\t\t\t【Others】Back to previous page\n");
			printf("\n\n\t\t\tYour choice：___\b\b\b");
			break;
		case 0:
			exit(0);
		default:
			k = 1;
			system("cls");
			printf("\n\n\t\t输入有误，请按照提示再次输入!\t\t");
			printf("Error,please follow the prompts to enter again!\n\n");
			break;
		}
		printf("___\b\b\b");
		scanf("%d", &Sin);
		k = 0;
		if (Sin == 1)
		{
			C_Sign_In();//中文注册函数
		}
		else if (Sin == 2)
		{
			Sin = 1;
			C_Sign_Up();
		}
		else if (Sin == 3)
		{
			printf("\t----------------------》进入中文简洁模式须知《-----------------------\n");
			printf("\t1◆中文简洁模式下只支持存豆，取豆，转豆业务，其他业务请到中文模式。\n\t\n");
			printf("\t2◆用方向键↑↓选择对应选项，回车键确认选项。\n\t\n");
			printf("\t3◆祝你使用愉快！\n\t\n");
			printf("\t|-----------------------------------------------------------------\n");
			C_Sign_In();
		}
		else
			k = 1;
	}
}


int main()
{
	CE_Time();
	CE_Initialize_User_Data();
	CE_Initialize_Transaction_Data();
	start();
	CE_Save_User_Data();
	CE_Save_Transaction_Data();
	return 0;
}

