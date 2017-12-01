// Protocol Buffers - Google's data interchange format
// Copyright 2016 Google Inc.  All rights reserved.
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

#import "AIYOU_G_P_BCodedOutputStream.h"

NS_ASSUME_NONNULL_BEGIN

CF_EXTERN_C_BEGIN

size_t AIYOU_G_P_BComputeDoubleSize(int32_t fieldNumber, double value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeFloatSize(int32_t fieldNumber, float value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeUInt64Size(int32_t fieldNumber, uint64_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeInt64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeInt32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeFixed64Size(int32_t fieldNumber, uint64_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeFixed32Size(int32_t fieldNumber, uint32_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeBoolSize(int32_t fieldNumber, BOOL value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeStringSize(int32_t fieldNumber, NSString *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeGroupSize(int32_t fieldNumber, AIYOU_G_P_BMessage *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeUnknownGroupSize(int32_t fieldNumber,
                                  AIYOU_G_P_BUnknownFieldSet *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeMessageSize(int32_t fieldNumber, AIYOU_G_P_BMessage *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeBytesSize(int32_t fieldNumber, NSData *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeUInt32Size(int32_t fieldNumber, uint32_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeSFixed32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeSFixed64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeSInt32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeSInt64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeTagSize(int32_t fieldNumber) __attribute__((const));
size_t AIYOU_G_P_BComputeWireFormatTagSize(int field_number, AIYOU_G_P_BDataType dataType)
    __attribute__((const));

size_t AIYOU_G_P_BComputeDoubleSizeNoTag(double value) __attribute__((const));
size_t AIYOU_G_P_BComputeFloatSizeNoTag(float value) __attribute__((const));
size_t AIYOU_G_P_BComputeUInt64SizeNoTag(uint64_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeInt64SizeNoTag(int64_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeInt32SizeNoTag(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeFixed64SizeNoTag(uint64_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeFixed32SizeNoTag(uint32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeBoolSizeNoTag(BOOL value) __attribute__((const));
size_t AIYOU_G_P_BComputeStringSizeNoTag(NSString *value) __attribute__((const));
size_t AIYOU_G_P_BComputeGroupSizeNoTag(AIYOU_G_P_BMessage *value) __attribute__((const));
size_t AIYOU_G_P_BComputeUnknownGroupSizeNoTag(AIYOU_G_P_BUnknownFieldSet *value)
    __attribute__((const));
size_t AIYOU_G_P_BComputeMessageSizeNoTag(AIYOU_G_P_BMessage *value) __attribute__((const));
size_t AIYOU_G_P_BComputeBytesSizeNoTag(NSData *value) __attribute__((const));
size_t AIYOU_G_P_BComputeUInt32SizeNoTag(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeEnumSizeNoTag(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeSFixed32SizeNoTag(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeSFixed64SizeNoTag(int64_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeSInt32SizeNoTag(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeSInt64SizeNoTag(int64_t value) __attribute__((const));

// Note that this will calculate the size of 64 bit values truncated to 32.
size_t AIYOU_G_P_BComputeSizeTSizeAsInt32NoTag(size_t value) __attribute__((const));

size_t AIYOU_G_P_BComputeRawVarint32Size(int32_t value) __attribute__((const));
size_t AIYOU_G_P_BComputeRawVarint64Size(int64_t value) __attribute__((const));

// Note that this will calculate the size of 64 bit values truncated to 32.
size_t AIYOU_G_P_BComputeRawVarint32SizeForInteger(NSInteger value)
    __attribute__((const));

// Compute the number of bytes that would be needed to encode a
// MessageSet extension to the stream.  For historical reasons,
// the wire format differs from normal fields.
size_t AIYOU_G_P_BComputeMessageSetExtensionSize(int32_t fieldNumber, AIYOU_G_P_BMessage *value)
    __attribute__((const));

// Compute the number of bytes that would be needed to encode an
// unparsed MessageSet extension field to the stream.  For
// historical reasons, the wire format differs from normal fields.
size_t AIYOU_G_P_BComputeRawMessageSetExtensionSize(int32_t fieldNumber, NSData *value)
    __attribute__((const));

size_t AIYOU_G_P_BComputeEnumSize(int32_t fieldNumber, int32_t value)
    __attribute__((const));

CF_EXTERN_C_END

NS_ASSUME_NONNULL_END
