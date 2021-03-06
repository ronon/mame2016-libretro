// license:GPL-2.0+
// copyright-holders:Couriersud
/*
 * nld_legacy.h
 *
 * All of the devices below needs to disappear at some time .....
 *
 *
 */

#pragma once

#ifndef NLD_LEGACY_H_
#define NLD_LEGACY_H_

#include "nl_base.h"

NETLIB_NAMESPACE_DEVICES_START()

// ----------------------------------------------------------------------------------------
// Macros
// ----------------------------------------------------------------------------------------

#define NETDEV_RSFF(_name)                                                          \
		NET_REGISTER_DEV(NETDEV_RSFF, _name)

#define NETDEV_DELAY(_name)                                                         \
		NET_REGISTER_DEV(NETDEV_DELAY, _name)

// ----------------------------------------------------------------------------------------
// Devices ...
// ----------------------------------------------------------------------------------------

NETLIB_OBJECT(nicRSFF)
{
	NETLIB_CONSTRUCTOR(nicRSFF)
	{
		enregister("S", m_S);
		enregister("R", m_R);
		enregister("Q", m_Q);
		enregister("QQ", m_QQ);
	}

	NETLIB_RESETI();
	NETLIB_UPDATEI();

protected:
	logic_input_t m_S;
	logic_input_t m_R;

	logic_output_t m_Q;
	logic_output_t m_QQ;
};


NETLIB_OBJECT(nicDelay)
{
	NETLIB_CONSTRUCTOR(nicDelay)
	, m_L_to_H(*this, "L_TO_H", 10)
	, m_H_to_L(*this, "H_TO_L", 10)
	, m_last(0)
	{
		enregister("1", m_I);
		enregister("2", m_Q);

		save(NLNAME(m_last));
	}

	//NETLIB_UPDATE_PARAMI();
	NETLIB_RESETI();
	NETLIB_UPDATEI();

protected:
	logic_input_t m_I;

	logic_output_t m_Q;

	param_int_t m_L_to_H;
	param_int_t m_H_to_L;

	UINT8 m_last;
};

NETLIB_NAMESPACE_DEVICES_END()

#endif /* NLD_LEGACY_H_ */
