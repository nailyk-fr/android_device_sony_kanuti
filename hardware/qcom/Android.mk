# Board platforms lists to be used for
# TARGET_BOARD_PLATFORM specific featurization
QCOM_BOARD_PLATFORMS += msm8952 msm8996 msm8998 sdm660

#List of targets that use video hw
MSM_VIDC_TARGET_LIST := msm8226 msm8916 msm8952 msm8974 msm8994 msm8996 msm8998 sdm660

#List of targets that use master side content protection
MASTER_SIDE_CP_TARGET_LIST := msm8996 msm8998 sdm660

TARGET_QCOM_AUDIO_VARIANT := caf
TARGET_QCOM_DISPLAY_VARIANT := caf
TARGET_QCOM_GPS_VARIANT := caf
TARGET_QCOM_MEDIA_VARIANT := caf

include device/sony/common-legacy/hardware/qcom/utils.mk

ifeq ($(BOARD_HAVE_BLUETOOTH_QCOM),true)
  include $(call all-makefiles-under,hardware/qcom/bt/msm8998)
endif
