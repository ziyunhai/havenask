/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>

#include "autil/Log.h"
#include "swift/common/Common.h"

namespace swift {
namespace common {
class FieldGroupReader;
} // namespace common
namespace filter {
class MsgFilter;
} // namespace filter
} // namespace swift

namespace swift {
namespace filter {

class DescFieldFilter {
public:
    DescFieldFilter();
    ~DescFieldFilter();

private:
    DescFieldFilter(const DescFieldFilter &);
    DescFieldFilter &operator=(const DescFieldFilter &);

public:
    bool init(const std::string &filterDesc);
    bool filterMsg(const common::FieldGroupReader &fieldGroupReader);

private:
    MsgFilter *_msgFilter;

private:
    AUTIL_LOG_DECLARE();
};

SWIFT_TYPEDEF_PTR(DescFieldFilter);

} // namespace filter
} // namespace swift
