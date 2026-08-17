// 60098718  FUN_60098718  size=132 bytes
// --- callers ---
//   600f1148 FUN_600f1148
// --- callees ---
//   600a1394 FUN_600a1394
//   6013cf90 thunk_EXT_FUN_0000b5ba


bool FUN_60098718(undefined1 param_1,int param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_28 [20];
  undefined1 *local_14;
  
  local_14 = local_28;
  thunk_EXT_FUN_0000b5ba(local_28,0,0x14);
  puVar1 = local_14 + 1;
  *local_14 = 0xe;
  local_14 = puVar1;
  puVar1 = local_14 + 1;
  *local_14 = param_1;
  local_14 = puVar1;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)((5 - iVar2) + param_2);
    local_14 = puVar1;
  }
  puVar1 = local_14 + 1;
  *local_14 = param_3;
  local_14 = puVar1;
  iVar2 = FUN_600a1394(0xfce9,9,local_28,DAT_6009879c);
  return iVar2 != 3;
}


