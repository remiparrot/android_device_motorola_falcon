/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"

//#include "util.h"
using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    //std::string platform = GetProperty("ro.board.platform", "unknown");
    //if (platform != ANDROID_TARGET)
    //    return;

    property_override("ro.product.model", "Moto G");

    std::string radio = GetProperty("ro.boot.radio", "unknown");
    if (radio == "0x1") {
        if (access("/dev/block/platform/msm_sdcc.1/by-name/metadata", F_OK) != -1) {
            /* xt1032 GPE */
            property_override("ro.product.device", "falcon_gpe");
            property_override("ro.build.description", "falcon_gpe-user 5.1 LMY47M.M005 10 release-keys");
            property_override("ro.build.fingerprint", "motorola/falcon_gpe/falcon_umts:5.1/LMY47M.M005/10:user/release-keys");
            property_override("ro.build.product", "falcon_gpe");
            property_set("ro.mot.build.customerid", "retusa_glb");
            property_set("ro.telephony.default_network", "0");
            property_set("persist.radio.multisim.config", "");
        } else {
            /* xt1032 */
            property_override("ro.product.device", "falcon_umts");
            property_override("ro.build.description", "falcon_retuglb-user 5.1 LPB23.13-58 58 release-keys");
            property_override("ro.build.fingerprint", "motorola/falcon_retuglb/falcon_umts:5.1/LPB23.13-58/58:user/release-keys");
            property_override("ro.build.product", "falcon_umts");
            property_set("ro.mot.build.customerid", "retusa_glb");
            property_set("ro.telephony.default_network", "0");
            property_set("persist.radio.multisim.config", "");
        }
    } else if (radio == "0x3") {
        std::string carrier = GetProperty("ro.boot.carrier", "unknown");
        if (carrier == "vzw") {
            property_override("ro.build.description", "falcon_verizon-user 5.1 LPB23.13-33.7 7 release-keys");
            property_override("ro.build.fingerprint", "motorola/falcon_verizon/falcon_cdma:5.1/LPB23.13-33.7/7:user/release-keys");
            property_set("ro.mot.build.customerid", "verizon");
            property_set("ro.cdma.home.operator.alpha", "Verizon");
            property_set("ro.cdma.home.operator.numeric", "310004");
            property_set("ro.com.google.clientidbase.ms", "android-verizon");
            property_set("ro.com.google.clientidbase.am", "android-verizon");
            property_set("ro.com.google.clientidbase.yt", "android-verizon");
            property_set("persist.radio.nw_mtu_enabled", "true");
        } else if (carrier == "boost") {
            property_override("ro.build.description", "falcon_boost-user 5.1 LPB23.13-56 55 release-keys");
            property_override("ro.build.fingerprint", "motorola/falcon_boost/falcon_cdma:5.1/LPB23.13-56/55:user/release-keys");
            property_set("ro.mot.build.customerid", "sprint");
            property_set("ro.cdma.home.operator.alpha", "Boost Mobile");
            property_set("ro.cdma.home.operator.numeric", "311870");
            property_set("ro.com.google.clientidbase.ms", "android-boost-us");
            property_set("ro.com.google.clientidbase.am", "android-boost-us");
            property_set("ro.com.google.clientidbase.yt", "android-boost-us");
        } else if (carrier == "usc") {
            property_override("ro.build.description", "falcon_usc-user 5.1 LPB23.13-33.6 8 release-keys");
            property_override("ro.build.fingerprint", "motorola/falcon_usc/falcon_cdma:5.1/LPB23.13-33.6/8:user/release-keys");
            property_set("ro.mot.build.customerid", "usc");
            property_set("ro.cdma.home.operator.numeric", "311220");
            property_set("gsm.sim.operator.numeric", "311580");
            property_set("ro.cdma.home.operator.alpha", "U.S. Cellular");
            property_set("ro.com.google.clientidbase.ms", "android-uscellular-us");
            property_set("ro.com.google.clientidbase.am", "android-uscellular-us");
            property_set("ro.com.google.clientidbase", "android-motorola");
            property_set("ro.com.google.clientidbase.gmm", "android-motorola");
            property_set("ro.com.google.clientidbase.yt", "android-motorola");
        } else {
            //ERROR("Unknown mobile carrier");
        }
        property_override("ro.product.device", "falcon_cdma");
        property_override("ro.build.product", "falcon_cdma");
        property_set("ro.telephony.default_cdma_sub", "1");
        property_set("ro.telephony.default_network", "4");
        property_set("ro.telephony.gsm-routes-us-smsc", "1");
        property_set("persist.radio.vrte_logic", "2");
        property_set("persist.radio.0x9e_not_callname", "1");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.radio.skip_data_check", "1");
        property_set("persist.ril.max.crit.qmi.fails", "4");
        property_set("persist.radio.call_type", "1");
        property_set("persist.radio.mode_pref_nv10", "1");
        property_set("persist.radio.snapshot_timer", "22");
        property_set("persist.radio.snapshot_enabled", "1");
        property_set("ro.cdma.home.operator.isnan", "1");
        property_set("ro.cdma.otaspnumschema", "SELC,1,80,99");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("ro.mot.ignore_csim_appid", "true");
        property_set("telephony.lteOnCdmaDevice", "0");
    } else if (radio == "0x5") {
        /* xt1033 */
        property_override("ro.product.device", "falcon_umtsds");
        property_override("ro.build.description", "falcon_retbr_ds-user 5.1 LPB23.13-56 58 release-keys");
        property_override("ro.build.fingerprint", "motorola/falcon_retbr_ds/falcon_umtsds:5.1/LPB23.13-56/58:user/release-keys");
        property_override("ro.build.product", "falcon_umtsds");
        property_set("ro.mot.build.customerid", "RETBR");
        property_set("ro.telephony.default_network", "0,1");
        property_set("ro.telephony.ril.config", "simactivation,sim2gsmonly");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("persist.radio.plmn_name_cmp", "1");
    } else if (radio == "0x6") {
        /* xt1034 */
        property_override("ro.product.device", "falcon_umts");
        property_override("ro.build.description", "falcon_retuaws-user 5.1 LPB23.13-58 61 release-keys");
        property_override("ro.build.fingerprint", "motorola/falcon_retuaws/falcon_umts:5.1/LPB23.13-58/61:user/release-keys");
        property_override("ro.build.product", "falcon_umts");
        property_set("ro.mot.build.customerid", "retusa_aws");
        property_set("ro.telephony.default_network", "0");
        property_set("persist.radio.multisim.config", "");
    }

    std::string device = GetProperty("ro.product.device", "unknown");
    //INFO("Found radio id: %s, setting build properties for %s device\n", radio.c_str(), device.c_str());
}
