// Copyright 2010 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: jmarantz@google.com (Joshua Marantz)
//         lsong@google.com (Libo Song)

#ifndef NET_INSTAWEB_HTTP_PUBLIC_SYNC_FETCHER_ADAPTER_CALLBACK_H_
#define NET_INSTAWEB_HTTP_PUBLIC_SYNC_FETCHER_ADAPTER_CALLBACK_H_

#include "net/instaweb/http/public/async_fetch.h"
#include "net/instaweb/http/public/request_context.h"
#include "net/instaweb/util/public/basictypes.h"
#include "net/instaweb/util/public/scoped_ptr.h"
#include "net/instaweb/util/public/string_util.h"
#include "net/instaweb/util/public/thread_system.h"
#include "net/instaweb/util/public/writer.h"

namespace net_instaweb {

class MessageHandler;

// Class to help run an asynchronous fetch synchronously with a timeout.
class SyncFetcherAdapterCallback : public AsyncFetch {
 public:
  SyncFetcherAdapterCallback(ThreadSystem* thread_system, Writer* writer,
                             const RequestContextPtr& request_context);

  // When implementing a synchronous fetch with a timeout based on an
  // underlying asynchronous mechanism, we need to ensure that we don't
  // write to freed memory if the Done callback fires after the timeout.
  //
  // So we need to make sure the Writer and Response Buffers are owned
  // by this Callback class, which will forward the output and headers
  // to the caller *if* it has not been released by the time the callback
  // is called.
  //
  // If this object may be accessed from multiple threads (e.g. due to
  // async rewrites), you should use LockIfNotReleased() and Unlock()
  // to guard access to these.

  // When the 'owner' of this callback -- the code that calls 'new' --
  // is done with it, it can call Release(). That will arrange for the object
  // to be deleted as soon as it's safe to do so, which may be immediately
  // at the point of call, or from some asynchronous event.
  // The object should not be used by the owner after Release() has been called.
  void Release();

  bool IsDone() const;

  // Version of IsDone() that may only be called if you already hold the mutex.
  bool IsDoneLockHeld() const;
  bool success() const;
  bool released() const;

  // If this fetcher hasn't yet been Released(), returns true with mutex_ held.
  // Otherwise, returns false with the mutex_ released. These methods
  // should be used to guard accesses to writer() and response_headers().
  bool LockIfNotReleased();

  // Releases mutex acquired by a successful LockIfNotReleased() call.
  void Unlock();

  // Waits on condition variable associated with the mutex, with timeout
  // of timeout_ms. The wake up condition is Done() being called, but this
  // merely waits for lookup and does not ensure the condition has occurred ---
  // the caller should use a while loop conditioned on done_lock_held().
  // Should not be called if this callback is already released, and expects
  // mutex already held.
  void TimedWait(int64 timeout_ms);

 protected:
  virtual void HandleDone(bool success);
  virtual bool HandleWrite(const StringPiece& content,
                           MessageHandler* handler) {
    return writer_->Write(content, handler);
  }
  virtual bool HandleFlush(MessageHandler* handler) {
    return writer_->Flush(handler);
  }
  virtual void HandleHeadersComplete() {
  }

 private:
  virtual ~SyncFetcherAdapterCallback();

  scoped_ptr<ThreadSystem::CondvarCapableMutex> mutex_;
  scoped_ptr<ThreadSystem::Condvar> cond_;

  bool done_;
  bool success_;
  bool released_;
  scoped_ptr<Writer> writer_;

  DISALLOW_COPY_AND_ASSIGN(SyncFetcherAdapterCallback);
};

}  // namespace net_instaweb

#endif  // NET_INSTAWEB_HTTP_PUBLIC_SYNC_FETCHER_ADAPTER_CALLBACK_H_
