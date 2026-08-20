// 600e68ac  FUN_600e68ac  size=146 bytes
// --- callers ---
// --- callees ---
//   600e63a4 FUN_600e63a4
//   600e643a FUN_600e643a
//   600e66be FUN_600e66be


void FUN_600e68ac(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined1 auStack_e0 [32];
  undefined1 auStack_c0 [32];
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [32];
  
  FUN_600e643a(auStack_e0,param_3);
  FUN_600e643a(auStack_c0,param_3 + 0x44);
  FUN_600e643a(auStack_a0,param_3 + 0x88);
  FUN_600e643a(auStack_80,param_4);
  FUN_600e643a(auStack_60,param_4 + 0x44);
  FUN_600e643a(auStack_40,param_4 + 0x88);
  FUN_600e66be(auStack_e0,auStack_c0,auStack_a0,auStack_e0,auStack_c0,auStack_a0,0,auStack_80,
               auStack_60,auStack_40);
  FUN_600e63a4(param_2,auStack_e0);
  FUN_600e63a4(param_2 + 0x44,auStack_c0);
  FUN_600e63a4(param_2 + 0x88,auStack_a0);
  return;
}


