#  Licensed to the Apache Software Foundation (ASF) under one
#  or more contributor license agreements.  See the NOTICE file
#  distributed with this work for additional information
#  regarding copyright ownership.  The ASF licenses this file
#  to you under the Apache License, Version 2.0 (the
#  "License"); you may not use this file except in compliance
#  with the License.  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

include $(top_srcdir)/build/plugins.mk
pkglib_LTLIBRARIES = ats_pagespeed.la

ats_pagespeed_la_SOURCES = \
 ats_base_fetch.cc \
 ats_beacon_intercept.cc \
 ats_config.cc \
 ats_header_utils.cc \
 ats_log_message_handler.cc \
 ats_message_handler.cc \
 ats_pagespeed.cc \
 ats_process_context.cc \
 ats_resource_intercept.cc \
 ats_rewrite_driver_factory.cc \
 ats_rewrite_options.cc \
 ats_server_context.cc

ats_pagespeed_la_LDFLAGS = $(TS_PLUGIN_LDFLAGS)
ats_pagespeed_ladir = ${includedir}/ats_pagespeed

#PSOL_BUILD_TYPE=Release
#PSOL_OS_NAME=linux
#PSOL_ARCH_NAME=x64

if BUILD_X64
PSOL_ARCH_NAME=x64
else
PSOL_ARCH_NAME=ia32
endif

PSOL_OS_NAME=linux
PSOL_BUILD_TYPE=Release


install-data-hook:
	cd psol/include; find . -type f -exec install  -D  {} $(includedir)/ats_pagespeed/psol/{}  \;
	cd psol/lib; find . -type f -name "*.a" -exec install -D {} ${libdir}/ats_pagespeed/psol/{} \;


PSOL_INCLUDE_DIR=psol/include
PSOL_INCLUDES=-I$(PSOL_INCLUDE_DIR)\
 -I$(PSOL_INCLUDE_DIR)/third_party/chromium/src/\
 -I$(PSOL_INCLUDE_DIR)/third_party/google-sparsehash/src\
 -I$(PSOL_INCLUDE_DIR)/third_party/google-sparsehash/gen/arch/$(PSOL_OS_NAME)/$(PSOL_ARCH_NAME)/include\
 -I$(PSOL_INCLUDE_DIR)/third_party/protobuf/src/src\
 -I$(PSOL_INCLUDE_DIR)/third_party/re2/src\
 -I$(PSOL_INCLUDE_DIR)/third_party/apr/src/include/\
 -I$(PSOL_INCLUDE_DIR)/third_party/aprutil/src/include/\
 -I$(PSOL_INCLUDE_DIR)/third_party/apr/gen/arch/$(PSOL_OS_NAME)/$(PSOL_ARCH_NAME)/include/\
 -I$(PSOL_INCLUDE_DIR)/third_party/aprutil/gen/arch/$(PSOL_OS_NAME)/$(PSOL_ARCH_NAME)/include \
 -I$(PSOL_INCLUDE_DIR)/out/$(PSOL_BUILD_TYPE)/obj/gen/protoc_out/instaweb \
 -I$(PSOL_INCLUDE_DIR)/out/$(PSOL_BUILD_TYPE)/obj/gen\
 -I$(PSOL_INCLUDE_DIR)/out/$(PSOL_BUILD_TYPE)/obj/gen/protoc_out/instaweb \
 -I$(PSOL_INCLUDE_DIR)/url

ats_pagespeed_la_CPPFLAGS = ${PSOL_INCLUDES} ${AM_CPPFLAGS}
ats_pagespeed_la_LIBADD=psol/lib/${PSOL_BUILD_TYPE}/${PSOL_OS_NAME}/${PSOL_ARCH_NAME}/pagespeed_automatic.a

1.11.33.4.tar.gz:
	wget --no-check-certificate https://dl.google.com/dl/page-speed/psol/1.11.33.4.tar.gz

psol: 1.11.33.4.tar.gz
	tar -xzvf 1.11.33.4.tar.gz
	touch psol

BUILT_SOURCES = psol
