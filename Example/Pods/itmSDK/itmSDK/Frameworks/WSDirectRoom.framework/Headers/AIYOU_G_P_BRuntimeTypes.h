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

#import <Foundation/Foundation.h>

#import "AIYOU_G_P_BBootstrap.h"

@class AIYOU_G_P_BEnumDescriptor;
@class AIYOU_G_P_BMessage;
@class AIYOU_G_P_BInt32Array;

/**
 * Verifies that a given value can be represented by an enum type.
 * */
typedef BOOL (*AIYOU_G_P_BEnumValidationFunc)(int32_t);

/**
 * Fetches an EnumDescriptor.
 * */
typedef AIYOU_G_P_BEnumDescriptor *(*AIYOU_G_P_BEnumDescriptorFunc)(void);

/**
 * Magic value used at runtime to indicate an enum value that wasn't know at
 * compile time.
 * */
enum {
  kAIYOU_G_P_BUnrecognizedEnumeratorValue = (int32_t)0xFBADBEEF,
};

/**
 * A union for storing all possible Protobuf values. Note that owner is
 * responsible for memory management of object types.
 * */
typedef union {
  BOOL valueBool;
  int32_t valueInt32;
  int64_t valueInt64;
  uint32_t valueUInt32;
  uint64_t valueUInt64;
  float valueFloat;
  double valueDouble;
  AIYOU_G_P_B_UNSAFE_UNRETAINED NSData *valueData;
  AIYOU_G_P_B_UNSAFE_UNRETAINED NSString *valueString;
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *valueMessage;
  int32_t valueEnum;
} AIYOU_G_P_BGenericValue;

/**
 * Enum listing the possible data types that a field can contain.
 * 
 * @note Do not change the order of this enum (or add things to it) without
 *       thinking about it very carefully. There are several things that depend
 *       on the order.
 * */
typedef NS_ENUM(uint8_t, AIYOU_G_P_BDataType) {
  /** Field contains boolean value(s). */
  AIYOU_G_P_BDataTypeBool = 0,
  /** Field contains unsigned 4 byte value(s). */
  AIYOU_G_P_BDataTypeFixed32,
  /** Field contains signed 4 byte value(s). */
  AIYOU_G_P_BDataTypeSFixed32,
  /** Field contains float value(s). */
  AIYOU_G_P_BDataTypeFloat,
  /** Field contains unsigned 8 byte value(s). */
  AIYOU_G_P_BDataTypeFixed64,
  /** Field contains signed 8 byte value(s). */
  AIYOU_G_P_BDataTypeSFixed64,
  /** Field contains double value(s). */
  AIYOU_G_P_BDataTypeDouble,
  /**
   * Field contains variable length value(s). Inefficient for encoding negative
   * numbers – if your field is likely to have negative values, use
   * AIYOU_G_P_BDataTypeSInt32 instead.
   **/
  AIYOU_G_P_BDataTypeInt32,
  /**
   * Field contains variable length value(s). Inefficient for encoding negative
   * numbers – if your field is likely to have negative values, use
   * AIYOU_G_P_BDataTypeSInt64 instead.
   **/
  AIYOU_G_P_BDataTypeInt64,
  /** Field contains signed variable length integer value(s). */
  AIYOU_G_P_BDataTypeSInt32,
  /** Field contains signed variable length integer value(s). */
  AIYOU_G_P_BDataTypeSInt64,
  /** Field contains unsigned variable length integer value(s). */
  AIYOU_G_P_BDataTypeUInt32,
  /** Field contains unsigned variable length integer value(s). */
  AIYOU_G_P_BDataTypeUInt64,
  /** Field contains an arbitrary sequence of bytes. */
  AIYOU_G_P_BDataTypeBytes,
  /** Field contains UTF-8 encoded or 7-bit ASCII text. */
  AIYOU_G_P_BDataTypeString,
  /** Field contains message type(s). */
  AIYOU_G_P_BDataTypeMessage,
  /** Field contains message type(s). */
  AIYOU_G_P_BDataTypeGroup,
  /** Field contains enum value(s). */
  AIYOU_G_P_BDataTypeEnum,
};

enum {
  /**
   * A count of the number of types in AIYOU_G_P_BDataType. Separated out from the
   * AIYOU_G_P_BDataType enum to avoid warnings regarding not handling AIYOU_G_P_BDataType_Count
   * in switch statements.
   **/
  AIYOU_G_P_BDataType_Count = AIYOU_G_P_BDataTypeEnum + 1
};

/** An extension range. */
typedef struct AIYOU_G_P_BExtensionRange {
  /** Inclusive. */
  uint32_t start;
  /** Exclusive. */
  uint32_t end;
} AIYOU_G_P_BExtensionRange;
