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



//��궨λ
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

void start();

//����
void C_Sign_Up();                      //����ע��
void C_Sign_In();                      //���ĵ�¼ 
void C_Main_Menu();                    //�������˵�ҳ
void C_DepositMoney();                 //���Ĵ涹ҵ��
void C_DepositMoney1();                //���Ĵ涹ʧ��ѡ��
void C_DepositMoney2();                //���Ĵ涹�ɹ�ѡ��
void C_Withdraw_Money();               //����ȡ��ҵ��
void C_Withdraw_Money1();              //����ȡ��ʧ��ѡ��
void C_Withdraw_Money2();              //����ȡ���ɹ�ѡ��
void C_Transfer_Money();               //����ת��ҵ��
void C_Transfer_Money1();              //����ת��ʧ��ѡ��
void C_Transfer_Money2();              //����ת��ʧ��ѡ��
void C_Enquiry();                      //���Ĳ�ѯҵ��
void C_Enquiry_balance();              //���Ĳ�ѯ�ඹ
void C_Enquiry_Information();          //���Ĳ�ѯ������Ϣ
void C_Enquiry_Record();               //���Ĳ�ѯ��ˮ��¼
void C_Change_Information();           //�����޸���Ϣѡ��ҳ
void C_Change_User();                  //�����޸��û�����
void C_Change_AccountNum();            //�����޸��˻�
void C_Change_phone();                 //�����޸���ϵ�绰
void C_Change_Password();              //�����޸�����

//English
void E_Sign_Up();                      //Ӣ��ע��
void E_Sign_In();                      //Ӣ�ĵ�¼ 
void E_Main_Menu();                    //Ӣ�Ĳ˵�ҳ
void E_DepositMoney();                 //Ӣ�Ĵ涹ҵ��
void E_Withdraw_Money();               //Ӣ��ȡ��ҵ��
void E_Transfer_Money();               //Ӣ��ת��ҵ��
void E_Enquiry();                      //Ӣ�Ĳ�ѯҵ��
void E_Enquiry_balance();              //Ӣ�Ĳ�ѯ�ඹ
void E_Enquiry_Information();          //Ӣ�Ĳ�ѯ������Ϣ
void E_Enquiry_Record();               //Ӣ�Ĳ�ѯ��ˮ��¼
void E_Change_Information();           //Ӣ���޸���Ϣѡ��ҳ
void E_Change_User();                  //Ӣ���޸��û�����
void E_Change_AccountNum();            //Ӣ���޸��˻�
void E_Change_phone();                 //Ӣ���޸���ϵ�绰
void E_Change_Password();              //Ӣ���޸�����

//���ļ��
void C_Easy_Main_Menu();               //���ļ�����˵�ҳ
void C_Easy_DepositMoney1();           //���ļ��涹�ɹ�ѡ��
void C_Easy_DepositMoney2();           //���ļ��涹ʧ��ѡ��
void C_Easy_Withdraw_Money1();         //���ļ��ȡ���ɹ�ѡ��
void C_Easy_Withdraw_Money2();         //���ļ��ȡ��ʧ��ѡ��
void C_Easy_Transfer_Money1();         //���ļ��ת���ɹ�ѡ��
void C_Easy_Transfer_Money2();         //���ļ��ת��ʧ��ѡ��

//CE
void gotoxy();
void getPassword();
void CE_Time();                       //ϵͳʱ��
void CE_Close_Account();              //ע���˻�ѡ��ҳ
void CE_Close_Account1();             //ע���˻�
void CE_Save_User_Data();             //�����û�����
void CE_Save_Transaction_Data();      //���潻������
void CE_Initial_Password();           //��ʼ�����뺯��
void CE_Initialize_User_Data();       //��ʼ���û�����
void CE_Initialize_Transaction_Data();//��ʼ����������
void CE_Set_Name();                   //��Ӣ����������
void CE_Set_Password();               //��Ӣ����������
void CE_Set_PhoneNumber();            //��Ӣ�����õ绰����
void CE_Add_Account_Number();         //��Ӣ�������˻����뺯��
void CE_Game_Transaction();           //��Ϸ���뽻��
void CE_GameOut_Transaction();        //��Ϸ֧������
void CE_Deposit_Transaction();        //�涹����
void CE_Withdraw_Transaction();       //ȡ������
void CE_Transfer_Transaction();       //ת������
void CE_SXF();                        //������
void CE_SXF_Transaction();            //�����ѽ���
void CE_Print_Transaction();          //��ӡ���׼�¼
void CE_Game();
void CE_Game_KK();
void TCS();                           //̰������Ϸ
void hide();
void print_wall();
void print_snake();
bool is_correct();
bool print_food();
bool go_ahead();
void locate();
void STJDB();                         //��ȭ��Ϸ
void DZ();                            //������Ϸ

int Language, Sin, Bank;
int Random_Number;           //�����
int ACCOUNT;                 //��ǰ�˺���ֵ
int TACCOUNT;                //��ǰ�Է��˺���ֵ
int SXF;                     //������
float SXFmoey;               //�����ѽ��
int AccountNum1 = 1231231000;//һ�ź���
int AccountNum2 = 1231232000;//���ź���
int AccountNum3 = 1231233000;//���ź���
int TCSm, TCSn;
char str[50];

//̰���߽ṹ��
struct TCSnode
{
	int x, y;
}snake[1000];
int snake_length, dir;
TCSnode food;
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

//�û���Ϣ����
struct Account
{
	//char bank[100];//����
	char name[100];//�û�����
	char account_number[50];//�˻��˺�
	char phone_number[12];//�绰����
	char password[10];//����
	float balance;//�ඹ

	struct Account* next;
};

