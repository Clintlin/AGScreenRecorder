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

#import "AIYOU_G_P_BUtilities.h"

#import "AIYOU_G_P_BDescriptor_PackagePrivate.h"

// Macros for stringifying library symbols. These are used in the generated
// PB descriptor classes wherever a library symbol name is represented as a
// string. See README.google for more information.
#define AIYOU_G_P_BStringify(S) #S
#define AIYOU_G_P_BStringifySymbol(S) AIYOU_G_P_BStringify(S)

#define AIYOU_G_P_BNSStringify(S) @#S
#define AIYOU_G_P_BNSStringifySymbol(S) AIYOU_G_P_BNSStringify(S)

// Constant to internally mark when there is no has bit.
#define AIYOU_G_P_BNoHasBit INT32_MAX

CF_EXTERN_C_BEGIN

// These two are used to inject a runtime check for version mismatch into the
// generated sources to make sure they are linked with a supporting runtime.
void AIYOU_G_P_BCheckRuntimeVersionSupport(int32_t objcRuntimeVersion);
AIYOU_G_P_B_INLINE void AIYOU_G_P_B_DEBUG_CHECK_RUNTIME_VERSIONS() {
  // NOTE: By being inline here, this captures the value from the library's
  // headers at the time the generated code was compiled.
#if defined(DEBUG) && DEBUG
  AIYOU_G_P_BCheckRuntimeVersionSupport(GOOGLE_PROTOBUF_OBJC_VERSION);
#endif
}

// Legacy version of the checks, remove when GOOGLE_PROTOBUF_OBJC_GEN_VERSION
// goes away (see more info in AIYOU_G_P_BBootstrap.h).
void AIYOU_G_P_BCheckRuntimeVersionInternal(int32_t version);
AIYOU_G_P_B_INLINE void AIYOU_G_P_BDebugCheckRuntimeVersion() {
#if defined(DEBUG) && DEBUG
  AIYOU_G_P_BCheckRuntimeVersionInternal(GOOGLE_PROTOBUF_OBJC_GEN_VERSION);
#endif
}

// Conversion functions for de/serializing floating point types.

AIYOU_G_P_B_INLINE int64_t AIYOU_G_P_BConvertDoubleToInt64(double v) {
  union { double f; int64_t i; } u;
  u.f = v;
  return u.i;
}

AIYOU_G_P_B_INLINE int32_t AIYOU_G_P_BConvertFloatToInt32(float v) {
  union { float f; int32_t i; } u;
  u.f = v;
  return u.i;
}

AIYOU_G_P_B_INLINE double AIYOU_G_P_BConvertInt64ToDouble(int64_t v) {
  union { double f; int64_t i; } u;
  u.i = v;
  return u.f;
}

AIYOU_G_P_B_INLINE float AIYOU_G_P_BConvertInt32ToFloat(int32_t v) {
  union { float f; int32_t i; } u;
  u.i = v;
  return u.f;
}

AIYOU_G_P_B_INLINE int32_t AIYOU_G_P_BLogicalRightShift32(int32_t value, int32_t spaces) {
  return (int32_t)((uint32_t)(value) >> spaces);
}

AIYOU_G_P_B_INLINE int64_t AIYOU_G_P_BLogicalRightShift64(int64_t value, int32_t spaces) {
  return (int64_t)((uint64_t)(value) >> spaces);
}

// Decode a ZigZag-encoded 32-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
AIYOU_G_P_B_INLINE int32_t AIYOU_G_P_BDecodeZigZag32(uint32_t n) {
  return (int32_t)(AIYOU_G_P_BLogicalRightShift32((int32_t)n, 1) ^ -((int32_t)(n) & 1));
}

// Decode a ZigZag-encoded 64-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
AIYOU_G_P_B_INLINE int64_t AIYOU_G_P_BDecodeZigZag64(uint64_t n) {
  return (int64_t)(AIYOU_G_P_BLogicalRightShift64((int64_t)n, 1) ^ -((int64_t)(n) & 1));
}

// Encode a ZigZag-encoded 32-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
AIYOU_G_P_B_INLINE uint32_t AIYOU_G_P_BEncodeZigZag32(int32_t n) {
  // Note:  the right-shift must be arithmetic
  return (uint32_t)((n << 1) ^ (n >> 31));
}

