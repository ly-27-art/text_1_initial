#include <iostream>
#include <string>
using namespace std;

struct student{
    string name;
    int age;
    int score;
};

void printstudent(const student *s){
    //s->score = 150    错误，不可进行改写
    cout << "name: " << s->name << " age: " << s->age << " score: " << s->score << endl;
}

int main()
{
    student s = {"zhangsan",15,100};
    printstudent(&s);
    return 0;
}