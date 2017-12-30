/******************************************************************************
 *
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2008 - 2014 Intel Corporation. All rights reserved.
 * Copyright(c) 2015 Intel Mobile Communications GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,
 * USA
 *
 * The full GNU General Public License is included in this distribution
 * in the file called COPYING.
 *
 * Contact Information:
 *  Intel Linux Wireless <linuxwifi@intel.com>
 * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497
 *
 * BSD LICENSE
 *
 * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.
 * Copyright(c) 2015 Intel Mobile Communications GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name Intel Corporation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#ifndef __iwl_eeprom_parse_h__
#define __iwl_eeprom_parse_h__

#include <net/cfg80211.h>

#define ETH_ALEN 6

struct iwl_nvm_data {
    int n_hw_addrs;
    UInt8 hw_addr[ETH_ALEN];
    
    UInt8 calib_version;
    UInt16 calib_voltage;
    
    UInt16 raw_temperature;
    UInt16 kelvin_temperature;
    UInt16 kelvin_voltage;
    UInt16 xtal_calib[2];
    
    bool sku_cap_band_24GHz_enable;
    bool sku_cap_band_52GHz_enable;
    bool sku_cap_11n_enable;
    bool sku_cap_11ac_enable;
    bool sku_cap_amt_enable;
    bool sku_cap_ipan_enable;
    bool sku_cap_mimo_disabled;
    
    UInt16 radio_cfg_type;
    UInt8 radio_cfg_step;
    UInt8 radio_cfg_dash;
    UInt8 radio_cfg_pnum;
    UInt8 valid_tx_ant, valid_rx_ant;
    
    UInt32 nvm_version;
    SInt8 max_tx_pwr_half_dbm;
    
    bool lar_enabled;
    bool vht160_supported;
    struct ieee80211_supported_band bands[NUM_NL80211_BANDS];
    struct ieee80211_channel channels[];
};

/* calibration */
struct iwl_eeprom_calib_hdr {
    UInt8 version;
    UInt8 pa_type;
    UInt16 voltage;
} __attribute__((packed));

#endif /* __iwl_eeprom_parse_h__ */
