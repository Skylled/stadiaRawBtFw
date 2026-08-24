// 600f13d8  FUN_600f13d8  size=164 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009e4d0 FUN_6009e4d0


void FUN_600f13d8(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_24 [5];
  undefined1 local_1f [3];
  int local_1c;
  undefined1 *local_18;
  byte local_11;
  
  local_1f[2] = *(undefined1 *)(param_2 + 1);
  local_11 = *(byte *)(param_2 + 2) & 0xf;
  puVar1 = local_1f;
  local_18 = (undefined1 *)(param_2 + 3);
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *puVar1 = *local_18;
    puVar1 = puVar1 + -1;
    local_18 = local_18 + 1;
  }
  local_1c = param_1;
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x7a) = 1;
    thunk_EXT_FUN_0000b572(param_1 + 0x74,auStack_24,6);
    thunk_EXT_FUN_0000b572(auStack_24,local_1c + 0x10,6);
    local_11 = *(byte *)(local_1c + 0x6a);
  }
  FUN_6009e4d0(auStack_24,local_11,local_1f[2],local_18);
  return;
}


