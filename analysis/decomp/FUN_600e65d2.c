// 600e65d2  FUN_600e65d2  size=236 bytes
// --- callers ---
//   600eb588 FUN_600eb588
//   6008aad8 FUN_6008aad8
//   600e66be FUN_600e66be
//   600e693e FUN_600e693e
// --- callees ---
//   600e398a FUN_600e398a
//   600e2316 FUN_600e2316
//   600e5208 FUN_600e5208
//   600e548a FUN_600e548a


void FUN_600e65d2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined1 auStack_118 [32];
  undefined1 auStack_f8 [32];
  undefined1 auStack_d8 [32];
  undefined1 auStack_b8 [32];
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [32];
  undefined1 auStack_58 [32];
  undefined1 auStack_38 [36];
  
  FUN_600e398a(auStack_118,param_6);
  FUN_600e398a(auStack_f8,param_5);
  FUN_600e2316(auStack_d8,param_4,auStack_f8);
  FUN_600e548a(auStack_b8,param_4,auStack_118);
  FUN_600e5208(auStack_98,param_4,auStack_118);
  FUN_600e5208(auStack_78,auStack_98);
  FUN_600e5208(auStack_98,auStack_98,auStack_78);
  FUN_600e2316(auStack_58,auStack_b8,auStack_98);
  FUN_600e398a(param_1,auStack_58);
  FUN_600e5208(auStack_38,auStack_d8);
  FUN_600e5208(auStack_38,auStack_38);
  FUN_600e5208(auStack_78,auStack_38);
  FUN_600e548a(param_1,param_1,auStack_78);
  FUN_600e5208(auStack_118,auStack_f8,auStack_118);
  FUN_600e5208(auStack_b8,param_5,param_6);
  FUN_600e398a(param_3,auStack_b8);
  FUN_600e548a(param_3,param_3,auStack_118);
  FUN_600e548a(param_2,auStack_38,param_1);
  FUN_600e5208(auStack_f8,auStack_f8);
  FUN_600e398a(auStack_f8);
  FUN_600e2316(param_2,auStack_58,param_2);
  FUN_600e5208(auStack_f8,auStack_f8);
  FUN_600e548a(param_2,param_2,auStack_f8);
  return;
}


