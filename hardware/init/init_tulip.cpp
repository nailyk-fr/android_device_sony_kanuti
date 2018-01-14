/*
 * Copyright (C) 2008 The Android Open Source Project
 * Copyright (C) 2014 The CyanogenMod Project
 * Copyright (C) 2018 Pavel Dubrova (Bart. Cubbins) <pashadubrova@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "util.h"

using android::init::property_set;
using android::init::import_kernel_cmdline;

void property_override(char const prop[], char const value[])
{
	prop_info *pi;

	pi = (prop_info*) __system_property_find(prop);
	if (pi)
		__system_property_update(pi, value, strlen(value));
	else
		__system_property_add(prop, strlen(prop), value, strlen(value));
}

static void import_kernel_nv(const std::string& key, const std::string& value,
				bool for_emulator __attribute__((unused)))
{
	if (key.empty())
		return;

	if (key == "oemandroidboot.phoneid") {
		//Dual Sim variant contains two IMEIs separated by comma.
		if ((count(value.begin(), value.end(),',')) > 0) {
			property_set("persist.multisim.config", "dsds");
			property_set("persist.radio.multisim.config", "dsds");
			property_override("ro.telephony.default_network", "9,1");
			property_override("ro.product.model", "Xperia M4 Aqua Dual (AOSP)");
		} else {
			// This property already set as default in common-prop.mk
			//property_set("ro.telephony.default_network", "9");
			property_override("ro.product.model", "Xperia M4 Aqua (AOSP)");
		}
	}
}

void vendor_load_properties()
{
	import_kernel_cmdline(0, import_kernel_nv);
}
