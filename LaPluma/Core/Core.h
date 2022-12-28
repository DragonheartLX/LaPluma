#pragma once

#ifdef LP_WINDOWS
    #ifdef LP_BUILD_DLL
        #define LP_API __declspec(dllexport)
    #else
        #ifdef LP_DLL
            #define LP_API __declspec(dllimport)
        #else
            #define LP_API
        #endif 
    #endif
#else
    #error LaPluma currently only supports Windows
#endif