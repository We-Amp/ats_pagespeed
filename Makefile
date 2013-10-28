TSXS?=tsxs
BUILDTYPE=Release
MOD_PAGESPEED_DIR=$(HOME)/code/google/mod_pagespeed/src/
PAGESPEED_OUT=$(MOD_PAGESPEED_DIR)out/$(BUILDTYPE)/

INC  = -I$(MOD_PAGESPEED_DIR)\
 -I$(MOD_PAGESPEED_DIR)third_party/chromium/src/\
 -I$(MOD_PAGESPEED_DIR)third_party/google-sparsehash/src\
 -I$(MOD_PAGESPEED_DIR)third_party/google-sparsehash/gen/arch/linux/x64/include\
 -I$(MOD_PAGESPEED_DIR)third_party/protobuf/src\
 -I$(MOD_PAGESPEED_DIR)third_party/re2/src\
 -I$(MOD_PAGESPEED_DIR)third_party/out/$(BUILDTYPE)/obj/gen\
 -I$(MOD_PAGESPEED_DIR)third_party/apr/src/include/\
 -I$(MOD_PAGESPEED_DIR)third_party/aprutil/src/include/\
 -I$(MOD_PAGESPEED_DIR)third_party/apr/gen/arch/linux/x64/include/\
 -I$(MOD_PAGESPEED_DIR)third_party/aprutil/gen/arch/linux/x64/include/\
 -I$(PAGESPEED_OUT)obj/gen/\
 -I$(PAGESPEED_OUT)obj/gen/protoc_out/instaweb/


# TODO(oschaaf): add in place resource recorder and console stuff
PSOL_SOURCES  = $(MOD_PAGESPEED_DIR)net/instaweb/system/add_headers_fetcher.cc\
 $(MOD_PAGESPEED_DIR)net/instaweb/system/loopback_route_fetcher.cc\
 $(MOD_PAGESPEED_DIR)net/instaweb/system/serf_url_async_fetcher.cc\
 $(MOD_PAGESPEED_DIR)out/$(BUILDTYPE)/obj/gen/data2c_out/instaweb/net/instaweb/apache/install/mod_pagespeed_example/mod_pagespeed_console_out.cc\
 $(MOD_PAGESPEED_DIR)out/$(BUILDTYPE)/obj/gen/data2c_out/instaweb/net/instaweb/apache/install/mod_pagespeed_example/mod_pagespeed_console_css_out.cc\
 $(MOD_PAGESPEED_DIR)out/$(BUILDTYPE)/obj/gen/data2c_out/instaweb/net/instaweb/apache/install/mod_pagespeed_example/mod_pagespeed_console_html_out.cc

PSOL_LIBS = $(MOD_PAGESPEED_DIR)net/instaweb/automatic/pagespeed_automatic.a\
 $(PAGESPEED_OUT)obj.target/third_party/serf/libserf.a\
 $(PAGESPEED_OUT)obj.target/third_party/aprutil/libaprutil.a\
 $(PAGESPEED_OUT)obj.target/third_party/apr/libapr.a

%.so: %.cc
	g++ $(INC) -g -pipe -Wall -Werror -O3 -fpic *.cc -c $(PSOL_SOURCES) 
	g++ -shared -g -o ats_speed.so *.o  -lstdc++ $(PSOL_LIBS) -lrt -pthread -lm

all: gzip/gzip.so ats_speed.so

install: all
	$(TSXS) -i -o ats_speed.so 
	cp gzip/gzip.so ./
	$(TSXS) -i -o zip.so 

clean:
	rm -f *.lo *.so *.o
