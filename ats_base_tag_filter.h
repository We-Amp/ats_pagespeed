// Copyright 2013 We-Amp B.V.
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
//
// Author: oschaaf@we-amp.com (Otto van der Schaaf)
#ifndef ATS_BASE_TAG_FILTER_H_
#define ATS_BASE_TAG_FILTER_H_

#include "base/basictypes.h"
#include "base/string_piece.h"
#include "net/instaweb/htmlparse/public/empty_html_filter.h"
#include "net/instaweb/util/public/atom.h"
#include "net/instaweb/htmlparse/public/html_parse.h"
#include "net/instaweb/htmlparse/public/html_element.h"
#include <string>

using base::StringPiece;

namespace net_instaweb {
  
  class AtsBaseTagFilter : public EmptyHtmlFilter {
  public:
    explicit AtsBaseTagFilter(HtmlParse* parser);
    virtual void StartElement(HtmlElement* element);
    virtual const char* Name() const { return "AtsBaseTag"; }
    // TODO: move to constructor?!
    void set_domains(const StringPiece& to_domain, const StringPiece& from_domain) 
    { 
      to_domain.CopyToString(&to_domain_); 
      from_domain.CopyToString(&from_domain_); 
    }

  private:
    std::string to_domain_;
    std::string from_domain_;
    HtmlParse* parser_;

    DISALLOW_COPY_AND_ASSIGN(AtsBaseTagFilter);
  };

}  // namespace net_instaweb

#endif  // ATS_BASE_TAG_FILTER_H_
