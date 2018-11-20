#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace std;


class Shell
{
private:
	string now_dir;
	string home;
public:
	Shell(string homedir = "/") :now_dir(homedir)
	{
		if (now_dir[now_dir.length() - 1] != '/') now_dir.push_back('/');
		while (now_dir.find("//", 0) != string::npos)
		{
			int kill_place = now_dir.find("//", 0);//�ҵ�����ַ���λ��
			now_dir = now_dir.erase(kill_place, 1);//����ɾ��
		}
		if (now_dir[0] != '/' && now_dir[0] != '~')
			now_dir = "/" + now_dir;
		home = now_dir;
	}
	~Shell() {}
	void cd(string path = "");
	void pwd();
	void distance(string path);
};

void Shell::pwd()
{
	cout << now_dir << endl;
	return;
}

void Shell::distance(string path)
{
	//����·�����������鷳���ˣ��Ҿ����еㆪ�£������
	//������Ҫ�Ƚ���һ�������·��
	//Shell now = 
	Shell where_goto(home);
	where_goto.now_dir = now_dir;
	where_goto.cd(path);//��goto��λ�ý�����Ϊһ��������·��

	
	/*cout << "=======" << endl;
	this->pwd();
	where_goto.pwd();
	cout << "=======" << endl;*/
	
	//int x(0);//��Ϊ��ʼѰ��/��λ��
	//while()//��Ϊ��Ҫ�ҵ���ͬ��·�����̣�ֱ������ͬΪֹ
	int i(0);
	for (; i < now_dir.length() && i < where_goto.now_dir.length(); ++i)
	{
		if (now_dir[i] != where_goto.now_dir[i])
			break;
	}

	int count1(0);
	for (int x(i); x < now_dir.length(); ++x)
	{
		if (now_dir[x] == '/')
			++count1;
	}

	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count1;
	}
	//��ʱ���count��һ��������ִ��
	/*
	//===================================================================================
	i = 0;
	Shell copy(home);
	int count2(1);
	for (; i < copy.now_dir.length() && i < where_goto.now_dir.length(); ++i)
	{
		if (copy.now_dir[i] != where_goto.now_dir[i])
			break;
	}

	for (int x(i); x < copy.now_dir.length(); ++x)
	{
		if (copy.now_dir[x] == '/')
			++count2;
	}

	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count2;
	}
	//===================================================================================
	i = 0;
	int count3(0);
	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count3;
	}

	if (count2 < count1)
		count1 = count2;
	if (count3 < count1)
		count1 = count3;
	*/
	cout << count1 << endl;

	return;
}

void Shell::cd(string path)
{
	string x;

	while (now_dir.find("//", 0) != string::npos)
	{
		int kill_place = now_dir.find("//", 0);//�ҵ�����ַ���λ��
		now_dir = now_dir.erase(kill_place, 1);//����ɾ��
	}

	if (path.length() == 0)
	{
		now_dir = home;
		return;
	}
	/*
	for (int i(0); i < path.length(); ++i)
	{
		//x.push_back(path[i]);
		//if (i == path.length() - 1)//��ʱ�Ѿ������һ��λ����

	}
	*/

	else if (path[0] == '/')//��ʱ�Ӹ�Ŀ¼��ʼ��չ
	{
		///*
		if (path.length()>1)
		{
			if (path[1] == '~')
				now_dir = home + path.erase(0, 3);
			else
				now_dir = path;
		}
		else
		//*/
			now_dir = path;
	}
	else if (path[0] == '~')//��ʱ��homeĿ¼��ʼ��չ
	{
		now_dir = home + path.erase(0, 2);//ɾ�����㿪ʼ��һ���ַ���Ҳ����ɾ��ͷ�ַ�
	}
	else
	{
		now_dir += path;
	}
	now_dir += "/";
	while (now_dir.find("//", 0) != string::npos)
	{
		int kill_place = now_dir.find("//", 0);//�ҵ�����ַ���λ��
		now_dir = now_dir.erase(kill_place, 1);//����ɾ��
	}	
	//Ȼ����Ҫ����������䣿������Ҫ�Ķ���ȥ��
	//����ȥ��./��������������һ�����
	while (now_dir.find("/./", 0) != string::npos)
	{
		int kill_place = now_dir.find("/./", 0);//�ҵ�����ַ���λ��
		now_dir = now_dir.erase(kill_place, 2);//����ɾ��
	}

	//Ȼ������Ҫ����../����ַ���
	while (now_dir.find("/../", 0) != string::npos)
	{
		//cout <<"->"<< now_dir << endl;
		int x = now_dir.find("/../", 0);
		/*if (x == 0)
		{
			now_dir = now_dir.erase(0, 3);
			break;
		}*/
		now_dir = now_dir.erase(x, 3);//�����λ��ɾ��
		//���ǻ���Ҫɾ�����λ��֮ǰ��һ��Ŀ¼λ�ã���Ϊ���ϼ�Ŀ¼�ĺ���
		if (x != 0)
		{
			int y = now_dir.rfind('/', x - 1);//��Ϊx��λ����Ȼ��һ��/������Ҫ��ǰѰ��
			//cout << y <<" "<<x - y<< endl;
			now_dir = now_dir.erase(y, x - y);//������Ѿ���Խ����Ŀ¼ɾ��
		}
	}
	while (now_dir.length() > 1 && now_dir[now_dir.length() - 1] == '/' && now_dir[now_dir.length() - 2] == '/')
		now_dir.pop_back();

	//if (now_dir.length() == 0)
		//now_dir = "/";

	return;
}

