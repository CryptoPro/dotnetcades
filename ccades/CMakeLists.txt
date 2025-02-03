CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(CMAKE_CXX_STANDARD 11)
PROJECT(ccades LANGUAGES CXX)
    SET (ccades_LIB_SRCS
            CCadesAbout.cpp
            CCadesAlgorithm.cpp
            CCadesAttribute.cpp
            CCadesAttributes.cpp
            CCadesBasicConstraints.cpp
            CCadesBlobs.cpp
            CCadesCertificate.cpp
            CCadesCertificates.cpp
            CCadesCertificateStatus.cpp
            CCadesCRL.cpp
            CCadesEKU.cpp
            CCadesEKUs.cpp
            CCadesEncodedData.cpp
            CCadesEnvelopedData.cpp
            CCadesExtendedKeyUsage.cpp
            CCadesHashedData.cpp
            CCadesKeyUsage.cpp
            CCadesLicense.cpp
            CCadesPrivateKey.cpp
            CCadesPublicKey.cpp
            CCadesRawSignature.cpp
            CCadesRecipients.cpp
            CCadesSignatureStatus.cpp
            CCadesSignedData.cpp
            CCadesSignedXML.cpp
            CCadesSigner.cpp
            CCadesSigners.cpp
            CCadesStore.cpp
            CCadesSymmetricAlgorithm.cpp
            CCadesVersion.cpp
            CCadesOID.cpp
            errormsg.cpp
        )
FIND_PACKAGE( Boost REQUIRED )

ADD_DEFINITIONS(-DUNIX -DSIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P})

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-write-strings")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-narrowing")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(ccades_DIRS
     /opt/cprocsp/include
     /opt/cprocsp/include/cpcsp
     /opt/cprocsp/include/pki/atl
     /opt/cprocsp/include/pki/cppcades
     /opt/cprocsp/include/pki/cplib
     /opt/cprocsp/include/pki
)    

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIRS} )
INCLUDE_DIRECTORIES( ${ccades_DIRS})

ADD_LIBRARY(ccades SHARED ${ccades_LIB_SRCS})

FIND_LIBRARY(FOUND_LIB_CPPCADES
    NAMES cppcades
    HINTS /opt/cprocsp/lib/amd64 /opt/cprocsp/lib/ia32 /opt/cprocsp/lib/aarch64)
TARGET_LINK_LIBRARIES(ccades ${FOUND_LIB_CPPCADES})

ADD_CUSTOM_COMMAND(TARGET ccades
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ccades> ..)
