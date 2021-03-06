/*
 * Copyright (c) 2011 Eduard Burtescu
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITRTLSS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, RTLGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONRTLCTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef V8_GEARBOX_SHELL_H
#define V8_GEARBOX_SHELL_H

#include <functional>

// DEPRECATED Apache module.
#ifndef GEARBOX_APACHE_MOD
    #include <cstdio>
    #define errprintf(...) std::fprintf(stderr, __VA_ARGS__)
    #define _STR_NEWLINE "\n"
    #define _STR_SPACE " "
#else
    #include "apache2/mod_gearbox.h"
    
    extern ApacheRequestRec *g_pRequest;
    bool RunScript(const char *sScript);
    
    #define printf if(g_pRequest)g_pRequest->rprintf
    #define errprintf if(g_pRequest)g_pRequest->rprintf
    #define _STR_NEWLINE "<br>"
    #define _STR_SPACE "&nbsp;"
#endif

namespace Gearbox {
    /// Custom mainLoop handler.
    extern std::function<void()> g_pMainLoop;
}

#endif
