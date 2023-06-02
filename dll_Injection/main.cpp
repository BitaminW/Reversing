
#include <Windows.h>

int main()
{
    // DLL 주입
    HMODULE dllModule = LoadLibraryA("C:\\Temp\\CreateDLL.dll");

    if (dllModule != NULL)
    {
        // DLL에서 호출할 함수 포인터 가져오기
        typedef void (*InjectedFunctionPtr)();
        InjectedFunctionPtr injectedFunction = (InjectedFunctionPtr)GetProcAddress(dllModule, "InjectedFunction");

        if (injectedFunction != NULL)
        {
            // DLL 함수 호출
            injectedFunction();
        }
        else
        {
            // DLL 함수를 찾을 수 없는 경우 처리
        }

        // DLL 언로드
        FreeLibrary(dllModule);
    }
    else
    {
        // DLL을 로드할 수 없는 경우 처리
    }

    return 0;
}
