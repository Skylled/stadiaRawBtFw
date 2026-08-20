// 600e693e  FUN_600e693e  size=88 bytes
// --- callers ---
// --- callees ---
//   600e65d2 FUN_600e65d2
//   600e63a4 FUN_600e63a4
//   600e643a FUN_600e643a


void FUN_600e693e(undefined4 param_1,int param_2,int param_3)

{
  undefined1 auStack_78 [32];
  undefined1 auStack_58 [32];
  undefined1 auStack_38 [36];
  
  FUN_600e643a(auStack_78,param_3);
  FUN_600e643a(auStack_58,param_3 + 0x44);
  FUN_600e643a(auStack_38,param_3 + 0x88);
  FUN_600e65d2(auStack_78,auStack_58,auStack_38,auStack_78,auStack_58,auStack_38);
  FUN_600e63a4(param_2,auStack_78);
  FUN_600e63a4(param_2 + 0x44,auStack_58);
  FUN_600e63a4(param_2 + 0x88,auStack_38);
  return;
}


