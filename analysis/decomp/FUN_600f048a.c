// 600f048a  FUN_600f048a  size=48 bytes
// --- callers ---
//   6009fae0 FUN_6009fae0
//   600f5a98 FUN_600f5a98
//   6009a9c4 FUN_6009a9c4
//   600f04e4 FUN_600f04e4
//   6009fcf4 FUN_6009fcf4
// --- callees ---
//   60098ec8 FUN_60098ec8


undefined2 FUN_600f048a(undefined4 param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  puVar1 = (undefined2 *)FUN_60098ec8(param_1,param_2);
  if (puVar1 == (undefined2 *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = *puVar1;
  }
  return uVar2;
}


