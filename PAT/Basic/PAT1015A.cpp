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
void OutPut(Student student);
bool Sort(Student student1, Student student2)
{
    if (student1.morality + student1.ability != student2.morality + student2.ability)
        return student1.morality + student1.ability > student2.morality + student2.ability;
    else
    {
        if (student1.morality != student2.morality)
            return student1.morality > student2.morality;
        else
            return student1.no < student2.no;
    }
}
int main()
{
    int N;
    vector<Student> candidate;
    vector<Student>::iterator first, second, third;
    vector<Student>::iterator last;
    //cin>>N>>L>>H;
    scanf("%d%d%d",&N,&L,&H);
    while(N--)
    {
        Student temp;
        //cin>>temp.no>>temp.morality>>temp.ability;
        scanf("%d%d%d",&temp.no,&temp.morality,&temp.ability);
        candidate.push_back(temp);
    }
    last = partition(candidate.begin(),candidate.end(),IsHighThanBottomLine);
    candidate.erase(last, candidate.end());
    first = stable_partition(candidate.begin(), candidate.end(), IsFirstClass);
    stable_sort(candidate.begin(), first, Sort);
    second = stable_partition(first, candidate.end(), IsSecondClass);
    stable_sort(first, second, Sort);
    third = stable_partition(second, candidate.end(), IsThirdClass);
    stable_sort(second, third, Sort);
    stable_sort(third, candidate.end(), Sort);
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
void OutPut(Student student)
{
    //cout<<student.no<<" "<<student.morality<<" "<<student.ability<<endl;
    printf("%d %d %d\n",student.no, student.morality, student.ability);
}
