// Copyright 2013 Google Inc. All Rights Reserved.
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

#ifndef PAGESPEED_KERNEL_HTTP_USER_AGENT_MATCHER_TEST_BASE_H_
#define PAGESPEED_KERNEL_HTTP_USER_AGENT_MATCHER_TEST_BASE_H_

#include "pagespeed/kernel/base/gtest.h"
#include "pagespeed/kernel/base/scoped_ptr.h"
#include "pagespeed/kernel/base/string_util.h"

namespace net_instaweb {

class UserAgentMatcher;

class UserAgentMatcherTestBase : public testing::Test {
 public:
  // User Agent strings are from http://www.useragentstring.com/.
  // IE: http://www.useragentstring.com/pages/Internet Explorer/
  // FireFox: http://www.useragentstring.com/pages/Firefox/
  // Chrome: http://www.useragentstring.com/pages/Chrome/
  // And there are many more.
  static const char kAcceptHeaderValueMobile[];
  static const char kAcceptHeaderValueNonMobile[];
  static const char kALCATELMobileUserAgent[];
  static const char kAlcatelUserAgent[];
  static const char kAmoiUserAgent[];
  static const char kAndroidChrome18UserAgent[];
  static const char kAndroidChrome21UserAgent[];
  static const char kAndroidHCUserAgent[];
  static const char kAndroidICSUserAgent[];
  static const char kAndroidNexusSUserAgent[];
  static const char kBenqUserAgent[];
  static const char kBlackBerryOS5UserAgent[];
  static const char kBlackBerryOS6UserAgent[];
  static const char kChrome12UserAgent[];
  static const char kChrome15UserAgent[];
  static const char kChrome18UserAgent[];
  static const char kChrome9UserAgent[];
  static const char kChromeUserAgent[];
  static const char kCompalUserAgent[];
  static const char kDoCoMoMobileUserAgent[];
  static const char kFirefox1UserAgent[];
  static const char kFirefox5UserAgent[];
  static const char kFirefoxNokiaN800[];
  static const char kFirefoxUserAgent[];
  static const char kFLYUserAgent[];
  static const char kGenericAndroidUserAgent[];
  static const char kGooglebotUserAgent[];
  static const char kGooglePlusUserAgent[];
  static const char kIe6UserAgent[];
  static const char kIe7UserAgent[];
  static const char kIe8UserAgent[];
  static const char kIe9UserAgent[];
  static const char kIPadTabletUserAgent[];
  static const char kIPadUserAgent[];
  static const char kIPhone4Safari[];
  static const char kIPhoneChrome21UserAgent[];
  static const char kIPhoneUserAgent[];
  static const char kIPodSafari[];
  static const char kiUserAgent[];
  static const char kJMobileUserAgent[];
  static const char kKDDIMobileUserAgent[];
  static const char kKindleTabletUserAgent[];
  static const char kKWCMobileUserAgent[];
  static const char kLENOVOUserAgent[];
  static const char kLGEMobileUserAgent[];
  static const char kLGEUserAgent[];
  static const char kLGMIDPMobileUserAgent[];
  static const char kLGUPBrowserMobileUserAgent[];
  static const char kLGUserAgent[];
  static const char kMOTMobileUserAgent[];
  static const char kMozillaMobileUserAgent[];
  static const char kMozillaUserAgent[];
  static const char kNECUserAgent[];
  static const char kNexus10ChromeUserAgent[];
  static const char kNexus7ChromeUserAgent[];
  static const char kNokiaMobileUserAgent[];
  static const char kNokiaUserAgent[];
  static const char kOpera1101UserAgent[];
  static const char kOpera1110UserAgent[];
  static const char kOpera5UserAgent[];
  static const char kOpera8UserAgent[];
  static const char kOperaMiniMobileUserAgent[];
  static const char kOperaMobi9[];
  static const char kOperaMobilMobileUserAgent[];
  static const char kPanasonicMobileUserAgent[];
  static const char kPGUserAgent[];
  static const char kPHILIPSUserAgent[];
  static const char kportalmmmMobileUserAgent[];
  static const char kPSPUserAgent[];
  static const char kRoverUserAgent[];
  static const char kSafariUserAgent[];
  static const char kSAGEMMobileUserAgent[];
  static const char kSAGEMUserAgent[];
  static const char kSAMSUNGMobileUserAgent[];
  static const char kSCHMobileUserAgent[];
  static const char kSCHUserAgent[];
  static const char kSECMobileUserAgent[];
  static const char kSGHUserAgent[];
  static const char kSHARPMobileUserAgent[];
  static const char kSHARPUserAgent[];
  static const char kSIEMobileUserAgent[];
  static const char kSIEUserAgent[];
  static const char kSilkDesktopUserAgent[];
  static const char kSilkTabletUserAgent[];
  static const char kSoftBankMobileUserAgent[];
  static const char kSpiceUserAgent[];
  static const char kTIANYUUserAgent[];
  static const char kVodafoneMobileUserAgent[];
  static const char kWinWAPUserAgent[];
  static const char kXWapProfile[];
  static const char kXWapProfileHeaderValue[];
  static const char kYourWapUserAgent[];
  static const char kZTEMobileUserAgent[];
  static const char XT907UserAgent[];
  static const char kTestingWebp[];
  static const char kTestingWebpLosslessAlpha[];

  static const char* const kMobileUserAgents[];
  static const char* const kDesktopUserAgents[];
  static const char* const kTabletUserAgents[];
  static const char* const kImageInliningSupportedUserAgents[];
  static const char* const kSplitHtmlSupportedUserAgents[];
  static const char* const kSplitHtmlUnSupportedUserAgents[];

  static const int kMobileUserAgentsArraySize;
  static const int kDesktopUserAgentsArraySize;
  static const int kTabletUserAgentsArraySize;
  static const int kImageInliningSupportedUserAgentsArraySize;
  static const int kSplitHtmlSupportedUserAgentsArraySize;
  static const int kSplitHtmlUnSupportedUserAgentsArraySize;

  UserAgentMatcherTestBase();
  virtual ~UserAgentMatcherTestBase() { }
  bool IsMobileUserAgent(const StringPiece& user_agent);
  bool IsDesktopUserAgent(const StringPiece& user_agent);
  bool IsTabletUserAgent(const StringPiece& user_agent);
  void VerifyGetDeviceTypeForUA();
  void VerifyImageInliningSupport();
  void VerifySplitHtmlSupport();

 protected:
  scoped_ptr<UserAgentMatcher> user_agent_matcher_;
};

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_HTTP_USER_AGENT_MATCHER_TEST_BASE_H_
