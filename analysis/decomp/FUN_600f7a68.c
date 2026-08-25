// 600f7a68  FUN_600f7a68  size=52 bytes
// --- callers ---
//   600f5fb4 FUN_600f5fb4
//   600fa568 FUN_600fa568
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600bcc30 FUN_600bcc30


bool FUN_600f7a68(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_600bcc30(0,param_1);
  if (iVar1 != 0) {
    FUN_600b5e00(iVar1,0x1c,0);
  }
  return iVar1 != 0;
}


