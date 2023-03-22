// Problem Description  假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。

// Input  输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。

// Output  对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
// 每个测试实例后面跟一个空行。

// Sample Input
// 2 2
// 5 10
// 10 20

// Sample Output
// 7.50 15.00
// 7.50 15.00
// 1

#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    double score[5];
    double average;
};
double scoreMap[5];
int main()
{
    int stuNum, classNum;
    vector<Student> students;
    cin >> stuNum >> classNum;
    for (int i = 0; i < stuNum; i++)
    {
        Student stu;
        double stuSum = 0;
        for (int j = 0; j < classNum; j++)
        {
            double score;
            cin >> score;
            scoreMap[j] += score;
            stuSum += score;
            stu.score[j] = score;
        }
        stu.average = stuSum / classNum;
        students.push_back(stu);
    }

    for (auto i : students)
        printf("%.2lf ", i.average);
    puts("");
    for (int i = 0; i < classNum; i++)
    {
        scoreMap[i] = scoreMap[i] / stuNum;
        printf("%.2lf ", scoreMap[i]);
    }
    puts("");
    int cnt = 0;
    for (auto stu : students)
    {
        bool allOver = true;
        for (int i = 0; i < classNum; i++)
        {
            if (stu.score[i] < scoreMap[i])
                allOver = false;
        }
        if (allOver)
            cnt++;
    }
    cout << cnt;
    return 0;
}
