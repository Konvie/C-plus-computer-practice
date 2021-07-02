#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#define max 10

using namespace std;
class KeyWord
{
public:
	KeyWord();
	void SetData(string* keyword, string filename, long key, long kcon, long nkcon, int keyn, int time);
	void Search();
	void Display();
	~KeyWord();

private:
	string m_keyword[max];		//�ؼ��֣������֣�
	string m_filename;			//�ĵ�����
	long m_key;					//�ĵ��е�����
	long m_keycount;			//�����ּ���
	long m_nokeycount;			//�Ǳ����ּ���
	int m_keynum;				//��Ҫƥ��ı����ָ���
	int m_time;					//ɨ���ļ�����
};

void KeyWord::Display() {
	for (int i = 0; i < m_keynum; i++) {
		cout << m_keyword[i] << endl;
	}
}
void KeyWord::Search() {
	fstream file;		//handle
	file.open(/*"C:\\Users\\lenovo\\Desktop\\" +*/ m_filename + ".txt");		//���ļ�
	ofstream record1("C:\\Users\\lenovo\\Desktop\\keyfile.txt");			//�ļ�д��,keyfile������¼�����ּ������ĵ�ɨ������ͷǱ����ּ���

	char str[2000];															//���ĵ����ݴ�������str��
	int flag = 0;															//����ȷ�����ʵ���ʼλ��

	for (int w = 0; w < m_keynum; w++) {
		while (file.getline(str, 2000))
		{
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') {
					m_key++;									//��¼������
					char* word = new char[i + 1 - flag];		//Ϊword�������ռ�
					for (int j = flag; j < i; j++) {
						word[j - flag] = str[j];				//�����ʴ���word����
					}
					word[i - flag] = '\0';						//�ַ����Ľ�β�����Ա�ת��Ϊ�ַ�����ʽ	
					string st = string(word);

					if (st == m_keyword[w]) {
						m_keycount++;							//����ͬ�������ּ���++
						flag = i + 1;
					}
					else {
						flag = i + 1;
					}
					delete[]word;								//�ͷ�word������ڴ�
				}
			}
			m_time++;
			flag = 0;
		}
		file.clear();											//����ļ�������״̬
		file.seekg(0, ios::beg);								//�ص��ĵ��ײ�
	}
	m_key = m_key / m_time;										//���ڹ�ɨ����m_time�Σ���������Ӧ�ó��Դ����ó���������
	m_nokeycount = m_key - m_keycount;							//����Ǳ����ּ���

	cout << "һ����" << m_key << "������" << endl;
	cout << "������" << m_keycount << "������ƥ��" << ",��" << m_nokeycount << "�����ʲ�ƥ�䡣" << "һ��ɨ��" << m_time << "���ļ�";
	record1 << "�ؼ��ֳ��ִ�����" << m_keycount << " �ǹؼ��ֳ��ִ�����" << m_nokeycount << " һ��ɨ��" << m_time << "���ļ�" << endl;

}
//������¼������
void KeyWord::SetData(string* keyword, string filename, long key, long kcon, long nkon, int keyn, int time) {
	for (int i = 0; i < keyn; i++) {
		m_keyword[i] = keyword[i];
	}
	m_filename = filename;
	m_key = key;
	m_keycount = kcon;
	m_nokeycount = nkon;
	m_keynum = keyn;
	m_time = time;
}
KeyWord::KeyWord()
{
	m_keyword[0] = "xxx";
	m_filename = "xxx";
	m_keycount = 0;
	m_nokeycount = 0;
	m_time = 0;
}

KeyWord::~KeyWord()
{
}
int main() {
	string file1;

	int count;
	int time1 = 0;
	cout << "����һ��ͳ���ļ��йؼ��ֵĳ���" << endl;
	cout << "����Ҫƥ����ļ�����";
	cin >> file1;
	cout << "����Ҫ���ҵĹؼ��ָ���(���Ϊ10)��";
	cin >> count;

	string* getkey = new string[count];				//ָ������ʵ��ÿһ����Ԫ�ء�Ϊһ���ַ�����ʵ�����൱�ڶ�ά����
	for (int i = 0; i < count; i++) {
		cout << "�����" << i + 1 << "���ؼ���" << endl;
		cin >> getkey[i];
	}
	ofstream record2("C:\\Users\\lenovo\\Desktop\\keyword.txt"/*, ios::in*/);	//keyword��������¼������
	for (int i = 0; i < count; i++) {
		record2 << getkey[i] << "  ";
	}
	KeyWord KeySearch;
	KeySearch.SetData(getkey, file1, 0, 0, 0, count, time1);
	KeySearch.Search();
	return 0;
}
