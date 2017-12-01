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

#import "AIYOU_G_P_BArray.h"
#import "AIYOU_G_P_BMessage.h"
#import "AIYOU_G_P_BRuntimeTypes.h"

CF_EXTERN_C_BEGIN

NS_ASSUME_NONNULL_BEGIN

/**
 * Generates a string that should be a valid "TextFormat" for the C++ version
 * of Protocol Buffers.
 *
 * @param message    The message to generate from.
 * @param lineIndent A string to use as the prefix for all lines generated. Can
 *                   be nil if no extra indent is needed.
 *
 * @return An NSString with the TextFormat of the message.
 **/
NSString *AIYOU_G_P_BTextFormatForMessage(AIYOU_G_P_BMessage *message,
                                  NSString * __nullable lineIndent);

/**
 * Generates a string that should be a valid "TextFormat" for the C++ version
 * of Protocol Buffers.
 *
 * @param unknownSet The unknown field set to generate from.
 * @param lineIndent A string to use as the prefix for all lines generated. Can
 *                   be nil if no extra indent is needed.
 *
 * @return An NSString with the TextFormat of the unknown field set.
 **/
NSString *AIYOU_G_P_BTextFormatForUnknownFieldSet(AIYOU_G_P_BUnknownFieldSet * __nullable unknownSet,
                                          NSString * __nullable lineIndent);

/**
 * Checks if the given field number is set on a message.
 *
 * @param self        The message to check.
 * @param fieldNumber The field number to check.
 *
 * @return YES if the field number is set on the given message.
 **/
BOOL AIYOU_G_P_BMessageHasFieldNumberSet(AIYOU_G_P_BMessage *self, uint32_t fieldNumber);

/**
 * Checks if the given field is set on a message.
 *
 * @param self  The message to check.
 * @param field The field to check.
 *
 * @return YES if the field is set on the given message.
 **/
