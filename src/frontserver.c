/**
 * @file frontserver.c
 * @brief gateway socket receive from IOT gateway implements
 * @author ritchietam
 * @version 0.0.1
 * @date 2017-06-02
 */

#include "frontserver.h"

/**
 * @brief start the front server receive network package from IOT device
 *
 * @param port listening port
 *
 * @return 
 */
int start_front_server(int port)
{
    struct address;

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( port );


}
