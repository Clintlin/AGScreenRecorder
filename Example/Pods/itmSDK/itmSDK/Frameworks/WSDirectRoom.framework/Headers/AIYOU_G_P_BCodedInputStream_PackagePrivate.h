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

// This header is private to the ProtobolBuffers library and must NOT be
// included by any sources outside this library. The contents of this file are
// subject to change at any time without notice.

#import "AIYOU_G_P_BCodedInputStream.h"

#import <libkern/OSAtomic.h>

@class AIYOU_G_P_BUnknownFieldSet;
@class AIYOU_G_P_BFieldDescriptor;

typedef struct AIYOU_G_P_BCodedInputStreamState {
  const uint8_t *bytes;
  size_t bufferSize;
  size_t bufferPos;

  // For parsing subsections of an input stream you can put a hard limit on
  // how much should be read. Normally the limit is the end of the stream,
  // but you can adjust it to anywhere, and if you hit it you will be at the
  // end of the stream, until you adjust the limit.
  size_t currentLimit;
  int32_t lastTag;
  NSUInteger recursionDepth;
} AIYOU_G_P_BCodedInputStreamState;

@interface AIYOU_G_P_BCodedInputStream () {
 @package
  struct AIYOU_G_P_BCodedInputStreamState state_;
  NSData *buffer_;
}

// Group support is deprecated, so we hide this interface from users, but
// support for older data.
- (void)readGroup:(int32_t)fieldNumber
              message:(AIYOU_G_P_BMessage *)message
    extensionRegistry:(AIYOU_G_P_BExtensionRegistry *)extensionRegistry;

// Reads a group field value from the stream and merges it into the given
// UnknownFieldSet.
- (void)readUnknownGroup:(int32_t)fieldNumber
                 message:(AIYOU_G_P_BUnknownFieldSet *)message;

// Reads a map entry.
- (void)readMapEntry:(id)mapDictionary
    extensionRegistry:(AIYOU_G_P_BExtensionRegistry *)extensionRegistry
                field:(AIYOU_G_P_BFieldDescriptor *)field
        parentMessage:(AIYOU_G_P_BMessage *)parentMessage;
@end

CF_EXTERN_C_BEGIN

int32_t AIYOU_G_P_BCodedInputStreamReadTag(AIYOU_G_P_BCodedInputStreamState *state);

double AIYOU_G_P_BCodedInputStreamReadDouble(AIYOU_G_P_BCodedInputStreamState *state);
float AIYOU_G_P_BCodedInputStreamReadFloat(AIYOU_G_P_BCodedInputStreamState *state);
uint64_t AIYOU_G_P_BCodedInputStreamReadUInt64(AIYOU_G_P_BCodedInputStreamState *state);
uint32_t AIYOU_G_P_BCodedInputStreamReadUInt32(AIYOU_G_P_BCodedInputStreamState *state);
int64_t AIYOU_G_P_BCodedInputStreamReadInt64(AIYOU_G_P_BCodedInputStreamState *state);
int32_t AIYOU_G_P_BCodedInputStreamReadInt32(AIYOU_G_P_BCodedInputStreamState *state);
uint64_t AIYOU_G_P_BCodedInputStreamReadFixed64(AIYOU_G_P_BCodedInputStreamState *state);
uint32_t AIYOU_G_P_BCodedInputStreamReadFixed32(AIYOU_G_P_BCodedInputStreamState *state);
int32_t AIYOU_G_P_BCodedInputStreamReadEnum(AIYOU_G_P_BCodedInputStreamState *state);
int32_t AIYOU_G_P_BCodedInputStreamReadSFixed32(AIYOU_G_P_BCodedInputStreamState *state);
int64_t AIYOU_G_P_BCodedInputStreamReadSFixed64(AIYOU_G_P_BCodedInputStreamState *state);
int32_t AIYOU_G_P_BCodedInputStreamReadSInt32(AIYOU_G_P_BCodedInputStreamState *state);
int64_t AIYOU_G_P_BCodedInputStreamReadSInt64(AIYOU_G_P_BCodedInputStreamState *state);
BOOL AIYOU_G_P_BCodedInputStreamReadBool(AIYOU_G_P_BCodedInputStreamState *state);
NSString *AIYOU_G_P_BCodedInputStreamReadRetainedString(AIYOU_G_P_BCodedInputStreamState *state)
    __attribute((ns_returns_retained));
NSData *AIYOU_G_P_BCodedInputStreamReadRetainedBytes(AIYOU_G_P_BCodedInputStreamState *state)
    __attribute((ns_returns_retained));
NSData *AIYOU_G_P_BCodedInputStreamReadRetainedBytesNoCopy(
    AIYOU_G_P_BCodedInputStreamState *state) __attribute((ns_returns_retained));

size_t AIYOU_G_P_BCodedInputStreamPushLimit(AIYOU_G_P_BCodedInputStreamState *state,
                                    size_t byteLimit);
void AIYOU_G_P_BCodedInputStreamPopLimit(AIYOU_G_P_BCodedInputStreamState *state,
                                 size_t oldLimit);
size_t AIYOU_G_P_BCodedInputStreamBytesUntilLimit(AIYOU_G_P_BCodedInputStreamState *state);
BOOL AIYOU_G_P_BCodedInputStreamIsAtEnd(AIYOU_G_P_BCodedInputStreamState *state);
void AIYOU_G_P_BCodedInputStreamCheckLastTagWas(AIYOU_G_P_BCodedInputStreamState *state,
                                        int32_t value);

CF_EXTERN_C_END