BOOL AIYOU_G_P_BMessageHasFieldSet(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Clears the given field for the given message.
 *
 * @param self  The message for which to clear the field.
 * @param field The field to clear.
 **/
void AIYOU_G_P_BClearMessageField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

//%PDDM-EXPAND AIYOU_G_P_B_ACCESSORS()
// This block of code is generated, do not edit it directly.


//
// Get/Set a given field from/to a message.
//

// Single Fields

/**
 * Gets the value of a bytes field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
NSData *AIYOU_G_P_BGetMessageBytesField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a bytes field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageBytesField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, NSData *value);

/**
 * Gets the value of a string field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
NSString *AIYOU_G_P_BGetMessageStringField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a string field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageStringField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, NSString *value);

/**
 * Gets the value of a message field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
AIYOU_G_P_BMessage *AIYOU_G_P_BGetMessageMessageField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a message field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageMessageField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, AIYOU_G_P_BMessage *value);

/**
 * Gets the value of a group field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
AIYOU_G_P_BMessage *AIYOU_G_P_BGetMessageGroupField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a group field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageGroupField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, AIYOU_G_P_BMessage *value);

/**
 * Gets the value of a bool field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
BOOL AIYOU_G_P_BGetMessageBoolField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a bool field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageBoolField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, BOOL value);

/**
 * Gets the value of an int32 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
int32_t AIYOU_G_P_BGetMessageInt32Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of an int32 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageInt32Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, int32_t value);

/**
 * Gets the value of an uint32 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
uint32_t AIYOU_G_P_BGetMessageUInt32Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of an uint32 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageUInt32Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, uint32_t value);

/**
 * Gets the value of an int64 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
int64_t AIYOU_G_P_BGetMessageInt64Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of an int64 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageInt64Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, int64_t value);

/**
 * Gets the value of an uint64 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
uint64_t AIYOU_G_P_BGetMessageUInt64Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of an uint64 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageUInt64Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, uint64_t value);

/**
 * Gets the value of a float field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
float AIYOU_G_P_BGetMessageFloatField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a float field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageFloatField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, float value);

/**
 * Gets the value of a double field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
double AIYOU_G_P_BGetMessageDoubleField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a double field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void AIYOU_G_P_BSetMessageDoubleField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, double value);

/**
 * Gets the given enum field of a message. For proto3, if the value isn't a
 * member of the enum, @c kAIYOU_G_P_BUnrecognizedEnumeratorValue will be returned.
 * AIYOU_G_P_BGetMessageRawEnumField will bypass the check and return whatever value
 * was set.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 *
 * @return The enum value for the given field.
 **/
int32_t AIYOU_G_P_BGetMessageEnumField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Set the given enum field of a message. You can only set values that are
 * members of the enum.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The enum value to set in the field.
 **/
void AIYOU_G_P_BSetMessageEnumField(AIYOU_G_P_BMessage *self,
                            AIYOU_G_P_BFieldDescriptor *field,
                            int32_t value);

/**
 * Get the given enum field of a message. No check is done to ensure the value
 * was defined in the enum.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 *
 * @return The raw enum value for the given field.
 **/
int32_t AIYOU_G_P_BGetMessageRawEnumField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Set the given enum field of a message. You can set the value to anything,
 * even a value that is not a member of the enum.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The raw enum value to set in the field.
 **/
void AIYOU_G_P_BSetMessageRawEnumField(AIYOU_G_P_BMessage *self,
                               AIYOU_G_P_BFieldDescriptor *field,
                               int32_t value);

// Repeated Fields

/**
 * Gets the value of a repeated field.
 *
 * @param self  The message from which to get the field.
 * @param field The repeated field to get.
 *
 * @return A AIYOU_G_P_B*Array or an NSMutableArray based on the field's type.
 **/
id AIYOU_G_P_BGetMessageRepeatedField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a repeated field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param array A AIYOU_G_P_B*Array or NSMutableArray based on the field's type.
 **/
void AIYOU_G_P_BSetMessageRepeatedField(AIYOU_G_P_BMessage *self,
                                AIYOU_G_P_BFieldDescriptor *field,
                                id array);

// Map Fields

/**
 * Gets the value of a map<> field.
 *
 * @param self  The message from which to get the field.
 * @param field The repeated field to get.
 *
 * @return A AIYOU_G_P_B*Dictionary or NSMutableDictionary based on the field's type.
 **/
id AIYOU_G_P_BGetMessageMapField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);

/**
 * Sets the value of a map<> field.
 *
 * @param self       The message into which to set the field.
 * @param field      The field to set.
 * @param dictionary A AIYOU_G_P_B*Dictionary or NSMutableDictionary based on the
 *                   field's type.
 **/
void AIYOU_G_P_BSetMessageMapField(AIYOU_G_P_BMessage *self,
                           AIYOU_G_P_BFieldDescriptor *field,
                           id dictionary);

//%PDDM-EXPAND-END AIYOU_G_P_B_ACCESSORS()

/**
 * Returns an empty NSData to assign to byte fields when you wish to assign them
 * to empty. Prevents allocating a lot of little [NSData data] objects.
 **/
NSData *AIYOU_G_P_BEmptyNSData(void) __attribute__((pure));

/**
 * Drops the `unknownFields` from the given message and from all sub message.
 **/
void AIYOU_G_P_BMessageDropUnknownFieldsRecursively(AIYOU_G_P_BMessage *message);

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END


