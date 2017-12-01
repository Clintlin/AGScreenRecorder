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

#import "AIYOU_G_P_BDictionary.h"

@class AIYOU_G_P_BCodedInputStream;
@class AIYOU_G_P_BCodedOutputStream;
@class AIYOU_G_P_BExtensionRegistry;
@class AIYOU_G_P_BFieldDescriptor;

@protocol AIYOU_G_P_BDictionaryInternalsProtocol
- (size_t)computeSerializedSizeAsField:(AIYOU_G_P_BFieldDescriptor *)field;
- (void)writeToCodedOutputStream:(AIYOU_G_P_BCodedOutputStream *)outputStream
                         asField:(AIYOU_G_P_BFieldDescriptor *)field;
- (void)setAIYOU_G_P_BGenericValue:(AIYOU_G_P_BGenericValue *)value
     forAIYOU_G_P_BGenericValueKey:(AIYOU_G_P_BGenericValue *)key;
- (void)enumerateForTextFormat:(void (^)(id keyObj, id valueObj))block;
@end

//%PDDM-DEFINE DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(KEY_NAME)
//%DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(KEY_NAME)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Object, Object)
//%PDDM-DEFINE DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(KEY_NAME)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, UInt32, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Int32, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, UInt64, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Int64, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Bool, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Float, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Double, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Enum, Enum)

//%PDDM-DEFINE DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, VALUE_NAME, HELPER)
//%@interface AIYOU_G_P_B##KEY_NAME##VALUE_NAME##Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
//% @package
//%  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
//%}
//%EXTRA_DICTIONARY_PRIVATE_INTERFACES_##HELPER()@end
//%

//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Basic()
// Empty
//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Object()
//%- (BOOL)isInitialized;
//%- (instancetype)deepCopyWithZone:(NSZone *)zone
//%    __attribute__((ns_returns_retained));
//%
//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Enum()
//%- (NSData *)serializedDataForUnknownValue:(int32_t)value
//%                                   forKey:(AIYOU_G_P_BGenericValue *)key
//%                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
//%

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(UInt32)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BUInt32UInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32Int32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32UInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32Int64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32BoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32FloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32DoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt32EnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

@interface AIYOU_G_P_BUInt32ObjectDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Int32)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BInt32UInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32Int32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32UInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32Int64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32BoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32FloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32DoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt32EnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

@interface AIYOU_G_P_BInt32ObjectDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(UInt64)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BUInt64UInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64Int32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64UInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64Int64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64BoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64FloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64DoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BUInt64EnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

@interface AIYOU_G_P_BUInt64ObjectDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Int64)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BInt64UInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64Int32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64UInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64Int64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64BoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64FloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64DoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BInt64EnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

@interface AIYOU_G_P_BInt64ObjectDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Bool)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BBoolUInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolUInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolBoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolFloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolDoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BBoolEnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

@interface AIYOU_G_P_BBoolObjectDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

//%PDDM-EXPAND DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(String)
// This block of code is generated, do not edit it directly.

@interface AIYOU_G_P_BStringUInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringInt32Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringUInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringInt64Dictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringBoolDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringFloatDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringDoubleDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

@interface AIYOU_G_P_BStringEnumDictionary () <AIYOU_G_P_BDictionaryInternalsProtocol> {
 @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(AIYOU_G_P_BGenericValue *)key
                              keyDataType:(AIYOU_G_P_BDataType)keyDataType;
@end

//%PDDM-EXPAND-END (6 expansions)

#pragma mark - NSDictionary Subclass

@interface AIYOU_G_P_BAutocreatedDictionary : NSMutableDictionary {
  @package
  AIYOU_G_P_B_UNSAFE_UNRETAINED AIYOU_G_P_BMessage *_autocreator;
}
@end

#pragma mark - Helpers

CF_EXTERN_C_BEGIN

// Helper to compute size when an NSDictionary is used for the map instead
// of a custom type.
size_t AIYOU_G_P_BDictionaryComputeSizeInternalHelper(NSDictionary *dict,
                                              AIYOU_G_P_BFieldDescriptor *field);

// Helper to write out when an NSDictionary is used for the map instead
// of a custom type.
void AIYOU_G_P_BDictionaryWriteToStreamInternalHelper(
    AIYOU_G_P_BCodedOutputStream *outputStream, NSDictionary *dict,
    AIYOU_G_P_BFieldDescriptor *field);

// Helper to check message initialization when an NSDictionary is used for
// the map instead of a custom type.
BOOL AIYOU_G_P_BDictionaryIsInitializedInternalHelper(NSDictionary *dict,
                                              AIYOU_G_P_BFieldDescriptor *field);

// Helper to read a map instead.
void AIYOU_G_P_BDictionaryReadEntry(id mapDictionary, AIYOU_G_P_BCodedInputStream *stream,
                            AIYOU_G_P_BExtensionRegistry *registry,
                            AIYOU_G_P_BFieldDescriptor *field,
                            AIYOU_G_P_BMessage *parentMessage);

CF_EXTERN_C_END
