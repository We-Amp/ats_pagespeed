/*
 * Copyright 2013 Google Inc.
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

// Author: Huibao Lin

#ifndef PAGESPEED_KERNEL_IMAGE_IMAGE_RESIZER_H_
#define PAGESPEED_KERNEL_IMAGE_IMAGE_RESIZER_H_

#include <cstddef>
#include "pagespeed/kernel/base/basictypes.h"
#include "pagespeed/kernel/base/scoped_ptr.h"
#include "pagespeed/kernel/image/scanline_interface.h"
#include "pagespeed/kernel/image/scanline_status.h"

namespace net_instaweb {
class MessageHandler;
}

namespace pagespeed {

namespace image_compression {

using net_instaweb::MessageHandler;

class ResizeRow;
class ResizeCol;

// Class ScanlineResizer resizes an image, and outputs a scanline at a time.
// To use it, you need to provide an initialized reader implementing
// ScanlineReaderInterface. The ScanlineResizer object will instruct the reader
// to fetch the image scanlines required for the resized scanline.
//
// You can specify the width, the height, or both in pixels. If you want to
// preserve the aspect ratio, you can specify only one of them, and pass in
// kPreserveAspectRatio for the other one.
//
// Currently, ScanlineResizer only supports shrinking. It works best when the
// image shrinks significantly, e.g, by more than 2x times.
//
class ScanlineResizer : public ScanlineReaderInterface {
 public:
  explicit ScanlineResizer(MessageHandler* handler);
  virtual ~ScanlineResizer();

  // Initialize the resizer. You must provide an initialized reader implementing
  // ScanlineReaderInterface. You can specify the width, the height, or both in
  // pixels. If you want to preserve the aspect ratio, you can specify only one
  // of them, and pass in kPreserveAspectRatio for the other one.
  //
  bool Initialize(ScanlineReaderInterface* reader,
                  size_t output_width,
                  size_t output_height);

  // Read the next available scanline. Returns false if the next scanline
  // is not available. This can happen when the reader cannot provide enough
  // image rows, or when all of the scanlines have been read.
  //
  virtual ScanlineStatus ReadNextScanlineWithStatus(void** out_scanline_bytes);

  // Reset the resizer to its initial state. Always returns true.
  virtual bool Reset();

  // Returns number of bytes required to store a scanline.
  virtual size_t GetBytesPerScanline() {
    return static_cast<size_t>(elements_per_row_);
  }

  // Returns true if there are more scanlines to read. Returns false if the
  // object has not been initialized or all of the scanlines have been read.
  virtual bool HasMoreScanLines() {
    return (row_ < height_);
  }

  // Returns the height of the image.
  virtual size_t GetImageHeight() {
    return static_cast<size_t>(height_);
  }

  // Returns the width of the image.
  virtual size_t GetImageWidth() {
    return static_cast<size_t>(width_);
  }

  // Returns the pixel format of the image.
  virtual PixelFormat GetPixelFormat() {
    return reader_->GetPixelFormat();
  }

  // This is a no-op and should not be called.
  virtual ScanlineStatus InitializeWithStatus(const void* image_buffer,
                                              size_t buffer_length);

  static const size_t kPreserveAspectRatio = 0;

 private:
  ScanlineReaderInterface* reader_;
  // Horizontal resizer.
  scoped_ptr<ResizeRow> resizer_x_;
  // Vertical resizer.
  scoped_ptr<ResizeCol> resizer_y_;

  net_instaweb::scoped_array<uint8> output_;
  int width_;
  int height_;
  int elements_per_row_;

  // TODO(huibao): Remove 'row_' and use 'resizer_y_->out_row_' instead.
  int row_;

  // Buffer for storing the intermediate results.
  net_instaweb::scoped_array<float> buffer_;
  int bytes_per_buffer_row_;
  MessageHandler* message_handler_;

  DISALLOW_COPY_AND_ASSIGN(ScanlineResizer);
};

}  // namespace image_compression

}  // namespace pagespeed

#endif  // PAGESPEED_KERNEL_IMAGE_IMAGE_RESIZER_H_
