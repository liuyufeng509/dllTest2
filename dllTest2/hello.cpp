//hello.cpp  
#include <string>  
#include<vector>
#define EXPORT_HELLO_DLL  
#include "hello.h"  
#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <regex>
#include <set>
#include <string>  

#include "AnalysisDescriptionMulti.h"
#include "AnalysisDescription.h"
#include "ServerGBDT.h"


using namespace std;


char* UTF8ToEncode(const char* mbcsStr)		//UTF8转换为Unicode
{
 wchar_t*  wideStr; 
 char*   unicodeStr; 
 int   charLen;

 charLen = MultiByteToWideChar(CP_UTF8, 0, mbcsStr, -1, NULL, 0);   
 wideStr = (wchar_t*) malloc(sizeof(wchar_t)*charLen); 
 MultiByteToWideChar(CP_UTF8, 0, mbcsStr, -1, wideStr, charLen); 

 charLen =WideCharToMultiByte(CP_ACP, 0, wideStr, -1, NULL, 0, NULL, NULL);  
 unicodeStr = (char*)malloc(charLen);
    WideCharToMultiByte(CP_ACP, 0, wideStr, -1, unicodeStr, charLen, NULL, NULL); 

 free(wideStr); 
 return unicodeStr;
}

char* EncodeToUTF8(const char* mbcsStr)			////Unicode转换为UTF8
{ 
 wchar_t*  wideStr; 
 char*   utf8Str; 
 int   charLen;

 charLen = MultiByteToWideChar(CP_UTF8, 0, mbcsStr, -1, NULL, 0); 
 wideStr = (wchar_t*) malloc(sizeof(wchar_t)*charLen); 
 MultiByteToWideChar(CP_ACP, 0, mbcsStr, -1, wideStr, charLen);

 charLen = WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, NULL, 0, NULL, NULL);

 utf8Str = (char*) malloc(charLen);

 WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, utf8Str, charLen, NULL, NULL);

 free(wideStr); 
 return utf8Str;

} 

HELLO_API int CreateModel_C(int MaxVectorDim, char * TrainSql )
{  
	 char* uTrainSql = UTF8ToEncode(TrainSql);
	 cout<<"******************CreateModel*****************"<<endl;
     cout<<"MaxVectorDim="<<MaxVectorDim<<endl;
	// cout<<"TrainSql="<<TrainSql<<endl;
	 cout<<"uTrainSql="<<uTrainSql<<endl;
	 int res = -1;
	 res = CreateModel(MaxVectorDim, string(uTrainSql));	//调用算法接口，createModel
	 cout<<"算法接口返回值：res="<<res<<endl;
	
	 free(uTrainSql);
	 return res;
}  

HELLO_API double Classification_C(int MaxVectorDim,char * TestSql,int TrainSampleNum)
{
	char* uTestSql = UTF8ToEncode(TestSql);
	cout<<"******************Classification*****************"<<endl;
    cout<<"MaxVectorDim="<<MaxVectorDim<<endl;
	//cout<<"TestSql="<<TestSql<<endl;
	cout<<"uTestSql="<<uTestSql<<endl;
	cout<<"TrainSampleNum="<<TrainSampleNum<<endl;
	double res = -1;
	res = Classification(MaxVectorDim, string(uTestSql),TrainSampleNum);
	cout<<"算法接口返回值：res="<<res<<endl;

	free(uTestSql);
	return res;
}

HELLO_API char* CosineSimilarity_C(int N,char* testCaseBHStr,char* sqlStr,int MaxVectorDim,int classifyResult)
{

	char *uTestCaseBHStr = UTF8ToEncode(testCaseBHStr);
	char *uSqlStr = UTF8ToEncode(sqlStr);
	cout<<"******************CosineSimilarity*****************"<<endl;
	cout<<"N="<<N<<endl;
    cout<<"MaxVectorDim="<<MaxVectorDim<<endl;
	//cout<<"testCaseBHStr="<<testCaseBHStr<<endl;
	cout<<"uTestCaseBHStr"<<uTestCaseBHStr<<endl;
	//cout<<"sqlStr="<<sqlStr<<endl;
	cout<<"usqlStr="<<uSqlStr<<endl;
	cout<<"classifyResult="<<classifyResult<<endl;

	string resStr("ERROR");
	resStr = CosineSimilarity(N, string(uTestCaseBHStr),string(uSqlStr), MaxVectorDim, classifyResult);
	cout<<"算法接口返回值：resStr="<<resStr<<endl;
	char * res1 = new char[resStr.length()+1];
	memset(res1,0, resStr.length()+1);
	strcpy(res1, resStr.c_str());
	char *res2 = EncodeToUTF8(res1);
	delete [] res1;
	char *res = new char[strlen(res2)+1];
	memset(res,0, strlen(res2)+1);
	strcpy(res, res2);
	free(res2);
	printf("allocated address: %p\n", res);
	
	free(uTestCaseBHStr);
	free(uSqlStr);

	return res;
}

