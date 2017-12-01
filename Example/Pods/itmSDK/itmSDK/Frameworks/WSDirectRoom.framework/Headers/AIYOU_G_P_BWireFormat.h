// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import "AIYOU_G_P_BRuntimeTypes.h"

CF_EXTERN_C_BEGIN

NS_ASSUME_NONNULL_BEGIN

typedef enum {
  AIYOU_G_P_BWireFormatVarint = 0,
  AIYOU_G_P_BWireFormatFixed64 = 1,
  AIYOU_G_P_BWireFormatLengthDelimited = 2,
  AIYOU_G_P_BWireFormatStartGroup = 3,
  AIYOU_G_P_BWireFormatEndGroup = 4,
  AIYOU_G_P_BWireFormatFixed32 = 5,
} AIYOU_G_P_BWireFormat;

enum {
  AIYOU_G_P_BWireFormatMessageSetItem = 1,
  AIYOU_G_P_BWireFormatMessageSetTypeId = 2,
  AIYOU_G_P_BWireFormatMessageSetMessage = 3
};

uint32_t AIYOU_G_P_BWireFormatMakeTag(uint32_t fieldNumber, AIYOU_G_P_BWireFormat wireType)
    __attribute__((const));
AIYOU_G_P_BWireFormat AIYOU_G_P_BWireFormatGetTagWireType(uint32_t tag) __attribute__((const));
uint32_t AIYOU_G_P_BWireFormatGetTagFieldNumber(uint32_t tag) __attribute__((const));
BOOL AIYOU_G_P_BWireFormatIsValidTag(uint32_t tag) __attribute__((const));

AIYOU_G_P_BWireFormat AIYOU_G_P_BWireFormatForType(AIYOU_G_P_BDataType dataType, BOOL isPacked)
    __attribute__((const));

#define AIYOU_G_P_BWireFormatMessageSetItemTag \
  (AIYOU_G_P_BWireFormatMakeTag(AIYOU_G_P_BWireFormatMessageSetItem, AIYOU_G_P_BWireFormatStartGroup))
#define AIYOU_G_P_BWireFormatMessageSetItemEndTag \
  (AIYOU_G_P_BWireFormatMakeTag(AIYOU_G_P_BWireFormatMessageSetItem, AIYOU_G_P_BWireFormatEndGroup))
#define AIYOU_G_P_BWireFormatMessageSetTypeIdTag \
  (AIYOU_G_P_BWireFormatMakeTag(AIYOU_G_P_BWireFormatMessageSetTypeId, AIYOU_G_P_BWireFormatVarint))
#define AIYOU_G_P_BWireFormatMessageSetMessageTag               \
  (AIYOU_G_P_BWireFormatMakeTag(AIYOU_G_P_BWireFormatMessageSetMessage, \
                        AIYOU_G_P_BWireFormatLengthDelimited))

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END
