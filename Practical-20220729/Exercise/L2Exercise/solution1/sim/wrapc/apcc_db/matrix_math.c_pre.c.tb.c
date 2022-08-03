/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void AESL_WRAP_m_add(signed int (*)[4], signed int (*)[4], signed int (*)[4]);
signed int m_compare(signed int (*)[4], signed int (*)[4]);


/* Global Variable Definitions and Initialization */
static signed int aesl_internal_main_OC_B[4][4] = { { 1u, 2u, 3u, 5u }, { 1u, 5u, 3u, 4u }, { 1u, 2u, 3u, 5u }, { 1u, 5u, 3u, 4u } };
static signed int aesl_internal_main_OC_Ex_Add[4][4] = { { 2u, 4u, 6u, 10u }, { 2u, 10u, 6u, 8u }, { 2u, 4u, 6u, 10u }, { 2u, 10u, 6u, 8u } };
static  char aesl_internal_str[19] = "Output of addition";
static  char aesl_internal_str1[47] = "FAIL: Output DOES NOT match the golden output ";
static  char aesl_internal_str2[44] = "PASS: The output matches the golden output!";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_A_count = 0;
  signed int llvm_cbe_A[4][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_B_count = 0;
  signed int llvm_cbe_B[4][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_Add_count = 0;
  signed int llvm_cbe_Add[4][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_Ex_Add_count = 0;
  signed int llvm_cbe_Ex_Add[4][4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  signed int (*llvm_cbe_tmp__5)[4];
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  signed int (*llvm_cbe_tmp__6)[4];
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  signed int (*llvm_cbe_tmp__7)[4];
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed int (*llvm_cbe_tmp__10)[4];
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts1_count = 0;
  unsigned int llvm_cbe_puts1;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast [4 x [4 x i32]]* %%A to i8*, !dbg !2 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_2_count);
  llvm_cbe_tmp__1 = ( char *)(( char *)(&llvm_cbe_A));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memcpy(i8* %%1, i8* bitcast ([4 x [4 x i32]]* @aesl_internal_main.B to i8*), i64 64 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_3_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__1, ( char *)(( char *)(&aesl_internal_main_OC_B)), 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast [4 x [4 x i32]]* %%B to i8*, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__3 = ( char *)(( char *)(&llvm_cbe_B));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* %%3, i8* bitcast ([4 x [4 x i32]]* @aesl_internal_main.B to i8*), i64 64 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__3, ( char *)(( char *)(&aesl_internal_main_OC_B)), 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [4 x [4 x i32]]* %%A, i64 0, i64 0, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__5 = (signed int (*)[4])(&llvm_cbe_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [4 x [4 x i32]]* %%B, i64 0, i64 0, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__6 = (signed int (*)[4])(&llvm_cbe_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [4 x [4 x i32]]* %%Add, i64 0, i64 0, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__7 = (signed int (*)[4])(&llvm_cbe_Add[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_m_add([4 x i32]* %%5, [4 x i32]* %%6, [4 x i32]* %%7) nounwind, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_11_count);
  AESL_WRAP_m_add(llvm_cbe_tmp__5, llvm_cbe_tmp__6, llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([19 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 19
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast [4 x [4 x i32]]* %%Ex_Add to i8*, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__8 = ( char *)(( char *)(&llvm_cbe_Ex_Add));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memcpy(i8* %%8, i8* bitcast ([4 x [4 x i32]]* @aesl_internal_main.Ex_Add to i8*), i64 64 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__8, ( char *)(( char *)(&aesl_internal_main_OC_Ex_Add)), 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [4 x [4 x i32]]* %%Ex_Add, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__10 = (signed int (*)[4])(&llvm_cbe_Ex_Add[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i32 @m_compare([4 x i32]* %%7, [4 x i32]* %%10) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__11 = (unsigned int )m_compare(llvm_cbe_tmp__7, llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
  if (((llvm_cbe_tmp__11&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__12;
  } else {
    goto llvm_cbe_tmp__13;
  }

llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts1 = call i32 @puts(i8* getelementptr inbounds ([47 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts1_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 47
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts1 = 0x%X",llvm_cbe_puts1);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__14;

llvm_cbe_tmp__12:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([44 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 44
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__14;

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ -1, %%13 ], [ 0, %%14  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge;
}

