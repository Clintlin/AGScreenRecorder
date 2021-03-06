// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: type.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(AIYOU_G_P_B_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define AIYOU_G_P_B_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if AIYOU_G_P_B_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/AIYOU_G_P_BProtocolBuffers.h>
#else
 #import "AIYOU_G_P_BProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class AIYOU_G_P_BAny;
@class AIYOU_G_P_BEnumValue;
@class AIYOU_G_P_BField;
@class AIYOU_G_P_BOption;
@class AIYOU_G_P_BSourceContext;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum AIYOU_G_P_BSyntax

/** The syntax in which a protocol buffer element is defined. */
typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BSyntax) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  AIYOU_G_P_BSyntax_AIYOU_G_P_BUnrecognizedEnumeratorValue = kAIYOU_G_P_BUnrecognizedEnumeratorValue,
  /** Syntax `proto2`. */
  AIYOU_G_P_BSyntax_SyntaxProto2 = 0,

  /** Syntax `proto3`. */
  AIYOU_G_P_BSyntax_SyntaxProto3 = 1,
};

AIYOU_G_P_BEnumDescriptor *AIYOU_G_P_BSyntax_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL AIYOU_G_P_BSyntax_IsValidValue(int32_t value);

#pragma mark - Enum AIYOU_G_P_BField_Kind

/** Basic field types. */
typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BField_Kind) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  AIYOU_G_P_BField_Kind_AIYOU_G_P_BUnrecognizedEnumeratorValue = kAIYOU_G_P_BUnrecognizedEnumeratorValue,
  /** Field type unknown. */
  AIYOU_G_P_BField_Kind_TypeUnknown = 0,

  /** Field type double. */
  AIYOU_G_P_BField_Kind_TypeDouble = 1,

  /** Field type float. */
  AIYOU_G_P_BField_Kind_TypeFloat = 2,

  /** Field type int64. */
  AIYOU_G_P_BField_Kind_TypeInt64 = 3,

  /** Field type uint64. */
  AIYOU_G_P_BField_Kind_TypeUint64 = 4,

  /** Field type int32. */
  AIYOU_G_P_BField_Kind_TypeInt32 = 5,

  /** Field type fixed64. */
  AIYOU_G_P_BField_Kind_TypeFixed64 = 6,

  /** Field type fixed32. */
  AIYOU_G_P_BField_Kind_TypeFixed32 = 7,

  /** Field type bool. */
  AIYOU_G_P_BField_Kind_TypeBool = 8,

  /** Field type string. */
  AIYOU_G_P_BField_Kind_TypeString = 9,

  /** Field type group. Proto2 syntax only, and deprecated. */
  AIYOU_G_P_BField_Kind_TypeGroup = 10,

  /** Field type message. */
  AIYOU_G_P_BField_Kind_TypeMessage = 11,

  /** Field type bytes. */
  AIYOU_G_P_BField_Kind_TypeBytes = 12,

  /** Field type uint32. */
  AIYOU_G_P_BField_Kind_TypeUint32 = 13,

  /** Field type enum. */
  AIYOU_G_P_BField_Kind_TypeEnum = 14,

  /** Field type sfixed32. */
  AIYOU_G_P_BField_Kind_TypeSfixed32 = 15,

  /** Field type sfixed64. */
  AIYOU_G_P_BField_Kind_TypeSfixed64 = 16,

  /** Field type sint32. */
  AIYOU_G_P_BField_Kind_TypeSint32 = 17,

  /** Field type sint64. */
  AIYOU_G_P_BField_Kind_TypeSint64 = 18,
};

AIYOU_G_P_BEnumDescriptor *AIYOU_G_P_BField_Kind_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL AIYOU_G_P_BField_Kind_IsValidValue(int32_t value);

#pragma mark - Enum AIYOU_G_P_BField_Cardinality

/** Whether a field is optional, required, or repeated. */
typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BField_Cardinality) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  AIYOU_G_P_BField_Cardinality_AIYOU_G_P_BUnrecognizedEnumeratorValue = kAIYOU_G_P_BUnrecognizedEnumeratorValue,
  /** For fields with unknown cardinality. */
  AIYOU_G_P_BField_Cardinality_CardinalityUnknown = 0,

  /** For optional fields. */
  AIYOU_G_P_BField_Cardinality_CardinalityOptional = 1,

  /** For required fields. Proto2 syntax only. */
  AIYOU_G_P_BField_Cardinality_CardinalityRequired = 2,

  /** For repeated fields. */
  AIYOU_G_P_BField_Cardinality_CardinalityRepeated = 3,
};

