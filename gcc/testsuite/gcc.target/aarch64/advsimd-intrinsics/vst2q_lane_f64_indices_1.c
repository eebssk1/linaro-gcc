#include <arm_neon.h>

/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-fno-fat-lto-objects" } } */
/* { dg-skip-if "" { arm*-*-* } } */

void
f_vst2q_lane_f64 (float64_t * p, float64x2x2_t v)
{
  /* { dg-error "lane 2 out of range 0 - 1" "" { target *-*-* } 0 } */
  vst2q_lane_f64 (p, v, 2);
  /* { dg-error "lane -1 out of range 0 - 1" "" { target *-*-* } 0 } */
  vst2q_lane_f64 (p, v, -1);
  return;
}