//%PDDM-DEFINE AIYOU_G_P_B_ACCESSORS()
//%
//%//
//%// Get/Set a given field from/to a message.
//%//
//%
//%// Single Fields
//%
//%AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(Bytes, NSData, , *)
//%AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(String, NSString, , *)
//%AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(Message, AIYOU_G_P_BMessage, , *)
//%AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(Group, AIYOU_G_P_BMessage, , *)
//%AIYOU_G_P_B_ACCESSOR_SINGLE(Bool, BOOL, )
//%AIYOU_G_P_B_ACCESSOR_SINGLE(Int32, int32_t, n)
//%AIYOU_G_P_B_ACCESSOR_SINGLE(UInt32, uint32_t, n)
//%AIYOU_G_P_B_ACCESSOR_SINGLE(Int64, int64_t, n)
//%AIYOU_G_P_B_ACCESSOR_SINGLE(UInt64, uint64_t, n)
//%AIYOU_G_P_B_ACCESSOR_SINGLE(Float, float, )
//%AIYOU_G_P_B_ACCESSOR_SINGLE(Double, double, )
//%/**
//% * Gets the given enum field of a message. For proto3, if the value isn't a
//% * member of the enum, @c kAIYOU_G_P_BUnrecognizedEnumeratorValue will be returned.
//% * AIYOU_G_P_BGetMessageRawEnumField will bypass the check and return whatever value
//% * was set.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% *
//% * @return The enum value for the given field.
//% **/
//%int32_t AIYOU_G_P_BGetMessageEnumField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);
//%
//%/**
//% * Set the given enum field of a message. You can only set values that are
//% * members of the enum.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The enum value to set in the field.
//% **/
//%void AIYOU_G_P_BSetMessageEnumField(AIYOU_G_P_BMessage *self,
//%                            AIYOU_G_P_BFieldDescriptor *field,
//%                            int32_t value);
//%
//%/**
//% * Get the given enum field of a message. No check is done to ensure the value
//% * was defined in the enum.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% *
//% * @return The raw enum value for the given field.
//% **/
//%int32_t AIYOU_G_P_BGetMessageRawEnumField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);
//%
//%/**
//% * Set the given enum field of a message. You can set the value to anything,
//% * even a value that is not a member of the enum.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The raw enum value to set in the field.
//% **/
//%void AIYOU_G_P_BSetMessageRawEnumField(AIYOU_G_P_BMessage *self,
//%                               AIYOU_G_P_BFieldDescriptor *field,
//%                               int32_t value);
//%
//%// Repeated Fields
//%
//%/**
//% * Gets the value of a repeated field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The repeated field to get.
//% *
//% * @return A AIYOU_G_P_B*Array or an NSMutableArray based on the field's type.
//% **/
//%id AIYOU_G_P_BGetMessageRepeatedField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a repeated field.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param array A AIYOU_G_P_B*Array or NSMutableArray based on the field's type.
//% **/
//%void AIYOU_G_P_BSetMessageRepeatedField(AIYOU_G_P_BMessage *self,
//%                                AIYOU_G_P_BFieldDescriptor *field,
//%                                id array);
//%
//%// Map Fields
//%
//%/**
//% * Gets the value of a map<> field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The repeated field to get.
//% *
//% * @return A AIYOU_G_P_B*Dictionary or NSMutableDictionary based on the field's type.
//% **/
//%id AIYOU_G_P_BGetMessageMapField(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a map<> field.
//% *
//% * @param self       The message into which to set the field.
//% * @param field      The field to set.
//% * @param dictionary A AIYOU_G_P_B*Dictionary or NSMutableDictionary based on the
//% *                   field's type.
//% **/
//%void AIYOU_G_P_BSetMessageMapField(AIYOU_G_P_BMessage *self,
//%                           AIYOU_G_P_BFieldDescriptor *field,
//%                           id dictionary);
//%

//%PDDM-DEFINE AIYOU_G_P_B_ACCESSOR_SINGLE(NAME, TYPE, AN)
//%AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(NAME, TYPE, AN, )
//%PDDM-DEFINE AIYOU_G_P_B_ACCESSOR_SINGLE_FULL(NAME, TYPE, AN, TisP)
//%/**
//% * Gets the value of a##AN NAME$L field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% **/
//%TYPE TisP##AIYOU_G_P_BGetMessage##NAME##Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a##AN NAME$L field.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The to set in the field.
//% **/
//%void AIYOU_G_P_BSetMessage##NAME##Field(AIYOU_G_P_BMessage *self, AIYOU_G_P_BFieldDescriptor *field, TYPE TisP##value);
//%
