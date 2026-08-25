// 600f3e00  FUN_600f3e00  size=106 bytes
// --- callers ---
//   600fdcfc FUN_600fdcfc
//   600ff21c FUN_600ff21c
//   600ff612 FUN_600ff612
//   600ff404 FUN_600ff404
//   600feba8 FUN_600feba8
//   600ff4de FUN_600ff4de
//   600ef648 FUN_600ef648
// --- callees ---
//   600afd28 FUN_600afd28
//   600af7c8 FUN_600af7c8
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1
FUN_600f3e00(undefined2 param_1,undefined1 *param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = FUN_600afd28((char)param_1);
  iVar2 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  local_9 = 0;
  if ((iVar2 != 0) && (iVar1 != 0)) {
    thunk_EXT_FUN_0000b572(param_3,iVar2 + 0xd,6);
    *param_2 = (char)param_1;
    *param_4 = *(undefined1 *)(iVar2 + 0x13);
    local_9 = 1;
  }
  return local_9;
}


