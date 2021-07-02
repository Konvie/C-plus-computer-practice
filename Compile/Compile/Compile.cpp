#include<iostream>
#include<string>
#include<sstream>
#include<fstream> 
#include<cstdlib>
#include<vector>

using namespace std;

//��ʼ���������������ļ���ȡ�ı�����
void initial(vector<string>& text)
{
	ifstream infile("�����ļ�.txt");			//����Ϊ�������ļ������ж�����
	if (!infile)							//���ڼ�������ļ��Ƿ���ڣ�infile�䵱һ��handle
	{
		cout << "open error" << endl;
		exit(0);
	}
	string temp;
	while (getline(infile, temp))
	{
		text.push_back(temp);				//��temp�����Ԫ��
	}
	infile.close();							//�ر��ļ�
}
void ShowText(vector<string>& text)
{
	int m, n;
	cin >> m >> n;
	cout<< "��" << m << "�е���" << n << "�е��ı�Ϊ:" <<endl;
	for (int i = m - 1; i < n; i++)
		cout << text[i] << endl;
}
void Insert(vector<string>& text)
{
	int m;
	cin >> m;
	cout << "���к�����^z��ɱ༭" << endl;
	int t = m;
	string temp;
	getline(cin, temp);
	while (getline(cin, temp))
	{
		if (temp == "^z")
			break;
		text.insert(text.begin() + t, temp);
		t++;
	}
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void Delete(vector<string>& text)
{
	int m, n;
	cin >> m >> n;
	text.erase(text.begin() + m - 1, text.begin() + n);
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void Replace(vector<string>& text)
{
	int m, n;
	cin >> m >> n;
	cout << "���к�����^z��ɱ༭" << endl;
	int t = m - 1;
	text.erase(text.begin() + t, text.begin() + n);
	string temp;
	
	getline(cin, temp);
	while (getline(cin, temp))
	{
		if (temp == "^z")
			break;
		text.insert(text.begin() + t, temp);
		t++;
	}
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void SaveQuit(vector<string>& text)
{
	ofstream outfile("����ļ�.txt", ios::out);
	if (!outfile)
	{
		cout << "open error" << endl;
		exit(0);
	}
	for (int i = 0; i < text.size(); i++)
		outfile << text[i] << endl;
	outfile.close();
	exit(0);
}
void Quit(vector<string>& text)
{
	initial(text);
	exit(0);
}
int main()
{	
	vector<string>text;
	initial(text);							//�������ļ��ж�ȡ����
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
	string command;							//�༭�����
	cout << "������༭���" << endl;
	while (cin >> command)					//��ȡ�༭����
	{
		if (command == "*L")
			ShowText(text);
		if (command == "*I")
			Insert(text);
		if (command == "*D")
			Delete(text);
		if (command == "*R")
			Replace(text);
		if (command == "*X")
			SaveQuit(text);
		if (command == "*Q")
			Quit(text);
	}
	return 0;
}