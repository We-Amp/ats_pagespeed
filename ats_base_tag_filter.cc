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
#include "net/instaweb/rewriter/public/add_head_filter.h"
#include "net/instaweb/htmlparse/public/html_parse.h"
#include "net/instaweb/htmlparse/public/html_element.h"
#include <string>

#include <ts/ts.h>
#include "ats_base_tag_filter.h"

namespace net_instaweb {
  AtsBaseTagFilter::AtsBaseTagFilter(HtmlParse* parser) :
    parser_(parser)
  {
  }

  void AtsBaseTagFilter::StartElement(HtmlElement* element) {
    if (element->keyword() == HtmlName::kA || element->keyword() == HtmlName::kBase
        || element->keyword() == HtmlName::kForm|| element->keyword() == HtmlName::kImg
        || element->keyword() == HtmlName::kLink || element->keyword() == HtmlName::kScript) { 
      HtmlElement::AttributeList* attributes = element->mutable_attributes();
      for (HtmlElement::AttributeIterator i(attributes->begin());
	   i != attributes->end(); ++i) {

	HtmlElement::Attribute& attribute = *i;
	if (attribute.keyword() == HtmlName::kAction || attribute.keyword() == HtmlName::kHref 
	    || attribute.keyword() == HtmlName::kSrc) {
	  const char * attribute_value = NULL;
	  if ( attribute.DecodedValueOrNull() != NULL ) {
	    attribute_value = attribute.DecodedValueOrNull();
	  } else {
	    attribute_value = attribute.escaped_value();
	  }

	  if ( attribute_value != NULL) {
	    GoogleUrl url( attribute_value );
	    if (url.IsWebValid()) {
	      if (url.Host() == from_domain_) {
		StringPiece scheme = url.Scheme();
		StringPiece host = to_domain_.c_str();
		StringPiece pathAndQuery = url.PathAndLeaf();
		GoogleString rewritten = StrCat(scheme,"://", host, pathAndQuery);
		attribute.SetValue(rewritten.c_str());
		break;
	      }
	    }
	  }
	}   
      }
      

    }
  }
}  // namespace net_instaweb
