#include<stdio.h>
#include<conio.h>

//����ȫ�ֱ�������
int ID[10] = { 0 };         //ѧ��
char Name[5][10];  //����
char Sex[5][3];    //�Ա�
int Birth[80];     //����
int end = 0;	   //����,���ڵ��ú�������֮��

int main()
{
	//����
	void add();//6.���Ӻ���
	void del();//4.ɾ������
	void Exit();//8.�˳�����
	void sort();//7.������
	void Entry();//1.¼�뺯��
	void revise();//3.�޸ĺ���
	void display();//2.��ʾ����
	void inquire();//5.��ѯ����

	welcome:
	printf("��������������������������������������\n");
	printf("��������������������������������������\n");
	printf("��      ��ӭʹ��ѧ����Ϣ����ϵͳ    ��\n");
	printf("��                                  ��\n");
	printf("����      ��      ��      ��      ���\n");
	printf("��                                  ��\n");
	printf("��          �밴��ʾ����            ��\n");
	printf("��                                  ��\n");
	printf("����      ��      ��      ��      ���\n");
	printf("��                                  ��\n");
	printf("��    1.¼��            2.��ʾ      ��\n");
	printf("��                                  ��\n");
	printf("��    3.�޸�            4.ɾ��      ��\n");
	printf("��                                  ��\n");
	printf("��    5.��ѯ            6.׷��      ��\n");
	printf("��                                  ��\n");
	printf("��    7.����            8.�˳�      ��\n");
	printf("��                                  ��\n");
	printf("��������������������������������������\n");
	printf("\n");
	printf("ʹ��ǰ����¼����Ϣ\n");
	printf("\n");


	int select = 0;
	printf("�밴��ʾѡ����:");
	scanf_s("%d", &select);
	printf("\n");

	//¼������
	if (select == 1) {
		Entry();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//��ʾĿǰ�洢��ȫ������
	else if (select == 2) {
		display();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//�޸���Ϣ
	else if (select == 3) {
		revise();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//ɾ����Ϣ
	else if (select == 4) {
		del();
		printf("\n");
		printf("����ѡ�����Ϣ��ɾ��\n");
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//��ѯĳ����Ϣ
	else if (select == 5) {
		inquire();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//����ĳ�˵���Ϣ
	else if (select == 6) {
		add();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else {
			goto welcome;
		}
	}

	//Ϊȫ����Ϣ����
	else if (select == 7) {
		sort();
		printf("�˳��밴 1 ,�� 2 ����������\n");
		scanf_s("%d", &end);
		if (end == 1) {
			Exit();
		}
		else if (end == 2) {
			goto welcome;
		}
	}


	//�˳�
	else if (select == 8) {
		Exit();
	}

	//��ѡ����1-8ʱ
	else if (select < 1 || select >8) {
		printf("�밴��ʾѡ��\n");
		printf("\n");
		goto welcome;
	}


	return 0;
}


//¼������
void Entry(){

	int a = 0;

	back:
	printf("����������������������������������������\n");
	printf("��                                    ��\n");
	printf("��       ��ӭʹ����Ϣ¼�빦��         ��\n");
	printf("��                                    ��\n");
	printf("����������������������������������������\n");
	printf("\n");
	printf("��ѡ����Ҫ¼�������(������10):");
	scanf_s("%d", &a);
	printf("\n");

	if (a < 11) {
		for (int n = 0;n < a;n++) {
			printf("������ѧ��:");
			scanf_s("%d", &ID[n]);
			printf("\n");

			//scanf��scanf_s������
			printf("����������:");
			scanf_s("%s", Name[n], 10);
			printf("\n");

			printf("�������Ա�:");
			scanf_s("%s", Sex[n], 3);
			printf("\n");

			printf("����������:");
			scanf_s("%d", &Birth[n]);
			printf("\n");
		}
	}

	else {
		printf("������Ҫ���� 10 �� \n");
		printf("\n");
		goto back;
	}
}


//�鿴�������ݺ���
void display() {

	printf("����������������������������������������\n");
	printf("��                                    ��\n");
	printf("��           �鿴��¼�����Ϣ         ��\n");
	printf("��                                    ��\n");
	printf("����������������������������������������\n");

	printf("\n");
	printf("         ѧ��              ����         �Ա�           ����\n");
	for (int n = 0;n < 10;n++) {
		if (ID[n] != 0) {
			printf("       %d,           %s,       %s,          %d\n", ID[n], Name[n], Sex[n], Birth[n]);
			printf("\n");
		}
		
	}
	printf("\n");
}


//������ݺ���   
void add(){

	int a = 0;
	int n = 0;
	void Exit();

	Continue:
	printf("������������������������������������������������������\n");
	printf("��                                                  ��\n");
	printf("��           ��������Ҫ���ӵ�ѧ����Ϣ����           ��\n");
	printf("��                                                  ��\n");
	printf("��              �˳������� 0                        ��\n");
	printf("������������������������������������������������������\n");
	printf("\n");
	printf("��������Ҫ���ӵ�ѧ����Ϣ����:");
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
				printf("������ѧ��ѧ��:");
				scanf_s("%d", &ID[n]);
				printf("\n");

				printf("������ѧ������:");
				scanf_s("%s", Name[n], 10);
				printf("\n");

				printf("������ѧ���Ա�:");
				scanf_s("%s", Sex[n], 3);
				printf("\n");

				printf("������ѧ����������:");
				scanf_s("%d", &Birth[n]);
				printf("\n");
			}
			printf("���� 1 ������ӣ����� 2 ����");
			scanf_s("%d", &end);
			printf("\n");
			if (end == 1) {
				goto Continue;
			}

		}

		else {
			printf("������������� 10 \n");
			printf("\n");
			goto Continue;
		}
	}
	

}


//�޸����ݺ���
void revise(){

	int a = 0;         //����a���ж�ѡ��ļ�����ʽ
	int n = 0;         //����n��ȷ��Ҫ���������λ��

	back:
	printf("����������������������������������������\n");
	printf("��                                    ��\n");
	printf("��         ��ӭʹ����Ϣɾ��ϵͳ       ��\n");
	printf("��                                    ��\n");
	printf("��    ѡ�����ļ�����ʽ��              ��\n");
	printf("��                                    ��\n");
	printf("��    1.ѧ��            2.����        ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��    3.����                          ��\n");
	printf("��                                    ��\n");
	printf("����������������������������������������\n");
	printf("\n");
	printf("ѡ�����ļ�����ʽ:");
	scanf_s("%d", &a);
	printf("\n");

	//ͨ��ѧ���������޸���Ϣ
	if (a == 1) {
		printf("���������޸���Ϣ��ѧ��");
		scanf_s("%d", &n);
		printf("\n");

		for (int i = 0;i < 11;i++) {
			if (n == ID[i]) {
				printf("������ѧ��:");
				scanf_s("%d", &ID[i]);
				printf("\n");

				printf("����������:");
				scanf_s("%s", Name[i], 10);
				printf("\n");

				printf("�������Ա�:");
				scanf_s("%s", Sex[i], 3);
				printf("\n");

				printf("�������������:");
				scanf_s("%d", &Birth[i]);
				printf("\n");

				break;
			}
			if (i > 9) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ�������������޸�
	else if (a == 2) {
		printf("���������޸���Ϣ�˵�����:");
		scanf_s("%d", &n);
		printf("\n");

		for (int i = 0;i < 11;i++) {
			if (n == Birth[i]) {
				printf("������ѧ��:");
				scanf_s("%d", &ID[i]);
				printf("\n");

				printf("����������:");
				scanf_s("%s", Name[i], 10);
				printf("\n");

				printf("�������Ա�:");
				scanf_s("%s", Sex[i], 3);
				printf("\n");

				printf("�������������:");
				scanf_s("%d", &Birth[i]);
				printf("\n");
				break;
			}

			if (i == 10) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ�������������޸�
	else if (a == 3) {
		char t[10];
		printf("���������ѯ������:");
		scanf_s("%s", t, 10);
		printf("\n");
		for (int i = 0;i < 11; i++) {
			if (strcmp(t, Name[i]) == 0 && ID[i] > 0) {
				printf("������ѧ��:");
				scanf_s("%d", &ID[i - 1]);

				printf("����������:");
				scanf_s("%s", Name[i], 10);

				printf("�������Ա�:");
				scanf_s("%s", Sex[i], 3);

				printf("�������������:");
				scanf_s("%d", &Birth[i]);
				printf("\n");

				break;
			}
			if (i == 10) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	else if (a > 3 || a < 1) {
		printf("�밴��ʾ����");
		printf("\n");
		goto back;
	}
}


//��ѯ��Ϣ����    
void inquire(){

	//��a���ж�ѡ���ѯ��ʽ
	int a = 0;

	back:
	printf("����������������������������������������\n");
	printf("��                                    ��\n");
	printf("��         ��ӭʹ����Ϣ��ѯϵͳ       ��\n");
	printf("��                                    ��\n");
	printf("��    ѡ�����Ĳ�ѯ��ʽ��              ��\n");
	printf("��                                    ��\n");
	printf("��    1.ѧ��            2.����        ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��    3.����                          ��\n");
	printf("��                                    ��\n");
	printf("����������������������������������������\n");


	printf("��ѡ��Ĳ�ѯ��ʽ�ǣ�");
	scanf_s("%d", &a);
	printf("\n");

	//ͨ��ѧ�Ų�ѯ
	if (a == 1) {
		int i = 0;
		printf("���������ѯ��ѧ��:");
		scanf_s("%d", &i);
		printf("\n");

		for (int n = 0;n < 11;n++) {
			if (i == ID[n]) {
				printf("%d,%s,%s,%d", ID[n],Name[n],Sex[n],Birth[n]);
				printf("\n");
				break;
			}
			if (n == 10) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ�����ղ�ѯ
	else if (a == 2) {
		int i = 0;
		printf("�������ѯ������:");
		scanf_s("%d", &i);
		printf("\n");


		for (int n = 0;n < 11;n++) {
			if (i == Birth[n]) {
				printf("%d,%s,%s,%d", ID[n], Name[n], Sex[n], Birth[n]);
				printf("\n");
				break;
			}
			if (n == 10) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ��������ѯ
	else if (a == 3) {
		char t[10];
		printf("���������ѯ������:");
		scanf_s("%s", t, 10);
		printf("\n");
		for (int i = 0;i < 11; i++) {
			if (strcmp(t, Name[i]) == 0 && ID[i] > 0) {
				printf("%d,%s,%s,%d\n", ID[i-1], Name[i-1], Sex[i-1], Birth[i-1]);
				printf("\n");
				break;
			}
			if (i == 10) {
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//�����벻��ȷʱѭ��
	else if (a < 1 || a>3) {
		printf("�밴�涨��������\n");
		printf("\n");
		goto back;
	}

}


//��Ϣɾ������ 
void del(){
	int a = 0, n = 0;
	char t[10];

	back:
	printf("����������������������������������������\n");
	printf("��                                    ��\n");
	printf("��         ��ӭʹ����Ϣɾ��ϵͳ       ��\n");
	printf("��                                    ��\n");
	printf("��    ѡ�����Ĳ�ѯ��ʽ��              ��\n");
	printf("��                                    ��\n");
	printf("��    1.ѧ��            2.����        ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��    3.����                          ��\n");
	printf("��                                    ��\n");
	printf("����������������������������������������\n");
	printf("\n");
	printf("ѡ�����Ĳ�ѯ��ʽ:");
	scanf_s("%d", &a);
	printf("\n");

	//ͨ��ѧ��ɾ��
	if (a == 1) {
		printf("����������ɾ����Ϣ��ѧ��;");
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
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ������ɾ��
	else if (a == 2) {
		printf("����������ɾ����Ϣ������:");
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
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//ͨ������ɾ��
	else if (a == 3) {
		printf("����������ɾ����Ϣ������:");
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
				printf("û��Ҫ��ѯ����Ϣ\n");
				printf("\n");
				goto back;
			}
		}
	}

	//�����벻��ȷʱ
	else if (a < 1 || a>3) {
		printf("�밴��ʾ��������\n");
		printf("\n");
		goto back;
	}

}



//������
void sort(){

	int a = 0;
	void Exit();

	back:
	printf("��������������������������������������������\n");
	printf("��                                        ��\n");
	printf("��              ��Ϣ����ϵͳ              ��\n");
	printf("��                                        ��\n");
	printf("��  1.��ѧ������        2.����������      ��\n");
	printf("��������������������������������������������\n");
	printf("����������ѡ��");
	scanf_s("%d", &a);
	printf("\n");

	//���ݷ�

	//��ѧ��
	if (a == 1) {
		for (int i = 0;i < 5;i++) {
			for (int j = i + 1;j < 5;j++) {
				//�����ĸ��м����
				int temp0 = 0;
				char temp1[10];
				char temp2[3];
				int temp3 = 0;
				if (ID[i] > ID[j]) {
					//�������
					temp0 = ID[i];
					for (int k = 0;k < 10;k++) {
						temp1[k] = Name[i][k];
					}
					//�������������洢����
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

	//������
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
		printf("�밴��ʾ����");
		printf("\n");
		goto back;
	}

}


//�˳�����
void Exit() {

printf("��������˳�");
_getch();
}

//�Ż�

//�Ż�����¼��ʱ��ѡ�����������

//�Ż���������Ϣ�����bug�޸ģ���ɱ�˸����Ѽ���

//�Ż���ɾ��ʱ�Ŀհ�����

//�Ż������޸�����ʱ����ͨ�����ռ���������

//�Ż��������������

//�Ż����ڲ�ѯ �޸� ���ɾ������ִ��ʱ���벻��ѡ��Χ�ڵ����

//�Ż�������Ӻ�¼��ʱ��������10�����

//�Ż��˼���ʱ���ݲ����ڵ����



//���Ż�

//¼���ʽ

//��ѭ����Ƕ��̫���жϣ������ٶȸ���

//��ʾ��Ϣ��ʱ��û�취ͳһ��ʽ����

//���κ�״̬������exit���������������ѭ��

//�ظ�������̫��Ӧ�ð��ظ�ʹ�õ����ݷ�װ�������ﵫ��δ��ʵ�֣�ȫ���޸Ĺ�����̫��