//������Ϣ����
struct Trade
{
	char Taccount_number[50];//�˻��˺�
	char Time[100];//ʱ��
	char Operation[100];//��������
	char TarUse[50];//Ŀ���˻��˺�
	float Money;//��������

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;

//�û���Ϣ
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account IV;

//������Ϣ
Trade* Thead = NULL;
Trade* Ttail = NULL;
Trade* TcurAccount;
Trade TA;
char tmp1[100];

//ѡ����
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
using namespace std;


//��Ϸ����
void CE_Game()
{
	int a, a1, k = 0;
	while (k < 3)
	{
		printf("\n��С��Ϸ�ܶ���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t��1��̰����\n");
		printf("\n\n\t\t��2����ȭ��Ϸ\n");
		printf("\n\n\t\t��3��������Ϸ\n");
		printf("\n\n\t\t��4��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			k = 0;
			while (k < 3)
			{
				printf("\n��̰���ߡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|----------------------̰����-----------------------\n");
				printf("\t|��1����ע�ⴰ�ڴ�С,���ⷢ����λ.���齫���ڵ�Ϊ���\n\t|\n");
				printf("\t|��2����ѡ���Ѷ�.����1-10������1����,1���,10�����ѡ�\n\t|\n");
				printf("\t|��3����Ϸ������,�ɻ�ó���X100���Ľ����������ܶ��ɡ�\n\t|\n");
				printf("\t|��4��������Ϸ���Զ���ȡ���Ļ��ֶ�����֪�󣬲����˻���\n\t|\n");
				printf("\t|��5��������Ϸ�����,��*�����*���Ʒ���.ף����Ϸ���!\n");
				printf("\t|---------------------------------------------------\n");
				printf("\n\n\t\t���۸񣤡�1000��/��\n");
				printf("\n\n\t\t��1������������Ϸ\n");
				printf("\n\n\t\t��2��������һҳ\n");
				printf("\n\n\t\t��3��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
				printf("\n����ȭ��Ϸ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|----------------------��ȭ��Ϸ-----------------------\n");
				printf("\t|��1������һ����ȭ��С��Ϸ�����������뷨��ȭ��ܵ��ԡ�\n\t|\n");
				printf("\t|��2������Ϊ�����ȭ��ÿ����Ϸ����������ȷ������ȶ�Ļ��ֶ���\n\t|\n");
				printf("\t|��3��������Ϊ100������������Ѻע���ó���10000��������Ч��\n\t|\n");
				printf("\t|��4�����͵��Դ��ƽ�֣�ϵͳ������������100���ֶ���ʾ������\n\t|\n");
				printf("\t|��5��ÿ��ܵ��ԣ��㽫�������������Ļ��ֶ���ף����Ϸ���!\n");
				printf("\t|-----------------------------------------------------\n");
				printf("\n\n\t\t��1����ʼ��Ϸ\n");
				printf("\n\n\t\t��2��������һҳ\n");
				printf("\n\n\t\t��3��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
				printf("\n��������Ϸ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\t|------------------------������Ϸ-------------------------\n\t|\n");
				printf("\t|��1�������������ʼ��������Ļ��ʾ�����ַ���������ȷ��*����ʾ��\n\t|\n");
				printf("\t|��2����Ϸ�����пɰ� ESC ��ͣ�������Ϸ���������Ϸ��������\n\t|\n");
				printf("\t|��3������Ϸ����100��/�֣���������ҵķ�Ӧ���� �����ٶ� ������\n\t|\n");
				printf("\t|��4��10�������޽���10���� ÿ��ȷ10���ɻ��100���ֶ��Ľ�����\n\t|\n");
				printf("\t|��5����֪�ۿ���޷�׷���˿���.ף����Ϸ���!\n");
				printf("\t|-------------------------------------------------------\n");
				printf("\n\n\t\t��1����ʼ��Ϸ\n");
				printf("\n\n\t\t��2��������һҳ\n");
				printf("\n\n\t\t��3��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t���ѡ��___\b\b\b");
				float z;
				scanf("%d", &a1);
				switch (a1)
				{
				case 1:
					system("cls");
					TA.Money = -100.00;
					z = -TA.Money;
					printf("\n\t\t\t�Ѿ���ȡ����%0.2f���ֶ����Ѹ�֪��\n", z);
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
//���
void locate(int x, int y)
{
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};
//���ع��
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cursor_info);
}
//���������
double random(double start, double end)
{
	return start + (end - start) * rand() / (RAND_MAX + 1.0);
}
//̰�������ǽ
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
//̰�������ǽ
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
//�ж��Ƿ�ײǽ������ײ
bool is_correct()
{
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == TCSm + 1 || snake[0].y == TCSn + 1) return false;
	for (int i = 1; i <= snake_length - 1; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) return false;
	}
	return true;
}
//������ɲ����ʳ��λ��
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
//�ߵ�ǰ��
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
	/*** �Ե���ʳ�� ***/
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		snake_length++;
		e = true;
		snake[snake_length - 1] = temp;
	}
	/*** �����ʱ��״̬ ***/
	if (!e)
	{
		locate(temp.x, temp.y);
		printf(" ");
	}
	else
		print_food();
	locate(snake[0].x, snake[0].y);
	printf("O");
	/*** �����ײ ***/
	if (!is_correct())
	{
		system("cls");
		TA.Money = snake_length * 100.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t�����ˣ�\n");
		printf("\n\t\t\t��ĳɼ�Ϊ��%d\n", snake_length);
		printf("\n\t\t\t���õĽ���Ϊ��%0.2f���ֶ�������գ�\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t��1�����¿�ʼ��Ϸ\n");
			printf("\n\n\t\t��2���˳���Ϸ\n");
			printf("\n\n\t\t��3��������ҳ\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
//̰������Ϸ
void TCS()
{
	TA.Money = -1000.00;
	float z = -TA.Money;
	CE_Game_KK();
	printf("\n\t\t\t�Ѿ���ȡ����%0.2f���ֶ����Ѹ�֪��\n", z);
	TCSm = 25;
	TCSn = 40;
	if (TCSm < 10 || TCSn < 10 || TCSm>25 || TCSn>40)
	{
		printf("\n\t\t\tERROR\n");
		system("pause");
		exit(0);
	}
	int hard;
	printf("\n\n\n\n\t\t\t\tѡ���Ѷ�Ϊ��__\b\b");
	scanf("%d", &hard);
	if (hard <= 0 || hard > 100)
	{
		printf("\n\t\t\tERROR\n");
		system("pause");
		exit(0);
	}
	/*** ����ȫ����ʼ���������߳���λ�ã����� ***/
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
	/*** �����ʼ��ͼ������ʳ�� ***/
	system("cls");
	hide();
	print_wall();
	print_food();
	print_snake();
	locate(TCSm + 2, 0);
	printf("���ڵĳ���:");
	/*** ��ʼ��Ϸ ***/
	while (1)
	{
		/*** �Ѷ��泤�����Ӷ���� ***/
		hard_len = (double)snake_length / (double)(TCSm * TCSn);
		/*** ����ʱ�䣬��λ��ms ***/
		a = clock();
		while (1)
		{
			b = clock();
			if (b - a >= (int)(400 - 30 * hard) * (1 - sqrt(hard_len))) break;
		}
		/*** ���ܼ���������������ң����Դ˸ı䷽�� ***/
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
		/*** ǰ�� ***/
		if (!go_ahead()) break;
		/*** ����������ʱ���� ***/
		locate(TCSm + 2, 12);
		printf("%d", snake_length);
	}
	system("pause");
	exit(0);
}

//��ȭ��Ϸ
void STJDB()
{
	int gamer;   // ��ҳ�ȭ
	int CM;      //����
	int computer;// ���Գ�ȭ
	srand((unsigned)time(NULL));  // ���������
	computer = (rand() % 3) + 1;        // �����������ȡ�࣬�õ����Գ�ȭ
	printf("\n\n\t\t\t��������ĳ��룺_____\b\b\b\b\b");
	scanf("%d", &CM);
	TA.Money = CM * -1.00;
	float z = -TA.Money;
	CE_Game_KK();
	int k11 = 0;
	while (k11 < 3)
	{
		system("cls");
		printf("\n\t\t\t�Ѿ���ȡ����%0.2f���ֶ����Ѹ�֪��\n", z);
		printf("\n\n\t\t\t��������Ҫ����ȭͷ��___\b\b\b\n");
		printf("\n\n\t1:����\n\n\n\t2:ʯͷ\n\n\n\t3:��\n\n\n\t0:������\n");
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
			printf("���ѡ��Ϊ %d ѡ�����\n", gamer);
			k11++;
			break;
		}
	}
	printf("���Գ��ˡ�");
	switch (computer)
	{
	case 1:
		printf("��������");
		break;
	case 2:
		printf("��ʯͷ��");
		break;
	case 3:
		printf("������");
		break;
	}
	printf("����ˡ�");
	switch (gamer)
	{
	case 1:
		printf("��������\n");
		break;
	case 2:
		printf("��ʯͷ��\n");
		break;
	case 3:
		printf("������\n");
		break;
	}
	if ((computer == 1 && gamer == 2) || (computer == 2 && gamer == 3) || (computer == 3 && gamer == 1))
	{
		printf("\t\t\t\t\t\t������Ӯ��!����\n\n");
		TA.Money = CM * 2.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t���õĽ���%0.2f���ֶ�������գ�\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t��1������һ��\n");
			printf("\n\n\t\t��2���˳���Ϸ\n");
			printf("\n\n\t\t��3��������ҳ\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
		printf("\t\t\t\t\t\t����ƽ�֡���\n\n");
		TA.Money = CM * 1.00 + 100.00;
		float z = TA.Money;
		curAccount->balance = curAccount->balance + TA.Money;
		printf("\n\t\t\t���õĽ��������˻س��빲%0.2f���ֶ�������գ�\n", z);
		CE_Game_Transaction();
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t��1������һ��\n");
			printf("\n\n\t\t��2���˳���Ϸ\n");
			printf("\n\n\t\t��3��������ҳ\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
		printf("\t\t\t\t\t\t����������ˡ���\n\n");
		int a, k = 0;
		while (k < 3)
		{
			printf("\n\n\t\t��1������һ��\n");
			printf("\n\n\t\t��2���˳���Ϸ\n");
			printf("\n\n\t\t��3��������ҳ\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//������Ϸ
void DZ() {
	const int ESCKEY = 27; //�������ͳ���ESCKEY����ֵΪESC����ASCII����
	int pos, posmax = 72;  //��ǰλ�ã��ұ߽����λ��
	int win = 0, loss = 0; //��Ӯ�������������
	getchar();
	int ch = 0, key = 0; //����ַ�����Ҽ����ַ�
	srand(time(0)); //�������������
	while (key != ESCKEY)//��ѭ����key ���� ESC��ʱ����Ϸ
	{
		ch = rand() % ('z' + 1 - 'a') + 'a'; //��������ַ�
		for (pos = 0; pos < posmax && key != 27; pos++)
		{
			printf("\b--%c", (char)ch);
			pos++;
			Sleep(150);
			if (kbhit() && (key = getch()) == ch)
			{
				win++;
				printf("*\a");//��� * ������
				break;
			}
		}
		if (key == ESCKEY) //�û�����ESC������Ҫȷ��
		{
			printf("\n������Ϸ��\n");
			printf("\n\n\t\t��1����\n");
			printf("\n\n\t\t��2����");
			printf("\n\n\t\t__\b\b");
			while ((key = tolower(getchar())) != '1' && ch != '2')
				;    //��ѭ����
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
	printf("�ַ���ϰ������%d\n", win + loss);
	printf("��ȷ���������%d\n", win);
	printf("\n\t\t\t���õĽ���Ϊ��%0.2f���ֶ�������գ�\n", z);
	CE_Game_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1�����¿�ʼ��Ϸ\n");
		printf("\n\n\t\t��2���˳���Ϸ\n");
		printf("\n\n\t\t��3��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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



	printf("��Ϸ������ллʹ��\n");
}

//��Ϸ�ۿ�
void CE_Game_KK()
{
	CE_Time();
	if (curAccount->balance + TA.Money < 0)
	{
		int k = 0, b;
		system("cls");
		printf("\n\n\n���ֶ�����!!!!\n");
		while (k < 3)
		{
			printf("\n\n\n\t\t��1��ȥ�涹");
			printf("\n\n\n\t\t��2��������һҳ");
			printf("\n\n\n\t\t��3��������ҳ");
			printf("\n\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//��Ӣ����Ϸ֧����ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "GB");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "������Ϸ");
		CE_Save_Transaction_Data();
	}
}

//��Ӣ����Ϸ������ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "GA");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "��Ϸ����");
		CE_Save_Transaction_Data();
	}
}

//�Ǻ�����
void getPassword(char* storePw, int maxPwLen)
{
	char c = '\0';          //����û������ÿ���ַ�
	char* pc = storePw;    //Ϊ����ָ�������ַ�����ÿ���ַ�
	int pwlen = 0;          //��ǰpassword�ĳ���

	while (1)
	{
		c = getch();

		//����û����»س�����ֹͣѭ��
		if (c == '\r')
			break;

		//���û��������Ч�ַ��������봮�������ǿ��ַ�'\0'
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

//���ҵ�ǰ�˻�
int findAccount(Account IV1)//��¼ʱ���ҵ�ǰ�˻�
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

//��֤��ǰ�˻�����
int findPassword(Account IV1)//��¼ʱ���ҵ�ǰ�˻�����
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

//�����Ƿ������˻�
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

//����ת�˶���
int findAccount3(Account TT)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->account_number, TT.account_number) == 0)
		{
			int b, k = 0;
			if (Language == 1)
				printf("\n���ܸ��Լ�ת�ˣ�����\n");
			else
				printf("\nYou can't transfer money to yourself! ! !\n");
			while (k < 3)
			{
				if (Language == 1)
				{
					printf("\n\n\n\t\t��1����������Է��˻�����");
					printf("\n\n\n\t\t��2��������ҳ");
					printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
				}
				else
				{
					printf("\n\n\n\t\t��1��Re-enter the account number of the other party");
					printf("\n\n\n\t\t��2��Return to the homepage");
					printf("\n\n\n\t\t��0��Exit the system\n\n");
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
			curAccountO = curP;//��ǰת�˶����˻�
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//ʱ��
void CE_Time()
{
	time_t t = time(0);
	Random_Number = time(0) % 4 + 1;
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strftime(tmp1, sizeof(tmp), "%Y-%m-%d", localtime(&t));
	strcpy(TA.Time, tmp);
}

//ע��
void CE_Close_Account()
{
	printf("\n\n\t�˽���Ϊע���˻����棬�Ƿ����ע�����˻���\n\n\t����ܰ��ʾ��1.ע��ǰ��ȷ������Ƿ���0������˻����δ��0���˺Ž��޷�ע���ɹ���\n\n\t\t2.�������ע���˺Ž��ᱻ���գ���ʱ�����޷��ٴε�¼���˺š�");
	int aaa, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1������ע��\n");
		printf("\n\n\t\t��2�����ˣ�������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
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
			printf("\n\n\t\t�������\n");
			k1 = 1;
			break;
		}
	}
}

//ע��
void CE_Close_Account1()
{
	if (curAccount->balance != 0)
	{
		printf("\n\n\t\tע��ʧ�ܣ����ֶ�δ���㡣\n");
		printf("\n\n\t\t���ֶ���%d\n", curAccount->balance);
		int a, k1 = 1;
		while (k1)
		{
			k1 = 0;
			printf("\n\n\t\t��1��ȥת��\n");
			printf("\n\n\t\t��2��������ҳ\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
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
				printf("\n\n\t\t�������\n");
				k1 = 1;
				break;
			}
		}
	}
	else
	{
		printf("\n\n\t\tע���ɹ�����ӭ���´ι��١�\n");
		strcpy(curAccount->name, "XXXX");
		strcpy(curAccount->account_number, "XXXX");
		strcpy(curAccount->phone_number, "XXXX");
		strcpy(curAccount->password, "XXXX");
		CE_Save_User_Data();
		exit(0);
	}

}

//�����û�����
void CE_Save_User_Data()
{
	FILE* fp = fopen("D:/atm.txt", "w");//�����û�����
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

//���潻������
void CE_Save_Transaction_Data()
{
	FILE* Tfp = fopen("D:/atmtrade.txt", "at+");//���潻������
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

//��ʼ���û���Ϣ
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

//��ʼ��������Ϣ
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

//��ʼ������
void CE_Initial_Password()
{
	strcpy(curAccount->password, "XXXXXX");
}

//��Ӣ����������
void CE_Set_Name()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>���������������\n");
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
				printf("\n\t\t����������ù�����\n\n\t���������ã�\n");
			}
			else
				printf("\n\t\tYour name is set too long.\n\n\tPlease reset it:\n");
		}
	}
}

//��Ӣ����������
void CE_Set_Password()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>����������˻����롾6λ����\n");
		}
		else
			printf("\n\t>>Please set your account password [6 digits]��\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
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
				printf("\n\t\t����Ϊ��λ�����������������\n\n\t���������ã�\n");
			}
			else
				printf("\n\t\tThe password is six digits, your password is set incorrectly��\n\n\tPlease reset it:\n");

		}
	}
}

//��Ӣ�����õ绰��
void CE_Set_PhoneNumber()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>��������ĵ绰���롾11λ����\n");
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
				printf("\n\t\tԤ������ӦΪʮһλ�������Ԥ��������������\n\n\t���������룺\n");
			}
			else
				printf("\n\t\tThe reserved number should be eleven digits, your reserved number is set incorrectly!\n\n\tPlease reset it:\n");
		}
	}
}

//��Ӣ�������˻��˺�
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

//��Ӣ�Ĵ涹��ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "AA");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "�ɱ��˻��涹");
		CE_Save_Transaction_Data();
	}
}

//��Ӣ��ȡ����ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BB");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "�ɱ��˻�ȡ��");
		CE_Save_Transaction_Data();
	}
}

//��Ӣ��ת��ת����ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BA");
		strcpy(TP->TarUse, curAccountO->account_number);
		TP->Money = TA.Money;
		CE_Save_Transaction_Data();
	}


	//ת��ת����ˮ��¼

	Trade* TPi = (Trade*)malloc(sizeof(Trade));//���彻�׽ṹ�� ���� ת��TPi
	TPi->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TPi;
		Ttail = TPi;
	}
	else
	{
		Ttail->Tnext = TPi;
		Ttail = TPi;//�ҵ�����
		strcpy(TPi->Taccount_number, curAccountO->account_number);//��ǰת���˺Ÿ�ֵ��TPi
		strcpy(TPi->Time, TA.Time);//��ǰʱ�丳ֵ��TPi
		strcpy(TPi->Operation, "AB");//��ǰ�������͸�ֵ��TPi
		strcpy(TPi->TarUse, curAccount->account_number);
		TPi->Money = -TA.Money;//��ǰ���׽�ֵ��TPi
		CE_Save_Transaction_Data();
	}
}

