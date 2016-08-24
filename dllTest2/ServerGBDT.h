#pragma   once 
#ifndef _SERVERGBDT_H
#define _SERVERGBDT_H
#ifdef __cplusplus
extern "C"  {
#endif
	__declspec(dllexport) int CreateModel(int MaxVectorDim,string TrainSql);//建模
	__declspec(dllexport) double Classification(int MaxVectorDim,string TestSql,int TrainSampleNum);//分类
	__declspec(dllexport) string CosineSimilarity(int N,string testCaseBHStr,string sqlStr,int MaxVectorDim,int classifyResult);



#ifdef __cplusplus
}
#endif
#endif /* _LIBLINEAR_H */



