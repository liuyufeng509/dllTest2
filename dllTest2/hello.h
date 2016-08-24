//hello.h  
#ifdef EXPORT_HELLO_DLL  
#define HELLO_API __declspec(dllexport)  
#else  
#define HELLO_API __declspec(dllimport)  
#endif  
  
struct TestStruct
{
	int len;
	char **p;
}; 
extern "C"  
{  
	
 
    HELLO_API int CreateModel_C(int MaxVectorDim, char * TrainSql );  
	HELLO_API double Classification_C(int MaxVectorDim,char * TestSql,int TrainSampleNum);
	HELLO_API char* CosineSimilarity_C(int N,char* testCaseBHStr,char* sqlStr,int MaxVectorDim,int classifyResult);

	HELLO_API char* AnalysisDescriptionMain_C(char* caseID,int len, char* caseDesc[],int MaxVectorDim,char* sqlSimilarSample,char* sqlTestCase,char* sqlTestPerson,bool AddSimilarCase);
	HELLO_API const char* AnalysisDescriptionMultiMain_C(char* caseID,int len1, TestStruct *p,int MaxVectorDim,char* sqlSimilarSample,char* sqlTestCase,char* sqlTestPerson,bool AddSimilarCase);


	HELLO_API int FreeMem(char * ptr );		//ÊÍ·ÅÉêÇëµÄchar * ÄÚ´æ
}  