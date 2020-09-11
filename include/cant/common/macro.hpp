//
// Created by binabik on 10/07/2020.
//

// not this time!
// #pragma once
#ifdef CANTINA_MACRO_HPP
    #error "Macros oughtn't be included twice in the same translation unit, ya thick."
#else
    #include <cassert>

    #define CANTINA_MACRO_HPP

    // compilers
    #if defined(__GNUC__)
        #define CANTINA_GCC   __GNUC__
    #elif defined(_MSC_VER)
        #define CANTINA_MSVC  _MSC_VER
    #elif defined(__clang__)
        #define CANTINA_CLANG __clang__
    #endif // Compilers


    #define CANT_CURRENT_FILE __FILE__
    #define CANT_CURRENT_LINE __LINE__

    #if defined(CANTINA_GCC)
        #define CANT_CURRENT_FUNC __PRETTY_FUNCTION__
    #elif defined(CANTINA_MSVC)
        #define CANT_CURRENT_FUNC __FUNCSIG__
    #elif defined(CANTINA_CLANG)
        #define CANT_CURRENT_FUNC __PRETTY_FUNCTION__
    #endif // Function

    // Attributes
    #define CANT_NODISCARD   [[nodiscard]]
    #define CANT_MAYBEUNUSED [[maybe_unused]]
    #define CANT_FALLTHROUGH [[fallthrough]]
    #define CANT_LIKELY      [[likely]]
    #define CANT_UNLIKELY    [[unlikely]]

    #define CANTINA_ASSERT(pred, message) assert((pred) && (message))

    // Specifiers
    #define CANT_CONSTEXPR constexpr
    #define CANT_INLINE    inline
    #define CANT_EXPLICIT  explicit
    #define CANT_NOEXCEPT  noexcept


    /* EXCEPTION SPECIFICS */
    #ifdef CANTINA_CANTINAEXCEPTION_HPP
        #define CANT_CURRENT_TRACE            ::cant::Trace(CANT_CURRENT_FUNC, CANT_CURRENT_FILE, CANT_CURRENT_LINE)

        #    define CANTINA_EXCEPTION(msg)        ::cant::CantinaException(CANT_CURRENT_TRACE, msg)
        #    define CANTINA_TRY_RETHROW(expression)                                               \
        try {                                     \
        expression                             \
        } catch(::cant::CantinaException& e) {    \
            e.addTrace(CANT_CURRENT_TRACE);       \
        throw;                                 \
        }
    #endif // CANTINA_CANTINAEXCEPTION_HPP
    #ifdef CANTINA_PANTOUFLEEXCEPTION_HPP
        # define PANTOUFLE_EXCEPTION(msg) ::cant::pan::PantoufleException(CANT_CURRENT_TRACE, msg)
        # define PANTOUFLE_TRY_RETHROW(expression) \
        try {                                     \
        expression                            \
        } catch (::cant::pan::PantoufleException& e) { \
            e.addTrace(CANT_CURRENT_TRACE);       \
        throw;                                 \
        }
    #endif // CANTINA_PANTOUFLEEXCEPTION_HPP

#endif //CANTINA_MACRO_HPP
