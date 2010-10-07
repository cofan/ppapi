// Copyright (c) 2010 The Native Client Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/proxy/plugin_getinterface.h"

#include <string.h>

#include "ppapi/c/ppb_core.h"
#include "ppapi/proxy/plugin_core.h"
#include "ppapi/proxy/plugin_var.h"
#include "ppapi/proxy/utility.h"

namespace ppapi_proxy {

const void* GetInterfaceProxy(const char* interface_name) {
  // TODO(sehr): Ask the browser whether it supports an interface
  // before using it.  We will need an RPC for this.
  if (strcmp(interface_name, PPB_CORE_INTERFACE) == 0) {
    return PluginCore::GetInterface();
  } else if (strcmp(interface_name, PPB_VAR_DEPRECATED_INTERFACE) == 0) {
    return PluginVar::GetInterface();
  } else {
    return NULL;
  }
}

}  // namespace ppapi_proxy
