#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int prof_id=0;
static int stu_id=0;
class Person {
    public:
    string name;
    int age;
    virtual void getdata(){};
    virtual void putdata(){};
    
};
class Professor: public Person {
    public:
    int publication;
    int cur_id;
    Professor(){
        prof_id++;
    }
    void getdata(){
        cin>>name>>age>>publication;
        cur_id=prof_id;
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<publication<<" "<<cur_id<<endl;
    }
};

class Student:public Person {
    public:
    int marks[6];
    int curd_id;
    
    Student(){
        stu_id++;
    }
    void getdata(){
        cin>>name>>age;
        for(int i=0;i<6;i++){
            cin>>marks[i];
        }
         curd_id=stu_id;
    }
    void putdata(){
        int sum=0;
        for(int i=0;i<6;i++){
            sum=sum+marks[i];
        }
        cout<<name<<" "<<age<<" "<<sum<<" "<<curd_id<<endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
