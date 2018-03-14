ifeq ($(PRODUCT_PLATFORM_SOD_LEGACY),true)
ifeq (kanuti,$(PRODUCT_PLATFORM))

LOCAL_PATH := $(call my-dir)

include $(call all-makefiles-under,$(LOCAL_PATH))

endif
endif
