#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int employeeId;
    string employeeName;
    float employeeSalary;
    Employee *next;
};

Employee *head = NULL;


void insert()
{
    Employee *newNode = new Employee;

    cout << "Enter Employee Id: ";
    cin >> newNode->employeeId;

    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, newNode->employeeName);

    cout << "Enter Employee Salary: ";
    cin >> newNode->employeeSalary;

    newNode->next = head;
    head = newNode;

    cout << "\nEmployee Record Inserted Successfully.\n";
}


void deleteNode(int id)
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;
    Employee *prev = NULL;

    if (head->employeeId == id)
    {
        head = head->next;
        delete temp;
        cout << "Employee Record Deleted Successfully.\n";
        return;
    }


    while (temp != NULL && temp->employeeId != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee Record Not Found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Employee Record Deleted Successfully.\n";
}
void search(int id)
{
    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->employeeId == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID     : " << temp->employeeId << endl;
            cout << "Employee Name   : " << temp->employeeName << endl;
            cout << "Employee Salary : " << temp->employeeSalary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Employee Record Not Found.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;

    cout << "\n========== Employee Records ==========\n";

    while (temp != NULL)
    {
        cout << "Employee ID     : " << temp->employeeId << endl;
        cout << "Employee Name   : " << temp->employeeName << endl;
        cout << "Employee Salary : " << temp->employeeSalary << endl;
        cout << "--------------------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n======= Employee Record Management =======\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            cout << "Enter Employee ID to Delete: ";
            cin >> id;
            deleteNode(id);
            break;

        case 3:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            search(id);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
