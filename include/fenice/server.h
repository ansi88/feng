/* *
 *  This file is part of Feng
 *
 * Copyright (C) 2007 by LScube team <team@streaming.polito.it>
 * See AUTHORS for more details
 *
 * Feng is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * Feng is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Feng; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * */

/**
 * @file server.h
 * Server instance structure
 */

#ifndef FN_SERVER_H
#define FN_SERVER_H

// #include <fenice/schedule.h>
#include <fenice/prefs.h>
#include "array.h"
#include "conf.h"
#include <netembryo/wsocket.h>
#include <pwd.h>
#include <grp.h>

typedef struct feng {
/** 
 * @name listening sockets
 * listening sockets
 */
//@{
    Sock *listen_socks;             //!< listen sockets
//@}
    pthread_t mth;                  //!< mediathread
    struct schedule_list *sched;
/**
 * @name lighttpd-alike preferences
 * lemon based, lighttpd alike preferences
 */
//@{
    array *config;
    array *config_touched;

    array *config_context;
    specific_config **config_storage;

    server_config srvconf;
//@}
/** 
 * @name port pool
 * port pool variables
 */
//@{ 
    int start_port;                 //!< initial rtp port
    int *port_pool;                 //!< list of allocated ports
//@}
/** 
 * @name user
 * User id and group id used by the current feng instance
 */
//@{
    gid_t gid;                      //!< group id
    uid_t uid;                      //!< user id
//@}
/** 
 * @name eventloop state
 * Includes the 
 */
//@{
    struct RTSP_buffer *rtsp_list;
    /**
     * Once it reaches the maximum the server redirects
     * to a twin if available
     */
    int num_conn;               //!< number of active connections
    int conn_count;             //!< number of active connections (FIXME)
    int child_count;            //!< unused
    int stop_schedule;          //!< to be refactored away
//@}
} feng;

typedef feng server;

#endif // FN_SERVER_H