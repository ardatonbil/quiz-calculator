#include <iostream>
using namespace std;

double quizzes() {
    double q1, q2, q3, q4, lowest, q_avg;
    cout << "What are the grades of your 4 quizzes? If any, enter your grade as 0 for missed quizzes. ";
    cin >> q1 >> q2 >> q3 >> q4;
    lowest = q1;
    if (q2 < q1) {
        lowest = q2;
    }
    else if (q3 < q1) {
        lowest = q3;
    }
    else if (q4 < q1) {
        lowest = q4;
    }
    q_avg = (q1 + q2 + q3 + q4 - lowest) / 30 * 100;
    return q_avg;
}

int main()
{
    string isim;
    cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
    cin >> isim;
    double midterm, final, exam_avg;
    cout << "Hello " << isim << ", what are your midterm and final exam grades? ";
    cin >> midterm >> final;
    exam_avg = (0.3 * midterm + 0.35 * final)/0.65;
    if (exam_avg < 30){
        cout << isim << ", your weighted exam average is less than 30, you will fail the course!" << endl;
        return 0;
    }
    else {
        double hw1, hw2, hw3, hw4, hw5, hw_avg, quiz , course_numeric_grade, ratio;
        cout << "What are the grades of your 5 homework? ";
        cin >> hw1 >> hw2 >> hw3 >> hw4 >> hw5;
        hw_avg = (hw1 + hw2 + hw3 + hw4 + hw5) / 5;
        ratio = hw_avg / exam_avg;
        if (ratio >= 3) {
            cout << "You'll get NONE of the points earned from homework!" << endl;
            quiz = quizzes();
            course_numeric_grade = quiz * 0.1 + exam_avg * 0.65;
            cout << isim << ", your grade for CS201 is: " << course_numeric_grade << endl;
            return 0;
        }
        else if (2 < ratio && ratio <3) {
            double last;
            last = hw_avg * (3-ratio);
            cout << "You'll get " << last << " from the points earned from homework!" << endl;
            quiz = quizzes();
            course_numeric_grade = quiz * 0.1 + last * 0.25 + exam_avg * 0.65;
            cout << isim << ", your grade for CS201 is: " << course_numeric_grade << endl;
            return 0;
        }
        else if (ratio <= 2) {
            cout << "You'll get all the points earned from homework!" << endl;
            quiz = quizzes();
            course_numeric_grade = quiz * 0.1 + hw_avg * 0.25 + exam_avg*0.65;
            cout << isim << ", your grade for CS201 is: " << course_numeric_grade << endl;
            return 0;
        }
    }
}


