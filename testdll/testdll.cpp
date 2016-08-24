// testdll.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include "../dllTest2/hello.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
//	CreateModel_C(2500, "select * from (select case_id as casebh,final_result as casetypeid,materials_abstract||'。'||newcontent||'。'||proof as caseinfo from  (select rownum nm,case_id,final_result,materials_abstract,newcontent,proof from model_view1 where rownum<=5000  and final_result<4 and case_id not in (select * from error_fayi) order by case_id) where  nm<=4500");
//	Classification_C(2500,"select case_id as casebh,final_result as casetypeid,materials_abstract||'。'||newcontent||'。'||proof as caseinfo from (select rownum nm,case_id,final_result,materials_abstract,newcontent,proof from model_view1 where rownum<=5000  and final_result<4 and case_id not in (select * from error_fayi) order by case_id) where case_id=111111",15);
	char *res =  CosineSimilarity_C(3,"5485", "select itemid as casebh,item_num as casetypeid,description ||remarks as caseinfo from model_standard where item_num=1union all select case_id as casebh,final_result as casetypeid,materials_abstract||'。'||newcontent as caseinfo from model_view1 where case_id=5485",
		2500, 1);

	if(res!=NULL)
		cout<<res<<endl;
	return 0;
}

