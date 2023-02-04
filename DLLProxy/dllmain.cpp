#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "Ws2_32.Lib")
#pragma comment(lib, "Crypt32.Lib")


// 这里填写DLL导出函数
#pragma comment(linker,"/export:CompareBrowserVersions=WebView2Loader01.CompareBrowserVersions,@1")
#pragma comment(linker,"/export:CreateCoreWebView2Environment=WebView2Loader01.CreateCoreWebView2Environment,@2")
#pragma comment(linker,"/export:CreateCoreWebView2EnvironmentWithOptions=WebView2Loader01.CreateCoreWebView2EnvironmentWithOptions,@3")
#pragma comment(linker,"/export:GetAvailableCoreWebView2BrowserVersionString=WebView2Loader01.GetAvailableCoreWebView2BrowserVersionString,@4")


INT WorkThread();

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        // 创建新线程
        HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(PVOID)WorkThread, NULL, 0, NULL);
        if (hThread != NULL)
            CloseHandle(hThread);

        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


INT WorkThread()
{
    // 执行你想做的事情
    // ...
    return 0;
}
