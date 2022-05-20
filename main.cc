#include"modules/task_utils.h"
#ifdef OPENH264__CC
#include"codec/common/inc/WelsLock.h"
#endif

// mingw or gcc we dont care
#include<future>
#include<mutex>

// for when we have c user based fags who use c99 for thsi shit
#ifdef C99_MINGW_GCC
#include<stdio.h>
#endif
signed main(int argvc, char ** argc) {
    void(*a)()=WelsCommon::CWelsLock().Lock();
    std::packaged_task<void()> tt({return 0;});
    std::future<void> std_o = std::async(std::async::deferred, )
    std::future<void> cline = tt.get_future();
    
    printf("OK" + *(&std_o));
    
}
