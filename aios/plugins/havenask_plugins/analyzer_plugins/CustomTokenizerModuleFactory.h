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

#include "build_service/analyzer/TokenizerModuleFactory.h"
#include "build_service/config/ResourceReader.h"
#include "build_service/util/Log.h"

namespace build_service {
namespace analyzer {
class Tokenizer;
}  // namespace analyzer
}  // namespace build_service

namespace pluginplatform {
namespace analyzer_plugins {

class CustomTokenizerModuleFactory : public build_service::analyzer::TokenizerModuleFactory
{
    typedef CustomTokenizerModuleFactory _Super;
public:
    CustomTokenizerModuleFactory() {}
    virtual ~CustomTokenizerModuleFactory() {}

    /*override*/ virtual bool init(const build_service::KeyValueMap& parameters , const build_service::config::ResourceReaderPtr& resourceReader){
        return true;
    }

    /*override*/ virtual void destroy() { delete this; }

    /*override tokenizer*/
    virtual build_service::analyzer::Tokenizer* createTokenizer(const std::string& tokenizerType);

private:
    CustomTokenizerModuleFactory(const CustomTokenizerModuleFactory &);
    CustomTokenizerModuleFactory& operator=(const CustomTokenizerModuleFactory &);

private:
    BS_LOG_DECLARE();
};

}}
