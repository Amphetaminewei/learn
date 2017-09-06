#include<stdio.h>
#include<conio.h>

//建立全局变量数组
int ID[10] = { 0 };         //学号
char Name[5][10];  //姓名
char Sex[5][3];    //性别
int Birth[80];     //生日
int end = 0;	   //结束,用在调用函数结束之后

int main()
{
	//调用
	void add();//6.增加函数
	void del();//4.删除函数
	void Exit();//8.退出函数
	void sort();//7.排序函数
	void Entry();//1.录入函数
	void revise();//3.修改函数
	void display();//2.显示函数
	void inquire();//5.查询函数

	welcome:
	printf("■■■■■■■■■■■■■■■■■■■\n");
	printf("■　　　　　　　　　　　　　　　　　■\n");
	printf("■      欢迎使用学生信息管理系统    ■\n");
	printf("■                                  ■\n");
	printf("■★      ★      ★      ★      ★■\n");
	printf("■                                  ■\n");
	printf("■          请按提示操作            ■\n");
	printf("■                                  ■\n");
	printf("■★      ★      ★      ★      ★■\n");
	printf("■                                  ■\n");
	printf("■    1.录入            2.显示      ■\n");
	printf("■                                  ■\n");
	printf("■    3.修改            4.删除      ■\n");
	printf("■                                  ■\n");
	printf("■    5.查询            6.追加      ■\n");
	printf("■                                  ■\n");
	printf("■    7.排序            8.退出      ■\n");
	printf("■                                  ■\n");
	printf("■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("使用前请先录入信息\n");
	printf("\n");


	int select = 0;
	printf("请按提示选择功能:");
	scanf_s("%d", &select);
	printf("\n");

	//录入数据
	if (select == 1) {
		Entry();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//显示目前存储的全部数据
	else if (select == 2) {
		display();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//修改信息
	else if (select == 3) {
		revise();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//删除信息
	else if (select == 4) {
		del();
		printf("\n");
		printf("您所选择的信息已删除\n");
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//查询某人信息
	else if (select == 5) {
		inquire();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//加入某人的信息
	else if (select == 6) {
		add();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//为全部信息排序
	else if (select == 7) {
		sort();
		printf("退出请按 1 ,按 2 返回主界面\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else if (end == 2) {
			goto welcome;
		}
	}


	//退出
	else if (select == 8) {
		Exit();
	}

	//当选择不在1-8时
	else if (select < 1 || select >8) {
		printf("请按提示选择\n");
		printf("\n");
		goto welcome;
	}


	return 0;
}


//录入数据
void Entry(){

	int a = 0;

	back:
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■       欢迎使用信息录入功能         ■\n");
	printf("■                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("请选择您要录入的人数(不大于10):");
	scanf_s("%d", &a);
	printf("\n");

	if (a < 11) {
		for (int n = 0;n < a;n++) {
			printf("请输入学号:");
			scanf_s("%d", &ID[n]);
			printf("\n");

			//scanf与scanf_s的区别
			printf("请输入姓名:");
			scanf_s("%s", Name[n], 10);
			printf("\n");

			printf("请输入性别:");
			scanf_s("%s", Sex[n], 3);
			printf("\n");

			printf("请输入生日:");
			scanf_s("%d", &Birth[n]);
			printf("\n");
		}
	}

	else {
		printf("总数不要超过 10 人 \n");
		printf("\n");
		goto back;
	}
}


//查看现有数据函数
void display() {

	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■           查看以录入的信息         ■\n");
	printf("■                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");

	printf("\n");
	printf("         学号              姓名         性别           生日\n");
	for (int n = 0;n < 10;n++) {
		if (ID[n] != 0) {
			printf("       %d,           %s,       %s,          %d\n", ID[n], Name[n], Sex[n], Birth[n]);
			printf("\n");
		}
		
	}
	printf("\n");
}


//添加数据函数   
void add(){

	int a = 0;
	int n = 0;
	void Exit();

	Continue:
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                  ■\n");
	printf("■           请输入您要增加的学生信息数量           ■\n");
	printf("■                                                  ■\n");
	printf("■              退出请输入 0                        ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("请输入您要增加的学生信息数量:");
	scanf_s("%d", &a);
	printf("\n");

	if (a == 0) {
		Exit();
	}
	
	else {
		
		for (int i = 0;i < 10;i++) {
			if (ID[i] == 0 ) {
				n = i;
				break;
			}
		}
		if (n + a < 10) {
			int m = n;
			for (n;n < a + m;n++) {
				printf("请输入学生学号:");
				scanf_s("%d", &ID[n]);
				printf("\n");

				printf("请输入学生姓名:");
				scanf_s("%s", Name[n], 10);
				printf("\n");

				printf("请输入学生性别:");
				scanf_s("%s", Sex[n], 3);
				printf("\n");

				printf("请输入学生出生年月:");
				scanf_s("%d", &Birth[n]);
				printf("\n");
			}
			printf("输入 1 继续添加，输入 2 返回");
			scanf_s("%d", &end);
			printf("\n");
			if (end == 1) {
				goto Continue;
			}

		}

		else {
			printf("输入的总数大于 10 \n");
			printf("\n");
			goto Continue;
		}
	}
	

}


//修改数据函数
void revise(){

	int a = 0;         //定义a来判断选择的检索方式
	int n = 0;         //定义n来确认要搜索的项的位置

	back:
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■         欢迎使用信息删除系统       ■\n");
	printf("■                                    ■\n");
	printf("■    选择您的检索方式：              ■\n");
	printf("■                                    ■\n");
	printf("■    1.学号            2.生日        ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■    3.姓名                          ■\n");
	printf("■                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("选择您的检索方式:");
	scanf_s("%d", &a);
	printf("\n");

	//通过学号搜索并修改信息
	if (a == 1) {
		printf("请输入想修改信息的学号");
		scanf_s("%d", &n);
		printf("\n");

		for (int i = 0;i < 11;i++) {
			if (n == ID[i]) {
				printf("请输入学号:");
				scanf_s("%d", &ID[i]);
				printf("\n");

				printf("请输入姓名:");
				scanf_s("%s", Name[i], 10);
				printf("\n");

				printf("请输入性别:");
				scanf_s("%s", Sex[i], 3);
				printf("\n");

				printf("请输入出生年月:");
				scanf_s("%d", &Birth[i]);
				printf("\n");

				break;
			}
			if (i > 9) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过生日搜索并修改
	else if (a == 2) {
		printf("请输入想修改信息人的生日:");
		scanf_s("%d", &n);
		printf("\n");

		for (int i = 0;i < 11;i++) {
			if (n == Birth[i]) {
				printf("请输入学号:");
				scanf_s("%d", &ID[i]);
				printf("\n");

				printf("请输入姓名:");
				scanf_s("%s", Name[i], 10);
				printf("\n");

				printf("请输入性别:");
				scanf_s("%s", Sex[i], 3);
				printf("\n");

				printf("请输入出生年月:");
				scanf_s("%d", &Birth[i]);
				printf("\n");
				break;
			}

			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过名字搜索并修改
	else if (a == 3) {
		char t[10];
		printf("输入您想查询的名字:");
		scanf_s("%s", t, 10);
		printf("\n");
		for (int i = 0;i < 11; i++) {
			if (strcmp(t, Name[i]) == 0 && ID[i] > 0) {
				printf("请输入学号:");
				scanf_s("%d", &ID[i - 1]);

				printf("请输入姓名:");
				scanf_s("%s", Name[i], 10);

				printf("请输入性别:");
				scanf_s("%s", Sex[i], 3);

				printf("请输入出生年月:");
				scanf_s("%d", &Birth[i]);
				printf("\n");

				break;
			}
			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	else if (a > 3 || a < 1) {
		printf("请按提示输入");
		printf("\n");
		goto back;
	}
}


//查询信息函数    
void inquire(){

	//用a的判断选择查询方式
	int a = 0;

	back:
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■         欢迎使用信息查询系统       ■\n");
	printf("■                                    ■\n");
	printf("■    选择您的查询方式：              ■\n");
	printf("■                                    ■\n");
	printf("■    1.学号            2.生日        ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■    3.姓名                          ■\n");
	printf("■                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");


	printf("您选择的查询方式是：");
	scanf_s("%d", &a);
	printf("\n");

	//通过学号查询
	if (a == 1) {
		int i = 0;
		printf("请输入想查询的学号:");
		scanf_s("%d", &i);
		printf("\n");

		for (int n = 0;n < 11;n++) {
			if (i == ID[n]) {
				printf("%d,%s,%s,%d", ID[n],Name[n],Sex[n],Birth[n]);
				printf("\n");
				break;
			}
			if (n == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过生日查询
	else if (a == 2) {
		int i = 0;
		printf("输入想查询的生日:");
		scanf_s("%d", &i);
		printf("\n");


		for (int n = 0;n < 11;n++) {
			if (i == Birth[n]) {
				printf("%d,%s,%s,%d", ID[n], Name[n], Sex[n], Birth[n]);
				printf("\n");
				break;
			}
			if (n == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过人名查询
	else if (a == 3) {
		char t[10];
		printf("输入您想查询的名字:");
		scanf_s("%s", t, 10);
		printf("\n");
		for (int i = 0;i < 11; i++) {
			if (strcmp(t, Name[i]) == 0 && ID[i] > 0) {
				printf("%d,%s,%s,%d\n", ID[i-1], Name[i-1], Sex[i-1], Birth[i-1]);
				printf("\n");
				break;
			}
			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//当输入不正确时循环
	else if (a < 1 || a>3) {
		printf("请按规定重新输入\n");
		printf("\n");
		goto back;
	}

}


//信息删除函数 
void del(){
	int a = 0, n = 0;
	char t[10];

	back:
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■         欢迎使用信息删除系统       ■\n");
	printf("■                                    ■\n");
	printf("■    选择您的查询方式：              ■\n");
	printf("■                                    ■\n");
	printf("■    1.学号            2.生日        ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■    3.姓名                          ■\n");
	printf("■                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("选择您的查询方式:");
	scanf_s("%d", &a);
	printf("\n");

	//通过学号删除
	if (a == 1) {
		printf("请输入您想删除信息的学号;");
		scanf_s("%d", &n);
		printf("\n");
		for (int i = 0;i < 11;i++) {
			if (ID[i] == n) {
				ID[i] = NULL;
				for (int j = 0;j < 10;j++) {
					Name[i][j] = NULL;
				}
				for (int j = 0;j < 3;j++) {
					Sex[i][j] = NULL;
				}
				Birth[i] = NULL;
				break;
			}
			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过生日删除
	else if (a == 2) {
		printf("请输入您想删除信息的生日:");
		scanf_s("%d", &n);
		printf("\n");
		for (int i = 0;i < 11;i++) {
			if (Birth[i] == n) {
				ID[i] = NULL;
				for (int j = 0;j < 10;j++) {
					Name[i][j] = NULL;
				}
				for (int j = 0;j < 3;j++) {
					Sex[i][j] = NULL;
				}
				Birth[i] = NULL;
				break;
			}
			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//通过人名删除
	else if (a == 3) {
		printf("请输入您想删除信息的人名:");
		scanf_s("%s", t, 10);
		printf("\n");
		for (int i = 0;i < 11 ; i++) {
			if (strcmp(t, Name[i]) == 0 && ID[i] != 0) {
				ID[i] = NULL;
				for (int j = 0;j < 10;j++) {
					Name[i][j] = NULL;
				}
				for (int j = 0;j < 3;j++) {
					Sex[i][j] = NULL;
				}
				Birth[i] = NULL;
				break;
			}
			if (i == 10) {
				printf("没有要查询的信息\n");
				printf("\n");
				goto back;
			}
		}
	}

	//当输入不正确时
	else if (a < 1 || a>3) {
		printf("请按提示重新输入\n");
		printf("\n");
		goto back;
	}

}



//排序函数
void sort(){

	int a = 0;
	void Exit();

	back:
	printf("■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                        ■\n");
	printf("■              信息排序系统              ■\n");
	printf("■                                        ■\n");
	printf("■  1.按学号排序        2.按生日排序      ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("请输入您的选择：");
	scanf_s("%d", &a);
	printf("\n");

	//起泡法

	//按学号
	if (a == 1) {
		for (int i = 0;i < 5;i++) {
			for (int j = i + 1;j < 5;j++) {
				//引入四个中间变量
				int temp0 = 0;
				char temp1[10];
				char temp2[3];
				int temp3 = 0;
				if (ID[i] > ID[j]) {
					//将两项交换
					temp0 = ID[i];
					for (int k = 0;k < 10;k++) {
						temp1[k] = Name[i][k];
					}
					//用两个数组来存储汉字
					for (int k = 0; k < 3; k++) {
						temp2[k] = Sex[i][k];
					}
					temp3 = Birth[i];
					ID[i] = ID[j];
					for (int k = 0;k < 10;k++) {
						Name[i][k] = Name[j][k];
					}
					for (int k = 0;k < 3;k++) {
						Sex[i][k] = Sex[j][k];
					}
					Birth[i] = Birth[j];
					ID[j] = temp0;
					for (int k = 0;k < 10;k++) {
						Name[j][k] = temp1[k];
					}
					for (int k = 0;k < 0;k++) {
						Sex[j][k] = temp2[k];
					}
					Birth[j] = temp3;
				}
			}
		}
		for (int a = 0;a < 5;a++) {
			if (ID[a] > 0) {
				printf("%d,%s,%s,%d\n", ID[a], Name[a], Sex[a], Birth[a]);
				printf("\n");
			}
		}
	}

	//按生日
	else if (a == 2) {
		for (int i = 0;i < 5;i++) {
			for (int j = i + 1;j < 5;j++) {
				int temp0 = 0;
				char temp1[10];
				char temp2[3];
				int temp3 = 0;
				if (Birth[i] > Birth[j]) {
					temp0 = ID[i];
					for (int k = 0;k < 10;k++) {
						temp1[k] = Name[i][k];
					}
					for (int k = 0;k < 3;k++) {
						temp2[k] = Sex[i][k];
					}
					temp3 = Birth[i];

					ID[i] = ID[j];
					for (int k = 0;k < 10;k++) {
						Name[i][k] = Name[j][k];
					}
					for (int k = 0;k < 3;k++) {
						Sex[i][k] = Sex[j][k];
					}
					Birth[i] = Birth[j];

					ID[j] = temp0;
					for (int k = 0;k < 10;k++) {
						Name[j][k] = temp1[k];
					}
					for (int k = 0;k < 3;k++) {
						Sex[j][k] = temp2[k];
					}
					Birth[j] = temp3;
				}
			}
		}
		for (int a = 0;a < 5;a++) {
			if (ID[0]) {
				printf("%d,%s,%s,%d\n", ID[a], Name[a], Sex[a], Birth[a]);
				printf("\n");
			}
		}
	}

	else if (a < 1 || a>2) {
		printf("请按提示输入");
		printf("\n");
		goto back;
	}

}


//退出函数
void Exit() {

printf("按任意键退出");
_getch();
}

//优化

//优化了在录入时可选择输入的人数

//优化了增加信息乱码的bug修改，还杀了个室友祭天

//优化了删除时的空白问题

//优化了在修改数据时增加通过生日及姓名搜索

//优化了整体的美观性

//优化了在查询 修改 添加删除函数执行时输入不在选择范围内的情况

//优化了在添加和录入时超出总数10的情况

//优化了检索时数据不存在的情况



//待优化

//录入格式

//在循环中嵌套太多判断，运行速度感人

//显示信息的时候没办法统一格式对齐

//在任何状态下输入exit命令会陷入无线死循环

//重复的内容太多应该把重复使用的内容封装到函数里但还未能实现（全部修改工作量太大