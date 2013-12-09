![ScreenShot](http://www.atsspeed.com/images/xATSSPEED_logo_plusshout_728x91.png.pagespeed.ic.8mRpu2PXS0.png
)

Apache Traffic Server web content optimization plugin powered by Google PageSpeed

The current state compiles against mod_pagspeed svn revision 3537
Please note the this plugin will generate asserts when build against
the debug version of mps (option->Merge from a different thread).

Work in progress! This plugin is known to be working on ubuntu 12.x (x64)

There are some hard-coded things in the plugin, so it expects:
- /tmp/ps_log/ to exist
- /tmp/ats_ps/ to exist

Configuration files go into `/usr/local/etc/trafficserver/psol.`
That folder is monitored, and changes to files in there are picked
up immediately. A sample configuration:

```
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

It also expects this in records.config from ATS to function:
`CONFIG proxy.config.url_remap.pristine_host_hdr INT 0`

You can view debug output of the plugin using `traffic_server -T ".*speed.*"`
