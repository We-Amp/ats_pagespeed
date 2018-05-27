/** @file

    A brief file description

    @section license License

    Licensed to the Apache Software Foundation (ASF) under one
    or more contributor license agreements.  See the NOTICE file
    distributed with this work for additional information
    regarding copyright ownership.  The ASF licenses this file
    to you under the Apache License, Version 2.0 (the
    "License"); you may not use this file except in compliance
    with the License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef ATS_REQUEST_CONTEXT_H
#define ATS_REQUEST_CONTEXT_H

#include <pagespeed/system/system_request_context.h>
#include <string>
#include <ts/ts.h>

namespace net_instaweb
{
  class AbstractMutex;
  class Timer;
  class AtsRequestContext : public SystemRequestContext
  {
  public:
    AtsRequestContext(AbstractMutex* logging_mutex,
                          Timer* timer,
                          StringPiece hostname,
                          int local_port,
                          StringPiece local_ip,
                          TSHttpTxn txn):
      SystemRequestContext(logging_mutex,
                           timer,
                           hostname,
                           local_port,
                           local_ip), _txn(txn) {
    }
    ~AtsRequestContext() {};

    TSHttpTxn txn() const { return _txn; }
  protected:
    TSHttpTxn _txn;
  };
}

#endif  // ATS_REQUEST_CONTEXT_H