AIYOU_G_P_BEnumDescriptor *AIYOU_G_P_BField_Cardinality_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL AIYOU_G_P_BField_Cardinality_IsValidValue(int32_t value);

#pragma mark - AIYOU_G_P_BTypeRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (AIYOU_G_P_BExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c AIYOU_G_P_BExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface AIYOU_G_P_BTypeRoot : AIYOU_G_P_BRootObject
@end

#pragma mark - AIYOU_G_P_BType

typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BType_FieldNumber) {
  AIYOU_G_P_BType_FieldNumber_Name = 1,
  AIYOU_G_P_BType_FieldNumber_FieldsArray = 2,
  AIYOU_G_P_BType_FieldNumber_OneofsArray = 3,
  AIYOU_G_P_BType_FieldNumber_OptionsArray = 4,
  AIYOU_G_P_BType_FieldNumber_SourceContext = 5,
  AIYOU_G_P_BType_FieldNumber_Syntax = 6,
};

/**
 * A protocol buffer message type.
 **/
@interface AIYOU_G_P_BType : AIYOU_G_P_BMessage

/** The fully qualified message name. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/** The list of fields. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BField*> *fieldsArray;
/** The number of items in @c fieldsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger fieldsArray_Count;

/** The list of types appearing in `oneof` definitions in this type. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *oneofsArray;
/** The number of items in @c oneofsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger oneofsArray_Count;

/** The protocol buffer options. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BOption*> *optionsArray;
/** The number of items in @c optionsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger optionsArray_Count;

/** The source context. */
@property(nonatomic, readwrite, strong, null_resettable) AIYOU_G_P_BSourceContext *sourceContext;
/** Test to see if @c sourceContext has been set. */
@property(nonatomic, readwrite) BOOL hasSourceContext;

/** The source syntax. */
@property(nonatomic, readwrite) AIYOU_G_P_BSyntax syntax;

@end

/**
 * Fetches the raw value of a @c AIYOU_G_P_BType's @c syntax property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t AIYOU_G_P_BType_Syntax_RawValue(AIYOU_G_P_BType *message);
/**
 * Sets the raw value of an @c AIYOU_G_P_BType's @c syntax property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAIYOU_G_P_BType_Syntax_RawValue(AIYOU_G_P_BType *message, int32_t value);

#pragma mark - AIYOU_G_P_BField

typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BField_FieldNumber) {
  AIYOU_G_P_BField_FieldNumber_Kind = 1,
  AIYOU_G_P_BField_FieldNumber_Cardinality = 2,
  AIYOU_G_P_BField_FieldNumber_Number = 3,
  AIYOU_G_P_BField_FieldNumber_Name = 4,
  AIYOU_G_P_BField_FieldNumber_TypeURL = 6,
  AIYOU_G_P_BField_FieldNumber_OneofIndex = 7,
  AIYOU_G_P_BField_FieldNumber_Packed = 8,
  AIYOU_G_P_BField_FieldNumber_OptionsArray = 9,
  AIYOU_G_P_BField_FieldNumber_JsonName = 10,
  AIYOU_G_P_BField_FieldNumber_DefaultValue = 11,
};

/**
 * A single field of a message type.
 **/
@interface AIYOU_G_P_BField : AIYOU_G_P_BMessage

/** The field type. */
@property(nonatomic, readwrite) AIYOU_G_P_BField_Kind kind;

/** The field cardinality. */
@property(nonatomic, readwrite) AIYOU_G_P_BField_Cardinality cardinality;

/** The field number. */
@property(nonatomic, readwrite) int32_t number;

/** The field name. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/**
 * The field type URL, without the scheme, for message or enumeration
 * types. Example: `"type.googleapis.com/google.protobuf.Timestamp"`.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *typeURL;

/**
 * The index of the field type in `Type.oneofs`, for message or enumeration
 * types. The first type has index 1; zero means the type is not in the list.
 **/
@property(nonatomic, readwrite) int32_t oneofIndex;

/** Whether to use alternative packed wire representation. */
@property(nonatomic, readwrite) BOOL packed;

