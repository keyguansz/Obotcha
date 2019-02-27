#include <time.h>

#include "TimeZone.hpp"

int _TimeZone::zone = -1;

int _TimeZone::getZone() {
    if(zone == -1) {
        time_t time_utc = 0;
        struct tm *p_tm_time;

        int time_zone = 0;
        p_tm_time = localtime( &time_utc );   //change to local time
        zone = (p_tm_time->tm_hour > 12)?(p_tm_time->tm_hour-= 24):p_tm_time->tm_hour;
    }

    return zone;
}

void _TimeZone::setZone(int z) {
    zone = z;
}