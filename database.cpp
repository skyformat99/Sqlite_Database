/*
 * database.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: xieliming
 */
#include "database.h"
DataBaseOperation::DataBaseOperation()
{
	int s=sqlite3_open("./vxcu.db", &this->vxcu);
	if(s!=SQLITE_OK)
	{
		fprintf(stderr,"vxcu.db database open faileld:%s\n",strerror(errno));
		sqlite3_close(vxcu);
	}
	memset(sql,0,sizeof(sql));
	s=this->GetMrCnt();
	if(s!=-1)
	{
		this->pmu_mr_curindex=s;
	}
	else
	{
		this->pmu_mr_curindex=0;
	}
	s=this->GetTyCnt();
	if(s!=-1)
	{
		this->type_an_curindex=s;
	}
	else
	{
		this->type_an_curindex=0;
	}
	this->phtable_curindex=0;
	this->antable_curindex=0;
//	printf("p_index=:%d t_index=:%d\n",this->pmu_mr_curindex,this->type_an_curindex);
}
int DataBaseOperation::GetMrCnt()
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from pmu_mr;");
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		sqlite3_free_table(selbuf);
		return -1;
	}
	sqlite3_free_table(selbuf);
	return row;
}
int DataBaseOperation::GetTyCnt()
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from type_an;");
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		sqlite3_free_table(selbuf);
		return -1;
	}
	sqlite3_free_table(selbuf);
	return row;
}
DataBaseOperation::~DataBaseOperation()
{
	sqlite3_close(vxcu);
}
bool DataBaseOperation::isTableExist()
{
	return true;
}
bool DataBaseOperation::ClearTable()
{
	memset(sql,0,sizeof(sql));
	char tmp[128]="delete from pmu_mr;";
	memcpy(sql,tmp,strlen(tmp)+1);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("delete vxcu's pmu_mr was failed:%d\n",res);
	}
	else
	{
//		printf("delete vxcu's pmu_mr table successful\n");
		this->pmu_mr_curindex=0;
	}
	char tmp2[128]="delete from type_an;";
	memcpy(sql,tmp2,strlen(tmp2)+1);
	res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("delete vxcu's type_an was failed:%d\n",res);
	}
	else
	{
//		printf("delete vxcu's type_an table successful\n");
		this->type_an_curindex=0;
	}
	char tmp3[128]="delete from phtable;";
	memcpy(sql,tmp3,strlen(tmp2)+3);
	res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("delete vxcu's phtable was failed:%d\n",res);
	}
	else
	{
		//		printf("delete vxcu's type_an table successful\n");
		this->phtable_curindex=0;
	}
	char tmp4[128]="delete from antable;";
	memcpy(sql,tmp4,strlen(tmp2)+4);
	res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("delete vxcu's antable was failed:%d\n",res);
	}
	else
	{
		//		printf("delete vxcu's type_an table successful\n");
		this->antable_curindex=0;
	}
	return true;
}
bool DataBaseOperation::createAllTable()
{
	memset(sql,0,sizeof(sql));
	char tmp[128]="CREATE TABLE pmu_mr(pmu_index int primary key,phnmr int not null,\
                   annmr int not null,dgnmr int not null);";
	memcpy(sql,tmp,strlen(tmp)+1);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("create vxcu's pmu_mr was failed:%d\n",res);
	}
	else
	{
		printf("create vxcu's pmu_mr table successful\n");
	}
	char tmp2[128]="create table type_an(p_index int,a_index int,number int,type int);";
	memcpy(sql,tmp2,strlen(tmp2)+1);
	res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("create vxcu's type_an was failed:%d\n",res);
	}
	else
	{
		printf("create vxcu's type_an table successful\n");
	}
	return true;
}
bool DataBaseOperation::insertMrData(int t_phnmr,int t_annmr,int t_dgnmr)
{
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"insert into pmu_mr('pmu_index','phnmr','annmr','dgnmr') values( \
			'%d','%d','%d','%d');",this->pmu_mr_curindex,t_phnmr,t_annmr,t_dgnmr);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("insert into vxcu's pmu_mr was failed:%d\n",res);
		return false;
	}
	else
	{
		++this->pmu_mr_curindex;
		printf("insert into vxcu's pmu_mr successful-phmr=:%d,anmr=:%d,dgmr=:%d\n",t_phnmr,t_annmr,t_dgnmr);
		return true;
	}
}
bool DataBaseOperation::insertphtableData(int p_index,int mr_index,unsigned int phval)
{
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"insert into phtable('p_index','phmr_index','phunit') values( \
					'%d','%d','%d');",this->phtable_curindex,mr_index,phval);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("insert into vxcu's phtable was failed:%d\n",res);
		return false;
	}
	else
	{
		++this->phtable_curindex;
		printf("insert into vxcu's phtable successful-phunit=:%d\n",phval);
		return true;
	}
	return true;
}
bool DataBaseOperation::insertantableData(int p_index,int mr_index,unsigned int anval)
{
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"insert into antable('p_index','anmr_index','anunit') values( \
					'%d','%d','%d');",this->antable_curindex,mr_index,anval);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("insert into vxcu's antable was failed:%d\n",res);
		return false;
	}
	else
	{
		++this->antable_curindex;
		printf("insert into vxcu's unit successful anunit=:%d\n",anval);
		return true;
	}
	return true;
}

