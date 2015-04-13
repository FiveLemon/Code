#include<WinSock2.h>
#include<iostream>
#include<mysql.h>
#pragma comment(lib,"libmysql.lib")
using namespace std;
void dispaly_header(MYSQL_RES *res_ptr);
int main()
{
    MYSQL mysql;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;    
    bool flag = true;
    mysql_init(&mysql);
    int res;
    int fields;
    char sql[] = {"select * from sql_database"};
    if (mysql_real_connect(&mysql, "localhost", "root", "786160313", "lottery", 3306, 0 ,0))
    {
        cout<<"Sucess"<<endl;
        res = mysql_query(&mysql, sql);
        if (!res)
        {
            res_ptr = mysql_store_result(&mysql);
            if (res_ptr)
            {
                cout<<"Retrieved "<<mysql_num_rows(res_ptr)<<" rows"<<endl;
                fields = mysql_num_fields(res_ptr);
                cout<<"Retrieved "<<fields<<" fields"<<endl;
                while(sqlrow = mysql_fetch_row(res_ptr))
                {
                    if (flag)
                    {
                        flag = false;
                        dispaly_header(res_ptr);
                    }
                    for( int i = 0; i < fields; i++)
                    {
                        cout<<sqlrow[i]<<'\t';
                    }
                    cout<<endl;
                }
            }
            mysql_free_result(res_ptr);
        }
        mysql_close(&mysql);
    }
    else
    {
        cout<<"failed"<<endl;
    }
    return 0;
}
void dispaly_header(MYSQL_RES *res_ptr)
{
     MYSQL_FIELD *field_ptr;
     cout<<"Column detail:"<<endl;
     while(field_ptr = mysql_fetch_field(res_ptr))
     {
         cout<<field_ptr->name<<'\t';
     }
     cout<<endl;
}