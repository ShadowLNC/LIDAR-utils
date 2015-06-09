/* 
 * File:   LIDAR-utils.h
 * Author: robot
 *
 * Created on 9 June 2015, 3:04 PM
 */

#ifndef LIDARUTILS_H
#define	LIDARUTILS_H

unsigned int LIDAR_decode_raw(const char* chars) {
    /*
     * LIDAR outputs 0x00 to 0x3F
     * 0x30 is added to make ASCII printable
     * We subtract 0x30
     * Concat the 6 bits onto the integer
     * Total 3 chars
     * 3*6 is 18 bits, 2MSB discarded as will be 0 anyway
     *
     * returns 0 if error, else distance in mm
     */
    int dist = 0;
    int i = 0;
    for (i=0; i<3; ++i) {
        //shift left 6 bits to make room for next
        dist <<= 6; //first iteration is zeros
        char tmp = chars[0]-0x30; //subtract 0x30
        if (tmp<0x00 || tmp>0x3F) { return 0; } //error handling
        dist += tmp & 0x3F; //6 LSB mask
    }
}


#endif	/* LIDAR_UTILS_H */

