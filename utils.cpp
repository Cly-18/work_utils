#include "utils.h"

std::string Utils::getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
    time_t localt=std::chrono::system_clock::to_time_t(now);
    std::stringstream ret;
    //%Y-%m-%d %H:%M:%S
    ret<<std::put_time(localtime(&localt),"%F %T.")<<std::setw(3)<<std::setfill('0')<<ms;
    return ret.str();
}