HELLO_API char* AnalysisDescriptionMain_C(char* caseID,int len, char* caseDesc[],int MaxVectorDim,char* sqlSimilarSample,char* sqlTestCase,char* sqlTestPerson,bool AddSimilarCase)
{
	vector<string> strDesc;
	cout<<"******************AnalysisDescriptionMain*****************"<<endl;
	char *ucaseID = UTF8ToEncode(caseID);
	char *uSqlSimilarSample = UTF8ToEncode(sqlSimilarSample);
	char *uSqlTestCase = UTF8ToEncode(sqlTestCase);
	char *uSqlTestPerson = UTF8ToEncode(sqlTestPerson);
	char **p = new char*[len];
	for(int i=0; i<len;i++)
	{
		p[i] = UTF8ToEncode(caseDesc[i]);
		strDesc.push_back(string(p[i]));
	}

	cout<<"caseID="<<caseID<<endl;
	cout<<"uCaseID="<<ucaseID<<endl;
    cout<<"len="<<len<<endl;
	for(int i=0; i<len; i++)
	{
		cout<<"caseDesc["<<i<<"]="<<caseDesc[i]<<endl;
		cout<<"p["<<i<<"]="<<p[i]<<endl;
	}
	cout<<"MaxVectorDim="<<MaxVectorDim<<endl;
	//cout<<"sqlSimilarSample="<<sqlSimilarSample<<endl;
	cout<<"uSqlSimilarSample="<<uSqlSimilarSample<<endl;
	//cout<<"sqlTestCase="<<sqlTestCase<<endl;
	cout<<"uSqlTestCase="<<uSqlTestCase<<endl;
	//cout<<"sqlTestPerson="<<sqlTestPerson<<endl;
	cout<<"uSqlTestPerson="<<uSqlTestPerson<<endl;
	cout<<"AddSimilarCase="<<AddSimilarCase<<endl;
	
	string resStr("CosineSimilarity 已执行");
	resStr = AnalysisDescriptionMain(ucaseID, strDesc, MaxVectorDim, string(uSqlSimilarSample), string(uSqlTestCase), string(uSqlTestPerson),AddSimilarCase );
	cout<<"算法接口返回值：resStr="<<resStr<<endl;
	
	char * res1 = new char[resStr.length()+1];
	memset(res1,0, resStr.length()+1);
	strcpy(res1, resStr.c_str());
	char *res2 = EncodeToUTF8(res1);
	delete [] res1;
	char *res = new char[strlen(res2)+1];
	memset(res,0, strlen(res2)+1);
	strcpy(res, res2);
	printf("allocated address: %p\n", res);
	
	free(res2);
	free(ucaseID);
	free(uSqlSimilarSample);
	free(uSqlTestCase);
	free(uSqlTestPerson);
	for(int i=0; i<len; i++)
	{
		free(p[i]);
	}
	delete[] p;

	return res;
}

HELLO_API const char* AnalysisDescriptionMultiMain_C(char* caseID,int len1,  TestStruct *p,int MaxVectorDim,char* sqlSimilarSample,char* sqlTestCase,char* sqlTestPerson,bool AddSimilarCase)
{
	cout<<"******************AnalysisDescriptionMultiMain*****************"<<endl;
	char *ucaseID = UTF8ToEncode(caseID);
	char *uSqlSimilarSample = UTF8ToEncode(sqlSimilarSample);
	char *uSqlTestCase = UTF8ToEncode(sqlTestCase);
	char *uSqlTestPerson = UTF8ToEncode(sqlTestPerson);

	TestStruct *newP = new TestStruct[len1];
	vector<vector<string>> caseDescVec;
	for(int i=0; i<len1; i++)
	{
		newP[i].len = p[i].len;
		newP[i].p = new char*[newP[i].len];
		vector<string> decVec;
		for(int j=0; j<p[i].len;j++)
		{
			newP[i].p[j] = UTF8ToEncode(p[i].p[j]);
			decVec.push_back(string(newP[i].p[j]));
		}
		caseDescVec.push_back(decVec);
	}
	cout<<"caseID="<<caseID<<endl;
	cout<<"uCaseID="<<ucaseID<<endl;
    cout<<"len1="<<len1<<endl;
	for(int i=0; i<len1; i++)
	{
		for(int j=0; j<p[i].len; j++)
		{
			cout<<"TestStruct["<<i<<"].p["<<j<<"]="<<p[i].p[j]<<endl;
			cout<<"NewP["<<i<<"].p["<<j<<"]="<<newP[i].p[j]<<endl;
		}
	}
	cout<<"MaxVectorDim="<<MaxVectorDim<<endl;
	//cout<<"sqlSimilarSample="<<sqlSimilarSample<<endl;
	cout<<"uSqlSimilarSample="<<uSqlSimilarSample<<endl;
	//cout<<"sqlTestCase="<<sqlTestCase<<endl;
	cout<<"uSqlTestCase="<<uSqlTestCase<<endl;

	//cout<<"sqlTestPerson="<<sqlTestPerson<<endl;
	cout<<"uSqlTestPerson="<<uSqlTestPerson<<endl;
	cout<<"AddSimilarCase="<<AddSimilarCase<<endl;
	
	string resStr("ERROR");
	resStr = AnalysisDescriptionMultiMain(string(ucaseID),caseDescVec,MaxVectorDim, string(uSqlSimilarSample),
		string(uSqlTestCase), string(uSqlTestPerson), AddSimilarCase);
	char * res1 = new char[resStr.length()+1];
	memset(res1, 0, resStr.length()+1);
	strcpy(res1, resStr.c_str());
	char *res2 = EncodeToUTF8(res1);
	delete [] res1;
	char *res = new char[strlen(res2)+1];
	memset(res, 0, strlen(res2)+1);
	strcpy(res, res2);
	printf("allocated address: %p\n", res);
	
	free(res2);
	free(ucaseID);
	free(uSqlSimilarSample);
	free(uSqlTestCase);
	free(uSqlTestPerson);

	for(int i=0; i<len1; i++)
	{
		for(int j=0; j<newP[i].len; j++)
		{
			free(newP[i].p[j]);
		}
	}

	delete[] newP;
	return res;
}


HELLO_API int FreeMem(char * ptr )
{
	printf("delete address: %p\n", ptr);
	delete[] ptr;
	return 0;
}