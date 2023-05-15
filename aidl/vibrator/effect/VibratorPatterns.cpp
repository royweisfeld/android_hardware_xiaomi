/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <string.h>
#include <errno.h>

#include "VibratorPatterns.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))

static const uint8_t effect_0[] = {
    /* (Amp MSB 1 bit) (Amp LSB 8bit) (Period)  FLRA */
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_1[] = {
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_2[] = {
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_3[] = {
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_4[] = {
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_5[] = {
    0x00, 0x1F, S_PERIOD_T_LRA, 0,
    0x00, 0x3F, S_PERIOD_T_LRA, 0,
    0x00, 0x5F, S_PERIOD_T_LRA, 0,
    0x00, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x7F, S_PERIOD_T_LRA, 0,
    0x01, 0x5F, S_PERIOD_T_LRA, 0,
    0x01, 0x3F, S_PERIOD_T_LRA, 0,
    0x01, 0x1F, S_PERIOD_T_LRA, 0,
};

static const uint8_t effect_6[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const uint8_t effect_7[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const uint8_t effect_8[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const uint8_t effect_9[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09,
    0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x06, 0x05, 0x03, 0x01, 0x00, 0xff, 0xfd, 0xfa, 0xf8, 0xf6,
    0xf3, 0xf1, 0xee, 0xec, 0xe9, 0xe6, 0xe3, 0xe0, 0xdc, 0xd9,
    0xd5, 0xd1, 0xcd, 0xc8, 0xc4, 0xbf, 0xbb, 0xb9, 0xb7, 0xb6,
    0xb7, 0xb8, 0xba, 0xbd, 0xc1, 0xc5, 0xcb, 0xd1, 0xd7, 0xde,
    0xe5, 0xed, 0xf5, 0xfd, 0x04, 0x0d, 0x15, 0x1e, 0x26, 0x2e,
    0x36, 0x3d, 0x44, 0x4b, 0x51, 0x56, 0x5b, 0x5f, 0x62, 0x64,
    0x65, 0x65, 0x64, 0x63, 0x5f, 0x5b, 0x56, 0x50, 0x4a, 0x45,
    0x3f, 0x3a, 0x34, 0x2f, 0x29, 0x24, 0x1f, 0x1a, 0x14, 0x0f,
    0x0a, 0x05, 0x00, 0xfc, 0xf8, 0xf3, 0xef, 0xea, 0xe6, 0xe2,
    0xdf, 0xdc, 0xd9, 0xd6, 0xd4, 0xd3, 0xd2, 0xd1, 0xd1, 0xd1,
    0xd2, 0xd4, 0xd7, 0xda, 0xde, 0xe2, 0xe8, 0xee, 0xf6, 0xfd,
    0x02, 0x08, 0x0d, 0x12, 0x16, 0x1a, 0x1d, 0x20, 0x23, 0x26,
    0x28, 0x2a, 0x2b, 0x2d, 0x2e, 0x2f, 0x30, 0x30, 0x30, 0x31,
    0x31, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2f, 0x2e, 0x2d, 0x2c,
    0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x26, 0x25, 0x24, 0x23, 0x22,
    0x21, 0x20, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc,
    0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

#define OFFSET_EFFECT_0    0

#define OFFSET_EFFECT_1    ARRAY_SIZE(effect_0)

#define OFFSET_EFFECT_2    OFFSET_EFFECT_1 + ARRAY_SIZE(effect_1)

#define OFFSET_EFFECT_3    OFFSET_EFFECT_2 + ARRAY_SIZE(effect_2)

#define OFFSET_EFFECT_4    OFFSET_EFFECT_3 + ARRAY_SIZE(effect_3)

#define OFFSET_EFFECT_5    OFFSET_EFFECT_4 + ARRAY_SIZE(effect_4)

#define OFFSET_EFFECT_6    OFFSET_EFFECT_5 + ARRAY_SIZE(effect_5)

#define OFFSET_EFFECT_7    OFFSET_EFFECT_6 + ARRAY_SIZE(effect_6)

#define OFFSET_EFFECT_8    OFFSET_EFFECT_7 + ARRAY_SIZE(effect_7)

#define OFFSET_EFFECT_9    OFFSET_EFFECT_8 + ARRAY_SIZE(effect_8)

#define LEN_TOTAL_PATTERNS   OFFSET_EFFECT_9 + ARRAY_SIZE(effect_9)

#define NUM_TOTAL_PATTERNS   10

const static struct effect config_data[] = {
    {
       .effect_id = 0, /* CLICK */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_0),
       .offset = OFFSET_EFFECT_0,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 1, /* DOUBLE_CLICK */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_1),
       .offset = OFFSET_EFFECT_1,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 2, /* TICK */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_2),
       .offset = OFFSET_EFFECT_2,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 3, /* THUD */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_3),
       .offset = OFFSET_EFFECT_3,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 4, /* POP */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_4),
       .offset = OFFSET_EFFECT_4,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 5, /* HEAVY_CLICK */
       .effect_type = EFFECT_TYPE_PATTERN,
       .effect_len = ARRAY_SIZE(effect_5),
       .offset = OFFSET_EFFECT_5,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 17, /* RINGTONE_12 */
       .effect_type = EFFECT_TYPE_FIFO_ENVELOPE,
       .effect_len = ARRAY_SIZE(effect_6),
       .offset = OFFSET_EFFECT_6,
       .play_rate = S_PERIOD_T_LRA,
    },

    {
       .effect_id = 18, /* RINGTONE_13 */
       .effect_type = EFFECT_TYPE_FIFO_ENVELOPE,
       .effect_len = ARRAY_SIZE(effect_7),
       .offset = OFFSET_EFFECT_7,
       .play_rate = S_PERIOD_T_LRA_X_8,
    },

    {
       .effect_id = 19, /* RINGTONE_14 */
       .effect_type = EFFECT_TYPE_FIFO_ENVELOPE,
       .effect_len = ARRAY_SIZE(effect_8),
       .offset = OFFSET_EFFECT_8,
       .play_rate = S_PERIOD_T_LRA_X_8,
    },

    {
       .effect_id = 20, /* RINGTONE_15 */
       .effect_type = EFFECT_TYPE_FIFO_ENVELOPE,
       .effect_len = ARRAY_SIZE(effect_9),
       .offset = OFFSET_EFFECT_9,
       .play_rate = S_PERIOD_T_LRA_X_8,
    },
};

int get_pattern_config(uint8_t **ptr, uint32_t *size)
{
    *ptr = (uint8_t *)config_data;
    *size = sizeof(config_data);
    return 0;
}

int get_pattern_data(uint8_t **ptr, uint32_t *size)
{
    uint8_t *pattern_data;
    uint8_t *pbuf;
    int i;
    const uint8_t *pattern[] = {effect_0, effect_1, effect_2, effect_3, effect_4,
                                effect_5, effect_6, effect_7, effect_8, effect_9};

    uint32_t pattern_size[] = {sizeof(effect_0), sizeof(effect_1),
                               sizeof(effect_2), sizeof(effect_3),
                               sizeof(effect_4), sizeof(effect_5),
                               sizeof(effect_6), sizeof(effect_7),
                               sizeof(effect_8), sizeof(effect_9)};

    pattern_data = new uint8_t[LEN_TOTAL_PATTERNS];
    if (!pattern_data) {
        *ptr = NULL;
        return -ENOMEM;
    }

    pbuf = pattern_data;
    for (i = 0; i < NUM_TOTAL_PATTERNS; i++) {
         memcpy(pbuf, pattern[i], pattern_size[i]);
         pbuf = pbuf + pattern_size[i]/sizeof(char);
    }

    *ptr = pattern_data;
    *size = LEN_TOTAL_PATTERNS;

    return 0;
}

void free_pattern_mem(uint8_t *ptr)
{
    delete ptr;
}
