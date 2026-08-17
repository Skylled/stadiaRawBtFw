// 600c25ac  FUN_600c25ac  size=80 bytes
// --- callers ---
//   600c0294 FUN_600c0294
// --- callees ---
//   600fbc3a FUN_600fbc3a
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1158 FUN_600c1158


bool FUN_600c25ac(int param_1)

{
  int iVar1;
  undefined1 auStack_18 [16];
  
  FUN_600c1158(param_1,auStack_18);
  FUN_600fbc3a(auStack_18,DAT_600c25fc);
  FUN_600fbc3a(param_1 + 0xbd,DAT_600c2600);
  iVar1 = thunk_EXT_FUN_0000b554(param_1 + 0xbd,auStack_18,0x10);
  return iVar1 == 0;
}


