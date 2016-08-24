#pragma   once 
#ifndef _ANALYSISDESCRIPTION_H
#define _ANALYSISDESCRIPTION_H
#include <vector>
#include <map>
#include <string>
using namespace std;
#ifdef __cplusplus
extern "C"  {
#endif
__declspec(dllimport) string AnalysisDescriptionMain(string caseID,vector<string> caseDesc,int MaxVectorDim,string sqlSimilarSample,
		string sqlTestCase,string sqlTestPerson,bool AddSimilarCase);
#ifdef __cplusplus
}
#endif
#endif

