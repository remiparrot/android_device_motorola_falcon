#!/vendor/bin/sh

# Alberto97's style
#
# Device configuration for falcon variants
#
PATH=/sbin:/vendor/sbin:/vendor/bin:/vendor/xbin
export PATH

radio=`getprop ro.boot.radio`
device=`getprop ro.product.device`

set_config_props ()
{
    case $radio in
        0x1 )
						if [[ -f "/dev/block/platform/msm_sdcc.1/by-name/metadata" ]]; then
								# xt1032 GPE
            		setprop ro.product.device "falcon_gpe"
            		setprop ro.build.description "falcon_gpe-user 5.1 LMY47M.M005 10 release-keys"
            		setprop ro.build.fingerprint "motorola/falcon_gpe/falcon_umts:5.1/LMY47M.M005/10:user/release-keys"
            		setprop ro.build.product "falcon_gpe"
						else
								# xt1032
								setprop ro.product.device "falcon_umts"
								setprop ro.build.description "falcon_retuglb-user 5.1 LPB23.13-58 58 release-keys"
								setprop ro.build.fingerprint "motorola/falcon_retuglb/falcon_umts:5.1/LPB23.13-58/58:user/release-keys"
								setprop ro.build.product "falcon_umts"
						fi
						setprop ro.mot.build.customerid "retusa_glb"
						setprop ro.telephony.default_network "0"
						setprop persist.radio.multisim.config ""
        ;;
				0x3 )
						carrier=`getprop ro.boot.carrier`
						case $carrier in
								"vzw")
										setprop ro.build.description "falcon_verizon-user 5.1 LPB23.13-33.7 7 release-keys"
										setprop ro.build.fingerprint "motorola/falcon_verizon/falcon_cdma:5.1/LPB23.13-33.7/7:user/release-keys"
										setprop ro.mot.build.customerid "verizon"
										setprop ro.cdma.home.operator.alpha "Verizon"
										setprop ro.cdma.home.operator.numeric "310004"
										setprop ro.com.google.clientidbase.ms "android-verizon"
										setprop ro.com.google.clientidbase.am "android-verizon"
										setprop ro.com.google.clientidbase.yt "android-verizon"
										setprop persist.radio.nw_mtu_enabled "true"
								;;
								"boost")
										setprop ro.build.description "falcon_boost-user 5.1 LPB23.13-56 55 release-keys"
										setprop ro.build.fingerprint "motorola/falcon_boost/falcon_cdma:5.1/LPB23.13-56/55:user/release-keys"
										setprop ro.mot.build.customerid "sprint"
										setprop ro.cdma.home.operator.alpha "Boost Mobile"
										setprop ro.cdma.home.operator.numeric "311870"
										setprop ro.com.google.clientidbase.ms "android-boost-us"
										setprop ro.com.google.clientidbase.am "android-boost-us"
										setprop ro.com.google.clientidbase.yt "android-boost-us"
								;;
								"usc")
										setprop ro.build.description "falcon_usc-user 5.1 LPB23.13-33.6 8 release-keys");
										setprop ro.build.fingerprint "motorola/falcon_usc/falcon_cdma:5.1/LPB23.13-33.6/8:user/release-keys");
										setprop ro.mot.build.customerid "usc"
										setprop ro.cdma.home.operator.numeric "311220"
										setprop gsm.sim.operator.numeric "311580"
										setprop ro.cdma.home.operator.alpha "U.S. Cellular"
										setprop ro.com.google.clientidbase.ms "android-uscellular-us"
										setprop ro.com.google.clientidbase.am "android-uscellular-us"
										setprop ro.com.google.clientidbase "android-motorola"
										setprop ro.com.google.clientidbase.gmm "android-motorola"
										setprop ro.com.google.clientidbase.yt "android-motorola"
								;;
								*)
									echo "Error: Unknown mobile carrier"
									return 1
								;;
						esac
						setprop ro.product.device "falcon_cdma"
						setprop ro.build.product "falcon_cdma"
						setprop ro.telephony.default_cdma_sub "1"
						setprop ro.telephony.default_network "4"
						setprop ro.telephony.gsm-routes-us-smsc "1"
						setprop persist.radio.vrte_logic "2"
						setprop persist.radio.0x9e_not_callname "1"
						setprop persist.radio.multisim.config ""
						setprop persist.radio.skip_data_check "1"
						setprop persist.ril.max.crit.qmi.fails "4"
						setprop persist.radio.call_type "1"
						setprop persist.radio.mode_pref_nv10 "1"
						setprop persist.radio.snapshot_timer "22"
						setprop persist.radio.snapshot_enabled "1"
						setprop ro.cdma.home.operator.isnan "1"
						setprop ro.cdma.otaspnumschema "SELC,1,80,99"
						setprop ro.cdma.data_retry_config "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000"
						setprop ro.gsm.data_retry_config "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000"
						setprop ro.mot.ignore_csim_appid "true"
						setprop telephony.lteOnCdmaDevice "0"
				;;
				0x5 )
						# xt1033
						setprop ro.product.device "falcon_umtsds"
						setprop ro.build.description "falcon_retbr_ds-user 5.1 LPB23.13-56 58 release-keys"
						setprop ro.build.fingerprint "motorola/falcon_retbr_ds/falcon_umtsds:5.1/LPB23.13-56/58:user/release-keys"
						setprop ro.build.product "falcon_umtsds"
						setprop ro.mot.build.customerid "RETBR"
						setprop ro.telephony.default_network "0,1"
						setprop ro.telephony.ril.config "simactivation,sim2gsmonly"
						setprop persist.radio.multisim.config "dsds"
						setprop persist.radio.dont_use_dsd "true"
						setprop persist.radio.plmn_name_cmp "1"
				;;
				0x6 )
						# xt1034
						setprop ro.product.device "falcon_umts"
						setprop ro.build.description "falcon_retuaws-user 5.1 LPB23.13-58 61 release-keys"
						setprop ro.build.fingerprint "motorola/falcon_retuaws/falcon_umts:5.1/LPB23.13-58/61:user/release-keys"
						setprop ro.build.product "falcon_umts"
						setprop ro.mot.build.customerid "retusa_aws"
						setprop ro.telephony.default_network "0"
						setprop persist.radio.multisim.config ""
				;;
    esac

		echo "Found radio id: $radio, setting build properties for $device device."
}

# Main
set_config_props

return 0
