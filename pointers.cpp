// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <cfenv>
#include <iomanip>

using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    student.f_name = new char[128];
    student.l_name = new char[128];
    student.grades = new double[134217728];
    double sum = 0;
    string temp;

    
    //Infinite loop break only when the user enter a valid input
    while (1)
    {
        cout << "Please enter the student's id number: ";
        cin >> temp;
        student.id = promptInt(temp, 0, 999999999);
        if(student.id > 0){
            break;
        }
    }
    


    cout << "Please enter the student's first name: ";
    cin >> student.f_name;
    cout << "Please enter the student's last name: ";
    cin >> student.l_name;

    //Infinite loop break only when the user enter a valid input
    while (1)
    {
        cout << "Please enter how many assignments were graded: ";
        cin >> temp;
        student.n_assignments = promptInt(temp, 0, 134217728);
        if(student.n_assignments > 0){
            break;
        }
    }

    




    cout << endl;

    for(int i=0; i<student.n_assignments; i++){
        
        

        while (1)
        {
            cout << "Please enter grade for assignment " << i << ": ";
            cin >> temp;
            student.grades[i] = promptDouble(temp, 0, 134217728);
            if(student.grades[i] > 0){
                break;
            }
        }


        sum += student.grades[i];
        

    }

    calculateStudentAverage(&student.n_assignments, &sum);
    cout << endl;

    cout << "Student: "<< student.f_name << " " << student.l_name << " [" << student.id << "]" << endl;

    string temp_string = to_string(sum);
    int length_counter =0;
    
    for(int j=0; j < temp_string.length(); j++){
        if(temp_string[j] == '.'){
            break;
        }else{
            length_counter = length_counter + 1;
        }
    }
    

    cout << "  Average grade: " << setprecision(length_counter + 1) << sum  << endl;



    return 0;
}

/*
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(string message, int min, int max)
{
    int return_value;

    for(int i=0; i<message.length(); i++){
        if(!isdigit(message[i])){
            cout << "Sorry, I cannot understand your answer" << endl;
            return -1;
        }
    }

             
    return_value = stoi(message);
    //check if the input is bigger than the min value and less than the max value 
    if(return_value < min || return_value > max){
        cout << "Sorry, I cannot understand your answer" << endl;
        return -1;
    }
    return return_value;
    
}

/*
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(string message, double min, double max)
{
    int dot_count = 0;
    double return_value;

    for(int i =0; i < message.length(); i++){
        if(message[i] == '.'){
            if(dot_count == 0){
                dot_count = 1;
            }else{
                cout << "Sorry, I cannot understand your answer" << endl;
                return -1;
            }
            
            
        }else if(isdigit(message[i]) == false){
            cout << "Sorry, I cannot understand your answer" << endl;
            return -1;
        }else{
            
        }
    }

    return_value = stod(message);
    //check if the input is bigger than the min value and less than the max value 
    if(return_value < min || return_value > max){
        cout << "Sorry, I cannot understand your answer" << endl;
        return -1;
    }
    return return_value;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    int *a;
    a = (int*)object;
    *avg = *avg / *a;
}