//��Ӣ�������ѱ���
void CE_SXF()
{
	int HX;
	if (TACCOUNT >= AccountNum1 && TACCOUNT < AccountNum2)      //�Է��˻�Ϊһ�ź���
	{
		HX = 1;
	}
	else if (TACCOUNT >= AccountNum2 && TACCOUNT < AccountNum3) //�Է��˻�Ϊ���ź���
	{
		HX = 2;
	}
	else if (TACCOUNT >= AccountNum3 && TACCOUNT < 1231234000)  //�Է��˻�Ϊ���ź���
	{
		HX = 3;
	}
	if (ACCOUNT >= AccountNum1 && ACCOUNT < AccountNum2)        //��ǰ�˻�Ϊһ�ź���
	{
		if (HX == 1)             //ͬ��
			SXF = 2;
		else                     //����
			SXF = 5;
	}
	else if (ACCOUNT >= AccountNum2 && ACCOUNT < AccountNum3)   //��ǰ�˻�Ϊ���ź���
	{
		if (HX == 2)
			SXF = 2;
		else
			SXF = 5;
	}
	else if (ACCOUNT >= AccountNum3 && ACCOUNT < 1231234000)   //��ǰ�˻�Ϊ���ź���
	{
		if (HX == 3)
			SXF = 2;
		else
			SXF = 5;
	}
}

