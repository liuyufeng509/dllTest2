//hello.h  
#ifdef TESTDLL2_EXPORTS  
#define HELLO_API __declspec(dllexport)  
#else  
#define HELLO_API __declspec(dllimport)  
#endif  
  

extern "C"  
{   
    HELLO_API char* use_fun_c(char* s1); 
}  