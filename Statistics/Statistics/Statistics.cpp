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
	string m_keyword[max];		//关键字（保留字）
	string m_filename;			//文档名称
	long m_key;					//文档中单词数
	long m_keycount;			//保留字计数
	long m_nokeycount;			//非保留字计数
	int m_keynum;				//需要匹配的保留字个数
	int m_time;					//扫描文件次数
};

void KeyWord::Display() {
	for (int i = 0; i < m_keynum; i++) {
		cout << m_keyword[i] << endl;
	}
}
void KeyWord::Search() {
	fstream file;		//handle
	file.open(/*"C:\\Users\\lenovo\\Desktop\\" +*/ m_filename + ".txt");		//打开文件
	ofstream record1("C:\\Users\\lenovo\\Desktop\\keyfile.txt");			//文件写入,keyfile用来记录保留字计数、文档扫描次数和非保留字计数

	char str[2000];															//将文档内容存入数组str中
	int flag = 0;															//用于确定单词的起始位置

	for (int w = 0; w < m_keynum; w++) {
		while (file.getline(str, 2000))
		{
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') {
					m_key++;									//记录单词数
					char* word = new char[i + 1 - flag];		//为word数组分配空间
					for (int j = flag; j < i; j++) {
						word[j - flag] = str[j];				//将单词存入word数组
					}
					word[i - flag] = '\0';						//字符串的结尾符，以便转换为字符串格式	
					string st = string(word);

					if (st == m_keyword[w]) {
						m_keycount++;							//若相同，则保留字计数++
						flag = i + 1;
					}
					else {
						flag = i + 1;
					}
					delete[]word;								//释放word数组的内存
				}
			}
			m_time++;
			flag = 0;
		}
		file.clear();											//清除文件流属性状态
		file.seekg(0, ios::beg);								//回到文档首部
	}
	m_key = m_key / m_time;										//由于共扫描了m_time次，所以总数应该除以次数得出单词总数
	m_nokeycount = m_key - m_keycount;							//计算非保留字计数

	cout << "一共有" << m_key << "个单词" << endl;
	cout << "其中有" << m_keycount << "个单词匹配" << ",有" << m_nokeycount << "个单词不匹配。" << "一共扫描" << m_time << "次文件";
	record1 << "关键字出现次数：" << m_keycount << " 非关键字出现次数：" << m_nokeycount << " 一共扫描" << m_time << "次文件" << endl;

}
//将数据录入类中
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
	cout << "这是一个统计文件中关键字的程序" << endl;
	cout << "输入要匹配的文件名：";
	cin >> file1;
	cout << "输入要查找的关键字个数(最大为10)：";
	cin >> count;

	string* getkey = new string[count];				//指针数组实现每一个“元素”为一个字符串，实际上相当于二维数组
	for (int i = 0; i < count; i++) {
		cout << "输入第" << i + 1 << "个关键字" << endl;
		cin >> getkey[i];
	}
	ofstream record2("C:\\Users\\lenovo\\Desktop\\keyword.txt"/*, ios::in*/);	//keyword表单用来记录保留字
	for (int i = 0; i < count; i++) {
		record2 << getkey[i] << "  ";
	}
	KeyWord KeySearch;
	KeySearch.SetData(getkey, file1, 0, 0, 0, count, time1);
	KeySearch.Search();
	return 0;
}
