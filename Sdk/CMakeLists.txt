cmake_minimum_required(VERSION 3.8)

project(Sdk  VERSION 0.0.1 DESCRIPTION "EnergyExpert SDK library")

set(SOURCE_LIB Core/Data/IDataReader.cpp Core/Data/IDataReader.h
               Core/Data/IDataStream.cpp Core/Data/IDataStream.h
               Core/Collections/Collection.h
               Core/Collections/Iterator.h
               Core/Collections/Array.h Core/Collections/ArrayIterator.h
               Core/Collections/CollectionExtensions.h
               Model/IIdentified.h
               Core/Types/Uuid.cpp Core/Types/Uuid.h
               Core/Types/IStringable.h
               Core/Types/ICloneable.h
               Core/Types/IDrawable.h
               Core/Types/IObservable.h
               Core/Draws/AbstractViewItem.cpp Core/Draws/AbstractViewItem.h
               Core/Draws/AbstractSurface.cpp Core/Draws/AbstractSurface.h
               Core/Serialization/Json/IJsonSerializable.h
               Core/Serialization/Json/JsonObject.cpp Core/Serialization/Json/JsonObject.h
               Core/Serialization/Json/JsonValue.cpp Core/Serialization/Json/JsonValue.h
               Core/Serialization/Json/JsonArray.cpp Core/Serialization/Json/JsonArray.h
               Core/Serialization/Xml/XmlObject.cpp Core/Serialization/Xml/XmlObject.h
               Core/Serialization/Xml/XmlNode.cpp Core/Serialization/Xml/XmlNode.h
               Core/Serialization/Xml/XmlAttribute.cpp Core/Serialization/Xml/XmlAttribute.h
               Core/Serialization/Xml/XmlValue.cpp Core/Serialization/Xml/XmlValue.h
               Core/Serialization/Xml/IXmlSerializable.cpp Core/Serialization/Xml/IXmlSerializable.h
               Core/Serialization/Xml/XmlSerializerImpl.cpp Core/Serialization/Xml/XmlSerializerImpl.h
               Core/Serialization/Xml/XmlTagNameDecorator.cpp Core/Serialization/Xml/XmlTagNameDecorator.h
               Core/Serialization/Xml/XmlAttributeNameDecorator.cpp Core/Serialization/Xml/XmlAttributeNameDecorator.h
               Core/Serialization/Xml/IXmlDecorator.h
               Core/Serialization/ISerializer.h
               Core/Serialization/ISerializable.h
               Core/Metadata/IMetadata.cpp Core/Metadata/IMetadata.h
               Core/Metadata/MetaObject.cpp Core/Metadata/MetaObject.h
               Core/Metadata/MetadataClass.h
               Core/Metadata/BaseMetadataClassBuilder.h
               Core/Helpers/HtmlHelper.cpp Core/Helpers/HtmlHelper.h
               Database/IDatabaseConnection.h
               Database/DatabaseConnectionsProviderImpl.cpp Database/IDatabaseConnectionsProvider.h
               Database/Exceptions/DatabaseNotOpenException.h
               Database/PostgreSql/PostgreSqlConnection.cpp Database/PostgreSql/PostgreSqlConnection.h
               Model/Network/AbstractNetworkElement.cpp Model/Network/AbstractNetworkElement.h
               Model/Network/Wire.cpp Model/Network/Wire.h
               Model/Network/TransformerSubstation.cpp Model/Network/TransformerSubstation.h
               Model/Network/Bus.cpp Model/Network/Bus.h
               Model/Network/Thread.cpp Model/Network/Thread.h
               Model/Network/Network.cpp Model/Network/Network.h
               Model/Network/NetworkElementBuilder.cpp Model/Network/NetworkElementBuilder.h
               export.h
               singleton.h
               Core/Metadata/TypeUids.txt
               )


add_library(Sdk SHARED ${SOURCE_LIB})

include_directories("/")

set_target_properties(Sdk PROPERTIES VERSION ${PROJECT_VERSION})

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(SDK_LIBRARY_EXPORT)

target_link_libraries(${TARGET} Sdk)
