/*
 * database.h
 *
 *  Created on: Apr 13, 2017
 *      Author: xieliming
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include"sqlite3.h"
#include "DataS.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <strings.h>

class DataBaseOperation
{
public:
	DataBaseOperation();
	~DataBaseOperation();
	bool isTableExist();
	bool createAllTable();
	int GetMrCnt();
	int GetTyCnt();
	////////////////////////////////////////////////////////
	bool ClearTable();
	bool insertMrData(int t_phnmr,int t_annmr,int t_dgnmr);
	bool insertTypeData(int p_index,int t_index,int number,int typeval);      //engine number 1 and 2

	bool insertphtableData(int p_index,int mr_index,unsigned int phval);
	bool insertantableData(int p_index,int mr_index,unsigned int anval);

	int GetPhnmr(int p_index);
	int GetAnnmr(int p_index);
	int GetDgnmr(int p_index);
	int GetAnType(int p_index,int a_index);
	bool _GetAnType(int p_index,struct Typeset* tps);
	int GetAnLastPindex();

private:
	sqlite3* vxcu;
	char sql[512];
	int pmu_mr_curindex;
	int type_an_curindex;
	int phtable_curindex;
	int antable_curindex;
};
#endif /* DATABASE_H_ */
