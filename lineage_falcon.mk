#
# Copyright (C) 2016 The CyanogenMod Project
#               2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from falcon device
$(call inherit-product, device/motorola/falcon/device.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := falcon
PRODUCT_NAME := lineage_falcon
PRODUCT_BRAND := Motorola
PRODUCT_MODEL := Moto G
PRODUCT_MANUFACTURER := Motorola
PRODUCT_RELEASE_NAME := falcon
PRODUCT_SHIPPING_API_LEVEL := 19

PRODUCT_GMS_CLIENTID_BASE := android-motorola

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)
