// bslstl_stdexceptutil.h                                             -*-C++-*-
#ifndef INCLUDED_BSLSTL_STDEXCEPTUTIL
#define INCLUDED_BSLSTL_STDEXCEPTUTIL

#include <bsls_ident.h>
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a utility to throw standard exceptions.
//
//@CLASSES:
//  bslstl::StdExceptUtil: namespace for utilities to throw standard exceptions
//
//@CANONICAL_HEADER: bsl_stdexcept.h
//
//@SEE_ALSO: stdexcept
//
//@DESCRIPTION: This component provides a means to throw standard exceptions
// without introducing a compile-time dependency on the standard exception
// classes.  This valuable where header files define function templates or
// inline functions that may throw these types as exceptions.
//
///Usage
///-----
// First we declare a function template that wants to throw a standard
// exception.  Note that the 'stdexcept' header is not included at this point.
//..
//  #include <bslstl_stdexceptutil.h>
//
//  template<typename T>
//  void testFunction(int selector)
//      //  Throw a standard exception according to the specified 'selector'.
//  {
//    switch(selector) {
//      case 1: bslstl::StdExceptUtil::throwRuntimeError("sample message 1");
//      case 2: bslstl::StdExceptUtil::throwLogicError("sample message 2");
//      default : bslstl::StdExceptUtil::throwInvalidArgument("ERROR");
//    }
//  }
//..
// However, if client code wishes to catch the exception, the '.cpp' file must
// '#include' the appropriate header.
//..
//  #include <stdexcept>
//
//  void callTestFunction()
//  {
//    try {
//      testFunction<int>(1);
//      assert(0 == "Should throw before reaching here.");
//    }
//    catch(const runtime_error& ex) {
//      assert(0 == std::strcmp(ex.what(), "sample message 1"));
//    }
//
//    try {
//      testFunction<double>(2);
//      assert(0 == "Should throw before reaching here.");
//    }
//    catch(const logic_error& ex) {
//      assert(0 == std::strcmp(ex.what(), "sample message 2"));
//    }
//  }
//..

#include <bslscm_version.h>

#include <bsls_annotation.h>
#include <bsls_compilerfeatures.h>
#include <bsls_platform.h>

namespace BloombergLP {

namespace bslstl {

                        //====================
                        // class StdExceptUtil
                        //====================

struct StdExceptUtil {
    // This 'struct' provides a namespace for 'static' utility functions that
    // throw standard library exceptions.

    // CLASS METHODS
    BSLS_ANNOTATION_NORETURN
    static void throwRuntimeError(const char *message);
        // Throw a 'std::runtime_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwLogicError(const char *message);
        // Throw a 'std::logic_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwDomainError(const char *message);
        // Throw a 'std::domain_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwInvalidArgument(const char *message);
        // Throw a 'std::invalid_argument' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwLengthError(const char *message);
        // Throw a 'std::length_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwOutOfRange(const char *message);
        // Throw a 'std::out_of_range' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwRangeError(const char *message);
        // Throw a 'std::range_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwOverflowError(const char *message);
        // Throw a 'std::overflow_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.

    BSLS_ANNOTATION_NORETURN
    static void throwUnderflowError(const char *message);
        // Throw a 'std::underflow_error' exception supplying the specified
        // 'message' as the sole argument to its constructor.
};

}  // close package namespace

#ifndef BDE_OPENSOURCE_PUBLICATION  // BACKWARD_COMPATIBILITY
// ============================================================================
//                           BACKWARD COMPATIBILITY
// ============================================================================

typedef bslstl::StdExceptUtil bslstl_StdExceptUtil;
    // This alias is defined for backward compatibility.
#endif  // BDE_OPENSOURCE_PUBLICATION -- BACKWARD_COMPATIBILITY

}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
