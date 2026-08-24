// 600f139a  FUN_600f139a  size=62 bytes
// --- callers ---
//   600f717c FUN_600f717c
//   600f735a FUN_600f735a
//   600b05f0 FUN_600b05f0
// --- callees ---
//   6009c2c0 FUN_6009c2c0
//   6009c124 FUN_6009c124


undefined4 FUN_600f139a(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 4;
  iVar1 = FUN_6009c2c0(param_1,param_2,&local_9);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_6009c124(param_1,param_2,local_9);
  }
  return uVar2;
}


