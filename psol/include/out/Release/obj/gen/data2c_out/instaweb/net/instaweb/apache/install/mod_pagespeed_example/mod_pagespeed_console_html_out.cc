// Copyright 2011 Google Inc. All Rights Reserved.
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

// Automatically generated from ../../net/instaweb/genfiles/mod_pagespeed_console/mod_pagespeed_console.html

namespace net_instaweb {

const char* HTML_mod_pagespeed_console_body =
    "<!--\n   Copyright 2012 Google Inc.\n\n   Licensed under the Ap"
    "ache License, Version 2.0 (the \"License\");\n   you may not us"
    "e this file except in compliance with the License.\n   You ma"
    "y obtain a copy of the License at\n\n   http://www.apache.org/"
    "licenses/LICENSE-2.0\n\n   Unless required by applicable law o"
    "r agreed to in writing, software\n   distributed under the Li"
    "cense is distributed on an \"AS IS\" BASIS,\n   WITHOUT WARRANT"
    "IES OR CONDITIONS OF ANY KIND, either express or implied.\n  "
    " See the License for the specific language governing permiss"
    "ions and\n   limitations under the License.\n\n   @fileoverview"
    " Layout for the mod_pagespeed console.\n\n   @author joseanton"
    "io@google.com (Jose Antonio Martinez)\n   @author sarahdw@goo"
    "gle.com (Sarah Dapul-Weberman)\n   @author bvb@google.com (Be"
    "n VanBerkum)\n\n   Note: this file is combined with others dur"
    "ing the build process and should\n   only contain the body of"
    " the console HTML.\n-->\n\n<title>mod_pagespeed console</title>"
    "\n<div id=\"mod\" class=\"mod-container\">\n  <div id=\"mod-header\""
    " style=\"z-index:60;\">\n    <div class=\"mod-appname\">\n      <s"
    "pan>mod_pagespeed console</span>\n    </div>\n  </div>\n  <div "
    "id=\"mod-toolbar\"></div>\n  <div class=\"mod-widgetbar\">\n    <u"
    "l>\n      <li>\n        <span class=\"row\">\n          <a id=\"mo"
    "dal-launcher\" class=\"mod-button\" style=\"-webkit-user-select:"
    " none;\">+ Add Graph</a>\n        </span>\n      </li>\n      <l"
    "i>\n        <span class=\"row\">\n          <a id=\"auto-update\" "
    "class=\"mod-button\">Auto-Update Off</a>\n        </span>\n     "
    " </li>\n      <li class=\"last\">\n        <span class=\"row\">\n  "
    "        <a id=\"toggle-messages\" class=\"mod-button\">Show rece"
    "nt messages</a>\n        </span>\n      </li>\n    </ul>\n  </di"
    "v><!-- End widgetbar -->\n  <div id=\"mod-wrap\">\n    <div id=\""
    "mod-error\">There was an error updating the data.</div>\n    <"
    "div id=\"container\"></div>\n    <div class=\"mod-widgets errors"
    "\" id=\"messages-div\" style=\"display: none;\">\n      <div class"
    "=\"mod-widgets-topbar\">\n        <span class=\"title\" id=\"error"
    "-messages-title\">Recent Messages</span>\n      </div>\n      <"
    "div id=\"messages\"></div>\n    </div>\n  </div>\n  <!-- End mod-"
    "wrap -->\n  <div id=\"mod-footer\">\n    Copyright Google Inc, 2"
    "012\n  </div>\n  <div id=\"add-widget\" style=\"display: none;\">\n"
    "    <p>Show the following metric:<br/>\n      <select id=\"add"
    "-graph-list\"></select>\n    </p><br/>\n    <p id=\"mod-compare-"
    "with\">Compare with: <span class=\"optional\">(optional)</span>"
    "<br/>\n      <select id=\"add-graph-compare-list\"></select>\n  "
    "  </p>\n    <br/>\n    <p><b>Filter this data: </b>&nbsp;&nbsp"
    ";&nbsp;<a id=\"hide-filter\" style=\"display: none;\">Hide</a><b"
    "r/>\n      <a id=\"add-filter\">Add a Filter</a>\n      <span id"
    "=\"date-filter\" style=\"display: none;\">\n        <span id=\"sta"
    "rt-date-filter\">\n          Start Date: <span id=\"start-date\""
    "></span>&nbsp;&nbsp;&nbsp;<span class=\"mod-button\" id=\"start"
    "-date-calendar-button\"><img alt=\"Choose a date\" id=\"start-da"
    "te-calendar\"/></span><br/>\n        </span>\n\n        <span id"
    "=\"end-date-label\">End Date: </span><span id=\"end-date\"></spa"
    "n>&nbsp;&nbsp;&nbsp;<span class=\"mod-button\" id=\"end-date-ca"
    "lendar-button\"><img alt=\"Choose a date\" id=\"end-date-calenda"
    "r\"/></span><br/>\n        Granularity (s): <input type=\"numbe"
    "r\" id=\"granularity\" min=\"1\"/>\n      </span>\n    </p>\n    <br"
    "/>\n    <p><b>Widget Title</b><br/>\n      <input type=\"text\" "
    "id=\"widget-title\"/>\n    </p>\n  </div>\n\n  <div id=\"edit-widge"
    "t\" style=\"display: none;\">\n    <p>Show the following metric:"
    "<br/>\n      <select id=\"edit-graph-list\"></select>\n    </p>\n"
    "    <br/>\n     <p id=\"mod-compare-with-edit\">Compare with: <"
    "span class=\"optional\">(optional)</span><br/>\n      <select i"
    "d=\"edit-graph-compare-list\"></select>\n    </p>\n    <br/>\n   "
    " <p>Filter this data: &nbsp;&nbsp;&nbsp;<a id=\"hide-filter-e"
    "dit\" style=\"display: none;\">Hide</a><br/>\n      <a id=\"add-f"
    "ilter-edit\">Add a Filter</a>\n      <span id=\"date-filter-edi"
    "t\" style=\"display: none;\">\n        <span id=\"start-date-filt"
    "er-edit\">\n          Start Date: <span id=\"start-date-edit\"><"
    "/span>&nbsp;&nbsp;&nbsp;<span class=\"mod-button\" id=\"start-d"
    "ate-calendar-button-edit\"><img alt=\"Choose a date\" id=\"start"
    "-date-calendar-edit\"/></span><br/>\n        </span>\n\n        "
    "<span id=\"end-date-label-edit\">End Date: </span><span id=\"en"
    "d-date-edit\"></span>&nbsp;&nbsp;&nbsp;<span class=\"mod-butto"
    "n\" id=\"end-date-calendar-button-edit\"><img alt=\"Choose a dat"
    "e\" id=\"end-date-calendar-edit\"/></span><br/>\n        Granula"
    "rity (s): <input type=\"number\" id=\"granularity-edit\" min=\"1\""
    "/>\n      </span>\n    </p><br/>\n    <p><b>Widget Title</b><br"
    "/>\n      <input type=\"text\" id=\"widget-title-edit\" value=\"ti"
    "tle\"/>\n    </p>\n  </div>\n\n</div><!-- End container -->\n<scri"
    "pt type=\"text/javascript\" src=\"https://www.google.com/jsapi\""
    "></script>\n";

}  // namespace net_instaweb