bool DataBaseOperation::insertTypeData(int p_index,int t_index,int number,int typeval)
{
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"insert into type_an('p_index','a_index','number','type') values( \
				'%d','%d','%d','%d');",p_index,t_index,number,typeval);
	int res=sqlite3_exec(this->vxcu,(const char*)sql,NULL,NULL,NULL);
	if(res!=0)
	{
		printf("insert into vxcu's ptype_an was failed:%d\n",res);
		return false;
	}
	else
	{
		++this->type_an_curindex;
//		printf("insert into vxcu's type_an successful\n");
		return true;
	}
}
int DataBaseOperation::GetPhnmr(int p_index)
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from pmu_mr where pmu_index = %d;",p_index);
//	printf("this->sql:%s\n",this->sql);
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
//	printf("s=:%d\n",s);

	int i;
	int res;
	bool r=false;
	for(i = 0; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if((i==1)&&(j==1))
			{
				res= atoi((char *)(*(selbuf+i*col+j)));
				r=true;
				break;
			}
//			printf("%s\t",*(selbuf+i*col+j));
		}
//		printf("\n");
	}
	sqlite3_free_table(selbuf);
	if(r)
	{
		return res;
	}
	else
	{
		return -1;
	}
}
int DataBaseOperation::GetAnnmr(int p_index)
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from pmu_mr where pmu_index = %d;",p_index);
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
	int i;
	int res;
	bool r=false;
	for(i = 0; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(i==1&&j==2)
			{
				res= atoi((char *)(*(selbuf+i*col+j)));
				r=true;
				break;
			}
			//			printf("%s\t",*(selbuf+i*col+j));
		}
		//		printf("\n");
	}
	sqlite3_free_table(selbuf);
	if(r)
	{
		return res;
	}
	else
	{
		return -1;
	}
}
int DataBaseOperation::GetDgnmr(int p_index)
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from pmu_mr where pmu_index = %d;",p_index);
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
	int i;
	int res;
	bool r=false;
	for(i = 0; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(i==1&&j==3)
			{
				res= atoi((char *)(*(selbuf+i*col+j)));
				r=true;
				break;
			}
			//			printf("%s\t",*(selbuf+i*col+j));
		}
		//		printf("\n");
	}
	sqlite3_free_table(selbuf);
	if(r)
	{
		return res;
	}
	else
	{
		return -1;
	}
}
int DataBaseOperation::GetAnType(int p_index,int a_index)
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));
	sprintf(this->sql,"select * from type_an where p_index = %d and a_index = %d;",p_index,a_index);
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
	int i;
	int res;
	bool r=false;
	for(i = 0; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(i==1&&j==2)
			{
				res= atoi((char *)(*(selbuf+i*col+j)));
				r=true;
				break;
			}
//						printf("%s\t",*(selbuf+i*col+j));
		}
//				printf("\n");
	}
	sqlite3_free_table(selbuf);
	if(r)
	{
		return res;
	}
	else
	{
		return -1;
	}
}
int DataBaseOperation::GetAnLastPindex()     //##################################
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));

	sprintf(this->sql,"select * from type_an;");
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
	int i;
	int res;
	bool r=false;
	for(i = 0; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(i==row&&j==0)
			{
				res= atoi((char *)(*(selbuf+i*col+j)));
				r=true;
				break;
			}
			//						printf("%s\t",*(selbuf+i*col+j));
		}
		//				printf("\n");
	}
	sqlite3_free_table(selbuf);
	if(r)
	{
		return res;
	}
	else
	{
		return -1;
	}
}
bool DataBaseOperation::_GetAnType(int p_index,struct Typeset* tps)
{
	char ** selbuf=NULL;
	int row,col;
	memset(this->sql,0,sizeof(this->sql));

	sprintf(this->sql,"select * from type_an where p_index=%d;",p_index);
	int s=sqlite3_get_table(vxcu,(const char*)this->sql,&selbuf,&row,&col,NULL);
	if(s!=0)
	{
		printf("select pmu_mr failed\n");
		return -1;
	}
	int i;
	for(i = 1; i <= row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(j==2)
			{
				tps->Tq[p_index].typelist[tps->Tq[p_index]._dindex].number=atoi((char *)(*(selbuf+i*col+j)));
			}
			if(j==3)
			{
				tps->Tq[p_index].typelist[tps->Tq[p_index]._dindex]._type=atoi((char *)(*(selbuf+i*col+j)));
				++tps->Tq[p_index]._dindex;
			}
		}
		printf("\n");

	}
	sqlite3_free_table(selbuf);
	return true;
}
