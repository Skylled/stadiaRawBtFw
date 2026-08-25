// 600f3ade  FUN_600f3ade  size=44 bytes
// --- callers ---
//   600fe432 FUN_600fe432
// --- callees ---
//   600af7c8 FUN_600af7c8


undefined1 FUN_600f3ade(undefined2 param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  iVar2 = FUN_600afd28((char)param_1);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    local_9 = 0x87;
  }
  else {
    iVar1 = FUN_600afd84(param_1);
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)FUN_600afdf8(param_1);
      if (puVar3 == (undefined4 *)0x0) {
        local_9 = 0x80;
      }
      else {
        *(undefined1 *)((int)puVar3 + 0x31) = 4;
        FUN_600f46b4(*puVar3,puVar3,param_2 != '\0');
      }
    }
    else {
      local_9 = 0x84;
    }
  }
  return local_9;
}


