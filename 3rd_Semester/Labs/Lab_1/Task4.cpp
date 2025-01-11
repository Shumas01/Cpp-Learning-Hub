#include<iostream>
#include<string>
using namespace std;
class Student
{
    private:
        string Name;
        string id;
        float gpa;
        string degree;
        double percentage;
        string grade;
        double totalMarks;
        double obtainedMarks;
    public:
        void setValue();
        void assignGrade();
        void line();
        void displayInfo();
};
void Student::setValue()
{
    cout<<"Enter your Name: ";
    cin.ignore();
    getline(cin,Name);
    cout<<"Enter your student ID: ";
    cin>>id;
    cout<<"Enter your CGPA: ";
    cin>>gpa;
    cout<<"Enter your degree Name: ";
    cin.ignore();
    getline(cin,degree);
    cout<<"Enter your total Marks: ";
    cin>>totalMarks;
    cout<<"Enter your obtained Marks: ";
    cin>>obtainedMarks;
    if (totalMarks>0)
        {
            percentage=(obtainedMarks*1.0/totalMarks)*100;
        }
    else 
        {
            percentage=0.0;
        }
}
void Student::assignGrade()
{
    if(percentage>=86)
    {
        grade="A+";
    }
    else if(percentage>=82){
        grade="A";
    }
    else if(percentage>78){
        grade="B+";
    }
    else if(percentage>=74){
        grade="B";
    }
    else if(percentage>=70){
        grade="B-";
    }
    else if(percentage>=66){
        grade="C+";
    }
    else if(percentage>=60)
    {
        grade="C";
    }
    else if(percentage>=55){
        grade="D+";
    }
    else if(percentage>=49){
        grade="D";
    }
    else if(percentage>=42){
        grade="D-";
    }
    else if(percentage>=36){
        grade="F";
    }
        else{
            grade="F";
            cout<<endl;
            cout<<"Better Luck Next Time!";
    }
}
    void Student::displayInfo()
    {
        cout << "-----------------------------------------------" << endl;
        cout<<"Students Name: "<<Name<<endl;
        cout<<"Student ID: "<<id<<endl;
        cout<<"Student CGPA: "<<gpa<<endl;
        cout<<"Degree: "<<degree<<endl;
        cout<<"Total Marks: "<<totalMarks<<endl;
        cout<<"Obtained Marks: "<<obtainedMarks<<endl;
        cout<<"Obtained Percentage: "<<percentage<<endl;
        cout<<"Grade: "<<grade<<endl; 
        cout << "-----------------------------------------------" << endl;

    }
int main ()
{
    int no;
    cout<<"How many students data u want to enter: ";
    cin>>no;
    Student *students=new Student[no];
    for(int i=0;i<no;++i)
    {
        cout<<"-----------------------------------------------"<<endl;
        cout<<"/////Entering Data of Student "<<i+1<<" : "<<endl;
        students[i].setValue();
        students[i].assignGrade();
        cout<<endl;
    }
        cout << "-----------------------------------------------" << endl;
        cout << "Displaying Students' Information: " << endl;
        cout<<endl;
        for(int i=0;i<no;++i){
            cout<<"Student"<<i+1<<": "<<endl;
        }
    for(int i=0;i<no;++i)
    {
        students[i].displayInfo();
    }
    delete[]students;
}