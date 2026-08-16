// 600e66be  FUN_600e66be  size=494 bytes
// --- callers ---
//   600eb588 FUN_600eb588
//   6008aad8 FUN_6008aad8
//   600e68ac FUN_600e68ac
// --- callees ---
//   600e1e54 FUN_600e1e54
//   600e65d2 FUN_600e65d2
//   600e652a FUN_600e652a
//   600e650a FUN_600e650a
//   600e398a FUN_600e398a
//   600e2316 FUN_600e2316
//   600e653e FUN_600e653e
//   600e5208 FUN_600e5208
//   600e548a FUN_600e548a


void FUN_600e66be(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint extraout_r2;
  undefined8 uVar6;
  undefined1 auStack_228 [32];
  undefined1 auStack_208 [32];
  undefined1 auStack_1e8 [32];
  undefined1 auStack_1c8 [32];
  undefined1 auStack_1a8 [32];
  undefined1 auStack_188 [32];
  undefined1 auStack_168 [32];
  undefined1 auStack_148 [32];
  undefined1 auStack_128 [32];
  undefined1 auStack_108 [32];
  undefined1 auStack_e8 [32];
  undefined1 auStack_c8 [32];
  undefined1 auStack_a8 [32];
  undefined1 auStack_88 [32];
  undefined1 auStack_68 [32];
  undefined1 auStack_48 [36];
  
  uVar1 = FUN_600e650a(param_6);
  uVar2 = FUN_600e650a(param_10);
  FUN_600e398a(auStack_1c8,param_6);
  if (param_7 == 0) {
    FUN_600e398a(auStack_48,param_10);
    FUN_600e2316(auStack_1a8,param_4,auStack_48);
    FUN_600e5208(auStack_168,param_6,param_10);
    FUN_600e398a(auStack_168);
    FUN_600e548a(auStack_168,auStack_168,auStack_1c8);
    FUN_600e548a(auStack_168,auStack_168,auStack_48);
    FUN_600e2316(auStack_188,param_10,auStack_48);
    FUN_600e2316(auStack_188,auStack_188,param_5);
  }
  else {
    FUN_600e652a(auStack_1a8,param_4);
    FUN_600e5208(auStack_168,param_6,param_6);
    FUN_600e652a(auStack_188,param_5);
  }
  FUN_600e2316(auStack_148,param_8,auStack_1c8);
  FUN_600e548a(auStack_128,auStack_148,auStack_1a8);
  uVar3 = FUN_600e650a(auStack_128);
  FUN_600e2316(auStack_1e8,auStack_128,auStack_168);
  FUN_600e2316(auStack_108,param_6,auStack_1c8);
  FUN_600e2316(auStack_e8,param_9,auStack_108);
  FUN_600e548a(auStack_c8,auStack_e8,auStack_188);
  FUN_600e5208(auStack_c8,auStack_c8);
  uVar4 = FUN_600e650a(auStack_c8);
  uVar5 = FUN_600e1e54(uVar4 | uVar3);
  uVar6 = FUN_600e1e54(uVar1,uVar5);
  uVar6 = FUN_600e1e54(uVar2,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
  if (((uint)((ulonglong)uVar6 >> 0x20) & ~((uint)uVar6 | extraout_r2)) == 0) {
    FUN_600e5208(auStack_a8,auStack_128);
    FUN_600e398a(auStack_a8);
    FUN_600e2316(auStack_88,auStack_128,auStack_a8);
    FUN_600e2316(auStack_68,auStack_1a8,auStack_a8);
    FUN_600e398a(auStack_228,auStack_c8);
    FUN_600e548a(auStack_228,auStack_228,auStack_88);
    FUN_600e548a(auStack_228,auStack_228,auStack_68);
    FUN_600e548a(auStack_228,auStack_228,auStack_68);
    FUN_600e548a(auStack_208,auStack_68,auStack_228);
    FUN_600e2316(auStack_208,auStack_208,auStack_c8);
    FUN_600e2316(auStack_48,auStack_188,auStack_88);
    FUN_600e548a(auStack_208,auStack_208,auStack_48);
    FUN_600e548a(auStack_208,auStack_208,auStack_48);
    FUN_600e653e(auStack_228,uVar1,param_8);
    FUN_600e653e(param_1,uVar2,param_4,auStack_228);
    FUN_600e653e(auStack_208,uVar1,param_9);
    FUN_600e653e(param_2,uVar2,param_5,auStack_208);
    FUN_600e653e(auStack_1e8,uVar1,param_10);
    FUN_600e653e(param_3,uVar2,param_6,auStack_1e8);
  }
  else {
    FUN_600e65d2(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}