/** The protocol buffer options. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BOption*> *optionsArray;
/** The number of items in @c optionsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger optionsArray_Count;

/** The field JSON name. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *jsonName;

/** The string value of the default value of this field. Proto2 syntax only. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *defaultValue;

@end

/**
 * Fetches the raw value of a @c AIYOU_G_P_BField's @c kind property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t AIYOU_G_P_BField_Kind_RawValue(AIYOU_G_P_BField *message);
/**
 * Sets the raw value of an @c AIYOU_G_P_BField's @c kind property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAIYOU_G_P_BField_Kind_RawValue(AIYOU_G_P_BField *message, int32_t value);

/**
 * Fetches the raw value of a @c AIYOU_G_P_BField's @c cardinality property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t AIYOU_G_P_BField_Cardinality_RawValue(AIYOU_G_P_BField *message);
/**
 * Sets the raw value of an @c AIYOU_G_P_BField's @c cardinality property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAIYOU_G_P_BField_Cardinality_RawValue(AIYOU_G_P_BField *message, int32_t value);

#pragma mark - AIYOU_G_P_BEnum

typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BEnum_FieldNumber) {
  AIYOU_G_P_BEnum_FieldNumber_Name = 1,
  AIYOU_G_P_BEnum_FieldNumber_EnumvalueArray = 2,
  AIYOU_G_P_BEnum_FieldNumber_OptionsArray = 3,
  AIYOU_G_P_BEnum_FieldNumber_SourceContext = 4,
  AIYOU_G_P_BEnum_FieldNumber_Syntax = 5,
};

/**
 * Enum type definition.
 **/
@interface AIYOU_G_P_BEnum : AIYOU_G_P_BMessage

/** Enum type name. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/** Enum value definitions. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BEnumValue*> *enumvalueArray;
/** The number of items in @c enumvalueArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger enumvalueArray_Count;

/** Protocol buffer options. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BOption*> *optionsArray;
/** The number of items in @c optionsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger optionsArray_Count;

/** The source context. */
@property(nonatomic, readwrite, strong, null_resettable) AIYOU_G_P_BSourceContext *sourceContext;
/** Test to see if @c sourceContext has been set. */
@property(nonatomic, readwrite) BOOL hasSourceContext;

/** The source syntax. */
@property(nonatomic, readwrite) AIYOU_G_P_BSyntax syntax;

@end

/**
 * Fetches the raw value of a @c AIYOU_G_P_BEnum's @c syntax property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t AIYOU_G_P_BEnum_Syntax_RawValue(AIYOU_G_P_BEnum *message);
/**
 * Sets the raw value of an @c AIYOU_G_P_BEnum's @c syntax property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAIYOU_G_P_BEnum_Syntax_RawValue(AIYOU_G_P_BEnum *message, int32_t value);

#pragma mark - AIYOU_G_P_BEnumValue

typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BEnumValue_FieldNumber) {
  AIYOU_G_P_BEnumValue_FieldNumber_Name = 1,
  AIYOU_G_P_BEnumValue_FieldNumber_Number = 2,
  AIYOU_G_P_BEnumValue_FieldNumber_OptionsArray = 3,
};

/**
 * Enum value definition.
 **/
@interface AIYOU_G_P_BEnumValue : AIYOU_G_P_BMessage

/** Enum value name. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/** Enum value number. */
@property(nonatomic, readwrite) int32_t number;

/** Protocol buffer options. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AIYOU_G_P_BOption*> *optionsArray;
/** The number of items in @c optionsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger optionsArray_Count;

@end

#pragma mark - AIYOU_G_P_BOption

typedef AIYOU_G_P_B_ENUM(AIYOU_G_P_BOption_FieldNumber) {
  AIYOU_G_P_BOption_FieldNumber_Name = 1,
  AIYOU_G_P_BOption_FieldNumber_Value = 2,
};

/**
 * A protocol buffer option, which can be attached to a message, field,
 * enumeration, etc.
 **/
@interface AIYOU_G_P_BOption : AIYOU_G_P_BMessage

/**
 * The option's name. For protobuf built-in options (options defined in
 * descriptor.proto), this is the short name. For example, `"map_entry"`.
 * For custom options, it should be the fully-qualified name. For example,
 * `"google.api.http"`.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/**
 * The option's value packed in an Any message. If the value is a primitive,
 * the corresponding wrapper type defined in wrappers.proto
 * should be used. If the value is an enum, it should be stored as an int32
 * value using the google.protobuf.Int32Value type.
 **/
@property(nonatomic, readwrite, strong, null_resettable) AIYOU_G_P_BAny *value;
/** Test to see if @c value has been set. */
@property(nonatomic, readwrite) BOOL hasValue;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
