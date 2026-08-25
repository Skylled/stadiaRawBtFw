// 600fbdd0  FUN_600fbdd0  size=178 bytes
// --- callers ---
//   600c0e7c FUN_600c0e7c
//   600c15a8 FUN_600c15a8
// --- callees ---
//   6009ab94 FUN_6009ab94
//   600c1a34 FUN_600c1a34
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600fad26 FUN_600fad26
//   600fbc02 FUN_600fbc02


void FUN_600fbdd0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_39;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [16];
  undefined1 local_24 [4];
  undefined1 auStack_20 [16];
  undefined1 *local_10;
  undefined2 local_a;
  
  local_a = 1;
  local_10 = local_24;
  local_39 = 8;
  FUN_6009ab94(auStack_20);
  puVar1 = local_10 + 1;
  *local_10 = (char)*(undefined2 *)(param_1 + 0x1d6);
  local_10 = puVar1;
  puVar1 = local_10 + 1;
  *local_10 = (char)((ushort)*(undefined2 *)(param_1 + 0x1d6) >> 8);
  local_10 = puVar1;
  puVar1 = local_10 + 1;
  *local_10 = (char)local_a;
  local_10 = puVar1;
  puVar1 = local_10 + 1;
  *local_10 = (char)((ushort)local_a >> 8);
  local_10 = puVar1;
  iVar2 = FUN_600fbc02(auStack_20,0x10,local_24,4,auStack_38);
  if (iVar2 == 0) {
    FUN_600c1a34(param_1,0x17,&local_39);
  }
  else {
    thunk_EXT_FUN_0000b572(param_1 + 0x1d8,auStack_34,0x10);
    FUN_600fad26(param_1,0);
  }
  return;
}


