/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * This contains the period callback functions for the periodic scheduler
 *
 * @warning
 * These callbacks should be used for hard real-time system, and the priority of these
 * tasks are above everything else in the system (above the PRIORITY_CRITICAL).
 * The period functions SHOULD NEVER block and SHOULD NEVER run over their time slot.
 * For example, the 1000Hz take slot runs periodically every 1ms, and whatever you
 * do must be completed within 1ms.  Running over the time slot will reset the system.
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "io.hpp"
#include "periodic_callback.h"
#include "gpio.hpp"
#include "eint.h"
#include "uart2.hpp"
#include "can.h"
/// This is the stack size used for each of the period tasks (1Hz, 10Hz, 100Hz, and 1000Hz)
const uint32_t PERIOD_TASKS_STACK_SIZE_BYTES = (512 * 4);

/**
 * This is the stack size of the dispatcher task that triggers the period tasks to run.
 * Minimum 1500 bytes are needed in order to write a debug file if the period tasks overrun.
 * This stack size is also used while calling the period_init() and period_reg_tlm(), and if you use
 * printf inside these functions, you need about 1500 bytes minimum
 */
const uint32_t PERIOD_DISPATCHER_TASK_STACK_SIZE_BYTES = (512 * 3);
// bool G_FLAG = 0;
// static int n_count;
// GPIO p20 (P2_0);
// static void intr_handler()
// {
//     printf("Interrupt\n");
//     G_FLAG = !G_FLAG;
// }

// static void bus_off(uint32_t can_num)
// {
// 	CAN_reset_bus(can_num);
// }
// static void data_ovr(uint32_t can_num)
// {
// 	CAN_reset_bus(can_num);
// }
/// Called once before the RTOS is started, this is a good place to initialize things once

// bool	can_func(void)
// {
// 	can_msg_t rx_msg;
// 	can_msg_t tx_msg;
// 	rx_msg.msg_id = 0x122;
// 	rx_msg.frame_fields.is_29bit = 1;
// 	rx_msg.frame_fields.data_len = 8;       // Send 8 bytes
// 	rx_msg.data.qword = 0x1122334455667788; // Write all 8 bytes of data at once

// 	tx_msg.msg_id = 0x125;
// 	tx_msg.frame_fields.is_29bit = 1;
// 	tx_msg.frame_fields.data_len = 8;       // Send 8 bytes
// 	tx_msg.data.qword = 0x1122334455667788;
// }
can_msg_t rx_msg;
can_msg_t tx_msg;
bool period_init(void)
{
	// Uart2 &u2 = Uart2::getInstance();

	// CAN_init(can_t can, uint32_t baudrate_kbps, uint16_t rxq_size, uint16_t txq_size,
		// can_void_func_t bus_off_cb, can_void_func_t data_ovr_cb);
	// CAN_init(can1, 500, 20, 20, bus_off, data_ovr);
	rx_msg.msg_id = 0x122;
	rx_msg.frame_fields.is_29bit = 1;
	rx_msg.frame_fields.data_len = 8;       // Send 8 bytes
	rx_msg.data.qword = 0x1122334455667788; // Write all 8 bytes of data at once

	tx_msg.msg_id = 0x125;
	tx_msg.frame_fields.is_29bit = 1;
	tx_msg.frame_fields.data_len = 8;       // Send 8 bytes
	tx_msg.data.qword = 0x1122334455667788;
	// CAN_tx(can_1, &msg, portMAX_DELAY);
	CAN_init(can1, 500, 20, 20, NULL, NULL);
	CAN_bypass_filter_accept_all_msgs();
	CAN_reset_bus(can1);
    return true; // Must return true upon success
}

/// Register any telemetry variables
bool period_reg_tlm(void)
{
    // Make sure "SYS_CFG_ENABLE_TLM" is enabled at sys_config.h to use Telemetry
    return true; // Must return true upon success
}

/**
 * Below are your periodic functions.
 * The argument 'count' is the number of times each periodic task is called.
 */
void period_1Hz(uint32_t count)
{
	if (CAN_is_bus_off(can1))
		CAN_reset_bus(can1);
}

void period_10Hz(uint32_t count)
{
	CAN_rx(can1, &rx_msg, 100);
	if (rx_msg.data.bytes[0] == 0xAA)
	{
		LE.toggle(4);
		CAN_tx(can1, &tx_msg, 100);
	}
}

void period_100Hz(uint32_t count)
{
  //  LE.toggle(3);
}

// 1Khz (1ms) is only run if Periodic Dispatcher was configured to run it at main():
// scheduler_add_task(new periodicSchedulerTask(run_1Khz = true));
void period_1000Hz(uint32_t count)
{
//    LE.toggle(4);
}
