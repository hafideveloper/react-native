/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "Registration.h"
#include "ConnectionDemux.h"

namespace facebook {
namespace hermes {
namespace inspector_modern {
namespace chrome {

namespace {

ConnectionDemux &demux() {
  static ConnectionDemux instance{facebook::react::getInspectorInstance()};
  return instance;
}

} // namespace

DebugSessionToken enableDebugging(
    std::unique_ptr<RuntimeAdapter> adapter,
    const std::string &title) {
  return demux().enableDebugging(std::move(adapter), title);
}

void disableDebugging(DebugSessionToken session) {
  demux().disableDebugging(session);
}

} // namespace chrome
} // namespace inspector_modern
} // namespace hermes
} // namespace facebook
