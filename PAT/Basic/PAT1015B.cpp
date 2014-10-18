#include<iostream>
#include<vector>
#include<algorithm>
/*
 *另外输出只能用printf 。。。cout会超时
 */
using namespace std;
int L;
int H;
typedef struct Student
{
    int no;
    int morality;
    int ability;
}Student;
typedef bool (*p) (Student student1, Student student2);
bool IsHighThanBottomLine(Student student);
bool IsFirstClass(Student student);
bool IsSecondClass(Student student);
bool IsThirdClass(Student student);
bool SortedByN0(Student student1, Student student2);
bool SortedByTotalScore(Student student1, Student student2);
bool SortedByMorality(Student student1, Student student2);
void OutPut(Student student);
int main()
{
    int N;
    vector<Student> candidate;
    vector<Student>::iterator first, second, third;
    vector<Student>::iterator last;
    Student temp;
    scanf("%d%d%d",&N,&L,&H);
    while(N--)
    {
        scanf("%d%d%d",&temp.no,&temp.morality,&temp.ability);
        candidate.push_back(temp);
    }
    last = partition(candidate.begin(),candidate.end(),IsHighThanBottomLine);
    candidate.erase(last, candidate.end());
    sort(candidate.begin(), candidate.end(), SortedByN0);
    stable_sort(candidate.begin(), candidate.end(), SortedByMorality);
    stable_sort(candidate.begin(), candidate.end(), SortedByTotalScore);
    first = stable_partition(candidate.begin(), candidate.end(), IsFirstClass);
    second = stable_partition(first, candidate.end(), IsSecondClass);
    third = stable_partition(second, candidate.end(), IsThirdClass);
    cout<<candidate.end() - candidate.begin()<<endl;
    for_each(candidate.begin(), candidate.end(), OutPut);
    return 0;
}
bool IsHighThanBottomLine(Student student)
{
    return (student.morality >= L) && (student.ability >= L);
}

bool IsFirstClass(Student student)
{
    return (student.morality >= H) && (student.ability >= H);
}
bool IsSecondClass(Student student)
{
    return (student.morality >= H) && (student.ability < H);
}
bool IsThirdClass(Student student)
{
    return (student.morality < H) && (student.ability < H) && (student.morality >= student.ability);
}
bool SortedByN0(Student student1, Student student2)
{
    return student1.no < student2.no;
}
bool SortedByTotalScore(Student student1, Student student2)
{
    return student1.morality + student1.ability > student2.morality + student2.ability;
}
bool SortedByMorality(Student student1, Student student2)
{
    return (student1.morality > student2.morality);
}
void OutPut(Student student)
{
    printf("%d %d %d\n",student.no, student.morality, student.ability);
}
