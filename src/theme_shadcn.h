/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * shadcn (zinc) tokens for the custom X6100 LVGL UI, a drop-in for x6100_gui.
 * The values are the web console's tokens (custom-build/console/src/index.css)
 * converted from HSL to 0xRRGGBB for lv_color_hex(). If you change a token, change
 * it in both places so the radio and the console stay the same.
 * See THEME_INTEGRATION.md.
 */
#pragma once
#include <stdint.h>

typedef struct {
    uint32_t bg;         /* screen background                       */
    uint32_t card;       /* panels, dialogs, top blocks              */
    uint32_t muted;      /* track and inactive fill                  */
    uint32_t muted_fg;   /* secondary text                           */
    uint32_t border;     /* hairlines                                */
    uint32_t fg;         /* primary text                             */
    uint32_t primary;    /* emphasis, the focused item's fill        */
    uint32_t primary_fg; /* text on a primary fill                   */
    uint32_t secondary;  /* secondary button surface                 */
    uint32_t accent;     /* hover and accent surface                 */
    uint32_t ring;       /* focus ring                               */
    uint32_t rx;         /* RX and OK (green)                        */
    uint32_t tx;         /* TX and danger (red)                      */
    uint32_t signal;     /* strong signal and warning (amber)        */
    uint32_t wf;         /* waterfall mid, spectrum, edit state (blue) */
} shadcn_theme_t;

/* Corner radius in pixels. The console's --radius is 0.6rem (9.6px) and its
 * --radius-md is 2px less, so 8px sits between the two. Upstream's dialog and
 * map code also assume 8px corners inside a 1px border, so this keeps them in step. */
#define SHADCN_RADIUS 8

/* The radio runs dark by default. Light is there for daylight use. */
static const shadcn_theme_t shadcn_dark = {
    .bg         = 0x09090B,
    .card       = 0x131316,
    .muted      = 0x27272A,
    .muted_fg   = 0xA1A1AA,
    .border     = 0x27272A,
    .fg         = 0xFAFAFA,
    .primary    = 0xFAFAFA,
    .primary_fg = 0x18181B,
    .secondary  = 0x27272A,
    .accent     = 0x27272A,
    .ring       = 0xD4D4D8,
    .rx         = 0x2FBC63,
    .tx         = 0xE04242,
    .signal     = 0xF5A519,
    .wf         = 0x3DA8F5,
};

static const shadcn_theme_t shadcn_light = {
    .bg         = 0xFFFFFF,
    .card       = 0xFFFFFF,
    .muted      = 0xF4F4F5,
    .muted_fg   = 0x67676F,
    .border     = 0xE4E4E7,
    .fg         = 0x09090B,
    .primary    = 0x18181B,
    .primary_fg = 0xFAFAFA,
    .secondary  = 0xF4F4F5,
    .accent     = 0xF4F4F5,
    .ring       = 0x18181B,
    .rx         = 0x20974C,
    .tx         = 0xD32222,
    .signal     = 0xE19209,
    .wf         = 0x0C8DE9,
};

/* The token set in use, or NULL when an upstream theme is selected.
 * styles_set_theme() keeps it current. */
extern const shadcn_theme_t *shadcn;
