/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2014 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * response_frame.h
 *
 * Store current response frame
 */

#pragma once

#include "build.h"
#include <stdint.h>
#include <cstring>
#include <assert.h>

namespace avdecc_lib
{
    class response_frame
    {
    public:
        response_frame(const uint8_t *frame, size_t size, size_t pos);
        virtual ~response_frame();
        
        /*
         * Buffer to store counters and command response frames.  Will be updated
         * by command response processing methods.
         */
        uint8_t * buffer;
        /*
         * Buffer to store descriptor response frames.  Will be updated by
         * update_desc_database() method in configuration descriptor.
         */
        uint8_t * desc_buffer;
        size_t frame_size;
        size_t desc_frame_size;
        size_t position;
        size_t desc_position;
        
        int replace_frame(const uint8_t* frame, size_t pos, size_t size);
        int replace_desc_frame(const uint8_t *frame, size_t pos, size_t size);
        uint8_t * get_buffer();
        uint8_t * get_desc_buffer();
        size_t get_pos();
        size_t get_desc_pos();
        size_t get_size();
        size_t get_desc_size();
    };
}