// Encode a ZigZag-encoded 64-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
AIYOU_G_P_B_INLINE uint64_t AIYOU_G_P_BEncodeZigZag64(int64_t n) {
  // Note:  the right-shift must be arithmetic
  return (uint64_t)((n << 1) ^ (n >> 63));
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BDataTypeIsObject(AIYOU_G_P_BDataType type) {
  switch (type) {
    case AIYOU_G_P_BDataTypeBytes:
    case AIYOU_G_P_BDataTypeString:
    case AIYOU_G_P_BDataTypeMessage:
    case AIYOU_G_P_BDataTypeGroup:
      return YES;
    default:
      return NO;
  }
}

AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BDataTypeIsMessage(AIYOU_G_P_BDataType type) {
  switch (type) {
    case AIYOU_G_P_BDataTypeMessage:
    case AIYOU_G_P_BDataTypeGroup:
      return YES;
    default:
      return NO;
  }
}

AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BFieldDataTypeIsMessage(AIYOU_G_P_BFieldDescriptor *field) {
  return AIYOU_G_P_BDataTypeIsMessage(field->description_->dataType);
}

AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BFieldDataTypeIsObject(AIYOU_G_P_BFieldDescriptor *field) {
  return AIYOU_G_P_BDataTypeIsObject(field->description_->dataType);
}

AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BExtensionIsMessage(AIYOU_G_P_BExtensionDescriptor *ext) {
  return AIYOU_G_P_BDataTypeIsMessage(ext->description_->dataType);
}

// The field is an array/map or it has an object value.
AIYOU_G_P_B_INLINE BOOL AIYOU_G_P_BFieldStoresObject(AIYOU_G_P_BFieldDescriptor *field) {
  AIYOU_G_P_BMessageFieldDescription *desc = field->description_;
  if ((desc->flags & (AIYOU_G_P_BFieldRepeated | AIYOU_G_P_BFieldMapKeyMask)) != 0) {
    return YES;
  }
  return AIYOU_G_P_BDataTypeIsObject(desc->dataType);
}

BOOL AIYOU_G_P_BGetHasIvar(AIYOU_G_P_BMessage *self, int32_t index, uint32_t fieldNumber);
void AIYOU_G_P_BSetHasIvar(AIYOU_G_P_BMessage *self, int32_t idx, uint32_t fieldNumber,
                   BOOL value);
uint32_t AIYOU_G_P_BGetHasOneof(AIYOU_G_P_BMessage *self, int32_t index);

AIYOU_G_P_B_INLINE BOOL
AIYOU_G_P_BGetHasIvarField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field) {
  AIYOU_G_P_BMessageFieldDescription *fieldDesc = field->description_;
  return AIYOU_G_P_BGetHasIvar(self, fieldDesc->hasIndex, fieldDesc->number);
}
AIYOU_G_P_B_INLINE void AIYOU_G_P_BSetHasIvarField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field,
                                   BOOL value) {
  AIYOU_G_P_BMessageFieldDescription *fieldDesc = field->description_;
  AIYOU_G_P_BSetHasIvar(self, fieldDesc->hasIndex, fieldDesc->number, value);
}

void AIYOU_G_P_BMaybeClearOneof(AIYOU_G_P_BMessage *self, AIYOU_G_P_BOneofDescriptor *oneof,
                        int32_t oneofHasIndex, uint32_t fieldNumberNotToClear);

#pragma clang diagnostic pop

//%PDDM-DEFINE AIYOU_G_P_B_IVAR_SET_DECL(NAME, TYPE)
//%void AIYOU_G_P_BSet##NAME##IvarWithFieldInternal(AIYOU_G_P_BMessage *self,
//%            NAME$S                     AIYOU_G_P_BFieldDescriptor *field,
//%            NAME$S                     TYPE value,
//%            NAME$S                     AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Bool, BOOL)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetBoolIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                     AIYOU_G_P_BFieldDescriptor *field,
                                     BOOL value,
                                     AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Int32, int32_t)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetInt32IvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                      AIYOU_G_P_BFieldDescriptor *field,
                                      int32_t value,
                                      AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(UInt32, uint32_t)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetUInt32IvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                       AIYOU_G_P_BFieldDescriptor *field,
                                       uint32_t value,
                                       AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Int64, int64_t)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetInt64IvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                      AIYOU_G_P_BFieldDescriptor *field,
                                      int64_t value,
                                      AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(UInt64, uint64_t)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetUInt64IvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                       AIYOU_G_P_BFieldDescriptor *field,
                                       uint64_t value,
                                       AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Float, float)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetFloatIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                      AIYOU_G_P_BFieldDescriptor *field,
                                      float value,
                                      AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Double, double)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetDoubleIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                       AIYOU_G_P_BFieldDescriptor *field,
                                       double value,
                                       AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND AIYOU_G_P_B_IVAR_SET_DECL(Enum, int32_t)
