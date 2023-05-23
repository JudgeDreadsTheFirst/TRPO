#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>

class Lesson{
    const std::string subject;
    std::pair<int, int> time;
public:
    Lesson(std::string nm,std::pair<int,int> tm) : subject(nm), time(tm){
        std::cout << "lesson announced " << subject << std::endl;
    }    

    ~Lesson(){
        std::cout << "lesson canceled " << subject << std::endl;
    }
    void info();
};

void Lesson::info(){
    std::cout << "Class:" << subject << " assigned at " << time.first << ":" << time.second << std::endl;
}

class Student{
    std::string name;
    std::weak_ptr<Student> teacher;
    std::vector<std::unique_ptr<Lesson>> lessons; 

public:
    Student(std::string nm) : name(nm){
        std::cout << "Student arrived " << name << std::endl; 
    }    
    ~Student(){
        std::cout << "Student gone home " << name << std::endl;
    }

    std::string getName();

    void assign_lesson(std::unique_ptr<Lesson> &Lesson);
    void assign_teacher(std::shared_ptr<Student> &teach);


};
std::string Student::getName(){
    return this->name;
}
void Student::assign_teacher(std::shared_ptr<Student> &teach){
    std::cout << teach->getName() << " now teaching " << this->name << std::endl;
}

void Student::assign_lesson(std::unique_ptr<Lesson> &Less){
    std::cout << "Student " << this->name << "now attends " ;
    Less->info();
    lessons.push_back(std::move(Less));
}

int main(){

    auto time1 = std::make_pair(19,20);
    auto time2 = std::make_pair(9,30);

    std::shared_ptr<Student> st1 = std::make_shared<Student>("Stepan");
    std::shared_ptr<Student> st2 = std::make_shared<Student>("Valera");
    std::shared_ptr<Student> thr = std::make_shared<Student>("Julia");

    st1->assign_teacher(thr);
    st2->assign_teacher(thr);

    std::shared_ptr<Student> thr1 = std::make_shared<Student>("Alex");
    std::shared_ptr<Student> thr2 = std::make_shared<Student>("Anna");

    thr1->assign_teacher(thr2);
    thr2->assign_teacher(thr1);

    std::unique_ptr<Lesson> less1 = std::make_unique<Lesson>("Maths", time2);
    std::unique_ptr<Lesson> less2 = std::make_unique<Lesson>("TRPO", time1);
    std::unique_ptr<Lesson> less3 = std::make_unique<Lesson>("Biology", time1);
    std::unique_ptr<Lesson> less4 = std::make_unique<Lesson>("electrodynamics", time2);

    st1->assign_lesson(less1);
    st2->assign_lesson(less3);
    st2->assign_lesson(less2);
    st1->assign_lesson(less4);

    return 0;
}