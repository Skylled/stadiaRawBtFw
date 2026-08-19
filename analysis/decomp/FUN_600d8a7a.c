// 600d8a7a  FUN_600d8a7a  size=76 bytes
// --- callers ---
//   600d8ae8 FUN_600d8ae8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600d8a7a(int param_1,undefined4 *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined1 auStack_11c [256];
  undefined4 local_1c;
  
  local_134 = *param_2;
  uStack_130 = param_2[1];
  uStack_12c = param_2[2];
  uStack_128 = param_2[3];
  local_124 = param_2[4];
  thunk_EXT_FUN_0000b5ba(auStack_11c,0,0x100);
  local_120 = 0;
  local_1c = 0;
  thunk_EXT_FUN_0000b572(*(int *)(param_1 + 0x1714) * 0x11c + param_1 + 0x230,&local_134);
  iVar1 = *(int *)(param_1 + 0x1714);
  *(int *)(param_1 + 0x1714) = iVar1 + 1;
  *param_3 = (short)iVar1;
  return 0;
}


