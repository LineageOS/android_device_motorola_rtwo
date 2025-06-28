/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "lineage.touch@1.0-service.lge_msmnile"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "TouchscreenGesture.h"

using ::vendor::lineage::touch::V1_0::ITouchscreenGesture;
using ::vendor::lineage::touch::V1_0::implementation::TouchscreenGesture;

int main() {
    android::sp<ITouchscreenGesture> touchscreenGesture = new TouchscreenGesture();

    android::hardware::configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (touchscreenGesture->registerAsService() != android::OK) {
        LOG(ERROR) << "Cannot register touchscreen gesture HAL service.";
        return 1;
    }

    LOG(DEBUG) << "Touchscreen Gesture HAL service ready.";

    android::hardware::joinRpcThreadpool();

    LOG(ERROR) << "Touchscreen HAL Gesture service failed to join thread pool.";
    return 1;
}
