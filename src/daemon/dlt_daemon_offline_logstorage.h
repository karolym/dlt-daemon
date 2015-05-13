/**
* @licence app begin@
* Copyright (C) 2013 - 2015  Advanced Driver Information Technology.
* This code is developed by Advanced Driver Information Technology.
* Copyright of Advanced Driver Information Technology, Bosch and DENSO.
*
* DLT offline log storage functionality header file.
*
* \copyright
* This Source Code Form is subject to the terms of the
* Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
* this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* \author Syed Hameed <shameed@jp.adit-jv.com> ADIT 2013 - 2015
* \author Christoph Lipka <clipka@jp.adit-jv.com> ADIT 2015
*
* \file: dlt_daemon_offline_logstorage.h
* For further information see http://www.genivi.org/.
* @licence end@
*/

/*******************************************************************************
*                                                                            **
*  SRC-MODULE: dlt_daemon_offline_logstorage.h                               **
*                                                                            **
*  TARGET    : linux                                                         **
*                                                                            **
*  PROJECT   : DLT                                                           **
*                                                                            **
*  AUTHOR    : Syed Hameed shameed@jp.adit-jv.com                            **
*              Christoph Lipka clipka@jp.adit-jv.com                         **
*  PURPOSE   :                                                               **
*                                                                            **
*  REMARKS   :                                                               **
*                                                                            **
*  PLATFORM DEPENDANT [yes/no]: yes                                          **
*                                                                            **
*  TO BE CHANGED BY USER [yes/no]: no                                        **
*                                                                            **
******************************************************************************/

/*******************************************************************************
*                      Author Identity                                       **
*******************************************************************************
*                                                                            **
* Initials     Name                       Company                            **
* --------     -------------------------  ---------------------------------- **
*  sh          Syed Hameed                ADIT                               **
*  cl          Christoph Lipka            ADIT                               **
 *******************************************************************************/
#ifndef DLT_DAEMON_OFFLINE_LOGSTORAGE_H
#define DLT_DAEMON_OFFLINE_LOGSTORAGE_H

#include "dlt-daemon.h"
#include "dlt_daemon_common.h"

#include "dlt_offline_logstorage.h"

#define DLT_DAEMON_LOGSTORAGE_RESET_LOGLEVEL            -1
#define DLT_DAEMON_LOGSTORAGE_RESET_SEND_LOGLEVEL        0

/**
 * dlt_daemon_logstorage_get_loglevel
 *
 * Obtain log level as a union of all configured storage devices and filters for the
 * provided application id and context id
 *
 * @param daemon        Pointer to DLT Daemon structure
 * @param max_device    Maximum storage devices setup by the daemon
 * @param apid          Application ID
 * @param ctid          Context ID
 * @return              Log level on success, -1 on error
 */
int dlt_daemon_logstorage_get_loglevel(DltDaemon *daemon, int max_device, char *apid, char *ctid);
/**
 * dlt_daemon_logstorage_reset_application_loglevel
 *
 * Reset storage log level of all running applications with -1
 *
 * @param daemon        Pointer to DLT Daemon structure
 * @param dev_num       Number of attached DLT Logstorage device
 * @param verbose       If set to true verbose information is printed out
 */
void dlt_daemon_logstorage_reset_application_loglevel(DltDaemon *daemon, int dev_num, int max_device, int verbose);
/**
 * dlt_daemon_logstorage_update_application_loglevel
 *
 * Update log level of all running applications with new filter configuration available due
 * to newly attached DltLogstorage device. The log level is only updated when the current
 * application log level is less than the log level obtained from the storage configuration file
 *
 * @param daemon        Pointer to DLT Daemon structure
 * @param dev_num       Number of attached DLT Logstorage device
 * @param verbose       if set to true verbose information is printed out
 */
void dlt_daemon_logstorage_update_application_loglevel(DltDaemon *daemon, int dev_num, int verbose);

/**
 * dlt_daemon_logstorage_write
 *
 * Write log message to all attached storage device. If the called dlt_logstorage_write function is not able
 * to write to the device, DltDaemon will disconnect this device.
 *
 * @param daemon        Pointer to Dlt Daemon structure
 * @param max_devices   number of configured storage devices
 * @param apid          application id
 * @param ctid          context id
 * @param log_level     log level
 * @param data1         message header buffer
 * @param size1         message header buffer size
 * @param data2         message data buffer
 * @param size2         message data size
 */
void dlt_daemon_logstorage_write(DltDaemon *daemon, int max_devices, unsigned char *data1, int size1, unsigned char *data2, int size2, unsigned char *data3, int size3);
#endif /* DLT_DAEMON_OFFLINE_LOGSTORAGE_H */
