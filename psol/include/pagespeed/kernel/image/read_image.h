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

#ifndef PAGESPEED_KERNEL_IMAGE_READ_IMAGE_H_
#define PAGESPEED_KERNEL_IMAGE_READ_IMAGE_H_

#include <cstddef>
#include "pagespeed/kernel/base/string.h"
#include "pagespeed/kernel/image/scanline_interface.h"
#include "pagespeed/kernel/image/scanline_status.h"

namespace net_instaweb {
class MessageHandler;
}

namespace pagespeed {

namespace image_compression {

using net_instaweb::MessageHandler;

// TODO(huibao): Add an overload function
// CreateScanlineReader(const void* image_buffer, size_t buffer_length).

// Return a scanline image reader. The following formats are supported:
// IMAGE_PNG, IMAGE_GIF, IMAGE_JPEG, and IMAGE_WEBP
ScanlineReaderInterface* CreateScanlineReader(ImageFormat image_type,
                                              const void* image_buffer,
                                              size_t buffer_length,
                                              MessageHandler* handler,
                                              ScanlineStatus* status);

inline ScanlineReaderInterface* CreateScanlineReader(ImageFormat image_type,
                                                     const void* image_buffer,
                                                     size_t buffer_length,
                                                     MessageHandler* handler) {
  ScanlineStatus status;
  return CreateScanlineReader(image_type, image_buffer, buffer_length,
                              handler, &status);
}

// Return a scanline image writer. The following formats are supported:
// IMAGE_PNG, IMAGE_JPEG, and IMAGE_WEBP.
ScanlineWriterInterface* CreateScanlineWriter(
    ImageFormat image_type,     // Type of the image to write
    PixelFormat pixel_format,   // Pixel format, RGB_888 etc
    size_t width,               // Width, in pixels, of the image
    size_t height,              // Height, in pixels, of the image
    const void* config,         // Configuration for the output image
    GoogleString* image_data,   // Output image
    MessageHandler* handler,    // Message handler
    ScanlineStatus* status);    // Status code

inline ScanlineWriterInterface* CreateScanlineWriter(ImageFormat image_type,
                                                     PixelFormat pixel_format,
                                                     size_t width,
                                                     size_t height,
                                                     const void* config,
                                                     GoogleString* image_data,
                                                     MessageHandler* handler) {
  ScanlineStatus status;
  return CreateScanlineWriter(image_type, pixel_format, width, height,
                              config, image_data, handler, &status);
}

// Decode the image stream and return the image information. Use non-null
// pointers to retrieve the informatin you need, and use null pointers to
// ignore other information.
//
// If the input "pixels" is set to a null pointer, the function will finish
// quicker because the pixel data will not be decoded. If "pixel" is set to
// a non-null pointer, the function will return a buffer containning the pixel
// data. You are responsible for destroying the buffer using free().
//
// Arguments "width" and "height" indicate the number of pixels along the
// horizontal and vertical directions, respectively. Argument "stride" indicates
// the number of bytes between the starting points of adjacent rows. Garbage
// bytes may be padded to the end of rows in order to make "stride" a multiplier
// of 4.
bool ReadImage(ImageFormat image_type,
               const void* image_buffer,
               size_t buffer_length,
               void** pixels,
               PixelFormat* pixel_format,
               size_t* width,
               size_t* height,
               size_t* stride,
               MessageHandler* handler);

}  // namespace image_compression

}  // namespace pagespeed

#endif  // PAGESPEED_KERNEL_IMAGE_READ_IMAGE_H_
