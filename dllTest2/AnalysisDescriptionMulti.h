#pragma once
#ifndef _ANALYSISDESCRIPTIONMULTI_H
#define _ANALYSISDESCRIPTIONMULTI_H
#include <vector>
#include <map>
#include <string>
using namespace std;
#ifdef __cplusplus
extern "C"  {
#endif
__declspec(dllimport)  string AnalysisDescriptionMultiMain(string caseID,vector<vector<string>> caseDesc,int MaxVectorDim,string sqlSimilarSample,
	string sqlTestCase,string sqlTestPerson,bool AddSimilarCase);
#ifdef __cplusplus
}
#endif
#endif /* _LIBLINEAR_H */