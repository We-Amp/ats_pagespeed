/*
 * Copyright 2010 Google Inc.
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

// Author: sligocki@google.com (Shawn Ligocki)

#ifndef PAGESPEED_KERNEL_UTIL_FILENAME_ENCODER_H_
#define PAGESPEED_KERNEL_UTIL_FILENAME_ENCODER_H_

#include "pagespeed/kernel/base/string.h"
#include "pagespeed/kernel/base/string_util.h"

#include "pagespeed/kernel/util/url_to_filename_encoder.h"

namespace net_instaweb {

// TODO(morlovich): Remove this, and just use UrlToFilenameEncoder directly.
class FilenameEncoder {
 public:
  FilenameEncoder() {}
  ~FilenameEncoder();

  void Encode(const StringPiece& filename_prefix,
              const StringPiece& filename_ending,
              GoogleString* encoded_filename);

  bool Decode(const StringPiece& encoded_filename, GoogleString* decoded_url);
};

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_UTIL_FILENAME_ENCODER_H_
