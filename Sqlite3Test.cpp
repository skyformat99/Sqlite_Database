//============================================================================
// Name        : Sqlite3Test.cpp
// Author      : xieliming
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "database.h"
#include"sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
DataBaseOperation DBOP;
struct Typeset Tyst;
void showTyst(int n);
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	sqlite3* vxcu=NULL;
//	int s=sqlite3_open("./vxcu.db", &vxcu);
//	if(s!=SQLITE_OK)
//	{
//		fprintf(stderr,"vxcu.db database open faileld:%s\n",strerror(errno));
//		exit(1);
//	}
//	//insert
//	int curindex= sqlite3_last_insert_rowid(vxcu);
//	printf("curindex=:%d\n",curindex);
//
////	++curindex;
//	char sql[128]={0};
//	sprintf(sql,"insert into pmu_mr('pmu_index','phnmr','annmr','dgnmr') values('%d','11','12','13');",curindex);
//	int res=sqlite3_exec(vxcu,(const char*)sql,NULL,NULL,NULL);
//	if(res!=0)
//	{
//		printf("inert into vxcu's pmu_mr was failed:%d\n",res);
//	}
//	else
//	{
//		printf("insert into vxcu's pmu_mr table successful\n");
//	}

//	memset(sql,0,sizeof(sql));
//	memcpy(sql,"create table a(id int ,name varchar(20));",sizeof("create table a(id int ,name varchar(20));"));
//	int res=sqlite3_exec(vxcu,(const char*)sql,NULL,NULL,NULL);
//	if(res!=0)
//	{
//		printf("create vxcu's a was failed:%d\n",res);
//	}
//	else
//	{
//		printf("create vxcu's a table successful\n");
//	}

//	memset(sql,0,sizeof(sql));
//	memcpy(sql,"drop table a;",sizeof("drop table a;"));
//	int res=sqlite3_exec(vxcu,(const char*)sql,NULL,NULL,NULL);
//	if(res!=0)
//	{
//		printf("drop vxcu's a was failed:%d\n",res);
//	}
//	else
//	{
//		printf("drop vxcu's a table successful\n");
//	}
//
//


//	char ** selbuf=NULL;
//	int row,col;
//	s=sqlite3_get_table(vxcu,"select * from pmu_mr where pmu_index=0;",&selbuf,&row,&col,NULL);
//	if(s!=0)
//	{
//		printf("select pmu_mr failed\n");
//	}
//	int i;
//	for(i = 0; i <= row; i++)
//	{
//		for(int j = 0; j < col; j++)
//		{
//			printf("%s\t",*(selbuf+i*col+j));
//		}
//		printf("\n");
//	}
//	sqlite3_free_table(selbuf);
//	printf("i=%d\n",i);
//
//	sqlite3_close(vxcu);
	//###########################################################################
	DBOP.ClearTable();
//	DBOP.insertMrData(1,2,3);
//	DBOP.insertMrData(11,21,31);
//	DBOP.insertMrData(12,22,32);
//	DBOP.insertMrData(13,23,33);
//	DBOP.insertMrData(14,24,34);
//	DBOP.insertMrData(15,25,35);
//	DBOP.insertMrData(16,26,36);
	int s;
//	s=DBOP.GetPhnmr(0);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(1);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(2);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(3);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(4);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(5);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d ",s);
//	}
//	s=DBOP.GetPhnmr(6);
//	if(s!=-1)
//	{
//		printf("phnmr=:%d\n",s);
//	}
//
//	s=DBOP.GetAnnmr(0);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(1);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(2);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(3);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(4);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(5);
//	if(s!=-1)
//	{
//		printf("anmr=:%d ",s);
//	}
//	s=DBOP.GetAnnmr(6);
//	if(s!=-1)
//	{
//		printf("anmr=:%d\n",s);
//	}
//
//
//
//	s=DBOP.GetDgnmr(0);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(1);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(2);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(3);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(4);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(5);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d ",s);
//	}
//	s=DBOP.GetDgnmr(6);
//	if(s!=-1)
//	{
//		printf("dgmr=:%d\n",s);
//	}
	DBOP.insertTypeData(0,0,1,99);
	DBOP.insertTypeData(0,1,2,98);
	DBOP.insertTypeData(0,2,2,97);
	DBOP.insertTypeData(1,1,1,96);
	DBOP.insertTypeData(1,2,1,95);
	DBOP.insertTypeData(1,3,1,94);

//	s=DBOP.GetAnType(0,0);
//	if(s!=-1)
//	{
//		printf("type=:%d\n",s);
//	}
//	s=DBOP.GetAnType(0,2);
//	if(s!=-1)
//	{
//		printf("type=:%d\n",s);
//	}
//	s=DBOP.GetAnType(1,2);
//	s=DBOP.GetAnLastPindex();
//	if(s!=-1)
//	{
//		printf("type=:%d\n",s);
//	}
	int n=DBOP.GetAnLastPindex();
	printf("n=%d\n",n);
	for(int i=0;i<=n;++i)
	{
		DBOP._GetAnType(i,&Tyst);
	}
	showTyst(n);
	return 0;
}
void showTyst(int n)
{

	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<Tyst.Tq[i]._dindex;++j)
		{
			printf("number=:%d  type=:%d\n",Tyst.Tq[i].typelist[j].number,Tyst.Tq[i].typelist[j]._type);
		}
	}
}
