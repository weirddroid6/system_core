/*
 * Copyright (C) 2019 The Android Open Source Project
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

#pragma once

#include <android/adbroot/BnADBRootService.h>
#include <binder/BinderService.h>

namespace android {
namespace adbroot {

class ADBRootService : public BinderService<ADBRootService>, public BnADBRootService {
  public:
    ADBRootService();

    static void Register();

    binder::Status setEnabled(bool enabled) override;
    binder::Status getEnabled(bool* _aidl_return) override;

    static char const* getServiceName() { return "adbroot_service"; }
  private:
    bool enabled_;
};

}  // namespace adbroot
}  // namespace android
