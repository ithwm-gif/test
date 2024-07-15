#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

const string fileName = "students.txt";
const int maxn = 10;
int currentN;

class Student
{
public:
    void Inputid();
    void Inputname();
    void Inputscore();
    int getId();
    static void heading()
    {
        cout << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "成绩" << '\n';
    }
    void output();
    // 自定义排序函数
    bool operator<(Student &o) const
    {
        if (score == o.score)
            return id < o.id;   // 成绩一样按学号从小到大排
        return score > o.score; // 成绩不一样按成绩由大到小排
    }
    int id;       // 学号
    string name;  // 姓名
    double score; // 成绩
};

// 输入学生学号
void Student::Inputid()
{
    cout << "请输入学号（1到40之间）：";
    cin >> id;
    while (id < 1 || id > 40)
    {
        cout << "输入学号有误，请重新输入学号（1到40之间）：" << '\n';
        cin >> id;
    }
}

// 输入学生姓名
void Student::Inputname()
{
    cout << "请输入学生姓名：";
    cin >> name;
}

// 输入学生成绩
void Student::Inputscore()
{
    cout << "请输入学生成绩：";
    cin >> score;
    while (score < 0 || score > 100)
    {
        cout << "输入错误，成绩应该在0到100之间!" << '\n';
        cout << "请输入学生成绩：";
        cin >> score;
    }
}

// 获取学生学号
int Student::getId() { return id; }

// 输出学生信息
void Student::output()
{
    cout << setw(10) << id << setw(10) << name << setw(10) << score << '\n';
}

// 输入学生信息
void Input(Student stu[], int &num)
{
    int i = 0;
    string str;
    if (num == 0)
    {
        while (1)
        {
            stu[i].Inputid();
            stu[i].Inputname();
            stu[i].Inputscore();
            i++;
            num = i;
            cout << "继续输入学生信息的按y或者Y，否则输出除y或者Y的任意数：";
            cin >> str;
            if (i == maxn)
            {
                cout << "人数已到达" << maxn << "人上限，无法在输入！" << '\n';
                return;
            }
            if (str[0] == 'y' || str[0] == 'Y')
                continue;
            else
                break;
        }
    }
    else
    { // 判断是否超限
        if (num == maxn)
        {
            cout << "人数已到达" << maxn << "人上限，无法在输入！" << '\n';
            return;
        }
        else
        {
            i = num;
            while (1)
            {
                stu[i].Inputid();
                stu[i].Inputname();
                stu[i].Inputscore();
                i++;
                num = i;
                cout << "进行输入学生信息的按y或者Y，否则输出除y或者Y的任意数：";
                cin >> str;
                if (i == maxn)
                {
                    cout << "人数已到达" << maxn << "人上限，无法在输入！" << '\n';
                    break;
                }
                if (str[0] == 'y' || str[0] == 'Y')
                    continue;
                else
                    break;
            }
        }
    }
}

// 输出学生信息
void Output(Student stu[], int num)
{
    if (num)
    {
        stu[0].heading();
        for (int i = 0; i < num; i++)
        {
            stu[i].output();
        }
    }
    else
    {
        cout << "暂无成绩信息，请选择1=录入学生信息" << '\n';
    }
}

// 根据学生学号查找学生信息
void Searchid(Student stu[], int num)
{
    int id;
    string str;
    while (1)
    {
        cout << "请输入你要查找的学号：";
        cin >> id;
        bool flag = 0;
        int pos = 0;
        for (int i = 0; i < num; i++)
        {
            if (stu[i].getId() == id)
            {
                flag = 1;
                pos = i;
                break;
            }
        }
        if (!flag)
            cout << "没有找到该学号学生信息！" << '\n';
        else
        {
            stu[0].heading();
            stu[pos].output();
        }
        cout << "继续查找请按y或Y：";
        cin >> str;
        if (str[0] == 'y' || str[0] == 'Y')
            continue;
        else
            break;
    }
}

// 根据学生姓名找
void Searchname(Student stu[], int num)
{
    string name;
    string str;
    while (1)
    {
        cout << "请输入你要查找的名字：";
        cin >> name;
        bool flag = 0;
        int pos = 0;
        for (int i = 0; i < num; i++)
        {
            if (stu[i].name == name)
            {
                flag = 1;
                pos = i;
                break;
            }
        }
        if (!flag)
            cout << "没有找到该姓名学生信息！" << '\n';
        else
        {
            stu[0].heading();
            stu[pos].output();
        }
        cout << "继续查找请按y或Y：";
        cin >> str;
        if (str[0] == 'y' || str[0] == 'Y')
            continue;
        else
            break;
    }
}

// 利用stl中的sort函数排序
void Sort(Student stu[], int num)
{
    sort(stu, stu + num);
}

// 清空txt文件
void fileEmpty(const string fileName)
{
    fstream file(fileName, ios::out);
}

// stu[]->txt文件
void inputtxt(Student stu[])
{
    fileEmpty(fileName);  // 先清空txt
    fstream in(fileName); // 打开txt
    int c = 0;
    for (int i = 0; i < currentN; i++)
    {
        in << stu[i].id << setw(10) << stu[i].name << setw(10) << stu[i].score;
        in << '\n';
    }
    in.close();
}

// 从文件中读取信息
void txttoclass(Student stu[])
{
    ifstream in;
    in.open(fileName);
    string sline; // 每一行
    Student tp;
    while (getline(in, sline)) // 逐行读取txt文件
    {
        istringstream sin(sline);
        sin >> tp.id >> tp.name >> tp.score;
        stu[currentN++] = tp;
    }
}

// 主菜单
void Menu()
{
    cout << "            ☆   学 生 成 绩 管 理 系  统   ☆       \n";
    cout << " =================================================\n";
    cout << " =               当前位置：主菜单                =\n";
    cout << " =                请输入您的选择                 =\n";
    cout << " =                1.录入学生成绩                 =\n";
    cout << " =                2.查找学生成绩                 =\n";
    cout << " =                3.排序输出成绩                 =\n";
    cout << " =                4.退出                         =\n";
    cout << " =================================================\n";
    cout << " 请输入你的选择（1-4）：";
}

int main()
{
    // fileEmpty(fileName);  //清空txt文件
    Student stu[maxn];
    txttoclass(stu); // 读取txt文件
    while (1)
    {
        Menu();
        int op;
        cin >> op;
        if (op == 1)
        {

            Input(stu, currentN);
            inputtxt(stu);
            system("cls");
        }
        else if (op == 2)
        {

            cout << "请选择：1.学号  2.姓名" << '\n';
            int op;
            cin >> op;
            if (op == 1)
                Searchid(stu, currentN);
            else if (op == 2)
                Searchname(stu, currentN);
            system("cls");
        }
        else if (op == 3)
        {
            Sort(stu, currentN);
            Output(stu, currentN);
            inputtxt(stu);
            system("pause");
            system("cls");
        }
        else if (op == 4)
        {
            system("cls");
            cout << "退出成功！" << '\n';
            break;
        }
        else
        {
            //	system("cls");
            cout << "输入非法，请重新输入！" << '\n';
            system("cls");
        }
    }
}
