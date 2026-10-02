# ats_pagespeed

> **This repository is archived.** ats_pagespeed was an Apache Traffic Server
> plugin built on the PageSpeed Optimization Library. It was last changed in 2022
> and is unmaintained. PageSpeed itself is maintained again as
> [mod_pagespeed 2.1](https://github.com/We-Amp/mod_pagespeed), open source under
> the Apache License 2.0, with nginx, Apache httpd, IIS and Envoy integrations.
> That tree has no Apache Traffic Server integration.

## Where to go

| | |
|---|---|
| **Maintained source tree** (nginx, Apache httpd, IIS, Envoy) | [We-Amp/mod_pagespeed →](https://github.com/We-Amp/mod_pagespeed) |
| **Proxy-style deployment** | [Envoy integration (experimental) →](https://github.com/We-Amp/mod_pagespeed/blob/master/docs/install-envoy.md) or the [Docker reverse-proxy images →](https://modpagespeed.com/docs/installation-docker/) |
| **Documentation** | [modpagespeed.com/docs →](https://modpagespeed.com/docs/) |
| **Report a bug or ask a question** | [Open an issue →](https://github.com/We-Amp/mod_pagespeed/issues) |

The sources stay here, read-only, for reference.

---

## Historical README (unmaintained)

Apache Traffic Server web content optimization plugin powered by Google PageSpeed

To build, a simple 'make' should work. Use 'sudo make install' to install.
Optionally, patching ATS with ethread.patch helps with eliminating latency that 
sometimes gets induced when synchronising ATS's and PSOL's thread pools.

After that, update ATS's plugin.config with:
```
ats_pagespeed.so                                                                                 
gzip.so /usr/local/etc/trafficserver/gzip.config  
````
gzip.so also is build with ats_pagespeed, as it currently is a slightly
modified version of the official one from the ATS repository.

There are some hard-coded things in the plugin, these directories should exist:
- /tmp/ps_log/ to exist
- /tmp/ats_ps/ to exist

Configuration files go into `/ats-conf-dir/psol.`
That folder is monitored, and changes to files in there are picked
up immediately. A sample configuration:

```
# Base configuration for the module, all host-specific configuration
# will inherit. 
pagespeed RewriteLevel CoreFilters
# Mandatory FileCachePath setting. The path must exist and be read/write for the traffic_server process.
pagespeed FileCachePath /tmp/ats_pagespeed/
# [host]
[192.168.185.185]
# Force traffic server to cache all origin responses
override_expiry
pagespeed FlushHtml on
pagespeed RewriteLevel CoreFilters
pagespeed EnableFilters rewrite_domains,trim_urls
pagespeed MapRewriteDomain http://192.168.185.185 http://www.foo.com
pagespeed MapOriginDomain http://192.168.185.185 http://www.foo.com
pagespeed EnableFilters prioritize_critical_css,move_css_to_head,move_css_above_scripts
pagespeed EnableFilters fallback_rewrite_css_urls,insert_img_dimensions,lazyload_images,local_storage_cache
pagespeed EnableFilters prioritize_critical_css,rewrite_css
pagespeed EnableFilters combine_javascript,combine_css
```

You can view debug output of the plugin using `traffic_server -T ats_pagespeed`

The current state compiles against PSOL 1.13.35.2-stable


