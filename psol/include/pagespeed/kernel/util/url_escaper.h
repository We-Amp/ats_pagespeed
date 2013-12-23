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

// Author: jmarantz@google.com (Joshua Marantz)

#ifndef PAGESPEED_KERNEL_UTIL_URL_ESCAPER_H_
#define PAGESPEED_KERNEL_UTIL_URL_ESCAPER_H_

#include "pagespeed/kernel/base/string.h"
#include "pagespeed/kernel/base/string_util.h"

namespace net_instaweb {

/*
common url format

  http://www.foo.bar/z1234/b_c.d?e=f&g=h

this suggests we should have short encodings for  a-zA-Z0-9.:/?&

We would like the above URL to be reasonably legible if possible.
However it's also nice if it's short.

One annoyance is that we are using '.' to delimit the 4 fields of an
instaweb-generated URL.  That can probably be changed to use ^, which
is a legal URL but is rarely used in URLs.  This would enable us to
leave . alone.  But that's probably a moderately painful change
involving a fair amount of regolding.

In the meantime we can replace . with ^ in this encoder so the they
don't change size.  So the transform table is:

a-zA-Z0-9_=+-&? unchanged
http://         ,h
%               ,P
/               ,_
\               ,-
,               ,
?               ,q
&               ,a

everything else ,XX  where xx are hex digits using capital latters


The intent of this class to to help encode arbitrary URLs (really, any
stream of 8-byte characters, but optimized for URLs) so that it can be
used in one 'segment' of a new URL.  This means we will not output
. or / but will instead escape those.
*/

namespace UrlEscaper {

void EncodeToUrlSegment(const StringPiece& in, GoogleString* url_segment);
bool DecodeFromUrlSegment(const StringPiece& url_segment, GoogleString* out);

}  // namespace UrlEscaper

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_UTIL_URL_ESCAPER_H_
