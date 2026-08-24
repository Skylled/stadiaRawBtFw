// 600edbf4  FUN_600edbf4  size=26 bytes
// --- callers ---
//   60091c10 obj__60091c10
//   60091b94 FUN_60091b94
// --- callees ---
//   600edb2a FUN_600edb2a


undefined4 FUN_600edbf4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_600edb2a(param_1,0,param_2,param_3,param_4,param_2,param_3);
  uVar2 = 0;
  if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
    uVar2 = *(undefined4 *)*piVar1;
  }
  return uVar2;
}