//��Ӣ����������ˮ��¼
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
		Ttail = TP;//�ҵ�����
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "CC");
		strcpy(TP->TarUse, "���˻�ת��");
		TP->Money = -SXFmoey;
		CE_Save_Transaction_Data();
	}
}


//AA���
//BBȡ�� 
//ABת��
//CC������ 
//GAB��Ϸ

//��Ӣ�Ĵ�ӡ��ˮ
void CE_Print_Transaction()
{
	int k = 0, w = 0;
	Trade* TcurP = Thead;
	if (Language == 1)
		printf("\n���\tʱ�䣺\t\t\t\t�������ͣ�\t\t���׻��ֶ�������\t���ױ�ע��\n\n");
	else
		printf("\nNum:\tTime:\t\t\t\tTrading Type:\t\tTrading Bean quantity:\tRemark:\n\n");
	while (TcurP != NULL)//���׼�¼
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
						printf("\n<%d>\t%s\t\t�涹/����\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t�涹/����\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tȡ��/֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tȡ��/֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tת��/֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tת��/֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "AB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tת��/����\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tת��/����\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "CC") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t������/֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t������/֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "GB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t��Ϸ/֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t��Ϸ/֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "GA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t��Ϸ/����\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t��Ϸ/����\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
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
			printf("\n\t��=��=��=��=��=¼\n\t\t\n\n");
		else
			printf("\n\tNo transaction record now.\n\t\t\n\n");
	}
}

