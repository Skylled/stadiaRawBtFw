// 60132de4  FUN_60132de4  size=120 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_60132de4(int param_1,ushort *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  ushort local_30;
  ushort local_2e;
  undefined1 local_28;
  undefined2 local_27;
  undefined2 local_25 [6];
  uint local_18;
  uint auStack_14 [2];
  
  local_30 = *(ushort *)(param_1 + 0x124);
  if (*(ushort *)(param_1 + 0x124) <= *param_2) {
    local_30 = *param_2;
  }
  local_2e = *(ushort *)(param_1 + 0x126);
  if (param_2[1] <= *(ushort *)(param_1 + 0x126)) {
    local_2e = param_2[1];
  }
  local_28 = *(undefined1 *)(param_1 + 0x128);
  local_27 = *(undefined2 *)(param_1 + 0x12a);
  uVar2 = 0;
  do {
    uVar3 = uVar2 + 1;
    local_25[uVar2] = *(undefined2 *)(param_1 + uVar2 * 2 + 0x130);
    uVar2 = uVar3;
  } while (uVar3 < 6);
  func_0x600eccbe(param_1,&local_30,&local_18);
  func_0x600eccbe(param_1,param_2,auStack_14);
  if ((local_18 <= auStack_14[0]) || (uVar1 = 0, auStack_14[0] != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


