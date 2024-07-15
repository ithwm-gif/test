#include <string>
#include <iostream>
using namespace std;

// 图书类
class Book
{
public:
    string title;  // 书名
    string author; // 作者

    // 构造函数
    Book(string t, string a) : title(t), author(a) {}

    // 显示图书信息
    void display()
    {
        cout << "书名: " << title << ", 作者: " << author << endl;
    }
};

// 动物基类
class Animal
{
protected:
    string name; // 动物名称

public:
    // 构造函数
    Animal(string n) : name(n) {}

    // 虚拟析构函数
    virtual ~Animal() {}

    // 显示动物名称
    void display()
    {
        cout << "动物名称: " << name << endl;
    }

    // 虚拟函数，供派生类重写
    virtual void speak()
    {
        cout << "发出声音..." << endl;
    }
};

// 狗类，继承自Animal
class Dog : public Animal
{
public:
    // 构造函数
    Dog(string n) : Animal(n) {}

    // 重写speak函数
    void speak() override
    {
        cout << name << " 说：汪汪！" << endl;
    }
};

// 猫类，继承自Animal
class Cat : public Animal
{
public:
    // 构造函数
    Cat(string n) : Animal(n) {}

    // 重写speak函数
    void speak() override
    {
        cout << name << " 说：喵喵！" << endl;
    }
};

int main()
{
    Book myBook("C++ Primer", "Stanley B. Lippman");
    myBook.display();

    Dog myDog("旺财");
    Cat myCat("小花");

    myDog.display();
    myDog.speak();

    myCat.display();
    myCat.speak();

    return 0;
}