// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <stdio.h>

// 인젝션될 함수
extern "C" __declspec(dllexport) void InjectedFunction()
{   
    printf("InjectedFunction called\n");
    MessageBoxA(NULL, "DLL Injection Successful!", "DLL Injection", MB_OK);
}

// DLL 엔트리 포인트
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    // DLL이 로드되거나 언로드될 때 실행되는 코드
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // DLL이 프로세스에 연결될 때 실행될 초기화 코드
        InjectedFunction();
        break;

    case DLL_THREAD_ATTACH:
        // DLL이 새 스레드에 연결될 때 실행될 초기화 코드
        break;

    case DLL_THREAD_DETACH:
        // DLL이 스레드에서 분리될 때 실행될 정리 코드
        break;

    case DLL_PROCESS_DETACH:
        // DLL이 프로세스에서 분리될 때 실행될 정리 코드
        break;
    }
    return TRUE;
}
