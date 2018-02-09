ifeq ($(PRODUCT_PLATFORM_SOD_LEGACY),true)

LOCAL_PATH := $(call my-dir)

include $(call all-makefiles-under,$(LOCAL_PATH))

endif