// This block of code is generated, do not edit it directly.

void AIYOU_G_P_BSetEnumIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                     AIYOU_G_P_BFieldDescriptor *field,
                                     int32_t value,
                                     AIYOU_G_P_BFileSyntax syntax);
//%PDDM-EXPAND-END (8 expansions)

int32_t AIYOU_G_P_BGetEnumIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                        AIYOU_G_P_BFieldDescriptor *field,
                                        AIYOU_G_P_BFileSyntax syntax);

id AIYOU_G_P_BGetObjectIvarWithField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

void AIYOU_G_P_BSetObjectIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                       AIYOU_G_P_BFieldDescriptor *field, id value,
                                       AIYOU_G_P_BFileSyntax syntax);
void AIYOU_G_P_BSetRetainedObjectIvarWithFieldInternal(AIYOU_G_P_BMessage *self,
                                               AIYOU_G_P_BFieldDescriptor *field,
                                               id __attribute__((ns_consumed))
                                               value,
                                               AIYOU_G_P_BFileSyntax syntax);

// AIYOU_G_P_BGetObjectIvarWithField will automatically create the field (message) if
// it doesn't exist. AIYOU_G_P_BGetObjectIvarWithFieldNoAutocreate will return nil.
id AIYOU_G_P_BGetObjectIvarWithFieldNoAutocreate(AIYOU_G_P_BMessage *self,
                                         AIYOU_G_P_BFieldDescriptor *field);

void AIYOU_G_P_BSetAutocreatedRetainedObjectIvarWithField(
    AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field,
    id __attribute__((ns_consumed)) value);

// Clears and releases the autocreated message ivar, if it's autocreated. If
// it's not set as autocreated, this method does nothing.
void AIYOU_G_P_BClearAutocreatedMessageIvarWithField(AIYOU_G_P_BMessage *self,
                                             AIYOU_G_P_BFieldDescriptor *field);

// Returns an Objective C encoding for |selector|. |instanceSel| should be
// YES if it's an instance selector (as opposed to a class selector).
// |selector| must be a selector from MessageSignatureProtocol.
const char *AIYOU_G_P_BMessageEncodingForSelector(SEL selector, BOOL instanceSel);

// Helper for text format name encoding.
// decodeData is the data describing the sepecial decodes.
// key and inputString are the input that needs decoding.
NSString *AIYOU_G_P_BDecodeTextFormatName(const uint8_t *decodeData, int32_t key,
                                  NSString *inputString);

// A series of selectors that are used solely to get @encoding values
// for them by the dynamic protobuf runtime code. See
// AIYOU_G_P_BMessageEncodingForSelector for details.
@protocol AIYOU_G_P_BMessageSignatureProtocol
@optional

#define AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(TYPE, NAME) \
  -(TYPE)get##NAME;                             \
  -(void)set##NAME : (TYPE)value;               \
  -(TYPE)get##NAME##AtIndex : (NSUInteger)index;

AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(BOOL, Bool)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(uint32_t, Fixed32)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int32_t, SFixed32)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(float, Float)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(uint64_t, Fixed64)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int64_t, SFixed64)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(double, Double)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int32_t, Int32)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int64_t, Int64)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int32_t, SInt32)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int64_t, SInt64)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(uint32_t, UInt32)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(uint64_t, UInt64)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(NSData *, Bytes)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(NSString *, String)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(AIYOU_G_P_BMessage *, Message)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(AIYOU_G_P_BMessage *, Group)
AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY(int32_t, Enum)

#undef AIYOU_G_P_B_MESSAGE_SIGNATURE_ENTRY

- (id)getArray;
- (NSUInteger)getArrayCount;
- (void)setArray:(NSArray *)array;
+ (id)getClassValue;
@end

BOOL AIYOU_G_P_BClassHasSel(Class aClass, SEL sel);

CF_EXTERN_C_END
