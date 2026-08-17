// 600c1494  FUN_600c1494  size=176 bytes
// --- callers ---
//   600c13e8 FUN_600c13e8
// --- callees ---
//   600c09f0 FUN_600c09f0


undefined1 FUN_600c1494(int param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 local_58 [32];
  undefined1 local_38 [16];
  undefined1 auStack_28 [19];
  undefined1 local_15;
  undefined1 *local_14;
  
  local_15 = 1;
  local_68 = *DAT_600c1544;
  uStack_64 = DAT_600c1544[1];
  uStack_60 = DAT_600c1544[2];
  uStack_5c = DAT_600c1544[3];
  local_14 = local_38;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)((int)&local_68 + iVar2);
    local_14 = puVar1;
  }
  local_14 = local_58;
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_1);
    local_14 = puVar1;
  }
  iVar2 = FUN_600c09f0(local_38,local_58,0x20,0x10,auStack_28);
  if (iVar2 == 0) {
    local_15 = 0;
  }
  local_14 = param_2;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *local_14 = auStack_28[iVar2];
    local_14 = local_14 + 1;
  }
  return local_15;
}


