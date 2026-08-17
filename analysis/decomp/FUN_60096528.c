// 60096528  FUN_60096528  size=46 bytes
// --- callers ---
//   60096358 FUN_60096358
// --- callees ---
//   6006e1e0 FUN_6006e1e0


uint FUN_60096528(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006e1e0(param_1,param_2);
  return (uint)((ulonglong)DAT_60096558 * (ulonglong)(uint)(iVar1 * 1000) >> 0x26);
}


