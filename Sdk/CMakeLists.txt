cmake_minimum_required(VERSION 3.8)

project(Sdk  VERSION 0.0.1 DESCRIPTION "EnergyExpert SDK library")

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# Настройка для включения компиляции классов работы с PostgreSQL
set(PostgreSQLSupport true)
set(PugixmlLinkingSupport true)

set(SOURCE_LIB export.h
               singleton.h
               property.h
               Core/Collections/Collection.h
               Core/Collections/Iterator.h
               Core/Collections/Array.h Core/Collections/ArrayIterator.h
               Core/Collections/CollectionExtensions.h
               Core/Configuration/AbstractFileConfiguration.cpp Core/Configuration/AbstractFileConfiguration.h
               Core/Configuration/IConfiguration.cpp Core/Configuration/IConfiguration.h
               Core/Configuration/XmlConfiguration.cpp Core/Configuration/XmlConfiguration.h
               Core/Data/Exceptions/DataStreamAlreadyOpenException.cpp Core/Data/Exceptions/DataStreamAlreadyOpenException.h
               Core/Data/Exceptions/DataStreamNotOpenException.cpp Core/Data/Exceptions/DataStreamNotOpenException.h
               Core/Data/BufferedWriteFile.cpp Core/Data/BufferedWriteFile.h
               Core/Data/File.cpp Core/Data/File.h
               Core/Data/IDataReader.cpp Core/Data/IDataReader.h
               Core/Data/IDataStream.cpp Core/Data/IDataStream.h
               Core/Draws/AbstractSurface.cpp Core/Draws/AbstractSurface.h
               Core/Draws/AbstractViewItem.cpp Core/Draws/AbstractViewItem.h
               Core/Exceptions/IOException.cpp Core/Exceptions/IOException.h
               Core/Exceptions/NullPointerException.cpp Core/Exceptions/NullPointerException.h
               Core/Exceptions/TypeCastingException.cpp Core/Exceptions/TypeCastingException.h
               Core/Helpers/HtmlHelper.cpp Core/Helpers/HtmlHelper.h
               Core/Metadata/IMetadata.cpp Core/Metadata/IMetadata.h
               Core/Metadata/MetaObject.cpp Core/Metadata/MetaObject.h
               Core/Metadata/MetadataClass.h
               Core/Metadata/BaseMetadataClassBuilder.h
               Core/Serialization/Json/IJsonSerializable.h
               Core/Serialization/Json/JsonObject.cpp Core/Serialization/Json/JsonObject.h
               Core/Serialization/Json/JsonValue.cpp Core/Serialization/Json/JsonValue.h
               Core/Serialization/Json/JsonArray.cpp Core/Serialization/Json/JsonArray.h
               Core/Serialization/Xml/IXmlDecorator.h
               Core/Serialization/Xml/IXmlSerializable.cpp Core/Serialization/Xml/IXmlSerializable.h
               Core/Serialization/Xml/XmlAttribute.cpp Core/Serialization/Xml/XmlAttribute.h
               Core/Serialization/Xml/XmlAttributeNameDecorator.cpp Core/Serialization/Xml/XmlAttributeNameDecorator.h
               Core/Serialization/Xml/XmlNode.cpp Core/Serialization/Xml/XmlNode.h
               Core/Serialization/Xml/XmlObject.cpp Core/Serialization/Xml/XmlObject.h
               Core/Serialization/Xml/XmlSerializerImpl.cpp Core/Serialization/Xml/XmlSerializerImpl.h
               Core/Serialization/Xml/XmlTagNameDecorator.cpp Core/Serialization/Xml/XmlTagNameDecorator.h
               Core/Serialization/Xml/XmlValue.cpp Core/Serialization/Xml/XmlValue.h
               Core/Serialization/Xml/IXmlAttributeDestroyingListener.h
               Core/Serialization/ISerializable.h
               Core/Serialization/ISerializer.h
               Core/Types/IStringable.h
               Core/Types/ICloneable.h
               Core/Types/IDrawable.h
               Core/Types/IObservable.h
               Core/Types/Uuid.cpp Core/Types/Uuid.h
               Core/Types/DateTime.cpp Core/Types/DateTime.h
               Database/IDatabaseConnection.h
               Database/IDatabaseConnectionSettings.h
               Database/IDatabaseQuery.cpp Database/IDatabaseQuery.h
               Database/IDatabasePatch.h
               Database/IDatabasePatcher.cpp Database/IDatabasePatcher.h
               Database/IDatabaseValue.cpp Database/IDatabaseValue.h
               Database/IDatabaseTransaction.cpp Database/IDatabaseTransaction.h
               Database/DatabaseConnectionsProviderImpl.cpp Database/IDatabaseConnectionsProvider.h
               Database/Exceptions/DatabaseCommitFailedException.cpp Database/Exceptions/DatabaseCommitFailedException.h
               Database/Exceptions/DatabaseExecutionFailed.cpp Database/Exceptions/DatabaseExecutionFailed.h
               Database/Exceptions/DatabaseNotOpenException.cpp Database/Exceptions/DatabaseNotOpenException.h
               Database/PostgreSql/PostgreSqlConnection.cpp Database/PostgreSql/PostgreSqlConnection.h
               Database/PostgreSql/PostgreSqlConnectionSettings.cpp Database/PostgreSql/PostgreSqlConnectionSettings.h
               Database/PostgreSql/PostgreSqlQuery.cpp Database/PostgreSql/PostgreSqlQuery.h
               Database/PostgreSql/PostgreSqlPatcher.cpp Database/PostgreSql/PostgreSqlPatcher.h
               Database/PostgreSql/PostgreSqlTransaction.cpp Database/PostgreSql/PostgreSqlTransaction.h
               Database/PostgreSql/PostgreSqlValue.cpp Database/PostgreSql/PostgreSqlValue.h
               Database/PostgreSql/Patches/DatabaseCreationPatch.cpp Database/PostgreSql/Patches/DatabaseCreationPatch.h
               Logs/ConsoleLogger.cpp Logs/ConsoleLogger.h
               Logs/DefaultLogMessageFormatter.cpp Logs/DefaultLogMessageFormatter.h
               Logs/FileLogger.cpp Logs/FileLogger.h
               Logs/ILogger.h Logs/ILogger.cpp
               Logs/ILogMessageFormatter.h
               Model/AbstractEntity.cpp Model/AbstractEntity.h
               Model/IIdentified.h
               Model/Network/AbstractNetworkElement.cpp Model/Network/AbstractNetworkElement.h
               Model/Network/Bus.cpp Model/Network/Bus.h
               Model/Network/Network.cpp Model/Network/Network.h
               Model/Network/Thread.cpp Model/Network/Thread.h
               Model/Network/TransformerSubstation.cpp Model/Network/TransformerSubstation.h
               Model/Network/NetworkElementBuilder.cpp Model/Network/NetworkElementBuilder.h
               Model/Network/Wire.cpp Model/Network/Wire.h
               Core/Metadata/TypeUids.txt
               )


add_library(Sdk SHARED ${SOURCE_LIB})

include(PostgreSql)
include(pugixml)

include_directories("../")

set_target_properties(Sdk PROPERTIES VERSION ${PROJECT_VERSION})

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET Sdk PROPERTY CXX_STANDARD 17)

add_compile_definitions(SDK_LIBRARY_EXPORT)

target_link_libraries(${TARGET} Sdk)