//ѡ�����
void CE_ChooseBank()
{
	int a, k = 1;
	while (k)
	{
		k = 0;
		if (Language == 1)
		{
			printf("\n��ѡ����Ҫע���˺ŵ��������У�\n\n");
			printf("\n\n\t\t��1��һ�ź���\n");
			printf("\n\n\t\t��2�����ź���\n");
			printf("\n\n\t\t��3�����ź���\n");
			printf("\n\n\t\t��4�������˲�����ѡ���������һ��\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
		}
		else
		{
			printf("\nPlease ѡ����Ҫע���˺ŵ��������У�\n\n");
			printf("\n\n\t\t��1��One Bean Bank\n");
			printf("\n\n\t\t��2��Two Bean Bank\n");
			printf("\n\n\t\t��3��Three Bean Bank\n");
			printf("\n\n\t\t��4��Any Bank\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour choice��___\b\b\b");
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
			printf("\n\n\t\tEnter eroor��\n");
			k = 1;
			break;
		}
	}
}

//����ע��
void C_Sign_Up()//����ע�ắ��
{
	int a, k = 0;
	system("cls");
	printf("\n��ע�᡿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_ChooseBank();
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//�Ѷ���
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
		tail->next = Pset; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
	CE_Set_Name();//��ת����������������
	CE_Add_Account_Number();//��ת�����������˻����뺯��
	strcpy(Pset->account_number, IV.account_number);
	CE_Set_PhoneNumber();//��ת����������Ԥ���绰����
	CE_Set_Password();//��ת�������������뺯��
	Pset->balance = 0;
	CE_Save_User_Data();
	while (k < 3)
	{
		system("cls");
		printf("\n\t\tע=��=��=��\n");
		printf("\n\t>>����˻�����Ϊ %s\n", Pset->account_number);
		printf("\n\n\t\t��1�����ص�¼\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
			printf("\n�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//Ӣ��ע��
void E_Sign_Up()//Ӣ��ע�ắ��
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
			printf("\n\n\t\t��1�� Return to login\n");
			printf("\n\n\t\t��0�� Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//���ĵ�¼
void C_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account IV1;//�˻��м����1
		printf("\n����¼��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>�������˺ţ�\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ
			{
				printf("\n����¼��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				printf("\n\n\n\t>>���������룺\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
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
						printf("\n\n\t���˺��Ѿ������ᣬ����ϵ��̨�һء�\n");
						CE_Initial_Password();
						break;
					}
					else
					{
						printf("\n\n\t�������  %d�λ�����˺Ž��ᱻ����\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\tû�в��ҵ����û�!  %d  ���������룺\n", 3 - m);
			if (m == 3)
			{
				printf("\n\n\t�������˳�ϵͳ\n");
				CE_Save_User_Data();
				exit(0);
			}
		}
	}
}

//Ӣ���¼
void E_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account IV1;//�˻��м����1
		printf("\nSign in\n==========================================\n");
		printf("\n\n\t>>Please enter account number:\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ
			{
				printf("\nSign in\n========================================\n\n\n\t>>>>Please enter password:\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
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

//���Ĳ˵�ҳ
void C_Main_Menu()//
{
	printf("\n���˵���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1���涹\n");
		printf("\n\n\t\t��2��ȡ��\n");
		printf("\n\n\t\t��3��ת��\n");
		printf("\n\n\t\t��4����ѯ\n");
		printf("\n\n\t\t��5���޸ĸ�������\n");
		printf("\n\n\t\t��6��ע���˺�\n");
		printf("\n\n\t\t��7��С��Ϸ�ܶ�\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
			printf("\n���˵���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t\t�������\n");
			k1 = 1;
			break;
		}
	}
}

//���Ĳ˵�ҳ�����
void C_Easy_Main_Menu()
{
	printf("\n���˵���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	int index = 0;
	char ch;
	string select[] = { "��1���涹","��2��ȡ��","��3��ת��","��4���˳�ϵͳ","","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//Ӣ��˵�ҳ
void E_Main_Menu()//
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1��Deposit money\n");
		printf("\n\n\t\t��2��Withdraw money\n");
		printf("\n\n\t\t��3��Transfer money\n");
		printf("\n\n\t\t��4��Inquire\n");
		printf("\n\n\t\t��5��Modify personal information\n");
		printf("\n\n\t\t��6��Logout\n");
		printf("\n\n\t\t��0��Exit system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//���Ĵ涹ҵ��
void C_DepositMoney()
{
	int a;
	printf("\n���涹��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t����ܰ��ʾ��1.���ֶ�������Ϊ100��������\n\n\t\t     2.���ʴ涹���ó���10000��");
	printf("\n\n\n\t>>��������Ҫ����Ļ��ֶ���\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n���涹��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("���ʴ涹���ó���10000��\n\n");
			}
			else
				printf("���ֶ�������Ϊ100��������\n\n");
			C_DepositMoney1();//�涹ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t���ʴ涹���ó���10000��\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\t���ֶ�������Ϊ100��������\n\n");
			C_Easy_DepositMoney1();
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		printf("\n���涹��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		CE_Save_User_Data();
		CE_Deposit_Transaction();
		if (Sin == 1)
		{
			printf("\n\t�������ѳɹ�����%.2f���ֶ�!!!!\n", TA.Money);
			C_DepositMoney2();//�涹�ɹ�ѡ��
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t�������ѳɹ�����%.2f���ֶ�!!!!\n", TA.Money);
			C_Easy_DepositMoney2();
		}
	}
}

//�涹ʧ��ѡ��
void C_DepositMoney1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t��1���������뻶�ֶ�����\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//�涹�ɹ�ѡ��
void C_DepositMoney2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t��1���ٴ�һ��\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//�涹ʧ��ѡ����
void C_Easy_DepositMoney1()
{
	int index = 0;
	char ch;
	string select[] = { "��1���������뻶�ֶ�����","��2��������ҳ","��3���˳�ϵͳ","","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//�涹�ɹ�ѡ����
void C_Easy_DepositMoney2()
{
	int index = 0;
	char ch;
	string select[] = { "��1���ٴ�һ��","��2��������ҳ","��3���˳�ϵͳ" ,"","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//Ӣ��涹ҵ��
void E_DepositMoney()
{
	int a;
	printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t[Reminder] 1. The number of happy beans must be an integer of 100.\n\n\t\t2. A single deposit of beans cannot exceed 10,000.");
	printf("\n\n\n\t>>Please enter the happy bean you want to deposit:\n");
	printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
			printf("\n\n\t\t��1��Re-enter the amount of happy beans\n");
			printf("\n\n\t\t��2��Return to homepage\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
			printf("\n\n\t\t��1��Save another one\n");
			printf("\n\n\t\t��2��Return to homepage\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//����ȡ��ҵ��
void C_Withdraw_Money()
{
	int a;
	printf("\n��ȡ����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t\t����ܰ��ʾ��1.���ֶ�������Ϊ100��������");
	printf("\n\n\n\t\t\t     2.����ȡ�����ó���10000��");
	printf("\n\n\n\t\t>>��������Ҫȡ���Ļ��ֶ���______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n��ȡ����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("����ȡ�����ó���10000��\n\n");
			}
			else
				printf("���ֶ�������Ϊ100��������\n\n");
			C_Withdraw_Money1();//ȡ��ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t����ȡ�����ó���10000��\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\t���ֶ�������Ϊ100��������\n\n");
			C_Easy_Withdraw_Money1();//ȡ��ʧ��ѡ����
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n��ȡ����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			if (Sin == 1)
			{
				printf("\n\t���ֶ�����!!!!\n");
				C_Withdraw_Money1();//ȡ��ʧ��ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t���ֶ�����!!!!\n");
				C_Easy_Withdraw_Money1();//ȡ��ʧ��ѡ����
			}
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			printf("\n��ȡ����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			if (Sin == 1)
			{
				printf("\n\tȡ���ɹ�!!!!\n");
				C_Withdraw_Money2();//ȡ���ɹ�ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\tȡ���ɹ�!!!!\n");
				C_Easy_Withdraw_Money2();//ȡ���ɹ�ѡ����
			}
		}
	}
}

//ȡ��ʧ��ѡ��
void C_Withdraw_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1���������뻶�ֶ�����");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//ȡ���ɹ�ѡ��
void C_Withdraw_Money2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1���ٴ�ȡ��");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//ȡ��ʧ��ѡ����
void C_Easy_Withdraw_Money1()
{
	int index = 0;
	char ch;
	string select[] = { "��1���������뻶�ֶ�����","��2��������ҳ","��3���˳�ϵͳ" ,"","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//ȡ���ɹ�ѡ����
void C_Easy_Withdraw_Money2()
{
	int index = 0;
	char ch;
	string select[] = { "��1����ȡһ��","��2��������ҳ","��3���˳�ϵͳ","","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//Ӣ��ȡ��ҵ��
void E_Withdraw_Money()
{
	int a;
	printf("\n��Take Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
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
		printf("\n��Take Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (a > 10000)
		{
			printf("Single deposit must not exceed 10000.\n\n");
		}
		else
			printf("The amount of happy beans must be an integer of 100.\n\n");
		while (k < 3)
		{
			printf("\n\n\n\t\t��1�� Re-enter the amount of happy beans");
			printf("\n\n\n\t\t��2�� Return to home page");
			printf("\n\n\n\t\t��0�� Exit the system");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
			printf("\n��Take Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nNot enough happy beans!!!!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Re-enter the amount of happy beans");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
			printf("\n��Take Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nGet the beans successfully!!!!\n");
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Take beans again");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//ת��ҵ��
void C_Transfer_Money()
{
	int a = 100;
	printf("\n��ת����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\t---------------------��ת����֪��----------------------\n");
	printf("\t1������ת�����ó���10000���ֶ���\n\t\n");
	printf("\t2��ͬ��ת������ȡ2%%�������ѡ�\n\t\n");
	printf("\t3������ת������ȡ5%%�������ѡ�\n\t\n");
	printf("\t2���㶹����Ī���棬İ���绰Ҫ������\n\t\n");
	printf("\t  ��������֪��ǳ�������ɼ�Ҫʵ�ϡ�\n");
	printf("\t----------------------------------------------------\n");
	printf("\n\n\n\n\t\t>>��������Ҫת�������˻���__________\b\b\b\b\b\b\b\b\b\b");
	Account TT;//Ŀ���˻�
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		ACCOUNT = atoi(curAccount->account_number);//��ǰ�˻�ת��Ϊ��ֵ
		TACCOUNT = atoi(TT.account_number);        //��ǰ�Է��˻�ת��Ϊ��ֵ
		system("cls");
		printf("\n��ת����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			printf("\t---------------------��ת����֪��----------------------\n");
			printf("\t1������ת�����ó���10000���ֶ���\n\t\n");
			printf("\t2��ͬ��ת������ȡ2%%�������ѡ�\n\t\n");
			printf("\t3������ת������ȡ5%%�������ѡ�\n\t\n");
			printf("\t2���㶹����Ī���棬İ���绰Ҫ������\n\t\n");
			printf("\t  ��������֪��ǳ�������ɼ�Ҫʵ�ϡ�\n");
			printf("\t----------------------------------------------------\n");
			printf("\n\n\t\t>>��������Ҫת���Ļ��ֶ����______\b\b\b\b\b\b");
		}
		else if (Sin == 3)
		{
			printf("\n\n\t\t>>��������Ҫת���Ļ��ֶ����______\b\b\b\b\b\b");
		}
		scanf("%d", &a);
		if (a > 10000)
		{

			if (Sin == 1)
			{
				printf("\n\t����ת�����ó���10000��\n\n");
				C_Transfer_Money1();//ȡ��ʧ��ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t����ת�����ó���10000��\n\n");
				C_Easy_Transfer_Money1();//ȡ��ʧ��ѡ����
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
				printf("\n��ת����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");

				if (Sin == 1)
				{
					printf("\n\t���ֶ�����!!!!\n");
					C_Transfer_Money1();          //ת��ʧ��ѡ��
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\t���ֶ�����!!!!\n");
					C_Easy_Transfer_Money1();      //ת��ʧ��ѡ����
				}
			}
			else
			{
				system("cls");
				printf("\n��ת����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
				printf("\n==================================================================================================\n");
				curAccount->balance = curAccount->balance + TA.Money - SXFmoey;//��ǰ�˻���ȥת�˽���������
				curAccountO->balance = curAccountO->balance - TA.Money;      //�Է��˻�����ת�˽��
				CE_Transfer_Transaction();
				CE_SXF_Transaction();
				CE_Save_User_Data();
				if (Sin == 1)
				{
					printf("\n\tת���ɹ�!!!!\n");
					C_Transfer_Money2();           //ת���ɹ�ѡ��
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\tת���ɹ�!!!!\n");
					C_Easy_Transfer_Money2();      //ת���ɹ�ѡ����
				}
			}
		}
	}
	else
	{
		system("cls");
		printf("\n��ת����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (Sin == 1)
		{
			printf("\n\t�Է��˻������ڣ�������");
			C_Transfer_Money1();             //ȡ��ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t�Է��˻������ڣ�������");
			C_Easy_Transfer_Money1();        //ȡ��ʧ��ѡ����
		}
	}
}

//ת��ʧ��ѡ��
void C_Transfer_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1������ת��");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//ת���ɹ�ѡ��
void C_Transfer_Money2()
{
	int k2 = 0, b;
	while (k2 < 3)
	{
		printf("\n\n\n\t\t��1���ٴ�ת��");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//ת��ʧ��ѡ����
void C_Easy_Transfer_Money1()
{
	int index = 0;
	char ch;
	string select[] = { "��1����������","��2��������ҳ","��3���˳�ϵͳ","","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//ת���ɹ�ѡ����
void C_Easy_Transfer_Money2()
{
	int index = 0;
	char ch;
	string select[] = { "��1����ȡһ��","��2��������ҳ","��3���˳�ϵͳ","","","����� �� �� ѡ���ܣ��س���ȷ��" };
	string str = "�� ";
	gotoxy(5, 1);
	//printf("����� �� �� ѡ���ܣ��س���ȷ����\n");
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
				if (ch == 27) //�˳�
				{
					printf("exit system\n");
					Sleep(2000);
				}
				else if (ch == 72) //��
				{
					printf("\r%*c\r", 79, ' ');
					gotoxy(9, 3 + index);
					cout << select[index];
					index--;
				}
				else if (ch == 80)//��
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

//ת��ҵ��
void E_Transfer_Money()
{
	int a = 100;
	printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\n\n\t��Reminder��1. No more than 10000 happy beans can be sent at a time.\n");
	printf("\n\n\t\t2.Beware of scams.");
	printf("\n\n\t\t>>Please enter the account you want to send to:\n\n");
	printf("\n\n\t\t\t___\b\b\b");
	Account TT;
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		system("cls");
		printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t��Reminder��1. No more than 10000 happy beans can be sent at a time.\n");
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
			printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nNot enough happy beans!!!!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Re-enter the amount of happy beans");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
			printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\nSuccessful delivery of beans!!!!\n");
			curAccount->balance = curAccount->balance + TA.Money;//��ǰ�˻���ȥת�˽��
			curAccountO->balance = curAccountO->balance - TA.Money;//�Է��˻�����ת�˽��
			CE_Transfer_Transaction();
			CE_Save_User_Data();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t[1] Transfer beans again");
				printf("\n\n\n\t\t[2] Return to the home page");
				printf("\n\n\n\t\t[0] Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
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
		printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\nThe account of the other party does not exist!!!!");
		while (k < 3)
		{
			printf("\n\n\n\t\t��1�� Re-enter the other party's account number");
			printf("\n\n\n\t\t��2�� Return to home page");
			printf("\n\n\n\t\t��0�� Exit the system\n\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//��ѯҵ��ҳ
void C_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n����ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t��1���˻�����ѯ\n");
		printf("\n\n\t\t��2��������Ϣ��ѯ\n");
		printf("\n\n\t\t��3�����׼�¼��ѯ\n");
		printf("\n\n\t\t��4��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//��ѯҵ��ҳ
void E_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n��Inquire��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t��1��Account balance inquiry\n");
		printf("\n\n\t\t��2��Personal information query\n");
		printf("\n\n\t\t��3��Transaction record query\n");
		printf("\n\n\t\t��4��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
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

//�˻�����ѯ
void C_Enquiry_balance()
{
	printf("\n���˻��ඹ��ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Time();
	printf("\n\t���Ļ��ֶ����Ϊ��\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��������һҳ\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//�˻�����ѯ
void E_Enquiry_balance()
{
	printf("\n��Account balance query��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Time();
	printf("\n\tYour Happy Beans also include:\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t��2��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
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

//������Ϣ��ѯ
void C_Enquiry_Information()
{
	printf("\n��������Ϣ��ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\t������\n\t\t%s\n", curAccount->name);
	printf("\n\t�˺ţ�\n\t\t%s\n", curAccount->account_number);
	printf("\n\tԤ���ֻ��ţ�\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t��1��������һҳ\n");
		printf("\n\n\t\t\t��2��������ҳ\n");
		printf("\n\n\t\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//������Ϣ��ѯ
void E_Enquiry_Information()
{
	printf("\n��Personal information inquiry��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	printf("\n\tName��\n\t\t%s\n", curAccount->name);
	printf("\n\tAccount number��\n\t\t%s\n", curAccount->account_number);
	printf("\n\tReserved phone number��\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t\t��2��Return to homepage\n");
		printf("\n\n\t\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//���׼�¼��ѯ
void C_Enquiry_Record()
{
	printf("\n�����׼�¼��ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��������һҳ\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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

//���׼�¼��ѯ
void E_Enquiry_Record()
{
	printf("\n��Transaction record query��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	printf("\n==================================================================================================\n");
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t��2��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
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

//�޸���Ϣѡ��ҳ
void C_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{
		printf("\n���޸ĸ������ϡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t��1���޸��û�����\n");
		printf("\n\n\t\t��2���޸��˻�����\n");
		printf("\n\n\t\t��3���޸���ϵ�绰\n");
		printf("\n\n\t\t��4���޸��˻�����\n");
		printf("\n\n\t\t��9��������һҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
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
			printf("�������\t�밴����ʾ�������룺\n");
			break;
		}
	}
}

//�޸���Ϣѡ��ҳ
void E_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{

		printf("\n��Modify personal information��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t\t��1��Modify user name\n");
		printf("\n\n\t\t��2��Modify account number\n");
		printf("\n\n\t\t��3��Modify contact number\n");
		printf("\n\n\t\t��4��Change account password\n");
		printf("\n\n\t\t��9��Go back to the last page\n");
		printf("\n\n\t\t��0��Exit system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//�޸��û�
void C_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>���������û�����:\n");
			printf("\n\n\t___\b\b\b\n");
			scanf("%s", curAccount->name);
			printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t�û������޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸��û�
void E_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new user name:\n");
			scanf("%s", curAccount->name);
			printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\tUser name modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Return to the previous page\n");
				printf("\n\n\t\t��2��Return to homepage\n");
				printf("\n\n\t\t��0��Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
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

//�޸��˻�
void C_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>���������˻�����:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t�˻������޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸��˻�
void E_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter new account number:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\tThe account number has been modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Return to the previous page\n");
				printf("\n\n\t\t��2��Return to homepage\n");
				printf("\n\n\t\t��0��Exit the system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
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

//�޸���ϵ�绰
void C_Change_phone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>����������ϵ�绰����:\n");
			scanf("%s", curAccount->phone_number);
			system("cls");
			printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			printf("\n\n\t��ϵ�绰�޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸���ϵ�绰
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
		char storePassword[10] = { '\0' };    //�洢�û����������
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
				printf("\n\n\t\t��1��Go back to the last page\n");
				printf("\n\n\t\t��2��Return to home page\n");
				printf("\n\n\t\t��0��Exit system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
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

//�޸�����
void C_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>������ԭʼ���룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>������������:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
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
			printf("\n\n\t�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸�����
void E_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		printf("\n\n\n\t>>Please enter your password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n==================================================================================================\n");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new password:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			printf("\n==================================================================================================\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Go back to the last page\n");
				printf("\n\n\t\t��2��Return to home page\n");
				printf("\n\n\t\t��0��Exit system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
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
			printf("\n\n\t�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//��ʼ����
void start()
{
	printf("\n\t----------------------����ӭʹ���Զ���ȡ������---------------------\n");
	printf("\t     Welcome to the Automated Deposit/Withdrawal Beans Machine\n\n");
	printf("\t1�����Զ���ȡ����֧����������ģʽ�����ģ�Ӣ�\n\t\n");
	printf("\t   This machine supports two language modes, Chinese, English.\n\t\n");
	printf("\t2��ѡ��ҳ����Ҫ�����Ӧѡ�����֣����س���ȷ��ѡ����ģʽ���⣩��\n\t\n");
	printf("\t   Enter the option number and press Enter to confirm the option.\n\t\n");
	printf("\t-------------------------------------------------------------------");
	int k = 1;
	while (k)
	{
		printf("\n\n\t\t����ѡ�����ԣ�\t");
		printf("��Please choose language��\n");
		printf("\n\n\t\t\t��1������\n");
		printf("\n\n\t\t\t��2��English\n");
		printf("\n\n\t\t\t��0���˳� Exit\n\n\n\t\t\t");
		printf("\n\n\t\t\t������ѡ��/Your choice��___\b\b\b");
		scanf("%d", &Language);
		switch (Language)
		{
		case 1:
			system("cls");
			printf("\n\t----------------------���û���֪��------------------------------\n");
			printf("\t1���û���¼ʱ����ȷ�����ʻ����룬����������κ��Զ��˳�ϵͳ��\n\t\n");
			printf("\t2����¼��������������κ��ʻ����������˳�ϵͳ��������Ա�ɽ�⡣\n\t\n");
			printf("\t3���û�ע��ʱ�밴��ʾ���������Ϣ�������������ν��Զ��˳�ϵͳ��\n\t\n");
			printf("\t4���û�ע��ʱ���������пɹ�ѡ��ע�⣺��ͬ���������ѿ��ܲ�ͬ��\n\t\n");
			printf("\t----------------------------------------------------------------\n");
			printf("\n\n\t\t\t��1���û���¼\n");
			printf("\n\n\t\t\t��2���û�ע��\n");
			printf("\n\n\t\t\t��3�����ĵ�¼����\n");
			printf("\n\n\t\t\t��������������һҳ\n");
			printf("\n\n\t\t\t|����ѡ��___\b\b\b");
			break;
		case 2:
			system("cls");
			printf("\n\n\t\t\t��1��Sign in\n");
			printf("\n\n\t\t\t��2��Sign up\n");
			printf("\n\n\t\t\t��Others��Back to previous page\n");
			printf("\n\n\t\t\tYour choice��___\b\b\b");
			break;
		case 0:
			exit(0);
		default:
			k = 1;
			system("cls");
			printf("\n\n\t\t���������밴����ʾ�ٴ�����!\t\t");
			printf("Error,please follow the prompts to enter again!\n\n");
			break;
		}
		printf("___\b\b\b");
		scanf("%d", &Sin);
		k = 0;
		if (Sin == 1)
		{
			C_Sign_In();//����ע�ắ��
		}
		else if (Sin == 2)
		{
			Sin = 1;
			C_Sign_Up();
		}
		else if (Sin == 3)
		{
			printf("\t----------------------���������ļ��ģʽ��֪��-----------------------\n");
			printf("\t1�����ļ��ģʽ��ֻ֧�ִ涹��ȡ����ת��ҵ������ҵ���뵽����ģʽ��\n\t\n");
			printf("\t2���÷��������ѡ���Ӧѡ��س���ȷ��ѡ�\n\t\n");
			printf("\t3��ף��ʹ����죡\n\t\n");
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

