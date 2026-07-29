#include <iostream>
using namespace std;

struct Student
{
    char studentName[50];
    int studentId;
    char studentAddress[100];
    char studentContactNumber[15];

public:
    void setCollegeDetails()
    {
        cout << "Enter your name: ";
        cin >> studentName;

        cout << "Enter your ID: ";
        cin >> studentId;

        cout << "Enter your address: ";
        cin >> studentAddress;

        cout << "Enter your contact number:";
        cin >> studentContactNumber;
    }

    void showCollegeDetails()
    {
        cout << "\n======= STUDENT DETAILS =======" << endl;
        cout << "Name: " << studentName << endl;
        cout << "ID: " << studentId << endl;
        cout << "Address: " << studentAddress << endl;
        cout << "Contact Number: " << studentContactNumber << endl;
    }
};

int main()
{
    Student s[100];
    Student *ptr;
    ptr=s;
     
     int n;
     cout<<"Enter number of student details:\n";
     cin>>n;
     for(int i=0;i<n;i++)
     {
     	(ptr+1)->setCollegeDetails();
	 }
	 for(int i=0;i<n;i++)
	 {
	 	(ptr+1)->showCollegeDetails();
	 }
}
    