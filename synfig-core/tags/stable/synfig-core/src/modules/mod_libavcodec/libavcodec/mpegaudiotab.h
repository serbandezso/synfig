/*
 * mpeg audio layer 2 tables. Most of them come from the mpeg audio
 * specification.
 * 
 * Copyright (c) 2000, 2001 Fabrice Bellard.
 *
 * The licence of this code is contained in file LICENCE found in the
 * same archive 
 */

/**
 * @file mpegaudiotab.h
 * mpeg audio layer 2 tables. 
 * Most of them come from the mpeg audio specification.
 */
 
#define SQRT2 1.41421356237309514547

static const int costab32[30] = {
    FIX(0.54119610014619701222),
    FIX(1.3065629648763763537),
    
    FIX(0.50979557910415917998),
    FIX(2.5629154477415054814),
    FIX(0.89997622313641556513),
    FIX(0.60134488693504528634),
    
    FIX(0.5024192861881556782),
    FIX(5.1011486186891552563),
    FIX(0.78815462345125020249),
    FIX(0.64682178335999007679),
    FIX(0.56694403481635768927),
    FIX(1.0606776859903470633),
    FIX(1.7224470982383341955),
    FIX(0.52249861493968885462),
    
    FIX(10.19000812354803287),
    FIX(0.674808341455005678),
    FIX(1.1694399334328846596),
    FIX(0.53104259108978413284),
    FIX(2.0577810099534108446),
    FIX(0.58293496820613388554),
    FIX(0.83934964541552681272),
    FIX(0.50547095989754364798),
    FIX(3.4076084184687189804),
    FIX(0.62250412303566482475),
    FIX(0.97256823786196078263),
    FIX(0.51544730992262455249),
    FIX(1.4841646163141661852),
    FIX(0.5531038960344445421),
    FIX(0.74453627100229857749),
    FIX(0.5006029982351962726),
};

static const int bitinv32[32] = {
    0,  16,  8, 24,  4,  20,  12,  28,
    2,  18, 10, 26,  6,  22,  14,  30,
    1,  17,  9, 25,  5,  21,  13,  29,
    3,  19, 11, 27,  7,  23,  15,  31
};


static int16_t filter_bank[512];

static int scale_factor_table[64];
#ifdef USE_FLOATS
static float scale_factor_inv_table[64];
#else
static int8_t scale_factor_shift[64];
static unsigned short scale_factor_mult[64];
#endif
static unsigned char scale_diff_table[128];

/* total number of bits per allocation group */
static unsigned short total_quant_bits[17];

/* signal to noise ratio of each quantification step (could be
   computed from quant_steps[]). The values are dB multiplied by 10 
*/
static unsigned short quant_snr[17] = { 
     70, 110, 160, 208,
    253, 316, 378, 439,
    499, 559, 620, 680, 
    740, 800, 861, 920, 
    980
};

/* fixed psycho acoustic model. ValueBases of SNR taken from the 'toolame'
   project */
static const float fixed_smr[SBLIMIT] =  {
    30, 17, 16, 10, 3, 12, 8, 2.5,
    5, 5, 6, 6, 5, 6, 10, 6,
    -4, -10, -21, -30, -42, -55, -68, -75,
    -75, -75, -75, -75, -91, -107, -110, -108
};

static const unsigned char nb_scale_factors[4] = { 3, 2, 1, 2 };

