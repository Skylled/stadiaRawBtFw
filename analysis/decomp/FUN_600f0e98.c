// 600f0e98  FUN_600f0e98  size=142 bytes
// --- callers ---
//   600f41d0 FUN_600f41d0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6009ff18 FUN_6009ff18
//   600f0a52 FUN_600f0a52
//   600c09f0 FUN_600c09f0


undefined1
FUN_600f0e98(undefined4 param_1,int param_2,undefined2 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_18 [8];
  int local_10;
  undefined1 local_9;
  
  local_9 = 0;
  local_10 = FUN_6009ff18(param_1);
  if (((local_10 != 0) &&
      (((local_10 == 0 || ((*(byte *)(local_10 + 0x7b) & 4) != 0)) &&
       (*(uint *)(local_10 + 0xdc) <= param_4)))) && (param_2 != 0)) {
    iVar1 = FUN_600c09f0(local_10 + 0x9c,param_2,param_3,8,auStack_18);
    if ((iVar1 != 0) && (iVar1 = thunk_EXT_FUN_0000b554(auStack_18,param_5,8), iVar1 == 0)) {
      FUN_600f0a52(param_1,0);
      local_9 = 1;
    }
  }
  return local_9;
}


