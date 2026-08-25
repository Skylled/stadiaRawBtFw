// 600f3e6a  FUN_600f3e6a  size=108 bytes
// --- callers ---
//   600fda2c FUN_600fda2c
//   600aae30 FUN_600aae30
//   600fdab8 FUN_600fdab8
//   600ff31a FUN_600ff31a
//   600abbc4 FUN_600abbc4
//   600fed9e FUN_600fed9e
// --- callees ---
//   600afd28 FUN_600afd28
//   600f6132 FUN_600f6132
//   600af814 FUN_600af814


undefined1
FUN_600f3e6a(undefined1 param_1,undefined4 param_2,undefined2 *param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = FUN_600afd28(param_1);
  iVar2 = FUN_600af814(param_2,param_4);
  local_9 = 0;
  if (((iVar1 != 0) && (iVar2 != 0)) && (iVar1 = FUN_600f6132(iVar2), iVar1 == 4)) {
    *param_3 = CONCAT11(*(undefined1 *)(iVar2 + 0xfb),param_1);
    local_9 = 1;
  }
  return local_9;
}


